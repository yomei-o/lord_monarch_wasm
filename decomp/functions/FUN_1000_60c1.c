/* 1000:60c1 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_60c1(void)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  byte extraout_AL;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char extraout_AH;
  char cVar12;
  undefined2 in_CX;
  int iVar11;
  char cVar13;
  byte bVar15;
  undefined2 uVar14;
  uint extraout_DX;
  int in_BX;
  byte *pbVar16;
  int iVar17;
  int unaff_BP;
  byte *pbVar18;
  int *unaff_SI;
  uint *puVar19;
  uint *puVar20;
  byte *pbVar21;
  byte *pbVar22;
  int unaff_DI;
  byte *pbVar23;
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
  byte bVar10;
  
  iVar11 = CONCAT11((char)((uint)in_CX >> 8) + (char)in_BX,(char)in_CX) +
           *(int *)(unaff_BP + unaff_DI + 0x477);
  pbStack_2 = (byte *)0x60cd;
  pbVar28 = (byte *)func_0x00015eef();
  pbStack_2 = (byte *)((ulong)pbVar28 >> 0x10);
  pbVar16 = (byte *)(in_BX + 6);
  bVar5 = (byte)pbVar28;
  *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ bVar5;
  pbVar18 = (byte *)(unaff_BP + -1);
  pbVar18[(int)unaff_SI] = pbVar18[(int)unaff_SI] & bVar5;
  pbVar23 = (byte *)(unaff_DI + -2);
  *(byte *)0xed32 = *(byte *)0xed32 ^ (byte)pbVar16;
  *unaff_SI = *unaff_SI + iVar11;
  bVar10 = (byte)((uint)iVar11 >> 8);
  cVar12 = bVar10 + pbVar16[(int)unaff_CS];
  iVar11 = CONCAT11(cVar12,(char)iVar11) + -1;
  pbVar22 = pbStack_2;
  pbVar24 = unaff_CS;
  pbVar21 = pbVar23;
  if (iVar11 == 0 || cVar12 == '\0') {
    cVar12 = (char)((ulong)pbVar28 >> 8);
    pbVar18[(int)pbVar23] = pbVar18[(int)pbVar23] + cVar12 + CARRY1(bVar10,pbVar16[(int)unaff_CS]);
    bVar15 = (byte)((ulong)pbVar28 >> 0x18);
    (pbVar18 + (int)unaff_CS)[-0x10] = (pbVar18 + (int)unaff_CS)[-0x10] | bVar15;
    bVar10 = *pbVar23;
    *pbVar23 = bVar5 - 0x18;
    bVar5 = (byte)((ulong)pbVar28 >> 0x10);
    cVar13 = bVar5 + pbVar18[(int)unaff_CS];
    pbVar22 = (byte *)CONCAT11(bVar15,cVar13);
    if (!CARRY1(bVar5,pbVar18[(int)unaff_CS])) {
      unaff_ES = 0xa800;
      pbVar21 = (byte *)0x1690;
      uRam000a968e = 0xa800;
      *(char *)0x19 = *(char *)0x19 + cVar13;
      while( true ) {
        for (; pbVar23 != (byte *)0x0; pbVar23 = pbVar23 + -1) {
          pbVar28 = pbVar21;
          pbVar21 = pbVar21 + 2;
          pbVar28[0] = 0;
          pbVar28[1] = 0xa8;
        }
        pbVar21 = pbVar21 + 0x1e;
        if (pbVar16 <= pbVar21) break;
        *(int *)(pbVar16 + (int)unaff_CS) = *(int *)(pbVar16 + (int)unaff_CS) + 0x57ff;
      }
      pbStack_e = (byte *)&pbStack_4;
      pbVar28 = pbVar16;
      bVar5 = *pbVar28;
      *pbVar28 = *pbVar28 + 0x58;
      uVar6 = CONCAT11(0xa8,-(bVar5 < 0xa8) - *unaff_CS);
      *(undefined2 *)(unaff_BP + -3) = 0;
      *(undefined2 *)(unaff_BP + -5) = 0x50;
      iVar11 = 0;
      pbVar23 = pbVar21;
      pbStack_10 = pbVar18;
      pbStack_4 = pbVar21;
      pbStack_2 = unaff_CS;
      goto LAB_1000_5f79;
    }
    pbVar16[(int)(unaff_CS + 1)] = pbVar16[(int)(unaff_CS + 1)] + 1;
    pbVar24 = unaff_CS + 2;
    pbVar21 = (byte *)(unaff_DI + -1);
    in_stack_0000ffec = CONCAT11(cVar12 + bVar10,199);
    pbStack_10 = unaff_CS;
    pbStack_e = pbVar18;
    pbStack_4 = (byte *)pbVar28;
  }
  unaff_SS = in_stack_0000ffec;
  uVar6 = in(pbVar22);
  if (iVar11 == 0) {
    iVar11 = 0x50;
  }
  *(int *)(unaff_BP + -5) = iVar11;
  uVar6 = uVar6 & 0xff00;
  iVar11 = 0xa0;
  pbVar23 = pbVar24;
LAB_1000_5f79:
  do {
    uVar27 = CONCAT22(pbVar22,uVar6);
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pbVar28 = pbVar23;
    pbVar23 = pbVar23 + 1;
    uVar27 = CONCAT22(pbVar22,uVar6);
  } while ((byte)uVar6 != *pbVar28);
LAB_1000_5f7e:
  uVar14 = (undefined2)((ulong)uVar27 >> 0x10);
  pbVar28 = pbVar24;
  pbVar24 = pbVar24 + 1;
  bVar5 = *pbVar28;
  uVar6 = CONCAT11((char)((ulong)uVar27 >> 8),bVar5);
  uVar27 = CONCAT22(uVar14,uVar6);
  if (0x1f < bVar5) {
    if (bVar5 == 0x20) {
LAB_1000_5fc7:
      pbVar21 = pbVar21 + 1;
      piVar2 = (int *)(unaff_BP + -5);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar5 = (byte)uVar6, bVar5 == 0x40) {
      pbVar28 = pbVar24;
      pbVar24 = pbVar24 + 1;
      uVar6 = (uint)*pbVar28;
      iVar11 = 0x1c;
      pbVar22 = (byte *)0x2847;
      bVar26 = true;
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pbVar3 = pbVar22;
        pbVar22 = pbVar22 + 1;
        bVar26 = *pbVar28 == *pbVar3;
      } while (!bVar26);
      if (bVar26) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar11 = (*(code *)*(undefined2 *)((int)(pbVar22 + -0x2848) * 2 + 0x78bb))();
        return iVar11;
      }
    }
    if ((0x7f < bVar5) && ((bVar5 < 0xa0 || (0xdf < bVar5)))) {
      pbVar28 = pbVar24;
      pbVar24 = pbVar24 + 1;
      uVar27 = CONCAT22(uVar14,CONCAT11(bVar5,*pbVar28));
      if (CONCAT11(bVar5,*pbVar28) != 0x4081) {
        uVar6 = FUN_1000_8401();
        if ((0x2920 < uVar6) && (uVar6 < 0x2b7f)) {
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
      pbVar21 = pbVar21 + 2;
      puVar1 = (uint *)(unaff_BP + -5);
      uVar6 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar6 < 2) {
        *(undefined2 *)(unaff_BP + -5) = 0;
LAB_1000_625d:
        iVar11 = 0x10;
        puVar20 = (uint *)(pbStack_10 + -2);
        pbVar24 = pbVar21;
        do {
          pbVar22 = pbVar24;
          puVar19 = puVar20;
          puVar20 = puVar19 + 1;
          uVar6 = *puVar19;
          *(uint *)(pbVar22 + -0x50) = uVar6;
          *(uint *)(pbVar22 + 0x50) = uVar6;
          uVar7 = CONCAT11((char)uVar6,(char)(uVar6 >> 8));
          uVar4 = uVar7 * 2;
          bVar5 = ((uVar6 & 0x100) != 0) << 7;
          iVar17 = CONCAT11(bVar5,CARRY2(uVar7,uVar7));
          uVar6 = uVar7 | uVar4 | uVar7 >> 1;
          bVar10 = (byte)(uVar6 >> 8);
          iVar8 = CONCAT11((char)uVar6,bVar10);
          pbVar22[-1] = CARRY2(uVar7,uVar7);
          *(int *)pbVar22 = iVar8;
          pbVar22[1] = bVar5;
          iVar11 = iVar11 + -1;
          pbVar24 = pbVar22 + 0x50;
        } while (iVar11 != 0);
        *(byte *)puVar20 = (byte)*puVar20 ^ bVar10;
        pbVar28 = pbVar22 + 0x4f;
        *pbVar28 = *pbVar28 + bVar10;
        pbVar22[0x4f] = bVar10;
        pbVar24 = pbVar22 + 0x51;
        uVar9 = iVar8 + 1;
        *(byte *)(puVar20 + uVar7) = (byte)puVar20[uVar7] + (byte)uVar9 + (((uint)pbVar21 & 1) != 0)
        ;
        uVar6 = (int)(pbStack_10 + -2) * 0x100;
        bVar26 = (uVar6 & 0x400) != 0;
        if ((uVar6 & 0x800) == 0) {
          *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar9 >> 8);
          pbVar22[0x50] = (byte)*puVar20;
          puVar20 = puVar20 + !bVar26;
          pbVar24 = pbVar24 + uVar9 + (uint)bVar26 * -2;
          pbVar28 = (byte *)((int)puVar20 + iVar17 + 0x10);
          *pbVar28 = *pbVar28 | (byte)(uVar7 >> 1);
          *(byte *)(iVar17 + (int)puVar20) = *(byte *)(iVar17 + (int)puVar20) << 1;
          LOCK();
          pbVar28 = (byte *)((int)puVar20 + iVar17 + 0x30ac);
          *pbVar28 = *pbVar28 ^ (byte)uVar9;
          UNLOCK();
        }
        iVar8 = *(int *)0x32a8;
        FUN_1000_5aba(uVar9,(char)puVar20);
        pbVar24[uVar4 + 0xbad9] = pbVar24[uVar4 + 0xbad9] - (byte)iVar11;
        pbVar24[uVar4] = pbVar24[uVar4] + (char)((uint)iVar11 >> 8);
        piVar2 = (int *)(iVar17 + iVar8 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar11 & 0x1f);
        iVar11 = iVar17;
        cVar12 = extraout_AH;
        do {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pbVar28 = pbVar24;
            pbVar24 = pbVar24 + (uint)bVar26 * -2 + 1;
            *pbVar28 = extraout_AL;
          }
          bVar25 = CARRY2((uint)pbVar24,extraout_DX);
          pbVar24 = pbVar24 + extraout_DX;
          cVar12 = cVar12 + -1;
          iVar11 = iVar17;
        } while (cVar12 != '\0');
        return (byte)-bVar25 + 0x6108 + (uint)bVar25;
      }
      goto LAB_1000_5f7e;
    }
    uVar27 = func_0x000163ff();
    uVar14 = (undefined2)((ulong)uVar27 >> 0x10);
    uVar6 = (int)uVar27 + 1;
    pbVar23[2] = (char)pbVar23[2] >> 0xb;
    bVar5 = (byte)uVar6;
    if (bVar5 != 0) {
      uVar6 = CONCAT11((char)(uVar6 >> 8),bVar5 - 0x10);
      uVar27 = CONCAT22(uVar14,uVar6);
      if (bVar5 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar5 - 0x10;
      pbVar23 = pbVar21 + 1;
      pbVar21 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar14,uVar6);
  goto LAB_1000_625d;
}


