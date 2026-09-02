/* 1000:c8d8 */

byte __cdecl16near FUN_1000_c8d8(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  bVar2 = *(byte *)0x32ce;
  bVar1 = FUN_1000_c7ce();
  if (!(bool)in_ZF) {
    if ((bVar2 & bVar1) == 0) {
      bVar2 = 0x14;
    }
    else {
      bVar2 = 2;
      if (*(char *)0x32d0 != '\0') {
        return 0;
      }
    }
  }
  *(byte *)0x32d0 = bVar2;
  return bVar1;
}


