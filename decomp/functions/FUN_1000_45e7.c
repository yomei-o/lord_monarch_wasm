/* 1000:45e7 */

undefined4 __cdecl16near FUN_1000_45e7(void)

{
  undefined1 uVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  
  FUN_1000_4814();
  iVar2 = FUN_1000_baaf();
  if ((!(bool)in_CF) &&
     (uVar3 = *(uint *)(unaff_SI + 6) == iVar2 * 2, (uint)(iVar2 * 2) <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = in_BX;
    FUN_1000_b78c();
    uVar1 = FUN_1000_c0bd();
    if (!(bool)uVar3) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar1;
    }
    *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 9;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}


