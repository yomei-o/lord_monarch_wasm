/* 1000:7105 */

void __cdecl16near FUN_1000_7105(void)

{
  undefined2 in_AX;
  int iVar1;
  int in_BX;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = 0;
  iVar1 = *(int *)&DAT_0000_c4e6;
  do {
    if (*(int *)((undefined *)&DAT_0000_c27e + iVar2) != 0) {
      *(int *)((undefined *)&DAT_0000_c27e + iVar2) =
           *(int *)((undefined *)&DAT_0000_c27e + iVar2) + -1;
    }
    iVar2 = iVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined2 *)((undefined *)&DAT_0000_c016 + in_BX) = in_AX;
  *(undefined2 *)((undefined *)&DAT_0000_c27e + in_BX) = 0xffff;
  return;
}


