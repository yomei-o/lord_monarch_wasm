/* 1000:5cc6 */

void FUN_1000_5cc6(void)

{
  int iVar1;
  undefined2 in_AX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  out(0xc4,(char)in_AX);
  iVar1 = unaff_DI * 2;
  *(undefined2 *)(iVar1 + -0x4252) = in_AX;
  *(undefined2 *)(iVar1 + -0x3d82) = 0;
  *(undefined2 *)(iVar1 + 0x1212) = 0x8348;
  *(undefined2 *)(unaff_BP + unaff_SI) = 0xc480;
  func_0x0001b63b();
  return;
}


