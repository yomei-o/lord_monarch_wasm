/* 1000:28d7 */

void FUN_1000_28d7(void)

{
  byte bVar1;
  byte in_CL;
  int in_DX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  
  unaff_SI[in_BX + 0x10] = unaff_SI[in_BX + 0x10] + (char)((uint)in_DX >> 8) + in_CF;
  *unaff_SI = *unaff_SI | in_CL;
  bVar1 = unaff_SI[2];
  *(int *)(unaff_SI + in_BX + -0x56) = *(int *)(unaff_SI + in_BX + -0x56) + in_DX;
  *unaff_DI = bVar1;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & bVar1;
  *unaff_SI = (char)in_BX + 1;
  return;
}


