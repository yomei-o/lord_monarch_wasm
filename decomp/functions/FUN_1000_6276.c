/* 1000:6276 */

/* WARNING: Unable to track spacebase fully for stack */

int FUN_1000_6276(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 extraout_AL;
  uint in_AX;
  uint uVar5;
  int iVar6;
  char extraout_AH;
  char cVar8;
  int in_CX;
  uint extraout_DX;
  int iVar9;
  byte *unaff_SI;
  int *unaff_DI;
  undefined1 *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
  bool bVar12;
  uint3 in_stack_00000000;
  byte bVar7;
  
  while( true ) {
    uVar4 = in_AX * 2;
    cVar8 = ((in_AX & 1) != 0) << 7;
    iVar9 = CONCAT11(cVar8,CARRY2(in_AX,in_AX));
    uVar5 = in_AX | uVar4 | in_AX >> 1;
    bVar7 = (byte)(uVar5 >> 8);
    iVar6 = CONCAT11((char)uVar5,bVar7);
    *(bool *)((int)unaff_DI + -1) = CARRY2(in_AX,in_AX);
    *unaff_DI = iVar6;
    *(char *)((int)unaff_DI + 1) = cVar8;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 2;
    iVar9 = *(int *)pbVar1;
    *unaff_DI = iVar9;
    unaff_DI[0x50] = iVar9;
    in_AX = CONCAT11((char)iVar9,(char)((uint)iVar9 >> 8));
    unaff_DI = unaff_DI + 0x28;
  }
  *unaff_SI = *unaff_SI ^ bVar7;
  pbVar1 = (byte *)((int)unaff_DI + 0x4f);
  *pbVar1 = *pbVar1 + bVar7;
  *(byte *)((int)unaff_DI + 0x4f) = bVar7;
  puVar10 = (undefined1 *)((int)unaff_DI + 0x51);
  uVar5 = iVar6 + 1;
  unaff_SI[uVar4] = unaff_SI[uVar4] + (byte)uVar5 + ((in_stack_00000000 & 1) != 0);
  bVar12 = (in_stack_00000000 & 0x40000) != 0;
  if ((in_stack_00000000 & 0x80000) == 0) {
    unaff_SI[0x346] = unaff_SI[0x346] + (char)(uVar5 >> 8);
    *(byte *)(unaff_DI + 0x28) = *unaff_SI;
    unaff_SI = unaff_SI + (uint)bVar12 * -2 + 2;
    puVar10 = puVar10 + uVar5 + (uint)bVar12 * -2;
    unaff_SI[iVar9 + 0x10] = unaff_SI[iVar9 + 0x10] | (byte)(in_AX >> 1);
    unaff_SI[iVar9] = unaff_SI[iVar9] << 1;
    LOCK();
    unaff_SI[iVar9 + 0x30ac] = unaff_SI[iVar9 + 0x30ac] ^ (byte)uVar5;
    UNLOCK();
  }
  iVar6 = *(int *)0x32a8;
  FUN_1000_5aba(uVar5,(char)unaff_SI);
  puVar10[uVar4 + 0xbad9] = puVar10[uVar4 + 0xbad9] - (byte)in_CX;
  puVar10[uVar4] = puVar10[uVar4] + (char)((uint)in_CX >> 8);
  piVar2 = (int *)(iVar9 + iVar6 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)in_CX & 0x1f);
  iVar6 = iVar9;
  cVar8 = extraout_AH;
  do {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar3 = puVar10;
      puVar10 = puVar10 + (uint)bVar12 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar11 = CARRY2((uint)puVar10,extraout_DX);
    puVar10 = puVar10 + extraout_DX;
    cVar8 = cVar8 + -1;
    iVar6 = iVar9;
  } while (cVar8 != '\0');
  return (byte)-bVar11 + 0x6108 + (uint)bVar11;
}


