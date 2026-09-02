/* 1000:14e8 */

undefined4 __cdecl16near FUN_1000_14e8(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  byte extraout_DH;
  byte bVar1;
  undefined2 unaff_DS;
  
  bVar1 = 0;
  do {
    if (bVar1 != 7) {
      FUN_1000_740d();
      bVar1 = extraout_DH;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0xe);
  FUN_1000_740d();
  FUN_1000_740d();
  *(undefined1 *)0x3ab7 = 0;
  *(undefined1 *)0x3ad7 = 0;
  *(undefined1 *)0x3af7 = 0;
  return CONCAT22(in_DX,in_AX);
}


