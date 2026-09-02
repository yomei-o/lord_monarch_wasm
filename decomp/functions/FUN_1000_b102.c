/* 1000:b102 */

undefined4 __cdecl16near FUN_1000_b102(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 in_AX;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  int iVar12;
  undefined2 in_DX;
  uint *puVar13;
  byte *pbVar14;
  undefined2 unaff_DS;
  undefined1 uVar15;
  
  puVar13 = (uint *)0xc792;
  iVar12 = 4;
  while (((*puVar13 & 8) != 0 || ((*puVar13 & 5) == 0))) {
    puVar13 = puVar13 + 0xb;
    iVar12 = iVar12 + -1;
    if (iVar12 == 0) goto LAB_1000_b28a;
  }
  uVar11 = *(undefined2 *)&DAT_0000_3be2;
  uVar5 = *(undefined2 *)&DAT_0000_3be4;
  iVar9 = (uint)*(byte *)((int)puVar13 + 0x15) * 0x16;
  uVar6 = puVar13[7];
  puVar1 = (uint *)((undefined *)&DAT_0000_c7a0 + iVar9);
  uVar4 = *puVar1;
  *puVar1 = *puVar1 + uVar6;
  uVar7 = puVar13[8];
  puVar1 = (uint *)((undefined *)&DAT_0000_c7a2 + iVar9);
  uVar6 = (uint)CARRY2(uVar4,uVar6);
  uVar4 = *puVar1;
  uVar8 = *puVar1 + uVar7;
  *puVar1 = uVar8 + uVar6;
  if (CARRY2(uVar4,uVar7) || CARRY2(uVar8,uVar6)) {
    *(undefined2 *)((undefined *)&DAT_0000_c7a0 + iVar9) = 0xffff;
    *(uint *)((undefined *)&DAT_0000_c7a2 + iVar9) =
         *(int *)((undefined *)&DAT_0000_c7a2 + iVar9) + -1 +
         (uint)(CARRY2(uVar4,uVar7) || CARRY2(uVar8,uVar6));
  }
  puVar13[7] = 0;
  puVar13[8] = 0;
  *(undefined1 *)(puVar13 + 9) = 0;
  *puVar13 = *puVar13 | 8;
  puVar13[3] = 0;
  *(uint *)&DAT_0000_3be4 = puVar13[1];
  FUN_1000_a656();
  uVar4 = puVar13[2];
  LOCK();
  bVar3 = (byte)puVar13[10];
  *(byte *)(puVar13 + 10) = 0x80;
  UNLOCK();
  if (bVar3 < 4) {
    *(undefined1 *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)bVar3 * 2) + 0x14) = 0x80;
  }
  iVar12 = 4 - iVar12;
  *(undefined2 *)0xc536 = *(undefined2 *)((undefined *)&DAT_0000_12ad + iVar12 * 2);
  FUN_1000_7c9e();
  uVar15 = (undefined1)iVar12;
  FUN_1000_93c5();
  uVar10 = FUN_1000_4a4d();
  FUN_1000_0d12(uVar10);
  FUN_1000_72ad();
  FUN_1000_c921();
  *(undefined **)((undefined *)&DAT_0000_d21c + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d21e + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d220 + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d27c + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d27e + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d280 + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d2dc + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d2de + uVar4) = (undefined *)&DAT_0000_6400;
  *(undefined **)((undefined *)&DAT_0000_d2e0 + uVar4) = (undefined *)&DAT_0000_6400;
  FUN_1000_bcf4();
  uVar10 = CONCAT11(0x80,uVar15);
  pbVar14 = (byte *)&DAT_0000_c800;
  iVar12 = 0x40;
  do {
    if ((((*pbVar14 & (byte)((uint)uVar10 >> 8)) == 0) && ((byte)uVar10 == pbVar14[0xc])) &&
       ((pbVar14[10] & 0x20) != 0)) {
      pbVar14[10] = 1;
      uVar10 = FUN_1000_a9ca();
    }
    pbVar14 = pbVar14 + 0x10;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  FUN_1000_0d12(uVar10);
  FUN_1000_7c9e();
  FUN_1000_727a();
  FUN_1000_9520();
  FUN_1000_026a();
  *(undefined2 *)&DAT_0000_3be4 = uVar5;
  *(undefined2 *)&DAT_0000_3be2 = uVar11;
  FUN_1000_7c9e();
  FUN_1000_72ad();
  puVar13 = (uint *)0xc792;
  iVar12 = 4;
  iVar9 = 0;
  do {
    if ((*puVar13 & 8) != 0) {
      iVar9 = iVar9 + 1;
    }
    puVar13 = puVar13 + 0xb;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  if (iVar9 == 2) {
    puVar13 = (uint *)0xc792;
    iVar12 = 4;
    do {
      if ((*puVar13 & 8) == 0) break;
      puVar13 = puVar13 + 0xb;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    LOCK();
    bVar3 = (byte)puVar13[10];
    *(byte *)(puVar13 + 10) = 0x80;
    UNLOCK();
    if (bVar3 < 4) {
      iVar12 = (uint)bVar3 * 2;
      *(undefined2 *)0xc530 = *(undefined2 *)((undefined *)&DAT_0000_12ad + iVar12);
      LOCK();
      pbVar2 = (byte *)(*(int *)((undefined *)&DAT_0000_12ef + iVar12) + 0x14);
      bVar3 = *pbVar2;
      *pbVar2 = 0x80;
      UNLOCK();
      *(undefined2 *)0xc52e = *(undefined2 *)((undefined *)&DAT_0000_12ad + (uint)bVar3 * 2);
      FUN_1000_7c9e();
      FUN_1000_4a4d();
      uVar11 = FUN_1000_72ad();
      FUN_1000_0d12(uVar11);
      FUN_1000_c921();
    }
  }
LAB_1000_b28a:
  return CONCAT22(in_DX,in_AX);
}


