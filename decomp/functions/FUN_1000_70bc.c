/* 1000:70bc */

undefined4 __cdecl16near FUN_1000_70bc(void)

{
  undefined2 in_AX;
  uint uVar1;
  int iVar2;
  undefined2 in_DX;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar3 = 0;
  uVar1 = 0xffff;
  iVar2 = *(int *)&DAT_0000_c4e6;
  do {
    if (*(uint *)((undefined *)&DAT_0000_c27e + iVar3) < uVar1) {
      uVar1 = *(uint *)((undefined *)&DAT_0000_c27e + iVar3);
    }
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}


