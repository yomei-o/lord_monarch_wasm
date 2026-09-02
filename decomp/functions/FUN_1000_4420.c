/* 1000:4420 */

undefined4 __cdecl16near FUN_1000_4420(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint in_AX;
  undefined2 in_DX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar3;
  undefined4 uVar4;
  
  FUN_1000_4814();
  uVar4 = FUN_1000_b876();
  if (((!(bool)in_CF) && ((uint)uVar4 < in_AX)) && ((uint)uVar4 * 2 <= *(uint *)(unaff_SI + 6))) {
    bVar1 = ((undefined *)&DAT_0000_d27e)[unaff_DI];
    uVar2 = 5;
    uVar3 = bVar1 == 0;
    if ((((!(bool)uVar3) && ((bVar1 < 0xc || (uVar3 = bVar1 == 0x10, 0xf < bVar1)))) &&
        ((uVar2 = 4, bVar1 < 8 || (uVar3 = bVar1 == 0xc, 0xb < bVar1)))) &&
       ((uVar2 = 8, bVar1 == 0 || (uVar3 = bVar1 == 5, 4 < bVar1)))) {
      uVar2 = 0xb;
      uVar3 = bVar1 == 5;
      if (!(bool)uVar3) goto LAB_1000_4492;
    }
    *(undefined1 *)(unaff_SI + 10) = uVar2;
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar4 >> 0x10);
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if ((!(bool)uVar3) &&
       (*(undefined1 *)(unaff_SI + 0xb) = uVar2, *(char *)(unaff_SI + 10) == '\v')) {
      FUN_1000_c2e7();
    }
    return CONCAT22(in_DX,in_AX);
  }
LAB_1000_4492:
  return CONCAT22(in_DX,in_AX);
}


