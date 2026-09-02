/* 1000:336a */

undefined4 FUN_1000_336a(undefined2 param_1)

{
  uint *puVar1;
  uint uVar2;
  uint in_AX;
  char in_CL;
  uint in_DX;
  uint uVar3;
  int unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar4;
  undefined2 in_stack_00000000;
  
  uVar3 = (in_DX >> 1) + 1;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - uVar3;
  bVar4 = *puVar1 == 0;
  if (uVar2 < uVar3 || bVar4) {
    *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + in_CL + (uVar2 < uVar3);
    unaff_DI = unaff_DI | in_AX;
    bVar4 = unaff_DI == 0;
  }
  if (bVar4) {
    if ((uVar3 & 0x1010) != 0) {
      if ((uVar3 & 0x10) == 0) goto LAB_1000_3402;
      if ((uVar3 & 0x1000) == 0) goto LAB_1000_33eb;
    }
    uVar3 = uVar3 & 0xf0f;
    if (uVar3 != 0x303) {
      if ((char)(uVar3 >> 8) == '\x03') goto LAB_1000_33eb;
      if ((char)uVar3 == '\x03') goto LAB_1000_3402;
    }
    if (*(uint *)(unaff_DI + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3402;
  }
LAB_1000_33eb:
  *(uint *)(unaff_DI + 6) = in_AX;
  in_stack_00000000 = FUN_1000_9f38();
LAB_1000_3402:
  return CONCAT22(param_1,in_stack_00000000);
}


