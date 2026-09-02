/* 1000:334f */

undefined4 FUN_1000_334f(undefined2 param_1)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  char in_CL;
  undefined2 in_DX;
  uint uVar6;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar7;
  undefined4 uVar8;
  
  bVar5 = in(in_DX);
  pbVar2 = (byte *)(in_BX + unaff_SI + -0x2f);
  bVar7 = CARRY1(*pbVar2,bVar5) || CARRY1(*pbVar2 + bVar5,in_CF);
  *pbVar2 = *pbVar2 + bVar5 + in_CF;
  uVar8 = FUN_1000_5c96();
  if (bVar7 || unaff_BP + 1 == 0) {
    uVar8 = FUN_1000_3ec3();
  }
  uVar6 = (uint)((ulong)uVar8 >> 0x14) + 1;
  puVar3 = (uint *)(unaff_SI + 6);
  uVar4 = *puVar3;
  *puVar3 = *puVar3 - uVar6;
  bVar7 = *puVar3 == 0;
  if (uVar4 < uVar6 || bVar7) {
    pcVar1 = (char *)(unaff_BP + 1 + unaff_SI);
    *pcVar1 = *pcVar1 + in_CL + (uVar4 < uVar6);
    unaff_DI = unaff_DI | (uint)uVar8;
    bVar7 = unaff_DI == 0;
  }
  if (bVar7) {
    if ((uVar6 & 0x1010) != 0) {
      if ((uVar6 & 0x10) == 0) goto LAB_1000_3402;
      if ((uVar6 & 0x1000) == 0) goto LAB_1000_33eb;
    }
    uVar6 = uVar6 & 0xf0f;
    if (uVar6 != 0x303) {
      if ((char)(uVar6 >> 8) == '\x03') goto LAB_1000_33eb;
      if ((char)uVar6 == '\x03') goto LAB_1000_3402;
    }
    if (*(uint *)(unaff_DI + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3402;
  }
LAB_1000_33eb:
  *(uint *)(unaff_DI + 6) = (uint)uVar8;
  unaff_ES = FUN_1000_9f38();
LAB_1000_3402:
  return CONCAT22(param_1,unaff_ES);
}


