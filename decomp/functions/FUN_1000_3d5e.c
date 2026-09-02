/* 1000:3d5e */

undefined4 __cdecl16near FUN_1000_3d5e(void)

{
  uint *puVar1;
  int iVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  undefined2 in_DX;
  uint extraout_DX;
  uint uVar7;
  uint uVar8;
  uint extraout_DX_00;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar6 = ((undefined *)&DAT_0000_d27e)[unaff_DI] - 0x14;
  bVar5 = ((undefined *)&DAT_0000_d27e)[in_BX] - 0x14;
  iVar2 = *(int *)((undefined *)&DAT_0000_e47e + in_BX);
  if (iVar2 != 0) {
    uVar3 = FUN_1000_a61d();
    if ((*(char *)(iVar2 + 0xc) != (char)uVar3) &&
       (*(char *)(iVar2 + 0xc) != (char)((uint)uVar3 >> 8))) {
      if (*(char *)(iVar2 + 0xb) == -1) {
        *(byte *)(iVar2 + 1) = *(char *)(unaff_SI + 1) + 4U & 6;
      }
      uVar7 = *(uint *)(iVar2 + 6);
      uVar8 = *(uint *)(unaff_SI + 6);
      if (bVar6 < 4) {
        uVar8 = (uVar8 >> 2) + 1;
        puVar1 = (uint *)(iVar2 + 6);
        uVar7 = *puVar1;
        *puVar1 = *puVar1 - uVar8;
        if (uVar7 < uVar8 || *puVar1 == 0) {
          FUN_1000_4924();
        }
      }
      else if (bVar5 < 4) {
        uVar4 = (uVar8 >> 3) + 1;
        puVar1 = (uint *)(iVar2 + 6);
        uVar8 = *puVar1;
        *puVar1 = *puVar1 - uVar4;
        if (uVar8 < uVar4 || *puVar1 == 0) {
          FUN_1000_4924();
          uVar7 = extraout_DX_00;
        }
        uVar8 = (uVar7 >> 3) + 1;
        puVar1 = (uint *)(unaff_SI + 6);
        uVar7 = *puVar1;
        *puVar1 = *puVar1 - uVar8;
        if (uVar7 < uVar8 || *puVar1 == 0) {
          FUN_1000_4924();
        }
      }
      else {
        uVar4 = (uVar8 >> 3) + 1;
        puVar1 = (uint *)(iVar2 + 6);
        uVar8 = *puVar1;
        *puVar1 = *puVar1 - uVar4;
        if (uVar8 < uVar4 || *puVar1 == 0) {
          FUN_1000_4924();
          uVar7 = extraout_DX;
        }
        uVar8 = (uVar7 >> 4) + 1;
        puVar1 = (uint *)(unaff_SI + 6);
        uVar7 = *puVar1;
        *puVar1 = *puVar1 - uVar8;
        if (uVar7 < uVar8 || *puVar1 == 0) {
          FUN_1000_4924();
        }
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}


