/* 1000:7ad3 */

undefined4 __cdecl16near FUN_1000_7ad3(void)

{
  undefined2 in_AX;
  byte bVar1;
  int in_CX;
  int iVar2;
  undefined2 in_DX;
  uint in_BX;
  uint unaff_SI;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_DI;
  uint uVar6;
  byte *pbVar7;
  byte bVar8;
  bool bVar9;
  
  FUN_1000_724a();
  iVar2 = in_CX;
  uVar4 = in_BX;
  if (unaff_SI < in_BX) {
    iVar2 = unaff_DI;
    uVar4 = unaff_SI;
    unaff_SI = in_BX;
    unaff_DI = in_CX;
  }
  uVar3 = unaff_SI - uVar4;
  uVar6 = unaff_DI - iVar2;
  bVar1 = (byte)uVar4 & 7;
  bVar1 = 0x80U >> bVar1 | -0x80 << 8 - bVar1;
  pbVar7 = (byte *)(iVar2 * 0x50 + (uVar4 >> 3));
  if ((int)uVar6 < 0) {
    uVar4 = -uVar6;
    if (uVar3 < uVar4) {
      uVar6 = uVar4 >> 1;
      iVar2 = uVar4 + 1;
      do {
        *pbVar7 = bVar1;
        pbVar7 = pbVar7 + -0x50;
        bVar9 = uVar6 < uVar3;
        uVar6 = uVar6 - uVar3;
        if (bVar9) {
          uVar6 = uVar6 + uVar4;
          bVar8 = bVar1 & 1;
          bVar1 = bVar1 >> 1 | bVar1 << 7;
          pbVar7 = pbVar7 + bVar8;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    else {
      uVar5 = uVar3 >> 1;
      iVar2 = uVar3 + 1;
      do {
        *pbVar7 = bVar1;
        bVar8 = bVar1 & 1;
        bVar1 = bVar1 >> 1 | bVar1 << 7;
        pbVar7 = pbVar7 + bVar8;
        bVar9 = uVar5 < uVar4;
        uVar5 = uVar5 + uVar6;
        if (bVar9) {
          uVar5 = uVar5 + uVar3;
          pbVar7 = pbVar7 + -0x50;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else if (uVar3 < uVar6) {
    uVar4 = uVar6 >> 1;
    iVar2 = uVar6 + 1;
    do {
      *pbVar7 = bVar1;
      pbVar7 = pbVar7 + 0x50;
      bVar9 = uVar4 < uVar3;
      uVar4 = uVar4 - uVar3;
      if (bVar9) {
        uVar4 = uVar4 + uVar6;
        bVar8 = bVar1 & 1;
        bVar1 = bVar1 >> 1 | bVar1 << 7;
        pbVar7 = pbVar7 + bVar8;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    uVar4 = uVar3 >> 1;
    iVar2 = uVar3 + 1;
    do {
      *pbVar7 = bVar1;
      bVar8 = bVar1 & 1;
      bVar1 = bVar1 >> 1 | bVar1 << 7;
      pbVar7 = pbVar7 + bVar8;
      bVar9 = uVar4 < uVar6;
      uVar4 = uVar4 - uVar6;
      if (bVar9) {
        uVar4 = uVar4 + uVar3;
        pbVar7 = pbVar7 + 0x50;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


