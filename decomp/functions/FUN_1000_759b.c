/* 1000:759b */

undefined4 __cdecl16near FUN_1000_759b(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 in_AX;
  uint uVar3;
  int iVar4;
  undefined2 in_DX;
  byte *unaff_SI;
  byte *pbVar5;
  int unaff_DI;
  byte *pbVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  uint local_14;
  undefined2 uVar9;
  
  uVar9 = 0;
  local_14 = 0x50;
  iVar4 = 0xa0;
  pbVar5 = unaff_SI;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pbVar1 = pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (*pbVar1 != 0);
LAB_1000_75d1:
  do {
    pbVar5 = unaff_SI + 1;
    bVar2 = *unaff_SI;
    if (bVar2 < 0x20) {
      if ((bVar2 == 0) || (bVar2 < 0x10)) goto LAB_1000_78b0;
      *(char *)0x32a9 = bVar2 - 0x10;
      unaff_SI = pbVar5;
      goto LAB_1000_75d1;
    }
    if (bVar2 == 0x20) {
joined_r0x0001762c:
      unaff_SI = pbVar5;
      local_14 = local_14 - 1;
      unaff_DI = unaff_DI + 1;
      if (local_14 == 0) goto LAB_1000_78b0;
    }
    else {
      if (bVar2 == 0x40) {
        pbVar1 = pbVar5;
        pbVar5 = unaff_SI + 2;
        bVar2 = *pbVar1;
        iVar4 = 0x1c;
        pbVar6 = (byte *)0x2847;
        bVar7 = true;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pbVar1 = pbVar6;
          pbVar6 = pbVar6 + 1;
          bVar7 = bVar2 == *pbVar1;
        } while (!bVar7);
        if (bVar7) {
                    /* WARNING: Could not recover jumptable at 0x00017664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar8 = (*(code *)*(undefined2 *)((int)(pbVar6 + -0x2848) * 2 + 0x78bb))(uVar9);
          return uVar8;
        }
      }
      if ((bVar2 < 0x80) || ((0x9f < bVar2 && (bVar2 < 0xe0)))) {
        FUN_1000_7a52();
        goto joined_r0x0001762c;
      }
      if (CONCAT11(bVar2,*pbVar5) != 0x4081) {
        uVar3 = FUN_1000_9a54();
        if ((0x2920 < uVar3) && (uVar3 < 0x2b7f)) {
          FUN_1000_72d0();
          FUN_1000_79f5();
          pbVar5 = pbVar5 + 1;
          goto joined_r0x0001762c;
        }
        FUN_1000_72d0();
        FUN_1000_7958();
      }
      unaff_DI = unaff_DI + 2;
      bVar7 = local_14 < 2;
      unaff_SI = pbVar5 + 1;
      local_14 = local_14 - 2;
      if (bVar7) {
LAB_1000_78b0:
        *(int *)0x3e76 = unaff_DI;
        return CONCAT22(in_DX,in_AX);
      }
    }
  } while( true );
}


