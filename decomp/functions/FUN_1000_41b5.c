/* 1000:41b5 */

undefined2 __cdecl16near FUN_1000_41b5(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  byte bVar2;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar2 = ((undefined *)&DAT_0000_d27e)[unaff_DI] - 0xc;
  if (bVar2 < 4) {
    uVar1 = FUN_1000_a61d();
    if ((bVar2 != (byte)uVar1) && (bVar2 != (byte)((uint)uVar1 >> 8))) {
      *(undefined **)((undefined *)&DAT_0000_d27e + unaff_DI) = (undefined *)&DAT_0000_6400;
    }
  }
  return in_AX;
}


