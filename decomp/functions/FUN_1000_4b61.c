/* 1000:4b61 */

undefined4 __cdecl16near FUN_1000_4b61(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  byte bVar3;
  undefined2 in_DX;
  int iVar4;
  int iVar5;
  uint in_BX;
  byte bVar8;
  int iVar6;
  int iVar7;
  undefined2 *puVar9;
  undefined *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar8 = (byte)(in_BX >> 8);
  bVar3 = (byte)(in_CX >> 8);
  if (*(int *)0x3288 == 0) {
    puVar10 = (undefined *)&DAT_0000_648c + (uint)bVar8 * 0x60 + (in_BX & 0xff) * 2;
    iVar7 = (in_CX & 0xff) + 1;
    iVar5 = (bVar3 + 1) * 2;
    iVar4 = iVar7 * 2;
    iVar6 = iVar4;
    do {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        puVar1 = puVar10;
        puVar10 = puVar10 + 1;
        *puVar1 = 0xff;
      }
      puVar10 = puVar10 + iVar7 * -2 + 0x30;
      iVar5 = iVar5 + -1;
      iVar6 = iVar4;
    } while (iVar5 != 0);
  }
  else {
    puVar9 = (undefined2 *)((undefined *)&DAT_0000_648c + ((uint)bVar8 * 0x18 + (in_BX & 0xff)) * 2)
    ;
    iVar4 = bVar3 + 1;
    iVar6 = (in_CX & 0xff) + 1;
    iVar5 = iVar6;
    do {
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        puVar2 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = 0xffff;
      }
      puVar9 = puVar9 + (0x18 - iVar6);
      iVar4 = iVar4 + -1;
      iVar5 = iVar6;
    } while (iVar4 != 0);
  }
  FUN_1000_9167();
  return CONCAT22(in_DX,in_AX);
}


