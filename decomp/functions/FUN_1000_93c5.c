/* 1000:93c5 */

undefined4 __cdecl16near FUN_1000_93c5(void)

{
  undefined2 in_AX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  uint uVar4;
  int extraout_DX;
  int extraout_DX_00;
  uint uVar5;
  int extraout_DX_01;
  int extraout_DX_02;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar6 = -0x386e;
  iVar2 = 5;
  uVar1 = 0;
  uVar4 = 0;
  do {
    if ((uVar4 < *(uint *)(iVar6 + 10)) ||
       ((uVar4 == *(uint *)(iVar6 + 10) && (uVar1 < *(uint *)(iVar6 + 8))))) {
      uVar4 = *(uint *)(iVar6 + 10);
      uVar1 = *(uint *)(iVar6 + 8);
    }
    iVar6 = iVar6 + 0x16;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  for (; uVar4 != 0; uVar4 = uVar4 >> 1) {
    iVar2 = iVar2 + 1;
  }
  *(int *)0xc4f4 = iVar2 + 1;
  *(uint *)0xc4f6 = ~(-1 << ((byte)(iVar2 + 1) & 0x1f));
  iVar2 = 2;
  if ((*(byte *)0x3482 & 1) != 0) {
    iVar2 = 6;
  }
  iVar9 = 0x666f;
  iVar8 = 0x3484;
  iVar7 = -0x386e;
  iVar6 = 5;
  do {
    uVar4 = *(uint *)(iVar7 + 8);
    uVar1 = *(uint *)(iVar7 + 10);
    for (iVar3 = *(int *)0xc4f4; iVar3 != 0; iVar3 = iVar3 + -1) {
      uVar5 = uVar1 & 1;
      uVar1 = uVar1 >> 1;
      uVar4 = (uint)(CONCAT12(uVar5 != 0,uVar4) >> 1);
    }
    uVar1 = uVar4 >> 8;
    if ((*(uint *)(iVar7 + 8) & *(uint *)0xc4f6) != 0 || (uVar4 & 0xff) != 0) {
      uVar1 = uVar1 + 1;
    }
    if ((uVar1 & 0xff80) != 0) {
      uVar1 = 0x7f;
    }
    uVar4 = *(uint *)(iVar2 + iVar8);
    *(uint *)(iVar2 + iVar8) = uVar1;
    iVar3 = uVar1 - uVar4;
    if (iVar3 != 0) {
      if (uVar1 < uVar4) {
        iVar3 = -iVar3;
        puVar10 = (undefined1 *)(iVar9 + (uVar4 - 1) * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0xff;
          puVar10 = puVar10 + extraout_DX_00;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else {
        puVar10 = (undefined1 *)(iVar9 + uVar4 * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0x5a;
          puVar10 = puVar10 + -extraout_DX;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      out(0x7c,0);
    }
    iVar7 = iVar7 + 0x16;
    iVar8 = iVar8 + 10;
    iVar9 = iVar9 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar9 = 0x6670;
  iVar8 = 0x3484;
  iVar7 = -0x386e;
  iVar6 = 5;
  do {
    uVar4 = 0;
    if (*(int *)(iVar7 + 6) != 0) {
      uVar4 = *(uint *)(*(int *)(iVar7 + 6) + 6);
    }
    uVar5 = uVar4 >> ((byte)*(undefined2 *)0xc4f4 & 0x1f);
    uVar1 = CONCAT11((char)((uint)*(undefined2 *)0xc4f4 >> 8),(char)(uVar5 >> 8));
    if ((uVar4 & *(uint *)0xc4f6) != 0 || (uVar5 & 0xff) != 0) {
      uVar1 = uVar1 + 1;
    }
    if ((uVar1 & 0xff80) != 0) {
      uVar1 = 0x7f;
    }
    uVar4 = *(uint *)(iVar2 + 2 + iVar8);
    *(uint *)(iVar2 + 2 + iVar8) = uVar1;
    iVar3 = uVar1 - uVar4;
    if (iVar3 != 0) {
      if (uVar1 < uVar4) {
        iVar3 = -iVar3;
        puVar10 = (undefined1 *)(iVar9 + (uVar4 - 1) * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0xff;
          puVar10 = puVar10 + extraout_DX_02;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else {
        puVar10 = (undefined1 *)(iVar9 + uVar4 * -0x50);
        FUN_1000_724a();
        do {
          *puVar10 = 0x5a;
          puVar10 = puVar10 + -extraout_DX_01;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      out(0x7c,0);
    }
    iVar7 = iVar7 + 0x16;
    iVar8 = iVar8 + 10;
    iVar9 = iVar9 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return CONCAT22(in_DX,in_AX);
}


