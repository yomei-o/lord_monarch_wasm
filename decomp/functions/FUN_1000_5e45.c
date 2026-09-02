/* 1000:5e45 */

undefined4 FUN_1000_5e45(void)

{
  undefined2 uVar1;
  byte bVar2;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  uVar1 = FUN_1000_5e86();
  out(0x188,(char)uVar1);
  bVar2 = (byte)((uint)uVar1 >> 8);
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ bVar2;
  out(0x18a,bVar2);
  return CONCAT22(in_DX,unaff_ES);
}


