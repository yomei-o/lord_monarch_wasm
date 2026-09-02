/* 1000:8c11 */

/* WARNING: Instruction at (ram,0x00018baa) overlaps instruction at (ram,0x00018ba9)
    */

byte * FUN_1000_8c11(byte *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  char extraout_AH;
  int iVar5;
  byte *in_AX;
  byte bVar6;
  byte bVar7;
  char cVar10;
  int iVar8;
  uint uVar9;
  byte bVar11;
  undefined2 extraout_DX;
  undefined2 uVar12;
  byte bVar13;
  undefined2 in_DX;
  byte *in_BX;
  byte *unaff_BP;
  byte *pbVar14;
  byte *pbVar15;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte *unaff_DS;
  undefined2 in_FS;
  char cVar16;
  bool bVar17;
  undefined1 uVar18;
  undefined4 uVar19;
  byte *in_stack_00000000;
  
  do {
    if ((*unaff_SI & 0xe0) == 0x60) {
      uVar9 = (uint)(*unaff_SI & 0x1f);
      unaff_SI = unaff_SI + -0x43f;
      pbVar14 = unaff_DS;
      unaff_DS = in_stack_00000000;
    }
    else {
code_r0x00018ba3:
      unaff_BP = unaff_SI;
      uVar12 = 0x8040;
      iVar5 = *(int *)unaff_BP;
      pbVar14 = unaff_BP;
      while( true ) {
        uVar19 = CONCAT22(uVar12,iVar5);
        pbVar14 = pbVar14 + 2;
        unaff_BP = unaff_BP + iVar5;
        cVar16 = pbVar14 < unaff_BP;
        uVar18 = pbVar14 == unaff_BP;
        while( true ) {
          in_DX = (undefined2)((ulong)uVar19 >> 0x10);
          cVar10 = (char)((uint)in_AX >> 8);
          if (!(bool)uVar18) {
            unaff_BP[(int)pbVar14] = unaff_BP[(int)pbVar14] + cVar10 + cVar16;
            FUN_1000_6390();
            bVar7 = in_BX[-0x2d82];
            if ((bVar7 != 0x7a) && (bVar7 != 0x7b)) {
              bVar7 = bVar7 - 0x30;
              if (bVar7 >= 0x30) {
                in_AX = (byte *)CONCAT11((char)((uint)in_AX >> 8) + *pbVar14 + (bVar7 < 0x30),
                                         (char)in_AX);
                in_BX[(int)pbVar14] = in_BX[(int)pbVar14] + extraout_AH;
                unaff_SI = (byte *)0x6000;
                unaff_DS = pbVar14;
                goto code_r0x00018ba3;
              }
            }
            unaff_DI[0xe15] = unaff_DI[0xe15] ^ (byte)((uint)in_BX >> 8);
            (in_BX + (int)pbVar14)[0x1f] = (in_BX + (int)pbVar14)[0x1f] + bVar7;
            return (byte *)CONCAT22(extraout_DX,param_1);
          }
          uVar18 = (undefined1)((ulong)uVar19 >> 8);
          pbVar15 = pbVar14 + 1;
          bVar7 = *pbVar14;
          iVar5 = CONCAT11(uVar18,bVar7);
          bVar13 = (byte)((ulong)uVar19 >> 0x18);
          if ((bVar13 & bVar7) != 0) {
            iVar5 = iVar5 << 1;
            goto code_r0x00018bf7;
          }
          bVar11 = (byte)((ulong)uVar19 >> 0x10);
          if ((bVar11 & bVar7) != 0) break;
          if ((bVar7 & 0x20) == 0) {
            uVar18 = true;
            for (uVar9 = (uint)bVar7; uVar9 != 0; uVar9 = uVar9 - 1) {
              pbVar2 = unaff_DI;
              unaff_DI = unaff_DI + 1;
              pbVar1 = pbVar15;
              pbVar15 = pbVar15 + 1;
              *pbVar2 = *pbVar1;
            }
          }
          else {
            uVar18 = (bVar7 & 0x1f) == 0;
            for (uVar9 = CONCAT11(bVar7,*pbVar15) & 0x1fff; pbVar15 = pbVar15 + 1, uVar9 != 0;
                uVar9 = uVar9 - 1) {
              pbVar1 = unaff_DI;
              unaff_DI = unaff_DI + 1;
              *pbVar1 = *pbVar15;
            }
          }
          in_AX = (byte *)0x0;
          cVar16 = '\0';
          uVar19 = FUN_1000_80e8();
          pbVar14 = pbVar15;
        }
        if ((bVar7 & 0x10) != 0) break;
        uVar9 = CONCAT11(uVar18,bVar7) & 0xff0f;
        uVar12 = CONCAT11(bVar13,bVar11 - in_BX[(int)pbVar15]);
        (unaff_BP + (int)unaff_DI)[0x4c1] =
             (unaff_BP + (int)unaff_DI)[0x4c1] + (char)uVar9 + (bVar11 < in_BX[(int)pbVar15]);
        bVar7 = *pbVar15;
        iVar5 = CONCAT11((char)(uVar9 >> 8),bVar7);
        for (; in_AX != (byte *)0x0; in_AX = in_AX + -1) {
          pbVar1 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          *pbVar1 = bVar7;
        }
      }
      iVar5 = iVar5 + 1;
      bVar6 = (byte)in_AX;
      bVar17 = CARRY1(bVar6,*in_BX);
      bVar3 = *in_BX;
      pbVar1 = in_BX + (int)pbVar15 + 2;
      bVar7 = *pbVar1;
      bVar4 = (byte)iVar5;
      bVar13 = *pbVar1;
      *pbVar1 = bVar13 + bVar4 + bVar17;
      in_DX = CONCAT11(0x36,bVar11);
      pbVar1 = unaff_BP + -0x80;
      cVar16 = (char)((uint)iVar5 >> 8);
      *pbVar1 = *pbVar1 + cVar16 + (CARRY1(bVar7,bVar4) || CARRY1(bVar13 + bVar4,bVar17));
      iVar8 = CONCAT11(cVar10,bVar6 + bVar3) + -1;
      if (iVar8 != 0 && *pbVar1 == 0) {
        bVar7 = in_BX[(int)pbVar15];
        (in_BX + (int)pbVar15)[0x59] = (in_BX + (int)pbVar15)[0x59] ^ (byte)in_BX;
        return (byte *)CONCAT22(0x3600,(byte *)CONCAT11(cVar16 - bVar7,bVar4));
      }
      bVar7 = (char)iVar8 << 1 | (char)iVar8 < '\0';
      in_AX = (byte *)CONCAT11((char)((uint)iVar8 >> 8),bVar7 << 1 | (char)bVar7 < '\0');
      param_1 = unaff_BP;
code_r0x00018bf7:
      uVar9 = CONCAT11((char)((uint)in_AX >> 8),((char)in_AX << 1 | (char)in_AX < '\0') + 4);
      unaff_SI = pbVar14 + 2;
      in_AX = (byte *)-((CONCAT11((char)iVar5,*pbVar15) & 0x1fff) - (int)unaff_DI);
      pbVar14 = in_BX;
    }
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      pbVar2 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      pbVar1 = in_AX;
      in_AX = in_AX + 1;
      *pbVar2 = *pbVar1;
    }
    in_stack_00000000 = unaff_DS;
    if (unaff_SI == unaff_BP) {
      do {
        bVar7 = *unaff_SI;
        pbVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        pbVar1 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        *pbVar2 = *pbVar1;
      } while (bVar7 != 0);
      return (byte *)CONCAT22(in_DX,in_AX);
    }
  } while( true );
}


