/* 1000:5ebc */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_5ebc(void)

{
  byte *pbVar1;
  byte in_AL;
  byte in_DH;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_AF;
  
  pbVar1 = (byte *)(in_BX + unaff_SI + -0x19fa);
  *pbVar1 = *pbVar1 | in_DH;
  out(0x37,in_AL + (9 < (in_AL & 0xf) | in_AF) * '\x06' & 0xf | 0x70);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


