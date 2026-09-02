/* 1000:6c94 */

void FUN_1000_6c94(void)

{
  char cVar1;
  uint in_DX;
  char *in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  char cVar2;
  
  *(uint *)(unaff_DI + 0x55) = *(uint *)(unaff_DI + 0x55) ^ in_DX;
  cVar2 = '\0';
  cVar1 = FUN_1000_9ea6();
  LOCK();
  *in_BX = (*in_BX - cVar1) - cVar2;
  UNLOCK();
  return;
}


