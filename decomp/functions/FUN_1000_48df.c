/* 1000:48df */

undefined4 __cdecl16near FUN_1000_48df(void)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  FUN_1000_bd1e();
  FUN_1000_c316();
  FUN_1000_bd84();
  FUN_1000_be36();
  FUN_1000_b78c();
  uVar1 = FUN_1000_c0bd();
  if (!(bool)in_ZF) {
    *(undefined1 *)(unaff_SI + 0xb) = uVar1;
    bVar2 = *(byte *)(unaff_SI + 10) & 0xf;
    if ((((bVar2 == 10) || (bVar2 == 7)) || (bVar2 == 9)) || ((bVar2 == 0xb || (bVar2 == 6)))) {
      FUN_1000_c2e7();
    }
    *(undefined1 *)(unaff_SI + 0xf) = 4;
    return CONCAT22(in_DX,in_AX);
  }
  return CONCAT22(in_DX,in_AX);
}


