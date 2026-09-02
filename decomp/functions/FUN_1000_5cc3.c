/* 1000:5cc3 */

void FUN_1000_5cc3(void)

{
  int iVar1;
  uint in_AX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  out(0xc4,(char)(in_AX & 0xff01));
  iVar1 = unaff_DI * 2;
  *(uint *)(iVar1 + -0x4252) = in_AX & 0xff01;
  *(undefined2 *)(iVar1 + -0x3d82) = 0;
  *(undefined2 *)(iVar1 + 0x1212) = 0x8348;
  *(undefined2 *)(unaff_BP + unaff_SI) = 0xc480;
  func_0x0001b63b();
  return;
}


