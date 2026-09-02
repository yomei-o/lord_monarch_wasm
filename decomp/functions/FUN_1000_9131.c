/* 1000:9131 */

/* WARNING: Instruction at (ram,0x00019158) overlaps instruction at (ram,0x00019157)
    */

undefined2 FUN_1000_9131(void)

{
  byte bVar1;
  uint uVar2;
  undefined2 uVar3;
  char cVar4;
  int in_CX;
  int iVar5;
  char cVar6;
  byte extraout_DL;
  byte in_BH;
  uint unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar7;
  
  iVar5 = in_CX + -1;
  func_0x00018d36();
  *unaff_SI = *unaff_SI & extraout_DL;
  uVar2 = FUN_1000_8ef0();
  cVar6 = (char)((uint)iVar5 >> 8);
  if ((uVar2 & 0x60) == 0) {
    *(byte *)(unaff_BP + 0x24fb) = *(byte *)(unaff_BP + 0x24fb) ^ in_BH;
    func_0x00018d52();
    do {
      bVar1 = FUN_1000_8ef0();
      cVar6 = (char)((uint)iVar5 >> 8);
      cVar7 = false;
    } while ((bVar1 & 0x60) == 0);
  }
  else {
    cVar7 = CARRY2(uVar2 & 0xff60,unaff_BP);
  }
  func_0x0001d3ee();
  FUN_1000_5d19();
  uVar3 = FUN_1000_8d16();
  cVar4 = (char)((uint)uVar3 >> 8);
  *(char *)(unaff_BP + 2) = *(char *)(unaff_BP + 2) + cVar4 + cVar7;
  return CONCAT11(cVar4,(char)uVar3 + cVar6);
}


