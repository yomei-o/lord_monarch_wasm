/* 1000:77f2 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_77f2(void)

{
  byte in_AH;
  byte extraout_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & in_AH;
  func_0x00018422();
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | extraout_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


