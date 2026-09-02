/* 1000:16c6 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001171f) overlaps instruction at (ram,0x0001171e)
    */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_16c6(int param_1,int param_2,int param_3,undefined2 param_4,int param_5)

{
  char *pcVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  int iVar5;
  int in_BX;
  byte bVar6;
  undefined1 *puVar7;
  int unaff_BP;
  int unaff_SI;
  undefined2 *puVar8;
  int unaff_DI;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  undefined2 in_stack_00000020;
  undefined2 in_stack_00000022;
  undefined2 in_stack_00000026;
  
  iVar5 = *(int *)0x3bc2;
  bVar10 = iVar5 != -1;
  if (iVar5 == -1) {
    *(undefined2 *)0x3bc2 = 0xffff;
    *(undefined2 *)0x346e = 0xffff;
    FUN_1000_5bfc();
    if (!bVar10) {
      func_0x00010081();
      param_5 = in_BX;
      param_3 = unaff_BP;
      param_2 = unaff_SI;
      param_1 = unaff_DI;
    }
  }
  else {
    param_5 = in_BX;
    param_3 = unaff_BP;
    param_2 = unaff_SI;
    param_1 = unaff_DI;
    if (iRam00013bd6 != 0) {
      puVar7 = (undefined1 *)(iVar5 + -2);
      *(undefined2 *)(iVar5 + -2) = 0x16df;
      uVar4 = FUN_1000_4616();
      *(undefined2 *)(puVar7 + -2) = uVar4;
      *(undefined2 *)(puVar7 + -4) = 0x16e6;
      func_0x000108db();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  *(undefined2 *)0x3bd4 = 0xffff;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_7860();
  FUN_1000_494f();
  FUN_1000_48a5();
  FUN_1000_6e71();
  func_0x0001c269();
  bVar6 = (byte)((uint)param_5 >> 8) & (byte)((uint)*(undefined2 *)(param_5 + param_1) >> 8);
  func_0x00017866();
  FUN_1000_48a5();
  pcVar1 = (char *)(param_3 + param_2 + -0x5000);
  *pcVar1 = *pcVar1 + bVar6;
  FUN_1000_6e8e();
  puVar8 = (undefined2 *)0x648c;
  puVar9 = (undefined2 *)0x6d8c;
  for (iVar5 = 0x240; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar3 = puVar9;
    puVar9 = puVar9 + 1;
    puVar2 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar3 = *puVar2;
  }
  return CONCAT22(in_stack_00000026,in_stack_00000022);
}


