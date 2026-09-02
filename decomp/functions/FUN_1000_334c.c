/* 1000:334c */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_334c(void)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  undefined2 uVar6;
  char in_CL;
  undefined2 in_DX;
  uint uVar7;
  int in_BX;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar12;
  undefined4 uVar13;
  undefined1 uStack_1;
  
  bVar5 = in(in_DX);
  pbVar2 = (byte *)(in_BX + unaff_SI + -0x2f);
  bVar12 = CARRY1(*pbVar2,bVar5) || CARRY1(*pbVar2 + bVar5,in_CF);
  *pbVar2 = *pbVar2 + bVar5 + in_CF;
  puVar8 = &uStack_1;
  uStack_1 = 0x56;
  uVar13 = FUN_1000_5c96();
  puVar9 = (undefined2 *)(puVar8 + -2);
  *(undefined2 *)(puVar8 + -2) = unaff_ES;
  if (bVar12 || unaff_BP + 1 == 0) {
    puVar9 = (undefined2 *)(puVar8 + -4);
    *(undefined2 *)(puVar8 + -4) = 0x3362;
    uVar13 = FUN_1000_3ec3();
  }
  uVar7 = (uint)((ulong)uVar13 >> 0x14) + 1;
  puVar3 = (uint *)(unaff_SI + 6);
  uVar4 = *puVar3;
  *puVar3 = *puVar3 - uVar7;
  bVar12 = *puVar3 == 0;
  if (uVar4 < uVar7 || bVar12) {
    puVar10 = (undefined2 *)((int)puVar9 + -2);
    puVar9 = (undefined2 *)((int)puVar9 + -2);
    *puVar10 = unaff_SS;
    pcVar1 = (char *)(unaff_BP + 1 + unaff_SI);
    *pcVar1 = *pcVar1 + in_CL + (uVar4 < uVar7);
    unaff_DI = unaff_DI | (uint)uVar13;
    bVar12 = unaff_DI == 0;
  }
  if (bVar12) {
    if ((uVar7 & 0x1010) == 0) {
LAB_1000_33cf:
      uVar7 = uVar7 & 0xf0f;
      if (uVar7 != 0x303) {
        if ((char)(uVar7 >> 8) == '\x03') goto LAB_1000_33eb;
        if ((char)uVar7 == '\x03') goto LAB_1000_33f4;
      }
      if (*(uint *)(unaff_SI + 6) < *(uint *)(unaff_DI + 6)) goto LAB_1000_33eb;
    }
    else if ((uVar7 & 0x10) != 0) {
      if ((uVar7 & 0x1000) == 0) goto LAB_1000_33eb;
      goto LAB_1000_33cf;
    }
LAB_1000_33f4:
    uVar6 = *puVar9;
    puVar11 = puVar9 + 1;
  }
  else {
LAB_1000_33eb:
    *(uint *)(unaff_DI + 6) = (uint)uVar13;
    puVar11 = puVar9 + -1;
    puVar9[-1] = 0x33f1;
    uVar6 = FUN_1000_9f38();
  }
  return CONCAT22(*puVar11,uVar6);
}


