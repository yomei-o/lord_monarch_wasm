/* 1000:7de8 */

undefined4 __cdecl16near FUN_1000_7de8(void)

{
  uint *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined2 *puVar9;
  
  puVar8 = (uint *)0x28c;
  iVar7 = 0xc0;
  uVar4 = 0x4444;
  do {
    for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = 0;
    }
    puVar8 = puVar8 + 0x10;
    for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = uVar4;
    }
    puVar8 = puVar8 + 0x10;
    uVar4 = (uVar4 >> 1 | (uint)((uVar4 & 1) != 0) << 0xf) >> 1 |
            (uint)((uVar4 >> 1 & 1) != 0) << 0xf;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar4 = 0xb000;
  do {
    uVar5 = uVar4;
    puVar9 = (undefined2 *)0x28c;
    iVar7 = 0x180;
    do {
      for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
        puVar2 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = 0;
      }
      puVar9 = puVar9 + 0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    uVar6 = uVar5 + 0x800;
    uVar4 = uVar6;
  } while ((uVar6 < 0xb801) || (uVar4 = uVar5 + 0x2800, uVar6 < 0xe000));
  return CONCAT22(in_DX,in_AX);
}


