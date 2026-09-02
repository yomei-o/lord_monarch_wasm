/* 1000:7036 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_7036(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  out(in_DX,in_AX);
  *(int *)(unaff_SI + 0x1a) = unaff_DI;
  *(undefined1 *)(unaff_BP + unaff_DI) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


