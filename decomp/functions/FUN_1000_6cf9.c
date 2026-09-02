/* 1000:6cf9 */

void FUN_1000_6cf9(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  undefined1 extraout_AH;
  int in_CX;
  int iVar7;
  undefined2 *puVar8;
  byte bVar9;
  uint uVar10;
  uint extraout_DX;
  undefined2 uVar11;
  undefined2 extraout_DX_00;
  int in_BX;
  int iVar12;
  int iVar13;
  undefined2 *unaff_SI;
  undefined1 *unaff_DI;
  undefined1 *puVar14;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 *unaff_DS;
  
  while( true ) {
    FUN_1000_710b();
    puVar8 = unaff_SI + 5;
    unaff_DI = unaff_DI + 3;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    *(undefined2 *)(in_BX + (int)puVar8) = 0;
    *(undefined2 *)((int)puVar8 + in_BX + 2) = 0;
    unaff_SI = puVar8;
  }
  unaff_DI[in_BX + -0x3d] = unaff_DI[in_BX + -0x3d] & 6;
  iVar7 = 5;
  uVar5 = 0;
  uVar10 = 0;
  iVar13 = -0x386e;
  do {
    iVar12 = iVar13;
    if ((uVar10 < *(uint *)(iVar12 + 10)) ||
       ((uVar10 == *(uint *)(iVar12 + 10) && (uVar5 < *(uint *)(iVar12 + 8))))) {
      uVar10 = *(uint *)(iVar12 + 10);
      uVar5 = *(uint *)(iVar12 + 8);
    }
    iVar13 = iVar12 + 0x16;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0;
  for (; uVar10 != 0; uVar10 = uVar10 >> 1) {
    iVar7 = iVar7 + 1;
  }
  *(int *)0xc4f4 = iVar7 + 1;
  *(uint *)0xc4f6 = ~(-1 << ((byte)(iVar7 + 1) & 0x1f));
  puVar2 = unaff_SI + 6;
  out(*puVar8,0);
  *(undefined1 *)(unaff_SI + 0x16) = 0;
  uVar10 = *(uint *)(iVar12 + 0x1e);
  uVar5 = *(uint *)(iVar12 + 0x20);
  for (iVar7 = *(int *)0xc4f4; iVar7 != 0; iVar7 = iVar7 + -1) {
    uVar4 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    uVar10 = (uint)(CONCAT12(uVar4 != 0,uVar10) >> 1);
  }
  uVar5 = uVar10 >> 8;
  if ((*(uint *)(iVar12 + 0x1e) & *(uint *)0xc4f6) != 0 || (uVar10 & 0xff) != 0) {
    uVar5 = uVar5 + 1;
  }
  if ((uVar5 & 0xff80) != 0) {
    uVar5 = 0x7f;
  }
  uVar10 = *(uint *)((int)unaff_SI + 0x6077);
  *(uint *)((int)unaff_SI + 0x6077) = uVar5;
  bVar9 = 0x50;
  iVar7 = uVar5 - uVar10;
  puVar8 = puVar2;
  if (iVar7 != 0) {
    if (uVar5 < uVar10) {
      pbVar1 = (byte *)(iVar13 + (int)puVar2);
      bVar9 = *pbVar1;
      bVar6 = (byte)(uVar10 - 1 >> 8);
      bVar3 = *pbVar1 - bVar6;
      *pbVar1 = bVar3 - (iVar7 != 0);
      uVar10 = (uint)(byte)(*(char *)0xddce + 'P' + (bVar9 < bVar6 || bVar3 < (iVar7 != 0)));
      do {
        *unaff_DI = 0xff;
        unaff_DI = unaff_DI + uVar10;
        puVar8 = (undefined2 *)((int)puVar8 + -1);
      } while (puVar8 != (undefined2 *)0x0);
      iVar13 = CONCAT11((char)((uint)(iVar12 + 0x17) >> 8),
                        (byte)(iVar12 + 0x17) | unaff_DI[iVar12 + 0x76]);
      puVar8 = unaff_DS;
    }
    else {
      puVar14 = unaff_DI + uVar10 * -0x50;
      FUN_1000_4b82();
      do {
        *puVar14 = 0x5a;
        puVar14 = puVar14 + -extraout_DX;
        iVar7 = iVar7 + -1;
        uVar10 = extraout_DX;
      } while (iVar7 != 0);
    }
    bVar9 = (byte)uVar10;
    iVar13 = iVar13 + 0x16;
  }
  *(char *)((int)unaff_SI + 0x6077) =
       *(char *)((int)unaff_SI + 0x6077) + CARRY1(bVar9,*(byte *)0xe460);
  uVar11 = 0;
  if (*(int *)(iVar13 + 6) != 0) {
    uVar11 = *(undefined2 *)(*(int *)(iVar13 + 6) + 6);
  }
  *(undefined2 *)0x8470 = uVar11;
  func_0x0001f552();
  LOCK();
  iVar13 = *(int *)((int)puVar8 + (int)puVar2);
  *(int *)((int)puVar8 + (int)puVar2) = (int)puVar2;
  UNLOCK();
  LOCK();
  *(undefined2 *)((int)puVar8 + iVar13 + 0x14) = extraout_DX_00;
  UNLOCK();
  *(undefined1 *)((int)puVar8 + -0x7b87) = extraout_AH;
  return;
}


