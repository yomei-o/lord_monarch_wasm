/* 1000:4754 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_4754(void)

{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  byte in_AL;
  char cVar4;
  byte bVar5;
  undefined2 in_CX;
  char cVar8;
  undefined2 uVar6;
  int iVar7;
  uint in_BX;
  uint uVar9;
  int unaff_BP;
  undefined1 *unaff_SI;
  int *piVar10;
  byte *unaff_DI;
  int *piVar11;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  undefined4 uVar12;
  undefined1 *in_stack_00000000;
  uint uVar13;
  
  pbVar1 = unaff_SI + in_BX;
  *pbVar1 = *pbVar1 | in_AL ^ *unaff_DI;
  if (*pbVar1 == 0) {
    return;
  }
  iVar7 = *(int *)0x3bde;
  cVar4 = (char)in_CX - unaff_SI[unaff_BP];
  cVar8 = (char)((uint)in_CX >> 8);
  if (iVar7 != *(int *)0x32a4) {
                    /* WARNING: Call to offcut address within same function */
    func_0x000147e3();
    *(int *)0x32a4 = iVar7;
    in_stack_00000000 = (undefined1 *)0x47e1;
    FUN_1000_8194();
  }
  *in_stack_00000000 = *unaff_SI;
  uVar6 = CONCAT11(cVar8 - (unaff_SI + 1)[unaff_BP + -0x17f7],cVar4);
  in_stack_00000000[1] = unaff_SI[1];
  uVar9 = in_BX & 0xff;
  uVar12 = (*(code *)*(undefined2 *)(uVar9 - 0x3d))();
  piVar11 = (int *)0x3eaa;
  piVar10 = (int *)((*(int *)0x3bc2 + -100) * 0x10 + -0x5c2);
  iVar7 = 8;
  if (*piVar10 == 0) {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      piVar2 = piVar11;
      piVar11 = piVar11 + 1;
      *piVar2 = 0x4081;
    }
  }
  else {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      piVar3 = piVar11;
      piVar11 = piVar11 + 1;
      piVar2 = piVar10;
      piVar10 = piVar10 + 1;
      *piVar3 = *piVar2;
    }
  }
  bVar5 = 0;
  *(undefined2 *)0x3bde = 0;
  *(undefined2 *)0x32a6 = 1;
  *(undefined2 *)0x32a2 = 0xffff;
  *(undefined2 *)0x32a4 = 0xffff;
  uVar13 = uVar9;
  FUN_1000_6b3e(in_stack_00000000 + 2,unaff_SI + 2);
  FUN_1000_45d0();
  FUN_1000_38ed();
  *(uint *)(uVar9 + (int)piVar11) = *(uint *)(uVar9 + (int)piVar11) | uVar9;
  FUN_1000_6b3d();
  FUN_1000_5acf(register0x00000010,uVar13,(int)((ulong)uVar12 >> 0x10),uVar6,(int)uVar12);
  *(byte *)(unaff_BP + 0x123f) = *(byte *)(unaff_BP + 0x123f) & bVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


