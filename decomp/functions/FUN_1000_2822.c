/* 1000:2822 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_2822(void)

{
  byte bVar1;
  char extraout_AH;
  byte extraout_AH_00;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  longdouble in_ST0;
  
  *(long *)(unaff_BP + unaff_SI + -0x61bc) = (long)in_ST0;
  bVar1 = func_0x00013085();
  *(byte *)0xe8fe = *(byte *)0xe8fe & bVar1;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + extraout_AH;
  bVar1 = FUN_1000_4083();
  *(byte *)0xe860 = *(byte *)0xe860 & bVar1;
  *(byte *)(in_BX + unaff_ES) = *(byte *)(in_BX + unaff_ES) & extraout_AH_00;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


