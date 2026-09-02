/* 1000:6916 */

undefined4 __cdecl16near FUN_1000_6916(void)

{
  int iVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  *(undefined2 *)0x3e8c = unaff_SI;
  *(undefined2 *)0x3e8e = (undefined *)&DAT_0000_b98e;
  *(undefined2 *)0x3e90 = 0x400;
  FUN_1000_69df();
  if (!(bool)in_CF) {
    uVar2 = FUN_1000_6d3a();
    if ((bool)in_CF) {
      FUN_1000_6d7b();
    }
    else {
      *(undefined2 *)0x3e8a = uVar2;
      FUN_1000_6df8();
      if (!(bool)in_CF) {
        FUN_1000_6f65();
        iVar1 = *(int *)0x3e94;
        *(undefined2 *)(iVar1 + 0x18) = extraout_DX;
        *(undefined2 *)(iVar1 + 0x16) = in_CX;
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}


