/* 1000:494f */

undefined4 FUN_1000_494f(void)

{
  byte *pbVar1;
  byte in_DL;
  int *in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  int in_stack_00000000;
  undefined2 in_stack_00000012;
  undefined2 in_stack_00000016;
  
  pbVar1 = (byte *)((int)in_BX + unaff_SI + 0x3a);
  *pbVar1 = *pbVar1 & in_DL;
  *in_BX = *in_BX + in_stack_00000000;
  func_0x0001fb4e();
  func_0x0001464d();
  return CONCAT22(in_stack_00000012,in_stack_00000016);
}


