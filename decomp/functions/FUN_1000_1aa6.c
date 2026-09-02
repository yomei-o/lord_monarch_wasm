/* 1000:1aa6 */

void FUN_1000_1aa6(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  undefined1 uVar2;
  
  FUN_1000_c6a0();
  FUN_1000_4cdd();
  do {
    FUN_1000_7c9e();
    FUN_1000_72ad();
    FUN_1000_4d4a();
    uVar2 = *(char *)0x34d6 != -1;
    if (*(char *)0x34d6 != -1) {
      FUN_1000_c612();
    }
    FUN_1000_c8fd();
    while( true ) {
      uVar1 = FUN_1000_4db2();
      if (!(bool)uVar2) break;
      uVar2 = *(int *)0x3bc2 != -1;
      if ((*(int *)0x3bc2 != -1) && (uVar2 = 0, *(int *)0x3bd4 != 0)) {
        FUN_1000_0d12(uVar1);
        uVar2 = 0;
        FUN_1000_1afa();
      }
    }
    FUN_1000_7c9e();
    FUN_1000_72ad();
    (*(code *)*(undefined2 *)((uVar1 & 0xff) * 2 + 0x202d))();
  } while( true );
}


