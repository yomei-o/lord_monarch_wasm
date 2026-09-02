/* 1000:6c53 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_6c53(void)

{
  char *pcVar1;
  char in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (in_BX == 1) {
    *(int *)0x0 = unaff_BP;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar1 = (char *)(unaff_BP + unaff_DI + 0x10);
  *pcVar1 = *pcVar1 + in_CL;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


