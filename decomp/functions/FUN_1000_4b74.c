/* 1000:4b74 */

void FUN_1000_4b74(void)

{
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  char in_CF;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)in_BX + in_CF;
  return;
}


