/* 1000:369b */

void FUN_1000_369b(void)

{
  char cVar1;
  byte bVar2;
  int in_BX;
  int iVar3;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar4;
  undefined4 uVar5;
  undefined2 in_stack_00000000;
  
  cVar4 = '\0';
  cVar1 = FUN_1000_8f5c();
  in(0x22);
  iVar3 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)(in_BX + unaff_SI + 0x293e));
  uVar5 = func_0x0001e104(cVar1 + *(char *)(unaff_BP + unaff_SI + 4) + cVar4 ^
                          *(byte *)(unaff_BP + unaff_SI));
  bVar2 = ((byte)uVar5 | 0x55) - 0x20;
  if (0xf < bVar2) {
    *(undefined2 *)((int)unaff_DI + (iVar3 - (int)((ulong)uVar5 >> 0x10)) + 0x12a7) =
         in_stack_00000000;
    return;
  }
  *unaff_DI = CONCAT11((char)((ulong)uVar5 >> 8),bVar2);
  *(byte *)(unaff_DI + 1) = bVar2;
  FUN_1000_8f07();
  return;
}


