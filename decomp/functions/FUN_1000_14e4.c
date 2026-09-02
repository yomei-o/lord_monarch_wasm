/* 1000:14e4 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_14e4(void)

{
  int in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  ((undefined *)&DAT_0000_41f6)[in_BX + unaff_DI] = ~((undefined *)&DAT_0000_41f6)[in_BX + unaff_DI]
  ;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


