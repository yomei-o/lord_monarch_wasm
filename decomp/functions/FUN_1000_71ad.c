/* 1000:71ad */

uint FUN_1000_71ad(void)

{
  byte *pbVar1;
  uint in_AX;
  uint uVar2;
  int in_CX;
  undefined2 in_DX;
  int unaff_BP;
  byte *unaff_SI;
  byte *pbVar3;
  uint unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  ulong uVar4;
  int in_stack_00000000;
  uint uVar5;
  
  uVar2 = in_AX;
  uVar5 = in_AX;
  do {
    pbVar3 = unaff_SI;
    unaff_SI = pbVar3 + -1;
    *unaff_SI = *unaff_SI & (byte)uVar2;
    *unaff_SI = *unaff_SI - (char)(uVar5 >> 8);
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & (byte)in_CX;
    in_CX = in_CX + -1;
    uVar2 = uVar5;
    uVar5 = unaff_DI;
  } while (in_CX != 0);
  pbVar1 = (byte *)(unaff_BP + in_stack_00000000 + -0x50);
  *pbVar1 = *pbVar1 ^ (byte)(in_AX >> 8);
  pbVar1 = pbVar3 + -0x3fdf;
  *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
  if (*pbVar1 != 0) {
    uVar4 = FUN_1000_71d9();
    unaff_DI = (uint)((int)(uVar4 & 0xff00ff) * (int)((uVar4 & 0xff00ff) >> 0x10)) >> 8;
  }
  return unaff_DI;
}


