/* 1000:49bb */

void FUN_1000_49bb(void)

{
  byte bVar1;
  byte bVar4;
  uint uVar2;
  uint uVar3;
  int unaff_SI;
  undefined2 *puVar5;
  undefined2 uVar6;
  char *unaff_DI;
  undefined2 unaff_DS;
  
  bVar4 = *(char *)(unaff_SI + 4) - 1;
  bVar1 = (byte)*(undefined2 *)unaff_DI;
  if (bVar4 < bVar1) {
    unaff_DI[0] = '\0';
    unaff_DI[1] = '\0';
  }
  else if ((bVar1 != bVar4) &&
          ((byte)(bVar1 - (char)((uint)*(undefined2 *)unaff_DI >> 8)) ==
           (byte)((*(byte *)(unaff_SI + 2) & 0x7f) - 1))) {
    *unaff_DI = *unaff_DI + -1;
  }
  uVar3 = *(uint *)(unaff_SI + 2);
  puVar5 = (undefined2 *)(unaff_SI + 6);
  bVar1 = unaff_DI[1];
  *(int *)0xc54c = bVar1 + 1;
  if (-1 < (char)uVar3) {
    puVar5 = puVar5 + bVar1;
  }
  FUN_1000_4b61();
  uVar2 = uVar3 & 0xff;
  if (-1 < (char)(byte)uVar3) {
    do {
      puVar5 = puVar5 + 1;
      FUN_1000_759b(puVar5);
      *(int *)0xc54c = *(int *)0xc54c + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    FUN_1000_9239();
    return;
  }
  uVar6 = *puVar5;
  uVar3 = (uint)((byte)uVar3 & 0x7f);
  do {
    FUN_1000_759b(uVar6);
    *(int *)0xc54c = *(int *)0xc54c + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  FUN_1000_9239();
  return;
}


