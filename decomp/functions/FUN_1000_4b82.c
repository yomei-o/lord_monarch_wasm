/* 1000:4b82 */

/* WARNING: Instruction at (ram,0x00014cda) overlaps instruction at (ram,0x00014cd9)
    */
/* WARNING: Removing unreachable block (ram,0x00014c91) */

undefined4 FUN_1000_4b82(void)

{
  uint *puVar1;
  ulong *puVar2;
  byte *pbVar3;
  char *pcVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int in_CX;
  uint uVar10;
  byte bVar11;
  int iVar12;
  uint extraout_DX;
  int extraout_DX_00;
  undefined2 extraout_DX_01;
  uint *in_BX;
  byte bVar13;
  int unaff_BP;
  char *pcVar14;
  char *pcVar15;
  undefined4 in_ESI;
  char *pcVar16;
  char *unaff_DI;
  byte *pbVar17;
  int unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  byte bVar18;
  bool bVar19;
  undefined1 uVar20;
  bool bVar21;
  longdouble in_ST0;
  undefined8 uVar22;
  unkbyte10 in_ST1;
  unkbyte10 in_ST2;
  unkbyte10 in_ST5;
  unkbyte10 in_ST6;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined2 uVar25;
  uint *puVar26;
  int in_stack_0000fffc;
  
  pbVar3 = (byte *)((char *)((int)in_BX + (int)unaff_DI) + 0x1a40);
  bVar18 = CARRY1(*pbVar3,(byte)in_BX);
  *pbVar3 = *pbVar3 + (byte)in_BX;
  bVar21 = (POPCOUNT(*pbVar3) & 1U) == 0;
  *(undefined1 *)0x3382 = 0x42;
  pcVar16 = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),(char *)0x337a);
  uVar23 = FUN_1000_5677();
  if (bVar21) {
LAB_1000_4bf5:
    iVar7 = (int)((ulong)uVar23 >> 0x10);
    iVar12 = (iVar7 - *(int *)((int)in_BX + (int)(char *)pcVar16)) - (uint)bVar18;
    pbVar3 = (byte *)((char *)pcVar16 + 0x75);
    bVar18 = (byte)iVar12;
    uVar10 = CONCAT11((char)((uint)iVar12 >> 8),bVar18 + *pbVar3);
    if (!SCARRY1(bVar18,*pbVar3)) {
      iVar12 = (int)uVar23 + unaff_BP + (uint)CARRY1(bVar18,*pbVar3);
      goto code_r0x00014c00;
    }
  }
  else {
    bVar18 = *(byte *)(unaff_BP + -0x17ef);
    cVar6 = (char)uVar23;
    pcVar14 = (char *)pcVar16;
    bVar13 = (byte)((uint)in_BX >> 8) | pcVar14[unaff_BP + 0x10];
    unaff_DI[unaff_BP] = unaff_DI[unaff_BP] ^ 0x52;
    iVar12 = *(int *)(pcVar14 + CONCAT11(bVar13,(char)in_BX));
    *unaff_DI = cVar6;
    pcVar15 = unaff_DI + 2;
    unaff_DI[1] = cVar6;
    iVar7 = CONCAT11((byte)((ulong)uVar23 >> 8) | bVar18,cVar6 + -0x37);
    bVar18 = pcVar14[unaff_BP + 0x60];
    bVar9 = (byte)in_CX | pcVar15[unaff_BP + -0x17ef];
    in_CX = CONCAT11((char)((uint)in_CX >> 8),bVar9);
    *(sqword *)(pcVar14 + unaff_BP) = (sqword)in_ST0;
    if ((POPCOUNT(bVar9) & 1U) == 0) {
      puVar26 = (uint *)((uint)in_BX & 0xff);
code_r0x00014bc5:
      pcVar15[unaff_BP] = pcVar15[unaff_BP] ^ 0x45;
      pcVar4 = (char *)pcVar16;
      *pcVar4 = *pcVar4 + (char)iVar7;
      in_BX = (uint *)CONCAT11((byte)((uint)iVar7 >> 8) | ((char *)pcVar16)[unaff_BP + 0x60],
                               (char)iVar7);
      iVar7 = (int)puVar26 + unaff_BP;
      pcVar15 = pcVar15 + 2;
      pcVar16 = (char *)((ulong)pcVar16 & 0xffff0000);
      in_ST1 = in_ST2;
      in_ST5 = in_ST6;
      in_stack_0000fffc = in_CX;
    }
    else {
      pcVar15[unaff_BP] = pcVar15[unaff_BP] ^ 0x47;
      *pcVar14 = *pcVar14 + cVar6 + -0x37;
      pcVar15 = unaff_DI + 3;
      puVar26 = (uint *)CONCAT11(bVar13 | bVar18 | pcVar14[unaff_BP + 0x60],(char)in_BX);
      bVar21 = (POPCOUNT((byte)((uint)((int)((ulong)uVar23 >> 0x10) - iVar12) >> 8) |
                         ((char *)((int)puVar26 + (int)pcVar14))[0x11]) & 1U) == 0;
      iVar7 = FUN_1000_5685();
      in_BX = puVar26;
      in_ST1 = in_ST2;
      in_ST5 = in_ST6;
      in_stack_0000fffc = 0x4bc3;
      if (!bVar21) goto code_r0x00014bc5;
    }
    in_CX = in_CX + 1;
    *pcVar15 = (char)iVar7;
    unaff_DI = pcVar15 + 2;
    pcVar15[1] = (char)iVar7;
    pcVar4 = unaff_DI + unaff_BP;
    cVar6 = (char)((uint)in_BX >> 8);
    bVar21 = SBORROW1(*pcVar4,cVar6);
    *pcVar4 = *pcVar4 - cVar6;
    *(undefined1 *)0x33a6 = 0x42;
    pcVar16 = (char *)CONCAT22((int)((ulong)pcVar16 >> 0x10),(char *)0x339e);
    uVar25 = 0x4bea;
    uVar23 = func_0x0001c159();
    uVar10 = (uint)((ulong)uVar23 >> 0x10);
    iVar12 = (int)uVar23;
    if (!bVar21) {
      *(uint *)((int)in_BX + (int)unaff_DI) = *(uint *)((int)in_BX + (int)unaff_DI) ^ uVar10;
      uVar23 = func_0x0001c174();
      bVar18 = 0;
      *(byte *)0x33a6 = *(byte *)0x33a6 & (byte)uVar23;
      goto LAB_1000_4bf5;
    }
    pcVar15 = (char *)pcVar16;
    uVar10 = uVar10 ^ *(uint *)(pcVar15 + unaff_BP + 0x1b);
    pcVar4 = pcVar15 + unaff_BP;
    *pcVar4 = *pcVar4 + (char)uVar23;
    if (*pcVar4 != '\0') {
      pcVar15[unaff_BP + 0x2aa] = pcVar15[unaff_BP + 0x2aa] & (byte)((uint)in_CX >> 8);
      puVar1 = (uint *)((int)in_BX + (int)pcVar15);
      iVar12 = (uVar10 + 1 & 3) - (*puVar1 & 3);
      *puVar1 = *puVar1 + (uint)(0 < iVar12) * iVar12;
      pcVar15[unaff_BP + 0x720a] = pcVar15[unaff_BP + 0x720a] | (byte)(uVar10 + 1 >> 8);
      bVar21 = true;
      FUN_1000_5644();
      iVar12 = unaff_ES;
      in_stack_0000fffc = unaff_DS;
      if (!bVar21) {
        FUN_1000_85e0(uVar25);
      }
      goto LAB_1000_4c8c;
    }
    *(byte *)0xe811 = *(byte *)0xe811 | (byte)uVar10;
    iVar7 = unaff_ES;
code_r0x00014c00:
    uVar23 = CONCAT22(iVar7,iVar12);
    in_stack_0000fffc = 0x2075;
    unaff_DI = unaff_DI + 1;
    pcVar16 = (char *)CONCAT22((int)((ulong)pcVar16 >> 0x10),(char *)pcVar16 + 1);
  }
  uVar8 = (uint)uVar23 ^ in_BX[0x1b];
  pcVar15 = (char *)pcVar16;
  cVar6 = (char)uVar8;
  pcVar15[unaff_BP] = pcVar15[unaff_BP] + cVar6;
  cVar6 = cVar6 + (char)((uint)in_CX >> 8) + (*(char **)(unaff_DI + 0x70) < pcVar15);
  bVar21 = false;
  bVar18 = (byte)(uVar10 >> 8) | pcVar15[unaff_BP + -0x58];
  uVar24 = CONCAT22(CONCAT11(bVar18,(char)uVar10),CONCAT11((char)(uVar8 >> 8),cVar6));
  *unaff_DI = cVar6;
  uVar10 = in_CX - 1;
  if (uVar10 == 0 || bVar18 != 0) {
    *(undefined1 *)0x33b2 = 0x42;
    pcVar16 = (char *)CONCAT22((int)((ulong)pcVar16 >> 0x10),(char *)0x33aa);
    uVar24 = FUN_1000_563c();
    if (bVar21) {
      puVar26 = (uint *)0x4ca3;
      uVar25 = FUN_1000_5644();
      bVar18 = (byte)(uVar10 >> 8);
      iVar12 = (int)((ulong)uVar23 >> 0x10);
      if (bVar21) {
LAB_1000_4c8c:
        return CONCAT22(in_stack_0000fffc,iVar12);
      }
      goto code_r0x00014ca5;
    }
  }
  uVar25 = in((int)((ulong)uVar24 >> 0x10));
  *(undefined2 *)(unaff_DI + 1) = uVar25;
  *(uint *)0xe880 = *(uint *)0xe880 & (uint)in_BX;
  cVar6 = *(char *)(ulong)((int)in_BX + ((uint)uVar24 & 0xff));
  bVar18 = (byte)(uVar10 >> 8);
  pcVar15 = (char *)pcVar16;
  puVar1 = (uint *)(pcVar15 + unaff_BP + -1);
  uVar8 = *puVar1;
  *puVar1 = *puVar1 - uVar10;
  if (uVar10 <= uVar8) {
    FUN_1000_85f2();
    pcVar15 = (char *)pcVar16;
    *(uint *)((int)in_BX + (int)pcVar15) = *(uint *)((int)in_BX + (int)pcVar15) & extraout_DX;
    *(char *)((int)in_BX + (int)pcVar15) =
         *(char *)((int)in_BX + (int)pcVar15) + (char)uVar10 +
         CARRY1((byte)extraout_DX,pcVar15[unaff_BP + 0x20]);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar25 = CONCAT11((char)((ulong)uVar24 >> 8),cVar6 + bVar18 * '\x02' + '\x01');
  pcVar14 = pcVar15 + 2;
  pcVar16 = (char *)CONCAT22((int)((ulong)pcVar16 >> 0x10),pcVar14);
  *(undefined2 *)(unaff_DI + 3) = *(undefined2 *)pcVar15;
  *(uint *)(pcVar14 + unaff_BP + -0x1a) = *(uint *)(pcVar14 + unaff_BP + -0x1a) | (uint)pcVar14;
  puVar26 = in_BX;
code_r0x00014ca5:
  *(char *)in_BX = (char)((uint)in_BX >> 8);
  ((char *)pcVar16)[unaff_BP + -1] = ((char *)pcVar16)[unaff_BP + -1] | (byte)uVar25;
  *(undefined2 *)(unaff_BP + -3) = uVar25;
  iVar12 = (uint)bVar18 << 8;
  bVar21 = false;
  do {
    do {
      bVar19 = bVar21;
      ((char *)pcVar16)[8] = 'B';
      FUN_1000_5622(puVar26);
      bVar21 = true;
    } while (bVar19);
    uVar20 = 0;
    pbVar17 = (byte *)0x0;
    FUN_1000_5cef();
    puVar26 = (uint *)0x4cc5;
    uVar23 = FUN_1000_5644();
    bVar21 = true;
  } while ((bool)uVar20);
  *in_BX = (uint)in_BX;
  do {
    pcVar15 = (char *)pcVar16;
    pcVar15[unaff_BP + -0x19] = pcVar15[unaff_BP + -0x19] | (byte)((ulong)uVar23 >> 0x10);
    bVar21 = pcVar15 < (char *)*(int *)((int)in_BX + (int)pcVar15);
    pcVar16 = (char *)CONCAT22((int)((ulong)pcVar16 >> 0x10),
                               pcVar15 + -*(int *)((int)in_BX + (int)pcVar15));
    bVar9 = (byte)uVar23;
    pbVar17[-1] = bVar9;
    pbVar3 = pbVar17;
    pbVar17 = pbVar17 + 1;
    *pbVar3 = bVar9;
    bVar11 = (byte)((uint)iVar12 >> 8);
    bVar18 = bVar9 + bVar11;
    bVar13 = bVar18 + bVar21;
    bVar21 = 0xef < bVar13 || CARRY1(bVar13 + 0x10,CARRY1(bVar9,bVar11) || CARRY1(bVar18,bVar21));
    uVar23 = FUN_1000_5641();
    iVar7 = (int)((ulong)uVar23 >> 0x10);
  } while (bVar21);
  while( true ) {
    piVar5 = (int *)((char *)((int)in_BX + (int)(char *)pcVar16) + 6);
    *piVar5 = *piVar5 - iVar7;
    cVar6 = FUN_1000_661b();
    uVar22 = psubsb((sqword)in_ST1,*(undefined8 *)(pbVar17 + 10));
    in_ST1 = CONCAT28((int)((unkuint10)in_ST1 >> 0x40),uVar22);
    if (0xfa < (byte)(cVar6 + 1U)) break;
    puVar2 = (ulong *)((char *)pcVar16 + unaff_BP + -0x15);
    *puVar2 = *puVar2 | (ulong)pcVar16;
    iVar7 = extraout_DX_00;
    pbVar17 = pbVar17 + 1;
  }
  uVar10 = *(int *)(unaff_BP + -3) + 0x800;
  if (0xb800 < uVar10) {
    uVar10 = *(int *)(unaff_BP + -3) + 0x2800;
  }
  *(uint *)(unaff_BP + -3) = uVar10;
  ((char *)pcVar16)[8] = 'E';
  FUN_1000_8b17();
  psubsb((sqword)in_ST5,*(undefined8 *)(char *)((int)in_BX + (int)(char *)pcVar16));
  uVar25 = in(0x61);
  return CONCAT22(CONCAT11((byte)((uint)extraout_DX_01 >> 8) | (byte)extraout_DX_01,
                           (byte)extraout_DX_01),uVar25);
}


