/* 1000:4304 */

undefined4 __cdecl16near FUN_1000_4304(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
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
    if (((undefined *)&DAT_0000_d27e)[in_BX] == '\x05') {
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
        uVar2 = *(uint *)(unaff_SI + 6) >> 3;
        iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
        if ((byte)((undefined *)&DAT_0000_d27f)[in_BX] < uVar2 || iVar1 == 0) {
          *(undefined2 *)((undefined *)&DAT_0000_d27e + in_BX) = 0x60;
          FUN_1000_a7e9();
          FUN_1000_484a();
          FUN_1000_9ae1();
          return CONCAT22(in_DX,in_AX);
        }
        ((undefined *)&DAT_0000_d27f)[in_BX] = (char)iVar1;
      }
      FUN_1000_9ae1();
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}


