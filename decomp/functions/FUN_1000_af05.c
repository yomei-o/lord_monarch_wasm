/* 1000:af05 */

byte __cdecl16near FUN_1000_af05(void)

{
  byte bVar1;
  char cVar2;
  int unaff_DI;
  undefined2 unaff_DS;
  
  cVar2 = '\0';
  if (((3 < (byte)(((undefined *)&DAT_0000_d21e)[unaff_DI] - 1)) &&
      (cVar2 = '\x02', 3 < (byte)(((undefined *)&DAT_0000_d2de)[unaff_DI] - 1))) &&
     (cVar2 = '\x01', 3 < (byte)(((undefined *)&DAT_0000_d27c)[unaff_DI] - 1))) {
    cVar2 = '\x03';
    bVar1 = ((undefined *)&DAT_0000_d280)[unaff_DI] - 1;
    if (3 < bVar1) {
      return bVar1;
    }
  }
  return cVar2 * '\x02';
}


