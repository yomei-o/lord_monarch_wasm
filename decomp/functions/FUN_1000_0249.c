/* 1000:0249 */

byte FUN_1000_0249(void)

{
  byte bVar1;
  
  out(0x7fdd,0);
  out(0xbfdb,1);
  bVar1 = in(10);
  out(10,bVar1 & 0xdf);
  return bVar1 & 0xdf;
}


