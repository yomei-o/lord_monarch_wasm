/* 1000:94ac */

void FUN_1000_94ac(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte extraout_DL;
  byte extraout_DH;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  FUN_1000_6095();
  func_0x0001389c();
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) & extraout_DH;
  pbVar1 = (byte *)(in_BX + unaff_SI + 8);
  *pbVar1 = *pbVar1 & extraout_DL;
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


