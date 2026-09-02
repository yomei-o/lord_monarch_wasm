/* 1000:7e3e */

undefined4 __cdecl16near FUN_1000_7e3e(void)

{
  char cVar1;
  byte bVar2;
  undefined2 in_AX;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  byte *pbVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 unaff_SS;
  
  puVar8 = (undefined1 *)0x28c;
  iVar7 = 0;
  pbVar6 = (byte *)&DAT_0000_648c;
  iVar4 = 0x30;
  do {
    iVar5 = 0x30;
    do {
      puVar9 = puVar8;
      bVar2 = ((undefined *)&DAT_0000_d27e)[iVar7];
      iVar3 = *(int *)((undefined *)&DAT_0000_e47e + iVar7);
      if (iVar3 != 0) {
        cVar1 = *(char *)(iVar3 + 0xc) * '\x04';
        bVar2 = cVar1 + 0x80;
        if (bVar2 != 0x90) {
          if ((*(byte *)(iVar3 + 10) & 0x20) == 0) {
            if ((999 < *(uint *)(iVar3 + 6)) &&
               (bVar2 = cVar1 + 0x81,
               (undefined2 *)&DAT_0000_270f < (undefined2 *)*(undefined2 *)(iVar3 + 6))) {
              bVar2 = cVar1 + 0x82;
            }
          }
          else {
            bVar2 = cVar1 + 0x83;
          }
        }
      }
      if (bVar2 != *pbVar6) {
        *pbVar6 = bVar2;
        iVar3 = (uint)bVar2 * 2 + 0x7000;
        *puVar9 = *(undefined1 *)0x0;
        puVar9[0x50] = *(undefined1 *)0x1;
        puVar9[0xa0] = *(undefined1 *)0x2;
        puVar9[0xf0] = *(undefined1 *)0x3;
        puVar9[0x140] = *(undefined1 *)0x4;
        puVar9[400] = *(undefined1 *)0x5;
        puVar9[0x1e0] = *(undefined1 *)0x6;
        puVar9[0x230] = *(undefined1 *)0x7;
        *puVar9 = *(undefined1 *)0x8;
        puVar9[0x50] = *(undefined1 *)0x9;
        puVar9[0xa0] = *(undefined1 *)0xa;
        puVar9[0xf0] = *(undefined1 *)0xb;
        puVar9[0x140] = *(undefined1 *)0xc;
        puVar9[400] = *(undefined1 *)0xd;
        puVar9[0x1e0] = *(undefined1 *)0xe;
        puVar9[0x230] = *(undefined1 *)0xf;
        *puVar9 = *(undefined1 *)0x10;
        puVar9[0x50] = *(undefined1 *)0x11;
        puVar9[0xa0] = *(undefined1 *)0x12;
        puVar9[0xf0] = *(undefined1 *)0x13;
        puVar9[0x140] = *(undefined1 *)0x14;
        puVar9[400] = *(undefined1 *)0x15;
        puVar9[0x1e0] = *(undefined1 *)0x16;
        puVar9[0x230] = *(undefined1 *)0x17;
        *puVar9 = *(undefined1 *)0x18;
        puVar9[0x50] = *(undefined1 *)0x19;
        puVar9[0xa0] = *(undefined1 *)0x1a;
        puVar9[0xf0] = *(undefined1 *)0x1b;
        puVar9[0x140] = *(undefined1 *)0x1c;
        puVar9[400] = *(undefined1 *)0x1d;
        puVar9[0x1e0] = *(undefined1 *)0x1e;
        puVar9[0x230] = *(undefined1 *)0x1f;
      }
      pbVar6 = pbVar6 + 1;
      iVar7 = iVar7 + 2;
      iVar5 = iVar5 + -1;
      puVar8 = puVar9 + 0x280;
    } while (iVar5 != 0);
    puVar8 = puVar9 + -0x757f;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = DAT_0000_3be4 * 0x200 + (DAT_0000_3be4 & 0xff) * 0x80 + (DAT_0000_3be4 >> 8);
  ((undefined *)&DAT_0000_648c)[(DAT_0000_3be4 & 0xff) + (DAT_0000_3be4 >> 8) * 0x30] = 0xff;
  FUN_1000_724a();
  *(undefined1 *)(iVar4 + 0x28c) = DAT_0000_26bb;
  puVar8 = (undefined1 *)(iVar4 + 0x28d + extraout_DX);
  *puVar8 = DAT_0000_26bc;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26bd;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26be;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26bf;
  puVar8 = puVar8 + extraout_DX + 1;
  *puVar8 = DAT_0000_26c0;
  puVar8[extraout_DX + 1] = DAT_0000_26c1;
  (puVar8 + extraout_DX + 1)[extraout_DX + 1] = DAT_0000_26c2;
  FUN_1000_724a();
  *(undefined1 *)(iVar4 + 0x28c) = DAT_0000_26c3;
  puVar8 = (undefined1 *)(iVar4 + 0x28d + extraout_DX_00);
  *puVar8 = DAT_0000_26c4;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c5;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c6;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c7;
  puVar8 = puVar8 + extraout_DX_00 + 1;
  *puVar8 = DAT_0000_26c8;
  puVar8[extraout_DX_00 + 1] = DAT_0000_26c9;
  (puVar8 + extraout_DX_00 + 1)[extraout_DX_00 + 1] = DAT_0000_26ca;
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


