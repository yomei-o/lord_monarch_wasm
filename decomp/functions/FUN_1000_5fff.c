/* 1000:5fff */

int FUN_1000_5fff(int param_1,undefined2 param_2)

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
  uint uVar9;
  uint in_AX;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  char extraout_AH;
  char cVar14;
  undefined2 in_DX;
  uint extraout_DX;
  int in_BX;
  int iVar15;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar16;
  uint *puVar17;
  byte *unaff_DI;
  int *piVar18;
  undefined1 *puVar19;
  undefined2 unaff_ES;
  int *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar20;
  undefined1 in_ZF;
  bool bVar21;
  undefined4 uVar22;
  int *in_stack_00000000;
  
  do {
    if ((bool)in_ZF) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar10 = (*(code *)*(undefined2 *)((int)(unaff_DI + -0x2848) * 2 + 0x78bb))();
      return iVar10;
    }
    while (bVar8 = (byte)in_AX, bVar8 != 0x40) {
      if ((bVar8 < 0x80) || ((0x9f < bVar8 && (bVar8 < 0xe0)))) {
        uVar22 = func_0x000163ff();
        in_DX = (undefined2)((ulong)uVar22 >> 0x10);
        in_AX = (int)uVar22 + 1;
        *(char *)(in_BX + 2) = *(char *)(in_BX + 2) >> 0xb;
        bVar8 = (byte)in_AX;
        if (bVar8 != 0) {
          in_AX = CONCAT11((char)(in_AX >> 8),bVar8 - 0x10);
          uVar22 = CONCAT22(in_DX,in_AX);
          if (0xf < bVar8) {
            *(char *)0x32a9 = bVar8 - 0x10;
            in_BX = (int)in_stack_00000000 + 1;
            in_stack_00000000 = unaff_CS;
            goto LAB_1000_5f7e;
          }
        }
FUN_1000_6259:
        out(in_DX,in_AX);
LAB_1000_625d:
        iVar10 = 0x10;
        puVar17 = (uint *)(param_1 + -2);
        piVar7 = in_stack_00000000;
        do {
          piVar18 = piVar7;
          puVar16 = puVar17;
          puVar17 = puVar16 + 1;
          uVar9 = *puVar16;
          piVar18[-0x28] = uVar9;
          piVar18[0x28] = uVar9;
          uVar11 = CONCAT11((char)uVar9,(char)(uVar9 >> 8));
          uVar6 = uVar11 * 2;
          cVar14 = ((uVar9 & 0x100) != 0) << 7;
          iVar15 = CONCAT11(cVar14,CARRY2(uVar11,uVar11));
          uVar9 = uVar11 | uVar6 | uVar11 >> 1;
          bVar8 = (byte)(uVar9 >> 8);
          iVar12 = CONCAT11((char)uVar9,bVar8);
          *(bool *)((int)piVar18 + -1) = CARRY2(uVar11,uVar11);
          *piVar18 = iVar12;
          *(char *)((int)piVar18 + 1) = cVar14;
          iVar10 = iVar10 + -1;
          piVar7 = piVar18 + 0x28;
        } while (iVar10 != 0);
        *(byte *)puVar17 = (byte)*puVar17 ^ bVar8;
        pbVar3 = (byte *)((int)piVar18 + 0x4f);
        *pbVar3 = *pbVar3 + bVar8;
        *(byte *)((int)piVar18 + 0x4f) = bVar8;
        puVar19 = (undefined1 *)((int)piVar18 + 0x51);
        uVar13 = iVar12 + 1;
        *(byte *)(puVar17 + uVar11) =
             (byte)puVar17[uVar11] + (byte)uVar13 + (((uint)in_stack_00000000 & 1) != 0);
        uVar9 = (param_1 + -2) * 0x100;
        bVar21 = (uVar9 & 0x400) != 0;
        if ((uVar9 & 0x800) == 0) {
          *(byte *)(puVar16 + 0x1a4) = (byte)puVar16[0x1a4] + (char)(uVar13 >> 8);
          *(byte *)(piVar18 + 0x28) = (byte)*puVar17;
          puVar17 = puVar17 + !bVar21;
          puVar19 = puVar19 + uVar13 + (uint)bVar21 * -2;
          pbVar3 = (byte *)((int)puVar17 + iVar15 + 0x10);
          *pbVar3 = *pbVar3 | (byte)(uVar11 >> 1);
          *(byte *)(iVar15 + (int)puVar17) = *(byte *)(iVar15 + (int)puVar17) << 1;
          LOCK();
          pbVar3 = (byte *)((int)puVar17 + iVar15 + 0x30ac);
          *pbVar3 = *pbVar3 ^ (byte)uVar13;
          UNLOCK();
        }
        iVar12 = *(int *)0x32a8;
        FUN_1000_5aba(uVar13,(char)puVar17);
        puVar19[uVar6 + 0xbad9] = puVar19[uVar6 + 0xbad9] - (byte)iVar10;
        puVar19[uVar6] = puVar19[uVar6] + (char)((uint)iVar10 >> 8);
        piVar2 = (int *)(iVar15 + iVar12 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar10 & 0x1f);
        iVar10 = iVar15;
        cVar14 = extraout_AH;
        do {
          for (; iVar10 != 0; iVar10 = iVar10 + -1) {
            puVar5 = puVar19;
            puVar19 = puVar19 + (uint)bVar21 * -2 + 1;
            *puVar5 = extraout_AL;
          }
          bVar20 = CARRY2((uint)puVar19,extraout_DX);
          puVar19 = puVar19 + extraout_DX;
          cVar14 = cVar14 + -1;
          iVar10 = iVar15;
        } while (cVar14 != '\0');
        return (byte)-bVar20 + 0x6108 + (uint)bVar20;
      }
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar22 = CONCAT22(in_DX,CONCAT11(bVar8,*pbVar3));
      if (CONCAT11(bVar8,*pbVar3) != 0x4081) {
        uVar9 = FUN_1000_8401();
        if ((0x2920 < uVar9) && (uVar9 < 0x2b7f)) {
          param_1 = 0x5fc4;
          FUN_1000_5c7d();
          param_2 = 0x5fc7;
          uVar22 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        param_1 = 0x5fad;
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        param_2 = 0x5fb0;
        uVar22 = func_0x00016305();
      }
      in_stack_00000000 = in_stack_00000000 + 1;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar9 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar9 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
        goto LAB_1000_625d;
      }
LAB_1000_5f7e:
      while( true ) {
        in_DX = (undefined2)((ulong)uVar22 >> 0x10);
        pbVar3 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        bVar8 = *pbVar3;
        in_AX = CONCAT11((char)((ulong)uVar22 >> 8),bVar8);
        uVar22 = CONCAT22(in_DX,in_AX);
        if (bVar8 < 0x20) goto FUN_1000_6259;
        if (bVar8 != 0x20) break;
LAB_1000_5fc7:
        in_stack_00000000 = (int *)((int)in_stack_00000000 + 1);
        piVar2 = (int *)(unaff_BP + -4);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) goto LAB_1000_625d;
      }
    }
    pbVar3 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    in_AX = (uint)*pbVar3;
    iVar10 = 0x1c;
    unaff_DI = (byte *)0x2847;
    in_ZF = true;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      pbVar4 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      in_ZF = *pbVar3 == *pbVar4;
    } while (!(bool)in_ZF);
  } while( true );
}


