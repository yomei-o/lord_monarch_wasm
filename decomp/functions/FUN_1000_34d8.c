/* 1000:34d8 */

void FUN_1000_34d8(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  unkbyte10 Var5;
  byte *pbVar6;
  undefined1 uVar7;
  byte bVar8;
  code *pcVar9;
  byte bVar10;
  uint uVar11;
  undefined2 in_AX;
  uint uVar12;
  byte in_CL;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined1 *unaff_DI;
  uint unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  unkbyte10 in_ST0;
  byte bVar4;
  
  uVar12 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + '3' + in_CF);
  pbVar1 = (byte *)(unaff_BP + unaff_SI + 0x7f97);
  *pbVar1 = *pbVar1 >> (in_CL & 7) | *pbVar1 << 8 - (in_CL & 7);
  pbVar1 = unaff_DI + in_BX + -0x3e;
  *pbVar1 = *pbVar1 << (in_CL & 7) | *pbVar1 >> 8 - (in_CL & 7);
  pcVar2 = (char *)(in_BX + unaff_SI + 0x20);
  *pcVar2 = *pcVar2 + (char)(in_DX >> 8);
  *(uint *)(unaff_BP + unaff_SI) = *(uint *)(unaff_BP + unaff_SI) ^ in_DX;
  if (in_DX < uVar12) {
    uVar12 = in_DX;
  }
  *(uint *)(unaff_BP + unaff_SI) = ~*(uint *)(unaff_BP + unaff_SI);
  pbVar6 = (byte *)(unaff_SI + 2);
  uVar7 = in(0);
  *unaff_DI = uVar7;
  pbVar6[in_BX] = pbVar6[in_BX];
  *(char *)(uVar12 + 6) = *(char *)(uVar12 + 6) << 1;
  *(undefined1 *)(in_BX + -0x2d81) = 0;
  *pbVar6 = *pbVar6 + (byte)unaff_ES;
  *pbVar6 = *pbVar6 & (byte)unaff_ES;
  *(uint *)(unaff_DI + in_BX + 1) = *(uint *)(unaff_DI + in_BX + 1) | unaff_ES;
  Var5 = to_bcd(in_ST0);
  *(unkbyte10 *)(pbVar6 + in_BX) = Var5;
  pbVar6[uVar12] = pbVar6[uVar12] ^ (byte)(unaff_ES >> 8);
  bVar10 = (byte)(unaff_ES / (byte)unaff_DI[4]);
  uVar11 = CONCAT11((char)(unaff_ES % (uint)(byte)unaff_DI[4]),bVar10);
  bVar8 = *pbVar6;
  pbVar1 = pbVar6 + uVar12;
  bVar3 = *pbVar1;
  bVar4 = *pbVar1;
  *pbVar1 = bVar4 + bVar10 + CARRY1(in_CL,bVar8);
  pbVar6[uVar12] =
       pbVar6[uVar12] + (char)unaff_SS +
       (uVar11 < *(uint *)(pbVar6 + uVar12) ||
       uVar11 - *(uint *)(pbVar6 + uVar12) <
       (uint)(CARRY1(bVar3,bVar10) || CARRY1(bVar4 + bVar10,CARRY1(in_CL,bVar8))));
  pcVar9 = (code *)swi(3);
  (*pcVar9)(&stack0xfffe);
  return;
}


