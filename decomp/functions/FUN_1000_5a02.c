/* 1000:5a02 */

undefined3 FUN_1000_5a02(void)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  char in_DL;
  char in_DH;
  int *in_BX;
  uint uVar7;
  int unaff_BP;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  uVar5 = 0xe500;
  if ((*unaff_DI != '\0') && (*unaff_DI != -0x1b)) {
    *(char *)((int)in_BX + unaff_SI) = *(char *)((int)in_BX + unaff_SI) - (in_DH + (char)in_BX);
    uVar5 = 0x6a;
  }
  LOCK();
  cVar3 = *(char *)((int)in_BX + unaff_SI);
  *(char *)((int)in_BX + unaff_SI) = in_DL;
  UNLOCK();
  *in_BX = *in_BX + -1;
  uVar7 = (uint)((int)in_BX * 3) >> 1;
  uVar6 = 0xf000;
  if (((int)in_BX * 3 & 1U) != 0) {
    uVar5 = uVar5 << 4;
    uVar6 = 0xf;
  }
  *(char *)(unaff_BP + (int)in_BX) = *(char *)(unaff_BP + (int)in_BX) + (char)uVar6;
  *(uint *)(uVar7 + (int)in_BX) = *(uint *)(uVar7 + (int)in_BX) & uVar6;
  puVar1 = (uint *)(uVar7 + (int)in_BX);
  *puVar1 = *puVar1 | uVar5;
  if (0 < (int)*puVar1) {
    cVar4 = *(char *)(uVar7 + 0x77);
    piVar2 = (int *)((int)in_BX + uVar7 + 0x1c4d);
    *piVar2 = *piVar2 - (int)in_BX;
    return CONCAT12(cVar3 + cVar4,in_stack_00000000);
  }
  return CONCAT12(cVar3,in_stack_00000000);
}


