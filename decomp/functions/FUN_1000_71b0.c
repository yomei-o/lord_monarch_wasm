/* 1000:71b0 */

uint FUN_1000_71b0(undefined2 param_1,int param_2)

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
  ulong uVar2;
  uint in_stack_00000000;
  
  while( true ) {
    *unaff_SI = *unaff_SI & (byte)in_AX;
    *unaff_SI = *unaff_SI - (char)(in_stack_00000000 >> 8);
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & (byte)in_CX;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    unaff_SI = unaff_SI + -1;
    in_AX = in_stack_00000000;
    in_stack_00000000 = unaff_DI;
  }
  pbVar1 = (byte *)(unaff_BP + param_2 + -0x50);
  *pbVar1 = *pbVar1 ^ (byte)((uint)param_1 >> 8);
  pbVar1 = unaff_SI + -0x3fde;
  *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
  if (*pbVar1 != 0) {
    uVar2 = FUN_1000_71d9();
    unaff_DI = (uint)((int)(uVar2 & 0xff00ff) * (int)((uVar2 & 0xff00ff) >> 0x10)) >> 8;
  }
  return unaff_DI;
}


