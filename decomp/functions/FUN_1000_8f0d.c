/* 1000:8f0d */

undefined2 FUN_1000_8f0d(void)

{
  code *pcVar1;
  char extraout_DL;
  undefined2 in_DX;
  char *unaff_SI;
  undefined2 unaff_DS;
  byte in_stack_00000008;
  undefined2 in_stack_00000010;
  
  in(in_DX);
  pcVar1 = (code *)swi(0x40);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x18);
  (*pcVar1)();
  out(0x68,8);
  *unaff_SI = *unaff_SI + extraout_DL + CARRY1(in_stack_00000008,in_stack_00000008);
  return in_stack_00000010;
}


