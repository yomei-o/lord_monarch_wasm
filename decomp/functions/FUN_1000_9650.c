/* 1000:9650 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_9650(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int in_CX;
  int iVar3;
  int in_DX;
  undefined2 *unaff_SI;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar5 = (undefined2 *)0x8006;
  iVar3 = in_DX;
  _DAT_7000_8000 = unaff_SI;
  _DAT_7000_8002 = in_CX;
  _DAT_7000_8004 = in_DX;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *puVar2 = *puVar1;
    }
    puVar4 = unaff_SI + -in_DX;
    for (iVar3 = in_DX; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    puVar4 = puVar4 + -in_DX;
    for (iVar3 = in_DX; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    puVar4 = puVar4 + -in_DX;
    for (iVar3 = in_DX; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    unaff_SI = puVar4 + (0x28 - in_DX);
    in_CX = in_CX + -1;
    iVar3 = in_DX;
  } while (in_CX != 0);
  return CONCAT22(in_DX,in_AX);
}


