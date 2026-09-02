/* 1000:c921 */

undefined2 __cdecl16near FUN_1000_c921(void)

{
  undefined2 in_AX;
  uint uVar1;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x32d4 = 0xf0;
  do {
    uVar1 = FUN_1000_c8d8();
    if ((uVar1 & 0x60) != 0) {
      FUN_1000_0d12(uVar1);
      break;
    }
  } while (*(char *)0x32d4 != '\0');
  *(undefined1 *)0x32d4 = 0;
  return in_AX;
}


