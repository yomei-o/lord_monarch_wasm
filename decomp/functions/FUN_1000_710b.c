/* 1000:710b */

void FUN_1000_710b(void)

{
  char in_AL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  char in_CF;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + in_AL + in_CF;
  return;
}


