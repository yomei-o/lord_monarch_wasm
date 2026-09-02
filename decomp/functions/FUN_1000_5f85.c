/* 1000:5f85 */

int FUN_1000_5f85(undefined2 param_1)

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
  uint in_AX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  char extraout_AH;
  char cVar13;
  int iVar14;
  undefined2 in_DX;
  uint extraout_DX;
  int in_BX;
  int iVar15;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar16;
  uint *puVar17;
  int *unaff_DI;
  byte *pbVar18;
  int *piVar19;
  undefined1 *puVar20;
  undefined2 unaff_ES;
  int *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar21;
  bool bVar22;
  undefined4 uVar23;
  int in_stack_00000000;
  
  do {
    while (bVar8 = (byte)in_AX, bVar8 == 0x40) {
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      in_AX = (uint)*pbVar3;
      iVar14 = 0x1c;
      pbVar18 = (byte *)0x2847;
      bVar22 = true;
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pbVar4 = pbVar18;
        pbVar18 = pbVar18 + 1;
        bVar22 = *pbVar3 == *pbVar4;
      } while (!bVar22);
      if (bVar22) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar14 = (*(code *)*(undefined2 *)((int)(pbVar18 + -0x2848) * 2 + 0x78bb))();
        return iVar14;
      }
    }
    if ((bVar8 < 0x80) || ((0x9f < bVar8 && (bVar8 < 0xe0)))) {
      uVar23 = func_0x000163ff();
      in_DX = (undefined2)((ulong)uVar23 >> 0x10);
      in_AX = (int)uVar23 + 1;
      *(char *)(in_BX + 2) = *(char *)(in_BX + 2) >> 0xb;
      bVar8 = (byte)in_AX;
      if (bVar8 != 0) {
        in_AX = CONCAT11((char)(in_AX >> 8),bVar8 - 0x10);
        uVar23 = CONCAT22(in_DX,in_AX);
        if (0xf < bVar8) {
          *(char *)0x32a9 = bVar8 - 0x10;
          in_BX = (int)unaff_DI + 1;
          unaff_DI = unaff_CS;
          goto LAB_1000_5f7e;
        }
      }
FUN_1000_6259:
      out(in_DX,in_AX);
LAB_1000_625d:
      iVar14 = 0x10;
      puVar17 = (uint *)(in_stack_00000000 + -2);
      piVar7 = unaff_DI;
      do {
        piVar19 = piVar7;
        puVar16 = puVar17;
        puVar17 = puVar16 + 1;
        uVar9 = *puVar16;
        piVar19[-0x28] = uVar9;
        piVar19[0x28] = uVar9;
        uVar10 = CONCAT11((char)uVar9,(char)(uVar9 >> 8));
        uVar6 = uVar10 * 2;
        cVar13 = ((uVar9 & 0x100) != 0) << 7;
        iVar15 = CONCAT11(cVar13,CARRY2(uVar10,uVar10));
        uVar9 = uVar10 | uVar6 | uVar10 >> 1;
        bVar8 = (byte)(uVar9 >> 8);
        iVar11 = CONCAT11((char)uVar9,bVar8);
        *(bool *)((int)piVar19 + -1) = CARRY2(uVar10,uVar10);
        *piVar19 = iVar11;
        *(char *)((int)piVar19 + 1) = cVar13;
        iVar14 = iVar14 + -1;
        piVar7 = piVar19 + 0x28;
      } while (iVar14 != 0);
      *(byte *)puVar17 = (byte)*puVar17 ^ bVar8;
      pbVar3 = (byte *)((int)piVar19 + 0x4f);
      *pbVar3 = *pbVar3 + bVar8;
      *(byte *)((int)piVar19 + 0x4f) = bVar8;
      puVar20 = (undefined1 *)((int)piVar19 + 0x51);
      uVar12 = iVar11 + 1;
      *(byte *)(puVar17 + uVar10) =
           (byte)puVar17[uVar10] + (byte)uVar12 + (((uint)unaff_DI & 1) != 0);
      uVar9 = (in_stack_00000000 + -2) * 0x100;
      bVar22 = (uVar9 & 0x400) != 0;
      if ((uVar9 & 0x800) == 0) {
        *(byte *)(puVar16 + 0x1a4) = (byte)puVar16[0x1a4] + (char)(uVar12 >> 8);
        *(byte *)(piVar19 + 0x28) = (byte)*puVar17;
        puVar17 = puVar17 + !bVar22;
        puVar20 = puVar20 + uVar12 + (uint)bVar22 * -2;
        pbVar3 = (byte *)((int)puVar17 + iVar15 + 0x10);
        *pbVar3 = *pbVar3 | (byte)(uVar10 >> 1);
        *(byte *)(iVar15 + (int)puVar17) = *(byte *)(iVar15 + (int)puVar17) << 1;
        LOCK();
        pbVar3 = (byte *)((int)puVar17 + iVar15 + 0x30ac);
        *pbVar3 = *pbVar3 ^ (byte)uVar12;
        UNLOCK();
      }
      iVar11 = *(int *)0x32a8;
      FUN_1000_5aba(uVar12,(char)puVar17);
      puVar20[uVar6 + 0xbad9] = puVar20[uVar6 + 0xbad9] - (byte)iVar14;
      puVar20[uVar6] = puVar20[uVar6] + (char)((uint)iVar14 >> 8);
      piVar2 = (int *)(iVar15 + iVar11 + 0x10ff);
      *piVar2 = *piVar2 >> ((byte)iVar14 & 0x1f);
      iVar14 = iVar15;
      cVar13 = extraout_AH;
      do {
        for (; iVar14 != 0; iVar14 = iVar14 + -1) {
          puVar5 = puVar20;
          puVar20 = puVar20 + (uint)bVar22 * -2 + 1;
          *puVar5 = extraout_AL;
        }
        bVar21 = CARRY2((uint)puVar20,extraout_DX);
        puVar20 = puVar20 + extraout_DX;
        cVar13 = cVar13 + -1;
        iVar14 = iVar15;
      } while (cVar13 != '\0');
      return (byte)-bVar21 + 0x6108 + (uint)bVar21;
    }
    pbVar3 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    uVar23 = CONCAT22(in_DX,CONCAT11(bVar8,*pbVar3));
    if (CONCAT11(bVar8,*pbVar3) != 0x4081) {
      uVar9 = FUN_1000_8401();
      if ((0x2920 < uVar9) && (uVar9 < 0x2b7f)) {
        in_stack_00000000 = 0x5fc4;
        FUN_1000_5c7d();
        param_1 = 0x5fc7;
        uVar23 = func_0x000163a2();
        goto LAB_1000_5fc7;
      }
      in_stack_00000000 = 0x5fad;
      FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
      param_1 = 0x5fb0;
      uVar23 = func_0x00016305();
    }
    unaff_DI = unaff_DI + 1;
    puVar1 = (uint *)(unaff_BP + -4);
    uVar9 = *puVar1;
    *puVar1 = *puVar1 - 2;
    if (uVar9 < 2) {
      *(undefined2 *)(unaff_BP + -4) = 0;
      goto LAB_1000_625d;
    }
LAB_1000_5f7e:
    while( true ) {
      in_DX = (undefined2)((ulong)uVar23 >> 0x10);
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      bVar8 = *pbVar3;
      in_AX = CONCAT11((char)((ulong)uVar23 >> 8),bVar8);
      uVar23 = CONCAT22(in_DX,in_AX);
      if (bVar8 < 0x20) goto FUN_1000_6259;
      if (bVar8 != 0x20) break;
LAB_1000_5fc7:
      unaff_DI = (int *)((int)unaff_DI + 1);
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
    }
  } while( true );
}


