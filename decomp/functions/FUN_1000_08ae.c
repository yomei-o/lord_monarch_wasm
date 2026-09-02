/* 1000:08ae */

/* WARNING: Instruction at (ram,0x0001094c) overlaps instruction at (ram,0x0001094b)
    */

undefined1 * FUN_1000_08ae(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  uint uVar7;
  int in_CX;
  byte extraout_DH;
  int unaff_BP;
  uint uVar8;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  uint uStack_6;
  
  if (iRam000032e2 != 0) {
    *unaff_DI = *unaff_SI;
    return &stack0x0000;
  }
  iRam000032e2 = 1;
  uStack_6 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
             0x40 | (uint)(in_AF & 1) * 0x10 | 4;
  iVar4 = FUN_1000_06bf();
  *(byte *)(unaff_BP + -0x72) = *(byte *)(unaff_BP + -0x72) & extraout_DH;
  do {
    iVar5 = iVar4;
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + -0x4dca);
    *pbVar1 = *pbVar1 + (char)in_CX;
    unaff_BP = 32000;
    uVar6 = 0xe7c3;
    pbVar2 = (byte *)*unaff_SI;
    if ((byte *)0x7cff < pbVar2) goto LAB_1000_0947;
    out(0xa6,0);
    *pbVar2 = *pbVar2 & 0xe7;
    pbVar2[0x50] = 0;
    pbVar2[0xa0] = 0;
    pbVar2[0xf0] = pbVar2[0xf0] & 0xe7;
    uVar7 = unaff_SI[1];
    unaff_DI = (uint *)(pbVar2 + unaff_SI[1]);
    *unaff_DI = 32000;
    *(byte *)((int)unaff_DI + -0x4b) =
         *(byte *)((int)unaff_DI + -0x4b) + 4 + CARRY2((uint)pbVar2,uVar7);
    uVar7 = *unaff_SI;
    *(byte *)unaff_DI = (byte)*unaff_DI | 0x18;
    *(byte *)(unaff_DI + 0x28) = (byte)unaff_DI[0x28] | 0x3c;
    *(byte *)(unaff_DI + 0x50) = (byte)unaff_DI[0x50] | 0x3c;
    *(byte *)((int)unaff_DI + 0x302d) = *(byte *)((int)unaff_DI + 0x302d) | 0x18;
    unaff_SI[0x1a9] = (int)&uStack_6 + unaff_SI[0x1a9];
    in_CX = in_CX + -1;
    iVar4 = (CONCAT11((char)uVar7 + -0x32,2) | 0x26) + 0x7316;
  } while (in_CX != 0);
  uVar6 = 0x33b;
  if ((uint *)*(undefined2 *)0x3bb6 <= unaff_SI) {
    unaff_SI = (uint *)0xce74;
  }
LAB_1000_0947:
  *(undefined2 *)0x6c4c = uVar6;
  uVar7 = FUN_1000_0984();
  uVar8 = 0x50;
  if (((uVar7 & 0x700) != 0) && (uVar8 = 0xa0, 1 < ((byte)(uVar7 >> 8) & 7))) {
    uVar8 = 0xf0;
  }
  unaff_SI[1] = uVar8;
  puVar3 = (undefined1 *)((uVar7 & 0xff) * 0xa0 >> 8);
  *unaff_SI = (uint)puVar3;
  return puVar3;
}


