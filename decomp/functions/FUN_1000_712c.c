/* 1000:712c */

void __cdecl16near FUN_1000_712c(void)

{
  int in_AX;
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = 0;
  iVar1 = *(int *)&DAT_0000_c4e6;
  do {
    if (in_AX == *(int *)((undefined *)&DAT_0000_c016 + iVar2)) {
      return;
    }
    iVar2 = iVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


