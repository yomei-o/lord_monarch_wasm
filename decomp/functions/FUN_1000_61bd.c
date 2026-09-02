/* 1000:61bd */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016240) overlaps instruction at (ram,0x0001623f)
    */

int FUN_1000_61bd(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined1 uVar6;
  undefined1 extraout_AL;
  int in_AX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar12;
  byte in_CL;
  int iVar13;
  undefined2 in_DX;
  uint extraout_DX;
  int in_BX;
  int iVar14;
  int unaff_BP;
  undefined1 *unaff_SI;
  byte *pbVar15;
  uint *puVar16;
  uint *puVar17;
  undefined2 *unaff_DI;
  int *piVar18;
  undefined1 *puVar19;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  bool bVar20;
  bool in_ZF;
  bool bVar21;
  int iStack_14;
  undefined2 *in_stack_0000ffee;
  byte bVar11;
  
  pbVar15 = unaff_SI + 1;
  out(*unaff_SI,in_DX);
  if (in_CF || in_ZF) {
    in_AX = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + *(char *)(unaff_BP + 0x30));
    pbVar15 = (byte *)0x612;
  }
  else if (!in_CF && !in_ZF) {
    pbVar1 = pbVar15;
    *pbVar1 = *pbVar1 ^ in_CL;
    if ((POPCOUNT(*pbVar1) & 1U) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    pbVar15 = (byte *)0x3e50;
    iStack_14 = in_AX;
    in_stack_0000ffee = unaff_DI;
    goto code_r0x00016244;
  }
  pbVar15[in_BX] = pbVar15[in_BX] ^ (byte)in_DX;
  cVar12 = CARRY1((char)in_AX + (char)((uint)in_AX >> 8) * -0x42,*(byte *)0x5056);
  uVar6 = FUN_1000_5b27();
  out(0x23,uVar6);
  *(char *)(unaff_BP + 0x3e50) = (*(char *)(unaff_BP + 0x3e50) - (char)((uint)in_BX >> 8)) - cVar12;
code_r0x00016244:
  *unaff_DI = *(undefined2 *)pbVar15;
  unaff_DI[0x28] = *(undefined2 *)(pbVar15 + 2);
  pbVar1 = pbVar15 + 4;
  *pbVar1 = *pbVar1 ^ in_CL;
  *(byte *)(unaff_DI + 0x50) = pbVar15[4];
  iVar13 = 0x10;
  puVar17 = (uint *)(iStack_14 + -2);
  piVar5 = (int *)((int)unaff_DI + -0x411);
  do {
    piVar18 = piVar5;
    puVar16 = puVar17;
    puVar17 = puVar16 + 1;
    uVar8 = *puVar16;
    piVar18[-0x28] = uVar8;
    piVar18[0x28] = uVar8;
    uVar7 = CONCAT11((char)uVar8,(char)(uVar8 >> 8));
    uVar4 = uVar7 * 2;
    cVar12 = ((uVar8 & 0x100) != 0) << 7;
    iVar14 = CONCAT11(cVar12,CARRY2(uVar7,uVar7));
    uVar8 = uVar7 | uVar4 | uVar7 >> 1;
    bVar11 = (byte)(uVar8 >> 8);
    iVar9 = CONCAT11((char)uVar8,bVar11);
    *(bool *)((int)piVar18 + -1) = CARRY2(uVar7,uVar7);
    *piVar18 = iVar9;
    *(char *)((int)piVar18 + 1) = cVar12;
    iVar13 = iVar13 + -1;
    piVar5 = piVar18 + 0x28;
  } while (iVar13 != 0);
  *(byte *)puVar17 = (byte)*puVar17 ^ bVar11;
  pbVar1 = (byte *)((int)piVar18 + 0x4f);
  *pbVar1 = *pbVar1 + bVar11;
  *(byte *)((int)piVar18 + 0x4f) = bVar11;
  puVar19 = (undefined1 *)((int)piVar18 + 0x51);
  uVar10 = iVar9 + 1;
  *(byte *)(puVar17 + uVar7) =
       (byte)puVar17[uVar7] + (byte)uVar10 + (((uint)((int)unaff_DI + -0x411) & 1) != 0);
  uVar8 = (iStack_14 + -2) * 0x100;
  bVar21 = (uVar8 & 0x400) != 0;
  if ((uVar8 & 0x800) == 0) {
    *(byte *)(puVar16 + 0x1a4) = (byte)puVar16[0x1a4] + (char)(uVar10 >> 8);
    *(byte *)(piVar18 + 0x28) = (byte)*puVar17;
    puVar17 = puVar17 + !bVar21;
    puVar19 = puVar19 + uVar10 + (uint)bVar21 * -2;
    pbVar1 = (byte *)((int)puVar17 + iVar14 + 0x10);
    *pbVar1 = *pbVar1 | (byte)(uVar7 >> 1);
    *(byte *)(iVar14 + (int)puVar17) = *(byte *)(iVar14 + (int)puVar17) << 1;
    LOCK();
    pbVar1 = (byte *)((int)puVar17 + iVar14 + 0x30ac);
    *pbVar1 = *pbVar1 ^ (byte)uVar10;
    UNLOCK();
  }
  iVar9 = *(int *)0x32a8;
  FUN_1000_5aba(uVar10,(char)puVar17);
  puVar19[uVar4 + 0xbad9] = puVar19[uVar4 + 0xbad9] - (byte)iVar13;
  puVar19[uVar4] = puVar19[uVar4] + (char)((uint)iVar13 >> 8);
  piVar2 = (int *)(iVar14 + iVar9 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)iVar13 & 0x1f);
  iVar13 = iVar14;
  cVar12 = extraout_AH;
  do {
    for (; iVar13 != 0; iVar13 = iVar13 + -1) {
      puVar3 = puVar19;
      puVar19 = puVar19 + (uint)bVar21 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar20 = CARRY2((uint)puVar19,extraout_DX);
    puVar19 = puVar19 + extraout_DX;
    cVar12 = cVar12 + -1;
    iVar13 = iVar14;
  } while (cVar12 != '\0');
  return (byte)-bVar20 + 0x6108 + (uint)bVar20;
}


