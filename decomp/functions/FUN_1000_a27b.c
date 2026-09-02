/* 1000:a27b */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_a27b(void)

{
  byte bVar1;
  undefined2 unaff_DS;
  
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


