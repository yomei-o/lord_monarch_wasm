/* 1000:c946 */

void __cdecl16near FUN_1000_c946(void)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  uint *puVar8;
  undefined *puVar9;
  int *piVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  FUN_1000_c5f4();
  FUN_1000_74c6();
  uVar5 = FUN_1000_c7ce();
  if ((uVar5 & 0x60) != 0) {
    FUN_1000_0ccc();
    return;
  }
  uVar5 = 0x80;
  iVar6 = 3 - *(uint *)0x3c1e;
  if (*(uint *)0x3c1e < 4 && iVar6 != 0) {
    uVar5 = 0x80 >> ((byte)iVar6 & 0x1f);
  }
  *(uint *)0x3bb4 = uVar5;
  *(undefined2 *)0x3bb6 = (undefined *)&DAT_0000_ce74 + uVar5 * 8;
  puVar8 = (uint *)&DAT_0000_ce74;
  iVar6 = *(int *)0x3bb4 * 2;
  do {
    uVar5 = FUN_1000_9a36();
    *puVar8 = uVar5 & 0x7fff;
    puVar8 = puVar8 + 2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puVar9 = (undefined *)&DAT_0000_ce74;
  iVar6 = *(int *)0x3bb4 * 2;
  do {
    bVar4 = FUN_1000_9a36();
    uVar7 = 0x50;
    if (((bVar4 & 7) != 0) && (uVar7 = 0xa0, 1 < (bVar4 & 7))) {
      uVar7 = 0xf0;
    }
    *(undefined2 *)(puVar9 + 2) = uVar7;
    puVar9 = puVar9 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_5dfd();
  FUN_1000_7c1c();
  FUN_1000_7ad3();
  FUN_1000_7ad3();
  piVar10 = (int *)0x3b4f;
  while (piVar1 = piVar10, piVar10 = piVar10 + 1, *piVar1 != -1) {
    FUN_1000_759b();
  }
  *(undefined2 *)0x32e0 = 0;
  puVar11 = (undefined2 *)0x24cb;
  puVar12 = (undefined2 *)&DAT_0000_3e20;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar12;
    puVar12 = puVar12 + 1;
    puVar2 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = *puVar2;
  }
  FUN_1000_c6ad();
  FUN_1000_c612();
  *(undefined1 *)0x32d3 = 0x1e;
  do {
    bVar4 = FUN_1000_c7ce();
    if ((bVar4 & 0x60) != 0) goto LAB_1000_ca35;
  } while (*(char *)0x32d3 != '\0');
  FUN_1000_c630();
  do {
    bVar4 = FUN_1000_c7ce();
  } while ((bVar4 & 0x60) == 0);
LAB_1000_ca35:
  FUN_1000_0ccc();
  FUN_1000_95f7();
  FUN_1000_c5f4();
  *(undefined2 *)0x32e0 = 1;
  FUN_1000_c6b3();
  return;
}


