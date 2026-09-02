/* 1000:73ea */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_73ea(void)

{
  uint in_CX;
  uint in_DX;
  uint *in_BX;
  uint uVar1;
  uint uVar2;
  uint unaff_BP;
  uint *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar1 = unaff_SI[0x30] & unaff_BP & in_CX & in_DX;
  uVar2 = ~uVar1;
  in_BX[0x30] = unaff_SI[0x30] & uVar1 | unaff_SI[0x30] & uVar2;
  in_BX[0x20] = unaff_SI[0x20] & uVar1 | unaff_BP & uVar2;
  in_BX[0x10] = unaff_SI[0x10] & uVar1 | in_CX & uVar2;
  *in_BX = *unaff_SI & uVar1 | in_DX & uVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


