/* 1000:cb19 */

void __cdecl16near FUN_1000_cb19(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar12;
  undefined4 uVar13;
  
  FUN_1000_5ee4();
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  FUN_1000_5ee4();
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  uVar12 = 0;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  FUN_1000_5ee4();
  FUN_1000_c6fa();
  FUN_1000_99ef();
  FUN_1000_c6ad();
  puVar10 = (undefined2 *)0x252b;
  puVar11 = (undefined2 *)&DAT_0000_3e20;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    *puVar3 = *puVar2;
  }
  *(undefined1 *)0x34d6 = 0xff;
  FUN_1000_9aae();
  uVar8 = 1;
  do {
    FUN_1000_cdc6();
  } while (!(bool)uVar12);
  uVar13 = FUN_1000_cdc6();
  FUN_1000_99ef((int)uVar13,uVar8,(int)((ulong)uVar13 >> 0x10));
  do {
    uVar5 = FUN_1000_cdc6();
  } while (99 < uVar5);
  iVar6 = uVar8 - (uVar8 >> 2);
  do {
    FUN_1000_cddb();
    uVar9 = 0;
  } while (iVar6 != 0);
  do {
    uVar8 = FUN_1000_cdc6();
  } while (0x9f < uVar8);
  FUN_1000_9aa6();
  FUN_1000_c6fa();
  FUN_1000_99ef();
  FUN_1000_99ef();
  FUN_1000_c6d1();
  *(undefined2 *)0xd276 = (undefined *)&DAT_0000_2ff8;
  *(undefined2 *)&DAT_0000_d27a = 0;
  FUN_1000_9aae();
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  iVar6 = 0xcf;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    uVar13 = FUN_1000_c76a();
    uVar12 = (undefined1)((ulong)uVar13 >> 0x18);
    if ((char)((ulong)uVar13 >> 0x10) == '\x01') {
      FUN_1000_99ef((int)uVar13 + -1,uVar9,iVar6,CONCAT11(uVar12,uVar12));
    }
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  do {
  } while (*(uint *)0x3f1a < 0x500);
  iVar7 = 0x28;
  iVar6 = 4000;
  do {
    *(int *)0xd276 = iVar6 + 1;
    uVar13 = FUN_1000_9aa6();
    iVar6 = (int)uVar13;
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_99ef(iVar6,uVar9,iVar7,(int)((ulong)uVar13 >> 0x10));
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  FUN_1000_5ee4();
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  puVar10 = (undefined2 *)0x0;
  uVar8 = 0xa800;
  do {
    uVar5 = uVar8;
    puVar11 = (undefined2 *)0x2e40;
    for (iVar6 = 0x18d8; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + 1;
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = uVar5 + 0x800;
    uVar8 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar8 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  iVar7 = 0x28;
  iVar6 = 0xfc8;
  do {
    *(int *)0xd276 = iVar6 + -1;
    uVar13 = FUN_1000_9aa6();
    iVar6 = (int)uVar13;
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_99ef(iVar6,uVar9,iVar7,(int)((ulong)uVar13 >> 0x10));
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6fa();
  FUN_1000_c6b3();
  FUN_1000_72c1();
  FUN_1000_72a7();
  FUN_1000_74c6();
  FUN_1000_9a0d();
  return;
}


