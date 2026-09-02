/* 1000:8f18 */

undefined2 FUN_1000_8f18(void)

{
  char in_DL;
  char *unaff_SI;
  undefined2 unaff_DS;
  byte in_stack_00000000;
  undefined2 in_stack_00000008;
  
  out(0x68,8);
  *unaff_SI = *unaff_SI + in_DL + CARRY1(in_stack_00000000,in_stack_00000000);
  return in_stack_00000008;
}


