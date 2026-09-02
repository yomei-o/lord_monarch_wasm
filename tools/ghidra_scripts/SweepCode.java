// Force-disassemble a range and make a function at every call target.
//
//   -postScript SweepCode.java 1000:0000 0xa438
//
// Following the entry point gets nowhere in hand-written 16-bit assembly: one
// bad byte truncates the flow and the auto-analyser stops, which on PROG.BIN
// left 7 functions out of 42KB of code.  Sweeping the range instead finds the
// code that nothing reachable points at - at the cost of also decoding the data
// tables mixed in with it, which is a fair trade when the alternative is
// nothing.
//
// Two passes: seed from every address in the range, then create functions where
// calls actually land, so the function list is driven by real references rather
// than by wherever the sweep happened to start.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.FlowType;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.util.TreeSet;

public class SweepCode extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String startSpec = args.length > 0 ? args[0] : "1000:0000";
        long length = args.length > 1 ? Long.decode(args[1]) : 0x10000L;

        Address start = currentProgram.getAddressFactory().getAddress(startSpec);
        Address end = start.add(length - 1);
        println("SweepCode: " + start + " .. " + end);

        // Pass 1: try every address the sweep has not already turned into code.
        int made = 0;
        Address a = start;
        while (a.compareTo(end) <= 0) {
            Instruction ins = getInstructionAt(a);
            if (ins == null) {
                disassemble(a);
                ins = getInstructionAt(a);
                if (ins != null)
                    made++;
            }
            long step = (ins != null) ? ins.getLength() : 1;
            try {
                a = a.add(step);
            } catch (Exception e) {
                break;
            }
        }
        println("SweepCode: disassembled from " + made + " fresh starts");

        // Pass 2: a function wherever a call lands inside the range.
        TreeSet<Long> targets = new TreeSet<>();
        Instruction ins = getFirstInstruction();
        while (ins != null && !monitor.isCancelled()) {
            FlowType ft = ins.getFlowType();
            if (ft != null && ft.isCall())
                for (Reference r : ins.getReferencesFrom())
                    if (r.getToAddress() != null &&
                        r.getToAddress().compareTo(start) >= 0 &&
                        r.getToAddress().compareTo(end) <= 0)
                        targets.add(r.getToAddress().getOffset());
            ins = getInstructionAfter(ins);
        }
        int fn = 0;
        for (Long off : targets) {
            Address t = start.getNewAddress(off);
            if (getFunctionAt(t) == null && getInstructionAt(t) != null) {
                if (createFunction(t, null) != null)
                    fn++;
            }
        }
        println("SweepCode: " + targets.size() + " call targets, " + fn +
                " new functions");
    }
}
