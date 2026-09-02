/* 1000:977d */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_977d(void)

{
  char extraout_DL;
  char *unaff_DI;
  undefined2 unaff_DS;
  char in_CF;
  
  FUN_1000_8add();
  *unaff_DI = *unaff_DI + extraout_DL + in_CF;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


