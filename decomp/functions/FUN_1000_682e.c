/* 1000:682e */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_682e(void)

{
  byte *pbVar1;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI);
  *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


