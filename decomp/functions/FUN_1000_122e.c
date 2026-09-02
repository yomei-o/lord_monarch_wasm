/* 1000:122e */

/* WARNING: Instruction at (ram,0x00011243) overlaps instruction at (ram,0x00011241)
    */

void FUN_1000_122e(void)

{
  undefined2 uVar1;
  byte bVar2;
  int in_AX;
  char cVar4;
  int iVar3;
  byte extraout_AH;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar5;
  
  cVar4 = 'H' - *(byte *)(unaff_SI + 6);
  if (*(byte *)(unaff_SI + 6) < 0x49) {
    bVar2 = 0x48 - cVar4;
    iVar3 = CONCAT11(cVar4,bVar2);
    bVar5 = bVar2 < *(byte *)(unaff_SI + 0x1d);
    if (bVar2 == *(byte *)(unaff_SI + 0x1d)) {
      return;
    }
  }
  else {
    bVar5 = CONCAT11(cVar4,0x7f) < 0x2275;
    iVar3 = CONCAT11(cVar4,0x7f) + 0xdd8b;
  }
  *(char *)(unaff_SI + 0x1d) = (char)iVar3;
  LOCK();
  uVar1 = *(undefined2 *)(in_AX + 0x24);
  *(undefined2 *)(in_AX + 0x24) = CONCAT11((char)((uint)iVar3 >> 8),(char)iVar3 + bVar5 + -0x50);
  UNLOCK();
  bVar2 = (byte)((uint)uVar1 >> 8);
  if ((bool)((byte)uVar1 & 1)) {
    FUN_1000_92b2();
    bVar2 = extraout_AH;
  }
  *(byte *)0x58f4 = *(byte *)0x58f4 & bVar2;
  return;
}


