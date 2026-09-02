/* 1000:0dd7 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_0dd7(void)

{
  undefined1 in_AL;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  
  *unaff_DI = in_AL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


