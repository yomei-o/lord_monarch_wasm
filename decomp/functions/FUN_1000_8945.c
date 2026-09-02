/* 1000:8945 */

void FUN_1000_8945(void)

{
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  char in_CF;
  
  *(int *)0x4402 = in_BX;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + '\x1e' + in_CF;
  return;
}


