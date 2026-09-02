/* 1000:8d9b */

undefined4 FUN_1000_8d9b(void)

{
  byte *pbVar1;
  byte bVar2;
  uint in_AX;
  int in_DX;
  byte *unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  do {
    in_DX = in_DX * 10 + in_AX;
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    bVar2 = *pbVar1 - 0x30;
    in_AX = (uint)bVar2;
    if (*pbVar1 < 0x30) break;
  } while (bVar2 < 10);
  return CONCAT22(in_stack_00000000,in_DX);
}


