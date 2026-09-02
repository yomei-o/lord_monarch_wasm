/* 1000:07af */

undefined4 FUN_1000_07af(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte in_AL;
  int iVar4;
  byte in_DL;
  byte bVar5;
  int in_BX;
  byte *unaff_SI;
  byte *unaff_DI;
  byte *pbVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  byte in_CF;
  undefined1 in_ZF;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  iVar4 = 0xe;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pbVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    in_CF = in_AL < *pbVar1;
    in_ZF = in_AL == *pbVar1;
  } while (!(bool)in_ZF);
  pbVar6 = unaff_DI;
  if ((bool)in_ZF) {
    pbVar6 = unaff_DI + -0x1001;
    bVar5 = unaff_DI[0xd];
    bVar3 = bVar5 & 7;
    in_CF = 0;
    *(byte *)0x32cc = *(byte *)0x32cc | '\x01' << bVar3 | 1U >> 8 - bVar3;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),bVar5);
    *(undefined1 *)(in_BX + 0x32c3) = 0;
  }
  unaff_SI[0x1eff] =
       (unaff_SI[0x1eff] - 0x1a) - (in_DL < pbVar6[in_BX] || (byte)(in_DL - pbVar6[in_BX]) < in_CF);
  iVar4 = 2;
  bVar5 = 0;
  do {
    bVar2 = *unaff_SI;
    *(byte *)(in_BX + 0x32f2) = *(byte *)(in_BX + 0x32f2) | bVar2;
    LOCK();
    bVar3 = ((undefined1 *)&DAT_0000_32f3)[in_BX];
    ((undefined1 *)&DAT_0000_32f3)[in_BX] = bVar2;
    UNLOCK();
    bVar5 = bVar5 | bVar3 ^ bVar2;
    unaff_SI = unaff_SI + 8;
    in_BX = in_BX + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((bVar5 & 8) != 0) {
    out(0x37,6);
    iVar4 = 0x1000;
    do {
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    out(0x37,7);
  }
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


