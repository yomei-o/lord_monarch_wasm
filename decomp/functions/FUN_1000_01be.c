/* 1000:01be */

byte __cdecl16near FUN_1000_01be(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte in_AL;
  char cVar3;
  byte bVar4;
  undefined *puVar5;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 in_BX;
  undefined2 *puVar6;
  int unaff_BP;
  undefined2 *unaff_SI;
  int unaff_DI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  
  pbVar1 = (byte *)((int)unaff_SI + unaff_BP + 0x72);
  bVar4 = (byte)((uint)in_DX >> 8);
  pbVar2 = (byte *)(unaff_BP + unaff_DI + 0x2c2);
  bVar7 = CARRY1(in_AL,*pbVar2) || CARRY1(in_AL + *pbVar2,bVar4 < *pbVar1);
  out(CONCAT11(bVar4 - *pbVar1,(char)in_DX),0xbf);
  FUN_1000_73ea();
  if ((!bVar7) && (cVar3 = in(extraout_DX), cVar3 == -0x41)) {
    *(undefined2 *)0x3b3a = 1;
    out(0x188,0xe);
    cVar3 = in(0x18a);
    puVar6 = (undefined2 *)0x50;
    if (-1 < cVar3) {
      pbVar1 = (byte *)0x3b3c;
      *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
      puVar6 = (undefined2 *)0x54;
    }
    *puVar6 = 0xd52;
    puVar6[1] = unaff_CS;
    FUN_1000_14da();
    FUN_1000_14bb();
    bVar4 = in(10);
    out(10,bVar4 & *(byte *)0x3b3c);
    return bVar4 & *(byte *)0x3b3c;
  }
  bVar4 = (byte)*unaff_SI ^ 0x10;
  pbVar1 = (byte *)((int)unaff_SI + CONCAT11((char)((uint)in_BX >> 8) + bVar4,(char)in_BX) + 2);
  *pbVar1 = *pbVar1 & bVar4;
  out(0x77,0x30);
  puVar5 = (undefined *)&DAT_0000_9fe8;
  if ((*(byte *)0x501 & 0x80) != 0) {
    puVar5 = (undefined *)&DAT_0000_81e8;
  }
  *(undefined2 *)0x3b4a = puVar5;
  out(0x71,(char)puVar5);
  out(0x71,(char)((uint)puVar5 >> 8));
  bVar4 = in(2);
  out(2,bVar4 & 0xfe);
  return bVar4 & 0xfe;
}


