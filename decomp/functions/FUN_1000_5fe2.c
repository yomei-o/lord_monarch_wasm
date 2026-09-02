/* 1000:5fe2 */

undefined * __cdecl16near FUN_1000_5fe2(void)

{
  uint in_DX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar1;
  
  FUN_1000_6c3f();
  *(undefined2 *)0x3b44 = 0;
  FUN_1000_0ccc();
  FUN_1000_0ce3();
  FUN_1000_c492();
  FUN_1000_c449();
  do {
    FUN_1000_687e();
    uVar1 = in_ZF;
    if (!(bool)in_CF) {
      FUN_1000_6f4b();
      FUN_1000_68a0();
      uVar1 = in_ZF;
      if (!(bool)in_CF) {
        *(undefined2 *)0x3472 = *(undefined2 *)&DAT_0000_3bc6;
        return (undefined *)CONCAT22(in_DX,(undefined *)&DAT_0000_3f1c);
      }
    }
    FUN_1000_6cb5();
    in_ZF = 1;
  } while ((bool)uVar1);
  return (undefined *)((ulong)in_DX << 0x10);
}


