/* 1000:3532 */

void FUN_1000_3532(void)

{
  byte *pbVar1;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  
  pbVar1 = (byte *)(in_BX + unaff_SI + 0x5b);
  *pbVar1 = in_CF | *pbVar1 << 1;
  return;
}


