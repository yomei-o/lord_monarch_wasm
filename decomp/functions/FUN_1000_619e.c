/* 1000:619e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016240) overlaps instruction at (ram,0x0001623f)
    */

int FUN_1000_619e(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  int *piVar5;
  char cVar6;
  undefined1 uVar7;
  undefined1 extraout_AL;
  int iVar8;
  char cVar12;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char extraout_AH;
  char cVar13;
  byte in_CL;
  byte bVar14;
  uint extraout_DX;
  byte bVar15;
  int in_BX;
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
  undefined4 uVar25;
  int iStack_16;
  undefined2 *in_stack_0000ffec;
  
  uVar25 = FUN_1000_771b();
  iVar8 = (int)uVar25 + 1;
  cVar13 = *(char *)((int)unaff_DI + unaff_BP + 0x3041);
  bVar14 = (byte)((ulong)uVar25 >> 0x10);
  bVar15 = (byte)iVar8;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] | bVar15;
  cVar12 = (char)((uint)iVar8 >> 8);
  cVar6 = -((char)bVar15 >> 7);
  in_BX = in_BX + 1;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ bVar14;
  uVar17 = unaff_BP & (uint)unaff_DI;
  *(undefined2 *)0x3e76 = unaff_DI;
  *(int *)(uVar17 + 2) = in_BX;
  bVar15 = (byte)in_BX & unaff_SI[uVar17];
  iVar8 = CONCAT11((char)((uint)in_BX >> 8),bVar15);
  out(*unaff_SI,CONCAT11((char)((ulong)uVar25 >> 0x18) + cVar13,bVar14));
  if (bVar15 == 0) {
    cVar13 = *(char *)(uVar17 + 0x30);
    puVar18 = (undefined2 *)0x612;
    *(byte *)(iVar8 + 0x612) = *(byte *)(iVar8 + 0x612) ^ bVar14;
    cVar13 = CARRY1(cVar6 + cVar13 + cVar12 * -0x42,*(byte *)0x5056);
    uVar7 = FUN_1000_5b27();
    out(0x23,uVar7);
    *(char *)(uVar17 + 0x3e50) = (*(char *)(uVar17 + 0x3e50) - (char)((uint)iVar8 >> 8)) - cVar13;
  }
  else {
    pbVar1 = unaff_SI + 1;
    *pbVar1 = *pbVar1 ^ in_CL;
    if ((POPCOUNT(*pbVar1) & 1U) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar18 = (undefined2 *)0x3e50;
    iStack_16 = CONCAT11(cVar12,cVar6);
    in_stack_0000ffec = unaff_DI;
  }
  *unaff_DI = *puVar18;
  unaff_DI[0x28] = puVar18[1];
  pbVar1 = (byte *)(puVar18 + 2);
  *pbVar1 = *pbVar1 ^ in_CL;
  *(byte *)(unaff_DI + 0x50) = *(byte *)(puVar18 + 2);
  iVar8 = 0x10;
  puVar20 = (uint *)(iStack_16 + -2);
  piVar5 = (int *)((int)unaff_DI + -0x411);
  do {
    piVar21 = piVar5;
    puVar19 = puVar20;
    puVar20 = puVar19 + 1;
    uVar17 = *puVar19;
    piVar21[-0x28] = uVar17;
    piVar21[0x28] = uVar17;
    uVar9 = CONCAT11((char)uVar17,(char)(uVar17 >> 8));
    uVar4 = uVar9 * 2;
    cVar13 = ((uVar17 & 0x100) != 0) << 7;
    iVar16 = CONCAT11(cVar13,CARRY2(uVar9,uVar9));
    uVar17 = uVar9 | uVar4 | uVar9 >> 1;
    bVar15 = (byte)(uVar17 >> 8);
    iVar10 = CONCAT11((char)uVar17,bVar15);
    *(bool *)((int)piVar21 + -1) = CARRY2(uVar9,uVar9);
    *piVar21 = iVar10;
    *(char *)((int)piVar21 + 1) = cVar13;
    iVar8 = iVar8 + -1;
    piVar5 = piVar21 + 0x28;
  } while (iVar8 != 0);
  *(byte *)puVar20 = (byte)*puVar20 ^ bVar15;
  pbVar1 = (byte *)((int)piVar21 + 0x4f);
  *pbVar1 = *pbVar1 + bVar15;
  *(byte *)((int)piVar21 + 0x4f) = bVar15;
  puVar22 = (undefined1 *)((int)piVar21 + 0x51);
  uVar11 = iVar10 + 1;
  *(byte *)(puVar20 + uVar9) =
       (byte)puVar20[uVar9] + (byte)uVar11 + (((uint)((int)unaff_DI + -0x411) & 1) != 0);
  uVar17 = (iStack_16 + -2) * 0x100;
  bVar24 = (uVar17 & 0x400) != 0;
  if ((uVar17 & 0x800) == 0) {
    *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar11 >> 8);
    *(byte *)(piVar21 + 0x28) = (byte)*puVar20;
    puVar20 = puVar20 + !bVar24;
    puVar22 = puVar22 + uVar11 + (uint)bVar24 * -2;
    pbVar1 = (byte *)((int)puVar20 + iVar16 + 0x10);
    *pbVar1 = *pbVar1 | (byte)(uVar9 >> 1);
    *(byte *)(iVar16 + (int)puVar20) = *(byte *)(iVar16 + (int)puVar20) << 1;
    LOCK();
    pbVar1 = (byte *)((int)puVar20 + iVar16 + 0x30ac);
    *pbVar1 = *pbVar1 ^ (byte)uVar11;
    UNLOCK();
  }
  iVar10 = *(int *)0x32a8;
  FUN_1000_5aba(uVar11,(char)puVar20);
  puVar22[uVar4 + 0xbad9] = puVar22[uVar4 + 0xbad9] - (byte)iVar8;
  puVar22[uVar4] = puVar22[uVar4] + (char)((uint)iVar8 >> 8);
  piVar2 = (int *)(iVar16 + iVar10 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)iVar8 & 0x1f);
  iVar8 = iVar16;
  cVar13 = extraout_AH;
  do {
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      puVar3 = puVar22;
      puVar22 = puVar22 + (uint)bVar24 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar23 = CARRY2((uint)puVar22,extraout_DX);
    puVar22 = puVar22 + extraout_DX;
    cVar13 = cVar13 + -1;
    iVar8 = iVar16;
  } while (cVar13 != '\0');
  return (byte)-bVar23 + 0x6108 + (uint)bVar23;
}


