/* 1000:3682 */

/* WARNING: Instruction at (ram,0x000136b7) overlaps instruction at (ram,0x000136b5)
    */

void FUN_1000_3682(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  byte bVar1;
  int in_BX;
  int iVar2;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool in_ZF;
  undefined4 uVar3;
  
  if (in_ZF) {
    in(0x42);
  }
  iVar2 = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX ^ *(byte *)((int)unaff_DI + in_BX + -0x7e));
  FUN_1000_98d3();
  FUN_1000_8f5c();
  in(0x22);
  iVar2 = CONCAT11((char)((uint)iVar2 >> 8),(char)iVar2 + *(char *)(iVar2 + unaff_SI + 0x293e));
  uVar3 = func_0x0001e104();
  bVar1 = ((byte)uVar3 | 0x55) - 0x20;
  if (0xf < bVar1) {
    *(undefined2 *)((int)unaff_DI + (iVar2 - (int)((ulong)uVar3 >> 0x10)) + 0x12a7) = param_3;
    return;
  }
  *unaff_DI = CONCAT11((char)((ulong)uVar3 >> 8),bVar1);
  *(byte *)(unaff_DI + 1) = bVar1;
  FUN_1000_8f07();
  return;
}


