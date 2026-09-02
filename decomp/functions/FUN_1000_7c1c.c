/* 1000:7c1c */

undefined4 __cdecl16near FUN_1000_7c1c(void)

{
  byte *pbVar1;
  undefined2 in_AX;
  byte bVar2;
  byte bVar3;
  uint in_CX;
  uint uVar4;
  uint uVar5;
  undefined2 in_DX;
  uint in_BX;
  uint uVar6;
  uint unaff_SI;
  byte *pbVar7;
  uint unaff_DI;
  byte *pbVar8;
  bool bVar9;
  int local_16;
  
  FUN_1000_724a();
  uVar6 = in_BX;
  if (unaff_SI < in_BX) {
    uVar6 = unaff_SI;
    unaff_SI = in_BX;
  }
  uVar4 = in_CX;
  if (unaff_DI < in_CX) {
    uVar4 = unaff_DI;
    unaff_DI = in_CX;
  }
  bVar3 = (byte)uVar6 & 7;
  pbVar7 = (byte *)(uVar4 * 0x50 + (uVar6 >> 3));
  local_16 = (unaff_DI - uVar4) + 1;
  do {
    uVar4 = (unaff_SI - uVar6) + 1;
    bVar2 = 0x80U >> bVar3 | -0x80 << 8 - bVar3;
    do {
      *pbVar7 = bVar2;
      uVar4 = uVar4 - 1;
      if (uVar4 == 0) goto LAB_1000_7c8d;
      bVar9 = (bool)(bVar2 & 1);
      bVar2 = bVar2 >> 1 | bVar2 << 7;
    } while (!bVar9);
    pbVar8 = pbVar7 + 1;
    uVar5 = uVar4 >> 3;
    if (uVar5 != 0) {
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        pbVar1 = pbVar8;
        pbVar8 = pbVar8 + 1;
        *pbVar1 = 0xff;
      }
    }
    for (uVar4 = uVar4 & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pbVar8 = bVar2;
      bVar2 = bVar2 >> 1 | bVar2 << 7;
    }
LAB_1000_7c8d:
    pbVar7 = pbVar7 + 0x50;
    local_16 = local_16 + -1;
    if (local_16 == 0) {
      out(0x7c,0);
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}


