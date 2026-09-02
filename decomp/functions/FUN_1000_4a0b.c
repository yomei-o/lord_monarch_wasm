/* 1000:4a0b */

/* WARNING: Instruction at (ram,0x00014a22) overlaps instruction at (ram,0x00014a21)
    */

void FUN_1000_4a0b(void)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  undefined2 in_CX;
  undefined2 uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  int iVar8;
  
  uVar4 = CONCAT11((char)((uint)in_CX >> 8),*(byte *)0x3288);
  if (0x17 < (byte)(*(char *)0x3be5 - *(char *)0x3be3 << (*(byte *)0x3288 & 0x1f))) {
    uVar4 = in_stack_00000000;
  }
  FUN_1000_5e46();
  *unaff_SI = *unaff_SI | (byte)((uint)uVar4 >> 8);
  pbVar1 = unaff_SI + in_BX + 0x59;
  bVar6 = *pbVar1;
  bVar5 = (byte)in_BX;
  *pbVar1 = *pbVar1 + bVar5;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] + (char)uVar4 + CARRY1(bVar6,bVar5);
  cVar3 = in(0x3b);
  cVar2 = *(char *)0x1ee2;
  bVar6 = bVar5 + unaff_SI[in_BX] ^ *(byte *)0xaaaa;
  cVar7 = bVar6 + *unaff_DI;
  iVar8 = CONCAT11((char)((uint)in_BX >> 8),cVar7);
  *(char *)0x18b0 = *(char *)0x18b0 + cVar7 + CARRY1(bVar6,*unaff_DI);
  *(char *)(iVar8 + 1) = ((cVar3 - cVar2) - *(char *)(iVar8 + 3)) + -2;
  return;
}


