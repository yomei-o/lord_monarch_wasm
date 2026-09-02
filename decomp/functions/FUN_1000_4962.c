/* 1000:4962 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_4962(undefined1 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  undefined2 in_CX;
  char cVar8;
  undefined2 extraout_DX;
  uint in_DX;
  uint in_BX;
  int unaff_BP;
  int *piVar9;
  undefined1 *unaff_SI;
  int *piVar10;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  undefined2 *puVar11;
  undefined2 uVar12;
  
  uVar3 = *(int *)0x3bda + 1;
  if (0x2f < uVar3) {
    uVar3 = 0;
  }
  *(uint *)0x1fda = uVar3;
  *(uint *)(unaff_DI + -0x2b) = *(uint *)(unaff_DI + -0x2b) ^ in_DX;
  cVar8 = (char)((uint)in_CX >> 8);
  uVar4 = 0x58;
  FUN_1000_8194();
  *param_1 = *unaff_SI;
  uVar6 = CONCAT11(cVar8 - (unaff_SI + 1)[unaff_BP + -0x17f7],uVar4);
  param_1[1] = unaff_SI[1];
  in_BX = in_BX & 0xff;
  puVar11 = (undefined2 *)&stack0x0002;
  (*(code *)*(undefined2 *)(in_BX - 0x3d))();
  piVar10 = (int *)0x3eaa;
  piVar9 = (int *)((*(int *)0x3bc2 + -100) * 0x10 + -0x5c2);
  iVar7 = 8;
  if (*piVar9 == 0) {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      piVar1 = piVar10;
      piVar10 = piVar10 + 1;
      *piVar1 = 0x4081;
    }
  }
  else {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      piVar2 = piVar10;
      piVar10 = piVar10 + 1;
      piVar1 = piVar9;
      piVar9 = piVar9 + 1;
      *piVar2 = *piVar1;
    }
  }
  bVar5 = 0;
  *(undefined2 *)0x3bde = 0;
  *(undefined2 *)0x32a6 = 1;
  *(undefined2 *)0x32a2 = 0xffff;
  *(undefined2 *)0x32a4 = 0xffff;
  uVar3 = in_BX;
  uVar12 = extraout_DX;
  FUN_1000_6b3e(param_1 + 2,unaff_SI + 2);
  FUN_1000_45d0();
  FUN_1000_38ed();
  *(uint *)(in_BX + (int)piVar10) = *(uint *)(in_BX + (int)piVar10) | in_BX;
  FUN_1000_6b3d();
  FUN_1000_5acf(puVar11,uVar3,uVar12,uVar6);
  *(byte *)(unaff_BP + 0x123f) = *(byte *)(unaff_BP + 0x123f) & bVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


