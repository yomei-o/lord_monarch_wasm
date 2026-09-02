/* 1000:8194 */

/* WARNING: Instruction at (ram,0x000181c9) overlaps instruction at (ram,0x000181c6)
    */

undefined4 FUN_1000_8194(void)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  byte bVar4;
  bool bVar5;
  code *pcVar6;
  byte in_AL;
  char cVar7;
  byte bVar8;
  int in_CX;
  uint uVar9;
  undefined2 in_BX;
  uint uVar10;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  byte in_AF;
  undefined4 uVar12;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  byte bVar11;
  
  pcVar1 = (char *)(unaff_DI + 2);
  bVar4 = 9 < (in_AL & 9) | in_AF;
  uVar9 = in_CX - 1;
  bVar11 = (byte)((uint)in_BX >> 8) | *unaff_SI;
  uVar10 = CONCAT11(bVar11,(char)in_BX);
  if ((POPCOUNT(bVar11) & 1U) == 0) {
    unaff_SI[uVar10] = unaff_SI[uVar10] & (byte)uVar9;
    pcVar6 = (code *)swi(3);
    uVar12 = (*pcVar6)();
    return uVar12;
  }
  cVar7 = ((in_AL & 0x49) + bVar4 * -6 & 0xf) + 0x3c;
  if ((POPCOUNT(cVar7) & 1U) == 0) {
    bVar8 = *(byte *)0xa02;
    bVar4 = 9 < (bVar8 & 0xf) | bVar4;
    bVar5 = 0x99 < bVar8 || unaff_SI[uVar10 + 0x1a] < bVar8;
    bVar8 = bVar8 + bVar4 * '\x06' + bVar5 * '`';
    uVar2 = (uint)bVar5;
    pcVar3 = pcVar1 + uVar9;
    *(char **)(pcVar1 + uVar10 + 2) =
         pcVar3 + uVar2 +
         (uint)(CARRY2(uVar9,(uint)pcVar1) || CARRY2((uint)pcVar3,uVar2)) +
         *(int *)(pcVar1 + uVar10 + 2);
    uVar10 = CONCAT11(bVar11 + (char)(pcVar3 + uVar2),(char)in_BX);
    *(uint *)(pcVar1 + uVar10) = *(uint *)(pcVar1 + uVar10) | uVar10;
    unaff_SI[uVar10] = unaff_SI[uVar10] << 1;
    cVar7 = bVar8 + (9 < (bVar8 & 0xf) | bVar4) * '\x06' +
            (0x99 < bVar8 || *(uint *)0x3bd6 < 0x5d) * '`';
  }
  *pcVar1 = cVar7;
  *(char *)(unaff_DI + 3) = cVar7;
  func_0x0001d9c8(uVar10);
  FUN_1000_95c5();
  return CONCAT22(in_stack_0000000e,in_stack_00000012);
}


