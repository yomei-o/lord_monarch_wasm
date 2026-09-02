/* 1000:2406 */

int FUN_1000_2406(void)

{
  code *pcVar1;
  byte in_CF;
  char in_OF;
  int in_stack_00000000;
  
  pcVar1 = (code *)swi(4);
  if (in_OF == '\x01') {
    in_stack_00000000 = (*pcVar1)();
  }
  return in_stack_00000000 + 0x7a36 + (uint)in_CF;
}


