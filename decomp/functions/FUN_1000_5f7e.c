/* 1000:5f7e */

undefined * __cdecl16near FUN_1000_5f7e(void)

{
  uint uVar1;
  undefined *puVar2;
  uint in_DX;
  uint extraout_DX;
  undefined2 unaff_DS;
  undefined1 uVar3;
  undefined1 uVar4;
  
  if ((undefined *)*(undefined2 *)0x3b44 == (undefined *)&DAT_0000_4f1c) {
    FUN_1000_0d0a();
    in_DX = extraout_DX;
  }
  uVar1 = *(uint *)&DAT_0000_3bc6;
  if (uVar1 == *(uint *)0x3470) {
    puVar2 = (undefined *)&DAT_0000_3f1c;
  }
  else {
    uVar3 = uVar1 < *(uint *)0x3472;
    uVar4 = uVar1 == *(uint *)0x3472;
    if (!(bool)uVar4) {
      FUN_1000_6c3f(uVar1);
      FUN_1000_c492();
      FUN_1000_c449();
      do {
        FUN_1000_687e();
        if (!(bool)uVar3) {
          FUN_1000_6f4b();
          FUN_1000_68a0();
          if (!(bool)uVar3) {
            *(undefined2 *)0x3472 = *(undefined2 *)&DAT_0000_3bc6;
            break;
          }
        }
        FUN_1000_6cb5();
        if (!(bool)uVar4) {
          return (undefined *)((ulong)in_DX << 0x10);
        }
      } while( true );
    }
    puVar2 = (undefined *)&DAT_0000_4f1c;
  }
  return (undefined *)CONCAT22(in_DX,puVar2);
}


