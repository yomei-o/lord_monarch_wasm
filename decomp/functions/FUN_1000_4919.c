/* 1000:4919 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_4919(void)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char in_DL;
  byte in_BL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  
  LOCK();
  piVar2 = (int *)(unaff_BP + unaff_SI + 0x503a);
  iVar3 = *piVar2;
  *piVar2 = unaff_BP;
  UNLOCK();
  pcVar1 = (char *)(iVar3 + -0x4e);
  *pcVar1 = (*pcVar1 - in_DL) - in_CF;
  *(byte *)0x1e34 = *(byte *)0x1e34 ^ in_BL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


