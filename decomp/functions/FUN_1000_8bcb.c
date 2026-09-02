/* 1000:8bcb */

/* WARNING: Instruction at (ram,0x00018bab) overlaps instruction at (ram,0x00018baa)
    */

byte * FUN_1000_8bcb(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  char extraout_AH;
  undefined1 extraout_AH_00;
  int iVar6;
  byte *pbVar7;
  byte bVar8;
  byte bVar9;
  char cVar13;
  uint in_CX;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  undefined2 extraout_DX;
  byte *in_BX;
  byte *unaff_BP;
  byte *pbVar14;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte *unaff_DS;
  undefined2 in_FS;
  char cVar15;
  bool bVar16;
  byte *in_stack_00000000;
  
  do {
    cVar15 = false;
    bVar16 = (in_CX & 0x1f00) == 0;
    for (uVar10 = in_CX & 0x1fff; uVar10 != 0; uVar10 = uVar10 - 1) {
      pbVar3 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      pbVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *pbVar3 = *pbVar2;
    }
    pbVar11 = (byte *)0x0;
LAB_1000_8baa:
    FUN_1000_80e8();
    cVar13 = (char)((uint)pbVar11 >> 8);
    if (!bVar16) {
      unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + cVar13 + cVar15;
      FUN_1000_6390();
      bVar9 = in_BX[-0x2d82];
      if (((bVar9 == 0x7a) || (bVar9 == 0x7b)) || (bVar9 = bVar9 - 0x30, bVar9 < 0x30)) {
        unaff_DI[0xe15] = unaff_DI[0xe15] ^ (byte)((uint)in_BX >> 8);
        (in_BX + (int)unaff_SI)[0x1f] = (in_BX + (int)unaff_SI)[0x1f] + bVar9;
        return in_stack_00000000;
      }
      pbVar11 = (byte *)CONCAT11((char)((uint)pbVar11 >> 8) + *unaff_SI,(char)pbVar11);
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + extraout_AH;
      pbVar7 = (byte *)0x6000;
      unaff_DS = unaff_SI;
code_r0x00018ba3:
      unaff_BP = pbVar7;
      iVar6 = *(int *)unaff_BP;
      unaff_SI = unaff_BP;
LAB_1000_8ba9:
      unaff_SI = unaff_SI + 2;
      unaff_BP = unaff_BP + iVar6;
      cVar15 = unaff_SI < unaff_BP;
      bVar16 = unaff_SI == unaff_BP;
      goto LAB_1000_8baa;
    }
    pbVar14 = unaff_SI + 1;
    bVar9 = *unaff_SI;
    if (((byte)((uint)extraout_DX >> 8) & bVar9) != 0) {
      iVar6 = CONCAT11(extraout_AH_00,bVar9) << 1;
code_r0x00018bf7:
      uVar10 = CONCAT11((char)((uint)pbVar11 >> 8),((char)pbVar11 << 1 | (char)pbVar11 < '\0') + 4);
      pbVar7 = unaff_SI + 2;
      pbVar11 = (byte *)-((CONCAT11((char)iVar6,*pbVar14) & 0x1fff) - (int)unaff_DI);
      pbVar14 = in_BX;
      while( true ) {
        for (; uVar10 != 0; uVar10 = uVar10 - 1) {
          pbVar3 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          pbVar2 = pbVar11;
          pbVar11 = pbVar11 + 1;
          *pbVar3 = *pbVar2;
        }
        if (pbVar7 == unaff_BP) {
          do {
            bVar9 = *pbVar7;
            pbVar3 = unaff_DI;
            unaff_DI = unaff_DI + 1;
            pbVar2 = pbVar7;
            pbVar7 = pbVar7 + 1;
            *pbVar3 = *pbVar2;
          } while (bVar9 != 0);
          return pbVar11;
        }
        in_stack_00000000 = unaff_DI;
        if ((*pbVar7 & 0xe0) != 0x60) break;
        uVar10 = (uint)(*pbVar7 & 0x1f);
        pbVar7 = pbVar7 + -0x43f;
        pbVar14 = unaff_DS;
      }
      goto code_r0x00018ba3;
    }
    if (((byte)extraout_DX & bVar9) != 0) {
      if ((bVar9 & 0x10) != 0) {
        iVar6 = CONCAT11(extraout_AH_00,bVar9) + 1;
        bVar8 = (byte)pbVar11;
        bVar16 = CARRY1(bVar8,*in_BX);
        bVar4 = *in_BX;
        pbVar2 = in_BX + (int)pbVar14 + 2;
        bVar9 = *pbVar2;
        bVar5 = (byte)iVar6;
        bVar1 = *pbVar2;
        *pbVar2 = bVar1 + bVar5 + bVar16;
        pbVar2 = unaff_BP + -0x80;
        cVar15 = (char)((uint)iVar6 >> 8);
        *pbVar2 = *pbVar2 + cVar15 + (CARRY1(bVar9,bVar5) || CARRY1(bVar1 + bVar5,bVar16));
        iVar12 = CONCAT11(cVar13,bVar8 + bVar4) + -1;
        if (iVar12 != 0 && *pbVar2 == 0) {
          bVar9 = in_BX[(int)pbVar14];
          (in_BX + (int)pbVar14)[0x59] = (in_BX + (int)pbVar14)[0x59] ^ (byte)in_BX;
          return (byte *)CONCAT11(cVar15 - bVar9,bVar5);
        }
        bVar9 = (char)iVar12 << 1 | (char)iVar12 < '\0';
        pbVar11 = (byte *)CONCAT11((char)((uint)iVar12 >> 8),bVar9 << 1 | (char)bVar9 < '\0');
        goto code_r0x00018bf7;
      }
      uVar10 = CONCAT11(extraout_AH_00,bVar9) & 0xff0f;
      (unaff_BP + (int)unaff_DI)[0x4c1] =
           (unaff_BP + (int)unaff_DI)[0x4c1] + (char)uVar10 +
           ((byte)extraout_DX < in_BX[(int)pbVar14]);
      bVar9 = *pbVar14;
      iVar6 = CONCAT11((char)(uVar10 >> 8),bVar9);
      for (; pbVar11 != (byte *)0x0; pbVar11 = pbVar11 + -1) {
        pbVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        *pbVar2 = bVar9;
      }
      goto LAB_1000_8ba9;
    }
    if ((bVar9 & 0x20) == 0) {
      cVar15 = false;
      bVar16 = true;
      for (uVar10 = (uint)bVar9; uVar10 != 0; uVar10 = uVar10 - 1) {
        pbVar3 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        pbVar2 = pbVar14;
        pbVar14 = pbVar14 + 1;
        *pbVar3 = *pbVar2;
      }
      pbVar11 = (byte *)0x0;
      unaff_SI = pbVar14;
      goto LAB_1000_8baa;
    }
    unaff_SI = unaff_SI + 2;
    in_CX = CONCAT11(bVar9,*pbVar14);
  } while( true );
}


