/* 1000:4ebd */

/* WARNING: Instruction at (ram,0x00015002) overlaps instruction at (ram,0x00015000)
    */

undefined2 FUN_1000_4ebd(void)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  byte bVar7;
  char cVar8;
  undefined2 in_AX;
  undefined2 uVar9;
  undefined2 in_CX;
  int iVar10;
  char cVar11;
  uint in_DX;
  uint uVar12;
  uint extraout_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  uint uVar13;
  undefined2 *puVar14;
  long *unaff_DI;
  undefined2 *puVar15;
  undefined1 *puVar16;
  char *pcVar17;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar18;
  char cVar19;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  longdouble lVar20;
  undefined4 in_stack_0000000a;
  undefined3 uVar21;
  
  uVar12 = in_DX & *(uint *)(in_BX + unaff_SI);
  *(char *)(unaff_BP + unaff_SI) =
       *(char *)(unaff_BP + unaff_SI) + (byte)in_AX +
       CARRY1((byte)((uint)in_AX >> 8),*(byte *)(in_BX + unaff_SI + 0x23));
  bVar18 = false;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & (byte)in_AX;
  uVar13 = unaff_SI + 1;
  while( true ) {
    pbVar2 = (byte *)0x719;
    bVar3 = *pbVar2;
    bVar7 = *pbVar2 + (byte)in_CX;
    *pbVar2 = bVar7 + bVar18;
    if (CARRY1(bVar3,(byte)in_CX) || CARRY1(bVar7,bVar18)) break;
    unaff_BP = unaff_BP + 1;
    bVar18 = false;
    *unaff_DI = (long)in_ST0;
    lVar20 = in_ST7;
    cVar8 = FUN_1000_5609();
    if (!bVar18) {
      puVar14 = (undefined2 *)0x7ca0;
      puVar15 = (undefined2 *)0x3c20;
      for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
        puVar6 = puVar15;
        puVar15 = puVar15 + 1;
        puVar4 = puVar14;
        puVar14 = puVar14 + 1;
        *puVar6 = *puVar4;
      }
      puVar15 = (undefined2 *)0xc632;
      for (iVar10 = 0xb0; iVar10 != 0; iVar10 = iVar10 + -1) {
        puVar6 = puVar15;
        puVar15 = puVar15 + 1;
        puVar4 = puVar14;
        puVar14 = puVar14 + 1;
        *puVar6 = *puVar4;
      }
      puVar16 = (undefined1 *)0x3eea;
      for (iVar10 = 0x2d; iVar10 != 0; iVar10 = iVar10 + -1) {
        puVar5 = puVar16;
        puVar16 = puVar16 + 1;
        puVar4 = puVar14;
        puVar14 = (undefined2 *)((int)puVar14 + 1);
        *puVar5 = *(undefined1 *)puVar4;
      }
      return 0x4000;
    }
    uVar12 = extraout_DX;
    in_ST0 = in_ST1;
    if (cVar8 != -0xb) goto code_r0x00014f1b;
    uVar12 = extraout_DX & *(uint *)(in_BX + uVar13);
    in_BX = CONCAT11((char)((uint)in_BX >> 8) + *(char *)(unaff_BP + uVar13),(char)in_BX);
    bVar18 = CARRY1((byte)in_CX,*(byte *)(unaff_SI + 0x47));
    in_CX = CONCAT11((char)((uint)in_CX >> 8),(byte)in_CX + *(byte *)(unaff_SI + 0x47));
    in_ST1 = in_ST2;
    in_ST2 = in_ST3;
    in_ST3 = in_ST4;
    in_ST4 = in_ST5;
    in_ST5 = in_ST6;
    in_ST6 = in_ST7;
    in_ST7 = lVar20;
  }
  uVar13 = uVar13 | *(uint *)(unaff_SI + -0x58);
code_r0x00014f1b:
  pcVar17 = (char *)((int)unaff_DI + 2);
  uVar9 = in(uVar12);
  *(undefined2 *)unaff_DI = uVar9;
  bVar18 = (char)(uVar12 >> 8) == '\0' && *(char *)(unaff_BP + uVar13 + 5) == '\0';
  uVar9 = FUN_1000_59b2();
  if (bVar18) {
    while( true ) {
      *(byte *)(in_BX + uVar13) = *(byte *)(in_BX + uVar13) & (byte)in_CX;
      bVar18 = (byte)uVar9 == 6;
      if (5 < (byte)uVar9) {
        if (!bVar18) {
          return uVar9;
        }
        cVar19 = CARRY1((byte)in_CX,pcVar17[in_BX]);
        cVar11 = (char)((uint)in_CX >> 8);
        uVar21 = 0x5014;
        cVar8 = FUN_1000_567c();
        if ((bool)cVar19) goto LAB_1000_501b;
        uVar9 = FUN_1000_2fef(uVar21);
        pcVar1 = (char *)(unaff_BP + uVar13 + 0x12aa);
        *pcVar1 = *pcVar1 + cVar11 + cVar19;
        bVar18 = *pcVar1 == '\0';
      }
      unaff_ES = (undefined2)((ulong)*(undefined4 *)(pcVar17 + in_BX) >> 0x10);
      in_CX = (undefined2)*(undefined4 *)(pcVar17 + in_BX);
      if (!bVar18) break;
      *(uint *)((int)unaff_DI + 0xf) = *(uint *)((int)unaff_DI + 0xf) | uVar13;
    }
  }
  else {
    cVar8 = (char)uVar9 + -0x18;
    *(int *)(in_BX + uVar13) = (int)ROUND(in_ST0);
    pcVar1 = pcVar17;
    pcVar17 = (char *)((int)unaff_DI + 3);
    *pcVar1 = cVar8;
LAB_1000_501b:
    *pcVar17 = cVar8;
    *(uint *)(uVar13 - 0x1f) = *(uint *)(uVar13 - 0x1f) | uVar13;
  }
  return in_stack_0000000a._1_2_;
}


