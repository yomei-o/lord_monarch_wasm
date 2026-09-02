/* 1000:353b */

/* WARNING: Removing unreachable block (ram,0x0001353e) */

void FUN_1000_353b(void)

{
  byte *pbVar1;
  uint *puVar2;
  unkbyte10 Var3;
  code *pcVar4;
  byte bVar5;
  byte bVar6;
  undefined2 in_AX;
  uint uVar7;
  byte bVar9;
  undefined2 in_CX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  longdouble in_ST0;
  uint in_stack_00000000;
  undefined2 uStack_6;
  undefined2 uStack_4;
  byte bVar8;
  
  bVar6 = (byte)in_AX;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & bVar6;
  swi(4);
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] + bVar6;
  bVar9 = (byte)in_CX;
  *(byte *)(unaff_BP + unaff_DI) = *(byte *)(unaff_BP + unaff_DI) ^ bVar9;
  puVar2 = (uint *)(unaff_BP + unaff_DI);
  uVar7 = *puVar2;
  *puVar2 = *puVar2 + in_stack_00000000;
  *unaff_SI = *unaff_SI + bVar6 + CARRY2(uVar7,in_stack_00000000);
  *(int *)(unaff_SI + in_stack_00000000) = (int)ROUND(in_ST0);
  bVar8 = (byte)((uint)in_AX >> 8);
  uVar7 = CONCAT11(bVar8,bVar6 + 0x4c);
  uStack_4 = 0xffdf;
  *unaff_SI = *unaff_SI & bVar6 + 0x4c;
  *(uint *)(in_stack_00000000 + unaff_DI) = *(uint *)(in_stack_00000000 + unaff_DI) | uVar7;
  Var3 = to_bcd(in_ST0);
  *(unkbyte10 *)(unaff_SI + in_stack_00000000) = Var3;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ bVar8;
  bVar5 = (byte)(uVar7 / *(byte *)(unaff_DI + 3));
  uVar7 = CONCAT11((char)(uVar7 % (uint)*(byte *)(unaff_DI + 3)),bVar5);
  bVar10 = CARRY1(bVar9,*unaff_SI);
  uStack_6 = CONCAT11((char)((uint)in_CX >> 8),bVar9 + *unaff_SI);
  pbVar1 = unaff_SI + unaff_BP;
  bVar6 = *pbVar1;
  bVar8 = *pbVar1;
  *pbVar1 = bVar8 + bVar5 + bVar10;
  unaff_SI[unaff_BP] =
       unaff_SI[unaff_BP] + (char)unaff_SS +
       (uVar7 < *(uint *)(unaff_SI + unaff_BP) ||
       uVar7 - *(uint *)(unaff_SI + unaff_BP) <
       (uint)(CARRY1(bVar6,bVar5) || CARRY1(bVar8 + bVar5,bVar10)));
  pcVar4 = (code *)swi(3);
  (*pcVar4)(&uStack_6);
  return;
}


