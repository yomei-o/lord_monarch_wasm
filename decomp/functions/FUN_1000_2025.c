/* 1000:2025 */

void FUN_1000_2025(void)

{
  undefined2 in_AX;
  byte in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  if (0x19 < in_DL) {
    in_AX = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + '\x01');
  }
  *(undefined2 *)0x3be6 = in_AX;
  FUN_1000_503d();
  FUN_1000_772e();
  FUN_1000_6d3d();
  func_0x00017730();
  func_0x00016d3f();
  *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) << 8;
  FUN_1000_774c();
  func_0x0001c0c0();
  func_0x00012d1d();
  return;
}


