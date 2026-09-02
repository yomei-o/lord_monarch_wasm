/* 1000:363e */

undefined2 FUN_1000_363e(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  byte bVar5;
  uint in_AX;
  undefined2 uVar6;
  undefined2 in_CX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined2 in_stack_00000000;
  undefined2 uStack_2;
  
  pbVar1 = (byte *)(in_BX + -0x2d81);
  bVar2 = *pbVar1;
  bVar5 = (byte)in_AX;
  *pbVar1 = *pbVar1 - bVar5;
  if (bVar5 <= bVar2 && *pbVar1 != 0) {
    bVar2 = *(byte *)(unaff_DI + 0x1451);
    bVar7 = CARRY1(bVar2,*unaff_SI);
    uStack_2 = CONCAT11((char)((uint)in_CX >> 8),bVar2 + *unaff_SI);
    pbVar1 = unaff_SI + unaff_BP;
    bVar2 = *pbVar1;
    bVar3 = *pbVar1;
    *pbVar1 = bVar3 + bVar5 + bVar7;
    unaff_SI[unaff_BP] =
         unaff_SI[unaff_BP] + (char)unaff_SS +
         (in_AX < *(uint *)(unaff_SI + unaff_BP) ||
         in_AX - *(uint *)(unaff_SI + unaff_BP) <
         (uint)(CARRY1(bVar2,bVar5) || CARRY1(bVar3 + bVar5,bVar7)));
    pcVar4 = (code *)swi(3);
    uVar6 = (*pcVar4)(&uStack_2);
    return uVar6;
  }
  return in_stack_00000000;
}


