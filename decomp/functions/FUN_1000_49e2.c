/* 1000:49e2 */

void FUN_1000_49e2(void)

{
  char *pcVar1;
  byte in_AL;
  int in_CX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined1 in_stack_00000000;
  undefined2 uStack0004;
  
  if (in_CX == 1 || (in_AL | 0x5b) != 0) {
    pcVar1 = (char *)(unaff_BP + unaff_SI + 6);
    *pcVar1 = *pcVar1 << 1;
    LOCK();
    *(undefined1 *)(unaff_BP + unaff_SI + -0x7c) = in_stack_00000000;
    UNLOCK();
    uStack0004 = 0x49fb;
    FUN_1000_4a0b();
    FUN_1000_3884();
    return;
  }
  return;
}


