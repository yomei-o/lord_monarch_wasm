/* 1000:4881 */

void __cdecl16near FUN_1000_4881(void)

{
  byte bVar1;
  byte *unaff_SI;
  undefined2 unaff_DS;
  bool bVar2;
  undefined1 uVar3;
  
  if (*(byte *)0x3c00 == unaff_SI[0xc]) {
    uVar3 = 0;
    if (*(int *)0x3480 != 0) {
      *unaff_SI = *unaff_SI | 1;
      return;
    }
  }
  else {
    bVar2 = *(uint *)(unaff_SI + 6) < 1000;
    if ((!bVar2) && (FUN_1000_46d3(), !bVar2)) {
      return;
    }
    bVar1 = FUN_1000_9a24();
    bVar2 = bVar1 < 0x5a;
    if (!bVar2) {
      FUN_1000_4374();
      if (!bVar2) {
        return;
      }
      FUN_1000_4559();
      if (!bVar2) {
        return;
      }
      FUN_1000_458e();
      return;
    }
    uVar3 = bVar1 < 0x50;
    if ((!(bool)uVar3) && (FUN_1000_4658(), !(bool)uVar3)) {
      return;
    }
  }
  FUN_1000_4420();
  if (((bool)uVar3) && (FUN_1000_4559(), (bool)uVar3)) {
    FUN_1000_458e();
    return;
  }
  return;
}


