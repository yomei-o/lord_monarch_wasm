/* 1000:c25c */

uint __cdecl16near FUN_1000_c25c(void)

{
  byte bVar1;
  uint in_AX;
  int iVar2;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar2 = (in_AX & 0xff) * 0x80;
  *(undefined2 *)((undefined *)&DAT_0000_247e + iVar2) = 0;
  *(undefined2 *)((undefined *)&DAT_0000_247c + iVar2) = 2;
  bVar1 = *(byte *)(unaff_SI + 1) >> 1;
  ((undefined *)&DAT_0000_2400)[iVar2] = bVar1 << 2 | bVar1;
  return in_AX;
}


