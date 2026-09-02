/* 1000:0250 */

byte __cdecl16near FUN_1000_0250(void)

{
  undefined1 in_AL;
  byte bVar1;
  undefined2 in_DX;
  int in_BX;
  undefined2 unaff_DS;
  unkbyte10 in_ST0;
  
  *(unkbyte10 *)(in_BX + 0x1b0) = in_ST0;
  out(in_DX,in_AL);
  bVar1 = in(10);
  out(10,bVar1 & 0xdf);
  return bVar1 & 0xdf;
}


