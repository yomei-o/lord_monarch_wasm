/* 1000:8bd2 */

/* WARNING: Instruction at (ram,0x00018baa) overlaps instruction at (ram,0x00018ba9)
    */

byte * FUN_1000_8bd2(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char extraout_AH;
  uint in_AX;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  byte *in_CX;
  int iVar10;
  undefined2 uVar11;
  undefined2 in_DX;
  byte *in_BX;
  byte *unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte *unaff_DS;
  byte *pbVar12;
  undefined2 in_FS;
  char cVar13;
  bool bVar14;
  undefined1 uVar15;
  undefined4 uVar16;
  byte *pbStack_14;
  
code_r0x00018bd2:
  if ((in_AX & 0x10) != 0) {
    in_AX = in_AX + 1;
    bVar8 = (byte)in_CX;
    bVar14 = CARRY1(bVar8,*in_BX);
    bVar4 = *in_BX;
    pbVar2 = in_BX + (int)unaff_SI + 2;
    bVar5 = *pbVar2;
    bVar6 = (byte)in_AX;
    bVar1 = *pbVar2;
    *pbVar2 = bVar1 + bVar6 + bVar14;
    pbVar2 = unaff_BP + -0x80;
    cVar13 = (char)(in_AX >> 8);
    *pbVar2 = *pbVar2 + cVar13 + (CARRY1(bVar5,bVar6) || CARRY1(bVar1 + bVar6,bVar14));
    iVar10 = CONCAT11((char)((uint)in_CX >> 8),bVar8 + bVar4) + -1;
    if (iVar10 != 0 && *pbVar2 == 0) {
      bVar5 = in_BX[(int)unaff_SI];
      (in_BX + (int)unaff_SI)[0x59] = (in_BX + (int)unaff_SI)[0x59] ^ (byte)in_BX;
      return (byte *)CONCAT11(cVar13 - bVar5,bVar6);
    }
    bVar5 = (char)iVar10 << 1 | (char)iVar10 < '\0';
    bVar14 = (char)bVar5 < '\0';
    in_CX = (byte *)CONCAT11((char)((uint)iVar10 >> 8),bVar5 << 1 | bVar14);
    goto LAB_1000_8bf3_1;
  }
  uVar11 = CONCAT11((char)((uint)in_DX >> 8),(byte)in_DX - in_BX[(int)unaff_SI]);
  (unaff_BP + (int)unaff_DI)[0x4c1] =
       (unaff_BP + (int)unaff_DI)[0x4c1] + (char)(in_AX & 0xff0f) +
       ((byte)in_DX < in_BX[(int)unaff_SI]);
  pbVar2 = unaff_SI;
  unaff_SI = unaff_SI + 1;
  bVar5 = *pbVar2;
  iVar10 = CONCAT11((char)((in_AX & 0xff0f) >> 8),bVar5);
  for (; in_CX != (byte *)0x0; in_CX = in_CX + -1) {
    pbVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *pbVar2 = bVar5;
  }
LAB_1000_8ba9:
  uVar16 = CONCAT22(uVar11,iVar10);
  unaff_BP = unaff_BP + iVar10;
  cVar13 = unaff_SI < unaff_BP;
  uVar15 = unaff_SI == unaff_BP;
  while (in_DX = (undefined2)((ulong)uVar16 >> 0x10), (bool)uVar15) {
    pbVar2 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    bVar5 = *pbVar2;
    in_AX = CONCAT11((char)((ulong)uVar16 >> 8),bVar5);
    bVar14 = false;
    if (((byte)((ulong)uVar16 >> 0x18) & bVar5) != 0) goto LAB_1000_8bf3_1;
    if (((byte)((ulong)uVar16 >> 0x10) & bVar5) != 0) goto code_r0x00018bd2;
    if ((bVar5 & 0x20) == 0) {
      uVar15 = true;
      for (uVar9 = (uint)bVar5; uVar9 != 0; uVar9 = uVar9 - 1) {
        pbVar3 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        pbVar2 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        *pbVar3 = *pbVar2;
      }
    }
    else {
      uVar15 = (bVar5 & 0x1f) == 0;
      for (uVar9 = CONCAT11(bVar5,*unaff_SI) & 0x1fff; unaff_SI = unaff_SI + 1, uVar9 != 0;
          uVar9 = uVar9 - 1) {
        pbVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        *pbVar2 = *unaff_SI;
      }
    }
    in_CX = (byte *)0x0;
    cVar13 = '\0';
    uVar16 = FUN_1000_80e8();
  }
  unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + (char)((uint)in_CX >> 8) + cVar13;
  FUN_1000_6390();
  bVar5 = in_BX[-0x2d82];
  if (((bVar5 == 0x7a) || (bVar5 == 0x7b)) || (bVar5 = bVar5 - 0x30, bVar5 < 0x30)) {
    unaff_DI[0xe15] = unaff_DI[0xe15] ^ (byte)((uint)in_BX >> 8);
    (in_BX + (int)unaff_SI)[0x1f] = (in_BX + (int)unaff_SI)[0x1f] + bVar5;
    return pbStack_14;
  }
  in_CX = (byte *)CONCAT11((char)((uint)in_CX >> 8) + *unaff_SI,(char)in_CX);
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + extraout_AH;
  pbVar7 = (byte *)0x6000;
  unaff_DS = unaff_SI;
  goto code_r0x00018ba3;
LAB_1000_8bf3_1:
  uVar9 = CONCAT11((char)((uint)in_CX >> 8),((char)in_CX << 1 | (char)in_CX < '\0') + 4);
  pbVar7 = unaff_SI + 1;
  in_CX = (byte *)-((CONCAT11((byte)(in_AX << 1) | bVar14,*unaff_SI) & 0x1fff) - (int)unaff_DI);
  pbVar12 = in_BX;
  while( true ) {
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      pbVar3 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      pbVar2 = in_CX;
      in_CX = in_CX + 1;
      *pbVar3 = *pbVar2;
    }
    if (pbVar7 == unaff_BP) {
      do {
        bVar5 = *pbVar7;
        pbVar3 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        pbVar2 = pbVar7;
        pbVar7 = pbVar7 + 1;
        *pbVar3 = *pbVar2;
      } while (bVar5 != 0);
      return in_CX;
    }
    pbStack_14 = unaff_DI;
    if ((*pbVar7 & 0xe0) != 0x60) break;
    uVar9 = (uint)(*pbVar7 & 0x1f);
    pbVar7 = pbVar7 + -0x43f;
    pbVar12 = unaff_DS;
  }
code_r0x00018ba3:
  unaff_BP = pbVar7;
  uVar11 = 0x8040;
  unaff_SI = unaff_BP + 2;
  iVar10 = *(int *)unaff_BP;
  goto LAB_1000_8ba9;
}


