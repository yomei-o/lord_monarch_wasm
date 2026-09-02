/* 1000:71b3 */

uint FUN_1000_71b3(int param_1)

{
  byte *pbVar1;
  uint in_AX;
  int in_CX;
  undefined2 in_DX;
  int unaff_BP;
  byte *unaff_SI;
  uint unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  ulong uVar2;
  undefined2 in_stack_00000000;
  
  while( true ) {
    *unaff_SI = (*unaff_SI - (char)(in_AX >> 8)) - in_CF;
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & (byte)in_CX;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    unaff_SI = unaff_SI + -1;
    in_CF = '\0';
    *unaff_SI = *unaff_SI & (byte)in_AX;
    in_AX = unaff_DI;
  }
  pbVar1 = (byte *)(unaff_BP + param_1 + -0x50);
  *pbVar1 = *pbVar1 ^ (byte)((uint)in_stack_00000000 >> 8);
  pbVar1 = unaff_SI + -0x3fde;
  *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
  if (*pbVar1 != 0) {
    uVar2 = FUN_1000_71d9();
    unaff_DI = (uint)((int)(uVar2 & 0xff00ff) * (int)((uVar2 & 0xff00ff) >> 0x10)) >> 8;
  }
  return unaff_DI;
}


