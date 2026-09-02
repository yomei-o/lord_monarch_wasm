/* 1000:6c57 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_6c57(void)

{
  undefined2 *in_BX;
  undefined2 unaff_BP;
  undefined2 unaff_DS;
  
  *in_BX = unaff_BP;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


