/* 1000:669c */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_669c(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint in_AX;
  byte in_CL;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  uVar2 = *(uint *)(unaff_BP + unaff_SI);
  *(char *)0xef81 = *(char *)0xef81 + (in_CL ^ (byte)*(undefined2 *)(unaff_BP + -0x10));
  *(uint *)(unaff_BP + unaff_SI) = *(uint *)(unaff_BP + unaff_SI) ^ in_AX ^ uVar2;
  uVar1 = in(in_DX);
  *unaff_DI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


