/* 1000:4cdc */

undefined2 FUN_1000_4cdc(void)

{
  byte *pbVar1;
  ulong *puVar2;
  int *piVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  undefined2 in_AX;
  uint uVar7;
  undefined2 uVar8;
  byte in_CH;
  undefined2 in_DX;
  int iVar9;
  int extraout_DX;
  int in_BX;
  int unaff_BP;
  ulong in_ESI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  undefined1 in_CF;
  undefined8 in_MM1;
  undefined8 in_MM5;
  undefined4 uVar11;
  
  uVar11 = CONCAT22(in_DX,in_AX);
  while (iVar9 = (int)((ulong)uVar11 >> 0x10), (bool)in_CF) {
    uVar7 = (uint)in_ESI;
    pbVar1 = (byte *)(unaff_BP + uVar7 + -0x18);
    *pbVar1 = *pbVar1 | (byte)((ulong)uVar11 >> 0x10);
    bVar10 = uVar7 < *(uint *)(in_BX + uVar7);
    in_ESI = CONCAT22((int)(in_ESI >> 0x10),uVar7 - *(uint *)(in_BX + uVar7));
    bVar4 = (byte)uVar11;
    unaff_DI[-1] = bVar4;
    pbVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *pbVar1 = bVar4;
    bVar5 = bVar4 + in_CH + bVar10;
    in_CF = 0xef < bVar5 || CARRY1(bVar5 + 0x10,CARRY1(bVar4,in_CH) || CARRY1(bVar4 + in_CH,bVar10))
    ;
    uVar11 = FUN_1000_5641();
  }
  while( true ) {
    piVar3 = (int *)(in_BX + (int)in_ESI + 6);
    *piVar3 = *piVar3 - iVar9;
    cVar6 = FUN_1000_661b();
    in_MM1 = psubsb(in_MM1,*(undefined8 *)(unaff_DI + 10));
    if (0xfa < (byte)(cVar6 + 1U)) break;
    puVar2 = (ulong *)(unaff_BP + (int)in_ESI + -0x14);
    *puVar2 = *puVar2 | in_ESI;
    iVar9 = extraout_DX;
    unaff_DI = unaff_DI + 1;
  }
  uVar7 = *(int *)(unaff_BP + -2) + 0x800;
  if (0xb800 < uVar7) {
    uVar7 = *(int *)(unaff_BP + -2) + 0x2800;
  }
  *(uint *)(unaff_BP + -2) = uVar7;
  *(undefined1 *)((int)in_ESI + 8) = 0x45;
  FUN_1000_8b17();
  psubsb(in_MM5,*(undefined8 *)(in_BX + (int)in_ESI));
  uVar8 = in(0x61);
  return uVar8;
}


