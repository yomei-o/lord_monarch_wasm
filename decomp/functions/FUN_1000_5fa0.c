/* 1000:5fa0 */

int FUN_1000_5fa0(undefined2 param_1)

{
  uint *puVar1;
  byte *pbVar2;
  int *piVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  uint uVar6;
  int *piVar7;
  byte bVar8;
  undefined1 extraout_AL;
  uint in_AX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  char extraout_AH;
  char cVar13;
  int iVar14;
  undefined2 uVar15;
  uint extraout_DX;
  int in_BX;
  int iVar16;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar17;
  uint *puVar18;
  int *unaff_DI;
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
  int iVar25;
  
code_r0x00015fa0:
  if ((0x2920 < in_AX) && (in_AX < 0x2b7f)) {
    FUN_1000_5c7d();
    iVar25 = 0x5fc7;
    uVar24 = func_0x000163a2();
    goto LAB_1000_5fc7;
  }
  FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
  iVar25 = 0x5fb0;
  uVar24 = func_0x00016305();
LAB_1000_5fb0:
  unaff_DI = unaff_DI + 1;
  puVar1 = (uint *)(unaff_BP + -4);
  uVar10 = *puVar1;
  *puVar1 = *puVar1 - 2;
  if (uVar10 < 2) {
    *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
    iVar14 = 0x10;
    puVar18 = (uint *)(iVar25 + -2);
    piVar7 = unaff_DI;
    do {
      piVar20 = piVar7;
      puVar17 = puVar18;
      puVar18 = puVar17 + 1;
      uVar10 = *puVar17;
      piVar20[-0x28] = uVar10;
      piVar20[0x28] = uVar10;
      uVar9 = CONCAT11((char)uVar10,(char)(uVar10 >> 8));
      uVar6 = uVar9 * 2;
      cVar13 = ((uVar10 & 0x100) != 0) << 7;
      iVar16 = CONCAT11(cVar13,CARRY2(uVar9,uVar9));
      uVar10 = uVar9 | uVar6 | uVar9 >> 1;
      bVar8 = (byte)(uVar10 >> 8);
      iVar11 = CONCAT11((char)uVar10,bVar8);
      *(bool *)((int)piVar20 + -1) = CARRY2(uVar9,uVar9);
      *piVar20 = iVar11;
      *(char *)((int)piVar20 + 1) = cVar13;
      iVar14 = iVar14 + -1;
      piVar7 = piVar20 + 0x28;
    } while (iVar14 != 0);
    *(byte *)puVar18 = (byte)*puVar18 ^ bVar8;
    pbVar2 = (byte *)((int)piVar20 + 0x4f);
    *pbVar2 = *pbVar2 + bVar8;
    *(byte *)((int)piVar20 + 0x4f) = bVar8;
    puVar21 = (undefined1 *)((int)piVar20 + 0x51);
    uVar12 = iVar11 + 1;
    *(byte *)(puVar18 + uVar9) = (byte)puVar18[uVar9] + (byte)uVar12 + (((uint)unaff_DI & 1) != 0);
    uVar10 = (iVar25 + -2) * 0x100;
    bVar23 = (uVar10 & 0x400) != 0;
    if ((uVar10 & 0x800) == 0) {
      *(byte *)(puVar17 + 0x1a4) = (byte)puVar17[0x1a4] + (char)(uVar12 >> 8);
      *(byte *)(piVar20 + 0x28) = (byte)*puVar18;
      puVar18 = puVar18 + !bVar23;
      puVar21 = puVar21 + uVar12 + (uint)bVar23 * -2;
      pbVar2 = (byte *)((int)puVar18 + iVar16 + 0x10);
      *pbVar2 = *pbVar2 | (byte)(uVar9 >> 1);
      *(byte *)(iVar16 + (int)puVar18) = *(byte *)(iVar16 + (int)puVar18) << 1;
      LOCK();
      pbVar2 = (byte *)((int)puVar18 + iVar16 + 0x30ac);
      *pbVar2 = *pbVar2 ^ (byte)uVar12;
      UNLOCK();
    }
    iVar25 = *(int *)0x32a8;
    FUN_1000_5aba(uVar12,(char)puVar18);
    puVar21[uVar6 + 0xbad9] = puVar21[uVar6 + 0xbad9] - (byte)iVar14;
    puVar21[uVar6] = puVar21[uVar6] + (char)((uint)iVar14 >> 8);
    piVar3 = (int *)(iVar16 + iVar25 + 0x10ff);
    *piVar3 = *piVar3 >> ((byte)iVar14 & 0x1f);
    iVar25 = iVar16;
    cVar13 = extraout_AH;
    do {
      for (; iVar25 != 0; iVar25 = iVar25 + -1) {
        puVar5 = puVar21;
        puVar21 = puVar21 + (uint)bVar23 * -2 + 1;
        *puVar5 = extraout_AL;
      }
      bVar22 = CARRY2((uint)puVar21,extraout_DX);
      puVar21 = puVar21 + extraout_DX;
      cVar13 = cVar13 + -1;
      iVar25 = iVar16;
    } while (cVar13 != '\0');
    return (byte)-bVar22 + 0x6108 + (uint)bVar22;
  }
LAB_1000_5f7e:
  do {
    uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
    pbVar2 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    bVar8 = *pbVar2;
    uVar10 = CONCAT11((char)((ulong)uVar24 >> 8),bVar8);
    uVar24 = CONCAT22(uVar15,uVar10);
    if (bVar8 < 0x20) {
FUN_1000_6259:
      out(uVar15,uVar10);
      goto LAB_1000_625d;
    }
    if (bVar8 == 0x20) {
LAB_1000_5fc7:
      unaff_DI = (int *)((int)unaff_DI + 1);
      piVar3 = (int *)(unaff_BP + -4);
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar8 = (byte)uVar10, bVar8 == 0x40) {
      pbVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar10 = (uint)*pbVar2;
      iVar14 = 0x1c;
      pbVar19 = (byte *)0x2847;
      bVar23 = true;
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pbVar4 = pbVar19;
        pbVar19 = pbVar19 + 1;
        bVar23 = *pbVar2 == *pbVar4;
      } while (!bVar23);
      if (bVar23) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar25 = (*(code *)*(undefined2 *)((int)(pbVar19 + -0x2848) * 2 + 0x78bb))();
        return iVar25;
      }
    }
    if ((0x7f < bVar8) && ((bVar8 < 0xa0 || (0xdf < bVar8)))) break;
    uVar24 = func_0x000163ff();
    uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
    uVar10 = (int)uVar24 + 1;
    *(char *)(in_BX + 2) = *(char *)(in_BX + 2) >> 0xb;
    bVar8 = (byte)uVar10;
    if (bVar8 == 0) goto FUN_1000_6259;
    uVar10 = CONCAT11((char)(uVar10 >> 8),bVar8 - 0x10);
    uVar24 = CONCAT22(uVar15,uVar10);
    if (bVar8 < 0x10) goto FUN_1000_6259;
    *(char *)0x32a9 = bVar8 - 0x10;
    in_BX = (int)unaff_DI + 1;
    unaff_DI = unaff_CS;
  } while( true );
  pbVar2 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  uVar24 = CONCAT22(uVar15,CONCAT11(bVar8,*pbVar2));
  if (CONCAT11(bVar8,*pbVar2) != 0x4081) goto code_r0x00015f9d;
  goto LAB_1000_5fb0;
code_r0x00015f9d:
  in_AX = FUN_1000_8401();
  goto code_r0x00015fa0;
}


