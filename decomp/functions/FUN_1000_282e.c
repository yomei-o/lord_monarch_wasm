/* 1000:282e */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_282e(void)

{
  byte bVar1;
  char in_AH;
  byte extraout_AH;
  int in_BX;
  int unaff_SI;
  int unaff_ES;
  undefined2 unaff_DS;
  char in_CF;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_AH + in_CF;
  bVar1 = FUN_1000_4083();
  *(byte *)0xe860 = *(byte *)0xe860 & bVar1;
  *(byte *)(in_BX + unaff_ES) = *(byte *)(in_BX + unaff_ES) & extraout_AH;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


