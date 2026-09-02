/* 1000:6cd2 */

void FUN_1000_6cd2(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 in_AX;
  uint uVar5;
  byte bVar6;
  undefined1 extraout_AH;
  int in_CX;
  int iVar7;
  undefined2 *puVar8;
  byte bVar9;
  int in_DX;
  uint uVar10;
  uint extraout_DX;
  undefined2 uVar11;
  undefined2 extraout_DX_00;
  int iVar12;
  int iVar13;
  undefined2 *puVar14;
  undefined2 *unaff_DI;
  undefined1 *puVar15;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 *unaff_DS;
  
  while( true ) {
    unaff_DI = (undefined2 *)((int)unaff_DI + in_DX);
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    *unaff_DI = in_AX;
    *(undefined2 *)((int)unaff_DI + 3) = in_AX;
    unaff_DI[3] = in_AX;
    *(undefined2 *)((int)unaff_DI + 9) = in_AX;
    *(char *)(unaff_DI + 6) = (char)in_AX;
  }
  puVar15 = (undefined1 *)0x66be;
  iVar12 = 2;
  if ((*(byte *)0x3482 & 1) != 0) {
    iVar12 = 6;
  }
  iVar7 = 4;
  puVar4 = (undefined2 *)0x3484;
  do {
    puVar14 = puVar4;
    *(undefined2 *)(iVar12 + (int)puVar14) = 0;
    *(undefined2 *)((int)puVar14 + iVar12 + 2) = 0;
    FUN_1000_710b();
    puVar15 = puVar15 + 3;
    iVar7 = iVar7 + -1;
    puVar4 = puVar14 + 5;
  } while (iVar7 != 0);
  puVar15[iVar12 + -0x3d] = puVar15[iVar12 + -0x3d] & 6;
  iVar7 = 5;
  uVar5 = 0;
  uVar10 = 0;
  iVar12 = -0x386e;
  do {
    iVar13 = iVar12;
    if ((uVar10 < *(uint *)(iVar13 + 10)) ||
       ((uVar10 == *(uint *)(iVar13 + 10) && (uVar5 < *(uint *)(iVar13 + 8))))) {
      uVar10 = *(uint *)(iVar13 + 10);
      uVar5 = *(uint *)(iVar13 + 8);
    }
    iVar12 = iVar13 + 0x16;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0;
  for (; uVar10 != 0; uVar10 = uVar10 >> 1) {
    iVar7 = iVar7 + 1;
  }
  *(int *)0xc4f4 = iVar7 + 1;
  *(uint *)0xc4f6 = ~(-1 << ((byte)(iVar7 + 1) & 0x1f));
  puVar4 = puVar14 + 6;
  out(puVar14[5],0);
  *(undefined1 *)(puVar14 + 0x16) = 0;
  uVar10 = *(uint *)(iVar13 + 0x1e);
  uVar5 = *(uint *)(iVar13 + 0x20);
  for (iVar7 = *(int *)0xc4f4; iVar7 != 0; iVar7 = iVar7 + -1) {
    uVar3 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    uVar10 = (uint)(CONCAT12(uVar3 != 0,uVar10) >> 1);
  }
  uVar5 = uVar10 >> 8;
  if ((*(uint *)(iVar13 + 0x1e) & *(uint *)0xc4f6) != 0 || (uVar10 & 0xff) != 0) {
    uVar5 = uVar5 + 1;
  }
  if ((uVar5 & 0xff80) != 0) {
    uVar5 = 0x7f;
  }
  uVar10 = *(uint *)((int)puVar14 + 0x6077);
  *(uint *)((int)puVar14 + 0x6077) = uVar5;
  bVar9 = 0x50;
  iVar7 = uVar5 - uVar10;
  puVar8 = puVar4;
  if (iVar7 != 0) {
    if (uVar5 < uVar10) {
      pbVar1 = (byte *)(iVar12 + (int)puVar4);
      bVar9 = *pbVar1;
      bVar6 = (byte)(uVar10 - 1 >> 8);
      bVar2 = *pbVar1 - bVar6;
      *pbVar1 = bVar2 - (iVar7 != 0);
      uVar10 = (uint)(byte)(*(char *)0xddce + 'P' + (bVar9 < bVar6 || bVar2 < (iVar7 != 0)));
      do {
        *puVar15 = 0xff;
        puVar15 = puVar15 + uVar10;
        puVar8 = (undefined2 *)((int)puVar8 + -1);
      } while (puVar8 != (undefined2 *)0x0);
      iVar12 = CONCAT11((char)((uint)(iVar13 + 0x17) >> 8),
                        (byte)(iVar13 + 0x17) | puVar15[iVar13 + 0x76]);
      puVar8 = unaff_DS;
    }
    else {
      puVar15 = puVar15 + uVar10 * -0x50;
      FUN_1000_4b82();
      do {
        *puVar15 = 0x5a;
        puVar15 = puVar15 + -extraout_DX;
        iVar7 = iVar7 + -1;
        uVar10 = extraout_DX;
      } while (iVar7 != 0);
    }
    bVar9 = (byte)uVar10;
    iVar12 = iVar12 + 0x16;
  }
  *(char *)((int)puVar14 + 0x6077) =
       *(char *)((int)puVar14 + 0x6077) + CARRY1(bVar9,*(byte *)0xe460);
  uVar11 = 0;
  if (*(int *)(iVar12 + 6) != 0) {
    uVar11 = *(undefined2 *)(*(int *)(iVar12 + 6) + 6);
  }
  *(undefined2 *)0x8470 = uVar11;
  func_0x0001f552();
  LOCK();
  iVar12 = *(int *)((int)puVar8 + (int)puVar4);
  *(int *)((int)puVar8 + (int)puVar4) = (int)puVar4;
  UNLOCK();
  LOCK();
  *(undefined2 *)((int)puVar8 + iVar12 + 0x14) = extraout_DX_00;
  UNLOCK();
  *(undefined1 *)((int)puVar8 + -0x7b87) = extraout_AH;
  return;
}


