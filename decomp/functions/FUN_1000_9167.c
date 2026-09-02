/* 1000:9167 */

undefined4 __cdecl16near FUN_1000_9167(void)

{
  undefined2 in_AX;
  uint in_CX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  
  iVar1 = (in_CX & 0xff) << 3;
  iVar2 = 8;
  do {
    FUN_1000_919f();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  do {
    FUN_1000_919f();
    FUN_1000_919f();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar2 = 8;
  do {
    FUN_1000_919f();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}


