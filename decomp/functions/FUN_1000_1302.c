/* 1000:1302 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011345) overlaps instruction at (ram,0x00011344)
    */

undefined4 FUN_1000_1302(undefined2 param_1,undefined2 param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  int iVar9;
  byte in_CL;
  uint in_DX;
  sqword *in_BX;
  uint unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  longdouble in_ST0;
  longdouble in_ST1;
  int in_stack_00000000;
  
  pcVar1 = (char *)((int)in_BX + unaff_DI + 0x20);
  *pcVar1 = *pcVar1 + -0x1c;
  bVar5 = *(byte *)(unaff_SI + 0x1f);
  uVar8 = (uint)bVar5;
  *(undefined1 *)0x3b4c = 0;
  if (bVar5 < 6) {
    *(uint *)((int)in_BX + unaff_SI) = *(uint *)((int)in_BX + unaff_SI) | in_DX;
    uVar8 = uVar8 * 2;
    unaff_SI = unaff_SI + uVar8;
  }
  else {
    *(undefined1 *)(unaff_BP + unaff_DI) = *(undefined1 *)(unaff_BP + unaff_DI);
  }
  iVar9 = uVar8 * 0x10;
  *(int *)0x3b4d = iVar9 + 0x3a3a;
  *(byte *)(iVar9 + 0x3a59) = *(byte *)(iVar9 + 0x3a59) & 0x40;
  *(byte *)(iVar9 + 0x3a59) = *(byte *)(iVar9 + 0x3a59) | 0xf;
  uVar6 = (ulong)*(uint *)((int)in_BX + unaff_SI + -0x458a);
  uVar7 = CONCAT22(in_DX,iVar9 + 0x3a3a);
  iVar9 = (int)(uVar7 / uVar6);
  *in_BX = (sqword)ROUND(in_ST0);
  *(undefined1 *)(unaff_SI + 9) = 1;
  piVar2 = (int *)((int)in_BX + iVar9);
  *piVar2 = *piVar2 - (int)(uVar7 % uVar6);
  uVar8 = CONCAT11((char)((uint)unaff_SI >> 8),0x76);
  out(0x3fdf,0x76);
  if ((POPCOUNT(unaff_BP - *(int *)((int)in_BX + iVar9) & 0xff) & 1U) != 0) {
    return CONCAT22((int)unaff_BP >> 0xf,unaff_BP >> (in_CL & 0x1f));
  }
  iVar9 = *(int *)0x654d;
  puVar3 = (uint *)((int)in_BX + 0x39);
  uVar4 = *puVar3;
  *puVar3 = *puVar3 - uVar8;
  pcVar1 = (char *)(uVar8 + iVar9 + 0x3b40);
  *pcVar1 = *pcVar1 + (char)(unaff_BP >> 8) + (uVar4 < uVar8);
  FUN_1000_71d9();
  *(float *)(param_3 + in_stack_00000000 + -0x2a93) = (float)in_ST1;
  out(0x71,(char)*(undefined2 *)0x3b4a);
  out(0x71,(char)((uint)*(undefined2 *)0x3b4a >> 8));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


