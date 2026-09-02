/* 1000:3b86 */

void __cdecl16near FUN_1000_3b86(void)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar8;
  undefined1 uVar9;
  
  FUN_1000_41b5();
  FUN_1000_9ad3();
  FUN_1000_ad80();
  FUN_1000_9b34();
  if ((((in_CF & 1) == 0) && (bVar4 = ((undefined *)&DAT_0000_d27e)[in_BX], bVar4 < 0x30)) &&
     (bVar8 = bVar4 < 0x1d, bVar4 != 0x1d)) {
    FUN_1000_3d5e();
    if (!bVar8) {
      return;
    }
    FUN_1000_3e21();
    if (!bVar8) {
      return;
    }
    bVar8 = false;
    if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
      FUN_1000_4163();
      if (!bVar8) {
        return;
      }
      pcVar1 = (char *)(unaff_SI + 0xf);
      *pcVar1 = *pcVar1 + -1;
      if (*pcVar1 != '\0') {
        *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
        LOCK();
        iVar7 = *(int *)(unaff_SI + 4);
        *(int *)(unaff_SI + 4) = in_BX;
        UNLOCK();
        *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar7) = 0;
        *(undefined2 *)(unaff_SI + 2) = extraout_DX;
        return;
      }
    }
  }
  cVar3 = FUN_1000_9a24();
  *(char *)(unaff_SI + 0xf) = cVar3 + '\x01';
  cVar3 = *(byte *)(unaff_SI + 1) < 4;
  uVar5 = (uint)(byte)(*(byte *)(unaff_SI + 1) - 4);
  iVar7 = 4;
  do {
    FUN_1000_9ad3();
    FUN_1000_ada4();
    bVar8 = cVar3 == '\0';
    uVar2 = uVar5 >> 8;
    bVar4 = (byte)(uVar2 << 1);
    bVar6 = bVar4 | bVar8;
    cVar3 = 0xfd < (byte)uVar5;
    uVar5 = CONCAT11(bVar6,(byte)uVar5 + 2);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar9 = 0;
  if (bVar6 == 0) {
    cVar3 = *(char *)(unaff_SI + 1);
    iVar7 = 4;
    while( true ) {
      FUN_1000_9ad3();
      FUN_1000_ad80();
      if (!(bool)uVar9) {
        FUN_1000_9b34();
      }
      if ((!(bool)uVar9) &&
         (uVar9 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x7b,
         ((undefined *)&DAT_0000_d27e)[in_BX] == 0x7b)) break;
      cVar3 = cVar3 + '\x01';
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        return;
      }
    }
    *(char *)(unaff_SI + 1) = cVar3;
    pcVar1 = (undefined *)&DAT_0000_d27f + in_BX;
    cVar3 = *pcVar1;
    *pcVar1 = *pcVar1 + -1;
    if (cVar3 != '\0') {
      return;
    }
    *(undefined **)((undefined *)&DAT_0000_d27e + in_BX) = (undefined *)&DAT_0000_6400;
    FUN_1000_484a();
    return;
  }
  if ((uVar2 & 3) != 0 || bVar8) {
    bVar4 = bVar4 & 7 | bVar8;
    cVar3 = '\0';
    if (((bVar4 == 2) || (cVar3 = '\x02', bVar4 == 1)) || (cVar3 = -2, bVar4 == 4))
    goto LAB_1000_3c25;
  }
  bVar4 = FUN_1000_9a24();
  cVar3 = '\x02';
  if (0x31 < bVar4) {
    cVar3 = -2;
  }
LAB_1000_3c25:
  *(byte *)(unaff_SI + 1) = cVar3 + *(char *)(unaff_SI + 1) & 6;
  return;
}


