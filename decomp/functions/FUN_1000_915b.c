/* 1000:915b */

char FUN_1000_915b(void)

{
  char cVar1;
  char extraout_AH;
  char in_CH;
  int unaff_BP;
  undefined2 unaff_SS;
  char in_CF;
  
  FUN_1000_5d19();
  cVar1 = FUN_1000_8d16();
  *(char *)(unaff_BP + 2) = *(char *)(unaff_BP + 2) + extraout_AH + in_CF;
  return cVar1 + in_CH;
}


