/* 1000:c33e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_c33e(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  undefined2 in_AX;
  uint uVar6;
  int iVar7;
  undefined2 in_DX;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *unaff_DI;
  
  pbVar8 = (byte *)(_DAT_2000_6000 + 0x6000);
  pbVar10 = (byte *)0x6002;
  while (pbVar10 != pbVar8) {
    pbVar9 = pbVar10 + 1;
    bVar3 = *pbVar10;
    if ((bVar3 & 0x80) == 0) {
      if ((bVar3 & 0x40) == 0) {
        if ((bVar3 & 0x20) == 0) {
          for (uVar6 = (uint)bVar3; pbVar10 = pbVar9, uVar6 != 0; uVar6 = uVar6 - 1) {
            pbVar5 = unaff_DI;
            unaff_DI = unaff_DI + 1;
            pbVar1 = pbVar9;
            pbVar9 = pbVar9 + 1;
            *pbVar5 = *pbVar1;
          }
        }
        else {
          for (uVar6 = CONCAT11(bVar3,*pbVar9) & 0x1fff; pbVar9 = pbVar9 + 1, pbVar10 = pbVar9,
              uVar6 != 0; uVar6 = uVar6 - 1) {
            pbVar1 = unaff_DI;
            unaff_DI = unaff_DI + 1;
            *pbVar1 = *pbVar9;
          }
        }
      }
      else if ((bVar3 & 0x10) == 0) {
        pbVar10 = pbVar10 + 2;
        bVar4 = *pbVar9;
        for (iVar7 = (bVar3 & 0xf) + 4; iVar7 != 0; iVar7 = iVar7 + -1) {
          pbVar1 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          *pbVar1 = bVar4;
        }
      }
      else {
        pbVar2 = pbVar10 + 3;
        bVar4 = pbVar10[2];
        for (iVar7 = (CONCAT11(bVar3,*pbVar9) & 0xfff) + 4; pbVar10 = pbVar2, iVar7 != 0;
            iVar7 = iVar7 + -1) {
          pbVar1 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          *pbVar1 = bVar4;
        }
      }
    }
    else {
      pbVar10 = pbVar10 + 2;
      pbVar9 = (byte *)-((CONCAT11(bVar3,*pbVar9) & 0x1fff) - (int)unaff_DI);
      for (uVar6 = (uint)(byte)((((char)((bVar3 & 0x60) << 1) < '\0') << 1 | (bVar3 & 0x20) != 0) +
                               4); uVar6 != 0; uVar6 = uVar6 - 1) {
        pbVar5 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        pbVar1 = pbVar9;
        pbVar9 = pbVar9 + 1;
        *pbVar5 = *pbVar1;
      }
      while( true ) {
        if (pbVar10 == pbVar8) goto LAB_1000_c3df;
        if ((*pbVar10 & 0xe0) != 0x60) break;
        pbVar1 = pbVar10;
        pbVar10 = pbVar10 + 1;
        for (uVar6 = (uint)(*pbVar1 & 0x1f); uVar6 != 0; uVar6 = uVar6 - 1) {
          pbVar5 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          pbVar1 = pbVar9;
          pbVar9 = pbVar9 + 1;
          *pbVar5 = *pbVar1;
        }
      }
    }
  }
LAB_1000_c3df:
  return CONCAT22(in_DX,in_AX);
}


