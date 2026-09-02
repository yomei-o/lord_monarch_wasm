/* 1000:a393 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_a393(void)

{
  char cVar1;
  byte in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  
  func_0x000159fa();
  cVar1 = func_0x0001cc69();
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + cVar1 + in_CF;
  *unaff_DI = cVar1;
  unaff_DI[1] = cVar1;
  cVar1 = '\0';
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) & in_CL;
  func_0x0001f44b();
  *(char *)(unaff_SI + 0x5011) = *(char *)(unaff_SI + 0x5011) + (char)in_BX + cVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


