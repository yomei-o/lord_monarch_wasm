/* 1000:a1b8 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_a1b8(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  char extraout_AH;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined2 in_CX;
  char cVar11;
  byte extraout_DL;
  int extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  byte *pbVar12;
  int unaff_BP;
  int iVar13;
  undefined2 *puVar14;
  int unaff_DI;
  undefined2 *puVar15;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar16;
  char cVar17;
  char cVar18;
  undefined2 uVar19;
  undefined1 *puVar20;
  
  iVar13 = unaff_BP + -1;
  *(byte *)0xb815 = *(byte *)0xb815 & (byte)in_CX;
  FUN_1000_5bdb(0xaa25);
  puVar20 = &stack0x0002;
  func_0x0001eee3();
  uVar19 = 0xaa25;
  bVar7 = *(byte *)0xaa25;
  *(int *)(in_BX + -0x55cd) =
       (*(int *)(in_BX + -0x55cd) - extraout_DX) - (uint)CARRY1((byte)in_CX,*(byte *)0xaa25);
  pbVar12 = (byte *)CONCAT11(0xe8,(char)in_BX);
  pbVar1 = pbVar12 + unaff_DI + 1000;
  *(int *)pbVar1 = *(int *)pbVar1 + 1;
  if (CONCAT11((char)((uint)in_CX >> 8),(byte)in_CX + bVar7) != 1 && *(int *)pbVar1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(char *)0xb908 = *(char *)0xb908 + (char)in_BX;
  iVar8 = extraout_DX;
  func_0x000188bb();
  cVar18 = '\0';
  cVar17 = '\0';
  uVar16 = 1;
  cVar11 = extraout_AH;
  FUN_1000_59b2();
  func_0x00015bb8(uVar19,iVar13,puVar20,in_BX,iVar8,in_CX);
  bVar7 = FUN_1000_33bf();
  if ((bool)uVar16 || cVar18 != cVar17) {
    pbVar1 = pbVar12 + 0x3255;
    bVar2 = *pbVar1;
    bVar5 = *pbVar1 + bVar7 * -2;
    *pbVar1 = bVar5 - CARRY1(bVar7,bVar7);
    *(char *)(unaff_BP + 0x24fe) =
         *(char *)(unaff_BP + 0x24fe) + cVar11 +
         (bVar2 < (byte)(bVar7 * '\x02') || bVar5 < CARRY1(bVar7,bVar7));
    pbVar12[0x2055] = pbVar12[0x2055] ^ 0xb7;
    iVar8 = func_0x0001daad();
    pbVar12[-0x4149] = pbVar12[-0x4149] | extraout_DL;
    iVar8 = iVar8 + 2;
    pbVar12[0x2055] = pbVar12[0x2055] + extraout_DL;
    (pbVar12 + -0x7318)[0] = 0x55;
    (pbVar12 + -0x7318)[1] = 0x20;
    *pbVar12 = *pbVar12 ^ (byte)pbVar12;
    iVar13 = *(int *)(pbVar12 + -0x3118);
    in(0xe8);
    FUN_1000_35c6();
    pbVar1 = (byte *)(in_BX + iVar13);
    bVar7 = *pbVar1;
    *pbVar1 = *pbVar1 + (byte)pbVar12;
    return CONCAT22(CONCAT11((char)((uint)extraout_DX_00 >> 8),
                             (char)extraout_DX_00 + pbVar12[iVar13 + 0x73e8] +
                             CARRY1(bVar7,(byte)pbVar12)),iVar8);
  }
  puVar14 = (undefined2 *)0x0;
  uVar6 = 0xa800;
  do {
    uVar9 = uVar6;
    puVar15 = (undefined2 *)0x0;
    for (iVar13 = 4000; iVar13 != 0; iVar13 = iVar13 + -1) {
      puVar4 = puVar15;
      puVar15 = puVar15 + 1;
      puVar3 = puVar14;
      puVar14 = puVar14 + 1;
      *puVar4 = *puVar3;
    }
    uVar10 = uVar9 + 0x800;
    uVar6 = uVar10;
  } while ((uVar10 < 0xc000) || (uVar6 = uVar9 + 0x2800, uVar10 < 0xe000));
  FUN_1000_1fdf();
  bVar7 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar7 ^ 1;
  out(0xa6,bVar7 ^ 1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


