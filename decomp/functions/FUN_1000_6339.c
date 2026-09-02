/* 1000:6339 */

/* WARNING: Instruction at (ram,0x00016406) overlaps instruction at (ram,0x00016404)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_1000_6339(byte *param_1)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint in_BX;
  int unaff_BP;
  uint *unaff_SI;
  uint *puVar14;
  int unaff_DI;
  byte *pbVar15;
  uint *puVar16;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar17;
  byte bVar18;
  
  bVar4 = (byte)in_BX & 7;
  bVar4 = 0x80U >> bVar4 | -0x80 << 8 - bVar4;
  uVar7 = (uint)bVar4;
  pbVar15 = (byte *)(unaff_DI + (in_BX >> 3));
  puVar16 = (uint *)*(undefined2 *)(unaff_BP + -2);
  puVar13 = (uint *)*(undefined2 *)(unaff_BP + -4);
  if ((int)puVar13 < 0) {
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar4;
    *(byte *)(unaff_BP + (int)unaff_SI) =
         *(byte *)(unaff_BP + (int)unaff_SI) + bVar4 + (pbVar15 < *(byte **)pbVar15);
    *(char *)0x866 = *(char *)0x866 + (char)puVar13;
    return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
  }
  if (puVar16 < puVar13) {
    uVar7 = (uVar7 - *(int *)(byte *)((int)unaff_SI + 0xa5)) - 1;
    pbVar15 = pbVar15 + 0x50;
    puVar14 = (uint *)((int)unaff_SI - (int)puVar16);
    if (unaff_SI < puVar16) {
      puVar14 = (uint *)((int)puVar14 + *(int *)(unaff_BP + -4));
      bVar4 = (byte)uVar7 & 0x20;
      uVar7 = (uint)bVar4;
      out(puVar16,bVar4);
    }
    iVar6 = CONCAT11(0x12,(char)puVar13) + 1;
    puVar13 = (uint *)0x0;
    goto LAB_1000_63cb;
  }
  puVar14 = (uint *)((uint)puVar16 >> 1);
  pbVar5 = (byte *)((int)puVar16 + 1);
  do {
    bVar4 = (byte)uVar7;
    *pbVar15 = bVar4;
    uVar7 = (uint)(byte)(bVar4 >> 1 | bVar4 << 7);
    pbVar15 = pbVar15 + (bVar4 & 1);
    bVar17 = puVar14 < puVar13;
    puVar14 = (uint *)((int)puVar14 - (int)puVar13);
    if (bVar17) {
      puVar14 = (uint *)((int)puVar14 + *(int *)(unaff_BP + -2));
      pbVar15 = pbVar15 + 0x50;
    }
    pbVar5 = pbVar5 + -1;
  } while (pbVar5 != (byte *)0x0);
  iVar6 = 0;
  while( true ) {
    bVar4 = (char)uVar7 + 0x88;
    uVar7 = (uint)(byte)(bVar4 >> 1 | (char)uVar7 << 7);
    pbVar15 = pbVar15 + (int)puVar13 + (bVar4 & 1);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
LAB_1000_63cb:
    *pbVar15 = (byte)uVar7;
    pbVar15[0x50] = (byte)uVar7;
  }
  pbVar15 = (byte *)*(undefined2 *)(unaff_BP + -2);
  bVar3 = in(puVar13);
  *(byte *)puVar14 = (byte)*puVar14 ^ (byte)((uint)pbVar15 >> 8);
  bVar4 = bVar3;
  if (((uint)pbVar15 & 7) != 0) {
    uVar7 = (uint)((byte)pbVar15 & 7);
    do {
      bVar18 = bVar4 & 1;
      bVar4 = bVar4 >> 1 | bVar4 << 7;
      pbVar15 = (byte *)((int)puVar13 + (int)(pbVar15 + bVar18));
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  iVar6 = *(int *)(unaff_BP + -4) + 1;
  do {
    iVar8 = iVar6;
    *param_1 = bVar3;
    param_1[(int)pbVar15] = bVar4;
    param_1 = param_1 + 0x50;
    iVar6 = iVar8 + -1;
  } while (iVar6 != 0);
  LOCK();
  bVar18 = *(byte *)((int)puVar14 + (int)(pbVar15 + 2));
  *(byte *)((int)puVar14 + (int)(pbVar15 + 2)) = bVar4;
  UNLOCK();
  uVar9 = iVar8 - 2;
  *(byte *)(unaff_BP + (int)puVar14) = *(byte *)(unaff_BP + (int)puVar14) & bVar3;
  *(uint *)(unaff_BP + 0x220) = *(uint *)(unaff_BP + 0x220) & CONCAT11(bVar18,bVar3);
  pbVar1 = (byte *)(unaff_BP + 0x4df0);
  *pbVar1 = *pbVar1 << 1 | *pbVar1 >> 7;
  *puVar14 = *puVar14 ^ uVar9;
  bVar4 = (byte)uVar9 & 7;
  bVar4 = 0x80U >> bVar4 | -0x80 << 8 - bVar4;
  uVar12 = (uint)bVar4;
  *(int *)(unaff_BP + -5) = *(int *)(unaff_BP + -5) + 1;
  uVar7 = puVar14[0x28];
  uVar10 = 0;
  do {
    *(byte *)puVar14 = bVar4;
    uVar10 = uVar10 - 1;
    uVar11 = uVar7;
    puVar16 = puVar14;
    if (uVar10 == 0) goto LAB_1000_6450;
    bVar17 = (bool)(bVar4 & 1);
    bVar4 = bVar4 >> 1 | bVar4 << 7;
  } while (!bVar17);
  puVar16 = (uint *)((int)puVar14 + 1);
  uVar11 = uVar10 >> 3;
  if (uVar11 != 0) {
    for (; uVar11 != 0; uVar11 = uVar11 - 1) {
      puVar2 = puVar16;
      puVar16 = (uint *)((int)puVar16 + 1);
      *(byte *)puVar2 = ((uVar9 & 0x1f) != 0) * ((int)(uVar12 << 8) < 0) - 0xe;
    }
  }
  for (uVar12 = uVar10 & 7; uVar11 = uVar10, uVar12 != 0; uVar12 = uVar12 - 1) {
    *(byte *)puVar16 = bVar4;
    bVar4 = bVar4 >> 1 | bVar4 << 7;
  }
LAB_1000_6450:
  if (puVar14 == (uint *)0xffb0) {
    *(byte *)(puVar16 + 0x5f) = (byte)puVar16[0x5f] | (byte)uVar7;
    return CONCAT22(uVar11,uVar7);
  }
  return CONCAT22(uVar11,uVar7);
}


