/* 1000:60e9 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_60e9(undefined2 param_1,int param_2,undefined2 *param_3)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte extraout_AL;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar12;
  int iVar11;
  uint in_CX;
  byte bVar13;
  byte bVar14;
  byte bVar17;
  undefined2 uVar16;
  int in_DX;
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
  bool bVar23;
  bool bVar24;
  undefined4 uVar25;
  byte *in_stack_00000000;
  byte *in_stack_00000010;
  byte *in_stack_00000012;
  undefined2 uVar15;
  
  bVar13 = (byte)(in_CX >> 8) ^ *(byte *)(unaff_BP + unaff_SI + 0x20);
  iVar11 = in_DX + *(int *)(unaff_BP + -0x75);
  iVar7 = (*(uint *)(unaff_SI + 1) & 0xff) * (in_CX & 0xff) + *(int *)(in_BX + 2);
  pbVar18 = (byte *)(in_BX + 4);
  *(int *)pbVar18 = iVar7;
  bVar17 = (byte)((uint)iVar11 >> 8);
  bVar14 = (byte)iVar11 & in_stack_00000000[unaff_BP + 0x50];
  uVar15 = CONCAT11(bVar17,bVar14);
  cVar12 = bVar13 + pbVar18[(int)in_stack_00000000];
  iVar11 = CONCAT11(cVar12,(char)in_CX) + -1;
  uVar16 = uVar15;
  pbVar21 = unaff_DI;
  if (iVar11 == 0 || cVar12 == '\0') {
    unaff_DI[unaff_BP] =
         unaff_DI[unaff_BP] + (char)((uint)iVar7 >> 8) +
         CARRY1(bVar13,pbVar18[(int)in_stack_00000000]);
    in_stack_00000000[unaff_BP + -0x10] = in_stack_00000000[unaff_BP + -0x10] | bVar17;
    pbVar21 = unaff_DI + 1;
    *unaff_DI = (char)iVar7 - 0x18;
    cVar12 = bVar14 + in_stack_00000000[unaff_BP];
    uVar16 = CONCAT11(bVar17,cVar12);
    if (!CARRY1(bVar14,in_stack_00000000[unaff_BP])) {
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
      bVar13 = *pbVar4;
      *pbVar4 = *pbVar4 + 0x58;
      uVar6 = CONCAT11(0xa8,-(bVar13 < 0xa8) - *in_stack_00000000);
      *(undefined2 *)(unaff_BP + -2) = 0;
      *(undefined2 *)(unaff_BP + -4) = 0x50;
      iVar11 = 0;
      pbVar18 = pbVar21;
      uVar15 = unaff_SS;
      param_2 = unaff_BP;
      in_stack_00000010 = pbVar21;
      in_stack_00000012 = in_stack_00000000;
      goto LAB_1000_5f79;
    }
    pbVar18[(int)(in_stack_00000000 + 1)] = pbVar18[(int)(in_stack_00000000 + 1)] + 1;
    in_stack_00000000 = in_stack_00000000 + 2;
  }
  uVar6 = in(uVar16);
  if (iVar11 == 0) {
    iVar11 = 0x50;
  }
  *(int *)(unaff_BP + -4) = iVar11;
  uVar6 = uVar6 & 0xff00;
  iVar11 = 0xa0;
  pbVar18 = in_stack_00000000;
LAB_1000_5f79:
  do {
    uVar25 = CONCAT22(uVar16,uVar6);
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pbVar4 = pbVar18;
    pbVar18 = pbVar18 + 1;
    uVar25 = CONCAT22(uVar16,uVar6);
  } while ((byte)uVar6 != *pbVar4);
LAB_1000_5f7e:
  uVar16 = (undefined2)((ulong)uVar25 >> 0x10);
  pbVar4 = in_stack_00000000;
  in_stack_00000000 = in_stack_00000000 + 1;
  bVar13 = *pbVar4;
  uVar6 = CONCAT11((char)((ulong)uVar25 >> 8),bVar13);
  uVar25 = CONCAT22(uVar16,uVar6);
  if (0x1f < bVar13) {
    if (bVar13 == 0x20) {
LAB_1000_5fc7:
      pbVar21 = pbVar21 + 1;
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar13 = (byte)uVar6, bVar13 == 0x40) {
      pbVar4 = in_stack_00000000;
      in_stack_00000000 = in_stack_00000000 + 1;
      uVar6 = (uint)*pbVar4;
      iVar11 = 0x1c;
      pbVar22 = (byte *)0x2847;
      bVar24 = true;
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pbVar3 = pbVar22;
        pbVar22 = pbVar22 + 1;
        bVar24 = *pbVar4 == *pbVar3;
      } while (!bVar24);
      if (bVar24) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar11 = (*(code *)*(undefined2 *)((int)(pbVar22 + -0x2848) * 2 + 0x78bb))();
        return iVar11;
      }
    }
    if ((0x7f < bVar13) && ((bVar13 < 0xa0 || (0xdf < bVar13)))) {
      pbVar4 = in_stack_00000000;
      in_stack_00000000 = in_stack_00000000 + 1;
      uVar25 = CONCAT22(uVar16,CONCAT11(bVar13,*pbVar4));
      if (CONCAT11(bVar13,*pbVar4) != 0x4081) {
        uVar6 = FUN_1000_8401();
        if ((0x2920 < uVar6) && (uVar6 < 0x2b7f)) {
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
      uVar6 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar6 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar11 = 0x10;
        puVar20 = (uint *)(param_2 + -2);
        pbVar18 = pbVar21;
        do {
          pbVar22 = pbVar18;
          puVar19 = puVar20;
          puVar20 = puVar19 + 1;
          uVar6 = *puVar19;
          *(uint *)(pbVar22 + -0x50) = uVar6;
          *(uint *)(pbVar22 + 0x50) = uVar6;
          uVar8 = CONCAT11((char)uVar6,(char)(uVar6 >> 8));
          uVar5 = uVar8 * 2;
          bVar13 = ((uVar6 & 0x100) != 0) << 7;
          iVar7 = CONCAT11(bVar13,CARRY2(uVar8,uVar8));
          uVar6 = uVar8 | uVar5 | uVar8 >> 1;
          bVar14 = (byte)(uVar6 >> 8);
          iVar9 = CONCAT11((char)uVar6,bVar14);
          pbVar22[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar22 = iVar9;
          pbVar22[1] = bVar13;
          iVar11 = iVar11 + -1;
          pbVar18 = pbVar22 + 0x50;
        } while (iVar11 != 0);
        *(byte *)puVar20 = (byte)*puVar20 ^ bVar14;
        pbVar4 = pbVar22 + 0x4f;
        *pbVar4 = *pbVar4 + bVar14;
        pbVar22[0x4f] = bVar14;
        pbVar18 = pbVar22 + 0x51;
        uVar10 = iVar9 + 1;
        bVar13 = (byte)uVar10;
        *(byte *)(puVar20 + uVar8) = (byte)puVar20[uVar8] + bVar13 + (((uint)pbVar21 & 1) != 0);
        uVar6 = (param_2 + -2) * 0x100;
        bVar24 = (uVar6 & 0x400) != 0;
        if ((uVar6 & 0x800) == 0) {
          *(byte *)(puVar19 + 0x1a4) = (byte)puVar19[0x1a4] + (char)(uVar10 >> 8);
          pbVar22[0x50] = (byte)*puVar20;
          puVar20 = puVar20 + !bVar24;
          pbVar18 = pbVar18 + uVar10 + (uint)bVar24 * -2;
          pbVar4 = (byte *)((int)puVar20 + iVar7 + 0x10);
          *pbVar4 = *pbVar4 | (byte)(uVar8 >> 1);
          *(byte *)(iVar7 + (int)puVar20) = *(byte *)(iVar7 + (int)puVar20) << 1;
          LOCK();
          pbVar4 = (byte *)((int)puVar20 + iVar7 + 0x30ac);
          *pbVar4 = *pbVar4 ^ bVar13;
          UNLOCK();
        }
        iVar9 = *(int *)0x32a8;
        FUN_1000_5aba(bVar13,(char)puVar20);
        pbVar18[uVar5 + 0xbad9] = pbVar18[uVar5 + 0xbad9] - (byte)iVar11;
        pbVar18[uVar5] = pbVar18[uVar5] + (char)((uint)iVar11 >> 8);
        piVar2 = (int *)(iVar7 + iVar9 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar11 & 0x1f);
        iVar11 = iVar7;
        cVar12 = extraout_AH;
        do {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pbVar4 = pbVar18;
            pbVar18 = pbVar18 + (uint)bVar24 * -2 + 1;
            *pbVar4 = extraout_AL;
          }
          bVar23 = CARRY2((uint)pbVar18,extraout_DX);
          pbVar18 = pbVar18 + extraout_DX;
          cVar12 = cVar12 + -1;
          iVar11 = iVar7;
        } while (cVar12 != '\0');
        return (byte)-bVar23 + 0x6108 + (uint)bVar23;
      }
      goto LAB_1000_5f7e;
    }
    uVar25 = func_0x000163ff();
    uVar16 = (undefined2)((ulong)uVar25 >> 0x10);
    uVar6 = (int)uVar25 + 1;
    pbVar18[2] = (char)pbVar18[2] >> 0xb;
    bVar13 = (byte)uVar6;
    if (bVar13 != 0) {
      uVar6 = CONCAT11((char)(uVar6 >> 8),bVar13 - 0x10);
      uVar25 = CONCAT22(uVar16,uVar6);
      if (bVar13 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar13 - 0x10;
      pbVar18 = pbVar21 + 1;
      pbVar21 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar16,uVar6);
  goto LAB_1000_625d;
}


