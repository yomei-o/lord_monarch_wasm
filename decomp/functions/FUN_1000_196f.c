/* 1000:196f */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_196f(void)

{
  undefined2 in_AX;
  byte in_CL;
  undefined1 in_CH;
  undefined2 unaff_DS;
  
  out(0x30,in_AX);
  *(undefined1 *)(in_CL + 0x14) = in_CH;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


