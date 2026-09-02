/* 1000:8ea9 */

undefined4 FUN_1000_8ea9(undefined2 param_1,undefined2 param_2)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int in_AX;
  uint in_CX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined2 in_stack_00000000;
  
  uVar6 = in_AX * 4;
  uVar4 = *(uint *)0xd274;
  *(uint *)0xd278 = uVar6 | uVar4;
  bVar7 = in_CX < *(uint *)(unaff_BP + unaff_SI);
  pcVar2 = (char *)(uVar6 + unaff_SI);
  cVar3 = *pcVar2;
  cVar5 = *pcVar2 + (char)uVar6;
  *pcVar2 = cVar5 + bVar7;
  if ((SCARRY1(cVar3,(char)uVar6) != SCARRY1(cVar5,bVar7)) == *pcVar2 < '\0') {
    return CONCAT22(param_2,in_stack_00000000);
  }
  piVar1 = (int *)(uVar6 + unaff_SI + -99);
  *piVar1 = *piVar1 + 0x2d8a;
  return CONCAT22(uVar4,0xd276);
}


