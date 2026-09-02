/* 1000:a6a5 */

undefined4 __cdecl16near FUN_1000_a6a5(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  byte bVar6;
  undefined2 in_AX;
  int iVar7;
  undefined2 in_DX;
  uint *puVar8;
  int iVar9;
  byte *pbVar10;
  undefined2 unaff_DS;
  
  iVar9 = -0x386e;
  iVar7 = 5;
  do {
    *(undefined2 *)(iVar9 + 8) = 0;
    *(undefined2 *)(iVar9 + 10) = 0;
    iVar9 = iVar9 + 0x16;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar8 = (uint *)&DAT_0000_d27e;
  iVar7 = 0x900;
  do {
    puVar4 = puVar8;
    puVar8 = puVar8 + 1;
    cVar5 = (char)*puVar4;
    uVar3 = *puVar4 >> 8;
    if (cVar5 == '\x05') {
      bVar6 = 4;
LAB_1000_a6ce:
      iVar9 = *(int *)((undefined *)&DAT_0000_12ef + (uint)bVar6 * 2);
      puVar4 = (uint *)(iVar9 + 8);
      uVar2 = *puVar4;
      *puVar4 = *puVar4 + uVar3;
      if (CARRY2(uVar2,uVar3)) {
        piVar1 = (int *)(iVar9 + 10);
        *piVar1 = *piVar1 + 1;
      }
    }
    else {
      bVar6 = cVar5 - 8;
      if (bVar6 < 4) goto LAB_1000_a6ce;
    }
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      pbVar10 = (byte *)&DAT_0000_c800;
      iVar7 = 0x40;
      do {
        if (((*pbVar10 & 0x80) == 0) && ((pbVar10[10] & 0x20) == 0)) {
          iVar9 = *(int *)((undefined *)&DAT_0000_12ef + (uint)pbVar10[0xc] * 2);
          uVar2 = *(uint *)(pbVar10 + 6);
          puVar4 = (uint *)(iVar9 + 8);
          uVar3 = *puVar4;
          *puVar4 = *puVar4 + uVar2;
          if (CARRY2(uVar3,uVar2)) {
            piVar1 = (int *)(iVar9 + 10);
            *piVar1 = *piVar1 + 1;
          }
        }
        pbVar10 = pbVar10 + 0x10;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      puVar8 = (uint *)0xc792;
      iVar7 = 4;
      do {
        if (puVar8[4] == 0 && puVar8[5] == 0) {
          *puVar8 = *puVar8 | 4;
          *(undefined1 *)((int)puVar8 + 0x15) = 4;
        }
        puVar8 = puVar8 + 0xb;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}


