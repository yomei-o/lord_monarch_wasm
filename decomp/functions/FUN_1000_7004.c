/* 1000:7004 */

void __cdecl16near FUN_1000_7004(void)

{
  code *pcVar1;
  undefined1 extraout_AH;
  undefined2 in_CX;
  int in_BX;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar2;
  undefined4 uVar3;
  
  FUN_1000_712c();
  if (!(bool)in_CF) {
    FUN_1000_70df();
    FUN_1000_7105();
    return;
  }
  FUN_1000_70bc();
  uVar3 = FUN_1000_70df();
  FUN_1000_707a((int)uVar3,in_BX,in_CX,(int)((ulong)uVar3 >> 0x10));
  *(undefined2 *)((undefined *)&DAT_0000_c016 + in_BX) = 0;
  uVar2 = 0;
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  FUN_1000_70a6();
  if (!(bool)uVar2) {
    FUN_1000_7105();
  }
  return;
}


