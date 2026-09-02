/* 1000:71bf */

void FUN_1000_71bf(void)

{
  byte *pbVar1;
  byte in_CH;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  pbVar1 = (byte *)(unaff_BP + in_stack_00000000 + -0x50);
  *pbVar1 = *pbVar1 ^ in_CH;
  pbVar1 = (byte *)(unaff_SI + -0x3fde);
  *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
  if (*pbVar1 != 0) {
    FUN_1000_71d9();
  }
  return;
}


