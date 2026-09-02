/* 1000:5f56 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_5f56(undefined2 param_1,int param_2,undefined2 param_3)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  uint uVar7;
  int *piVar8;
  byte bVar9;
  undefined1 extraout_AL;
  undefined2 in_AX;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  char extraout_AH;
  char cVar14;
  int in_CX;
  int iVar15;
  undefined2 in_DX;
  undefined2 uVar16;
  uint extraout_DX;
  int iVar17;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar18;
  uint *puVar19;
  char *unaff_DI;
  byte *pbVar20;
  int *piVar21;
  undefined1 *puVar22;
  undefined2 unaff_ES;
  int *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar23;
  bool bVar24;
  undefined4 uVar25;
  int *in_stack_00000000;
  
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)(unaff_BP + -4) = 0x50;
  do {
    uVar25 = CONCAT22(in_DX,in_AX);
    if (in_CX == 0) break;
    in_CX = in_CX + -1;
    pcVar4 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    uVar25 = CONCAT22(in_DX,in_AX);
  } while ((char)in_AX != *pcVar4);
LAB_1000_5f7e:
  uVar16 = (undefined2)((ulong)uVar25 >> 0x10);
  pbVar3 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  bVar9 = *pbVar3;
  uVar10 = CONCAT11((char)((ulong)uVar25 >> 8),bVar9);
  uVar25 = CONCAT22(uVar16,uVar10);
  if (0x1f < bVar9) {
    if (bVar9 == 0x20) {
LAB_1000_5fc7:
      in_stack_00000000 = (int *)((int)in_stack_00000000 + 1);
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar9 = (byte)uVar10, bVar9 == 0x40) {
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar10 = (uint)*pbVar3;
      iVar15 = 0x1c;
      pbVar20 = (byte *)0x2847;
      bVar24 = true;
      do {
        if (iVar15 == 0) break;
        iVar15 = iVar15 + -1;
        pbVar5 = pbVar20;
        pbVar20 = pbVar20 + 1;
        bVar24 = *pbVar3 == *pbVar5;
      } while (!bVar24);
      if (bVar24) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar15 = (*(code *)*(undefined2 *)((int)(pbVar20 + -0x2848) * 2 + 0x78bb))();
        return iVar15;
      }
    }
    if ((0x7f < bVar9) && ((bVar9 < 0xa0 || (0xdf < bVar9)))) {
      pbVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar25 = CONCAT22(uVar16,CONCAT11(bVar9,*pbVar3));
      if (CONCAT11(bVar9,*pbVar3) != 0x4081) {
        uVar10 = FUN_1000_8401();
        if ((0x2920 < uVar10) && (uVar10 < 0x2b7f)) {
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
      in_stack_00000000 = in_stack_00000000 + 1;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar10 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar10 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar15 = 0x10;
        puVar19 = (uint *)(param_2 + -2);
        piVar8 = in_stack_00000000;
        do {
          piVar21 = piVar8;
          puVar18 = puVar19;
          puVar19 = puVar18 + 1;
          uVar10 = *puVar18;
          piVar21[-0x28] = uVar10;
          piVar21[0x28] = uVar10;
          uVar11 = CONCAT11((char)uVar10,(char)(uVar10 >> 8));
          uVar7 = uVar11 * 2;
          cVar14 = ((uVar10 & 0x100) != 0) << 7;
          iVar17 = CONCAT11(cVar14,CARRY2(uVar11,uVar11));
          uVar10 = uVar11 | uVar7 | uVar11 >> 1;
          bVar9 = (byte)(uVar10 >> 8);
          iVar12 = CONCAT11((char)uVar10,bVar9);
          *(bool *)((int)piVar21 + -1) = CARRY2(uVar11,uVar11);
          *piVar21 = iVar12;
          *(char *)((int)piVar21 + 1) = cVar14;
          iVar15 = iVar15 + -1;
          piVar8 = piVar21 + 0x28;
        } while (iVar15 != 0);
        *(byte *)puVar19 = (byte)*puVar19 ^ bVar9;
        pbVar3 = (byte *)((int)piVar21 + 0x4f);
        *pbVar3 = *pbVar3 + bVar9;
        *(byte *)((int)piVar21 + 0x4f) = bVar9;
        puVar22 = (undefined1 *)((int)piVar21 + 0x51);
        uVar13 = iVar12 + 1;
        *(byte *)(puVar19 + uVar11) =
             (byte)puVar19[uVar11] + (byte)uVar13 + (((uint)in_stack_00000000 & 1) != 0);
        uVar10 = (param_2 + -2) * 0x100;
        bVar24 = (uVar10 & 0x400) != 0;
        if ((uVar10 & 0x800) == 0) {
          *(byte *)(puVar18 + 0x1a4) = (byte)puVar18[0x1a4] + (char)(uVar13 >> 8);
          *(byte *)(piVar21 + 0x28) = (byte)*puVar19;
          puVar19 = puVar19 + !bVar24;
          puVar22 = puVar22 + uVar13 + (uint)bVar24 * -2;
          pbVar3 = (byte *)((int)puVar19 + iVar17 + 0x10);
          *pbVar3 = *pbVar3 | (byte)(uVar11 >> 1);
          *(byte *)(iVar17 + (int)puVar19) = *(byte *)(iVar17 + (int)puVar19) << 1;
          LOCK();
          pbVar3 = (byte *)((int)puVar19 + iVar17 + 0x30ac);
          *pbVar3 = *pbVar3 ^ (byte)uVar13;
          UNLOCK();
        }
        iVar12 = *(int *)0x32a8;
        FUN_1000_5aba(uVar13,(char)puVar19);
        puVar22[uVar7 + 0xbad9] = puVar22[uVar7 + 0xbad9] - (byte)iVar15;
        puVar22[uVar7] = puVar22[uVar7] + (char)((uint)iVar15 >> 8);
        piVar2 = (int *)(iVar17 + iVar12 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar15 & 0x1f);
        iVar15 = iVar17;
        cVar14 = extraout_AH;
        do {
          for (; iVar15 != 0; iVar15 = iVar15 + -1) {
            puVar6 = puVar22;
            puVar22 = puVar22 + (uint)bVar24 * -2 + 1;
            *puVar6 = extraout_AL;
          }
          bVar23 = CARRY2((uint)puVar22,extraout_DX);
          puVar22 = puVar22 + extraout_DX;
          cVar14 = cVar14 + -1;
          iVar15 = iVar17;
        } while (cVar14 != '\0');
        return (byte)-bVar23 + 0x6108 + (uint)bVar23;
      }
      goto LAB_1000_5f7e;
    }
    uVar25 = func_0x000163ff();
    uVar16 = (undefined2)((ulong)uVar25 >> 0x10);
    uVar10 = (int)uVar25 + 1;
    unaff_DI[2] = unaff_DI[2] >> 0xb;
    bVar9 = (byte)uVar10;
    if (bVar9 != 0) {
      uVar10 = CONCAT11((char)(uVar10 >> 8),bVar9 - 0x10);
      uVar25 = CONCAT22(uVar16,uVar10);
      if (bVar9 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar9 - 0x10;
      unaff_DI = (char *)((int)in_stack_00000000 + 1);
      in_stack_00000000 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(uVar16,uVar10);
  goto LAB_1000_625d;
}


