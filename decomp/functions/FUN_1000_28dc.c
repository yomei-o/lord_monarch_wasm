/* 1000:28dc */

void FUN_1000_28dc(void)

{
  byte bVar1;
  int in_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  bVar1 = unaff_SI[2];
  *(uint *)(unaff_SI + in_BX + -0x56) = *(int *)(unaff_SI + in_BX + -0x56) + in_DX + (uint)in_CF;
  *unaff_DI = bVar1;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & bVar1;
  *unaff_SI = (char)in_BX + '\x01';
  return;
}


