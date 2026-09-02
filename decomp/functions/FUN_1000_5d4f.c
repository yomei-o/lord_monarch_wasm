/* 1000:5d4f */

/* WARNING: Instruction at (ram,0x00015d59) overlaps instruction at (ram,0x00015d58)
    */

undefined2 FUN_1000_5d4f(void)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined2 in_AX;
  uint uVar3;
  byte bVar4;
  int in_CX;
  int iVar5;
  byte bVar6;
  uint in_BX;
  byte bVar7;
  int unaff_BP;
  uint unaff_SI;
  byte *pbVar8;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  do {
    out(0xa1,(byte)in_AX);
    out(0xa3,(char)((uint)in_AX >> 8));
    *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + in_BX + (uint)in_CF;
    out(0xa5,0x99);
    uVar2 = in(0xa9);
    bVar7 = (byte)(in_BX >> 8);
    bVar6 = *(byte *)(CONCAT11(bVar7,uVar2) + unaff_SI);
    in_BX = CONCAT11(bVar7 + 0xb9,uVar2);
    bVar4 = ((byte)in_CX & 0x1f) % 0x11;
    uVar3 = *(uint *)(unaff_BP + 0x3e50);
    *(uint *)(unaff_BP + 0x3e50) =
         uVar3 << bVar4 | (uint)(CONCAT12(0x46 < bVar7,uVar3) >> 0x11 - bVar4);
    *(byte *)(unaff_BP + 0x4213) = *(byte *)(unaff_BP + 0x4213) ^ (byte)in_CX;
    *(char *)(unaff_BP + 0x3e50) = *(char *)(unaff_BP + 0x3e50) << 6;
    in_CF = 0;
    uVar3 = (uint)(((ulong)~CONCAT11((byte)in_AX | bVar6,0xb9) | 0x10000) >> 1) & in_BX | unaff_SI;
    in_AX = CONCAT11((char)uVar3,(char)(uVar3 >> 8));
    *(undefined2 *)0x3e50 = in_AX;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  pbVar8 = (byte *)0x3e20;
  bVar6 = 0;
  do {
    out(0xa8,bVar6);
    uVar3 = 0xae;
    iVar5 = 3;
    do {
      pbVar1 = pbVar8;
      pbVar8 = pbVar8 + 1;
      bVar4 = (byte)((uint)(byte)((*pbVar1 & 0xf) + 1) * (uint)*(byte *)0x34d6 >> 8);
      out(uVar3,bVar4);
      uVar3 = uVar3 - 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 0x10);
  bVar6 = (byte)uVar3;
  *(char *)0xe432 = *(char *)0xe432 + bVar6 + CARRY1(bVar4,bVar6);
  bVar6 = ~(byte)((uint)(byte)(bVar4 + bVar6) / (uVar3 & 0xff));
  return CONCAT11(bVar6,bVar6);
}


