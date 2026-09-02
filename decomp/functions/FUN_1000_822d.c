/* 1000:822d */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000182f6) overlaps instruction at (ram,0x000182f5)
    */

void FUN_1000_822d(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  undefined2 uVar6;
  char in_CL;
  char extraout_DL;
  undefined2 extraout_DX;
  char in_BL;
  int iVar7;
  int unaff_BP;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar8;
  
  func_0x0001e3b3();
  *unaff_SI = *unaff_SI - in_BL;
  *(char *)0xcbf3 = (*(char *)0xcbf3 - (in_CL + '\x01')) - (*(int *)0xcc06 != 0);
  FUN_1000_9131();
  if (*(byte *)0x32b5 < 0x31) {
    bVar3 = *(char *)0x32b6 - 0x30;
  }
  else {
    bVar3 = *(byte *)0x32b5 - 0x27;
  }
  if ((uint)bVar3 <= *(uint *)0xce72) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x0001d96b();
  in(CONCAT11((char)((uint)extraout_DX >> 8),(byte)extraout_DX & *(byte *)(unaff_BP + unaff_DI)));
  FUN_1000_2c1c();
  func_0x0001d989();
  *(int *)0xce72 = *(int *)0xce72 + 1;
  iVar7 = 0x3e70;
  pcVar2 = (code *)swi(0x1c);
  (*pcVar2)();
  bVar3 = FUN_1000_3c62();
  bVar4 = bVar3 + 0xa8;
  if (bVar3 < 0x58) {
    bVar4 = bVar3 + 0xc;
  }
  uVar5 = (uint)bVar4;
  if (0x1f < uVar5) {
    uVar5 = 0x20;
  }
  *(uint *)0xc54e = uVar5;
  uVar8 = (*(byte *)(iVar7 + 1) >> 3 & 1) != 0;
  uVar6 = FUN_1000_3c62();
  *(undefined2 *)0xc550 = uVar6;
  uVar6 = FUN_1000_3c62();
  *(undefined2 *)0xc552 = uVar6;
  FUN_1000_493c();
  FUN_1000_2af5();
  if ((bool)uVar8) {
    FUN_1000_16eb();
    FUN_1000_53d6();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar7 = 0;
  FUN_1000_171f();
  *(undefined2 *)0x32a8 = 0xf;
  bVar4 = 10;
  bVar3 = FUN_1000_9883();
  *(byte *)(iVar7 + 0x297a) = *(byte *)(iVar7 + 0x297a) ^ bVar4;
  *(char *)0xd0e2 = *(char *)0xd0e2 + extraout_DL + (0x99 < bVar3);
  func_0x0001d9a4();
  FUN_1000_3f40();
  FUN_1000_95a6();
  pbVar1 = (byte *)(iVar7 + 0x3d7c);
  *pbVar1 = *pbVar1 << (bVar4 & 7) | *pbVar1 >> 8 - (bVar4 & 7);
  *(undefined2 *)0xce72 = *(undefined2 *)0x297a;
  func_0x0001d941();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


