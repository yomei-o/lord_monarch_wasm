/* 1000:2983 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000129a6) */

void FUN_1000_2983(void)

{
  char *pcVar1;
  int in_CX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  func_0x0001a844();
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) << ((byte)in_CX & 0x1f);
  pcVar1 = (char *)(in_BX + unaff_DI + 0x30);
  *pcVar1 = *pcVar1 >> ((byte)in_CX & 0x1f);
  do {
    unaff_SI = unaff_SI + 2;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  do {
    *(byte *)(unaff_BP + unaff_DI) = *(byte *)(unaff_BP + unaff_DI) | 0x20;
    *(char *)(unaff_BP + unaff_SI) =
         *(char *)(unaff_BP + unaff_SI) + '.' + (*(byte *)(unaff_SI + 0x5e) < 0x12);
    unaff_SI = unaff_SI + 0x60;
  } while( true );
}


