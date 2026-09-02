/* 1000:77e5 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_77e5(void)

{
  undefined2 in_AX;
  byte in_CL;
  byte extraout_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) & in_CL;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & (byte)((uint)in_AX >> 8);
  func_0x00018422();
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | extraout_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


