/* 1000:458e */

undefined4 __cdecl16near FUN_1000_458e(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar4;
  undefined4 uVar5;
  
  bVar2 = *(char *)(unaff_SI + 0xc) + 8;
  uVar4 = bVar2 < (byte)((undefined *)&DAT_0000_d27e)[*(int *)(unaff_SI + 4)];
  if (bVar2 == ((undefined *)&DAT_0000_d27e)[*(int *)(unaff_SI + 4)]) {
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    *(undefined2 *)(unaff_SI + 8) = *(undefined2 *)(unaff_SI + 2);
    *(undefined1 *)(unaff_SI + 10) = 2;
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_4814();
  uVar5 = FUN_1000_bc56();
  if ((!(bool)uVar4) &&
     (uVar1 = (int)uVar5 * 2, uVar4 = *(uint *)(unaff_SI + 6) == uVar1,
     uVar1 <= *(uint *)(unaff_SI + 6))) {
    *(undefined2 *)(unaff_SI + 8) = (int)((ulong)uVar5 >> 0x10);
    FUN_1000_b78c();
    uVar3 = FUN_1000_c0bd();
    if (!(bool)uVar4) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar3;
    }
    *(undefined1 *)(unaff_SI + 10) = 2;
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}


