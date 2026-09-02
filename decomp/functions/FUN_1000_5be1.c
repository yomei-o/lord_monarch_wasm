/* 1000:5be1 */

void FUN_1000_5be1(void)

{
  char in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  char in_CF;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_DL + in_CF;
  *(undefined2 *)(in_BX + -0x3d82) = 0xffff;
  return;
}


