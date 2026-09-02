/* 1000:812c */

/* WARNING: Instruction at (ram,0x000181c9) overlaps instruction at (ram,0x000181c6)
    */

undefined4 FUN_1000_812c(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  bool bVar5;
  code *pcVar6;
  char cVar7;
  byte bVar8;
  int in_AX;
  int in_CX;
  uint uVar9;
  undefined2 extraout_DX;
  int in_BX;
  uint uVar10;
  int unaff_BP;
  byte *unaff_SI;
  uint unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte bVar12;
  byte in_AF;
  undefined1 in_ZF;
  undefined4 uVar13;
  int in_stack_0000000e;
  undefined2 in_stack_00000012;
  byte bVar11;
  
  if (in_CX != 0) {
    FUN_1000_9611();
    *(uint *)(unaff_SI + in_BX) = *(uint *)(unaff_SI + in_BX) ^ unaff_DI;
    bVar12 = *(uint *)0x3bc2 < 0x33;
    if (*(uint *)0x3bc2 == 0x33) {
      *(undefined2 *)0xce70 = 0x33;
      FUN_1000_8360();
      in_AX = FUN_1000_9749();
      *unaff_SI = *unaff_SI & (byte)((uint)in_BX >> 8);
      in_stack_0000000e = in_AX;
      goto code_r0x0001818c;
    }
    FUN_1000_828e();
    in_AX = *(int *)0x3bc2 + 1;
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 2;
    out(*(undefined2 *)pbVar1,extraout_DX);
    pbVar1 = unaff_SI + unaff_BP;
    bVar8 = (byte)((uint)in_BX >> 8);
    bVar11 = *pbVar1 + bVar8;
    in_CF = CARRY1(*pbVar1,bVar8) || CARRY1(bVar11,bVar12);
    *pbVar1 = bVar11 + bVar12;
    in_ZF = *pbVar1 == 0;
  }
  if (((bool)in_ZF) && (in_AX = FUN_1000_3013(), !(bool)in_CF)) {
    FUN_1000_92f2();
    in_AX = func_0x0001d1b6();
  }
  unaff_SI[in_BX] = unaff_SI[in_BX] + (char)((uint)in_AX >> 8) + in_CF;
code_r0x0001818c:
  pcVar2 = (char *)(unaff_DI + 2);
  bVar12 = 9 < ((byte)in_AX & 9) | in_AF;
  uVar9 = in_CX - 1;
  bVar11 = (byte)((uint)in_BX >> 8) | *unaff_SI;
  uVar10 = CONCAT11(bVar11,(char)in_BX);
  if ((POPCOUNT(bVar11) & 1U) == 0) {
    unaff_SI[uVar10] = unaff_SI[uVar10] & (byte)uVar9;
    pcVar6 = (code *)swi(3);
    uVar13 = (*pcVar6)();
    return uVar13;
  }
  cVar7 = (((byte)in_AX & 0x49) + bVar12 * -6 & 0xf) + 0x3c;
  if ((POPCOUNT(cVar7) & 1U) == 0) {
    bVar8 = *(byte *)0xa02;
    bVar12 = 9 < (bVar8 & 0xf) | bVar12;
    bVar5 = 0x99 < bVar8 || unaff_SI[uVar10 + 0x1a] < bVar8;
    bVar8 = bVar8 + bVar12 * '\x06' + bVar5 * '`';
    uVar3 = (uint)bVar5;
    pcVar4 = pcVar2 + uVar9;
    *(char **)(pcVar2 + uVar10 + 2) =
         pcVar4 + uVar3 +
         (uint)(CARRY2(uVar9,(uint)pcVar2) || CARRY2((uint)pcVar4,uVar3)) +
         *(int *)(pcVar2 + uVar10 + 2);
    uVar10 = CONCAT11(bVar11 + (char)(pcVar4 + uVar3),(char)in_BX);
    *(uint *)(pcVar2 + uVar10) = *(uint *)(pcVar2 + uVar10) | uVar10;
    unaff_SI[uVar10] = unaff_SI[uVar10] << 1;
    cVar7 = bVar8 + (9 < (bVar8 & 0xf) | bVar12) * '\x06' +
            (0x99 < bVar8 || *(uint *)0x3bd6 < 0x5d) * '`';
  }
  *pcVar2 = cVar7;
  *(char *)(unaff_DI + 3) = cVar7;
  func_0x0001d9c8(uVar10);
  FUN_1000_95c5();
  return CONCAT22(in_stack_0000000e,in_stack_00000012);
}


