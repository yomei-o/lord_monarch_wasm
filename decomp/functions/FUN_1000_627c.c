/* 1000:627c */

/* WARNING: Unable to track spacebase fully for stack */

int FUN_1000_627c(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined1 extraout_AL;
  uint in_AX;
  uint uVar6;
  int iVar7;
  char extraout_AH;
  int in_CX;
  uint in_DX;
  uint extraout_DX;
  char cVar9;
  uint in_BX;
  int iVar10;
  uint unaff_BP;
  byte *unaff_SI;
  int *unaff_DI;
  undefined1 *puVar11;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  bool bVar13;
  uint3 in_stack_00000000;
  byte bVar8;
  
  while( true ) {
    uVar4 = unaff_BP * 2;
    cVar9 = (char)in_BX * '\x02' + CARRY2(unaff_BP,unaff_BP);
    uVar5 = (undefined1)(((uint)((in_DX & 1) != 0) << 8 | in_BX >> 8) >> 1);
    iVar10 = CONCAT11(uVar5,cVar9);
    uVar6 = in_AX | uVar4 | in_DX >> 1;
    bVar8 = (byte)(uVar6 >> 8);
    iVar7 = CONCAT11((char)uVar6,bVar8);
    *(char *)((int)unaff_DI + -1) = cVar9;
    *unaff_DI = iVar7;
    *(undefined1 *)((int)unaff_DI + 1) = uVar5;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 2;
    iVar10 = *(int *)pbVar1;
    *unaff_DI = iVar10;
    unaff_DI[0x50] = iVar10;
    in_AX = CONCAT11((char)iVar10,(char)((uint)iVar10 >> 8));
    in_BX = 0;
    in_DX = in_AX;
    unaff_BP = in_AX;
    unaff_DI = unaff_DI + 0x28;
  }
  *unaff_SI = *unaff_SI ^ bVar8;
  pbVar1 = (byte *)((int)unaff_DI + 0x4f);
  *pbVar1 = *pbVar1 + bVar8;
  *(byte *)((int)unaff_DI + 0x4f) = bVar8;
  puVar11 = (undefined1 *)((int)unaff_DI + 0x51);
  uVar6 = iVar7 + 1;
  unaff_SI[uVar4] = unaff_SI[uVar4] + (byte)uVar6 + ((in_stack_00000000 & 1) != 0);
  bVar13 = (in_stack_00000000 & 0x40000) != 0;
  if ((in_stack_00000000 & 0x80000) == 0) {
    unaff_SI[0x346] = unaff_SI[0x346] + (char)(uVar6 >> 8);
    *(byte *)(unaff_DI + 0x28) = *unaff_SI;
    unaff_SI = unaff_SI + (uint)bVar13 * -2 + 2;
    puVar11 = puVar11 + uVar6 + (uint)bVar13 * -2;
    unaff_SI[iVar10 + 0x10] = unaff_SI[iVar10 + 0x10] | (byte)(in_DX >> 1);
    unaff_SI[iVar10] = unaff_SI[iVar10] << 1;
    LOCK();
    unaff_SI[iVar10 + 0x30ac] = unaff_SI[iVar10 + 0x30ac] ^ (byte)uVar6;
    UNLOCK();
  }
  iVar7 = *(int *)0x32a8;
  FUN_1000_5aba(uVar6,(char)unaff_SI);
  puVar11[uVar4 + 0xbad9] = puVar11[uVar4 + 0xbad9] - (byte)in_CX;
  puVar11[uVar4] = puVar11[uVar4] + (char)((uint)in_CX >> 8);
  piVar2 = (int *)(iVar10 + iVar7 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)in_CX & 0x1f);
  iVar7 = iVar10;
  cVar9 = extraout_AH;
  do {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      puVar3 = puVar11;
      puVar11 = puVar11 + (uint)bVar13 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar12 = CARRY2((uint)puVar11,extraout_DX);
    puVar11 = puVar11 + extraout_DX;
    cVar9 = cVar9 + -1;
    iVar7 = iVar10;
  } while (cVar9 != '\0');
  return (byte)-bVar12 + 0x6108 + (uint)bVar12;
}


