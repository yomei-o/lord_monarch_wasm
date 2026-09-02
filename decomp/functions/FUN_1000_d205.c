/* 1000:d205 */

void __cdecl16near FUN_1000_d205(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int extraout_DX;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar8;
  
  puVar6 = (undefined2 *)0x258b;
  puVar7 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar7;
    puVar7 = puVar7 + 1;
    puVar1 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar3 = 0xc;
  do {
    FUN_1000_9859();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_1000_74c6();
  *(undefined1 *)0x34d6 = 0xff;
  FUN_1000_99ef();
  FUN_1000_99ef();
  FUN_1000_c6fa();
  FUN_1000_98a0();
  iVar3 = 200;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_c6fa();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)0x34d6 = 0;
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  FUN_1000_c6fa();
  FUN_1000_7518();
  FUN_1000_9a0d();
  FUN_1000_98a0();
  FUN_1000_729a();
  FUN_1000_98a0();
  FUN_1000_729a();
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_c6ad();
  FUN_1000_c612();
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_c7b5();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_c79d();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aae();
  FUN_1000_c79d();
  *(undefined2 *)0x34e0 = 0;
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x3c;
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x78;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x3c;
  FUN_1000_72a7();
  FUN_1000_7518();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  FUN_1000_9aae();
  uVar5 = 399;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    FUN_1000_c6fa();
    uVar4 = extraout_DX + 1;
    if (uVar4 >> 3 != 0) {
      FUN_1000_99ef();
    }
    bVar8 = uVar4 <= uVar5;
    uVar5 = uVar5 - uVar4;
  } while (bVar8);
  FUN_1000_7518();
  FUN_1000_9a0d();
  FUN_1000_c6fa();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined1 *)0x32d3 = 0x10;
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_9aa6();
  FUN_1000_72ad();
  *(undefined2 *)0x34dc = 0x10;
  *(undefined2 *)0x34e0 = 1;
  FUN_1000_9aae();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  return;
}


