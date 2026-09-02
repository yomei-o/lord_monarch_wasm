/* 1000:49c4 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_49c4(void)

{
  byte in_BL;
  undefined2 unaff_DS;
  
  *(byte *)0x1e34 = *(byte *)0x1e34 ^ in_BL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


