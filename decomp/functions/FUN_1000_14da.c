/* 1000:14da */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_14da(void)

{
  byte *pbVar1;
  byte in_DH;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 in_GS;
  
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) ^ in_DH;
  pbVar1 = (byte *)(in_BX + unaff_DI + 0x41f5);
  *pbVar1 = ~*pbVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


