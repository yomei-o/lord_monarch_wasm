/* 1000:c050 */

void __cdecl16near FUN_1000_c050(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char in_DL;
  uint in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar4;
  
  uVar2 = *(uint *)(in_BX + unaff_DI);
  if (-1 < in_DL) {
    while (((bVar4 = 1 < in_BX, in_BX = in_BX - 2, bVar4 && (-1 < (int)*(uint *)(in_BX + unaff_DI)))
           && (((uVar1 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI), uVar3 = uVar2,
                uVar2 <= uVar1 || (uVar3 = uVar1, uVar2 - uVar1 < 3)) &&
               (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)))))) {
      *(uint *)(in_BX + unaff_DI) = uVar2;
    }
    return;
  }
  while ((((bVar4 = 1 < in_BX, in_BX = in_BX - 2, bVar4 && (-1 < (int)*(uint *)(in_BX + unaff_DI)))
          && ((uVar1 = *(uint *)(in_BX + unaff_DI + 0x60), uVar3 = uVar2, uVar2 <= uVar1 ||
              (uVar3 = uVar1, uVar2 - uVar1 < 3)))) &&
         (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)))) {
    *(uint *)(in_BX + unaff_DI) = uVar2;
  }
  return;
}


