/* 1000:6065 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_1000_6065(byte *param_1,int param_2,undefined2 *param_3)

{
  uint *puVar1;
  char *pcVar2;
  int *piVar3;
  byte *pbVar4;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint *puVar8;
  byte bVar9;
  byte extraout_AL;
  int in_AX;
  uint uVar10;
  uint uVar11;
  int iVar12;
  char extraout_AH;
  char cVar13;
  int iVar14;
  undefined2 in_CX;
  int iVar15;
  char cVar16;
  undefined2 uVar18;
  uint extraout_DX;
  byte *pbVar19;
  byte *in_BX;
  int iVar20;
  int unaff_BP;
  int unaff_SI;
  uint *puVar21;
  uint *puVar22;
  byte *pbVar23;
  byte *pbVar24;
  char *unaff_DI;
  byte *pbVar25;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar26;
  byte bVar27;
  bool bVar28;
  undefined4 uVar29;
  undefined2 in_stack_00000000;
  byte *in_stack_00000010;
  byte *in_stack_00000012;
  undefined2 uVar17;
  
  bVar27 = 0;
  *(char *)0x210 = *(char *)0x210 + -0x2f;
  pcVar5 = unaff_DI + 1;
  *unaff_DI = (char)in_AX;
  pbVar25 = (byte *)&param_1;
  bVar9 = (char)in_AX + 1;
  uVar18 = CONCAT11((char)((uint)in_stack_00000000 >> 8),(byte)in_stack_00000000 + bVar9);
  uVar10 = in_AX + 2;
  iVar14 = CONCAT11((char)((uint)in_CX >> 8) + (char)uVar10,
                    (char)in_CX + pcVar5[unaff_BP + -0x74fc] + CARRY1((byte)in_stack_00000000,bVar9)
                   );
  puVar1 = (uint *)(unaff_BP + unaff_SI + 1);
  *puVar1 = *puVar1 ^ uVar10;
  if ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) {
    bVar9 = (char)((uint)*(undefined2 *)(in_BX + (int)&param_1) >> 8) + in_BX[0x5019];
    pbVar25 = (byte *)((int)&param_1 +
                      (-(uint)CARRY1(bVar9,(byte)param_1) - *(int *)(in_BX + (int)&param_1)));
    in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),
                             (char)in_BX + pbVar25[-0x7f02] +
                             CARRY1((byte)*(undefined2 *)(in_BX + (int)&param_1),*(byte *)0x701b));
    bVar27 = 1;
    pbVar25[0xf] = pbVar25[0xf] ^ bVar9 + (byte)param_1;
  }
  else {
    pcVar2 = &stack0x30ff + (int)in_BX;
    *pcVar2 = *pcVar2 + '\x01';
    if (*pcVar2 == '\0') {
      pbVar25 = (byte *)((int)&param_1 + 1);
      pcVar5[unaff_BP + 0x2c3] = pcVar5[unaff_BP + 0x2c3] + '\x01';
      goto FUN_1000_5f28;
    }
  }
  uVar18 = *(undefined2 *)(pbVar25 + unaff_BP + 0x4030);
  *(uint *)(unaff_BP + -2) = uVar10;
FUN_1000_5f28:
  bVar9 = (byte)((uint)uVar18 >> 8);
  pbVar25[unaff_BP + -0x10] = pbVar25[unaff_BP + -0x10] | bVar9;
  cVar13 = *pcVar5;
  pbVar23 = (byte *)(unaff_DI + (uint)bVar27 * -2 + 2);
  *pcVar5 = (char)uVar10;
  cVar16 = (byte)uVar18 + pbVar25[unaff_BP];
  uVar17 = CONCAT11(bVar9,cVar16);
  if (CARRY1((byte)uVar18,pbVar25[unaff_BP])) {
    unaff_SS = CONCAT11((char)(uVar10 >> 8) + cVar13,199);
    in_BX[(int)(pbVar25 + 1)] = in_BX[(int)(pbVar25 + 1)] + 1;
    pbVar25 = pbVar25 + 2;
    uVar10 = in(uVar17);
    if (iVar14 == 0) {
      iVar14 = 0x50;
    }
    *(int *)(unaff_BP + -4) = iVar14;
    uVar10 = uVar10 & 0xff00;
    iVar14 = 0xa0;
    pbVar19 = pbVar25;
  }
  else {
    unaff_ES = 0xa800;
    pbVar23 = (byte *)0x1690;
    uRam000a968e = 0xa800;
    *(char *)0x19 = *(char *)0x19 + cVar16;
    while( true ) {
      for (; param_1 != (byte *)0x0; param_1 = param_1 + -1) {
        pbVar6 = pbVar23;
        pbVar23 = pbVar23 + 2;
        pbVar6[0] = 0;
        pbVar6[1] = 0xa8;
      }
      pbVar23 = pbVar23 + 0x1e;
      if (in_BX <= pbVar23) break;
      *(int *)(in_BX + (int)pbVar25) = *(int *)(in_BX + (int)pbVar25) + 0x57ff;
    }
    param_3 = &stack0x0010;
    pbVar6 = in_BX;
    bVar9 = *pbVar6;
    *pbVar6 = *pbVar6 + 0x58;
    uVar10 = CONCAT11(0xa8,-(bVar9 < 0xa8) - *pbVar25);
    *(undefined2 *)(unaff_BP + -2) = 0;
    *(undefined2 *)(unaff_BP + -4) = 0x50;
    iVar14 = 0;
    pbVar19 = pbVar23;
    param_1 = pbVar25;
    param_2 = unaff_BP;
    in_stack_00000010 = pbVar23;
    in_stack_00000012 = pbVar25;
  }
  do {
    uVar29 = CONCAT22(uVar17,uVar10);
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    pbVar6 = pbVar19;
    pbVar19 = pbVar19 + 1;
    uVar29 = CONCAT22(uVar17,uVar10);
  } while ((byte)uVar10 != *pbVar6);
LAB_1000_5f7e:
  uVar18 = (undefined2)((ulong)uVar29 >> 0x10);
  pbVar6 = pbVar25;
  pbVar25 = pbVar25 + 1;
  bVar9 = *pbVar6;
  uVar10 = CONCAT11((char)((ulong)uVar29 >> 8),bVar9);
  uVar29 = CONCAT22(uVar18,uVar10);
  if (0x1f < bVar9) {
    if (bVar9 == 0x20) {
LAB_1000_5fc7:
      uVar18 = (undefined2)((ulong)uVar29 >> 0x10);
      pbVar23 = pbVar23 + 1;
      piVar3 = (int *)(unaff_BP + -4);
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar9 = (byte)uVar10, bVar9 == 0x40) {
      pbVar6 = pbVar25;
      pbVar25 = pbVar25 + 1;
      uVar10 = (uint)*pbVar6;
      iVar15 = 0x1c;
      pbVar24 = (byte *)0x2847;
      bVar28 = true;
      do {
        if (iVar15 == 0) break;
        iVar15 = iVar15 + -1;
        pbVar4 = pbVar24;
        pbVar24 = pbVar24 + 1;
        bVar28 = *pbVar6 == *pbVar4;
      } while (!bVar28);
      if (bVar28) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar14 = (*(code *)*(undefined2 *)((int)(pbVar24 + -0x2848) * 2 + 0x78bb))();
        return iVar14;
      }
    }
    if ((0x7f < bVar9) && ((bVar9 < 0xa0 || (0xdf < bVar9)))) {
      pbVar6 = pbVar25;
      pbVar25 = pbVar25 + 1;
      uVar29 = CONCAT22(uVar18,CONCAT11(bVar9,*pbVar6));
      if (CONCAT11(bVar9,*pbVar6) != 0x4081) {
        uVar10 = FUN_1000_8401();
        if ((0x2920 < uVar10) && (uVar10 < 0x2b7f)) {
          param_1 = (byte *)0x5fc4;
          FUN_1000_5c7d();
          param_2 = 0x5fc7;
          uVar29 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        param_1 = (byte *)0x5fad;
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        param_2 = 0x5fb0;
        uVar29 = func_0x00016305();
      }
      uVar18 = (undefined2)((ulong)uVar29 >> 0x10);
      pbVar23 = pbVar23 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar10 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar10 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        puVar21 = (uint *)(param_2 + -2);
        iVar15 = 0x10;
        puVar8 = puVar21;
        pbVar25 = pbVar23;
        do {
          pbVar19 = pbVar25;
          puVar22 = puVar8;
          puVar8 = puVar22 + 1;
          uVar10 = *puVar22;
          *(uint *)(pbVar19 + -0x50) = uVar10;
          *(uint *)(pbVar19 + 0x50) = uVar10;
          uVar11 = CONCAT11((char)uVar10,(char)(uVar10 >> 8));
          uVar7 = uVar11 * 2;
          bVar9 = ((uVar10 & 0x100) != 0) << 7;
          iVar20 = CONCAT11(bVar9,CARRY2(uVar11,uVar11));
          uVar10 = uVar11 | uVar7 | uVar11 >> 1;
          bVar27 = (byte)(uVar10 >> 8);
          iVar12 = CONCAT11((char)uVar10,bVar27);
          pbVar19[-1] = CARRY2(uVar11,uVar11);
          *(int *)pbVar19 = iVar12;
          pbVar19[1] = bVar9;
          iVar15 = iVar15 + -1;
          pbVar25 = pbVar19 + 0x50;
        } while (iVar15 != 0);
        *(byte *)puVar8 = (byte)*puVar8 ^ bVar27;
        pbVar6 = pbVar19 + 0x4f;
        *pbVar6 = *pbVar6 + bVar27;
        pbVar19[0x4f] = bVar27;
        pbVar25 = pbVar19 + 0x51;
        uVar10 = iVar12 + 1;
        *(byte *)(puVar8 + uVar11) =
             (byte)puVar8[uVar11] + (byte)uVar10 + (((uint)pbVar23 & 1) != 0);
        bVar28 = ((uint)puVar21 & 4) != 0;
        if (((uint)puVar21 & 8) == 0) {
          *(byte *)(puVar22 + 0x1a4) = (byte)puVar22[0x1a4] + (char)(uVar10 >> 8);
          pbVar19[0x50] = (byte)*puVar8;
          iVar12 = (uint)bVar28 * -2 + 2;
          pbVar25 = pbVar25 + uVar10 + (uint)bVar28 * -2;
          pbVar6 = (byte *)((int)puVar8 + iVar20 + iVar12 + 0x10);
          *pbVar6 = *pbVar6 | (byte)(uVar11 >> 1);
          pbVar6 = (byte *)((int)puVar8 + iVar20 + iVar12);
          *pbVar6 = *pbVar6 << 1;
          LOCK();
          pbVar6 = (byte *)((int)puVar8 + iVar20 + iVar12 + 0x30ac);
          *pbVar6 = *pbVar6 ^ (byte)uVar10;
          UNLOCK();
        }
        iVar12 = *(int *)0x32a8;
        param_1 = (byte *)uVar18;
        param_2 = iVar14;
        FUN_1000_5aba();
        pbVar25[uVar7 + 0xbad9] = pbVar25[uVar7 + 0xbad9] - (byte)iVar15;
        pbVar25[uVar7] = pbVar25[uVar7] + (char)((uint)iVar15 >> 8);
        piVar3 = (int *)(iVar20 + iVar12 + 0x10ff);
        *piVar3 = *piVar3 >> ((byte)iVar15 & 0x1f);
        iVar14 = iVar20;
        cVar13 = extraout_AH;
        do {
          for (; iVar14 != 0; iVar14 = iVar14 + -1) {
            pbVar6 = pbVar25;
            pbVar25 = pbVar25 + (uint)bVar28 * -2 + 1;
            *pbVar6 = extraout_AL;
          }
          bVar26 = CARRY2((uint)pbVar25,extraout_DX);
          pbVar25 = pbVar25 + extraout_DX;
          cVar13 = cVar13 + -1;
          iVar14 = iVar20;
        } while (cVar13 != '\0');
        return (byte)-bVar26 + 0x6108 + (uint)bVar26;
      }
      goto LAB_1000_5f7e;
    }
    uVar29 = func_0x000163ff();
    uVar18 = (undefined2)((ulong)uVar29 >> 0x10);
    uVar10 = (int)uVar29 + 1;
    pbVar19[2] = (char)pbVar19[2] >> 0xb;
    bVar9 = (byte)uVar10;
    if (bVar9 != 0) {
      uVar10 = CONCAT11((char)(uVar10 >> 8),bVar9 - 0x10);
      uVar29 = CONCAT22(uVar18,uVar10);
      if (bVar9 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar9 - 0x10;
      pbVar19 = pbVar23 + 1;
      pbVar23 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar18,uVar10);
  uVar18 = CONCAT11((char)((uint)uVar18 >> 8),4);
  goto LAB_1000_625d;
}


