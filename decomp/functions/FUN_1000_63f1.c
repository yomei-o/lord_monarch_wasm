/* 1000:63f1 */

/* WARNING: Instruction at (ram,0x00016406) overlaps instruction at (ram,0x00016404)
    */

void FUN_1000_63f1(void)

{
  byte *pbVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined2 in_AX;
  byte bVar6;
  byte bVar7;
  int in_CX;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int in_BX;
  int unaff_BP;
  uint *unaff_SI;
  byte *unaff_DI;
  uint *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar14;
  
  iVar9 = in_CX + 1;
  do {
    iVar8 = iVar9;
    bVar7 = (byte)in_AX;
    *unaff_DI = bVar7;
    bVar6 = (byte)((uint)in_AX >> 8);
    unaff_DI[in_BX] = bVar6;
    unaff_DI = unaff_DI + 0x50;
    iVar9 = iVar8 + -1;
  } while (iVar9 != 0);
  LOCK();
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 2);
  bVar2 = *pbVar1;
  *pbVar1 = bVar6;
  UNLOCK();
  uVar10 = iVar8 - 2;
  *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar7;
  *(uint *)(unaff_BP + 0x220) = *(uint *)(unaff_BP + 0x220) & CONCAT11(bVar2,bVar7);
  pbVar1 = (byte *)(unaff_BP + 0x4df0);
  *pbVar1 = *pbVar1 << 1 | *pbVar1 >> 7;
  *unaff_SI = *unaff_SI ^ uVar10;
  bVar7 = (byte)uVar10 & 7;
  bVar7 = 0x80U >> bVar7 | -0x80 << 8 - bVar7;
  uVar5 = (uint)bVar7;
  *(int *)(unaff_BP + -5) = *(int *)(unaff_BP + -5) + 1;
  uVar4 = unaff_SI[0x28];
  uVar11 = 0;
  do {
    *(byte *)unaff_SI = bVar7;
    uVar11 = uVar11 - 1;
    puVar13 = unaff_SI;
    if (uVar11 == 0) goto LAB_1000_6450;
    bVar14 = (bool)(bVar7 & 1);
    bVar7 = bVar7 >> 1 | bVar7 << 7;
  } while (!bVar14);
  puVar13 = (uint *)((int)unaff_SI + 1);
  uVar12 = uVar11 >> 3;
  if (uVar12 != 0) {
    for (; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = puVar13;
      puVar13 = (uint *)((int)puVar13 + 1);
      *(char *)puVar3 = ((uVar10 & 0x1f) != 0) * ((int)(uVar5 << 8) < 0) + -0xe;
    }
  }
  for (uVar11 = uVar11 & 7; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(byte *)puVar13 = bVar7;
    bVar7 = bVar7 >> 1 | bVar7 << 7;
  }
LAB_1000_6450:
  if (unaff_SI == (uint *)0xffb0) {
    *(byte *)(puVar13 + 0x5f) = (byte)puVar13[0x5f] | (byte)uVar4;
    return;
  }
  return;
}


