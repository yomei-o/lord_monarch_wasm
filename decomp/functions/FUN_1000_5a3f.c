/* 1000:5a3f */

undefined3 FUN_1000_5a3f(void)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  uint in_AX;
  char in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  puVar1 = (uint *)(in_BX + unaff_SI);
  *puVar1 = *puVar1 | in_AX;
  if (0 < (int)*puVar1) {
    cVar3 = *(char *)(in_BX + 0x77);
    piVar2 = (int *)(in_BX + unaff_SI + 0x1c4d);
    *piVar2 = *piVar2 - unaff_SI;
    return CONCAT12(in_DL + cVar3,in_stack_00000000);
  }
  return CONCAT12(in_DL,in_stack_00000000);
}


