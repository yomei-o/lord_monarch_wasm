/* 1000:355d */

void FUN_1000_355d(void)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  uint in_AX;
  byte bVar6;
  undefined2 in_CX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined2 uStack_2;
  
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ (byte)(in_AX >> 8);
  bVar4 = (byte)(in_AX / *(byte *)(unaff_DI + 3));
  uVar5 = CONCAT11((char)(in_AX % (uint)*(byte *)(unaff_DI + 3)),bVar4);
  bVar6 = (byte)in_CX;
  bVar7 = CARRY1(bVar6,*unaff_SI);
  uStack_2 = CONCAT11((char)((uint)in_CX >> 8),bVar6 + *unaff_SI);
  pbVar1 = unaff_SI + unaff_BP;
  bVar6 = *pbVar1;
  bVar2 = *pbVar1;
  *pbVar1 = bVar2 + bVar4 + bVar7;
  unaff_SI[unaff_BP] =
       unaff_SI[unaff_BP] + (char)unaff_SS +
       (uVar5 < *(uint *)(unaff_SI + unaff_BP) ||
       uVar5 - *(uint *)(unaff_SI + unaff_BP) <
       (uint)(CARRY1(bVar6,bVar4) || CARRY1(bVar2 + bVar4,bVar7)));
  pcVar3 = (code *)swi(3);
  (*pcVar3)(&uStack_2);
  return;
}


