/* 1000:0cca */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_0cca(void)

{
  char *pcVar1;
  char in_AL;
  char in_CL;
  undefined2 in_BX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  
  if (*(int *)(CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + ((in_AL + -1) - in_CF)) + 0x35e2) ==
      0) {
    return;
  }
  *(int *)(unaff_BP + unaff_DI) = *(int *)(unaff_BP + unaff_DI) - (int)&stack0x0000;
  pcVar1 = (char *)(unaff_BP + unaff_DI + -0x7402);
  *pcVar1 = *pcVar1 - in_CL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


