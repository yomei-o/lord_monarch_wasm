/* 1000:02e8 */

byte FUN_1000_02e8(void)

{
  byte in_AL;
  char in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_DL;
  return in_AL & 0xb9 | 0x58;
}


