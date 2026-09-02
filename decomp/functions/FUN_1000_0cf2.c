/* 1000:0cf2 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_0cf2(void)

{
  char in_AL;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  *unaff_DI = in_AL;
  unaff_DI[1] = in_AL;
  unaff_DI[-0x1f] = unaff_DI[-0x1f] | 0x40;
  *(int *)0x3b44 = (int)in_AL;
  return;
}


