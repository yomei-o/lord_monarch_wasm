/* 1000:575e */

int FUN_1000_575e(void)

{
  byte *pbVar1;
  int in_AX;
  uint uVar2;
  byte bVar3;
  byte extraout_AH;
  int in_CX;
  int iVar4;
  int in_BX;
  byte *unaff_SI;
  byte *pbVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_GS;
  byte in_CF;
  bool bVar6;
  
  uVar2 = (in_AX + 0x1754) - (uint)in_CF;
  bVar3 = (byte)(uVar2 - *(uint *)(unaff_SI + in_BX) >> 8);
  if (uVar2 < *(uint *)(unaff_SI + in_BX)) {
    bVar6 = true;
    FUN_1000_578e();
    bVar3 = extraout_AH;
    if (bVar6) {
      iVar4 = 0;
      do {
        pbVar1 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        iVar4 = iVar4 + (uint)*pbVar1;
        in_CX = in_CX + -1;
      } while (in_CX != 0);
      return iVar4;
    }
  }
  iVar4 = 0x40;
  pbVar5 = unaff_SI;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pbVar1 = pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar3 == *pbVar1);
  *unaff_SI = *unaff_SI ^ bVar3;
  return CONCAT11(bVar3,bVar3);
}


