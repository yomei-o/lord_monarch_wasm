/* 1000:0820 */

undefined4 FUN_1000_0820(void)

{
  int in_AX;
  char in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_DL;
  do {
    in_AX = in_AX + -1;
  } while (in_AX != 0);
  out(0x37,7);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


