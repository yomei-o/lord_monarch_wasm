/* 1000:0f7e */

uint FUN_1000_0f7e(void)

{
  uint uVar1;
  uint in_AX;
  undefined1 in_DL;
  undefined1 in_DH;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(in_BX + unaff_SI + 0x7fe2);
  *(undefined1 *)(unaff_SI + 0xc) = in_DL;
  *(undefined1 *)(unaff_SI + 0xd) = in_DH;
  return in_AX | uVar1;
}


