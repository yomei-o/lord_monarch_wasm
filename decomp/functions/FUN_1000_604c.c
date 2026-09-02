/* 1000:604c */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_604c(void)

{
  byte *pbVar1;
  char *pcVar2;
  char in_AL;
  byte in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)(unaff_BP + unaff_DI + -0x17fc);
  *pbVar1 = *pbVar1 | in_CL;
  pcVar2 = (char *)(in_BX + unaff_SI + 4);
  *pcVar2 = *pcVar2 - (in_AL + -0x30);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


