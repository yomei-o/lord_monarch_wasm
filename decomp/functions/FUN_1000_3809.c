/* 1000:3809 */

void FUN_1000_3809(void)

{
  byte in_AL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ in_AL;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


