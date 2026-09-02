/* 1000:6986 */

char FUN_1000_6986(void)

{
  char *pcVar1;
  char in_AL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_SS;
  
  pcVar1 = (char *)(in_BX + unaff_SI + 0x60);
  *pcVar1 = *pcVar1 + (char)in_BX;
  return in_AL + -0x18;
}


