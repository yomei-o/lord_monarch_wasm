/* 1000:4af4 */

void FUN_1000_4af4(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int unaff_SI;
  undefined2 *puVar4;
  undefined2 uVar5;
  int unaff_DI;
  undefined2 unaff_DS;
  
  uVar3 = *(uint *)(unaff_SI + 2);
  puVar4 = (undefined2 *)(unaff_SI + 6);
  bVar1 = *(byte *)(unaff_DI + 1);
  *(int *)0xc54c = bVar1 + 1;
  if (-1 < (char)uVar3) {
    puVar4 = puVar4 + bVar1;
  }
  FUN_1000_91ea();
  uVar2 = uVar3 & 0xff;
  if (-1 < (char)(byte)uVar3) {
    do {
      puVar4 = puVar4 + 1;
      FUN_1000_759b(puVar4);
      *(int *)0xc54c = *(int *)0xc54c + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    FUN_1000_9239();
    return;
  }
  uVar5 = *puVar4;
  uVar3 = (uint)((byte)uVar3 & 0x7f);
  do {
    FUN_1000_759b(uVar5);
    *(int *)0xc54c = *(int *)0xc54c + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  FUN_1000_9239();
  return;
}


