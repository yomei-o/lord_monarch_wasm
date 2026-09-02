/* 1000:9127 */

/* WARNING: Instruction at (ram,0x00019158) overlaps instruction at (ram,0x00019157)
    */

undefined2 FUN_1000_9127(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 uVar3;
  char cVar4;
  char in_CH;
  byte extraout_DL;
  int in_BX;
  byte bVar5;
  byte bVar6;
  uint unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar7;
  
  pbVar1 = (byte *)(unaff_BP + 0x24cb);
  bVar6 = *pbVar1;
  bVar5 = (byte)((uint)in_BX >> 8);
  *pbVar1 = *pbVar1 + bVar5;
  bVar6 = bVar5 + unaff_SI[in_BX + 0x949] + CARRY1(bVar6,bVar5);
  func_0x00018dd1();
  func_0x00018d36();
  *unaff_SI = *unaff_SI & extraout_DL;
  uVar2 = FUN_1000_8ef0();
  if ((uVar2 & 0x60) == 0) {
    *(byte *)(unaff_BP + 0x24fb) = *(byte *)(unaff_BP + 0x24fb) ^ bVar6;
    func_0x00018d52();
    do {
      bVar6 = FUN_1000_8ef0();
      cVar7 = false;
    } while ((bVar6 & 0x60) == 0);
  }
  else {
    cVar7 = CARRY2(uVar2 & 0xff60,unaff_BP);
  }
  func_0x0001d3ee();
  FUN_1000_5d19();
  uVar3 = FUN_1000_8d16();
  cVar4 = (char)((uint)uVar3 >> 8);
  *(char *)(unaff_BP + 2) = *(char *)(unaff_BP + 2) + cVar4 + cVar7;
  return CONCAT11(cVar4,(char)uVar3 + in_CH);
}


