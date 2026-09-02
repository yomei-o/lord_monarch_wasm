/* 1000:71c4 */

void FUN_1000_71c4(void)

{
  byte *pbVar1;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)(unaff_SI + -0x3fde);
  *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
  if (*pbVar1 != 0) {
    FUN_1000_71d9();
  }
  return;
}


