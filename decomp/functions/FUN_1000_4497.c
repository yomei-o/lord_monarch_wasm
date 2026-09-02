/* 1000:4497 */

undefined4 __cdecl16near FUN_1000_4497(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar3;
  undefined4 uVar4;
  
  uVar3 = false;
  FUN_1000_b4d8();
  if (!(bool)uVar3) {
    FUN_1000_4814();
    uVar4 = FUN_1000_b9a7();
    if ((!(bool)uVar3) &&
       (uVar1 = (int)uVar4 * 2, uVar3 = *(uint *)(unaff_SI + 6) == uVar1,
       uVar1 <= *(uint *)(unaff_SI + 6))) {
      *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
      FUN_1000_b78c();
      uVar2 = FUN_1000_c0bd();
      if (!(bool)uVar3) {
        *(undefined1 *)(unaff_SI + 0xb) = uVar2;
      }
      *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 5;
      *(undefined1 *)(unaff_SI + 0xf) = 4;
      return CONCAT22(in_DX,in_AX);
    }
  }
  return CONCAT22(in_DX,in_AX);
}


