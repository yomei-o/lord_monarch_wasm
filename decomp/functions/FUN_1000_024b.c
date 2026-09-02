/* 1000:024b */

byte __cdecl16near FUN_1000_024b(void)

{
  byte bVar1;
  
  out(0x7fdf,0x93);
  out(0x7fdf,0x92);
  out(0x7fdd,0);
  out(0xbfdb,1);
  bVar1 = in(10);
  out(10,bVar1 & 0xdf);
  return bVar1 & 0xdf;
}


