/* 1000:6217 */

int FUN_1000_6217(int param_1,undefined2 *param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  int *piVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  byte bVar8;
  undefined1 uVar9;
  undefined1 extraout_AL;
  undefined2 uVar10;
  byte bVar14;
  uint uVar11;
  uint uVar12;
  int iVar13;
  char extraout_AH;
  char cVar15;
  undefined2 in_CX;
  int iVar16;
  byte extraout_DL;
  uint extraout_DX;
  int iVar17;
  int unaff_BP;
  int unaff_SI;
  uint *puVar18;
  int *piVar19;
  undefined1 *puVar20;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar21;
  bool bVar22;
  
  uVar10 = func_0x00015e90();
  iVar16 = CONCAT11((char)((uint)param_1 >> 8),(char)param_1 - *(char *)(param_1 + unaff_SI));
  *(byte *)0xe805 = *(byte *)0xe805 & (byte)uVar10;
  pbVar1 = (byte *)(iVar16 + unaff_SI + 2);
  bVar8 = *pbVar1;
  bVar14 = (byte)((uint)uVar10 >> 8);
  *pbVar1 = *pbVar1 - bVar14;
  pcVar2 = (char *)(iVar16 + param_3 + 0xa06);
  *pcVar2 = (*pcVar2 - (byte)uVar10) - (bVar8 < bVar14);
  bVar8 = func_0x00019312();
  cVar15 = (char)((uint)iVar16 >> 8);
  bVar14 = (byte)((uint)in_CX >> 8);
  cVar21 = CARRY1(bVar14,extraout_DL) ||
           CARRY1(bVar14 + extraout_DL,CARRY1(bVar8,*(byte *)(unaff_BP + 0x30)));
  bVar14 = (byte)in_CX;
  uVar9 = FUN_1000_5b27(bVar8 + *(byte *)(unaff_BP + 0x30));
  out(0x23,uVar9);
  *(char *)(unaff_BP + 0x3e50) = (*(char *)(unaff_BP + 0x3e50) - cVar15) - cVar21;
  *param_2 = *(undefined2 *)0x612;
  param_2[0x28] = *(undefined2 *)0x614;
  *(byte *)0x616 = *(byte *)0x616 ^ bVar14;
  *(undefined1 *)(param_2 + 0x50) = *(undefined1 *)0x616;
  iVar16 = 0x10;
  puVar6 = (uint *)0x610;
  piVar7 = (int *)((int)param_2 + -0x411);
  do {
    piVar19 = piVar7;
    puVar18 = puVar6;
    puVar6 = puVar18 + 1;
    uVar12 = *puVar18;
    piVar19[-0x28] = uVar12;
    piVar19[0x28] = uVar12;
    uVar11 = CONCAT11((char)uVar12,(char)(uVar12 >> 8));
    uVar5 = uVar11 * 2;
    cVar15 = ((uVar12 & 0x100) != 0) << 7;
    iVar17 = CONCAT11(cVar15,CARRY2(uVar11,uVar11));
    uVar12 = uVar11 | uVar5 | uVar11 >> 1;
    bVar8 = (byte)(uVar12 >> 8);
    iVar13 = CONCAT11((char)uVar12,bVar8);
    *(bool *)((int)piVar19 + -1) = CARRY2(uVar11,uVar11);
    *piVar19 = iVar13;
    *(char *)((int)piVar19 + 1) = cVar15;
    iVar16 = iVar16 + -1;
    piVar7 = piVar19 + 0x28;
  } while (iVar16 != 0);
  *(byte *)puVar6 = (byte)*puVar6 ^ bVar8;
  pbVar1 = (byte *)((int)piVar19 + 0x4f);
  *pbVar1 = *pbVar1 + bVar8;
  *(byte *)((int)piVar19 + 0x4f) = bVar8;
  uVar12 = iVar13 + 1;
  *(byte *)(puVar6 + uVar11) =
       (byte)puVar6[uVar11] + (byte)uVar12 + (((uint)((int)param_2 + -0x411) & 1) != 0);
  *(byte *)(puVar18 + 0x1a4) = (byte)puVar18[0x1a4] + (char)(uVar12 >> 8);
  *(byte *)(piVar19 + 0x28) = (byte)*puVar6;
  puVar18 = puVar18 + 2;
  puVar20 = (undefined1 *)((int)piVar19 + iVar13 + 0x52);
  pbVar1 = (byte *)((int)puVar18 + iVar17 + 0x10);
  *pbVar1 = *pbVar1 | (byte)(uVar11 >> 1);
  *(byte *)(iVar17 + (int)puVar18) = *(byte *)(iVar17 + (int)puVar18) << 1;
  LOCK();
  pbVar1 = (byte *)((int)puVar18 + iVar17 + 0x30ac);
  *pbVar1 = *pbVar1 ^ (byte)uVar12;
  UNLOCK();
  iVar13 = *(int *)0x32a8;
  FUN_1000_5aba(uVar12,(char)puVar18);
  puVar20[uVar5 + 0xbad9] = puVar20[uVar5 + 0xbad9] - (byte)iVar16;
  puVar20[uVar5] = puVar20[uVar5] + (char)((uint)iVar16 >> 8);
  piVar3 = (int *)(iVar17 + iVar13 + 0x10ff);
  *piVar3 = *piVar3 >> ((byte)iVar16 & 0x1f);
  iVar16 = iVar17;
  cVar15 = extraout_AH;
  do {
    for (; iVar16 != 0; iVar16 = iVar16 + -1) {
      puVar4 = puVar20;
      puVar20 = puVar20 + 1;
      *puVar4 = extraout_AL;
    }
    bVar22 = CARRY2((uint)puVar20,extraout_DX);
    puVar20 = puVar20 + extraout_DX;
    cVar15 = cVar15 + -1;
    iVar16 = iVar17;
  } while (cVar15 != '\0');
  return (byte)-bVar22 + 0x6108 + (uint)bVar22;
}


