/* 1000:3651 */

void FUN_1000_3651(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  uint in_AX;
  undefined2 in_CX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  undefined2 auStack_4 [2];
  
  bVar2 = *(byte *)(unaff_DI + 0x1451);
  bVar5 = CARRY1(bVar2,*unaff_SI);
  auStack_4[0] = CONCAT11((char)((uint)in_CX >> 8),bVar2 + *unaff_SI);
  pbVar1 = unaff_SI + unaff_BP;
  bVar2 = *pbVar1;
  bVar3 = *pbVar1 + (byte)in_AX;
  *pbVar1 = bVar3 + bVar5;
  unaff_SI[unaff_BP] =
       unaff_SI[unaff_BP] + (char)unaff_SS +
       (in_AX < *(uint *)(unaff_SI + unaff_BP) ||
       in_AX - *(uint *)(unaff_SI + unaff_BP) <
       (uint)(CARRY1(bVar2,(byte)in_AX) || CARRY1(bVar3,bVar5)));
  pcVar4 = (code *)swi(3);
  (*pcVar4)(auStack_4);
  return;
}


