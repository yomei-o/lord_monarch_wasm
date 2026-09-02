/* 1000:6aaa */

undefined4 __cdecl16near FUN_1000_6aaa(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  char extraout_DH;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6c69();
  FUN_1000_6aea();
  if ((bool)in_CF) {
    FUN_1000_712c();
    if (!(bool)in_CF) {
      FUN_1000_70df();
    }
  }
  else {
    FUN_1000_712c();
    if (!(bool)in_CF) {
      uVar3 = FUN_1000_707a();
      puVar6 = (undefined2 *)((uint)(byte)(extraout_DH - 1) << 10);
      puVar5 = (undefined2 *)&DAT_0000_b98e;
      for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = puVar6;
        puVar6 = puVar6 + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
      FUN_1000_70a6();
    }
  }
  return CONCAT22(in_DX,in_AX);
}


