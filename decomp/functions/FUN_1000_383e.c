/* 1000:383e */

void __cdecl16near FUN_1000_383e(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  int extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  int in_BX;
  uint uVar4;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
  iVar1 = *(int *)(unaff_SI + 4);
  FUN_1000_a98d();
  if ((bool)in_CF) {
    return;
  }
  FUN_1000_41b5();
  bVar5 = *(char *)(unaff_SI + 0xb) != -1;
  if (*(char *)(unaff_SI + 0xb) != -1) {
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
      bVar5 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30;
      if (bVar5) {
        FUN_1000_3d5e();
        if (!bVar5) {
          return;
        }
        FUN_1000_3e21();
        if (!bVar5) {
          return;
        }
        bVar5 = false;
        if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
          FUN_1000_4163();
          if (!bVar5) {
            return;
          }
          *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
          LOCK();
          iVar1 = *(int *)(unaff_SI + 4);
          *(int *)(unaff_SI + 4) = in_BX;
          UNLOCK();
          *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar1) = 0;
          *(undefined2 *)(unaff_SI + 2) = extraout_DX_01;
          FUN_1000_c2c0();
          return;
        }
      }
      else if (*(char *)0x3c00 != *(char *)(unaff_SI + 0xc)) {
        uVar7 = 7;
        if (((undefined *)&DAT_0000_d27e)[in_BX] != 'z') {
          if (((undefined *)&DAT_0000_d27e)[in_BX] != '{') goto LAB_1000_3a3e;
          uVar7 = 9;
        }
        *(undefined1 *)(unaff_SI + 10) = uVar7;
        *(undefined2 *)(unaff_SI + 8) = extraout_DX_00;
        *(undefined1 *)(unaff_SI + 0xb) = 0xff;
        return;
      }
    }
LAB_1000_3a3e:
    *(undefined1 *)(unaff_SI + 10) = 1;
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    return;
  }
  FUN_1000_3d2c();
  if (!bVar5) {
    return;
  }
  uVar4 = *(byte *)(unaff_SI + 10) & 0xf;
  uVar6 = CARRY2(uVar4,uVar4);
  uVar7 = (*(byte *)(unaff_SI + 10) & 0xf) == 0;
  switch(uVar4) {
  default:
    *(undefined1 *)(unaff_SI + 1) = 6;
    return;
  case 1:
  case 3:
    FUN_1000_3ec7();
    if (!(bool)uVar6) {
      return;
    }
    FUN_1000_adbe();
    if (!(bool)uVar6) {
      FUN_1000_4881();
      return;
    }
    bVar5 = 0xf7 < *(byte *)(unaff_SI + 0xc);
    uVar7 = FUN_1000_af42();
    if (!bVar5) {
      *(undefined1 *)(unaff_SI + 1) = uVar7;
      uVar7 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar7;
      FUN_1000_c231();
      return;
    }
    return;
  case 2:
    FUN_1000_3ec7();
    *(undefined1 *)(unaff_SI + 1) = 6;
    bVar3 = ((undefined *)&DAT_0000_d27e)[iVar1] - 0x14;
    if (bVar3 < 4) {
      bVar5 = bVar3 < *(byte *)(unaff_SI + 0xc);
      if (bVar3 != *(byte *)(unaff_SI + 0xc)) {
        return;
      }
    }
    else {
      bVar3 = ((undefined *)&DAT_0000_d27a)[iVar1] - 0x14;
      bVar5 = false;
      if ((bVar3 < 4) &&
         (bVar5 = bVar3 < *(byte *)(unaff_SI + 0xc), bVar3 != *(byte *)(unaff_SI + 0xc))) {
        if (*(int *)((undefined *)&DAT_0000_e47a + iVar1) == 0) {
          return;
        }
        uVar4 = *(uint *)(*(int *)((undefined *)&DAT_0000_e47a + iVar1) + 6);
        if ((extraout_DX << 1 | (uint)((int)uVar4 < 0)) + extraout_DX +
            (uint)CARRY2(uVar4 * 2,uVar4) != 0) {
          return;
        }
        if (*(uint *)(unaff_SI + 6) <= uVar4 * 3) {
          return;
        }
        FUN_1000_47e9();
        return;
      }
    }
    FUN_1000_adbe();
    if (!bVar5) {
      FUN_1000_4881();
    }
    return;
  case 4:
    bVar3 = FUN_1000_a61d();
    bVar5 = 0xf7 < bVar3;
    cVar2 = FUN_1000_b037();
    if (!bVar5) {
      *(char *)(unaff_SI + 1) = cVar2 << 1;
      uVar7 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar7;
      if (-1 < cVar2) {
        FUN_1000_c231();
        return;
      }
      FUN_1000_c25c();
      return;
    }
    break;
  case 5:
    FUN_1000_3ec7();
    if (!(bool)uVar6) {
      return;
    }
    if (!(bool)uVar7) {
      bVar3 = FUN_1000_a61d();
      bVar5 = 0xf7 < bVar3;
      uVar7 = FUN_1000_af6f();
      if (!bVar5) {
        *(undefined1 *)(unaff_SI + 1) = uVar7;
        uVar7 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar7;
        FUN_1000_c25c();
        return;
      }
    }
    break;
  case 6:
    FUN_1000_3f62();
    if ((bool)uVar6) {
      if ((bool)uVar7) break;
      FUN_1000_9b34();
      FUN_1000_4163();
      uVar7 = uVar6;
    }
    if (!(bool)uVar7) {
      return;
    }
    break;
  case 7:
    FUN_1000_4040();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 8:
    FUN_1000_3f2a();
    if (((!(bool)uVar6) && (!(bool)uVar7)) || (FUN_1000_3ec7(), !(bool)uVar6)) {
      return;
    }
    uVar7 = FUN_1000_af05();
    if (!(bool)uVar6) {
      *(undefined1 *)(unaff_SI + 1) = uVar7;
      uVar7 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar7;
      FUN_1000_c231();
      return;
    }
    break;
  case 9:
    FUN_1000_41dc();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 10:
    FUN_1000_4247();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 0xb:
    FUN_1000_4304();
    if ((!(bool)uVar6) && (!(bool)uVar7)) {
      return;
    }
    break;
  case 0xc:
    *(undefined1 *)(unaff_SI + 0xc) =
         *(undefined1 *)
          (*(int *)((undefined *)&DAT_0000_12ef + (uint)*(byte *)(unaff_SI + 0xc) * 2) + 0x15);
  }
  *(undefined1 *)(unaff_SI + 10) = 1;
  return;
}


