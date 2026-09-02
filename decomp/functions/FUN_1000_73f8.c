/* 1000:73f8 */

undefined4 __cdecl16near FUN_1000_73f8(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  
  iVar2 = 0x1000;
  do {
    bVar1 = in(0x188);
    if ((bVar1 & 0x80) == 0) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}


