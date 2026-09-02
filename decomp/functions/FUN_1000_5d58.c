/* 1000:5d58 */

/* WARNING: Instruction at (ram,0x00015d59) overlaps instruction at (ram,0x00015d58)
    */

undefined2 FUN_1000_5d58(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined1 uVar3;
  undefined2 in_AX;
  uint uVar4;
  byte bVar5;
  int in_CX;
  int iVar6;
  byte bVar7;
  uint in_BX;
  byte bVar8;
  int unaff_BP;
  uint unaff_SI;
  byte *pbVar9;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  do {
    *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + in_BX + (uint)in_CF;
    out(0xa5,0x99);
    uVar3 = in(0xa9);
    bVar8 = (byte)(in_BX >> 8);
    bVar7 = *(byte *)(CONCAT11(bVar8,uVar3) + unaff_SI);
    in_BX = CONCAT11(bVar8 + 0xb9,uVar3);
    bVar5 = ((byte)in_CX & 0x1f) % 0x11;
    uVar4 = *(uint *)(unaff_BP + (int)unaff_DI);
    *(uint *)(unaff_BP + (int)unaff_DI) =
         uVar4 << bVar5 | (uint)(CONCAT12(0x46 < bVar8,uVar4) >> 0x11 - bVar5);
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x3c3);
    *pbVar1 = *pbVar1 ^ (byte)in_CX;
    *(char *)(unaff_BP + (int)unaff_DI) = *(char *)(unaff_BP + (int)unaff_DI) << 6;
    in_CF = 0;
    uVar4 = (uint)(((ulong)~CONCAT11((byte)((uint)in_AX >> 8) | bVar7,0xb9) | 0x10000) >> 1) & in_BX
            | unaff_SI;
    in_AX = CONCAT11((char)uVar4,(char)(uVar4 >> 8));
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar2 = in_AX;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  pbVar9 = (byte *)0x3e20;
  bVar7 = 0;
  do {
    out(0xa8,bVar7);
    uVar4 = 0xae;
    iVar6 = 3;
    do {
      pbVar1 = pbVar9;
      pbVar9 = pbVar9 + 1;
      bVar5 = (byte)((uint)(byte)((*pbVar1 & 0xf) + 1) * (uint)*(byte *)0x34d6 >> 8);
      out(uVar4,bVar5);
      uVar4 = uVar4 - 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    bVar7 = bVar7 + 1;
  } while (bVar7 < 0x10);
  bVar7 = (byte)uVar4;
  *(char *)0xe432 = *(char *)0xe432 + bVar7 + CARRY1(bVar5,bVar7);
  bVar7 = ~(byte)((uint)(byte)(bVar5 + bVar7) / (uVar4 & 0xff));
  return CONCAT11(bVar7,bVar7);
}


