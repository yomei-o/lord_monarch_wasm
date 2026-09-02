/* 1000:92fb */

void FUN_1000_92fb(void)

{
  uint *puVar1;
  code *pcVar2;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar2 = (code *)swi(0xfa);
  (*pcVar2)();
  FUN_1000_8da7();
  *(undefined2 *)0xd276 = 0x2ff8;
  *(undefined2 *)0xd27a = 0;
  FUN_1000_6184();
  puVar1 = (uint *)(unaff_BP + unaff_SI);
  *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0xf;
  pcVar2 = (code *)swi(1);
  (*pcVar2)();
  return;
}


