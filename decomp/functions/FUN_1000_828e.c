/* 1000:828e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000182f6) overlaps instruction at (ram,0x000182f5)
    */

void FUN_1000_828e(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  uint in_AX;
  undefined2 uVar4;
  byte bVar5;
  char extraout_DL;
  int in_BX;
  int iVar6;
  undefined2 unaff_DS;
  undefined1 uVar7;
  
  if (0x1f < in_AX) {
    in_AX = 0x20;
  }
  *(uint *)0xc54e = in_AX;
  uVar7 = (*(byte *)(in_BX + 1) >> 3 & 1) != 0;
  uVar4 = FUN_1000_3c62();
  *(undefined2 *)0xc550 = uVar4;
  uVar4 = FUN_1000_3c62();
  *(undefined2 *)0xc552 = uVar4;
  FUN_1000_493c();
  FUN_1000_2af5();
  if ((bool)uVar7) {
    FUN_1000_16eb();
    FUN_1000_53d6();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar6 = 0;
  FUN_1000_171f();
  *(undefined2 *)0x32a8 = 0xf;
  bVar5 = 10;
  bVar3 = FUN_1000_9883();
  *(byte *)(iVar6 + 0x297a) = *(byte *)(iVar6 + 0x297a) ^ bVar5;
  *(char *)0xd0e2 = *(char *)0xd0e2 + extraout_DL + (0x99 < bVar3);
  func_0x0001d9a4();
  FUN_1000_3f40();
  FUN_1000_95a6();
  pbVar1 = (byte *)(iVar6 + 0x3d7c);
  *pbVar1 = *pbVar1 << (bVar5 & 7) | *pbVar1 >> 8 - (bVar5 & 7);
  *(undefined2 *)0xce72 = *(undefined2 *)0x297a;
  func_0x0001d941();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


