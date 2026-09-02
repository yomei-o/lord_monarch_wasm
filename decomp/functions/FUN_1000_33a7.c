/* 1000:33a7 */

undefined4 FUN_1000_33a7(undefined2 param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  if (CARRY2(*(uint *)(unaff_SI + 6),*(uint *)(unaff_DI + 6))) goto LAB_1000_3402;
  bVar1 = *(byte *)(unaff_SI + 10);
  bVar2 = *(byte *)(unaff_DI + 10);
  if ((bVar1 & 0x20) != 0) goto LAB_1000_3402;
  if ((bVar2 & 0x20) == 0) {
    if ((CONCAT11(bVar1,bVar2) & 0x1010) != 0) {
      if ((bVar2 & 0x10) == 0) goto LAB_1000_3402;
      if ((bVar1 & 0x10) == 0) goto LAB_1000_33eb;
    }
    uVar3 = CONCAT11(bVar1,bVar2) & 0xf0f;
    if (uVar3 != 0x303) {
      if ((char)(uVar3 >> 8) == '\x03') goto LAB_1000_33eb;
      if ((char)uVar3 == '\x03') goto LAB_1000_3402;
    }
    if (*(uint *)(unaff_DI + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3402;
  }
LAB_1000_33eb:
  *(int *)(unaff_DI + 6) = *(uint *)(unaff_SI + 6) + *(uint *)(unaff_DI + 6);
  in_stack_00000000 = FUN_1000_9f38();
LAB_1000_3402:
  return CONCAT22(param_1,in_stack_00000000);
}


