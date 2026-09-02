/* 1000:60ec */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_60ec(undefined2 param_1,int param_2,undefined2 *param_3)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte bVar6;
  byte extraout_AL;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char extraout_AH;
  char cVar12;
  uint in_CX;
  byte bVar13;
  byte bVar17;
  undefined2 uVar15;
  int in_DX;
  int iVar16;
  uint extraout_DX;
  int in_BX;
  byte *pbVar18;
  int unaff_BP;
  int unaff_SI;
  uint *puVar19;
  uint *puVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *unaff_DI;
  undefined2 unaff_ES;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar23;
  bool bVar24;
  undefined4 uVar25;
  byte *in_stack_00000000;
  byte *in_stack_00000010;
  byte *in_stack_00000012;
  undefined2 uVar14;
  
  iVar16 = in_DX + *(int *)(unaff_BP + -0x75) + (uint)in_CF;
  iVar8 = (*(uint *)(unaff_SI + 1) & 0xff) * (in_CX & 0xff) + *(int *)(in_BX + 2);
  pbVar18 = (byte *)(in_BX + 4);
  *(int *)pbVar18 = iVar8;
  bVar17 = (byte)((uint)iVar16 >> 8);
  bVar13 = (byte)iVar16 & in_stack_00000000[unaff_BP + 0x50];
  uVar14 = CONCAT11(bVar17,bVar13);
  bVar6 = (byte)(in_CX >> 8);
  cVar12 = bVar6 + pbVar18[(int)in_stack_00000000];
  iVar16 = CONCAT11(cVar12,(char)in_CX) + -1;
  uVar15 = uVar14;
  pbVar21 = unaff_DI;
  if (iVar16 == 0 || cVar12 == '\0') {
    unaff_DI[unaff_BP] =
         unaff_DI[unaff_BP] + (char)((uint)iVar8 >> 8) +
         CARRY1(bVar6,pbVar18[(int)in_stack_00000000]);
    in_stack_00000000[unaff_BP + -0x10] = in_stack_00000000[unaff_BP + -0x10] | bVar17;
    pbVar21 = unaff_DI + 1;
    *unaff_DI = (char)iVar8 - 0x18;
    cVar12 = bVar13 + in_stack_00000000[unaff_BP];
    uVar15 = CONCAT11(bVar17,cVar12);
    if (!CARRY1(bVar13,in_stack_00000000[unaff_BP])) {
      unaff_ES = 0xa800;
      pbVar21 = (byte *)0x1690;
      uRam000a968e = 0xa800;
      *(char *)0x19 = *(char *)0x19 + cVar12;
      while( true ) {
        for (; unaff_DI != (byte *)0x0; unaff_DI = unaff_DI + -1) {
          pbVar4 = pbVar21;
          pbVar21 = pbVar21 + 2;
          pbVar4[0] = 0;
          pbVar4[1] = 0xa8;
        }
        pbVar21 = pbVar21 + 0x1e;
        if (pbVar18 <= pbVar21) break;
        *(int *)(pbVar18 + (int)in_stack_00000000) =
             *(int *)(pbVar18 + (int)in_stack_00000000) + 0x57ff;
      }
      param_3 = &stack0x0010;
      pbVar4 = pbVar18;
      bVar6 = *pbVar4;
      *pbVar4 = *pbVar4 + 0x58;
      uVar7 = CONCAT11(0xa8,-(bVar6 < 0xa8) - *in_stack_00000000);
      *(undefined2 *)(unaff_BP + -2) = 0;
      *(undefined2 *)(unaff_BP + -4) = 0x50;
      iVar8 = 0;
      pbVar18 = pbVar21;
      uVar14 = unaff_SS;
      param_2 = unaff_BP;
      in_stack_00000010 = pbVar21;
      in_stack_00000012 = in_stack_00000000;
      goto LAB_1000_5f79;
    }
    pbVar18[(int)(in_stack_00000000 + 1)] = pbVar18[(int)(in_stack_00000000 + 1)] + 1;
    in_stack_00000000 = in_stack_00000000 + 2;
  }
  uVar7 = in(uVar15);
  if (iVar16 == 0) {
    iVar16 = 0x50;
  }
  *(int *)(unaff_BP + -4) = iVar16;
  uVar7 = uVar7 & 0xff00;
  iVar8 = 0xa0;
  pbVar18 = in_stack_00000000;
LAB_1000_5f79:
  do {
    uVar25 = CONCAT22(uVar15,uVar7);
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pbVar4 = pbVar18;
    pbVar18 = pbVar18 + 1;
    uVar25 = CONCAT22(uVar15,uVar7);
  } while ((byte)uVar7 != *pbVar4);
LAB_1000_5f7e:
  uVar15 = (undefined2)((ulong)uVar25 >> 0x10);
  pbVar4 = in_stack_00000000;
  in_stack_00000000 = in_stack_00000000 + 1;
  bVar6 = *pbVar4;
  uVar7 = CONCAT11((char)((ulong)uVar25 >> 8),bVar6);
  uVar25 = CONCAT22(uVar15,uVar7);
  if (0x1f < bVar6) {
    if (bVar6 == 0x20) {
LAB_1000_5fc7:
      pbVar21 = pbVar21 + 1;
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar6 = (byte)uVar7, bVar6 == 0x40) {
      pbVar4 = in_stack_00000000;
      in_stack_00000000 = in_stack_00000000 + 1;
      uVar7 = (uint)*pbVar4;
      iVar8 = 0x1c;
      pbVar22 = (byte *)0x2847;
      bVar24 = true;
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pbVar3 = pbVar22;
        pbVar22 = pbVar22 + 1;
        bVar24 = *pbVar4 == *pbVar3;
      } while (!bVar24);
      if (bVar24) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar8 = (*(code *)*(undefined2 *)((int)(pbVar22 + -0x2848) * 2 + 0x78bb))();
        return iVar8;
      }
    }
    if ((0x7f < bVar6) && ((bVar6 < 0xa0 || (0xdf < bVar6)))) {
      pbVar4 = in_stack_00000000;
      in_stack_00000000 = in_stack_00000000 + 1;
      uVar25 = CONCAT22(uVar15,CONCAT11(bVar6,*pbVar4));
      if (CONCAT11(bVar6,*pbVar4) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          param_2 = 0x5fc7;
          uVar25 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        param_2 = 0x5fb0;
        uVar25 = func_0x00016305();
      }
      pbVar21 = pbVar21 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar7 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar8 = 0x10;
        puVar20 = (uint *)(param_2 + -2);
        pbVar18 = pbVar21;
        do {
          pbVar22 = pbVar18;
          puVar19 = puVar20;
          puVar20 = puVar19 + 1;
          uVar7 = *puVar19;
          *(uint *)(pbVar22 + -0x50) = uVar7;
          *(uint *)(pbVar22 + 0x50) = uVar7;
          uVar9 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar5 = uVar9 * 2;
          bVar6 = ((uVar7 & 0x100) != 0) << 7;
          iVar16 = CONCAT11(bVar6,CARRY2(uVar9,uVar9));
          uVar7 = uVar9 | uVar5 | uVar9 >> 1;
          bVar13 = (byte)(uVar7 >> 8);
          iVar10 = CONCAT11((char)uVar7,bVar13);
          pbVar22[-1] = CARRY2(uVar9,uVar9);
          *(int *)pbVar22 = iVar10;
          pbVar22[1] = bVar6;
          iVar8 = iVar8 + -1;
          pbVar18 = pbVar22 + 0x50;
        } while (iVar8 != 0);
        *(byte *)puVar20 = (byte)*puVar20 ^ bVar13;
        pbVar4 = pbVar22 + 0x4f;
        *pbVar4 = *pbVar4 + bVar13;
        pbVar22[0x4f] = bVar13;
        pbVar18 = pbVar22 + 0x51;
        uVar11 = iVar10 + 1;
        bVar6 = (byte)uVar11;
        *(byte *)(puVar20 + uVar9) = (byte)puVar20[uVar9] + bVar6 + (((uint)pbVar21 & 1) != 0);
        uVar7 = (param_2 + -2) * 0x100;
        bVar24 = (uVar7 & 0x400) != 0;
        if ((uVar7 & 0x800) == 0) {
          *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar11 >> 8);
          pbVar22[0x50] = (byte)*puVar20;
          puVar20 = puVar20 + !bVar24;
          pbVar18 = pbVar18 + uVar11 + (uint)bVar24 * -2;
          pbVar4 = (byte *)((int)puVar20 + iVar16 + 0x10);
          *pbVar4 = *pbVar4 | (byte)(uVar9 >> 1);
          *(byte *)(iVar16 + (int)puVar20) = *(byte *)(iVar16 + (int)puVar20) << 1;
          LOCK();
          pbVar4 = (byte *)((int)puVar20 + iVar16 + 0x30ac);
          *pbVar4 = *pbVar4 ^ bVar6;
          UNLOCK();
        }
        iVar10 = *(int *)0x32a8;
        FUN_1000_5aba(bVar6,(char)puVar20);
        pbVar18[uVar5 + 0xbad9] = pbVar18[uVar5 + 0xbad9] - (byte)iVar8;
        pbVar18[uVar5] = pbVar18[uVar5] + (char)((uint)iVar8 >> 8);
        piVar2 = (int *)(iVar16 + iVar10 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar8 & 0x1f);
        iVar8 = iVar16;
        cVar12 = extraout_AH;
        do {
          for (; iVar8 != 0; iVar8 = iVar8 + -1) {
            pbVar4 = pbVar18;
            pbVar18 = pbVar18 + (uint)bVar24 * -2 + 1;
            *pbVar4 = extraout_AL;
          }
          bVar23 = CARRY2((uint)pbVar18,extraout_DX);
          pbVar18 = pbVar18 + extraout_DX;
          cVar12 = cVar12 + -1;
          iVar8 = iVar16;
        } while (cVar12 != '\0');
        return (byte)-bVar23 + 0x6108 + (uint)bVar23;
      }
      goto LAB_1000_5f7e;
    }
    uVar25 = func_0x000163ff();
    uVar15 = (undefined2)((ulong)uVar25 >> 0x10);
    uVar7 = (int)uVar25 + 1;
    pbVar18[2] = (char)pbVar18[2] >> 0xb;
    bVar6 = (byte)uVar7;
    if (bVar6 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar6 - 0x10);
      uVar25 = CONCAT22(uVar15,uVar7);
      if (bVar6 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar6 - 0x10;
      pbVar18 = pbVar21 + 1;
      pbVar21 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar15,uVar7);
  goto LAB_1000_625d;
}


