/* 1000:82eb */

void FUN_1000_82eb(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte in_AL;
  byte in_CL;
  char in_DL;
  int in_BX;
  undefined2 *unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  
  *(char *)0xd0e2 = *(char *)0xd0e2 + in_DL + (0x99 < in_AL | in_CF);
  func_0x0001d9a4();
  FUN_1000_3f40();
  FUN_1000_95a6();
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x1402);
  *pbVar1 = *pbVar1 << (in_CL & 7) | *pbVar1 >> 8 - (in_CL & 7);
  *(undefined2 *)0xce72 = *unaff_SI;
  func_0x0001d941();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


