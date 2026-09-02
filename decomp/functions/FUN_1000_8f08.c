/* 1000:8f08 */

undefined2 FUN_1000_8f08(void)

{
  code *pcVar1;
  char extraout_DL;
  char *unaff_SI;
  undefined2 unaff_DS;
  byte in_stack_00000000;
  undefined2 in_stack_00000008;
  
  pcVar1 = (code *)swi(0x18);
  (*pcVar1)();
  out(0x68,8);
  *unaff_SI = *unaff_SI + extraout_DL + CARRY1(in_stack_00000000,in_stack_00000000);
  return in_stack_00000008;
}


