/* 1000:4b90 */

/* WARNING: Instruction at (ram,0x00014cda) overlaps instruction at (ram,0x00014cd9)
    */
/* WARNING: Removing unreachable block (ram,0x00014c91) */

undefined4 FUN_1000_4b90(void)

{
  uint *puVar1;
  ulong *puVar2;
  char *pcVar3;
  byte *pbVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int in_CX;
  uint uVar10;
  byte bVar11;
  int iVar12;
  byte bVar13;
  uint extraout_DX;
  int extraout_DX_00;
  undefined2 extraout_DX_01;
  uint *in_BX;
  byte bVar14;
  int unaff_BP;
  char *pcVar15;
  char *pcVar16;
  char *in_ESI;
  char *unaff_DI;
  byte *pbVar17;
  int unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  byte in_CF;
  bool bVar18;
  undefined1 uVar19;
  undefined1 in_PF;
  bool bVar20;
  longdouble in_ST0;
  undefined8 uVar21;
  unkbyte10 in_ST1;
  unkbyte10 in_ST2;
  unkbyte10 in_ST5;
  unkbyte10 in_ST6;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined2 uVar24;
  uint *puVar25;
  int in_stack_0000fffc;
  
  uVar22 = FUN_1000_5677();
  if ((bool)in_PF) {
LAB_1000_4bf5:
    iVar7 = (int)((ulong)uVar22 >> 0x10);
    iVar12 = (iVar7 - *(int *)((int)in_BX + (int)(char *)in_ESI)) - (uint)in_CF;
    pbVar4 = (byte *)((char *)in_ESI + 0x75);
    bVar13 = (byte)iVar12;
    uVar10 = CONCAT11((char)((uint)iVar12 >> 8),bVar13 + *pbVar4);
    if (!SCARRY1(bVar13,*pbVar4)) {
      iVar12 = (int)uVar22 + unaff_BP + (uint)CARRY1(bVar13,*pbVar4);
      goto code_r0x00014c00;
    }
  }
  else {
    bVar13 = *(byte *)(unaff_BP + -0x17ef);
    cVar6 = (char)uVar22;
    pcVar15 = (char *)in_ESI;
    bVar14 = (byte)((uint)in_BX >> 8) | pcVar15[unaff_BP + 0x10];
    unaff_DI[unaff_BP] = unaff_DI[unaff_BP] ^ 0x52;
    iVar12 = *(int *)(pcVar15 + CONCAT11(bVar14,(char)in_BX));
    *unaff_DI = cVar6;
    pcVar16 = unaff_DI + 2;
    unaff_DI[1] = cVar6;
    iVar7 = CONCAT11((byte)((ulong)uVar22 >> 8) | bVar13,cVar6 + -0x37);
    bVar13 = pcVar15[unaff_BP + 0x60];
    bVar9 = (byte)in_CX | pcVar16[unaff_BP + -0x17ef];
    in_CX = CONCAT11((char)((uint)in_CX >> 8),bVar9);
    *(sqword *)(pcVar15 + unaff_BP) = (sqword)in_ST0;
    if ((POPCOUNT(bVar9) & 1U) == 0) {
      puVar25 = (uint *)((uint)in_BX & 0xff);
code_r0x00014bc5:
      pcVar16[unaff_BP] = pcVar16[unaff_BP] ^ 0x45;
      pcVar3 = (char *)in_ESI;
      *pcVar3 = *pcVar3 + (char)iVar7;
      in_BX = (uint *)CONCAT11((byte)((uint)iVar7 >> 8) | ((char *)in_ESI)[unaff_BP + 0x60],
                               (char)iVar7);
      iVar7 = (int)puVar25 + unaff_BP;
      pcVar16 = pcVar16 + 2;
      in_ESI = (char *)((ulong)in_ESI & 0xffff0000);
      in_ST1 = in_ST2;
      in_ST5 = in_ST6;
      in_stack_0000fffc = in_CX;
    }
    else {
      pcVar16[unaff_BP] = pcVar16[unaff_BP] ^ 0x47;
      *pcVar15 = *pcVar15 + cVar6 + -0x37;
      pcVar16 = unaff_DI + 3;
      puVar25 = (uint *)CONCAT11(bVar14 | bVar13 | pcVar15[unaff_BP + 0x60],(char)in_BX);
      bVar20 = (POPCOUNT((byte)((uint)((int)((ulong)uVar22 >> 0x10) - iVar12) >> 8) |
                         ((char *)((int)puVar25 + (int)pcVar15))[0x11]) & 1U) == 0;
      iVar7 = FUN_1000_5685();
      in_BX = puVar25;
      in_ST1 = in_ST2;
      in_ST5 = in_ST6;
      in_stack_0000fffc = 0x4bc3;
      if (!bVar20) goto code_r0x00014bc5;
    }
    in_CX = in_CX + 1;
    *pcVar16 = (char)iVar7;
    unaff_DI = pcVar16 + 2;
    pcVar16[1] = (char)iVar7;
    pcVar3 = unaff_DI + unaff_BP;
    cVar6 = (char)((uint)in_BX >> 8);
    bVar20 = SBORROW1(*pcVar3,cVar6);
    *pcVar3 = *pcVar3 - cVar6;
    *(undefined1 *)0x33a6 = 0x42;
    in_ESI = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),(char *)0x339e);
    uVar24 = 0x4bea;
    uVar22 = func_0x0001c159();
    uVar10 = (uint)((ulong)uVar22 >> 0x10);
    iVar12 = (int)uVar22;
    if (!bVar20) {
      *(uint *)((int)in_BX + (int)unaff_DI) = *(uint *)((int)in_BX + (int)unaff_DI) ^ uVar10;
      uVar22 = func_0x0001c174();
      in_CF = 0;
      *(byte *)0x33a6 = *(byte *)0x33a6 & (byte)uVar22;
      goto LAB_1000_4bf5;
    }
    pcVar16 = (char *)in_ESI;
    uVar10 = uVar10 ^ *(uint *)(pcVar16 + unaff_BP + 0x1b);
    pcVar3 = pcVar16 + unaff_BP;
    *pcVar3 = *pcVar3 + (char)uVar22;
    if (*pcVar3 != '\0') {
      pcVar16[unaff_BP + 0x2aa] = pcVar16[unaff_BP + 0x2aa] & (byte)((uint)in_CX >> 8);
      puVar1 = (uint *)((int)in_BX + (int)pcVar16);
      iVar12 = (uVar10 + 1 & 3) - (*puVar1 & 3);
      *puVar1 = *puVar1 + (uint)(0 < iVar12) * iVar12;
      pcVar16[unaff_BP + 0x720a] = pcVar16[unaff_BP + 0x720a] | (byte)(uVar10 + 1 >> 8);
      bVar20 = true;
      FUN_1000_5644();
      iVar12 = unaff_ES;
      in_stack_0000fffc = unaff_DS;
      if (!bVar20) {
        FUN_1000_85e0(uVar24);
      }
      goto LAB_1000_4c8c;
    }
    *(byte *)0xe811 = *(byte *)0xe811 | (byte)uVar10;
    iVar7 = unaff_ES;
code_r0x00014c00:
    uVar22 = CONCAT22(iVar7,iVar12);
    in_stack_0000fffc = 0x2075;
    unaff_DI = unaff_DI + 1;
    in_ESI = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),(char *)in_ESI + 1);
  }
  uVar8 = (uint)uVar22 ^ in_BX[0x1b];
  pcVar16 = (char *)in_ESI;
  cVar6 = (char)uVar8;
  pcVar16[unaff_BP] = pcVar16[unaff_BP] + cVar6;
  cVar6 = cVar6 + (char)((uint)in_CX >> 8) + (*(char **)(unaff_DI + 0x70) < pcVar16);
  bVar20 = false;
  bVar13 = (byte)(uVar10 >> 8) | pcVar16[unaff_BP + -0x58];
  uVar23 = CONCAT22(CONCAT11(bVar13,(char)uVar10),CONCAT11((char)(uVar8 >> 8),cVar6));
  *unaff_DI = cVar6;
  uVar10 = in_CX - 1;
  if (uVar10 == 0 || bVar13 != 0) {
    *(undefined1 *)0x33b2 = 0x42;
    in_ESI = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),(char *)0x33aa);
    uVar23 = FUN_1000_563c();
    if (bVar20) {
      puVar25 = (uint *)0x4ca3;
      uVar24 = FUN_1000_5644();
      bVar13 = (byte)(uVar10 >> 8);
      iVar12 = (int)((ulong)uVar22 >> 0x10);
      if (bVar20) {
LAB_1000_4c8c:
        return CONCAT22(in_stack_0000fffc,iVar12);
      }
      goto code_r0x00014ca5;
    }
  }
  uVar24 = in((int)((ulong)uVar23 >> 0x10));
  *(undefined2 *)(unaff_DI + 1) = uVar24;
  *(uint *)0xe880 = *(uint *)0xe880 & (uint)in_BX;
  cVar6 = *(char *)(ulong)((int)in_BX + ((uint)uVar23 & 0xff));
  bVar13 = (byte)(uVar10 >> 8);
  pcVar16 = (char *)in_ESI;
  puVar1 = (uint *)(pcVar16 + unaff_BP + -1);
  uVar8 = *puVar1;
  *puVar1 = *puVar1 - uVar10;
  if (uVar10 <= uVar8) {
    FUN_1000_85f2();
    pcVar16 = (char *)in_ESI;
    *(uint *)((int)in_BX + (int)pcVar16) = *(uint *)((int)in_BX + (int)pcVar16) & extraout_DX;
    *(char *)((int)in_BX + (int)pcVar16) =
         *(char *)((int)in_BX + (int)pcVar16) + (char)uVar10 +
         CARRY1((byte)extraout_DX,pcVar16[unaff_BP + 0x20]);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar24 = CONCAT11((char)((ulong)uVar23 >> 8),cVar6 + bVar13 * '\x02' + '\x01');
  pcVar15 = pcVar16 + 2;
  in_ESI = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),pcVar15);
  *(undefined2 *)(unaff_DI + 3) = *(undefined2 *)pcVar16;
  *(uint *)(pcVar15 + unaff_BP + -0x1a) = *(uint *)(pcVar15 + unaff_BP + -0x1a) | (uint)pcVar15;
  puVar25 = in_BX;
code_r0x00014ca5:
  *(char *)in_BX = (char)((uint)in_BX >> 8);
  ((char *)in_ESI)[unaff_BP + -1] = ((char *)in_ESI)[unaff_BP + -1] | (byte)uVar24;
  *(undefined2 *)(unaff_BP + -3) = uVar24;
  iVar12 = (uint)bVar13 << 8;
  bVar20 = false;
  do {
    do {
      bVar18 = bVar20;
      ((char *)in_ESI)[8] = 'B';
      FUN_1000_5622(puVar25);
      bVar20 = true;
    } while (bVar18);
    uVar19 = 0;
    pbVar17 = (byte *)0x0;
    FUN_1000_5cef();
    puVar25 = (uint *)0x4cc5;
    uVar22 = FUN_1000_5644();
    bVar20 = true;
  } while ((bool)uVar19);
  *in_BX = (uint)in_BX;
  do {
    pcVar16 = (char *)in_ESI;
    pcVar16[unaff_BP + -0x19] = pcVar16[unaff_BP + -0x19] | (byte)((ulong)uVar22 >> 0x10);
    bVar20 = pcVar16 < (char *)*(int *)((int)in_BX + (int)pcVar16);
    in_ESI = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),
                              pcVar16 + -*(int *)((int)in_BX + (int)pcVar16));
    bVar9 = (byte)uVar22;
    pbVar17[-1] = bVar9;
    pbVar4 = pbVar17;
    pbVar17 = pbVar17 + 1;
    *pbVar4 = bVar9;
    bVar11 = (byte)((uint)iVar12 >> 8);
    bVar13 = bVar9 + bVar11;
    bVar14 = bVar13 + bVar20;
    bVar20 = 0xef < bVar14 || CARRY1(bVar14 + 0x10,CARRY1(bVar9,bVar11) || CARRY1(bVar13,bVar20));
    uVar22 = FUN_1000_5641();
    iVar7 = (int)((ulong)uVar22 >> 0x10);
  } while (bVar20);
  while( true ) {
    piVar5 = (int *)((char *)((int)in_BX + (int)(char *)in_ESI) + 6);
    *piVar5 = *piVar5 - iVar7;
    cVar6 = FUN_1000_661b();
    uVar21 = psubsb((sqword)in_ST1,*(undefined8 *)(pbVar17 + 10));
    in_ST1 = CONCAT28((int)((unkuint10)in_ST1 >> 0x40),uVar21);
    if (0xfa < (byte)(cVar6 + 1U)) break;
    puVar2 = (ulong *)((char *)in_ESI + unaff_BP + -0x15);
    *puVar2 = *puVar2 | (ulong)in_ESI;
    iVar7 = extraout_DX_00;
    pbVar17 = pbVar17 + 1;
  }
  uVar10 = *(int *)(unaff_BP + -3) + 0x800;
  if (0xb800 < uVar10) {
    uVar10 = *(int *)(unaff_BP + -3) + 0x2800;
  }
  *(uint *)(unaff_BP + -3) = uVar10;
  ((char *)in_ESI)[8] = 'E';
  FUN_1000_8b17();
  psubsb((sqword)in_ST5,*(undefined8 *)(char *)((int)in_BX + (int)(char *)in_ESI));
  uVar24 = in(0x61);
  return CONCAT22(CONCAT11((byte)((uint)extraout_DX_01 >> 8) | (byte)extraout_DX_01,
                           (byte)extraout_DX_01),uVar24);
}


