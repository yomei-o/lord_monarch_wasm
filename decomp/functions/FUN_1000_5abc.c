/* 1000:5abc */

undefined4 FUN_1000_5abc(void)

{
  byte in_AL;
  byte in_DL;
  undefined2 in_stack_00000000;
  
  return CONCAT22(in_stack_00000000,(uint)(byte)((in_AL >> 4) * '\n' + (in_DL & 0xf)));
}


