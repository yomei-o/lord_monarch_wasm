/* 1000:4980 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_4980(void)

{
  char in_BL;
  undefined2 unaff_DS;
  
  *(char *)0xd88e = *(char *)0xd88e + in_BL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


