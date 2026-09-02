/* 1000:61a2 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016240) overlaps instruction at (ram,0x0001623f)
    */

int FUN_1000_61a2(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  int *piVar5;
  char cVar6;
  undefined1 uVar7;
  undefined1 extraout_AL;
  int in_AX;
  char cVar11;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar12;
  byte in_CL;
  byte bVar13;
  undefined2 in_DX;
  uint extraout_DX;
  byte bVar14;
  int in_BX;
  int iVar15;
  int iVar16;
  uint unaff_BP;
  uint uVar17;
  undefined1 *unaff_SI;
  undefined2 *puVar18;
  uint *puVar19;
  uint *puVar20;
  undefined2 *unaff_DI;
  int *piVar21;
  undefined1 *puVar22;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar23;
  bool bVar24;
  int iStack_18;
  undefined2 *in_stack_0000ffea;
  
  cVar12 = *(char *)((int)unaff_DI + unaff_BP + 0x3041);
  bVar13 = (byte)in_DX;
  bVar14 = (byte)(in_AX + 1);
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] | bVar14;
  cVar11 = (char)((uint)(in_AX + 1) >> 8);
  cVar6 = -((char)bVar14 >> 7);
  iVar15 = in_BX + 1;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ bVar13;
  uVar17 = unaff_BP & (uint)unaff_DI;
  *(undefined2 *)0x3e76 = unaff_DI;
  *(int *)(uVar17 + 2) = iVar15;
  bVar14 = (byte)iVar15 & unaff_SI[uVar17];
  iVar15 = CONCAT11((char)((uint)iVar15 >> 8),bVar14);
  out(*unaff_SI,CONCAT11((char)((uint)in_DX >> 8) + cVar12,bVar13));
  if (bVar14 == 0) {
    cVar12 = *(char *)(uVar17 + 0x30);
    puVar18 = (undefined2 *)0x612;
    *(byte *)(iVar15 + 0x612) = *(byte *)(iVar15 + 0x612) ^ bVar13;
    cVar12 = CARRY1(cVar6 + cVar12 + cVar11 * -0x42,*(byte *)0x5056);
    uVar7 = FUN_1000_5b27();
    out(0x23,uVar7);
    *(char *)(uVar17 + 0x3e50) = (*(char *)(uVar17 + 0x3e50) - (char)((uint)iVar15 >> 8)) - cVar12;
  }
  else {
    pbVar1 = unaff_SI + 1;
    *pbVar1 = *pbVar1 ^ in_CL;
    if ((POPCOUNT(*pbVar1) & 1U) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar18 = (undefined2 *)0x3e50;
    iStack_18 = CONCAT11(cVar11,cVar6);
    in_stack_0000ffea = unaff_DI;
  }
  *unaff_DI = *puVar18;
  unaff_DI[0x28] = puVar18[1];
  pbVar1 = (byte *)(puVar18 + 2);
  *pbVar1 = *pbVar1 ^ in_CL;
  *(byte *)(unaff_DI + 0x50) = *(byte *)(puVar18 + 2);
  iVar15 = 0x10;
  puVar20 = (uint *)(iStack_18 + -2);
  piVar5 = (int *)((int)unaff_DI + -0x411);
  do {
    piVar21 = piVar5;
    puVar19 = puVar20;
    puVar20 = puVar19 + 1;
    uVar17 = *puVar19;
    piVar21[-0x28] = uVar17;
    piVar21[0x28] = uVar17;
    uVar8 = CONCAT11((char)uVar17,(char)(uVar17 >> 8));
    uVar4 = uVar8 * 2;
    cVar12 = ((uVar17 & 0x100) != 0) << 7;
    iVar16 = CONCAT11(cVar12,CARRY2(uVar8,uVar8));
    uVar17 = uVar8 | uVar4 | uVar8 >> 1;
    bVar14 = (byte)(uVar17 >> 8);
    iVar9 = CONCAT11((char)uVar17,bVar14);
    *(bool *)((int)piVar21 + -1) = CARRY2(uVar8,uVar8);
    *piVar21 = iVar9;
    *(char *)((int)piVar21 + 1) = cVar12;
    iVar15 = iVar15 + -1;
    piVar5 = piVar21 + 0x28;
  } while (iVar15 != 0);
  *(byte *)puVar20 = (byte)*puVar20 ^ bVar14;
  pbVar1 = (byte *)((int)piVar21 + 0x4f);
  *pbVar1 = *pbVar1 + bVar14;
  *(byte *)((int)piVar21 + 0x4f) = bVar14;
  puVar22 = (undefined1 *)((int)piVar21 + 0x51);
  uVar10 = iVar9 + 1;
  *(byte *)(puVar20 + uVar8) =
       (byte)puVar20[uVar8] + (byte)uVar10 + (((uint)((int)unaff_DI + -0x411) & 1) != 0);
  uVar17 = (iStack_18 + -2) * 0x100;
  bVar24 = (uVar17 & 0x400) != 0;
  if ((uVar17 & 0x800) == 0) {
    *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar10 >> 8);
    *(byte *)(piVar21 + 0x28) = (byte)*puVar20;
    puVar20 = puVar20 + !bVar24;
    puVar22 = puVar22 + uVar10 + (uint)bVar24 * -2;
    pbVar1 = (byte *)((int)puVar20 + iVar16 + 0x10);
    *pbVar1 = *pbVar1 | (byte)(uVar8 >> 1);
    *(byte *)(iVar16 + (int)puVar20) = *(byte *)(iVar16 + (int)puVar20) << 1;
    LOCK();
    pbVar1 = (byte *)((int)puVar20 + iVar16 + 0x30ac);
    *pbVar1 = *pbVar1 ^ (byte)uVar10;
    UNLOCK();
  }
  iVar9 = *(int *)0x32a8;
  FUN_1000_5aba(uVar10,(char)puVar20);
  puVar22[uVar4 + 0xbad9] = puVar22[uVar4 + 0xbad9] - (byte)iVar15;
  puVar22[uVar4] = puVar22[uVar4] + (char)((uint)iVar15 >> 8);
  piVar2 = (int *)(iVar16 + iVar9 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)iVar15 & 0x1f);
  iVar15 = iVar16;
  cVar12 = extraout_AH;
  do {
    for (; iVar15 != 0; iVar15 = iVar15 + -1) {
      puVar3 = puVar22;
      puVar22 = puVar22 + (uint)bVar24 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar23 = CARRY2((uint)puVar22,extraout_DX);
    puVar22 = puVar22 + extraout_DX;
    cVar12 = cVar12 + -1;
    iVar15 = iVar16;
  } while (cVar12 != '\0');
  return (byte)-bVar23 + 0x6108 + (uint)bVar23;
}


