/* 1000:7245 */

int FUN_1000_7245(void)

{
  byte *pbVar1;
  int in_AX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)(in_BX + unaff_SI + 0x53);
  *pbVar1 = *pbVar1 | (byte)in_AX;
  return in_AX + -0x6f0;
}


