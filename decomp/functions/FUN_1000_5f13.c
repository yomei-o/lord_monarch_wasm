/* 1000:5f13 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */
/* WARNING: Removing unreachable block (ram,0x00015f1a) */

int FUN_1000_5f13(void)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  byte extraout_AL;
  byte *in_AX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar12;
  int in_CX;
  int iVar13;
  byte bVar14;
  char cVar15;
  undefined2 in_DX;
  uint extraout_DX;
  byte *in_BX;
  byte *pbVar17;
  int iVar18;
  byte *unaff_BP;
  byte *pbVar19;
  byte *unaff_SI;
  uint *puVar20;
  uint *puVar21;
  byte *unaff_DI;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar25;
  bool bVar26;
  undefined4 uVar27;
  undefined2 in_stack_0000ffec;
  byte *in_stack_0000fff0;
  byte *pbStack_e;
  byte *pbStack_4;
  byte bVar11;
  undefined2 uVar16;
  
  while( true ) {
    pbVar19 = unaff_BP + 1;
    (pbVar19 + (int)unaff_DI)[0xac7] = (pbVar19 + (int)unaff_DI)[0xac7] | (byte)in_AX;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    *(byte **)(unaff_DI + 2) = in_AX;
    *(byte **)(unaff_DI + 4) = in_AX;
    *(byte **)(unaff_DI + 6) = in_AX;
    *(byte **)(unaff_DI + 8) = in_AX;
    unaff_DI = unaff_DI + 10;
    unaff_BP = pbVar19;
  }
  swi(4);
  bVar11 = (byte)((uint)in_DX >> 8);
  bVar14 = (byte)in_DX & (pbVar19 + (int)unaff_SI)[0x50];
  uVar16 = CONCAT11(bVar11,bVar14);
  iVar13 = (uint)in_BX[(int)unaff_SI] * 0x100 + -1;
  pbVar24 = unaff_SI;
  pbVar22 = unaff_DI;
  if (iVar13 == 0 || in_BX[(int)unaff_SI] == 0) {
    cVar12 = (char)((uint)in_AX >> 8);
    pbVar19[(int)unaff_DI] = pbVar19[(int)unaff_DI] + cVar12;
    (pbVar19 + (int)unaff_SI)[-0x10] = (pbVar19 + (int)unaff_SI)[-0x10] | bVar11;
    bVar5 = *unaff_DI;
    pbVar22 = unaff_DI + 1;
    *unaff_DI = (byte)in_AX - 0x18;
    cVar15 = bVar14 + pbVar19[(int)unaff_SI];
    uVar16 = CONCAT11(bVar11,cVar15);
    if (!CARRY1(bVar14,pbVar19[(int)unaff_SI])) {
      unaff_ES = 0xa800;
      pbVar22 = (byte *)0x1690;
      uRam000a968e = 0xa800;
      *(char *)0x19 = *(char *)0x19 + cVar15;
      while( true ) {
        for (; unaff_DI != (byte *)0x0; unaff_DI = unaff_DI + -1) {
          pbVar4 = pbVar22;
          pbVar22 = pbVar22 + 2;
          pbVar4[0] = 0;
          pbVar4[1] = 0xa8;
        }
        pbVar22 = pbVar22 + 0x1e;
        if (in_BX <= pbVar22) break;
        *(int *)(in_BX + (int)unaff_SI) = *(int *)(in_BX + (int)unaff_SI) + 0x57ff;
      }
      pbStack_e = (byte *)&pbStack_4;
      pbVar4 = in_BX;
      bVar14 = *pbVar4;
      *pbVar4 = *pbVar4 + 0x58;
      uVar7 = CONCAT11(0xa8,-(bVar14 < 0xa8) - *unaff_SI);
      (unaff_BP + -1)[0] = 0;
      (unaff_BP + -1)[1] = 0;
      (unaff_BP + -3)[0] = 0x50;
      (unaff_BP + -3)[1] = 0;
      iVar13 = 0;
      pbVar17 = pbVar22;
      pbStack_4 = pbVar22;
      goto LAB_1000_5f79;
    }
    in_BX[(int)(unaff_SI + 1)] = in_BX[(int)(unaff_SI + 1)] + 1;
    pbVar24 = unaff_SI + 2;
    in_stack_0000ffec = CONCAT11(cVar12 + bVar5,199);
    in_stack_0000fff0 = unaff_SI;
    pbStack_e = pbVar19;
    pbStack_4 = in_AX;
  }
  pbVar19 = in_stack_0000fff0;
  unaff_SS = in_stack_0000ffec;
  uVar7 = in(uVar16);
  if (iVar13 == 0) {
    iVar13 = 0x50;
  }
  *(int *)(unaff_BP + -3) = iVar13;
  uVar7 = uVar7 & 0xff00;
  iVar13 = 0xa0;
  pbVar17 = pbVar24;
LAB_1000_5f79:
  do {
    uVar27 = CONCAT22(uVar16,uVar7);
    if (iVar13 == 0) break;
    iVar13 = iVar13 + -1;
    pbVar4 = pbVar17;
    pbVar17 = pbVar17 + 1;
    uVar27 = CONCAT22(uVar16,uVar7);
  } while ((byte)uVar7 != *pbVar4);
LAB_1000_5f7e:
  uVar16 = (undefined2)((ulong)uVar27 >> 0x10);
  pbVar4 = pbVar24;
  pbVar24 = pbVar24 + 1;
  bVar14 = *pbVar4;
  uVar7 = CONCAT11((char)((ulong)uVar27 >> 8),bVar14);
  uVar27 = CONCAT22(uVar16,uVar7);
  if (0x1f < bVar14) {
    if (bVar14 == 0x20) {
LAB_1000_5fc7:
      pbVar22 = pbVar22 + 1;
      pbVar4 = unaff_BP + -3;
      *(int *)pbVar4 = *(int *)pbVar4 + -1;
      if (*(int *)pbVar4 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar14 = (byte)uVar7, bVar14 == 0x40) {
      pbVar4 = pbVar24;
      pbVar24 = pbVar24 + 1;
      uVar7 = (uint)*pbVar4;
      iVar13 = 0x1c;
      pbVar23 = (byte *)0x2847;
      bVar26 = true;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pbVar3 = pbVar23;
        pbVar23 = pbVar23 + 1;
        bVar26 = *pbVar4 == *pbVar3;
      } while (!bVar26);
      if (bVar26) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar13 = (*(code *)*(undefined2 *)((int)(pbVar23 + -0x2848) * 2 + 0x78bb))();
        return iVar13;
      }
    }
    if ((0x7f < bVar14) && ((bVar14 < 0xa0 || (0xdf < bVar14)))) {
      pbVar4 = pbVar24;
      pbVar24 = pbVar24 + 1;
      uVar27 = CONCAT22(uVar16,CONCAT11(bVar14,*pbVar4));
      if (CONCAT11(bVar14,*pbVar4) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          pbVar19 = (byte *)0x5fc7;
          uVar27 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        pbVar19 = (byte *)0x5fb0;
        uVar27 = func_0x00016305();
      }
      pbVar22 = pbVar22 + 2;
      puVar1 = (uint *)(unaff_BP + -3);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar7 < 2) {
        (unaff_BP + -3)[0] = 0;
        (unaff_BP + -3)[1] = 0;
LAB_1000_625d:
        iVar13 = 0x10;
        puVar21 = (uint *)(pbVar19 + -2);
        pbVar24 = pbVar22;
        do {
          pbVar17 = pbVar24;
          puVar20 = puVar21;
          puVar21 = puVar20 + 1;
          uVar7 = *puVar20;
          *(uint *)(pbVar17 + -0x50) = uVar7;
          *(uint *)(pbVar17 + 0x50) = uVar7;
          uVar8 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar6 = uVar8 * 2;
          bVar14 = ((uVar7 & 0x100) != 0) << 7;
          iVar18 = CONCAT11(bVar14,CARRY2(uVar8,uVar8));
          uVar7 = uVar8 | uVar6 | uVar8 >> 1;
          bVar11 = (byte)(uVar7 >> 8);
          iVar9 = CONCAT11((char)uVar7,bVar11);
          pbVar17[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar17 = iVar9;
          pbVar17[1] = bVar14;
          iVar13 = iVar13 + -1;
          pbVar24 = pbVar17 + 0x50;
        } while (iVar13 != 0);
        *(byte *)puVar21 = (byte)*puVar21 ^ bVar11;
        pbVar4 = pbVar17 + 0x4f;
        *pbVar4 = *pbVar4 + bVar11;
        pbVar17[0x4f] = bVar11;
        pbVar24 = pbVar17 + 0x51;
        uVar10 = iVar9 + 1;
        *(byte *)(puVar21 + uVar8) =
             (byte)puVar21[uVar8] + (byte)uVar10 + (((uint)pbVar22 & 1) != 0);
        uVar7 = (int)(pbVar19 + -2) * 0x100;
        bVar26 = (uVar7 & 0x400) != 0;
        if ((uVar7 & 0x800) == 0) {
          *(byte *)(puVar20 + 0x1a4) = (byte)puVar20[0x1a4] + (char)(uVar10 >> 8);
          pbVar17[0x50] = (byte)*puVar21;
          puVar21 = puVar21 + !bVar26;
          pbVar24 = pbVar24 + uVar10 + (uint)bVar26 * -2;
          pbVar4 = (byte *)((int)puVar21 + iVar18 + 0x10);
          *pbVar4 = *pbVar4 | (byte)(uVar8 >> 1);
          *(byte *)(iVar18 + (int)puVar21) = *(byte *)(iVar18 + (int)puVar21) << 1;
          LOCK();
          pbVar4 = (byte *)((int)puVar21 + iVar18 + 0x30ac);
          *pbVar4 = *pbVar4 ^ (byte)uVar10;
          UNLOCK();
        }
        iVar9 = *(int *)0x32a8;
        FUN_1000_5aba(uVar10,(char)puVar21);
        pbVar24[uVar6 + 0xbad9] = pbVar24[uVar6 + 0xbad9] - (byte)iVar13;
        pbVar24[uVar6] = pbVar24[uVar6] + (char)((uint)iVar13 >> 8);
        piVar2 = (int *)(iVar18 + iVar9 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar13 & 0x1f);
        iVar13 = iVar18;
        cVar12 = extraout_AH;
        do {
          for (; iVar13 != 0; iVar13 = iVar13 + -1) {
            pbVar4 = pbVar24;
            pbVar24 = pbVar24 + (uint)bVar26 * -2 + 1;
            *pbVar4 = extraout_AL;
          }
          bVar25 = CARRY2((uint)pbVar24,extraout_DX);
          pbVar24 = pbVar24 + extraout_DX;
          cVar12 = cVar12 + -1;
          iVar13 = iVar18;
        } while (cVar12 != '\0');
        return (byte)-bVar25 + 0x6108 + (uint)bVar25;
      }
      goto LAB_1000_5f7e;
    }
    uVar27 = func_0x000163ff();
    uVar16 = (undefined2)((ulong)uVar27 >> 0x10);
    uVar7 = (int)uVar27 + 1;
    pbVar17[2] = (char)pbVar17[2] >> 0xb;
    bVar14 = (byte)uVar7;
    if (bVar14 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar14 - 0x10);
      uVar27 = CONCAT22(uVar16,uVar7);
      if (bVar14 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar14 - 0x10;
      pbVar17 = pbVar22 + 1;
      pbVar22 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar16,uVar7);
  goto LAB_1000_625d;
}


