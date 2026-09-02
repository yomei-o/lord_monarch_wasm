/* 1000:6808 */

void __cdecl16near FUN_1000_6808(void)

{
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar1;
  
  while( true ) {
    FUN_1000_6c3f();
    FUN_1000_69df();
    uVar1 = in_ZF;
    if ((!(bool)in_CF) && (FUN_1000_6d3a(), uVar1 = in_ZF, !(bool)in_CF)) break;
    FUN_1000_6cf8();
    in_ZF = 1;
    if (!(bool)uVar1) {
      return;
    }
  }
  return;
}


