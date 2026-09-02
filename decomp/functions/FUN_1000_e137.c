/* 1000:e137 */

void __cdecl16near FUN_1000_e137(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar11;
  undefined4 uVar12;
  
  FUN_1000_5efe();
  iVar6 = 4;
  do {
    FUN_1000_9859();
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_5ee4();
  puVar8 = (undefined2 *)0x0;
  uVar7 = 0xa800;
  do {
    uVar5 = uVar7;
    puVar10 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar2 = *puVar1;
    }
    uVar4 = uVar5 + 0x800;
    uVar7 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar7 = uVar5 + 0x2800, uVar4 < 0xe000));
  FUN_1000_5ee4();
  bVar3 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar3 ^ 1;
  out(0xa6,bVar3 ^ 1);
  puVar8 = (undefined2 *)0x0;
  uVar7 = 0xa800;
  do {
    uVar5 = uVar7;
    puVar10 = (undefined2 *)0x0;
    for (iVar6 = 4000; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar10;
      puVar10 = puVar10 + 1;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar2 = *puVar1;
    }
    uVar4 = uVar5 + 0x800;
    uVar7 = uVar4;
  } while ((uVar4 < 0xc000) || (uVar7 = uVar5 + 0x2800, uVar4 < 0xe000));
  bVar3 = *(byte *)0x3482;
  uVar11 = 0;
  *(byte *)0x3482 = bVar3 ^ 1;
  out(0xa6,bVar3 ^ 1);
  do {
    do {
      FUN_1000_6c3f();
      FUN_1000_687e();
    } while ((bool)uVar11);
    FUN_1000_6f4b();
    FUN_1000_68a0();
  } while ((bool)uVar11);
  FUN_1000_c6fa();
  FUN_1000_99ef();
  FUN_1000_c6ad();
  puVar8 = (undefined2 *)0x252b;
  puVar10 = (undefined2 *)&DAT_0000_3e20;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined1 *)0x34d6 = 0xff;
  FUN_1000_9aae();
  uVar7 = 1;
  do {
    FUN_1000_e33b();
  } while (!(bool)uVar11);
  uVar12 = FUN_1000_e33b();
  FUN_1000_99ef((int)uVar12,uVar7,(int)((ulong)uVar12 >> 0x10));
  do {
    uVar5 = FUN_1000_e33b();
  } while (99 < uVar5);
  iVar6 = uVar7 - (uVar7 >> 2);
  do {
    FUN_1000_e350();
  } while (iVar6 != 0);
  do {
    uVar7 = FUN_1000_e33b();
  } while (0x9f < uVar7);
  FUN_1000_9aa6();
  FUN_1000_c6fa();
  FUN_1000_c6d1();
  *(undefined2 *)0xd276 = (undefined *)&DAT_0000_1720;
  *(undefined2 *)&DAT_0000_d27a = 0;
  do {
    iVar9 = 0x3a3a;
    iVar6 = 6;
    bVar3 = 0x80;
    do {
      bVar3 = bVar3 & *(byte *)(iVar9 + 0x1f);
      iVar9 = iVar9 + 0x20;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  } while (bVar3 == 0);
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_9aae();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_9946();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_9946();
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


