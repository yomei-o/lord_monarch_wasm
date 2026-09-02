/* 1000:5f36 */

/* WARNING: Instruction at (ram,0x00015f7a) overlaps instruction at (ram,0x00015f79)
    */

int FUN_1000_5f36(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  byte extraout_AL;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char extraout_AH;
  char cVar12;
  int in_CX;
  int iVar13;
  undefined2 in_DX;
  uint extraout_DX;
  byte *in_BX;
  int iVar14;
  int unaff_BP;
  byte *unaff_SI;
  uint *puVar15;
  uint *puVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar20;
  bool bVar21;
  undefined4 uVar22;
  uint auStackY_50 [18];
  int iVar23;
  byte bStack_1;
  byte bVar11;
  
  pbVar17 = (byte *)0x1690;
  uRam000a968e = 0xa800;
  *(char *)0x19 = *(char *)0x19 + (char)in_DX + in_CF;
  while( true ) {
    for (; in_CX != 0; in_CX = in_CX + -1) {
      pbVar5 = pbVar17;
      pbVar17 = pbVar17 + 2;
      pbVar5[0] = 0;
      pbVar5[1] = 0xa8;
    }
    pbVar17 = pbVar17 + 0x1e;
    if (in_BX <= pbVar17) break;
    *(int *)(in_BX + (int)unaff_SI) = *(int *)(in_BX + (int)unaff_SI) + 0x57ff;
  }
  pbVar5 = in_BX;
  bVar6 = *pbVar5;
  *pbVar5 = *pbVar5 + 0x58;
  bVar6 = -(bVar6 < 0xa8) - *unaff_SI;
  uVar7 = CONCAT11(0xa8,bVar6);
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)(unaff_BP + -4) = 0x50;
  iVar13 = 0;
  pbVar19 = pbVar17;
  do {
    iVar23 = unaff_BP;
    if (iVar13 == 0) break;
    iVar13 = iVar13 + -1;
    pbVar5 = pbVar19;
    pbVar19 = pbVar19 + 1;
  } while (bVar6 != *pbVar5);
LAB_1000_5f7e:
  pbVar5 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  bVar6 = *pbVar5;
  uVar7 = CONCAT11((char)(uVar7 >> 8),bVar6);
  uVar22 = CONCAT22(in_DX,uVar7);
  if (0x1f < bVar6) {
    if (bVar6 == 0x20) {
LAB_1000_5fc7:
      in_DX = (undefined2)((ulong)uVar22 >> 0x10);
      uVar7 = (uint)uVar22;
      pbVar17 = pbVar17 + 1;
      piVar2 = (int *)(unaff_BP + -4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) goto LAB_1000_625d;
      goto LAB_1000_5f7e;
    }
    while (bVar6 = (byte)uVar7, bVar6 == 0x40) {
      pbVar5 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar7 = (uint)*pbVar5;
      iVar13 = 0x1c;
      pbVar18 = (byte *)0x2847;
      bVar21 = true;
      do {
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pbVar4 = pbVar18;
        pbVar18 = pbVar18 + 1;
        bVar21 = *pbVar5 == *pbVar4;
      } while (!bVar21);
      if (bVar21) {
                    /* WARNING: Could not recover jumptable at 0x0001600d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar13 = (*(code *)*(undefined2 *)((int)(pbVar18 + -0x2848) * 2 + 0x78bb))();
        return iVar13;
      }
    }
    if ((0x7f < bVar6) && ((bVar6 < 0xa0 || (0xdf < bVar6)))) {
      pbVar5 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      uVar22 = CONCAT22(in_DX,CONCAT11(bVar6,*pbVar5));
      if (CONCAT11(bVar6,*pbVar5) != 0x4081) {
        uVar7 = FUN_1000_8401();
        if ((0x2920 < uVar7) && (uVar7 < 0x2b7f)) {
          FUN_1000_5c7d();
          iVar23 = 0x5fc7;
          uVar22 = func_0x000163a2();
          goto LAB_1000_5fc7;
        }
        FUN_1000_5c7d();
                    /* WARNING: Call to offcut address within same function */
        iVar23 = 0x5fb0;
        uVar22 = func_0x00016305();
      }
      in_DX = (undefined2)((ulong)uVar22 >> 0x10);
      uVar7 = (uint)uVar22;
      pbVar17 = pbVar17 + 2;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 - 2;
      if (uVar3 < 2) {
        *(undefined2 *)(unaff_BP + -4) = 0;
LAB_1000_625d:
        iVar13 = 0x10;
        puVar16 = (uint *)(iVar23 + -2);
        pbVar19 = pbVar17;
        do {
          pbVar18 = pbVar19;
          puVar15 = puVar16;
          puVar16 = puVar15 + 1;
          uVar7 = *puVar15;
          *(uint *)(pbVar18 + -0x50) = uVar7;
          *(uint *)(pbVar18 + 0x50) = uVar7;
          uVar8 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
          uVar3 = uVar8 * 2;
          bVar6 = ((uVar7 & 0x100) != 0) << 7;
          iVar14 = CONCAT11(bVar6,CARRY2(uVar8,uVar8));
          uVar7 = uVar8 | uVar3 | uVar8 >> 1;
          bVar11 = (byte)(uVar7 >> 8);
          iVar9 = CONCAT11((char)uVar7,bVar11);
          pbVar18[-1] = CARRY2(uVar8,uVar8);
          *(int *)pbVar18 = iVar9;
          pbVar18[1] = bVar6;
          iVar13 = iVar13 + -1;
          pbVar19 = pbVar18 + 0x50;
        } while (iVar13 != 0);
        *(byte *)puVar16 = (byte)*puVar16 ^ bVar11;
        pbVar5 = pbVar18 + 0x4f;
        *pbVar5 = *pbVar5 + bVar11;
        pbVar18[0x4f] = bVar11;
        pbVar19 = pbVar18 + 0x51;
        uVar10 = iVar9 + 1;
        *(byte *)(puVar16 + uVar8) =
             (byte)puVar16[uVar8] + (byte)uVar10 + (((uint)pbVar17 & 1) != 0);
        uVar7 = (iVar23 + -2) * 0x100;
        bVar21 = (uVar7 & 0x400) != 0;
        if ((uVar7 & 0x800) == 0) {
          *(byte *)(puVar15 + 0x1a4) = (byte)puVar15[0x1a4] + (char)(uVar10 >> 8);
          pbVar18[0x50] = (byte)*puVar16;
          puVar16 = puVar16 + !bVar21;
          pbVar19 = pbVar19 + uVar10 + (uint)bVar21 * -2;
          pbVar5 = (byte *)((int)puVar16 + iVar14 + 0x10);
          *pbVar5 = *pbVar5 | (byte)(uVar8 >> 1);
          *(byte *)(iVar14 + (int)puVar16) = *(byte *)(iVar14 + (int)puVar16) << 1;
          LOCK();
          pbVar5 = (byte *)((int)puVar16 + iVar14 + 0x30ac);
          *pbVar5 = *pbVar5 ^ (byte)uVar10;
          UNLOCK();
        }
        iVar23 = *(int *)0x32a8;
        FUN_1000_5aba(uVar10,(char)puVar16);
        pbVar19[uVar3 + 0xbad9] = pbVar19[uVar3 + 0xbad9] - (byte)iVar13;
        pbVar19[uVar3] = pbVar19[uVar3] + (char)((uint)iVar13 >> 8);
        piVar2 = (int *)(iVar14 + iVar23 + 0x10ff);
        *piVar2 = *piVar2 >> ((byte)iVar13 & 0x1f);
        iVar13 = iVar14;
        cVar12 = extraout_AH;
        do {
          for (; iVar13 != 0; iVar13 = iVar13 + -1) {
            pbVar5 = pbVar19;
            pbVar19 = pbVar19 + (uint)bVar21 * -2 + 1;
            *pbVar5 = extraout_AL;
          }
          bVar20 = CARRY2((uint)pbVar19,extraout_DX);
          pbVar19 = pbVar19 + extraout_DX;
          cVar12 = cVar12 + -1;
          iVar13 = iVar14;
        } while (cVar12 != '\0');
        return (byte)-bVar20 + 0x6108 + (uint)bVar20;
      }
      goto LAB_1000_5f7e;
    }
    uVar22 = func_0x000163ff();
    in_DX = (undefined2)((ulong)uVar22 >> 0x10);
    uVar7 = (int)uVar22 + 1;
    pbVar19[2] = (char)pbVar19[2] >> 0xb;
    bVar6 = (byte)uVar7;
    if (bVar6 != 0) {
      uVar7 = CONCAT11((char)(uVar7 >> 8),bVar6 - 0x10);
      if (bVar6 < 0x10) goto FUN_1000_6259;
      *(char *)0x32a9 = bVar6 - 0x10;
      pbVar19 = pbVar17 + 1;
      pbVar17 = unaff_CS;
      goto LAB_1000_5f7e;
    }
  }
FUN_1000_6259:
  out(in_DX,uVar7);
  goto LAB_1000_625d;
}


