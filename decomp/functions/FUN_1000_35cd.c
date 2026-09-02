/* 1000:35cd */

void FUN_1000_35cd(void)

{
  int in_AX;
  int *unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  
  *unaff_SI = *unaff_SI + in_AX + (uint)in_CF;
  return;
}


