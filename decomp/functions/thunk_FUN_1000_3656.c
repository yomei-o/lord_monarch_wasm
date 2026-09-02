/* 1000:3575 */

void thunk_FUN_1000_3656(void)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  uint in_AX;
  byte bVar4;
  undefined2 in_CX;
  int unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  undefined2 uStack_2;
  
  bVar4 = (byte)in_CX;
  bVar5 = CARRY1(bVar4,*unaff_SI);
  uStack_2 = CONCAT11((char)((uint)in_CX >> 8),bVar4 + *unaff_SI);
  pbVar1 = unaff_SI + unaff_BP;
  bVar4 = *pbVar1;
  bVar2 = *pbVar1 + (byte)in_AX;
  *pbVar1 = bVar2 + bVar5;
  unaff_SI[unaff_BP] =
       unaff_SI[unaff_BP] + (char)unaff_SS +
       (in_AX < *(uint *)(unaff_SI + unaff_BP) ||
       in_AX - *(uint *)(unaff_SI + unaff_BP) <
       (uint)(CARRY1(bVar4,(byte)in_AX) || CARRY1(bVar2,bVar5)));
  pcVar3 = (code *)swi(3);
  (*pcVar3)(&uStack_2);
  return;
}


