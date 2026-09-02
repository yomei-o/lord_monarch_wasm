/* 1000:93bb */

void FUN_1000_93bb(void)

{
  byte *pbVar1;
  byte in_DL;
  int in_BX;
  undefined2 *unaff_SI;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)((int)unaff_SI + in_BX + -0x7d);
  *pbVar1 = *pbVar1 & in_DL;
  *unaff_SI = 0xdce2;
  func_0x000160cb();
  FUN_1000_8c11();
  FUN_1000_8d16();
  FUN_1000_8cd0();
  FUN_1000_38de();
  func_0x000138c4();
  func_0x00013ae3();
  FUN_1000_602a();
  return;
}


