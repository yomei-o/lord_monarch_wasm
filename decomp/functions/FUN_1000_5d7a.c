/* 1000:5d7a */

undefined2 FUN_1000_5d7a(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte bVar3;
  undefined1 uVar4;
  uint in_AX;
  uint uVar5;
  byte bVar6;
  int in_CX;
  int iVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  uint in_BX;
  int unaff_BP;
  uint unaff_SI;
  byte *pbVar11;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while( true ) {
    uVar5 = in_AX & in_BX | unaff_SI;
    bVar9 = (byte)uVar5;
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar2 = CONCAT11(bVar9,(char)(uVar5 >> 8));
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    bVar8 = (char)bVar9 >> 7;
    *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + in_BX;
    out(0xa5,bVar8);
    uVar4 = in(0xa9);
    bVar10 = (byte)(in_BX >> 8);
    bVar6 = *(byte *)(CONCAT11(bVar10,uVar4) + unaff_SI);
    in_BX = CONCAT11(bVar10 + (bVar8 | 0x20),uVar4);
    bVar3 = ((byte)in_CX & 0x1f) % 0x11;
    uVar5 = *(uint *)(unaff_BP + (int)unaff_DI);
    *(uint *)(unaff_BP + (int)unaff_DI) =
         uVar5 << bVar3 | (uint)(CONCAT12(CARRY1(bVar10,bVar8 | 0x20),uVar5) >> 0x11 - bVar3);
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x3c3);
    *pbVar1 = *pbVar1 ^ (byte)in_CX;
    *(char *)(unaff_BP + (int)unaff_DI) = *(char *)(unaff_BP + (int)unaff_DI) << 6;
    in_AX = (uint)(((ulong)~(CONCAT11(bVar9 | bVar6,bVar8) | 0x20) | 0x10000) >> 1);
  }
  pbVar11 = (byte *)0x3e20;
  bVar9 = 0;
  do {
    out(0xa8,bVar9);
    uVar5 = 0xae;
    iVar7 = 3;
    do {
      pbVar1 = pbVar11;
      pbVar11 = pbVar11 + 1;
      bVar6 = (byte)((uint)(byte)((*pbVar1 & 0xf) + 1) * (uint)*(byte *)0x34d6 >> 8);
      out(uVar5,bVar6);
      uVar5 = uVar5 - 2;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    bVar9 = bVar9 + 1;
  } while (bVar9 < 0x10);
  bVar9 = (byte)uVar5;
  *(char *)0xe432 = *(char *)0xe432 + bVar9 + CARRY1(bVar6,bVar9);
  bVar9 = ~(byte)((uint)(byte)(bVar6 + bVar9) / (uVar5 & 0xff));
  return CONCAT11(bVar9,bVar9);
}


