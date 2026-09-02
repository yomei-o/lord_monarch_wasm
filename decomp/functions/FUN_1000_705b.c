/* 1000:705b */

undefined2 __cdecl16near FUN_1000_705b(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar3 = 0;
  iVar2 = *(int *)&DAT_0000_c4e6;
  iVar1 = (uint)*(byte *)&DAT_0000_3e80 << 8;
  do {
    if ((char)((uint)iVar1 >> 8) == *(char *)(iVar3 + -0x3fe9)) {
      iVar1 = FUN_1000_70df();
    }
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}


