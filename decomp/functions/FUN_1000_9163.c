/* 1000:9163 */

char FUN_1000_9163(void)

{
  char in_AL;
  char in_AH;
  char in_CH;
  int unaff_BP;
  undefined2 unaff_SS;
  char in_CF;
  
  *(char *)(unaff_BP + 1) = *(char *)(unaff_BP + 1) + in_AH + in_CF;
  return in_AL + in_CH;
}


