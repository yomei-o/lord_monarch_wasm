/* 1000:5fe0 */

int thunk_FUN_1000_6259(int param_1,undefined2 param_2)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined1 extraout_AL;
  undefined2 in_AX;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char extraout_AH;
  char cVar11;
  int iVar12;
  undefined2 in_DX;
  uint extraout_DX;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  int *unaff_DI;
  int *piVar16;
  undefined1 *puVar17;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar18;
  bool bVar19;
  byte bVar10;
  
  out(in_DX,in_AX);
  iVar12 = 0x10;
  puVar15 = (uint *)(param_1 + -2);
  piVar5 = unaff_DI;
  do {
    piVar16 = piVar5;
    puVar14 = puVar15;
    puVar15 = puVar14 + 1;
    uVar7 = *puVar14;
    piVar16[-0x28] = uVar7;
    piVar16[0x28] = uVar7;
    uVar6 = CONCAT11((char)uVar7,(char)(uVar7 >> 8));
    uVar4 = uVar6 * 2;
    cVar11 = ((uVar7 & 0x100) != 0) << 7;
    iVar13 = CONCAT11(cVar11,CARRY2(uVar6,uVar6));
    uVar7 = uVar6 | uVar4 | uVar6 >> 1;
    bVar10 = (byte)(uVar7 >> 8);
    iVar8 = CONCAT11((char)uVar7,bVar10);
    *(bool *)((int)piVar16 + -1) = CARRY2(uVar6,uVar6);
    *piVar16 = iVar8;
    *(char *)((int)piVar16 + 1) = cVar11;
    iVar12 = iVar12 + -1;
    piVar5 = piVar16 + 0x28;
  } while (iVar12 != 0);
  *(byte *)puVar15 = (byte)*puVar15 ^ bVar10;
  pbVar1 = (byte *)((int)piVar16 + 0x4f);
  *pbVar1 = *pbVar1 + bVar10;
  *(byte *)((int)piVar16 + 0x4f) = bVar10;
  puVar17 = (undefined1 *)((int)piVar16 + 0x51);
  uVar9 = iVar8 + 1;
  *(byte *)(puVar15 + uVar6) = (byte)puVar15[uVar6] + (byte)uVar9 + (((uint)unaff_DI & 1) != 0);
  uVar7 = (param_1 + -2) * 0x100;
  bVar19 = (uVar7 & 0x400) != 0;
  if ((uVar7 & 0x800) == 0) {
    *(byte *)(puVar14 + 0x1a4) = (byte)puVar14[0x1a4] + (char)(uVar9 >> 8);
    *(byte *)(piVar16 + 0x28) = (byte)*puVar15;
    puVar15 = puVar15 + !bVar19;
    puVar17 = puVar17 + uVar9 + (uint)bVar19 * -2;
    pbVar1 = (byte *)((int)puVar15 + iVar13 + 0x10);
    *pbVar1 = *pbVar1 | (byte)(uVar6 >> 1);
    *(byte *)(iVar13 + (int)puVar15) = *(byte *)(iVar13 + (int)puVar15) << 1;
    LOCK();
    pbVar1 = (byte *)((int)puVar15 + iVar13 + 0x30ac);
    *pbVar1 = *pbVar1 ^ (byte)uVar9;
    UNLOCK();
  }
  iVar8 = *(int *)0x32a8;
  FUN_1000_5aba(uVar9,(char)puVar15);
  puVar17[uVar4 + 0xbad9] = puVar17[uVar4 + 0xbad9] - (byte)iVar12;
  puVar17[uVar4] = puVar17[uVar4] + (char)((uint)iVar12 >> 8);
  piVar2 = (int *)(iVar13 + iVar8 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)iVar12 & 0x1f);
  iVar12 = iVar13;
  cVar11 = extraout_AH;
  do {
    for (; iVar12 != 0; iVar12 = iVar12 + -1) {
      puVar3 = puVar17;
      puVar17 = puVar17 + (uint)bVar19 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar18 = CARRY2((uint)puVar17,extraout_DX);
    puVar17 = puVar17 + extraout_DX;
    cVar11 = cVar11 + -1;
    iVar12 = iVar13;
  } while (cVar11 != '\0');
  return (byte)-bVar18 + 0x6108 + (uint)bVar18;
}


