/* 1000:3a67 */

void __cdecl16near FUN_1000_3a67(void)

{
  char *pcVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  int iVar5;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar6;
  undefined1 uVar7;
  
  iVar5 = *(int *)(unaff_SI + 4);
  bVar3 = *(char *)(unaff_SI + 0xc) + 0x14;
  bVar6 = bVar3 < (byte)((undefined *)&DAT_0000_d27e)[iVar5];
  if (bVar3 != ((undefined *)&DAT_0000_d27e)[iVar5]) {
    FUN_1000_a98d();
    if (bVar6) {
      return;
    }
  }
  FUN_1000_3c7f();
  FUN_1000_41b5();
  bVar6 = *(char *)(unaff_SI + 0xb) != -1;
  if (*(char *)(unaff_SI + 0xb) == -1) {
    FUN_1000_3d2c();
    if (!bVar6) {
      return;
    }
    *(undefined1 *)(unaff_SI + 1) = 6;
    if ((((*(int *)0x3bce == 0) || (0x13 < *(uint *)0x3bc2)) &&
        (*(char *)(unaff_SI + 0xc) != *(char *)0x3c00)) &&
       ((*(char *)(unaff_SI + 0xc) == (char)(((undefined *)&DAT_0000_d27e)[iVar5] + -0x14) &&
        (iVar5 = *(int *)((undefined *)&DAT_0000_e482 + iVar5), iVar5 != 0)))) {
      uVar4 = FUN_1000_a61d();
      if (((char)uVar4 != *(char *)(iVar5 + 0xc)) &&
         (((char)((uint)uVar4 >> 8) != *(char *)(iVar5 + 0xc) &&
          (uVar7 = *(uint *)(iVar5 + 6) < *(uint *)(unaff_SI + 6), (bool)uVar7)))) {
        FUN_1000_9ad3();
        FUN_1000_ad80();
        if (!(bool)uVar7) {
          FUN_1000_9b34();
          if (((byte)((undefined *)&DAT_0000_d27e)[iVar5] < 0x30) &&
             (*(int *)((undefined *)&DAT_0000_e47e + iVar5) == 0)) {
            *(int *)((undefined *)&DAT_0000_e47e + iVar5) = unaff_SI;
            LOCK();
            iVar2 = *(int *)(unaff_SI + 4);
            *(int *)(unaff_SI + 4) = iVar5;
            UNLOCK();
            *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar2) = 0;
            *(undefined2 *)(unaff_SI + 2) = extraout_DX;
            *(undefined1 *)(unaff_SI + 1) = 2;
            uVar7 = FUN_1000_b78c();
            *(undefined1 *)(unaff_SI + 0xb) = uVar7;
            FUN_1000_c231();
            return;
          }
        }
      }
    }
    return;
  }
  bVar3 = FUN_1000_c291();
  uVar7 = *(byte *)(unaff_SI + 1) < bVar3;
  if (*(byte *)(unaff_SI + 1) != bVar3) {
    *(byte *)(unaff_SI + 0xe) = bVar3;
    *(byte *)(unaff_SI + 1) = bVar3;
    return;
  }
  FUN_1000_9ad3();
  FUN_1000_ad80();
  if (!(bool)uVar7) {
    FUN_1000_9b34();
    bVar6 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30;
    if (bVar6) {
      FUN_1000_3d5e();
      if (!bVar6) {
        return;
      }
      FUN_1000_3e21();
      if (!bVar6) {
        return;
      }
      bVar6 = false;
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
        FUN_1000_4163();
        if (!bVar6) {
          return;
        }
        *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
        LOCK();
        iVar5 = *(int *)(unaff_SI + 4);
        *(int *)(unaff_SI + 4) = in_BX;
        UNLOCK();
        *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar5) = 0;
        *(undefined2 *)(unaff_SI + 2) = extraout_DX_00;
        FUN_1000_c2c0();
        return;
      }
    }
    bVar6 = false;
    pcVar1 = (char *)(unaff_SI + 0xf);
    *pcVar1 = *pcVar1 + -1;
    if (*pcVar1 == '\0') {
      *(undefined1 *)(unaff_SI + 0xf) = 1;
      FUN_1000_adbe();
      if (!bVar6) {
        FUN_1000_48df();
        return;
      }
    }
    return;
  }
  *(undefined1 *)(unaff_SI + 0xb) = 0xff;
  return;
}


