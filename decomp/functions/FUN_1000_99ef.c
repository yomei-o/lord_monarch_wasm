/* 1000:99ef */

undefined2 __cdecl16near FUN_1000_99ef(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int in_CX;
  int iVar2;
  int in_DX;
  undefined2 *unaff_DI;
  undefined2 *puVar3;
  
  iVar2 = in_DX;
  puVar3 = unaff_DI;
  do {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar1 = in_AX;
    }
    unaff_DI = puVar3 + 0x50;
    in_CX = in_CX + -1;
    iVar2 = in_DX;
    puVar3 = unaff_DI;
  } while (in_CX != 0);
  return in_AX;
}


