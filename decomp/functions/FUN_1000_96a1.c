/* 1000:96a1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_96a1(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 in_AX;
  int iVar4;
  int iVar5;
  undefined2 in_DX;
  undefined2 *puVar6;
  undefined2 *puVar7;
  
  iVar3 = _DAT_7000_8004;
  puVar6 = (undefined2 *)0x8006;
  iVar4 = iVar3;
  puVar7 = _DAT_7000_8000;
  iVar5 = _DAT_7000_8002;
  do {
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar7 = *puVar1;
      puVar7 = puVar7 + 1;
    }
    puVar7 = puVar7 + -iVar3;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = puVar7 + -iVar3;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = puVar7 + -iVar3;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = puVar7 + (0x28 - iVar3);
    iVar5 = iVar5 + -1;
    iVar4 = iVar3;
  } while (iVar5 != 0);
  return CONCAT22(in_DX,in_AX);
}


