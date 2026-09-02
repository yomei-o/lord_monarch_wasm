/* 1000:3511 */

/* WARNING: Instruction at (ram,0x0001354f) overlaps instruction at (ram,0x0001354d)
    */

void FUN_1000_3511(void)

{
  byte *pbVar1;
  unkbyte10 Var2;
  undefined1 *puVar3;
  undefined1 uVar4;
  byte bVar5;
  code *pcVar6;
  byte bVar7;
  byte bVar8;
  uint in_AX;
  byte bVar10;
  byte in_CL;
  uint in_DX;
  int in_BX;
  uint unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  bool in_ZF;
  char in_SF;
  char in_OF;
  longdouble in_ST0;
  undefined4 uVar11;
  uint uVar9;
  
  if (in_ZF || in_OF != in_SF) {
    *(uint *)(unaff_SI + unaff_BP) = *(uint *)(unaff_SI + unaff_BP) ^ in_DX;
    if (in_DX < in_AX) {
      in_AX = in_DX;
    }
    *(uint *)(unaff_SI + unaff_BP) = ~*(uint *)(unaff_SI + unaff_BP);
    unaff_SI = unaff_SI + 2;
    puVar3 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    uVar4 = in(0);
    *puVar3 = uVar4;
    unaff_SI[in_BX] = unaff_SI[in_BX];
    *(char *)(in_AX + 6) = *(char *)(in_AX + 6) << 1;
    *(undefined1 *)(in_BX + -0x2d81) = 0;
    uVar9 = (uint)*(byte *)(in_BX + -0x21);
    pbVar1 = unaff_SI;
    in_CF = CARRY1(*pbVar1,(byte)unaff_ES);
    *pbVar1 = *pbVar1 + (byte)unaff_ES;
  }
  else {
    uVar11 = func_0x0001b229();
    uVar9 = (uint)((ulong)uVar11 >> 0x10);
    unaff_ES = (undefined2)uVar11;
    in_AX = unaff_BP;
  }
  bVar10 = (byte)((uint)unaff_ES >> 8);
  *(uint *)(unaff_DI + 0x55) =
       *(uint *)(unaff_DI + 0x55) | (uVar9 - *(int *)(unaff_SI + in_BX)) - (uint)in_CF;
  *(int *)(unaff_SI + in_BX) = (int)ROUND(in_ST0);
  bVar8 = (char)unaff_ES + 0x5b;
  uVar9 = CONCAT11(bVar10,bVar8);
  *unaff_SI = *unaff_SI & bVar8;
  *(uint *)(unaff_DI + in_BX) = *(uint *)(unaff_DI + in_BX) | uVar9;
  Var2 = to_bcd(in_ST0);
  *(unkbyte10 *)(unaff_SI + in_BX) = Var2;
  unaff_SI[in_AX] = unaff_SI[in_AX] ^ bVar10;
  bVar7 = (byte)(uVar9 / (byte)unaff_DI[3]);
  uVar9 = CONCAT11((char)(uVar9 % (uint)(byte)unaff_DI[3]),bVar7);
  bVar5 = *unaff_SI;
  pbVar1 = unaff_SI + in_AX;
  bVar8 = *pbVar1;
  bVar10 = *pbVar1;
  *pbVar1 = bVar10 + bVar7 + CARRY1(in_CL,bVar5);
  unaff_SI[in_AX] =
       unaff_SI[in_AX] + (char)unaff_SS +
       (uVar9 < *(uint *)(unaff_SI + in_AX) ||
       uVar9 - *(uint *)(unaff_SI + in_AX) <
       (uint)(CARRY1(bVar8,bVar7) || CARRY1(bVar10 + bVar7,CARRY1(in_CL,bVar5))));
  pcVar6 = (code *)swi(3);
  (*pcVar6)(&stack0xfffe);
  return;
}


