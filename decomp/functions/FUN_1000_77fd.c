/* 1000:77fd */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_77fd(void)

{
  byte extraout_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  func_0x00018422();
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | extraout_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


