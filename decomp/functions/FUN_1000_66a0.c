/* 1000:66a0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_66a0(void)

{
  undefined2 uVar1;
  uint in_AX;
  byte in_CL;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(char *)0xef81 = *(char *)0xef81 + (in_CL ^ (byte)*(undefined2 *)(unaff_BP + -0x10));
  *(uint *)(unaff_BP + unaff_SI) = *(uint *)(unaff_BP + unaff_SI) ^ in_AX;
  uVar1 = in(in_DX);
  *unaff_DI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


