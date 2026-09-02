/* 1000:0dcd */

void FUN_1000_0dcd(void)

{
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + '\x14';
  return;
}


