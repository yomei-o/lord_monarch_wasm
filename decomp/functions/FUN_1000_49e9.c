/* 1000:49e9 */

void FUN_1000_49e9(void)

{
  undefined1 in_BL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 uStack0002;
  
  LOCK();
  *(undefined1 *)(unaff_BP + unaff_SI + -0x7c) = in_BL;
  UNLOCK();
  uStack0002 = 0x49fb;
  FUN_1000_4a0b();
  FUN_1000_3884();
  return;
}


