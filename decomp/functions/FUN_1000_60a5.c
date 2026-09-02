/* 1000:60a5 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_60a5(int param_1,undefined2 *param_2)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte bVar6;
  byte extraout_AL;
  uint uVar7;
  undefined2 in_AX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar12;
  int iVar13;
  int in_CX;
  char cVar14;
  undefined2 in_DX;
  uint extraout_DX;
  int in_BX;
  byte *pbVar16;
  int iVar17;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar18;
  uint *puVar19;
  byte *pbVar20;
  byte *pbVar21;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar22;
  bool bVar23;
  undefined4 uVar24;
  int in_stack_00000000;
  byte *in_stack_0000000e;
  byte bVar11;
  undefined2 uVar15;
  
  pbVar16 = (byte *)(in_BX + 2);
  bVar6 = (byte)((uint)in_DX >> 8);
  unaff_SI[unaff_BP + -0x10] = unaff_SI[unaff_BP + -0x10] | bVar6;
  cVar12 = *unaff_DI;
  pbVar20 = (byte *)(unaff_DI + 1);
  *unaff_DI = (char)in_AX;
  cVar14 = (byte)in_DX + unaff_SI[unaff_BP];
  uVar15 = CONCAT11(bVar6,cVar14);
  if (CARRY1((byte)in_DX,unaff_SI[unaff_BP])) {
    unaff_SS = CONCAT11((char)((uint)in_AX >> 8) + cVar12,199);
    pbVar16[(int)(unaff_SI + 1)] = pbVar16[(int)(unaff_SI + 1)] + 1;
    unaff_SI = unaff_SI + 2;
    uVar7 = in(uVar15);
    if (in_CX == 0) {
      in_CX = 0x50;
    }
    *(int *)(unaff_BP + -4) = in_CX;
    uVar7 = uVar7 & 0xff00;
    iVar13 = 0xa0;
    pbVar16 = unaff_SI;
  }
  else {
    unaff_ES = 0xa800;
    in_stack_0000000e = (byte *)0x1690;
    uRam000a968e = 0xa800;
    *(char *)0x19 = *(char *)0x19 + cVar14;
    while( true ) {
      for (; in_stack_00000000 != 0; in_stack_00000000 = in_stack_00000000 + -1) {
        pbVar4 = in_stack_0000000e;
        in_stack_0000000e = in_stack_0000000e + 2;
        pbVar4[0] = 0;
        pbVar4[1] = 0xa8;
      }
      in_stack_0000000e = in_stack_0000000e + 0x1e;
      if (pbVar16 <= in_stack_0000000e) break;
      *(int *)(pbVar16 + (int)unaff_SI) = *(int *)(pbVar16 + (int)unaff_SI) + 0x57ff;
    }
    param_2 = &stack0x000e;
    pbVar4 = pbVar16;
    bVar6 = *pbVar4;
    *pbVar4 = *pbVar4 + 0x58;
    uVar7 = CONCAT11(0xa8,-(bVar6 < 0xa8) - *unaff_SI);
    *(undefined2 *)(unaff_BP + -2) = 0;
    *(undefined2 *)(unaff_BP + -4) = 0x50;
    iVar13 = 0;
    pbVar16 = in_stack_0000000e;
    param_1 = unaff_BP;
    pbVar20 = in_stack_0000000e;
  }
  do {
    uVar24 = CONCAT22(uVar15,uVar7);
    if (iVar13 == 0) break;
    iVar13 = iVar13 + -1;
    pbVar4 = pbVar16;
    pbVar16 = pbVar16 + 1;
    uVar24 = CONCAT22(uVar15,uVar7);
  } while ((byte)uVar7 != *pbVar4);
LAB_1000_5f7e:
  uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
  pbVar4 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  bVar6 = *pbVar4;
  uVar7 = CONCAT11((char)((ulong)uVar24 >> 8),bVar6);
  uVar24 = CONCAT22(uVar15,uVar7);
  if (0x1f < bVar6) {
    if (bVar6 == 0x20) {
LAB_1000_5fc7:
      pbVar20 = pbVar20 + 1;
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar6 = (byte)uVar7, bVar6 == 0x40) {
      pbVar4 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar7 = (uint)*pbVar4;
      iVar13 = 0x1c;
      pbVar21 = (byte *)0x2847;
      bVar23 = true;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pbVar3 = pbVar21;
        pbVar21 = pbVar21 + 1;
        bVar23 = *pbVar4 == *pbVar3;
      } while (!bVar23);
      if (bVar23) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar13 = (*(code *)*(undefined2 *)((int)(pbVar21 + -0x2848) * 2 + 0x78bb))();
        return iVar13;
      }
    }
    if ((0x7f < bVar6) && ((bVar6 < 0xa0 || (0xdf < bVar6)))) {
      pbVar4 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar24 = CONCAT22(uVar15,CONCAT11(bVar6,*pbVar4));
      if (CONCAT11(bVar6,*pbVar4) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          param_1 = 0x5fc7;
          uVar24 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        param_1 = 0x5fb0;
        uVar24 = func_0x00016305();
      }
      pbVar20 = pbVar20 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar7 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar13 = 0x10;
        puVar19 = (uint *)(param_1 + -2);
        pbVar16 = pbVar20;
        do {
          pbVar21 = pbVar16;
          puVar18 = puVar19;
          puVar19 = puVar18 + 1;
          uVar7 = *puVar18;
          *(uint *)(pbVar21 + -0x50) = uVar7;
          *(uint *)(pbVar21 + 0x50) = uVar7;
          uVar8 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar5 = uVar8 * 2;
          bVar6 = ((uVar7 & 0x100) != 0) << 7;
          iVar17 = CONCAT11(bVar6,CARRY2(uVar8,uVar8));
          uVar7 = uVar8 | uVar5 | uVar8 >> 1;
          bVar11 = (byte)(uVar7 >> 8);
          iVar9 = CONCAT11((char)uVar7,bVar11);
          pbVar21[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar21 = iVar9;
          pbVar21[1] = bVar6;
          iVar13 = iVar13 + -1;
          pbVar16 = pbVar21 + 0x50;
        } while (iVar13 != 0);
        *(byte *)puVar19 = (byte)*puVar19 ^ bVar11;
        pbVar4 = pbVar21 + 0x4f;
        *pbVar4 = *pbVar4 + bVar11;
        pbVar21[0x4f] = bVar11;
        pbVar16 = pbVar21 + 0x51;
        uVar10 = iVar9 + 1;
        *(byte *)(puVar19 + uVar8) =
             (byte)puVar19[uVar8] + (byte)uVar10 + (((uint)pbVar20 & 1) != 0);
        uVar7 = (param_1 + -2) * 0x100;
        bVar23 = (uVar7 & 0x400) != 0;
        if ((uVar7 & 0x800) == 0) {
          *(byte *)(puVar18 + 0x1a4) = (byte)puVar18[0x1a4] + (char)(uVar10 >> 8);
          pbVar21[0x50] = (byte)*puVar19;
          puVar19 = puVar19 + !bVar23;
          pbVar16 = pbVar16 + uVar10 + (uint)bVar23 * -2;
          pbVar4 = (byte *)((int)puVar19 + iVar17 + 0x10);
          *pbVar4 = *pbVar4 | (byte)(uVar8 >> 1);
          *(byte *)(iVar17 + (int)puVar19) = *(byte *)(iVar17 + (int)puVar19) << 1;
          LOCK();
          pbVar4 = (byte *)((int)puVar19 + iVar17 + 0x30ac);
          *pbVar4 = *pbVar4 ^ (byte)uVar10;
          UNLOCK();
        }
        iVar9 = *(int *)0x32a8;
        FUN_1000_5aba(uVar10,(char)puVar19);
        pbVar16[uVar5 + 0xbad9] = pbVar16[uVar5 + 0xbad9] - (byte)iVar13;
        pbVar16[uVar5] = pbVar16[uVar5] + (char)((uint)iVar13 >> 8);
        piVar2 = (int *)(iVar17 + iVar9 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar13 & 0x1f);
        iVar13 = iVar17;
        cVar12 = extraout_AH;
        do {
          for (; iVar13 != 0; iVar13 = iVar13 + -1) {
            pbVar4 = pbVar16;
            pbVar16 = pbVar16 + (uint)bVar23 * -2 + 1;
            *pbVar4 = extraout_AL;
          }
          bVar22 = CARRY2((uint)pbVar16,extraout_DX);
          pbVar16 = pbVar16 + extraout_DX;
          cVar12 = cVar12 + -1;
          iVar13 = iVar17;
        } while (cVar12 != '\0');
        return (byte)-bVar22 + 0x6108 + (uint)bVar22;
      }
      goto LAB_1000_5f7e;
    }
    uVar24 = func_0x000163ff();
    uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
    uVar7 = (int)uVar24 + 1;
    pbVar16[2] = (char)pbVar16[2] >> 0xb;
    bVar6 = (byte)uVar7;
    if (bVar6 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar6 - 0x10);
      uVar24 = CONCAT22(uVar15,uVar7);
      if (bVar6 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar6 - 0x10;
      pbVar16 = pbVar20 + 1;
      pbVar20 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar15,uVar7);
  goto LAB_1000_625d;
}


