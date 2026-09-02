/* 1000:41dc */

undefined4 __cdecl16near FUN_1000_41dc(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    FUN_1000_9b34();
    if (((undefined *)&DAT_0000_d27e)[in_BX] == '{') {
      uVar2 = *(uint *)(unaff_SI + 6) >> 5;
      iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
      cVar3 = (char)iVar1;
      if (uVar2 <= (byte)((undefined *)&DAT_0000_d27f)[in_BX] && iVar1 != 0) {
        ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
        FUN_1000_9ae1();
        return CONCAT22(in_DX,in_AX);
      }
      *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = (uint)(byte)-cVar3 << 8;
      FUN_1000_484a();
      FUN_1000_9ae1();
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}


