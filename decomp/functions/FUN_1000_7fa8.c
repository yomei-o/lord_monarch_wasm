/* 1000:7fa8 */

undefined4 __cdecl16near FUN_1000_7fa8(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined2 unaff_SS;
  
  pbVar7 = (byte *)0x28c;
  iVar6 = 0;
  pbVar5 = (byte *)&DAT_0000_648c;
  iVar3 = 0x30;
  do {
    iVar4 = 0x30;
    do {
      pbVar8 = pbVar7;
      bVar1 = ((undefined *)&DAT_0000_d27e)[iVar6];
      if (bVar1 != *pbVar5) {
        *pbVar5 = bVar1;
        if (CARRY1(bVar1,bVar1)) {
          iVar2 = (byte)(bVar1 * '\x02') + 0x7000;
          *pbVar8 = *(byte *)0x0 | 0x55;
          pbVar8[0x50] = *(byte *)0x1 | 0x55;
          pbVar8[0xa0] = *(byte *)0x2 | 0x55;
          pbVar8[0xf0] = *(byte *)0x3 | 0x55;
          pbVar8[0x140] = *(byte *)0x4 | 0x55;
          pbVar8[400] = *(byte *)0x5 | 0x55;
          pbVar8[0x1e0] = *(byte *)0x6 | 0x55;
          pbVar8[0x230] = *(byte *)0x7 | 0x55;
          *pbVar8 = *(byte *)0x8 | 0x55;
          pbVar8[0x50] = *(byte *)0x9 | 0x55;
          pbVar8[0xa0] = *(byte *)0xa | 0x55;
          pbVar8[0xf0] = *(byte *)0xb | 0x55;
          pbVar8[0x140] = *(byte *)0xc | 0x55;
          pbVar8[400] = *(byte *)0xd | 0x55;
          pbVar8[0x1e0] = *(byte *)0xe | 0x55;
          pbVar8[0x230] = *(byte *)0xf | 0x55;
          *pbVar8 = *(byte *)0x10 | 0x55;
          pbVar8[0x50] = *(byte *)0x11 | 0x55;
          pbVar8[0xa0] = *(byte *)0x12 | 0x55;
          pbVar8[0xf0] = *(byte *)0x13 | 0x55;
          pbVar8[0x140] = *(byte *)0x14 | 0x55;
          pbVar8[400] = *(byte *)0x15 | 0x55;
          pbVar8[0x1e0] = *(byte *)0x16 | 0x55;
          pbVar8[0x230] = *(byte *)0x17 | 0x55;
          *pbVar8 = *(byte *)0x18 | 0x55;
          pbVar8[0x50] = *(byte *)0x19 | 0x55;
          pbVar8[0xa0] = *(byte *)0x1a | 0x55;
          pbVar8[0xf0] = *(byte *)0x1b | 0x55;
          pbVar8[0x140] = *(byte *)0x1c | 0x55;
          pbVar8[400] = *(byte *)0x1d | 0x55;
          pbVar8[0x1e0] = *(byte *)0x1e | 0x55;
          pbVar8[0x230] = *(byte *)0x1f | 0x55;
        }
        else {
          iVar2 = (byte)(bVar1 * '\x02') + 0x7000;
          *pbVar8 = *(byte *)0x0;
          pbVar8[0x50] = *(byte *)0x1;
          pbVar8[0xa0] = *(byte *)0x2;
          pbVar8[0xf0] = *(byte *)0x3;
          pbVar8[0x140] = *(byte *)0x4;
          pbVar8[400] = *(byte *)0x5;
          pbVar8[0x1e0] = *(byte *)0x6;
          pbVar8[0x230] = *(byte *)0x7;
          *pbVar8 = *(byte *)0x8;
          pbVar8[0x50] = *(byte *)0x9;
          pbVar8[0xa0] = *(byte *)0xa;
          pbVar8[0xf0] = *(byte *)0xb;
          pbVar8[0x140] = *(byte *)0xc;
          pbVar8[400] = *(byte *)0xd;
          pbVar8[0x1e0] = *(byte *)0xe;
          pbVar8[0x230] = *(byte *)0xf;
          *pbVar8 = *(byte *)0x10;
          pbVar8[0x50] = *(byte *)0x11;
          pbVar8[0xa0] = *(byte *)0x12;
          pbVar8[0xf0] = *(byte *)0x13;
          pbVar8[0x140] = *(byte *)0x14;
          pbVar8[400] = *(byte *)0x15;
          pbVar8[0x1e0] = *(byte *)0x16;
          pbVar8[0x230] = *(byte *)0x17;
          *pbVar8 = *(byte *)0x18;
          pbVar8[0x50] = *(byte *)0x19;
          pbVar8[0xa0] = *(byte *)0x1a;
          pbVar8[0xf0] = *(byte *)0x1b;
          pbVar8[0x140] = *(byte *)0x1c;
          pbVar8[400] = *(byte *)0x1d;
          pbVar8[0x1e0] = *(byte *)0x1e;
          pbVar8[0x230] = *(byte *)0x1f;
        }
      }
      pbVar5 = pbVar5 + 1;
      iVar6 = iVar6 + 2;
      iVar4 = iVar4 + -1;
      pbVar7 = pbVar8 + 0x280;
    } while (iVar4 != 0);
    pbVar7 = pbVar8 + -0x757f;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (DAT_0000_3298 == -1) {
    iVar3 = DAT_0000_3be4 * 0x200 + (DAT_0000_3be4 & 0xff) * 0x80 + (DAT_0000_3be4 >> 8);
    ((undefined *)&DAT_0000_648c)[(DAT_0000_3be4 & 0xff) + (DAT_0000_3be4 >> 8) * 0x30] = 0xff;
    FUN_1000_724a();
    *(undefined1 *)(iVar3 + 0x28c) = DAT_0000_26bb;
    puVar9 = (undefined1 *)(iVar3 + 0x28d + extraout_DX);
    *puVar9 = DAT_0000_26bc;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26bd;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26be;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26bf;
    puVar9 = puVar9 + extraout_DX + 1;
    *puVar9 = DAT_0000_26c0;
    puVar9[extraout_DX + 1] = DAT_0000_26c1;
    (puVar9 + extraout_DX + 1)[extraout_DX + 1] = DAT_0000_26c2;
    FUN_1000_724a();
    *(undefined1 *)(iVar3 + 0x28c) = DAT_0000_26c3;
    puVar9 = (undefined1 *)(iVar3 + 0x28d + extraout_DX_00);
    *puVar9 = DAT_0000_26c4;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c5;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c6;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c7;
    puVar9 = puVar9 + extraout_DX_00 + 1;
    *puVar9 = DAT_0000_26c8;
    puVar9[extraout_DX_00 + 1] = DAT_0000_26c9;
    (puVar9 + extraout_DX_00 + 1)[extraout_DX_00 + 1] = DAT_0000_26ca;
    out(0x7c,0);
  }
  return CONCAT22(in_DX,in_AX);
}


