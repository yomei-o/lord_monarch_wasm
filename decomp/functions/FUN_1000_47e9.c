/* 1000:47e9 */

undefined4 __cdecl16near FUN_1000_47e9(void)

{
  undefined1 uVar1;
  int in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  FUN_1000_4814();
  *(undefined2 *)(unaff_SI + 8) = *(undefined2 *)(in_AX + 2);
  FUN_1000_b78c();
  uVar1 = FUN_1000_c0bd();
  if (!(bool)in_ZF) {
    *(undefined1 *)(unaff_SI + 0xb) = uVar1;
    *(undefined1 *)(unaff_SI + 10) = 2;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}


