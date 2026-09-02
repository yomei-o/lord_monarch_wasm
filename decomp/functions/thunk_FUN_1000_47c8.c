/* 1000:47ab */

/* WARNING: Control flow encountered bad instruction data */

void thunk_FUN_1000_47c8(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  undefined2 in_CX;
  char cVar7;
  undefined2 uVar5;
  int iVar6;
  uint in_BX;
  uint uVar8;
  int unaff_BP;
  undefined1 *unaff_SI;
  int *piVar9;
  int *piVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  char in_CF;
  undefined4 uVar11;
  undefined1 *in_stack_00000000;
  uint uVar12;
  
  iVar6 = *(int *)0x3bde;
  cVar7 = (char)((uint)in_CX >> 8);
  cVar3 = ((char)in_CX - unaff_SI[unaff_BP]) - in_CF;
  if (iVar6 != *(int *)0x32a4) {
                    /* WARNING: Call to offcut address within same function */
    func_0x000147e3();
    *(int *)0x32a4 = iVar6;
    in_stack_00000000 = (undefined1 *)0x47e1;
    FUN_1000_8194();
  }
  *in_stack_00000000 = *unaff_SI;
  uVar5 = CONCAT11(cVar7 - (unaff_SI + 1)[unaff_BP + -0x17f7],cVar3);
  in_stack_00000000[1] = unaff_SI[1];
  uVar8 = in_BX & 0xff;
  uVar11 = (*(code *)*(undefined2 *)(uVar8 - 0x3d))();
  piVar10 = (int *)0x3eaa;
  piVar9 = (int *)((*(int *)0x3bc2 + -100) * 0x10 + -0x5c2);
  iVar6 = 8;
  if (*piVar9 == 0) {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      piVar1 = piVar10;
      piVar10 = piVar10 + 1;
      *piVar1 = 0x4081;
    }
  }
  else {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      piVar2 = piVar10;
      piVar10 = piVar10 + 1;
      piVar1 = piVar9;
      piVar9 = piVar9 + 1;
      *piVar2 = *piVar1;
    }
  }
  bVar4 = 0;
  *(undefined2 *)0x3bde = 0;
  *(undefined2 *)0x32a6 = 1;
  *(undefined2 *)0x32a2 = 0xffff;
  *(undefined2 *)0x32a4 = 0xffff;
  uVar12 = uVar8;
  FUN_1000_6b3e(in_stack_00000000 + 2,unaff_SI + 2);
  FUN_1000_45d0();
  FUN_1000_38ed();
  *(uint *)(uVar8 + (int)piVar10) = *(uint *)(uVar8 + (int)piVar10) | uVar8;
  FUN_1000_6b3d();
  FUN_1000_5acf(register0x00000010,uVar12,(int)((ulong)uVar11 >> 0x10),uVar5,(int)uVar11);
  *(byte *)(unaff_BP + 0x123f) = *(byte *)(unaff_BP + 0x123f) & bVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


