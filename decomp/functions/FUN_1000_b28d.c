/* 1000:b28d */

undefined4 __cdecl16near FUN_1000_b28d(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 unaff_DS;
  byte bVar2;
  uint uVar3;
  
  if (*(byte *)0x3c00 < 4) {
    bVar2 = 0;
    if ((**(uint **)((undefined *)&DAT_0000_12ef + (uint)*(byte *)0x3c00 * 2) & 8) != 0) {
      FUN_1000_0ccc();
      *(undefined2 *)&DAT_0000_3bc6 = 2;
      FUN_1000_5f7e();
      FUN_1000_0ceb();
      FUN_1000_7c9e();
      FUN_1000_93c5();
      FUN_1000_4a4d();
      FUN_1000_0d0a();
      uVar1 = FUN_1000_72ad();
      FUN_1000_0d12(uVar1);
      FUN_1000_c90f();
      *(undefined2 *)0x3bd6 = 0xffff;
      *(undefined2 *)0x346e = 0xffff;
      FUN_1000_6033();
      uVar3 = (uint)(bVar2 & 1);
      FUN_1000_c5f4();
      if ((uVar3 & 1) == 0) {
        FUN_1000_04b8();
      }
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}


