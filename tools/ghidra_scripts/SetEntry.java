// Mark an entry point and disassemble from it, for a raw binary that has no
// header to tell Ghidra where the code starts.
//
// Run as a -preScript so the auto-analyser has something to follow; without it a
// Raw Binary import finds no functions at all.
//
//   -preScript SetEntry.java 1000:0000
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class SetEntry extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String spec = args.length > 0 ? args[0] : "1000:0000";

        for (String one : spec.split(",")) {
            Address a = currentProgram.getAddressFactory().getAddress(one.trim());
            if (a == null) {
                println("SetEntry: cannot parse " + one);
                continue;
            }
            currentProgram.getSymbolTable().addExternalEntryPoint(a);
            createLabel(a, "entry_" + one.trim().replace(':', '_'), true);
            disassemble(a);
            println("SetEntry: entry at " + a);
        }
    }
}
