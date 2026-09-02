/* 1000:720b */

undefined2 __cdecl16near FUN_1000_720b(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  uint in_CX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  uVar2 = *(int *)&DAT_0000_c4e6 + in_CX;
  uVar3 = uVar2 - 0x134;
  if ((uVar2 < 0x134 || uVar3 == 0) ||
     (bVar5 = uVar3 <= in_CX, in_CX = in_CX - uVar3, bVar5 && in_CX != 0)) {
    iVar4 = *(int *)&DAT_0000_c4e6;
    *(int *)&DAT_0000_c4e6 = *(int *)&DAT_0000_c4e6 + in_CX;
    iVar4 = iVar4 * 2;
    uVar1 = in_AX;
    do {
      *(undefined2 *)((undefined *)&DAT_0000_bdae + iVar4) = uVar1;
      *(undefined2 *)((undefined *)&DAT_0000_c27e + iVar4) = 0;
      *(undefined2 *)((undefined *)&DAT_0000_c016 + iVar4) = 0;
      iVar4 = iVar4 + 2;
      uVar1 = CONCAT11((char)((uint)uVar1 >> 8) + '\x02',(char)uVar1);
      in_CX = in_CX - 1;
    } while (in_CX != 0);
  }
  return in_AX;
}


