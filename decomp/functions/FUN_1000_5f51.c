/* 1000:5f51 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_5f51(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  int *piVar4;
  byte *pbVar5;
  char *pcVar6;
  char cVar7;
  byte bVar8;
  char extraout_AL;
  undefined2 in_AX;
  byte bVar13;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  char extraout_AH;
  int in_CX;
  int iVar14;
  undefined2 in_DX;
  uint extraout_DX;
  byte *in_BX;
  int *piVar15;
  int iVar16;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar17;
  uint *puVar18;
  int *unaff_DI;
  byte *pbVar19;
  int *piVar20;
  char *pcVar21;
  undefined2 unaff_ES;
  int *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar22;
  bool bVar23;
  undefined4 uVar24;
  uint auStackY_50 [26];
  int iVar25;
  char cStack_1;
  
  pbVar2 = in_BX;
  bVar8 = *pbVar2;
  bVar13 = (byte)((uint)in_AX >> 8);
  *pbVar2 = *pbVar2 - bVar13;
  cVar7 = ((char)in_AX - *unaff_SI) - (bVar8 < bVar13);
  uVar9 = CONCAT11(bVar13,cVar7);
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)(unaff_BP + -4) = 0x50;
  piVar15 = unaff_DI;
  do {
    iVar25 = unaff_BP;
    if (in_CX == 0) break;
    in_CX = in_CX + -1;
    piVar4 = piVar15;
    piVar15 = (int *)((int)piVar15 + 1);
  } while (cVar7 != (char)*piVar4);
LAB_1000_5f7e:
  pbVar2 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  bVar8 = *pbVar2;
  uVar9 = CONCAT11((char)(uVar9 >> 8),bVar8);
  uVar24 = CONCAT22(in_DX,uVar9);
  if (0x1f < bVar8) {
    if (bVar8 == 0x20) {
LAB_1000_5fc7:
      in_DX = (undefined2)((ulong)uVar24 >> 0x10);
      uVar9 = (uint)uVar24;
      unaff_DI = (int *)((int)unaff_DI + 1);
      piVar4 = (int *)(unaff_BP + -4);
      *piVar4 = *piVar4 + -1;
      if (*piVar4 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar8 = (byte)uVar9, bVar8 == 0x40) {
      pbVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar9 = (uint)*pbVar2;
      iVar14 = 0x1c;
      pbVar19 = (byte *)0x2847;
      bVar23 = true;
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pbVar5 = pbVar19;
        pbVar19 = pbVar19 + 1;
        bVar23 = *pbVar2 == *pbVar5;
      } while (!bVar23);
      if (bVar23) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar25 = (*(code *)*(undefined2 *)((int)(pbVar19 + -0x2848) * 2 + 0x78bb))();
        return iVar25;
      }
    }
    if ((0x7f < bVar8) && ((bVar8 < 0xa0 || (0xdf < bVar8)))) {
      pbVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar24 = CONCAT22(in_DX,CONCAT11(bVar8,*pbVar2));
      if (CONCAT11(bVar8,*pbVar2) != 0x4081) {
        uVar9 = FUN_1000_8401();
        if ((0x2920 < uVar9) && (uVar9 < 0x2b7f)) {
          FUN_1000_5c7d();
          iVar25 = 0x5fc7;
          uVar24 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        iVar25 = 0x5fb0;
        uVar24 = func_0x00016305();
      }
      in_DX = (undefined2)((ulong)uVar24 >> 0x10);
      uVar9 = (uint)uVar24;
      unaff_DI = unaff_DI + 1;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar3 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar14 = 0x10;
        puVar18 = (uint *)(iVar25 + -2);
        piVar15 = unaff_DI;
        do {
          piVar20 = piVar15;
          puVar17 = puVar18;
          puVar18 = puVar17 + 1;
          uVar9 = *puVar17;
          piVar20[-0x28] = uVar9;
          piVar20[0x28] = uVar9;
          uVar10 = CONCAT11((char)uVar9,(char)(uVar9 >> 8));
          uVar3 = uVar10 * 2;
          cVar7 = ((uVar9 & 0x100) != 0) << 7;
          iVar16 = CONCAT11(cVar7,CARRY2(uVar10,uVar10));
          uVar9 = uVar10 | uVar3 | uVar10 >> 1;
          bVar8 = (byte)(uVar9 >> 8);
          iVar11 = CONCAT11((char)uVar9,bVar8);
          *(char *)((int)piVar20 + -1) = CARRY2(uVar10,uVar10);
          *piVar20 = iVar11;
          *(char *)((int)piVar20 + 1) = cVar7;
          iVar14 = iVar14 + -1;
          piVar15 = piVar20 + 0x28;
        } while (iVar14 != 0);
        *(byte *)puVar18 = (byte)*puVar18 ^ bVar8;
        pbVar2 = (byte *)((int)piVar20 + 0x4f);
        *pbVar2 = *pbVar2 + bVar8;
        *(byte *)((int)piVar20 + 0x4f) = bVar8;
        pcVar21 = (char *)((int)piVar20 + 0x51);
        uVar12 = iVar11 + 1;
        *(byte *)(puVar18 + uVar10) =
             (byte)puVar18[uVar10] + (byte)uVar12 + (((uint)unaff_DI & 1) != 0);
        uVar9 = (iVar25 + -2) * 0x100;
        bVar23 = (uVar9 & 0x400) != 0;
        if ((uVar9 & 0x800) == 0) {
          *(byte *)(puVar17 + 0x1a4) = (byte)puVar17[0x1a4] + (char)(uVar12 >> 8);
          *(byte *)(piVar20 + 0x28) = (byte)*puVar18;
          puVar18 = puVar18 + !bVar23;
          pcVar21 = pcVar21 + uVar12 + (uint)bVar23 * -2;
          pbVar2 = (byte *)((int)puVar18 + iVar16 + 0x10);
          *pbVar2 = *pbVar2 | (byte)(uVar10 >> 1);
          *(byte *)(iVar16 + (int)puVar18) = *(byte *)(iVar16 + (int)puVar18) << 1;
          LOCK();
          pbVar2 = (byte *)((int)puVar18 + iVar16 + 0x30ac);
          *pbVar2 = *pbVar2 ^ (byte)uVar12;
          UNLOCK();
        }
        iVar25 = *(int *)0x32a8;
        FUN_1000_5aba(uVar12,(char)puVar18);
        pcVar21[uVar3 + 0xbad9] = pcVar21[uVar3 + 0xbad9] - (byte)iVar14;
        pcVar21[uVar3] = pcVar21[uVar3] + (char)((uint)iVar14 >> 8);
        piVar4 = (int *)(iVar16 + iVar25 + 0x10ff);
        *piVar4 = *piVar4 >> ((byte)iVar14 & 0x1f);
        iVar25 = iVar16;
        cVar7 = extraout_AH;
        do {
          for (; iVar25 != 0; iVar25 = iVar25 + -1) {
            pcVar6 = pcVar21;
            pcVar21 = pcVar21 + (uint)bVar23 * -2 + 1;
            *pcVar6 = extraout_AL;
          }
          bVar22 = CARRY2((uint)pcVar21,extraout_DX);
          pcVar21 = pcVar21 + extraout_DX;
          cVar7 = cVar7 + -1;
          iVar25 = iVar16;
        } while (cVar7 != '\0');
        return (byte)-bVar22 + 0x6108 + (uint)bVar22;
      }
      goto LAB_1000_5f7e;
    }
    uVar24 = func_0x000163ff();
    in_DX = (undefined2)((ulong)uVar24 >> 0x10);
    uVar9 = (int)uVar24 + 1;
    *(char *)(piVar15 + 1) = (char)piVar15[1] >> 0xb;
    bVar8 = (byte)uVar9;
    if (bVar8 != 0) {
      uVar9 = CONCAT11((char)(uVar9 >> 8),bVar8 - 0x10);
      if (bVar8 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar8 - 0x10;
      piVar15 = (int *)((int)unaff_DI + 1);
      unaff_DI = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(in_DX,uVar9);
  goto LAB_1000_625d;
}


