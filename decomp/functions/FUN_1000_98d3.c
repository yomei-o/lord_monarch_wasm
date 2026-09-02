/* 1000:98d3 */

/* WARNING: Instruction at (ram,0x00019907) overlaps instruction at (ram,0x00019906)
    */
/* WARNING: Removing unreachable block (ram,0x0001991c) */

char FUN_1000_98d3(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 in_BL;
  int iVar3;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar4;
  undefined2 uStack0003;
  undefined2 uStack0005;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI + 0x6dbe);
  *pbVar1 = *pbVar1 | 0x2e;
  bVar4 = (POPCOUNT(*pbVar1) & 1U) == 0;
  FUN_1000_5cb1();
  if (bVar4) {
    in(0xc3);
  }
  iVar3 = CONCAT11(*(undefined1 *)(unaff_BP + 0x2ebd),in_BL);
  bVar2 = 0x16;
  func_0x0001b0ae();
  *(byte *)(iVar3 + 0x36) = *(byte *)(iVar3 + 0x36) ^ bVar2;
  FUN_1000_8afb();
  FUN_1000_3914();
  func_0x00015cee();
  uStack0003 = 0x9912;
  func_0x00015cee();
  uStack0005 = 0x9917;
  bVar2 = FUN_1000_36f5();
  *(byte *)(unaff_BP + 0x177d) = *(byte *)(unaff_BP + 0x177d) & bVar2;
  swi(4);
  return bVar2 - 0x3b;
}


