/* 1000:92b2 */

void FUN_1000_92b2(void)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  int in_DX;
  int iVar6;
  uint unaff_BP;
  undefined1 *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  out(*unaff_SI,in_DX + 1);
  func_0x000160cf();
  uVar4 = unaff_BP;
  do {
    uVar3 = FUN_1000_94a6();
  } while (99 < uVar3);
  iVar6 = uVar4 - (uVar4 >> 2);
  do {
    FUN_1000_94bb();
  } while (iVar6 != 0);
  do {
    uVar4 = FUN_1000_94a6();
  } while (0x9f < uVar4);
  FUN_1000_6184();
  uVar5 = FUN_1000_8dd4();
  pcVar2 = (code *)swi(0xfa);
  (*pcVar2)();
  FUN_1000_8da7(uVar5);
  *(undefined2 *)0xd276 = 0x2ff8;
  *(undefined2 *)0xd27a = 0;
  FUN_1000_6184();
  puVar1 = (uint *)(unaff_SI + unaff_BP + 1);
  *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0xf;
  pcVar2 = (code *)swi(1);
  (*pcVar2)();
  return;
}


