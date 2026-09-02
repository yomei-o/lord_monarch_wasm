/* 1000:607b */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_607b(int param_1,int param_2,undefined2 *param_3)

{
  uint *puVar1;
  byte *pbVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  byte extraout_AL;
  uint uVar6;
  undefined2 in_AX;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char extraout_AH;
  char cVar10;
  int iVar11;
  int in_CX;
  char cVar12;
  undefined2 in_DX;
  byte bVar14;
  uint extraout_DX;
  byte *in_BX;
  int iVar15;
  int unaff_BP;
  uint *puVar16;
  uint *puVar17;
  byte *pbVar18;
  byte *pbVar19;
  char *unaff_DI;
  byte *pbVar20;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar21;
  bool in_PF;
  byte bVar22;
  bool bVar23;
  undefined4 uVar24;
  byte *in_stack_00000000;
  byte *in_stack_00000010;
  byte *in_stack_00000012;
  undefined2 uVar13;
  
  bVar22 = 0;
  if (in_PF) {
    pbVar18 = in_BX + (int)in_stack_00000000;
    bVar14 = (char)((uint)*(undefined2 *)pbVar18 >> 8) + in_BX[0x5019];
    pbVar2 = in_stack_00000000;
    in_stack_00000000 =
         in_stack_00000000 +
         (-(uint)CARRY1(bVar14,*pbVar2) - *(int *)(in_BX + (int)in_stack_00000000));
    in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),
                             (char)in_BX + in_stack_00000000[-0x7f02] +
                             CARRY1((byte)*(undefined2 *)pbVar18,*(byte *)0x701b));
    bVar22 = 1;
    in_stack_00000000[0xf] = in_stack_00000000[0xf] ^ bVar14 + *pbVar2;
  }
  else {
    pbVar2 = in_BX + (int)in_stack_00000000 + 0x30fd;
    *pbVar2 = *pbVar2 + 1;
    if (*pbVar2 == 0) {
      in_stack_00000000 = in_stack_00000000 + 1;
      unaff_DI[unaff_BP + 0x2c3] = unaff_DI[unaff_BP + 0x2c3] + '\x01';
      goto FUN_1000_5f28;
    }
  }
  in_DX = *(undefined2 *)(in_stack_00000000 + unaff_BP + 0x4030);
  *(undefined2 *)(unaff_BP + -2) = in_AX;
FUN_1000_5f28:
  bVar14 = (byte)((uint)in_DX >> 8);
  in_stack_00000000[unaff_BP + -0x10] = in_stack_00000000[unaff_BP + -0x10] | bVar14;
  cVar10 = *unaff_DI;
  pbVar18 = (byte *)(unaff_DI + (uint)bVar22 * -2 + 1);
  *unaff_DI = (char)in_AX;
  cVar12 = (byte)in_DX + in_stack_00000000[unaff_BP];
  uVar13 = CONCAT11(bVar14,cVar12);
  if (CARRY1((byte)in_DX,in_stack_00000000[unaff_BP])) {
    unaff_SS = CONCAT11((char)((uint)in_AX >> 8) + cVar10,199);
    in_BX[(int)(in_stack_00000000 + 1)] = in_BX[(int)(in_stack_00000000 + 1)] + 1;
    in_stack_00000000 = in_stack_00000000 + 2;
    uVar6 = in(uVar13);
    if (in_CX == 0) {
      in_CX = 0x50;
    }
    *(int *)(unaff_BP + -4) = in_CX;
    uVar6 = uVar6 & 0xff00;
    iVar11 = 0xa0;
    pbVar20 = in_stack_00000000;
  }
  else {
    unaff_ES = 0xa800;
    pbVar18 = (byte *)0x1690;
    uRam000a968e = 0xa800;
    *(char *)0x19 = *(char *)0x19 + cVar12;
    while( true ) {
      for (; param_1 != 0; param_1 = param_1 + -1) {
        pbVar2 = pbVar18;
        pbVar18 = pbVar18 + 2;
        pbVar2[0] = 0;
        pbVar2[1] = 0xa8;
      }
      pbVar18 = pbVar18 + 0x1e;
      if (in_BX <= pbVar18) break;
      *(int *)(in_BX + (int)in_stack_00000000) = *(int *)(in_BX + (int)in_stack_00000000) + 0x57ff;
    }
    param_3 = &stack0x0010;
    pbVar2 = in_BX;
    bVar22 = *pbVar2;
    *pbVar2 = *pbVar2 + 0x58;
    uVar6 = CONCAT11(0xa8,-(bVar22 < 0xa8) - *in_stack_00000000);
    *(undefined2 *)(unaff_BP + -2) = 0;
    *(undefined2 *)(unaff_BP + -4) = 0x50;
    iVar11 = 0;
    pbVar20 = pbVar18;
    param_2 = unaff_BP;
    in_stack_00000010 = pbVar18;
    in_stack_00000012 = in_stack_00000000;
  }
  do {
    uVar24 = CONCAT22(uVar13,uVar6);
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pbVar2 = pbVar20;
    pbVar20 = pbVar20 + 1;
    uVar24 = CONCAT22(uVar13,uVar6);
  } while ((byte)uVar6 != *pbVar2);
LAB_1000_5f7e:
  uVar13 = (undefined2)((ulong)uVar24 >> 0x10);
  pbVar2 = in_stack_00000000;
  in_stack_00000000 = in_stack_00000000 + 1;
  bVar22 = *pbVar2;
  uVar6 = CONCAT11((char)((ulong)uVar24 >> 8),bVar22);
  uVar24 = CONCAT22(uVar13,uVar6);
  if (0x1f < bVar22) {
    if (bVar22 == 0x20) {
LAB_1000_5fc7:
      pbVar18 = pbVar18 + 1;
      piVar3 = (int *)(unaff_BP + -4);
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar22 = (byte)uVar6, bVar22 == 0x40) {
      pbVar2 = in_stack_00000000;
      in_stack_00000000 = in_stack_00000000 + 1;
      uVar6 = (uint)*pbVar2;
      iVar11 = 0x1c;
      pbVar19 = (byte *)0x2847;
      bVar23 = true;
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pbVar4 = pbVar19;
        pbVar19 = pbVar19 + 1;
        bVar23 = *pbVar2 == *pbVar4;
      } while (!bVar23);
      if (bVar23) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar11 = (*(code *)*(undefined2 *)((int)(pbVar19 + -0x2848) * 2 + 0x78bb))();
        return iVar11;
      }
    }
    if ((0x7f < bVar22) && ((bVar22 < 0xa0 || (0xdf < bVar22)))) {
      pbVar2 = in_stack_00000000;
      in_stack_00000000 = in_stack_00000000 + 1;
      uVar24 = CONCAT22(uVar13,CONCAT11(bVar22,*pbVar2));
      if (CONCAT11(bVar22,*pbVar2) != 0x4081) {
        uVar6 = FUN_1000_8401();
        if ((0x2920 < uVar6) && (uVar6 < 0x2b7f)) {
          FUN_1000_5c7d();
          param_2 = 0x5fc7;
          uVar24 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        param_2 = 0x5fb0;
        uVar24 = func_0x00016305();
      }
      pbVar18 = pbVar18 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar6 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar6 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar11 = 0x10;
        puVar17 = (uint *)(param_2 + -2);
        pbVar20 = pbVar18;
        do {
          pbVar19 = pbVar20;
          puVar16 = puVar17;
          puVar17 = puVar16 + 1;
          uVar6 = *puVar16;
          *(uint *)(pbVar19 + -0x50) = uVar6;
          *(uint *)(pbVar19 + 0x50) = uVar6;
          uVar7 = CONCAT11((char)uVar6,(char)(uVar6 >> 8));
          uVar5 = uVar7 * 2;
          bVar22 = ((uVar6 & 0x100) != 0) << 7;
          iVar15 = CONCAT11(bVar22,CARRY2(uVar7,uVar7));
          uVar6 = uVar7 | uVar5 | uVar7 >> 1;
          bVar14 = (byte)(uVar6 >> 8);
          iVar8 = CONCAT11((char)uVar6,bVar14);
          pbVar19[-1] = CARRY2(uVar7,uVar7);
          *(int *)pbVar19 = iVar8;
          pbVar19[1] = bVar22;
          iVar11 = iVar11 + -1;
          pbVar20 = pbVar19 + 0x50;
        } while (iVar11 != 0);
        *(byte *)puVar17 = (byte)*puVar17 ^ bVar14;
        pbVar2 = pbVar19 + 0x4f;
        *pbVar2 = *pbVar2 + bVar14;
        pbVar19[0x4f] = bVar14;
        pbVar20 = pbVar19 + 0x51;
        uVar9 = iVar8 + 1;
        *(byte *)(puVar17 + uVar7) = (byte)puVar17[uVar7] + (byte)uVar9 + (((uint)pbVar18 & 1) != 0)
        ;
        uVar6 = (param_2 + -2) * 0x100;
        bVar23 = (uVar6 & 0x400) != 0;
        if ((uVar6 & 0x800) == 0) {
          *(byte *)(puVar16 + 0x1a4) = (byte)puVar16[0x1a4] + (char)(uVar9 >> 8);
          pbVar19[0x50] = (byte)*puVar17;
          puVar17 = puVar17 + !bVar23;
          pbVar20 = pbVar20 + uVar9 + (uint)bVar23 * -2;
          pbVar2 = (byte *)((int)puVar17 + iVar15 + 0x10);
          *pbVar2 = *pbVar2 | (byte)(uVar7 >> 1);
          *(byte *)(iVar15 + (int)puVar17) = *(byte *)(iVar15 + (int)puVar17) << 1;
          LOCK();
          pbVar2 = (byte *)((int)puVar17 + iVar15 + 0x30ac);
          *pbVar2 = *pbVar2 ^ (byte)uVar9;
          UNLOCK();
        }
        iVar8 = *(int *)0x32a8;
        FUN_1000_5aba(uVar9,(char)puVar17);
        pbVar20[uVar5 + 0xbad9] = pbVar20[uVar5 + 0xbad9] - (byte)iVar11;
        pbVar20[uVar5] = pbVar20[uVar5] + (char)((uint)iVar11 >> 8);
        piVar3 = (int *)(iVar15 + iVar8 + 0x10ff);
        *piVar3 = *piVar3 >> ((byte)iVar11 & 0x1f);
        iVar11 = iVar15;
        cVar10 = extraout_AH;
        do {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pbVar2 = pbVar20;
            pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
            *pbVar2 = extraout_AL;
          }
          bVar21 = CARRY2((uint)pbVar20,extraout_DX);
          pbVar20 = pbVar20 + extraout_DX;
          cVar10 = cVar10 + -1;
          iVar11 = iVar15;
        } while (cVar10 != '\0');
        return (byte)-bVar21 + 0x6108 + (uint)bVar21;
      }
      goto LAB_1000_5f7e;
    }
    uVar24 = func_0x000163ff();
    uVar13 = (undefined2)((ulong)uVar24 >> 0x10);
    uVar6 = (int)uVar24 + 1;
    pbVar20[2] = (char)pbVar20[2] >> 0xb;
    bVar22 = (byte)uVar6;
    if (bVar22 != 0) {
      uVar6 = CONCAT11((char)(uVar6 >> 8),bVar22 - 0x10);
      uVar24 = CONCAT22(uVar13,uVar6);
      if (bVar22 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar22 - 0x10;
      pbVar20 = pbVar18 + 1;
      pbVar18 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar13,uVar6);
  goto LAB_1000_625d;
}


