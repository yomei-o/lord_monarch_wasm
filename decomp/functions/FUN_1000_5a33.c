/* 1000:5a33 */

undefined3 FUN_1000_5a33(void)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  int in_AX;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + '\x0f' + (in_AX << 1 < 0);
  *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) & 0xf;
  puVar1 = (uint *)(in_BX + unaff_SI);
  *puVar1 = *puVar1 | in_AX << 2;
  if (0 < (int)*puVar1) {
    cVar3 = *(char *)(in_BX + 0x77);
    piVar2 = (int *)(in_BX + unaff_SI + 0x1c4d);
    *piVar2 = *piVar2 - unaff_SI;
    return CONCAT12(in_DL + cVar3,in_stack_00000000);
  }
  return CONCAT12(in_DL,in_stack_00000000);
}


