/* 1000:3b86 */

undefined4 FUN_1000_3b86(void)

{
  byte bVar1;
  uint in_AX;
  uint uVar2;
  byte in_CL;
  byte in_DL;
  byte extraout_DL;
  byte *in_BX;
  byte *unaff_DI;
  undefined2 unaff_DS;
  byte bVar3;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  uVar2 = in_AX & 0x443a;
  *in_BX = *in_BX ^ in_CL;
  bVar1 = (byte)uVar2;
  bVar3 = bVar1 < 10;
  if ((((bVar1 == 10) || (bVar3 = bVar1 < 7, bVar1 == 7)) || (bVar3 = bVar1 < 9, bVar1 == 9)) ||
     ((bVar3 = bVar1 < 0xb, bVar1 == 0xb || (bVar3 = bVar1 < 6, bVar1 == 6)))) {
    uVar2 = func_0x0001b56d();
    in_DL = extraout_DL;
  }
  (in_BX + (int)unaff_DI)[-0x3d] =
       ((in_BX + (int)unaff_DI)[-0x3d] - (char)(uVar2 >> 8)) -
       (in_DL < *unaff_DI || (byte)(in_DL - *unaff_DI) < bVar3);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


