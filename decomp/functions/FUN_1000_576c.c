/* 1000:576c */

byte FUN_1000_576c(void)

{
  byte *pbVar1;
  undefined2 in_AX;
  byte bVar2;
  int in_CX;
  int iVar3;
  byte *unaff_SI;
  byte *pbVar4;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool in_CF;
  
  if (in_CF) {
    bVar2 = 0;
    do {
      pbVar1 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      bVar2 = bVar2 + *pbVar1;
      in_CX = in_CX + -1;
    } while (in_CX != 0);
    return bVar2;
  }
  iVar3 = 0x40;
  bVar2 = (byte)((uint)in_AX >> 8);
  pbVar4 = unaff_SI;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pbVar1 = pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar2 == *pbVar1);
  *unaff_SI = *unaff_SI ^ bVar2;
  return bVar2;
}


