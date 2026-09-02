/* 1000:3608 */

void __cdecl16near FUN_1000_3608(void)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 extraout_DX;
  int in_BX;
  uint uVar6;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar7;
  undefined1 uVar8;
  
  FUN_1000_a98d();
  if ((bool)in_CF) {
    return;
  }
  FUN_1000_41b5();
  bVar7 = *(char *)(unaff_SI + 0xb) != -1;
  if (*(char *)(unaff_SI + 0xb) != -1) {
    bVar5 = FUN_1000_c291();
    uVar8 = *(byte *)(unaff_SI + 1) < bVar5;
    if (*(byte *)(unaff_SI + 1) != bVar5) {
      *(byte *)(unaff_SI + 0xe) = bVar5;
      *(byte *)(unaff_SI + 1) = bVar5;
      return;
    }
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if ((bool)uVar8) {
      *(undefined1 *)(unaff_SI + 10) = 1;
      *(undefined1 *)(unaff_SI + 0xb) = 0xff;
      return;
    }
    FUN_1000_9b34();
    bVar7 = (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30;
    if (bVar7) {
      FUN_1000_3d5e();
      if (!bVar7) {
        return;
      }
      FUN_1000_3e21();
      if (!bVar7) {
        return;
      }
      bVar7 = false;
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
        FUN_1000_4163();
        if (!bVar7) {
          return;
        }
        *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
        LOCK();
        iVar2 = *(int *)(unaff_SI + 4);
        *(int *)(unaff_SI + 4) = in_BX;
        UNLOCK();
        *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar2) = 0;
        *(undefined2 *)(unaff_SI + 2) = extraout_DX;
        FUN_1000_c2c0();
        return;
      }
    }
    bVar7 = false;
    pcVar1 = (char *)(unaff_SI + 0xf);
    *pcVar1 = *pcVar1 + -1;
    if (*pcVar1 == '\0') {
      *(undefined1 *)(unaff_SI + 0xf) = 1;
      FUN_1000_adbe();
      if (!bVar7) {
        FUN_1000_48df();
        return;
      }
    }
    return;
  }
  FUN_1000_3d2c();
  if (!bVar7) {
    return;
  }
  uVar6 = *(byte *)(unaff_SI + 10) & 0xf;
  uVar8 = CARRY2(uVar6,uVar6);
  bVar7 = (*(byte *)(unaff_SI + 10) & 0xf) == 0;
  switch(uVar6) {
  default:
    *(undefined1 *)(unaff_SI + 1) = 6;
    return;
  case 1:
  case 3:
    FUN_1000_adbe();
    if (!(bool)uVar8) {
      FUN_1000_4881();
      return;
    }
    bVar7 = 0xf7 < *(byte *)(unaff_SI + 0xc);
    uVar8 = FUN_1000_af42();
    if (!bVar7) {
      *(undefined1 *)(unaff_SI + 1) = uVar8;
      uVar8 = FUN_1000_b78c();
      *(undefined1 *)(unaff_SI + 0xb) = uVar8;
      FUN_1000_c231();
      return;
    }
    return;
  case 2:
    FUN_1000_3ec7();
    *(undefined1 *)(unaff_SI + 1) = 6;
    return;
  case 4:
    FUN_1000_3e98();
    if ((bool)uVar8) {
      FUN_1000_3807();
      bVar5 = FUN_1000_a61d();
      bVar7 = 0xf7 < bVar5;
      cVar3 = FUN_1000_b037();
      if (!bVar7) {
        *(char *)(unaff_SI + 1) = cVar3 << 1;
        uVar8 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar8;
        if (-1 < cVar3) {
          FUN_1000_c231();
          return;
        }
        FUN_1000_c25c();
        return;
      }
      FUN_1000_adbe();
      if ((!bVar7) && (FUN_1000_44dc(), bVar7)) break;
    }
    return;
  case 5:
    FUN_1000_3ec7();
    if (!(bool)uVar8) {
      return;
    }
    if (!bVar7) {
      FUN_1000_3807();
      bVar5 = FUN_1000_a61d();
      bVar7 = 0xf7 < bVar5;
      uVar8 = FUN_1000_af6f();
      if (!bVar7) {
        *(undefined1 *)(unaff_SI + 1) = uVar8;
        uVar8 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar8;
        FUN_1000_c25c();
        return;
      }
      FUN_1000_adbe();
      if (bVar7) {
        return;
      }
      FUN_1000_4497();
      if (!bVar7) {
        return;
      }
    }
    break;
  case 6:
    FUN_1000_3f62();
    if ((bool)uVar8) {
      if (!bVar7) {
        FUN_1000_9b34();
        FUN_1000_4163();
        if ((bool)uVar8) {
          FUN_1000_3807();
        }
      }
    }
    else if (bVar7) {
      FUN_1000_3807();
    }
    return;
  case 7:
    FUN_1000_4040();
    if ((bool)uVar8) {
      if (!bVar7) {
        FUN_1000_3807();
      }
    }
    else if (bVar7) {
      FUN_1000_3807();
    }
    return;
  case 8:
    FUN_1000_3f2a();
    if (((bool)uVar8) || (bVar7)) {
      FUN_1000_3807();
      uVar4 = FUN_1000_af05();
      if (!(bool)uVar8) {
        *(undefined1 *)(unaff_SI + 1) = uVar4;
        uVar8 = FUN_1000_b78c();
        *(undefined1 *)(unaff_SI + 0xb) = uVar8;
        FUN_1000_c231();
        return;
      }
      FUN_1000_adbe();
      if ((!(bool)uVar8) && (FUN_1000_4516(), (bool)uVar8)) break;
    }
    return;
  case 9:
    FUN_1000_41dc();
    if ((bool)uVar8) {
      FUN_1000_3807();
      FUN_1000_adbe();
      if ((!(bool)uVar8) && (FUN_1000_45e7(), (bool)uVar8)) break;
    }
    else if (bVar7) {
      FUN_1000_3807();
      FUN_1000_adbe();
      if ((!(bool)uVar8) && (FUN_1000_45e7(), (bool)uVar8)) break;
    }
    return;
  case 10:
    FUN_1000_4247();
    if (!(bool)uVar8) {
      if (bVar7) {
        FUN_1000_3807();
      }
      return;
    }
    FUN_1000_3807();
    break;
  case 0xb:
    FUN_1000_4304();
    if ((!(bool)uVar8) && (!bVar7)) {
      return;
    }
    FUN_1000_3807();
    FUN_1000_adbe();
    if ((bool)uVar8) {
      return;
    }
    FUN_1000_461e();
    if (!(bool)uVar8) {
      return;
    }
    break;
  case 0xc:
    *(undefined1 *)(unaff_SI + 0xc) =
         *(undefined1 *)
          (*(int *)((undefined *)&DAT_0000_12ef + (uint)*(byte *)(unaff_SI + 0xc) * 2) + 0x15);
    *(undefined1 *)(unaff_SI + 10) = 1;
    return;
  }
  *(undefined1 *)(unaff_SI + 10) = 1;
  return;
}


