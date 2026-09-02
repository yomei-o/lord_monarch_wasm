/* 1000:5f7d */

int FUN_1000_5f7d(undefined2 param_1,int param_2,undefined2 param_3)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  uint uVar6;
  int *piVar7;
  byte bVar8;
  undefined1 extraout_AL;
  undefined2 in_AX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  char extraout_AH;
  char cVar13;
  int iVar14;
  undefined2 in_DX;
  undefined2 uVar15;
  uint extraout_DX;
  int in_BX;
  int iVar16;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar17;
  uint *puVar18;
  byte *pbVar19;
  int *piVar20;
  undefined1 *puVar21;
  undefined2 unaff_ES;
  int *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar22;
  bool bVar23;
  undefined4 uVar24;
  int *in_stack_00000000;
  
  uVar24 = CONCAT22(in_DX,in_AX);
LAB_1000_5f7e:
  uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
  pbVar3 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  bVar8 = *pbVar3;
  uVar9 = CONCAT11((char)((ulong)uVar24 >> 8),bVar8);
  uVar24 = CONCAT22(uVar15,uVar9);
  if (0x1f < bVar8) {
    if (bVar8 == 0x20) {
LAB_1000_5fc7:
      in_stack_00000000 = (int *)((int)in_stack_00000000 + 1);
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar8 = (byte)uVar9, bVar8 == 0x40) {
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar9 = (uint)*pbVar3;
      iVar14 = 0x1c;
      pbVar19 = (byte *)0x2847;
      bVar23 = true;
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pbVar4 = pbVar19;
        pbVar19 = pbVar19 + 1;
        bVar23 = *pbVar3 == *pbVar4;
      } while (!bVar23);
      if (bVar23) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar14 = (*(code *)*(undefined2 *)((int)(pbVar19 + -0x2848) * 2 + 0x78bb))();
        return iVar14;
      }
    }
    if ((0x7f < bVar8) && ((bVar8 < 0xa0 || (0xdf < bVar8)))) {
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar24 = CONCAT22(uVar15,CONCAT11(bVar8,*pbVar3));
      if (CONCAT11(bVar8,*pbVar3) != 0x4081) {
        uVar9 = FUN_1000_8401();
        if ((0x2920 < uVar9) && (uVar9 < 0x2b7f)) {
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
      in_stack_00000000 = in_stack_00000000 + 1;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar9 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar9 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar14 = 0x10;
        puVar18 = (uint *)(param_2 + -2);
        piVar7 = in_stack_00000000;
        do {
          piVar20 = piVar7;
          puVar17 = puVar18;
          puVar18 = puVar17 + 1;
          uVar9 = *puVar17;
          piVar20[-0x28] = uVar9;
          piVar20[0x28] = uVar9;
          uVar10 = CONCAT11((char)uVar9,(char)(uVar9 >> 8));
          uVar6 = uVar10 * 2;
          cVar13 = ((uVar9 & 0x100) != 0) << 7;
          iVar16 = CONCAT11(cVar13,CARRY2(uVar10,uVar10));
          uVar9 = uVar10 | uVar6 | uVar10 >> 1;
          bVar8 = (byte)(uVar9 >> 8);
          iVar11 = CONCAT11((char)uVar9,bVar8);
          *(bool *)((int)piVar20 + -1) = CARRY2(uVar10,uVar10);
          *piVar20 = iVar11;
          *(char *)((int)piVar20 + 1) = cVar13;
          iVar14 = iVar14 + -1;
          piVar7 = piVar20 + 0x28;
        } while (iVar14 != 0);
        *(byte *)puVar18 = (byte)*puVar18 ^ bVar8;
        pbVar3 = (byte *)((int)piVar20 + 0x4f);
        *pbVar3 = *pbVar3 + bVar8;
        *(byte *)((int)piVar20 + 0x4f) = bVar8;
        puVar21 = (undefined1 *)((int)piVar20 + 0x51);
        uVar12 = iVar11 + 1;
        *(byte *)(puVar18 + uVar10) =
             (byte)puVar18[uVar10] + (byte)uVar12 + (((uint)in_stack_00000000 & 1) != 0);
        uVar9 = (param_2 + -2) * 0x100;
        bVar23 = (uVar9 & 0x400) != 0;
        if ((uVar9 & 0x800) == 0) {
          *(byte *)(puVar17 + 0x1a4) = (byte)puVar17[0x1a4] + (char)(uVar12 >> 8);
          *(byte *)(piVar20 + 0x28) = (byte)*puVar18;
          puVar18 = puVar18 + !bVar23;
          puVar21 = puVar21 + uVar12 + (uint)bVar23 * -2;
          pbVar3 = (byte *)((int)puVar18 + iVar16 + 0x10);
          *pbVar3 = *pbVar3 | (byte)(uVar10 >> 1);
          *(byte *)(iVar16 + (int)puVar18) = *(byte *)(iVar16 + (int)puVar18) << 1;
          LOCK();
          pbVar3 = (byte *)((int)puVar18 + iVar16 + 0x30ac);
          *pbVar3 = *pbVar3 ^ (byte)uVar12;
          UNLOCK();
        }
        iVar11 = *(int *)0x32a8;
        FUN_1000_5aba(uVar12,(char)puVar18);
        puVar21[uVar6 + 0xbad9] = puVar21[uVar6 + 0xbad9] - (byte)iVar14;
        puVar21[uVar6] = puVar21[uVar6] + (char)((uint)iVar14 >> 8);
        piVar2 = (int *)(iVar16 + iVar11 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar14 & 0x1f);
        iVar14 = iVar16;
        cVar13 = extraout_AH;
        do {
          for (; iVar14 != 0; iVar14 = iVar14 + -1) {
            puVar5 = puVar21;
            puVar21 = puVar21 + (uint)bVar23 * -2 + 1;
            *puVar5 = extraout_AL;
          }
          bVar22 = CARRY2((uint)puVar21,extraout_DX);
          puVar21 = puVar21 + extraout_DX;
          cVar13 = cVar13 + -1;
          iVar14 = iVar16;
        } while (cVar13 != '\0');
        return (byte)-bVar22 + 0x6108 + (uint)bVar22;
      }
      goto LAB_1000_5f7e;
    }
    uVar24 = func_0x000163ff();
    uVar15 = (undefined2)((ulong)uVar24 >> 0x10);
    uVar9 = (int)uVar24 + 1;
    *(char *)(in_BX + 2) = *(char *)(in_BX + 2) >> 0xb;
    bVar8 = (byte)uVar9;
    if (bVar8 != 0) {
      uVar9 = CONCAT11((char)(uVar9 >> 8),bVar8 - 0x10);
      uVar24 = CONCAT22(uVar15,uVar9);
      if (bVar8 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar8 - 0x10;
      in_BX = (int)in_stack_00000000 + 1;
      in_stack_00000000 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar15,uVar9);
  goto LAB_1000_625d;
}


