/* 1000:8d2e */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_8d2e(void)

{
  byte in_AH;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ in_AH;
  FUN_1000_8da3(0xff9a);
  FUN_1000_8da3();
  FUN_1000_8da3();
  func_0x0001e1a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


