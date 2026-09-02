/* 1000:7252 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_7252(void)

{
  int in_BX;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  int iStack_2;
  
  *(int *)((int)&iStack_2 + (-(uint)in_CF - *(int *)(in_BX + unaff_SI))) = in_BX;
  return;
}


