/* 1000:4d4a */

undefined2 __cdecl16near FUN_1000_4d4a(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if (*(char *)0x328a != -1) {
    if (*(char *)0x328a == *(char *)0x3bee) {
      return in_AX;
    }
    FUN_1000_4d86();
  }
  *(undefined1 *)0x328a = *(undefined1 *)0x3bee;
  FUN_1000_97e3();
  FUN_1000_727a();
  FUN_1000_8738();
  FUN_1000_727a();
  FUN_1000_8738();
  return in_AX;
}


