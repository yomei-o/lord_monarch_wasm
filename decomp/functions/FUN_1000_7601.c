/* 1000:7601 */

undefined4 FUN_1000_7601(void)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  undefined2 in_AX;
  byte bVar6;
  byte bVar7;
  uint in_DX;
  int in_BX;
  char *unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  uVar3 = *(uint *)(unaff_SI + in_BX + -0x5f);
  bVar6 = (byte)((uint)in_AX >> 8);
  bVar4 = in(0x3b);
  bVar7 = bVar6 - 0xc;
  if (bVar6 < 0xc) {
    bVar7 = 0;
  }
  if (0x17 < bVar7) {
    bVar7 = 0x18;
  }
  cVar5 = bVar4 - 0xd;
  unaff_SI[in_BX] = unaff_SI[in_BX] + (char)in_BX + (bVar4 < 0xd);
  pcVar1 = unaff_SI;
  cVar2 = *pcVar1;
  *pcVar1 = *pcVar1 >> 0x18;
  if ((cVar2 >> 0x17 & 1U) == 0) {
    cVar5 = '\x18';
  }
  *(undefined2 *)0x3be2 = CONCAT11(bVar7,cVar5);
  return CONCAT22(in_DX & uVar3,in_stack_00000000);
}


