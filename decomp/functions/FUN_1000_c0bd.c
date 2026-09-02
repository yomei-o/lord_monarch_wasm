/* 1000:c0bd */

undefined4 __cdecl16near FUN_1000_c0bd(void)

{
  uint in_AX;
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint in_DX;
  byte bVar5;
  int *piVar6;
  undefined *puVar7;
  byte *pbVar8;
  
  iVar1 = (in_AX & 0xff) * 0x80;
  piVar6 = (int *)(((in_DX >> 8) * 0x30 + (in_DX & 0xff)) * 2);
  uVar2 = *piVar6 - 1;
  if ((uVar2 == 0) || (0x1ef < uVar2)) {
LAB_1000_c180:
    return CONCAT22(in_DX,in_AX);
  }
  *(uint *)((undefined *)&DAT_0000_247c + iVar1) = uVar2;
  *(undefined2 *)((undefined *)&DAT_0000_247e + iVar1) = 0;
  pbVar8 = (undefined *)&DAT_0000_2400 + (uVar2 >> 2) + iVar1;
  uVar2 = uVar2 & 3;
  if (uVar2 != 0) {
    pbVar8 = pbVar8 + 1;
    puVar7 = (undefined *)0x2;
    bVar4 = 1;
    goto LAB_1000_c121;
  }
  puVar7 = (undefined *)0x2;
  bVar4 = 1;
  do {
    uVar2 = 4;
LAB_1000_c121:
    bVar5 = 0;
    do {
      uVar3 = *(uint *)((int)piVar6 + (int)puVar7);
      if ((uint)piVar6[-0x30] < *(uint *)((int)piVar6 + (int)puVar7)) {
        bVar4 = 2;
        puVar7 = (undefined *)&DAT_0000_ffa0;
        uVar3 = piVar6[-0x30];
      }
      if ((uint)piVar6[-1] < uVar3) {
        bVar4 = 3;
        puVar7 = (undefined *)0xfffe;
        uVar3 = piVar6[-1];
      }
      if ((uint)piVar6[0x30] < uVar3) {
        bVar4 = 0;
        puVar7 = (undefined *)0x60;
        uVar3 = piVar6[0x30];
      }
      if ((uint)piVar6[1] < uVar3) {
        bVar4 = 1;
        puVar7 = (undefined *)0x2;
        uVar3 = piVar6[1];
      }
      bVar5 = bVar5 << 2 | bVar4;
      if (uVar3 == 1) {
        pbVar8[-1] = bVar5;
        goto LAB_1000_c180;
      }
      piVar6 = (int *)((int)piVar6 + (int)puVar7);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    pbVar8 = pbVar8 + -1;
    *pbVar8 = bVar5;
  } while( true );
}


