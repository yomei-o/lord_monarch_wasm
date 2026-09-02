/* 1000:c492 */

undefined4 __cdecl16near FUN_1000_c492(void)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar2;
  undefined2 in_DX;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  iVar2 = 0x10;
  do {
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_3 = (undefined1)((uint)in_CX >> 8);
  *(uint *)(char *)s_0000000000_0000_32b0 = CONCAT11(local_3,local_3);
  *(uint *)((char *)s_0000000000_0000_32b0 + 2) = CONCAT11(local_3,local_3);
  FUN_1000_c585();
  FUN_1000_c585();
  cVar1 = FUN_1000_c585();
  if (cVar1 == ' ') {
    ((char *)s_0000000000_0000_32b0)[3] = '0';
  }
  return CONCAT22(in_DX,in_AX);
}


