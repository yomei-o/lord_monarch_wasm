/* 1000:1afa */

void __cdecl16near FUN_1000_1afa(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  bVar2 = *(int *)0x3bc2 != -1;
  if (*(int *)0x3bc2 == -1) {
    *(undefined2 *)0x3bc2 = *(undefined2 *)0xce70;
    *(undefined2 *)0x346e = 0xffff;
    FUN_1000_6033();
    if (bVar2) {
      FUN_1000_7c9e();
      FUN_1000_4cdd();
      FUN_1000_72ad();
      return;
    }
    FUN_1000_04b8();
  }
  else if ((*(int *)0x3bd4 != 0) && (*(int *)0x3bd6 != 0)) {
    uVar1 = FUN_1000_4a4d();
    FUN_1000_0d12(uVar1);
    FUN_1000_c90f();
    return;
  }
  *(undefined2 *)0x3bd4 = 0xffff;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_7c9e();
  FUN_1000_4d86();
  FUN_1000_4cdd();
  FUN_1000_72ad();
  FUN_1000_c6a0();
  return;
}


