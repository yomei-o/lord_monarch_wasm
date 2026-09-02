/* 1000:2828 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_2828(void)

{
  byte in_AH;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | in_AH;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


