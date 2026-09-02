/* 1000:59b7 */

undefined4 FUN_1000_59b7(void)

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
  char in_BL;
  uint uVar13;
  undefined2 *puVar14;
  undefined2 *unaff_BP;
  int iVar15;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int *unaff_DS;
  int *in_stack_00009f7b;
  int in_stack_00009f7f;
  undefined2 uStack_6;
  char acStack_4 [4];
  
  while( true ) {
    pcVar5 = (char *)*(undefined2 *)0x3e94;
    uVar8 = *(uint *)(pcVar5 + 0x1a);
    pbVar3 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    bVar6 = (byte)uVar8;
    *pbVar3 = bVar6;
    acStack_4[0] = '_';
    acStack_4[1] = '\0';
    *(byte *)((int)unaff_BP + (int)pcVar5) = *(byte *)((int)unaff_BP + (int)pcVar5) & bVar6;
    puVar14 = &uStack_6;
    uStack_6 = unaff_BP;
    cVar11 = '\b';
    do {
      unaff_BP = unaff_BP + -1;
      puVar14 = puVar14 + -1;
      *puVar14 = *unaff_BP;
      cVar11 = cVar11 + -1;
    } while ('\0' < cVar11);
    *pcVar5 = *pcVar5 << 1;
    if (0xff6 < uVar8) break;
    *(byte *)((int)&uStack_6 + (int)unaff_DI) = *(byte *)((int)&uStack_6 + (int)unaff_DI) + in_BL;
    unaff_BP = &uStack_6;
    unaff_DS = in_stack_00009f7b;
  }
  iVar15 = in_stack_00009f7f + 1;
  iVar9 = 0x262;
  do {
    uVar8 = *(uint *)((int)in_stack_00009f7b + iVar15);
    if (((uVar8 & 0xfff) == 0) ||
       (uVar8 = *(uint *)((int)in_stack_00009f7b + iVar15 + 1), (uVar8 & 0xfff0) == 0)) {
      return CONCAT22(in_DX,uVar8);
    }
    in_stack_00009f7b = in_stack_00009f7b + 1;
    iVar15 = iVar15 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined2 *)(byte *)((int)in_stack_00009f7b + (int)unaff_DI) = in_DX;
  *(byte *)((int)in_stack_00009f7b + iVar15) =
       *(byte *)((int)in_stack_00009f7b + iVar15) ^ (byte)in_DX;
  uVar7 = CONCAT11((char)(uVar8 >> 8),(char)uVar8 + 'Q');
  uVar8 = 0xe500;
  if ((*unaff_DI != 0) && (*unaff_DI != 0xe5)) {
    cVar11 = (char)((uint)in_DX >> 8) + (char)in_stack_00009f7b;
    in_DX = CONCAT11(cVar11,(byte)in_DX);
    *(char *)((int)in_stack_00009f7b + iVar15) = *(char *)((int)in_stack_00009f7b + iVar15) - cVar11
    ;
    uVar8 = 0x6a;
  }
  LOCK();
  cVar11 = *(char *)((int)in_stack_00009f7b + iVar15);
  *(char *)((int)in_stack_00009f7b + iVar15) = (char)in_DX;
  uVar12 = (undefined1)((uint)in_DX >> 8);
  UNLOCK();
  *in_stack_00009f7b = *in_stack_00009f7b + -1;
  uVar13 = (uint)((int)in_stack_00009f7b * 3) >> 1;
  uVar10 = 0xf000;
  if (((int)in_stack_00009f7b * 3 & 1U) != 0) {
    uVar8 = uVar8 << 4;
    uVar10 = 0xf;
  }
  *(char *)((int)&uStack_6 + (int)in_stack_00009f7b) =
       *(char *)((int)&uStack_6 + (int)in_stack_00009f7b) + (char)uVar10;
  *(uint *)(uVar13 + (int)in_stack_00009f7b) = *(uint *)(uVar13 + (int)in_stack_00009f7b) & uVar10;
  puVar1 = (uint *)(uVar13 + (int)in_stack_00009f7b);
  *puVar1 = *puVar1 | uVar8;
  if (0 < (int)*puVar1) {
    cVar4 = *(char *)(uVar13 + 0x77);
    piVar2 = (int *)((int)in_stack_00009f7b + uVar13 + 0x1c4d);
    *piVar2 = *piVar2 - (int)in_stack_00009f7b;
    return CONCAT22(CONCAT11(uVar12,cVar11 + cVar4),uVar7);
  }
  return CONCAT22(CONCAT11(uVar12,cVar11),uVar7);
}


