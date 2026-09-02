// Decompile every function to C, one file per function plus one combined file,
// and a CSV index of what was found.  Run through analyzeHeadless -postScript.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.*;
import java.util.*;

public class DecompileAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outDir = getScriptArgs().length > 0 ? getScriptArgs()[0]
                                                   : "decomp";
        new File(outDir).mkdirs();
        new File(outDir + "/functions").mkdirs();

        DecompInterface decomp = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decomp.setOptions(options);
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) {
            println("decompiler failed to open: " + decomp.getLastMessage());
            return;
        }

        PrintWriter all = new PrintWriter(
            new BufferedWriter(new FileWriter(outDir + "/all.c")));
        PrintWriter index = new PrintWriter(
            new BufferedWriter(new FileWriter(outDir + "/index.csv")));
        index.println("address,name,size,calls,called_by,decompiled");

        all.println("/* Ghidra decompilation of " +
                    currentProgram.getName() + " - machine output, not the "
                    + "original source. */");

        int ok = 0, fail = 0;
        FunctionIterator it = currentProgram.getFunctionManager()
                                            .getFunctions(true);
        ConsoleTaskMonitor monitor = new ConsoleTaskMonitor();
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            String addr = f.getEntryPoint().toString();
            String name = f.getName();
            long size = f.getBody().getNumAddresses();
            int calls = f.getCalledFunctions(monitor).size();
            int callers = f.getCallingFunctions(monitor).size();

            DecompileResults res = decomp.decompileFunction(f, 120, monitor);
            boolean good = res != null && res.decompileCompleted()
                           && res.getDecompiledFunction() != null;
            if (good) {
                String c = res.getDecompiledFunction().getC();
                all.println();
                all.println("/* " + addr + "  " + name + "  " + size
                            + " bytes, " + callers + " callers */");
                all.println(c);
                PrintWriter one = new PrintWriter(new FileWriter(
                    outDir + "/functions/" + name + ".c"));
                one.println("/* " + addr + " */");
                one.println(c);
                one.close();
                ok++;
            } else {
                fail++;
            }
            index.println(addr + "," + name + "," + size + "," + calls + ","
                          + callers + "," + (good ? 1 : 0));
        }
        all.close();
        index.close();
        decomp.dispose();
        println("decompiled " + ok + " functions, " + fail + " failed");
    }
}
