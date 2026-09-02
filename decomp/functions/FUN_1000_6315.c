/* 1000:6315 */

undefined4 __cdecl16near FUN_1000_6315(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  bool bVar1;
  
  *(undefined2 *)0x3bc2 = *(undefined2 *)0xce70;
  bVar1 = false;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)0x346e = 0xffff;
  FUN_1000_6033();
  if (bVar1) {
    FUN_1000_7c9e();
    FUN_1000_72ad();
    FUN_1000_7c9e();
    FUN_1000_72ad();
  }
  return CONCAT22(in_DX,in_AX);
}


