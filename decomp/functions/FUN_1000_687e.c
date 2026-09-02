/* 1000:687e */

undefined4 __cdecl16near FUN_1000_687e(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  *(undefined2 *)0x3e8c = unaff_SI;
  *(undefined2 *)0x3e8e = (undefined *)&DAT_0000_b98e;
  *(undefined2 *)0x3e90 = 0;
  FUN_1000_69df();
  if (!(bool)in_CF) {
    uVar1 = FUN_1000_6d3a();
    if (!(bool)in_CF) {
      *(undefined2 *)0x3e8a = uVar1;
    }
  }
  return CONCAT22(in_DX,in_AX);
}


