/* 1000:816c */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_816c(void)

{
  int iVar1;
  byte in_CL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  FUN_1000_174b();
  func_0x0001da08();
  iVar1 = func_0x0001d0ab();
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ in_CL;
  *(undefined2 *)(iVar1 + 2) = 0x817d;
  func_0x0001d10a();
  return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
}


