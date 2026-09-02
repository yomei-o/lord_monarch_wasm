/* 1000:6070 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_1000_6070(int param_1,undefined2 *param_2)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint *puVar6;
  byte extraout_AL;
  int in_AX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char extraout_AH;
  char cVar10;
  int iVar11;
  undefined2 in_CX;
  int iVar12;
  char cVar13;
  undefined2 in_DX;
  byte bVar15;
  uint extraout_DX;
  byte *pbVar16;
  byte *in_BX;
  int iVar17;
  int unaff_BP;
  int unaff_SI;
  uint *puVar18;
  uint *puVar19;
  byte *pbVar20;
  byte *pbVar21;
  char *unaff_DI;
  byte *pbVar22;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar23;
  byte bVar24;
  bool bVar25;
  undefined4 uVar26;
  int in_stack_00000000;
  byte *in_stack_0000000e;
  byte *in_stack_00000010;
  undefined2 uVar14;
  
  bVar24 = 0;
  uVar7 = in_AX + 1;
  iVar11 = CONCAT11((char)((uint)in_CX >> 8) + (char)uVar7,
                    (char)in_CX + unaff_DI[unaff_BP + -0x74fc] + in_CF);
  puVar1 = (uint *)(unaff_BP + unaff_SI);
  *puVar1 = *puVar1 ^ uVar7;
  if ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) {
    bVar15 = (char)((uint)*(undefined2 *)(in_BX + (int)register0x00000010) >> 8) + in_BX[0x5019];
    pbVar22 = &stack0x0000 +
              (-(uint)CARRY1(bVar15,(byte)in_stack_00000000) -
              *(int *)(in_BX + (int)register0x00000010));
    in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),
                             (char)in_BX + pbVar22[-0x7f02] +
                             CARRY1((byte)*(undefined2 *)(in_BX + (int)register0x00000010),
                                    *(byte *)0x701b));
    bVar24 = 1;
    pbVar22[0xf] = pbVar22[0xf] ^ bVar15 + (byte)in_stack_00000000;
  }
  else {
    pbVar4 = in_BX + (int)register0x00000010 + 0x30fd;
    *pbVar4 = *pbVar4 + 1;
    pbVar22 = (byte *)register0x00000010;
    if (*pbVar4 == 0) {
      pbVar22 = &stack0x0001;
      unaff_DI[unaff_BP + 0x2c3] = unaff_DI[unaff_BP + 0x2c3] + '\x01';
      goto FUN_1000_5f28;
    }
  }
  in_DX = *(undefined2 *)(pbVar22 + unaff_BP + 0x4030);
  *(uint *)(unaff_BP + -2) = uVar7;
FUN_1000_5f28:
  bVar15 = (byte)((uint)in_DX >> 8);
  pbVar22[unaff_BP + -0x10] = pbVar22[unaff_BP + -0x10] | bVar15;
  cVar10 = *unaff_DI;
  pbVar20 = (byte *)(unaff_DI + (uint)bVar24 * -2 + 1);
  *unaff_DI = (char)uVar7;
  cVar13 = (byte)in_DX + pbVar22[unaff_BP];
  uVar14 = CONCAT11(bVar15,cVar13);
  if (CARRY1((byte)in_DX,pbVar22[unaff_BP])) {
    unaff_SS = CONCAT11((char)(uVar7 >> 8) + cVar10,199);
    in_BX[(int)(pbVar22 + 1)] = in_BX[(int)(pbVar22 + 1)] + 1;
    pbVar22 = pbVar22 + 2;
    uVar7 = in(uVar14);
    if (iVar11 == 0) {
      iVar11 = 0x50;
    }
    *(int *)(unaff_BP + -4) = iVar11;
    uVar7 = uVar7 & 0xff00;
    iVar11 = 0xa0;
    pbVar16 = pbVar22;
  }
  else {
    unaff_ES = 0xa800;
    in_stack_0000000e = (byte *)0x1690;
    uRam000a968e = 0xa800;
    *(char *)0x19 = *(char *)0x19 + cVar13;
    while( true ) {
      for (; in_stack_00000000 != 0; in_stack_00000000 = in_stack_00000000 + -1) {
        pbVar4 = in_stack_0000000e;
        in_stack_0000000e = in_stack_0000000e + 2;
        pbVar4[0] = 0;
        pbVar4[1] = 0xa8;
      }
      in_stack_0000000e = in_stack_0000000e + 0x1e;
      if (in_BX <= in_stack_0000000e) break;
      *(int *)(in_BX + (int)pbVar22) = *(int *)(in_BX + (int)pbVar22) + 0x57ff;
    }
    param_2 = &stack0x000e;
    pbVar4 = in_BX;
    bVar24 = *pbVar4;
    *pbVar4 = *pbVar4 + 0x58;
    uVar7 = CONCAT11(0xa8,-(bVar24 < 0xa8) - *pbVar22);
    *(undefined2 *)(unaff_BP + -2) = 0;
    *(undefined2 *)(unaff_BP + -4) = 0x50;
    iVar11 = 0;
    pbVar16 = in_stack_0000000e;
    param_1 = unaff_BP;
    in_stack_00000010 = pbVar22;
    pbVar20 = in_stack_0000000e;
  }
  do {
    uVar26 = CONCAT22(uVar14,uVar7);
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pbVar4 = pbVar16;
    pbVar16 = pbVar16 + 1;
    uVar26 = CONCAT22(uVar14,uVar7);
  } while ((byte)uVar7 != *pbVar4);
LAB_1000_5f7e:
  uVar14 = (undefined2)((ulong)uVar26 >> 0x10);
  pbVar4 = pbVar22;
  pbVar22 = pbVar22 + 1;
  bVar24 = *pbVar4;
  uVar7 = CONCAT11((char)((ulong)uVar26 >> 8),bVar24);
  uVar26 = CONCAT22(uVar14,uVar7);
  if (0x1f < bVar24) {
    if (bVar24 == 0x20) {
LAB_1000_5fc7:
      pbVar20 = pbVar20 + 1;
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar24 = (byte)uVar7, bVar24 == 0x40) {
      pbVar4 = pbVar22;
      pbVar22 = pbVar22 + 1;
      uVar7 = (uint)*pbVar4;
      iVar12 = 0x1c;
      pbVar21 = (byte *)0x2847;
      bVar25 = true;
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        pbVar3 = pbVar21;
        pbVar21 = pbVar21 + 1;
        bVar25 = *pbVar4 == *pbVar3;
      } while (!bVar25);
      if (bVar25) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar11 = (*(code *)*(undefined2 *)((int)(pbVar21 + -0x2848) * 2 + 0x78bb))();
        return iVar11;
      }
    }
    if ((0x7f < bVar24) && ((bVar24 < 0xa0 || (0xdf < bVar24)))) {
      pbVar4 = pbVar22;
      pbVar22 = pbVar22 + 1;
      uVar26 = CONCAT22(uVar14,CONCAT11(bVar24,*pbVar4));
      if (CONCAT11(bVar24,*pbVar4) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          param_1 = 0x5fc7;
          uVar26 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        param_1 = 0x5fb0;
        uVar26 = func_0x00016305();
      }
      pbVar20 = pbVar20 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar7 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        puVar18 = (uint *)(param_1 + -2);
        iVar12 = 0x10;
        puVar6 = puVar18;
        pbVar22 = pbVar20;
        do {
          pbVar16 = pbVar22;
          puVar19 = puVar6;
          puVar6 = puVar19 + 1;
          uVar7 = *puVar19;
          *(uint *)(pbVar16 + -0x50) = uVar7;
          *(uint *)(pbVar16 + 0x50) = uVar7;
          uVar8 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar5 = uVar8 * 2;
          bVar24 = ((uVar7 & 0x100) != 0) << 7;
          iVar17 = CONCAT11(bVar24,CARRY2(uVar8,uVar8));
          uVar7 = uVar8 | uVar5 | uVar8 >> 1;
          bVar15 = (byte)(uVar7 >> 8);
          iVar9 = CONCAT11((char)uVar7,bVar15);
          pbVar16[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar16 = iVar9;
          pbVar16[1] = bVar24;
          iVar12 = iVar12 + -1;
          pbVar22 = pbVar16 + 0x50;
        } while (iVar12 != 0);
        *(byte *)puVar6 = (byte)*puVar6 ^ bVar15;
        pbVar4 = pbVar16 + 0x4f;
        *pbVar4 = *pbVar4 + bVar15;
        pbVar16[0x4f] = bVar15;
        pbVar22 = pbVar16 + 0x51;
        uVar7 = iVar9 + 1;
        *(byte *)(puVar6 + uVar8) = (byte)puVar6[uVar8] + (byte)uVar7 + (((uint)pbVar20 & 1) != 0);
        bVar25 = ((uint)puVar18 & 4) != 0;
        if (((uint)puVar18 & 8) == 0) {
          *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar7 >> 8);
          pbVar16[0x50] = (byte)*puVar6;
          iVar9 = (uint)bVar25 * -2 + 2;
          pbVar22 = pbVar22 + uVar7 + (uint)bVar25 * -2;
          pbVar4 = (byte *)((int)puVar6 + iVar17 + iVar9 + 0x10);
          *pbVar4 = *pbVar4 | (byte)(uVar8 >> 1);
          pbVar4 = (byte *)((int)puVar6 + iVar17 + iVar9);
          *pbVar4 = *pbVar4 << 1;
          LOCK();
          pbVar4 = (byte *)((int)puVar6 + iVar17 + iVar9 + 0x30ac);
          *pbVar4 = *pbVar4 ^ (byte)uVar7;
          UNLOCK();
        }
        iVar9 = *(int *)0x32a8;
        param_1 = iVar11;
        FUN_1000_5aba();
        pbVar22[uVar5 + 0xbad9] = pbVar22[uVar5 + 0xbad9] - (byte)iVar12;
        pbVar22[uVar5] = pbVar22[uVar5] + (char)((uint)iVar12 >> 8);
        piVar2 = (int *)(iVar17 + iVar9 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar12 & 0x1f);
        iVar11 = iVar17;
        cVar10 = extraout_AH;
        do {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pbVar4 = pbVar22;
            pbVar22 = pbVar22 + (uint)bVar25 * -2 + 1;
            *pbVar4 = extraout_AL;
          }
          bVar23 = CARRY2((uint)pbVar22,extraout_DX);
          pbVar22 = pbVar22 + extraout_DX;
          cVar10 = cVar10 + -1;
          iVar11 = iVar17;
        } while (cVar10 != '\0');
        return (byte)-bVar23 + 0x6108 + (uint)bVar23;
      }
      goto LAB_1000_5f7e;
    }
    uVar26 = func_0x000163ff();
    uVar14 = (undefined2)((ulong)uVar26 >> 0x10);
    uVar7 = (int)uVar26 + 1;
    pbVar16[2] = (char)pbVar16[2] >> 0xb;
    bVar24 = (byte)uVar7;
    if (bVar24 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar24 - 0x10);
      uVar26 = CONCAT22(uVar14,uVar7);
      if (bVar24 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar24 - 0x10;
      pbVar16 = pbVar20 + 1;
      pbVar20 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar14,uVar7);
  goto LAB_1000_625d;
}


