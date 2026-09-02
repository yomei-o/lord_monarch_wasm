/* 1000:33bf */

undefined4 FUN_1000_33bf(undefined2 param_1)

{
  undefined2 in_AX;
  uint in_DX;
  uint uVar1;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  if ((in_DX & 0x1010) == 0) {
LAB_1000_33cf:
    uVar1 = in_DX & 0xf0f;
    if (uVar1 != 0x303) {
      if ((char)(uVar1 >> 8) == '\x03') goto LAB_1000_33eb;
      if ((char)uVar1 == '\x03') goto LAB_1000_3402;
    }
    if (*(uint *)(unaff_DI + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3402;
  }
  else {
    if ((in_DX & 0x10) == 0) goto LAB_1000_3402;
    if ((in_DX & 0x1000) != 0) goto LAB_1000_33cf;
  }
LAB_1000_33eb:
  *(undefined2 *)(unaff_DI + 6) = in_AX;
  in_stack_00000000 = FUN_1000_9f38();
LAB_1000_3402:
  return CONCAT22(param_1,in_stack_00000000);
}


