/* 1000:602a */

int FUN_1000_602a(byte *param_1,int *param_2,undefined2 param_3,int param_4,undefined2 param_5)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte bVar7;
  undefined1 extraout_AL;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char extraout_AH;
  char cVar12;
  int iVar13;
  int iVar14;
  undefined2 uVar15;
  uint extraout_DX;
  int unaff_BP;
  uint *puVar16;
  uint *puVar17;
  int *piVar18;
  byte *pbVar19;
  int *piVar20;
  undefined1 *puVar21;
  undefined2 unaff_ES;
  int *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar22;
  bool bVar23;
  undefined4 uVar24;
  
  uVar24 = FUN_1000_5f56();
  piVar18 = (int *)*(undefined2 *)0x3e76;
LAB_1000_5f7a:
  iVar14 = (int)piVar18 + 1;
  do {
    while( true ) {
      uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
      pbVar3 = param_1;
      param_1 = param_1 + 1;
      bVar7 = *pbVar3;
      uVar8 = CONCAT11((char)((ulong)uVar24 >> 8),bVar7);
      uVar24 = CONCAT22(uVar15,uVar8);
      if (bVar7 < 0x20) goto FUN_1000_6259;
      if (bVar7 != 0x20) break;
LAB_1000_5fc7:
      param_2 = (int *)((int)param_2 + 1);
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
    }
    while (bVar7 = (byte)uVar8, bVar7 == 0x40) {
      pbVar3 = param_1;
      param_1 = param_1 + 1;
      uVar8 = (uint)*pbVar3;
      iVar13 = 0x1c;
      pbVar19 = (byte *)0x2847;
      bVar23 = true;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pbVar4 = pbVar19;
        pbVar19 = pbVar19 + 1;
        bVar23 = *pbVar3 == *pbVar4;
      } while (!bVar23);
      if (bVar23) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar14 = (*(code *)*(undefined2 *)((int)(pbVar19 + -0x2848) * 2 + 0x78bb))();
        return iVar14;
      }
    }
    if ((bVar7 < 0x80) || ((0x9f < bVar7 && (bVar7 < 0xe0)))) break;
    pbVar3 = param_1;
    param_1 = param_1 + 1;
    uVar24 = CONCAT22(uVar15,CONCAT11(bVar7,*pbVar3));
    if (CONCAT11(bVar7,*pbVar3) != 0x4081) {
      uVar8 = FUN_1000_8401();
      if ((0x2920 < uVar8) && (uVar8 < 0x2b7f)) {
        FUN_1000_5c7d();
        param_4 = 0x5fc7;
        uVar24 = func_0x000163a2();
        goto LAB_1000_5fc7;
      }
      FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
      param_4 = 0x5fb0;
      uVar24 = func_0x00016305();
    }
    param_2 = param_2 + 1;
    puVar1 = (uint *)(unaff_BP + -4);
    uVar8 = *puVar1;
    *puVar1 = *puVar1 - 2;
    if (uVar8 < 2) {
      *(undefined2 *)(unaff_BP + -4) = 0;
      goto LAB_1000_625d;
    }
  } while( true );
  uVar24 = func_0x000163ff();
  uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
  uVar8 = (int)uVar24 + 1;
  *(char *)(iVar14 + 2) = *(char *)(iVar14 + 2) >> 0xb;
  bVar7 = (byte)uVar8;
  if (bVar7 == 0) {
FUN_1000_6259:
    out(uVar15,uVar8);
LAB_1000_625d:
    iVar14 = 0x10;
    puVar17 = (uint *)(param_4 + -2);
    piVar18 = param_2;
    do {
      piVar20 = piVar18;
      puVar16 = puVar17;
      puVar17 = puVar16 + 1;
      uVar8 = *puVar16;
      piVar20[-0x28] = uVar8;
      piVar20[0x28] = uVar8;
      uVar9 = CONCAT11((char)uVar8,(char)(uVar8 >> 8));
      uVar6 = uVar9 * 2;
      cVar12 = ((uVar8 & 0x100) != 0) << 7;
      iVar13 = CONCAT11(cVar12,CARRY2(uVar9,uVar9));
      uVar8 = uVar9 | uVar6 | uVar9 >> 1;
      bVar7 = (byte)(uVar8 >> 8);
      iVar10 = CONCAT11((char)uVar8,bVar7);
      *(bool *)((int)piVar20 + -1) = CARRY2(uVar9,uVar9);
      *piVar20 = iVar10;
      *(char *)((int)piVar20 + 1) = cVar12;
      iVar14 = iVar14 + -1;
      piVar18 = piVar20 + 0x28;
    } while (iVar14 != 0);
    *(byte *)puVar17 = (byte)*puVar17 ^ bVar7;
    pbVar3 = (byte *)((int)piVar20 + 0x4f);
    *pbVar3 = *pbVar3 + bVar7;
    *(byte *)((int)piVar20 + 0x4f) = bVar7;
    puVar21 = (undefined1 *)((int)piVar20 + 0x51);
    uVar11 = iVar10 + 1;
    *(byte *)(puVar17 + uVar9) = (byte)puVar17[uVar9] + (byte)uVar11 + (((uint)param_2 & 1) != 0);
    uVar8 = (param_4 + -2) * 0x100;
    bVar23 = (uVar8 & 0x400) != 0;
    if ((uVar8 & 0x800) == 0) {
      *(byte *)(puVar16 + 0x1a4) = (byte)puVar16[0x1a4] + (char)(uVar11 >> 8);
      *(byte *)(piVar20 + 0x28) = (byte)*puVar17;
      puVar17 = puVar17 + !bVar23;
      puVar21 = puVar21 + uVar11 + (uint)bVar23 * -2;
      pbVar3 = (byte *)((int)puVar17 + iVar13 + 0x10);
      *pbVar3 = *pbVar3 | (byte)(uVar9 >> 1);
      *(byte *)(iVar13 + (int)puVar17) = *(byte *)(iVar13 + (int)puVar17) << 1;
      LOCK();
      pbVar3 = (byte *)((int)puVar17 + iVar13 + 0x30ac);
      *pbVar3 = *pbVar3 ^ (byte)uVar11;
      UNLOCK();
    }
    iVar10 = *(int *)0x32a8;
    FUN_1000_5aba(uVar11,(char)puVar17);
    puVar21[uVar6 + 0xbad9] = puVar21[uVar6 + 0xbad9] - (byte)iVar14;
    puVar21[uVar6] = puVar21[uVar6] + (char)((uint)iVar14 >> 8);
    piVar2 = (int *)(iVar13 + iVar10 + 0x10ff);
    *piVar2 = *piVar2 >> ((byte)iVar14 & 0x1f);
    iVar14 = iVar13;
    cVar12 = extraout_AH;
    do {
      for (; iVar14 != 0; iVar14 = iVar14 + -1) {
        puVar5 = puVar21;
        puVar21 = puVar21 + (uint)bVar23 * -2 + 1;
        *puVar5 = extraout_AL;
      }
      bVar22 = CARRY2((uint)puVar21,extraout_DX);
      puVar21 = puVar21 + extraout_DX;
      cVar12 = cVar12 + -1;
      iVar14 = iVar13;
    } while (cVar12 != '\0');
    return (byte)-bVar22 + 0x6108 + (uint)bVar22;
  }
  uVar8 = CONCAT11((char)(uVar8 >> 8),bVar7 - 0x10);
  uVar24 = CONCAT22(uVar15,uVar8);
  if (bVar7 < 0x10) goto FUN_1000_6259;
  *(char *)0x32a9 = bVar7 - 0x10;
  piVar18 = param_2;
  param_2 = unaff_CS;
  goto LAB_1000_5f7a;
}


