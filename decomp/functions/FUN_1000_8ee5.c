/* 1000:8ee5 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_8ee5(void)

{
  byte in_DH;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  *unaff_SI = *unaff_SI ^ in_DH;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


