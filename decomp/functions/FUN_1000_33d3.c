/* 1000:33d3 */

undefined4 FUN_1000_33d3(undefined2 param_1)

{
  undefined2 in_AX;
  int in_DX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  if (in_DX == 0x303) {
LAB_1000_33e3:
    if (*(uint *)(unaff_DI + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3402;
  }
  else if ((char)((uint)in_DX >> 8) != '\x03') {
    if ((char)in_DX == '\x03') goto LAB_1000_3402;
    goto LAB_1000_33e3;
  }
  *(undefined2 *)(unaff_DI + 6) = in_AX;
  in_stack_00000000 = FUN_1000_9f38();
LAB_1000_3402:
  return CONCAT22(param_1,in_stack_00000000);
}


