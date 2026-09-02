/* 1000:c231 */

uint __cdecl16near FUN_1000_c231(void)

{
  uint in_AX;
  int iVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = (in_AX & 0xff) * 0x80;
  *(undefined2 *)((undefined *)&DAT_0000_247e + iVar1) = 0;
  *(undefined2 *)((undefined *)&DAT_0000_247c + iVar1) = 1;
  ((undefined *)&DAT_0000_2400)[iVar1] = *(byte *)(unaff_SI + 1) >> 1;
  return in_AX;
}


