/* 1000:43d0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_43d0(void)

{
  bool in_CF;
  
  if (!in_CF) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


