/* 1000:81d6 */

undefined4 __cdecl16near FUN_1000_81d6(void)

{
  undefined2 *puVar1;
  uint *puVar2;
  byte bVar3;
  undefined2 in_AX;
  uint uVar4;
  byte bVar6;
  int iVar5;
  int iVar7;
  int iVar8;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  int in_BX;
  int *piVar9;
  int *piVar10;
  undefined2 *puVar11;
  uint *puVar12;
  undefined2 *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  puVar11 = (undefined2 *)&DAT_0000_788e;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    puVar1 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar1 = 0;
  }
  FUN_1000_9b34();
  puVar12 = (uint *)0x600c;
  iVar7 = 0x18;
  do {
    iVar8 = 0x18;
    do {
      iVar5 = in_BX;
      uVar4 = (uint)(byte)((undefined *)&DAT_0000_d27e)[iVar5];
      if (*(int *)((undefined *)&DAT_0000_e47e + iVar5) != 0) {
        FUN_1000_ac00();
        uVar4 = FUN_1000_9c09();
        puVar12[0x240] = 0xffff;
      }
      puVar2 = puVar12;
      puVar12 = puVar12 + 1;
      *puVar2 = uVar4;
      iVar8 = iVar8 + -1;
      in_BX = iVar5 + 2;
    } while (iVar8 != 0);
    in_BX = iVar5 + 0x32;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar11 = (undefined2 *)0x28c;
  piVar9 = (int *)0x600a;
  iVar7 = 0x18;
  do {
    iVar8 = 0x18;
    piVar10 = piVar9;
    do {
      puVar13 = puVar11;
      piVar9 = piVar10 + 1;
      iVar5 = *piVar9;
      if (iVar5 != piVar10[0x241]) {
        piVar10[0x241] = iVar5;
        iVar5 = iVar5 * 8 + 0x3000;
        *puVar13 = *(undefined2 *)0x0;
        puVar13[0x28] = *(undefined2 *)0x2;
        puVar13[0x50] = *(undefined2 *)0x4;
        puVar13[0x78] = *(undefined2 *)0x6;
        puVar13[0xa0] = *(undefined2 *)0x8;
        puVar13[200] = *(undefined2 *)0xa;
        puVar13[0xf0] = *(undefined2 *)0xc;
        puVar13[0x118] = *(undefined2 *)0xe;
        puVar13[0x140] = *(undefined2 *)0x10;
        puVar13[0x168] = *(undefined2 *)0x12;
        puVar13[400] = *(undefined2 *)0x14;
        puVar13[0x1b8] = *(undefined2 *)0x16;
        puVar13[0x1e0] = *(undefined2 *)0x18;
        puVar13[0x208] = *(undefined2 *)0x1a;
        puVar13[0x230] = *(undefined2 *)0x1c;
        puVar13[600] = *(undefined2 *)0x1e;
        *puVar13 = *(undefined2 *)0x20;
        puVar13[0x28] = *(undefined2 *)0x22;
        puVar13[0x50] = *(undefined2 *)0x24;
        puVar13[0x78] = *(undefined2 *)0x26;
        puVar13[0xa0] = *(undefined2 *)0x28;
        puVar13[200] = *(undefined2 *)0x2a;
        puVar13[0xf0] = *(undefined2 *)0x2c;
        puVar13[0x118] = *(undefined2 *)0x2e;
        puVar13[0x140] = *(undefined2 *)0x30;
        puVar13[0x168] = *(undefined2 *)0x32;
        puVar13[400] = *(undefined2 *)0x34;
        puVar13[0x1b8] = *(undefined2 *)0x36;
        puVar13[0x1e0] = *(undefined2 *)0x38;
        puVar13[0x208] = *(undefined2 *)0x3a;
        puVar13[0x230] = *(undefined2 *)0x3c;
        puVar13[600] = *(undefined2 *)0x3e;
        *puVar13 = *(undefined2 *)0x40;
        puVar13[0x28] = *(undefined2 *)0x42;
        puVar13[0x50] = *(undefined2 *)0x44;
        puVar13[0x78] = *(undefined2 *)0x46;
        puVar13[0xa0] = *(undefined2 *)0x48;
        puVar13[200] = *(undefined2 *)0x4a;
        puVar13[0xf0] = *(undefined2 *)0x4c;
        puVar13[0x118] = *(undefined2 *)0x4e;
        puVar13[0x140] = *(undefined2 *)0x50;
        puVar13[0x168] = *(undefined2 *)0x52;
        puVar13[400] = *(undefined2 *)0x54;
        puVar13[0x1b8] = *(undefined2 *)0x56;
        puVar13[0x1e0] = *(undefined2 *)0x58;
        puVar13[0x208] = *(undefined2 *)0x5a;
        puVar13[0x230] = *(undefined2 *)0x5c;
        puVar13[600] = *(undefined2 *)0x5e;
        *puVar13 = *(undefined2 *)0x60;
        puVar13[0x28] = *(undefined2 *)0x62;
        puVar13[0x50] = *(undefined2 *)0x64;
        puVar13[0x78] = *(undefined2 *)0x66;
        puVar13[0xa0] = *(undefined2 *)0x68;
        puVar13[200] = *(undefined2 *)0x6a;
        puVar13[0xf0] = *(undefined2 *)0x6c;
        puVar13[0x118] = *(undefined2 *)0x6e;
        puVar13[0x140] = *(undefined2 *)0x70;
        puVar13[0x168] = *(undefined2 *)0x72;
        puVar13[400] = *(undefined2 *)0x74;
        puVar13[0x1b8] = *(undefined2 *)0x76;
        puVar13[0x1e0] = *(undefined2 *)0x78;
        puVar13[0x208] = *(undefined2 *)0x7a;
        puVar13[0x230] = *(undefined2 *)0x7c;
        puVar13[600] = *(undefined2 *)0x7e;
      }
      iVar8 = iVar8 + -1;
      piVar10 = piVar9;
      puVar11 = puVar13 + 0x280;
    } while (iVar8 != 0);
    puVar11 = puVar13 + -0x397f;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  bVar6 = (char)((uint)DAT_0000_3be4 >> 8) - (char)((uint)DAT_0000_3be2 >> 8);
  if ((bVar6 < 0x18) && (bVar3 = (char)DAT_0000_3be4 - (char)DAT_0000_3be2, bVar3 < 0x18)) {
    iVar7 = (uint)bVar3 * 0x500 + (uint)bVar6 * 2;
    *(undefined2 *)((undefined *)&DAT_0000_648c + ((uint)bVar3 + (uint)bVar6 * 0x18) * 2) = 0xffff;
    FUN_1000_724a();
    *(undefined2 *)(iVar7 + 0x28c) = DAT_0000_26cb;
    puVar11 = (undefined2 *)(iVar7 + 0x28e + extraout_DX);
    *puVar11 = DAT_0000_26cd;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26cf;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d1;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d3;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d5;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d7;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26d9;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26db;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26dd;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26df;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e1;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e3;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e5;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX + 2);
    *puVar11 = DAT_0000_26e7;
    *(undefined2 *)((int)puVar11 + extraout_DX + 2) = DAT_0000_26e9;
    FUN_1000_724a();
    *(undefined2 *)(iVar7 + 0x28c) = DAT_0000_26eb;
    puVar11 = (undefined2 *)(iVar7 + 0x28e + extraout_DX_00);
    *puVar11 = DAT_0000_26ed;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26ef;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f1;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f3;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f5;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f7;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26f9;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26fb;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26fd;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_26ff;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2701;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2703;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2705;
    puVar11 = (undefined2 *)((int)puVar11 + extraout_DX_00 + 2);
    *puVar11 = DAT_0000_2707;
    *(undefined2 *)((int)puVar11 + extraout_DX_00 + 2) = DAT_0000_2709;
    out(0x7c,0);
  }
  return CONCAT22(in_DX,in_AX);
}


