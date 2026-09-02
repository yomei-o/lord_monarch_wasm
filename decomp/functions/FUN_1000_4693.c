/* 1000:4693 */

void FUN_1000_4693(void)

{
  uint in_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000008;
  int in_stack_0000000a;
  byte in_stack_00000010;
  
  *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) ^ in_DX;
  FUN_1000_8940();
  func_0x000161bc();
  FUN_1000_6844();
  *(byte *)(in_stack_0000000a + in_stack_00000008) =
       *(byte *)(in_stack_0000000a + in_stack_00000008) & in_stack_00000010;
  thunk_FUN_1000_7b7d();
  return;
}


