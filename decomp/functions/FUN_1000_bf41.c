/* 1000:bf41 */

void __cdecl16near FUN_1000_bf41(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int in_DX;
  char cVar4;
  byte bVar5;
  uint in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  if (-1 < (char)in_DX) {
    uVar2 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI);
    while( true ) {
      while( true ) {
        cVar4 = (char)((uint)in_DX >> 8);
        if ((int)*(uint *)(in_BX + unaff_DI) < 0) break;
        uVar1 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI);
        uVar3 = uVar2;
        if (((uVar2 <= uVar1) || (uVar2 = uVar2 - uVar1, uVar3 = uVar1, uVar2 < 3)) &&
           (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI))) {
          *(uint *)0x4400 = in_BX;
          goto LAB_1000_bf95;
        }
        bVar5 = cVar4 - 1;
        in_DX = (uint)bVar5 << 8;
        if (bVar5 == 0) goto LAB_1000_bf83;
        in_BX = in_BX + 2;
      }
      bVar5 = cVar4 - 1;
      in_DX = (uint)bVar5 << 8;
      if (bVar5 == 0) break;
      in_BX = in_BX + 2;
      uVar2 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI);
    }
LAB_1000_bf83:
    *(uint *)0x4402 = in_BX;
    return;
  }
  uVar2 = *(uint *)(in_BX + unaff_DI + 0x60);
  while( true ) {
    while( true ) {
      cVar4 = (char)((uint)in_DX >> 8);
      if ((int)*(uint *)(in_BX + unaff_DI) < 0) break;
      uVar1 = *(uint *)(in_BX + unaff_DI + 0x60);
      uVar3 = uVar2;
      if (((uVar2 <= uVar1) || (uVar2 = uVar2 - uVar1, uVar3 = uVar1, uVar2 < 3)) &&
         (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI))) {
        *(uint *)0x4400 = in_BX;
        goto LAB_1000_c018;
      }
      bVar5 = cVar4 - 1;
      in_DX = (uint)bVar5 << 8;
      if (bVar5 == 0) goto LAB_1000_c006;
      in_BX = in_BX + 2;
    }
    bVar5 = cVar4 - 1;
    in_DX = (uint)bVar5 << 8;
    if (bVar5 == 0) break;
    in_BX = in_BX + 2;
    uVar2 = *(uint *)(in_BX + unaff_DI + 0x60);
  }
LAB_1000_c006:
  *(uint *)0x4402 = in_BX;
  return;
  while (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)) {
LAB_1000_bf95:
    *(uint *)(in_BX + unaff_DI) = uVar2;
    in_BX = in_BX + 2;
    if (((0x5f < in_BX) || ((int)*(uint *)(in_BX + unaff_DI) < 0)) ||
       ((uVar1 = *(uint *)((undefined *)&DAT_0000_ffa0 + in_BX + unaff_DI), uVar3 = uVar2,
        uVar1 < uVar2 && (uVar3 = uVar1, 2 < uVar2 - uVar1)))) break;
  }
  *(uint *)0x4402 = in_BX;
  return;
  while (uVar2 = uVar3 + 1, uVar2 < *(uint *)(in_BX + unaff_DI)) {
LAB_1000_c018:
    *(uint *)(in_BX + unaff_DI) = uVar2;
    in_BX = in_BX + 2;
    if (((0x5f < in_BX) || ((int)*(uint *)(in_BX + unaff_DI) < 0)) ||
       ((uVar1 = *(uint *)(in_BX + unaff_DI + 0x60), uVar3 = uVar2, uVar1 < uVar2 &&
        (uVar3 = uVar1, 2 < uVar2 - uVar1)))) break;
  }
  *(uint *)0x4402 = in_BX;
  return;
}


