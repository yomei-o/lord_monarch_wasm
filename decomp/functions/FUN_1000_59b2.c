/* 1000:59b2 */

/* WARNING: Instruction at (ram,0x000159b3) overlaps instruction at (ram,0x000159b2)
    */

undefined4 FUN_1000_59b2(void)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  char cVar4;
  char *pcVar5;
  byte bVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined2 in_DX;
  char cVar11;
  undefined1 uVar12;
  int *in_BX;
  uint uVar13;
  undefined2 *puVar14;
  undefined2 *unaff_BP;
  int iVar15;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int *unaff_DS;
  byte in_CF;
  int *in_stack_00009f79;
  int in_stack_00009f7d;
  undefined2 uStack_8;
  char acStack_6 [2];
  int *piStack_4;
  
  while( true ) {
    in_BX = (int *)((int)in_BX + (-(uint)in_CF - *in_BX));
    piStack_4 = in_BX;
    pcVar5 = (char *)*(undefined2 *)0x3e94;
    uVar8 = *(uint *)(pcVar5 + 0x1a);
    pbVar3 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    bVar6 = (byte)uVar8;
    *pbVar3 = bVar6;
    acStack_6[0] = '_';
    acStack_6[1] = '\0';
    *(byte *)((int)unaff_BP + (int)pcVar5) = *(byte *)((int)unaff_BP + (int)pcVar5) & bVar6;
    puVar14 = &uStack_8;
    uStack_8 = unaff_BP;
    cVar11 = '\b';
    do {
      unaff_BP = unaff_BP + -1;
      puVar14 = puVar14 + -1;
      *puVar14 = *unaff_BP;
      cVar11 = cVar11 + -1;
    } while ('\0' < cVar11);
    *pcVar5 = *pcVar5 << 1;
    if (0xff6 < uVar8) break;
    pbVar3 = (byte *)((int)&uStack_8 + (int)unaff_DI);
    in_CF = CARRY1(*pbVar3,(byte)in_BX);
    *pbVar3 = *pbVar3 + (byte)in_BX;
    unaff_BP = &uStack_8;
    unaff_DS = in_stack_00009f79;
  }
  iVar15 = in_stack_00009f7d + 1;
  iVar9 = 0x262;
  do {
    uVar8 = *(uint *)((int)in_stack_00009f79 + iVar15);
    if (((uVar8 & 0xfff) == 0) ||
       (uVar8 = *(uint *)((int)in_stack_00009f79 + iVar15 + 1), (uVar8 & 0xfff0) == 0)) {
      return CONCAT22(in_DX,uVar8);
    }
    in_stack_00009f79 = in_stack_00009f79 + 1;
    iVar15 = iVar15 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined2 *)(byte *)((int)in_stack_00009f79 + (int)unaff_DI) = in_DX;
  *(byte *)((int)in_stack_00009f79 + iVar15) =
       *(byte *)((int)in_stack_00009f79 + iVar15) ^ (byte)in_DX;
  uVar7 = CONCAT11((char)(uVar8 >> 8),(char)uVar8 + 'Q');
  uVar8 = 0xe500;
  if ((*unaff_DI != 0) && (*unaff_DI != 0xe5)) {
    cVar11 = (char)((uint)in_DX >> 8) + (char)in_stack_00009f79;
    in_DX = CONCAT11(cVar11,(byte)in_DX);
    *(char *)((int)in_stack_00009f79 + iVar15) = *(char *)((int)in_stack_00009f79 + iVar15) - cVar11
    ;
    uVar8 = 0x6a;
  }
  LOCK();
  cVar11 = *(char *)((int)in_stack_00009f79 + iVar15);
  *(char *)((int)in_stack_00009f79 + iVar15) = (char)in_DX;
  uVar12 = (undefined1)((uint)in_DX >> 8);
  UNLOCK();
  *in_stack_00009f79 = *in_stack_00009f79 + -1;
  uVar13 = (uint)((int)in_stack_00009f79 * 3) >> 1;
  uVar10 = 0xf000;
  if (((int)in_stack_00009f79 * 3 & 1U) != 0) {
    uVar8 = uVar8 << 4;
    uVar10 = 0xf;
  }
  *(char *)((int)&uStack_8 + (int)in_stack_00009f79) =
       *(char *)((int)&uStack_8 + (int)in_stack_00009f79) + (char)uVar10;
  *(uint *)(uVar13 + (int)in_stack_00009f79) = *(uint *)(uVar13 + (int)in_stack_00009f79) & uVar10;
  puVar1 = (uint *)(uVar13 + (int)in_stack_00009f79);
  *puVar1 = *puVar1 | uVar8;
  if (0 < (int)*puVar1) {
    cVar4 = *(char *)(uVar13 + 0x77);
    piVar2 = (int *)((int)in_stack_00009f79 + uVar13 + 0x1c4d);
    *piVar2 = *piVar2 - (int)in_stack_00009f79;
    return CONCAT22(CONCAT11(uVar12,cVar11 + cVar4),uVar7);
  }
  return CONCAT22(CONCAT11(uVar12,cVar11),uVar7);
}


