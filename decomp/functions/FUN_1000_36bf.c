/* 1000:36bf */

void FUN_1000_36bf(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  int in_BX;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined4 uVar2;
  
  uVar2 = func_0x0001e104();
  bVar1 = ((byte)uVar2 | 0x55) - 0x20;
  if (0xf < bVar1) {
    *(undefined2 *)((int)unaff_DI + (in_BX - (int)((ulong)uVar2 >> 0x10)) + 0x12a7) = param_2;
    return;
  }
  *unaff_DI = CONCAT11((char)((ulong)uVar2 >> 8),bVar1);
  *(byte *)(unaff_DI + 1) = bVar1;
  FUN_1000_8f07();
  return;
}


