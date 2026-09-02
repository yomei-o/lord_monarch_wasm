/* 1000:4374 */

undefined4 __cdecl16near FUN_1000_4374(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint in_AX;
  uint uVar3;
  uint uVar4;
  undefined1 in_CL;
  undefined2 in_DX;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar8;
  undefined4 uVar9;
  
  FUN_1000_4814();
  uVar9 = FUN_1000_b876();
  uVar5 = (undefined2)((ulong)uVar9 >> 0x10);
  uVar3 = (uint)uVar9;
  if ((bool)in_CF) {
    uVar3 = 0x3fff;
  }
  else {
    bVar1 = ((undefined *)&DAT_0000_d27e)[unaff_DI];
    in_CL = 5;
    if ((((bVar1 != 0) && ((bVar1 < 0xc || (0xf < bVar1)))) &&
        ((in_CL = 4, bVar1 < 8 || (0xb < bVar1)))) && (in_CL = 0xb, bVar1 != 5)) {
      in_CL = 8;
    }
  }
  uVar6 = uVar5;
  uVar9 = FUN_1000_baaf(uVar5);
  uVar7 = uVar6;
  uVar4 = FUN_1000_bb70((int)((ulong)uVar9 >> 0x10));
  uVar2 = 7;
  if ((uint)uVar9 <= uVar4) {
    uVar2 = 9;
    uVar4 = (uint)uVar9;
    uVar7 = uVar6;
  }
  if (uVar3 <= uVar4) {
    uVar4 = uVar3;
    uVar7 = uVar5;
    uVar2 = in_CL;
  }
  if ((uVar4 < in_AX) &&
     (uVar8 = *(uint *)(unaff_SI + 6) == uVar4 * 2, uVar4 * 2 <= *(uint *)(unaff_SI + 6))) {
    *(undefined1 *)(unaff_SI + 10) = uVar2;
    *(undefined2 *)(unaff_SI + 8) = uVar7;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    FUN_1000_b78c();
    uVar2 = FUN_1000_c0bd();
    if ((!(bool)uVar8) &&
       (*(undefined1 *)(unaff_SI + 0xb) = uVar2, *(char *)(unaff_SI + 10) == '\v')) {
      FUN_1000_c2e7();
    }
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}


