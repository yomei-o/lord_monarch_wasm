/* 1000:a98d */

void __cdecl16near FUN_1000_a98d(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar4;
  
  if (((byte)(((undefined *)&DAT_0000_d27e)[unaff_DI] - 0x14) < 4) ||
     ((char)(((undefined *)&DAT_0000_d27e)[unaff_DI] + -8) == *(char *)(unaff_SI + 0xc))) {
    bVar4 = false;
    FUN_1000_abc7();
    if (!bVar4) {
      return;
    }
  }
  uVar3 = (*(uint *)(unaff_SI + 6) >> 8) + 1;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - uVar3;
  if (uVar3 <= uVar2 && *puVar1 != 0) {
    return;
  }
  FUN_1000_4924();
  return;
}


