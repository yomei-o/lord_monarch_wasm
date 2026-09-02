/* 1000:16eb */

/* WARNING: Instruction at (ram,0x0001171f) overlaps instruction at (ram,0x0001171e)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_16eb(int param_1,int param_2,int param_3,undefined2 param_4,int param_5)

{
  char *pcVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 in_AX;
  int iVar4;
  int in_BX;
  byte bVar5;
  int unaff_BP;
  int unaff_SI;
  undefined2 *puVar6;
  int unaff_DI;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool in_OF;
  undefined2 in_stack_00000020;
  undefined2 in_stack_00000022;
  undefined2 in_stack_00000026;
  
  if (in_OF) {
    in(0x8b);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined2 *)0x3bc2 = in_AX;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_5bfc();
  if (!(bool)in_CF) {
    func_0x00010081();
    param_5 = in_BX;
    param_3 = unaff_BP;
    param_2 = unaff_SI;
    param_1 = unaff_DI;
  }
  *(undefined2 *)0x3bd4 = 0xffff;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_7860();
  FUN_1000_494f();
  FUN_1000_48a5();
  FUN_1000_6e71();
  func_0x0001c269();
  bVar5 = (byte)((uint)param_5 >> 8) & (byte)((uint)*(undefined2 *)(param_5 + param_1) >> 8);
  func_0x00017866();
  FUN_1000_48a5();
  pcVar1 = (char *)(param_3 + param_2 + -0x5000);
  *pcVar1 = *pcVar1 + bVar5;
  FUN_1000_6e8e();
  puVar6 = (undefined2 *)0x648c;
  puVar7 = (undefined2 *)0x6d8c;
  for (iVar4 = 0x240; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar3 = puVar7;
    puVar7 = puVar7 + 1;
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar3 = *puVar2;
  }
  return CONCAT22(in_stack_00000026,in_stack_00000022);
}


