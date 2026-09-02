/* 1000:077d */

undefined4 FUN_1000_077d(void)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined2 in_AX;
  int iVar5;
  byte bVar6;
  int iVar7;
  int unaff_BP;
  int unaff_SI;
  byte *pbVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  undefined2 in_stack_00000008;
  undefined2 in_stack_0000000c;
  
  out(0x43,0x14);
  uVar4 = in(0x41);
  piVar1 = (int *)(unaff_BP + unaff_SI + -100);
  *piVar1 = *piVar1 + CONCAT11((char)((uint)in_AX >> 8),uVar4) + (uint)in_CF;
  pbVar8 = (byte *)&DAT_0000_0564;
  iVar7 = 0;
  iVar5 = 2;
  bVar6 = 0;
  do {
    bVar3 = *pbVar8;
    *(byte *)(iVar7 + 0x32f2) = *(byte *)(iVar7 + 0x32f2) | bVar3;
    LOCK();
    bVar2 = ((undefined1 *)&DAT_0000_32f3)[iVar7];
    ((undefined1 *)&DAT_0000_32f3)[iVar7] = bVar3;
    UNLOCK();
    bVar6 = bVar6 | bVar2 ^ bVar3;
    pbVar8 = pbVar8 + 8;
    iVar7 = iVar7 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((bVar6 & 8) != 0) {
    out(0x37,6);
    iVar5 = 0x1000;
    do {
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    out(0x37,7);
  }
  return CONCAT22(in_stack_00000008,in_stack_0000000c);
}


