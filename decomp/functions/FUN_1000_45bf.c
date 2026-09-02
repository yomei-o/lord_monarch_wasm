/* 1000:45bf */

undefined4 FUN_1000_45bf(void)

{
  undefined1 in_AL;
  undefined2 in_DX;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  out(0x32,in_AL);
  *(undefined2 *)0x32e8 = in_DX;
  func_0x0001fc0d();
  return CONCAT22(unaff_SS,(uint)*(byte *)0x3298);
}


