/* 1000:60bb */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_60bb(void)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  byte in_AL;
  byte bVar6;
  byte extraout_AL;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar13;
  int iVar12;
  int in_CX;
  char cVar14;
  byte bVar16;
  undefined2 uVar15;
  undefined2 in_DX;
  uint extraout_DX;
  int in_BX;
  byte *pbVar17;
  int iVar18;
  int unaff_BP;
  byte *pbVar19;
  int unaff_SI;
  uint *puVar20;
  uint *puVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *unaff_DI;
  byte *pbVar24;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar25;
  bool bVar26;
  undefined4 uVar27;
  byte *pbVar28;
  undefined2 in_stack_0000ffec;
  byte *pbStack_10;
  byte *pbStack_e;
  byte *pbStack_4;
  byte *pbStack_2;
  byte bVar11;
  
  *unaff_DI = in_AL;
  unaff_DI[1] = in_AL;
  *(char *)(unaff_SI + 5) = *(char *)(unaff_SI + 5) + (char)((uint)in_DX >> 8);
  piVar4 = (int *)*(undefined2 *)(in_BX + 2);
  pbStack_2 = (byte *)0x60cd;
  pbVar28 = (byte *)func_0x00015eef();
  pbStack_2 = (byte *)((ulong)pbVar28 >> 0x10);
  pbVar17 = (byte *)(in_BX + 6);
  bVar6 = (byte)pbVar28;
  *(byte *)(unaff_BP + (int)piVar4) = *(byte *)(unaff_BP + (int)piVar4) ^ bVar6;
  pbVar19 = (byte *)(unaff_BP + -1);
  pbVar19[(int)piVar4] = pbVar19[(int)piVar4] & bVar6;
  *(byte *)0xed32 = *(byte *)0xed32 ^ (byte)pbVar17;
  *piVar4 = *piVar4 + in_CX;
  bVar11 = (byte)((uint)in_CX >> 8);
  cVar13 = bVar11 + pbVar17[(int)unaff_CS];
  iVar12 = CONCAT11(cVar13,(char)in_CX) + -1;
  pbVar23 = pbStack_2;
  pbVar24 = unaff_CS;
  pbVar22 = unaff_DI;
  if (iVar12 == 0 || cVar13 == '\0') {
    cVar13 = (char)((ulong)pbVar28 >> 8);
    pbVar19[(int)unaff_DI] = pbVar19[(int)unaff_DI] + cVar13 + CARRY1(bVar11,pbVar17[(int)unaff_CS])
    ;
    bVar16 = (byte)((ulong)pbVar28 >> 0x18);
    (pbVar19 + (int)unaff_CS)[-0x10] = (pbVar19 + (int)unaff_CS)[-0x10] | bVar16;
    bVar11 = *unaff_DI;
    *unaff_DI = bVar6 - 0x18;
    bVar6 = (byte)((ulong)pbVar28 >> 0x10);
    cVar14 = bVar6 + pbVar19[(int)unaff_CS];
    pbVar23 = (byte *)CONCAT11(bVar16,cVar14);
    if (!CARRY1(bVar6,pbVar19[(int)unaff_CS])) {
      unaff_ES = 0xa800;
      pbVar22 = (byte *)0x1690;
      uRam000a968e = 0xa800;
      *(char *)0x19 = *(char *)0x19 + cVar14;
      while( true ) {
        for (; unaff_DI != (byte *)0x0; unaff_DI = unaff_DI + -1) {
          pbVar28 = pbVar22;
          pbVar22 = pbVar22 + 2;
          pbVar28[0] = 0;
          pbVar28[1] = 0xa8;
        }
        pbVar22 = pbVar22 + 0x1e;
        if (pbVar17 <= pbVar22) break;
        *(int *)(pbVar17 + (int)unaff_CS) = *(int *)(pbVar17 + (int)unaff_CS) + 0x57ff;
      }
      pbStack_e = (byte *)&pbStack_4;
      pbVar28 = pbVar17;
      bVar6 = *pbVar28;
      *pbVar28 = *pbVar28 + 0x58;
      uVar7 = CONCAT11(0xa8,-(bVar6 < 0xa8) - *unaff_CS);
      *(undefined2 *)(unaff_BP + -3) = 0;
      *(undefined2 *)(unaff_BP + -5) = 0x50;
      iVar12 = 0;
      pbVar17 = pbVar22;
      pbStack_10 = pbVar19;
      pbStack_4 = pbVar22;
      pbStack_2 = unaff_CS;
      goto LAB_1000_5f79;
    }
    pbVar17[(int)(unaff_CS + 1)] = pbVar17[(int)(unaff_CS + 1)] + 1;
    pbVar24 = unaff_CS + 2;
    pbVar22 = unaff_DI + 1;
    in_stack_0000ffec = CONCAT11(cVar13 + bVar11,199);
    pbStack_10 = unaff_CS;
    pbStack_e = pbVar19;
    pbStack_4 = (byte *)pbVar28;
  }
  unaff_SS = in_stack_0000ffec;
  uVar7 = in(pbVar23);
  if (iVar12 == 0) {
    iVar12 = 0x50;
  }
  *(int *)(unaff_BP + -5) = iVar12;
  uVar7 = uVar7 & 0xff00;
  iVar12 = 0xa0;
  pbVar17 = pbVar24;
LAB_1000_5f79:
  do {
    uVar27 = CONCAT22(pbVar23,uVar7);
    if (iVar12 == 0) break;
    iVar12 = iVar12 + -1;
    pbVar28 = pbVar17;
    pbVar17 = pbVar17 + 1;
    uVar27 = CONCAT22(pbVar23,uVar7);
  } while ((byte)uVar7 != *pbVar28);
LAB_1000_5f7e:
  uVar15 = (undefined2)((ulong)uVar27 >> 0x10);
  pbVar28 = pbVar24;
  pbVar24 = pbVar24 + 1;
  bVar6 = *pbVar28;
  uVar7 = CONCAT11((char)((ulong)uVar27 >> 8),bVar6);
  uVar27 = CONCAT22(uVar15,uVar7);
  if (0x1f < bVar6) {
    if (bVar6 == 0x20) {
LAB_1000_5fc7:
      pbVar22 = pbVar22 + 1;
      piVar2 = (int *)(unaff_BP + -5);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar6 = (byte)uVar7, bVar6 == 0x40) {
      pbVar28 = pbVar24;
      pbVar24 = pbVar24 + 1;
      uVar7 = (uint)*pbVar28;
      iVar12 = 0x1c;
      pbVar23 = (byte *)0x2847;
      bVar26 = true;
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        pbVar3 = pbVar23;
        pbVar23 = pbVar23 + 1;
        bVar26 = *pbVar28 == *pbVar3;
      } while (!bVar26);
      if (bVar26) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar12 = (*(code *)*(undefined2 *)((int)(pbVar23 + -0x2848) * 2 + 0x78bb))();
        return iVar12;
      }
    }
    if ((0x7f < bVar6) && ((bVar6 < 0xa0 || (0xdf < bVar6)))) {
      pbVar28 = pbVar24;
      pbVar24 = pbVar24 + 1;
      uVar27 = CONCAT22(uVar15,CONCAT11(bVar6,*pbVar28));
      if (CONCAT11(bVar6,*pbVar28) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          pbStack_10 = (byte *)0x5fc7;
          uVar27 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        pbStack_10 = (byte *)0x5fb0;
        uVar27 = func_0x00016305();
      }
      pbVar22 = pbVar22 + 2;
      puVar1 = (uint *)(unaff_BP + -5);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar7 < 2) {
        *(undefined2 *)(unaff_BP + -5) = 0;
LAB_1000_625d:
        iVar12 = 0x10;
        puVar21 = (uint *)(pbStack_10 + -2);
        pbVar24 = pbVar22;
        do {
          pbVar23 = pbVar24;
          puVar20 = puVar21;
          puVar21 = puVar20 + 1;
          uVar7 = *puVar20;
          *(uint *)(pbVar23 + -0x50) = uVar7;
          *(uint *)(pbVar23 + 0x50) = uVar7;
          uVar8 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar5 = uVar8 * 2;
          bVar6 = ((uVar7 & 0x100) != 0) << 7;
          iVar18 = CONCAT11(bVar6,CARRY2(uVar8,uVar8));
          uVar7 = uVar8 | uVar5 | uVar8 >> 1;
          bVar11 = (byte)(uVar7 >> 8);
          iVar9 = CONCAT11((char)uVar7,bVar11);
          pbVar23[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar23 = iVar9;
          pbVar23[1] = bVar6;
          iVar12 = iVar12 + -1;
          pbVar24 = pbVar23 + 0x50;
        } while (iVar12 != 0);
        *(byte *)puVar21 = (byte)*puVar21 ^ bVar11;
        pbVar28 = pbVar23 + 0x4f;
        *pbVar28 = *pbVar28 + bVar11;
        pbVar23[0x4f] = bVar11;
        pbVar24 = pbVar23 + 0x51;
        uVar10 = iVar9 + 1;
        *(byte *)(puVar21 + uVar8) =
             (byte)puVar21[uVar8] + (byte)uVar10 + (((uint)pbVar22 & 1) != 0);
        uVar7 = (int)(pbStack_10 + -2) * 0x100;
        bVar26 = (uVar7 & 0x400) != 0;
        if ((uVar7 & 0x800) == 0) {
          *(byte *)(puVar20 + 0x1a4) = (byte)puVar20[0x1a4] + (char)(uVar10 >> 8);
          pbVar23[0x50] = (byte)*puVar21;
          puVar21 = puVar21 + !bVar26;
          pbVar24 = pbVar24 + uVar10 + (uint)bVar26 * -2;
          pbVar28 = (byte *)((int)puVar21 + iVar18 + 0x10);
          *pbVar28 = *pbVar28 | (byte)(uVar8 >> 1);
          *(byte *)(iVar18 + (int)puVar21) = *(byte *)(iVar18 + (int)puVar21) << 1;
          LOCK();
          pbVar28 = (byte *)((int)puVar21 + iVar18 + 0x30ac);
          *pbVar28 = *pbVar28 ^ (byte)uVar10;
          UNLOCK();
        }
        iVar9 = *(int *)0x32a8;
        FUN_1000_5aba(uVar10,(char)puVar21);
        pbVar24[uVar5 + 0xbad9] = pbVar24[uVar5 + 0xbad9] - (byte)iVar12;
        pbVar24[uVar5] = pbVar24[uVar5] + (char)((uint)iVar12 >> 8);
        piVar2 = (int *)(iVar18 + iVar9 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar12 & 0x1f);
        iVar12 = iVar18;
        cVar13 = extraout_AH;
        do {
          for (; iVar12 != 0; iVar12 = iVar12 + -1) {
            pbVar28 = pbVar24;
            pbVar24 = pbVar24 + (uint)bVar26 * -2 + 1;
            *pbVar28 = extraout_AL;
          }
          bVar25 = CARRY2((uint)pbVar24,extraout_DX);
          pbVar24 = pbVar24 + extraout_DX;
          cVar13 = cVar13 + -1;
          iVar12 = iVar18;
        } while (cVar13 != '\0');
        return (byte)-bVar25 + 0x6108 + (uint)bVar25;
      }
      goto LAB_1000_5f7e;
    }
    uVar27 = func_0x000163ff();
    uVar15 = (undefined2)((ulong)uVar27 >> 0x10);
    uVar7 = (int)uVar27 + 1;
    pbVar17[2] = (char)pbVar17[2] >> 0xb;
    bVar6 = (byte)uVar7;
    if (bVar6 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar6 - 0x10);
      uVar27 = CONCAT22(uVar15,uVar7);
      if (bVar6 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar6 - 0x10;
      pbVar17 = pbVar22 + 1;
      pbVar22 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar15,uVar7);
  goto LAB_1000_625d;
}


