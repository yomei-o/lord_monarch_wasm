/* 1000:5d66 */

undefined2 FUN_1000_5d66(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  undefined2 in_AX;
  uint uVar6;
  byte bVar7;
  int in_CX;
  int iVar8;
  byte bVar9;
  int in_BX;
  uint uVar10;
  int unaff_BP;
  uint unaff_SI;
  byte *pbVar13;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar11;
  byte bVar12;
  
  while( true ) {
    bVar4 = (byte)in_AX | 0x20;
    bVar9 = *(byte *)(in_BX + unaff_SI);
    bVar12 = (byte)((uint)in_BX >> 8);
    cVar11 = bVar12 + bVar4;
    uVar10 = CONCAT11(cVar11,(char)in_BX);
    bVar7 = ((byte)in_CX & 0x1f) % 0x11;
    uVar6 = *(uint *)(unaff_BP + (int)unaff_DI);
    *(uint *)(unaff_BP + (int)unaff_DI) =
         uVar6 << bVar7 | (uint)(CONCAT12(CARRY1(bVar12,bVar4),uVar6) >> 0x11 - bVar7);
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x3c3);
    *pbVar1 = *pbVar1 ^ (byte)in_CX;
    *(char *)(unaff_BP + (int)unaff_DI) = *(char *)(unaff_BP + (int)unaff_DI) << 6;
    uVar6 = (uint)(((ulong)~(CONCAT11((byte)((uint)in_AX >> 8) | bVar9,(byte)in_AX) | 0x20) |
                   0x10000) >> 1) & uVar10 | unaff_SI;
    cVar5 = (char)uVar6;
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar2 = CONCAT11(cVar5,(char)(uVar6 >> 8));
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    *(int *)(uVar10 + unaff_SI) = *(int *)(uVar10 + unaff_SI) + uVar10;
    out(0xa5,cVar5 >> 7);
    uVar3 = in(0xa9);
    in_BX = CONCAT11(cVar11,uVar3);
    in_AX = CONCAT11(cVar5,cVar5 >> 7);
  }
  pbVar13 = (byte *)0x3e20;
  bVar9 = 0;
  do {
    out(0xa8,bVar9);
    uVar6 = 0xae;
    iVar8 = 3;
    do {
      pbVar1 = pbVar13;
      pbVar13 = pbVar13 + 1;
      bVar7 = (byte)((uint)(byte)((*pbVar1 & 0xf) + 1) * (uint)*(byte *)0x34d6 >> 8);
      out(uVar6,bVar7);
      uVar6 = uVar6 - 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    bVar9 = bVar9 + 1;
  } while (bVar9 < 0x10);
  bVar9 = (byte)uVar6;
  *(char *)0xe432 = *(char *)0xe432 + bVar9 + CARRY1(bVar7,bVar9);
  bVar9 = ~(byte)((uint)(byte)(bVar7 + bVar9) / (uVar6 & 0xff));
  return CONCAT11(bVar9,bVar9);
}


