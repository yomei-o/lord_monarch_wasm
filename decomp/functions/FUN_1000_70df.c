/* 1000:70df */

undefined2 __cdecl16near FUN_1000_70df(void)

{
  uint uVar1;
  undefined2 in_AX;
  int iVar2;
  int in_BX;
  int iVar3;
  undefined2 unaff_DS;
  
  *(undefined2 *)((undefined *)&DAT_0000_c016 + in_BX) = 0;
  LOCK();
  uVar1 = *(uint *)((undefined *)&DAT_0000_c27e + in_BX);
  *(uint *)((undefined *)&DAT_0000_c27e + in_BX) = 0;
  UNLOCK();
  iVar3 = 0;
  iVar2 = *(int *)&DAT_0000_c4e6;
  do {
    if (*(uint *)((undefined *)&DAT_0000_c27e + iVar3) <= uVar1) {
      *(int *)((undefined *)&DAT_0000_c27e + iVar3) =
           *(int *)((undefined *)&DAT_0000_c27e + iVar3) + 1;
    }
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}


