/* 1000:60dd */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_60dd(void)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte bVar6;
  byte extraout_AL;
  uint uVar7;
  byte *in_AX;
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
  byte *pbVar17;
  byte *in_BX;
  int iVar18;
  byte *unaff_BP;
  int *unaff_SI;
  uint *puVar19;
  uint *puVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *unaff_DI;
  byte *pbVar23;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar24;
  bool bVar25;
  undefined4 uVar26;
  byte *in_stack_00000000;
  undefined2 in_stack_0000ffec;
  byte *in_stack_0000fff0;
  byte **in_stack_0000fff2;
  byte *apbStack_4 [2];
  byte bVar11;
  
  *unaff_SI = *unaff_SI + in_CX;
  bVar6 = (byte)((uint)in_CX >> 8);
  cVar13 = bVar6 + in_BX[(int)in_stack_00000000];
  iVar12 = CONCAT11(cVar13,(char)in_CX) + -1;
  pbVar23 = in_stack_00000000;
  pbVar21 = unaff_DI;
  if (iVar12 == 0 || cVar13 == '\0') {
    cVar13 = (char)((uint)in_AX >> 8);
    unaff_BP[(int)unaff_DI] =
         unaff_BP[(int)unaff_DI] + cVar13 + CARRY1(bVar6,in_BX[(int)in_stack_00000000]);
    bVar16 = (byte)((uint)in_DX >> 8);
    (unaff_BP + (int)in_stack_00000000)[-0x10] = (unaff_BP + (int)in_stack_00000000)[-0x10] | bVar16
    ;
    bVar6 = *unaff_DI;
    pbVar21 = unaff_DI + 1;
    *unaff_DI = (char)in_AX - 0x18;
    bVar11 = (byte)in_DX;
    cVar14 = bVar11 + unaff_BP[(int)in_stack_00000000];
    in_DX = CONCAT11(bVar16,cVar14);
    if (!CARRY1(bVar11,unaff_BP[(int)in_stack_00000000])) {
      unaff_ES = 0xa800;
      pbVar21 = (byte *)0x1690;
      uRam000a968e = 0xa800;
      *(char *)0x19 = *(char *)0x19 + cVar14;
      while( true ) {
        for (; unaff_DI != (byte *)0x0; unaff_DI = unaff_DI + -1) {
          pbVar4 = pbVar21;
          pbVar21 = pbVar21 + 2;
          pbVar4[0] = 0;
          pbVar4[1] = 0xa8;
        }
        pbVar21 = pbVar21 + 0x1e;
        if (in_BX <= pbVar21) break;
        *(int *)(in_BX + (int)in_stack_00000000) = *(int *)(in_BX + (int)in_stack_00000000) + 0x57ff
        ;
      }
      in_stack_0000fff2 = apbStack_4;
      pbVar4 = in_BX;
      bVar6 = *pbVar4;
      *pbVar4 = *pbVar4 + 0x58;
      uVar7 = CONCAT11(0xa8,-(bVar6 < 0xa8) - *in_stack_00000000);
      (unaff_BP + -2)[0] = 0;
      (unaff_BP + -2)[1] = 0;
      (unaff_BP + -4)[0] = 0x50;
      (unaff_BP + -4)[1] = 0;
      iVar12 = 0;
      pbVar17 = pbVar21;
      in_stack_0000fff0 = unaff_BP;
      apbStack_4[0] = pbVar21;
      goto LAB_1000_5f79;
    }
    in_BX[(int)(in_stack_00000000 + 1)] = in_BX[(int)(in_stack_00000000 + 1)] + 1;
    pbVar23 = in_stack_00000000 + 2;
    in_stack_0000ffec = CONCAT11(cVar13 + bVar6,199);
    in_stack_0000fff0 = in_stack_00000000;
    in_stack_0000fff2 = (byte **)unaff_BP;
    apbStack_4[0] = in_AX;
  }
  unaff_SS = in_stack_0000ffec;
  uVar7 = in(in_DX);
  if (iVar12 == 0) {
    iVar12 = 0x50;
  }
  *(int *)(unaff_BP + -4) = iVar12;
  uVar7 = uVar7 & 0xff00;
  iVar12 = 0xa0;
  pbVar17 = pbVar23;
LAB_1000_5f79:
  do {
    uVar26 = CONCAT22(in_DX,uVar7);
    if (iVar12 == 0) break;
    iVar12 = iVar12 + -1;
    pbVar4 = pbVar17;
    pbVar17 = pbVar17 + 1;
    uVar26 = CONCAT22(in_DX,uVar7);
  } while ((byte)uVar7 != *pbVar4);
LAB_1000_5f7e:
  uVar15 = (undefined2)((ulong)uVar26 >> 0x10);
  pbVar4 = pbVar23;
  pbVar23 = pbVar23 + 1;
  bVar6 = *pbVar4;
  uVar7 = CONCAT11((char)((ulong)uVar26 >> 8),bVar6);
  uVar26 = CONCAT22(uVar15,uVar7);
  if (0x1f < bVar6) {
    if (bVar6 == 0x20) {
LAB_1000_5fc7:
      pbVar21 = pbVar21 + 1;
      pbVar4 = unaff_BP + -4;
      *(int *)pbVar4 = *(int *)pbVar4 + -1;
      if (*(int *)pbVar4 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar6 = (byte)uVar7, bVar6 == 0x40) {
      pbVar4 = pbVar23;
      pbVar23 = pbVar23 + 1;
      uVar7 = (uint)*pbVar4;
      iVar12 = 0x1c;
      pbVar22 = (byte *)0x2847;
      bVar25 = true;
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        pbVar3 = pbVar22;
        pbVar22 = pbVar22 + 1;
        bVar25 = *pbVar4 == *pbVar3;
      } while (!bVar25);
      if (bVar25) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar12 = (*(code *)*(undefined2 *)((int)(pbVar22 + -0x2848) * 2 + 0x78bb))();
        return iVar12;
      }
    }
    if ((0x7f < bVar6) && ((bVar6 < 0xa0 || (0xdf < bVar6)))) {
      pbVar4 = pbVar23;
      pbVar23 = pbVar23 + 1;
      uVar26 = CONCAT22(uVar15,CONCAT11(bVar6,*pbVar4));
      if (CONCAT11(bVar6,*pbVar4) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          in_stack_0000fff0 = (byte *)0x5fc7;
          uVar26 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        in_stack_0000fff0 = (byte *)0x5fb0;
        uVar26 = func_0x00016305();
      }
      pbVar21 = pbVar21 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar7 < 2) {
        (unaff_BP + -4)[0] = 0;
        (unaff_BP + -4)[1] = 0;
LAB_1000_625d:
        iVar12 = 0x10;
        puVar20 = (uint *)(in_stack_0000fff0 + -2);
        pbVar23 = pbVar21;
        do {
          pbVar17 = pbVar23;
          puVar19 = puVar20;
          puVar20 = puVar19 + 1;
          uVar7 = *puVar19;
          *(uint *)(pbVar17 + -0x50) = uVar7;
          *(uint *)(pbVar17 + 0x50) = uVar7;
          uVar8 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar5 = uVar8 * 2;
          bVar6 = ((uVar7 & 0x100) != 0) << 7;
          iVar18 = CONCAT11(bVar6,CARRY2(uVar8,uVar8));
          uVar7 = uVar8 | uVar5 | uVar8 >> 1;
          bVar11 = (byte)(uVar7 >> 8);
          iVar9 = CONCAT11((char)uVar7,bVar11);
          pbVar17[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar17 = iVar9;
          pbVar17[1] = bVar6;
          iVar12 = iVar12 + -1;
          pbVar23 = pbVar17 + 0x50;
        } while (iVar12 != 0);
        *(byte *)puVar20 = (byte)*puVar20 ^ bVar11;
        pbVar4 = pbVar17 + 0x4f;
        *pbVar4 = *pbVar4 + bVar11;
        pbVar17[0x4f] = bVar11;
        pbVar23 = pbVar17 + 0x51;
        uVar10 = iVar9 + 1;
        *(byte *)(puVar20 + uVar8) =
             (byte)puVar20[uVar8] + (byte)uVar10 + (((uint)pbVar21 & 1) != 0);
        uVar7 = (int)(in_stack_0000fff0 + -2) * 0x100;
        bVar25 = (uVar7 & 0x400) != 0;
        if ((uVar7 & 0x800) == 0) {
          *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar10 >> 8);
          pbVar17[0x50] = (byte)*puVar20;
          puVar20 = puVar20 + !bVar25;
          pbVar23 = pbVar23 + uVar10 + (uint)bVar25 * -2;
          pbVar4 = (byte *)((int)puVar20 + iVar18 + 0x10);
          *pbVar4 = *pbVar4 | (byte)(uVar8 >> 1);
          *(byte *)(iVar18 + (int)puVar20) = *(byte *)(iVar18 + (int)puVar20) << 1;
          LOCK();
          pbVar4 = (byte *)((int)puVar20 + iVar18 + 0x30ac);
          *pbVar4 = *pbVar4 ^ (byte)uVar10;
          UNLOCK();
        }
        iVar9 = *(int *)0x32a8;
        FUN_1000_5aba(uVar10,(char)puVar20);
        pbVar23[uVar5 + 0xbad9] = pbVar23[uVar5 + 0xbad9] - (byte)iVar12;
        pbVar23[uVar5] = pbVar23[uVar5] + (char)((uint)iVar12 >> 8);
        piVar2 = (int *)(iVar18 + iVar9 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar12 & 0x1f);
        iVar12 = iVar18;
        cVar13 = extraout_AH;
        do {
          for (; iVar12 != 0; iVar12 = iVar12 + -1) {
            pbVar4 = pbVar23;
            pbVar23 = pbVar23 + (uint)bVar25 * -2 + 1;
            *pbVar4 = extraout_AL;
          }
          bVar24 = CARRY2((uint)pbVar23,extraout_DX);
          pbVar23 = pbVar23 + extraout_DX;
          cVar13 = cVar13 + -1;
          iVar12 = iVar18;
        } while (cVar13 != '\0');
        return (byte)-bVar24 + 0x6108 + (uint)bVar24;
      }
      goto LAB_1000_5f7e;
    }
    uVar26 = func_0x000163ff();
    uVar15 = (undefined2)((ulong)uVar26 >> 0x10);
    uVar7 = (int)uVar26 + 1;
    pbVar17[2] = (char)pbVar17[2] >> 0xb;
    bVar6 = (byte)uVar7;
    if (bVar6 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar6 - 0x10);
      uVar26 = CONCAT22(uVar15,uVar7);
      if (bVar6 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar6 - 0x10;
      pbVar17 = pbVar21 + 1;
      pbVar21 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar15,uVar7);
  goto LAB_1000_625d;
}


