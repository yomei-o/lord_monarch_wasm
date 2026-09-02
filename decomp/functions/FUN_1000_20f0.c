/* 1000:20f0 */

undefined4 __cdecl16near FUN_1000_20f0(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 in_AX;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  byte bVar7;
  undefined2 in_DX;
  int in_BX;
  byte *pbVar8;
  undefined2 unaff_DS;
  undefined1 uVar9;
  
  bVar1 = FUN_1000_9b34();
  pbVar8 = *(byte **)((undefined *)&DAT_0000_e47e + in_BX);
  if (((pbVar8 == (byte *)0x0) || (bVar1 = *(byte *)0x3c00, bVar1 != pbVar8[0xc])) ||
     ((*pbVar8 & 2) != 0)) {
    FUN_1000_0d12(bVar1);
    goto LAB_1000_22dc;
  }
  *(undefined2 *)0x3ea6 = pbVar8;
  uVar3 = 0;
  do {
    while( true ) {
      uVar9 = uVar3;
      FUN_1000_bd1e();
      FUN_1000_be36();
      uVar4 = FUN_1000_22de();
      if ((bool)uVar9) goto LAB_1000_22ce;
      *(undefined2 *)0x3ea4 = *(undefined2 *)&DAT_0000_3be4;
      FUN_1000_bd1e();
      FUN_1000_bd84();
      FUN_1000_c316();
      FUN_1000_be36();
      FUN_1000_aaae();
      if (!(bool)uVar9) goto LAB_1000_21f5;
      FUN_1000_bd1e();
      FUN_1000_bd3b();
      FUN_1000_c316();
      FUN_1000_be36();
      uVar4 = FUN_1000_aaae();
      if (!(bool)uVar9) break;
      FUN_1000_bd1e();
      FUN_1000_c316();
      FUN_1000_be36();
      uVar4 = FUN_1000_aaae();
      if ((bool)uVar9) {
        FUN_1000_0d12(uVar4);
        uVar3 = uVar9;
      }
      else {
        FUN_1000_0d12(uVar4);
        FUN_1000_7c9e();
        FUN_1000_4a4d();
        FUN_1000_49bb();
        FUN_1000_72ad();
        cVar2 = FUN_1000_4be9();
        uVar3 = uVar9;
        if ((!(bool)uVar9) && (uVar3 = 0, cVar2 == '\0')) goto LAB_1000_21f5;
      }
    }
    FUN_1000_0d12(uVar4);
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_49bb();
    FUN_1000_72ad();
    cVar2 = FUN_1000_4be9();
    uVar3 = 1;
  } while (((bool)uVar9) || (uVar3 = 0, cVar2 != '\0'));
LAB_1000_21f5:
  iVar5 = FUN_1000_aaae();
  *(int *)0x3ea2 = iVar5 + -1;
  FUN_1000_0d12(iVar5 + -1);
  uVar9 = 0;
  bVar1 = 0x2d;
  uVar3 = false;
  if ((pbVar8[10] & 0x20) == 0) {
    FUN_1000_ab3e();
    FUN_1000_7c9e();
    FUN_1000_5c69();
    FUN_1000_5bd4();
    FUN_1000_49bb();
    FUN_1000_72ad();
    uVar6 = FUN_1000_4be9();
    uVar4 = uVar6;
    if ((bool)uVar9) {
LAB_1000_22ce:
      *(undefined2 *)&DAT_0000_32bf = pbVar8;
      FUN_1000_0d12(uVar4);
      goto LAB_1000_22dc;
    }
    uVar4 = 0;
    if (3 < (byte)uVar6) {
      FUN_1000_7c9e();
      FUN_1000_5c69();
      FUN_1000_5bd4();
      bVar1 = FUN_1000_4a4d();
      uVar9 = bVar1 < 7;
      FUN_1000_5bd4();
      FUN_1000_49bb();
      FUN_1000_72ad();
      uVar3 = FUN_1000_4be9();
      uVar4 = CONCAT11(uVar3,uVar3);
      if ((bool)uVar9) goto LAB_1000_22ce;
    }
    bVar7 = (byte)((uint)uVar4 >> 8);
    bVar1 = 1;
    if (*(byte *)0x3bf4 != 1) {
      bVar1 = *(byte *)0x3bf4 | 0x10;
    }
    bVar1 = bVar1 | bVar7 >> 2 | bVar7 << 6;
    uVar3 = bVar1 == 0;
  }
  pbVar8[10] = bVar1;
  *(undefined2 *)(pbVar8 + 8) = *(undefined2 *)0x3ea4;
  pbVar8[0xb] = 0xff;
  FUN_1000_b78c();
  bVar1 = FUN_1000_c0bd();
  if (!(bool)uVar3) {
    pbVar8[0xb] = bVar1;
    bVar1 = pbVar8[10] & 0xf;
    if ((((bVar1 == 10) || (bVar1 == 7)) || (bVar1 == 9)) || ((bVar1 == 6 || (bVar1 == 0xb)))) {
      FUN_1000_c2e7();
    }
  }
  *(undefined2 *)&DAT_0000_32bf = pbVar8;
LAB_1000_22dc:
  return CONCAT22(in_DX,in_AX);
}


