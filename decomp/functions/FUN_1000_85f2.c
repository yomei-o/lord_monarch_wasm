/* 1000:85f2 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_85f2(void)

{
  char in_AL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  char in_CF;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + in_AL + in_CF;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


