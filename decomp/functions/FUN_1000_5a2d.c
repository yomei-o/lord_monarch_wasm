/* 1000:5a2d */

undefined3 FUN_1000_5a2d(void)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  uint in_AX;
  uint uVar4;
  uint in_CX;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  undefined2 in_stack_00000000;
  
  uVar4 = in_AX;
  if (in_CF) {
    uVar4 = in_AX << 4;
    in_CX = 0xf;
  }
  *(char *)(unaff_BP + unaff_SI) =
       *(char *)(unaff_BP + unaff_SI) + (char)in_CX + (in_CF && (int)(in_AX << 3) < 0);
  *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) & in_CX;
  puVar1 = (uint *)(in_BX + unaff_SI);
  *puVar1 = *puVar1 | uVar4;
  if (0 < (int)*puVar1) {
    cVar3 = *(char *)(in_BX + 0x77);
    piVar2 = (int *)(in_BX + unaff_SI + 0x1c4d);
    *piVar2 = *piVar2 - unaff_SI;
    return CONCAT12(in_DL + cVar3,in_stack_00000000);
  }
  return CONCAT12(in_DL,in_stack_00000000);
}


