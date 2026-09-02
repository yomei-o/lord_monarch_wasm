/* 1000:3806 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_3806(void)

{
  byte in_AL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  char in_CF;
  int in_stack_00000000;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + in_AL + in_CF;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ in_AL;
  *(int *)(in_stack_00000000 + -2) = unaff_BP;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


