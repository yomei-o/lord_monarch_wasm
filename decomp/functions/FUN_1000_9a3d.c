/* 1000:9a3d */

void FUN_1000_9a3d(void)

{
  byte in_CH;
  int in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  *(byte *)(in_BX + unaff_DI) = *(byte *)(in_BX + unaff_DI) & in_CH;
  return;
}


