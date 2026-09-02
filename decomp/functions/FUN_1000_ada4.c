/* 1000:ada4 */

void __cdecl16near FUN_1000_ada4(void)

{
  int in_BX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_ad80();
  if (!(bool)in_CF) {
    FUN_1000_9b34();
    if (((byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30) &&
       (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0)) {
      return;
    }
  }
  return;
}


