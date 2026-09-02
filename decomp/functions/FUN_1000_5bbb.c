/* 1000:5bbb */

char FUN_1000_5bbb(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar3;
  char in_AL;
  byte bVar4;
  undefined2 in_CX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ (byte)((uint)in_CX >> 8);
  pbVar1 = unaff_SI;
  bVar2 = *pbVar1;
  bVar4 = (byte)in_CX;
  *pbVar1 = *pbVar1 + bVar4;
  if (!CARRY1(bVar2,bVar4)) {
    *(int *)(in_BX + -0x3d82) = *(int *)(in_BX + -0x3d82) + 1;
  }
  uVar3 = *(undefined2 *)(unaff_SI + in_BX);
  *unaff_DI = in_AL;
  return in_AL + unaff_DI[unaff_BP + 0x7ec0] + CARRY1((byte)((uint)uVar3 >> 8),bVar4);
}


