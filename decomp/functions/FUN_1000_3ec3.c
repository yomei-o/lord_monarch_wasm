/* 1000:3ec3 */

undefined2 FUN_1000_3ec3(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  byte *pbVar1;
  undefined1 in_AL;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI + 0x74);
  *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
  *(uint *)(unaff_BP + unaff_SI) = *(uint *)(unaff_BP + unaff_SI) | unaff_DI + 1U;
  out(in_DX,in_AL);
  FUN_1000_3efd();
  *(undefined1 *)0x328a = *(undefined1 *)0x3bee;
  FUN_1000_895a();
  FUN_1000_63f1();
  func_0x000178af();
  FUN_1000_63f1();
  func_0x000178af();
  return param_3;
}


