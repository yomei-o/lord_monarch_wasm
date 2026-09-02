/* 1000:6390 */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_6390(void)

{
  byte in_AL;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & in_AL;
  *(char *)(unaff_BP + unaff_SI) =
       *(char *)(unaff_BP + unaff_SI) + in_AL + (unaff_DI < (uint *)*unaff_DI);
  *(char *)(in_BX + 0x816) = *(char *)(in_BX + 0x816) + in_DL;
  return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
}


