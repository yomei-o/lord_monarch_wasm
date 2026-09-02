/* 1000:36e4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00013ade) overlaps instruction at (ram,0x00013add)
    */
/* WARNING: Possible PIC construction at 0x00013b35: Changing call to branch */
/* WARNING: Possible PIC construction at 0x00013b44: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x00013b38) */
/* WARNING: Removing unreachable block (ram,0x00013b3a) */
/* WARNING: Removing unreachable block (ram,0x00013b47) */
/* WARNING: Removing unreachable block (ram,0x00013b49) */
/* WARNING: Removing unreachable block (ram,0x00013821) */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x00013ace) */
/* WARNING: Removing unreachable block (ram,0x00013ada) */
/* WARNING: Removing unreachable block (ram,0x00013ad5) */
/* WARNING: Removing unreachable block (ram,0x00013add) */
/* WARNING: Removing unreachable block (ram,0x00013889) */
/* WARNING: Removing unreachable block (ram,0x00013860) */
/* WARNING: Removing unreachable block (ram,0x00013862) */
/* WARNING: Removing unreachable block (ram,0x00013a25) */
/* WARNING: Removing unreachable block (ram,0x00013ae4) */
/* WARNING: Removing unreachable block (ram,0x000139ea) */
/* WARNING: Removing unreachable block (ram,0x0001384c) */

ulong FUN_1000_36e4(void)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  code *pcVar6;
  byte bVar7;
  byte bVar8;
  undefined2 uVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  undefined2 uVar13;
  undefined2 in_CX;
  uint uVar14;
  byte bVar15;
  char cVar17;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar16;
  uint *in_BX;
  uint uVar18;
  uint uVar19;
  undefined2 *puVar20;
  undefined2 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  int *piVar25;
  undefined2 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined2 *puVar30;
  undefined2 *puVar31;
  undefined2 *puVar32;
  undefined2 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined2 *in_ESP;
  undefined2 *puVar36;
  int *unaff_BP;
  int iVar37;
  uint *unaff_SI;
  int iVar38;
  uint *puVar39;
  char *unaff_DI;
  char *pcVar40;
  uint *puVar41;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 uVar42;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar43;
  byte in_AF;
  undefined1 uVar44;
  bool bVar45;
  bool bVar46;
  byte in_TF;
  byte in_IF;
  bool bVar47;
  char cVar48;
  byte in_NT;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  ulong uVar49;
  undefined4 uVar50;
  ulong uVar51;
  int *piVar52;
  uint uVar5;
  
  puVar20 = (undefined2 *)in_ESP;
  uVar42 = *puVar20;
  uVar9 = (undefined2)((ulong)in_ESP >> 0x10);
  uVar19 = CONCAT11(((char)((uint)in_CX >> 8) - *unaff_DI) - in_CF,(char)in_CX);
  *puVar20 = 0x36ef;
  uVar49 = FUN_1000_3d58();
  uVar14 = (uint)uVar49 | 0x89;
  bVar43 = false;
  uVar51 = uVar49 & 0xffff0000;
  pcVar40 = unaff_DI;
  if (uVar14 == 0) {
LAB_1000_3777:
    puVar41 = (uint *)(uVar51 >> 0x10);
    puVar23 = (undefined1 *)puVar20;
    if (bVar43) goto FUN_1000_3790_1;
  }
  else {
    bVar15 = (byte)(uVar49 >> 0x10);
    *(char *)((int)in_BX + (int)unaff_DI) = *(char *)((int)in_BX + (int)unaff_DI) - bVar15;
    bVar8 = ((char *)((int)in_BX + (int)unaff_DI))[0x3d];
    bVar7 = (byte)uVar14;
    unaff_SI = (uint *)((int)unaff_SI +
                       (-(uint)(bVar7 < 2 ||
                               (byte)(bVar7 - 2) <
                               CARRY1(bVar15,((char *)((int)in_BX + (int)unaff_DI))[0x3d])) -
                       in_BX[0x318]));
    uVar13 = *puVar20;
    *in_BX = *in_BX ^ (uint)unaff_BP;
    puVar3 = (uint *)((byte *)((int)unaff_BP + (int)unaff_SI) + 0x55);
    uVar14 = *puVar3;
    *puVar3 = *puVar3 >> 0xd;
    puVar3 = unaff_SI;
    iVar16 = (uVar19 & 3) - (*puVar3 & 3);
    *puVar3 = *puVar3 + (uint)(0 < iVar16) * iVar16;
    uVar18 = CONCAT11(((char)((uint)in_BX >> 8) - (char)uVar13) - ((uVar14 >> 0xc & 1) != 0),
                      (char)in_BX);
    LOCK();
    pcVar40 = (char *)unaff_BP[-0x17];
    unaff_BP[-0x17] = (int)unaff_DI;
    UNLOCK();
    *puVar20 = uVar13;
    puVar20[-1] = uVar19;
    puVar20[-2] = CONCAT11((char)(uVar49 >> 0x18),bVar15 + bVar8);
    puVar20[-3] = uVar18;
    puVar20[-4] = puVar20 + 1;
    puVar20[-5] = unaff_BP;
    puVar20[-6] = unaff_SI;
    puVar20[-7] = pcVar40;
    puVar3 = (uint *)((int)unaff_BP + (int)unaff_SI);
    piVar11 = (int *)*puVar3;
    uVar14 = *puVar3;
    *puVar3 = *puVar3 - (int)unaff_BP;
    uVar10 = *puVar3;
    uVar4 = *puVar3;
    uVar5 = *puVar3;
    puVar20[-8] = unaff_CS;
    puVar20[-9] = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar14,(int)unaff_BP) * 0x800 |
                  (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                  (uint)((int)uVar10 < 0) * 0x80 | (uint)(uVar4 == 0) * 0x40 |
                  (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT(uVar5 & 0xff) & 1U) == 0) * 4 |
                  (uint)(piVar11 < unaff_BP);
    puVar21 = puVar20 + -10;
    puVar20[-10] = 0x3743;
    FUN_1000_3c36();
    puVar22 = (undefined1 *)((int)puVar21 + -2);
    *(undefined2 *)((int)puVar21 + -2) = 0x3746;
    uVar50 = func_0x0001a7d4();
    *(int *)(puVar22 + -2) = (int)uVar50;
    cVar17 = pcVar40[-0x3f90];
    *(undefined2 *)(puVar22 + -4) = unaff_ES;
    *(int *)(puVar22 + -6) =
         CONCAT11((char)((ulong)uVar50 >> 8),(char)uVar50 + cVar17 + -0x25) + 0x534f;
    *(uint *)(puVar22 + -8) = uVar19;
    *(int *)(puVar22 + -10) = (int)((ulong)uVar50 >> 0x10);
    *(uint *)(puVar22 + -0xc) = uVar18;
    *(undefined1 **)(puVar22 + -0xe) = puVar22 + -4;
    *(int **)(puVar22 + -0x10) = unaff_BP;
    *(uint **)(puVar22 + -0x12) = unaff_SI;
    unaff_BP = (int *)(puVar22 + -0x14);
    *(char **)(puVar22 + -0x14) = pcVar40;
    iVar16 = -*unaff_SI;
    uVar14 = (uint)(puVar22 + -0x14 < (undefined1 *)*unaff_SI);
    uVar10 = uVar18 + *(uint *)(pcVar40 + uVar18);
    bVar43 = CARRY2(uVar18,*(uint *)(pcVar40 + uVar18)) || CARRY2(uVar10,uVar14);
    in_BX = (uint *)(uVar10 + uVar14);
    puVar20 = (undefined2 *)(puVar22 + iVar16 + -0x17);
    *(undefined2 *)(puVar22 + iVar16 + -0x17) = 0x375c;
    uVar51 = func_0x0001ac4f();
    puVar41 = (uint *)(uVar51 >> 0x10);
    if (bVar43) goto FUN_1000_3790_1;
    bVar8 = pcVar40[-0x2d82];
    in_BX = (uint *)CONCAT11((char)((uint)in_BX >> 8),bVar8);
    uVar19 = 5;
    unaff_BP = (int *)(puVar22 + -0x14);
    if (bVar8 == 0) goto FUN_1000_3790_1;
    unaff_BP = (int *)(puVar22 + -0x14);
    puVar23 = (undefined1 *)puVar20;
    if (0xb < bVar8) {
      bVar43 = bVar8 < 0x10;
      unaff_BP = (int *)(puVar22 + -0x14);
      goto LAB_1000_3777;
    }
  }
  puVar41 = (uint *)(uVar51 >> 0x10);
  uVar19 = 4;
  pcVar40 = (char *)((uint)pcVar40 | *(uint *)((char *)((int)in_BX + (int)pcVar40) + 0xb));
  if ((char)in_BX != '\x05') {
    uVar19 = 8;
  }
  *(uint *)(puVar23 + -2) = (uint)uVar51 | 0x6c72;
  puVar20 = (undefined2 *)(puVar23 + -4);
  *(uint **)(puVar23 + -4) = puVar41;
  in_BX = puVar41;
FUN_1000_3790_1:
  *(uint *)((int)puVar20 + -2) = uVar19;
  *(undefined2 *)((int)puVar20 + -4) = puVar41;
  puVar24 = (undefined1 *)((int)puVar20 + -6);
  *(undefined2 *)((int)puVar20 + -6) = 0x3799;
  uVar50 = func_0x0001ae87();
  *(int *)(puVar24 + -2) = (int)uVar50;
  *(uint **)(puVar24 + -4) = in_BX;
  *(undefined2 *)(puVar24 + -6) = 9;
  *(int *)(puVar24 + -8) = (int)((ulong)uVar50 >> 0x10);
  *(undefined2 *)(puVar24 + -10) = 0x37a1;
  uVar50 = func_0x0001af48();
  if ((uint)unaff_BP[-5] <= (uint)uVar50) {
    in_BX = (uint *)unaff_BP[-6];
    uVar50 = CONCAT22(unaff_BP[-8],unaff_BP[-5]);
  }
  *(uint *)(byte *)((int)in_BX + (int)unaff_SI) =
       *(int *)(byte *)((int)in_BX + (int)unaff_SI) + (int)((ulong)uVar50 >> 0x10) +
       (uint)((uint)uVar50 < (uint)unaff_BP[-1]);
  uVar19 = (uint)(byte)((char)uVar50 + (char)((ulong)uVar50 >> 8) * 't');
  ((char *)((int)unaff_BP + (int)pcVar40))[-0x3a2] =
       ((char *)((int)unaff_BP + (int)pcVar40))[-0x3a2] + -1;
  iVar16 = unaff_BP[-3];
  iVar37 = unaff_BP[-4];
  uVar14 = uVar19 - unaff_BP[7];
  uVar44 = uVar14 == 0;
  if (uVar19 < (uint)unaff_BP[7]) {
    uVar14 = unaff_SI[3] + uVar19 * -2;
    uVar44 = uVar14 == 0;
    if (uVar19 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar16;
      unaff_SI[4] = (uint)in_BX;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      piVar25 = unaff_BP + -1;
      unaff_BP[-1] = 0x37e2;
      func_0x0001ab65();
      puVar23 = (undefined1 *)((int)piVar25 + -2);
      *(undefined2 *)((int)piVar25 + -2) = 0x37e5;
      bVar8 = func_0x0001b496();
      if (!(bool)uVar44) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar8;
        if ((byte)unaff_SI[5] == 0xb) {
          puVar26 = (undefined2 *)(puVar23 + -2);
          puVar23 = puVar23 + -2;
          *puVar26 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar23 + 10),*(undefined2 *)(puVar23 + 0xe));
    }
  }
  piVar11 = unaff_BP + -1;
  unaff_BP[-1] = unaff_DS;
  puVar3 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar51 = CONCAT22(iVar37,CONCAT11(((int)uVar14 < 0) << 7 | uVar44 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar14 & 0xff) & 1U) == 0) << 2,(byte)*puVar3)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar3;
  if (pcVar40 != (char *)0xffff) {
    iVar38 = *unaff_BP;
    iVar37 = unaff_BP[1];
    uVar9 = unaff_BP[6];
    pcVar1 = (char *)(iVar37 + iVar38);
    *pcVar1 = *pcVar1 + (byte)uVar9;
    iVar16 = unaff_BP[7];
    pbVar2 = (byte *)(iVar37 + iVar38);
    *pbVar2 = *pbVar2 ^ (byte)uVar9;
    *(int *)(iVar16 + -2) = iVar37;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar14 = iVar16 + *(int *)((byte *)((int)in_BX + (int)unaff_SI) + 0xb44);
  puVar41 = (uint *)0x0;
code_r0x0001387f:
  uVar19 = (uint)(uVar51 >> 0x10);
  uVar10 = CONCAT11((char)(uVar51 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar8 = (byte)uVar10;
  *(byte *)(unaff_SI + 5) = bVar8;
  swi(4);
  pbVar2 = (byte *)((int)unaff_BP + (int)unaff_SI);
  *pbVar2 = *pbVar2 + bVar8;
  if ((POPCOUNT(*pbVar2) & 1U) != 0) {
    bVar8 = ((byte *)((int)in_BX + (int)unaff_SI))[0x33];
    bVar15 = (byte)(uVar51 >> 0x10);
    bVar7 = ((byte *)((int)in_BX + (int)unaff_SI))[0x33];
    cVar17 = (char)(uVar51 >> 0x18) + *(byte *)((int)in_BX + (int)unaff_SI);
    *(byte *)(puVar41 + 0x39) = (byte)puVar41[0x39] - cVar17;
    ((byte *)((int)unaff_BP + (int)puVar41))[-0x178e] =
         ((byte *)((int)unaff_BP + (int)puVar41))[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar17,bVar15 + bVar7),
                         (uVar10 + 0x5556) - (uint)CARRY1(bVar15,bVar8)) % (ulong)unaff_SI[0x410]);
    *(int *)(byte *)((int)unaff_BP + (int)puVar41) =
         *(int *)(byte *)((int)unaff_BP + (int)puVar41) >> 0x10;
    return CONCAT22(piVar11[1],*piVar11);
  }
  puVar39 = unaff_SI;
  if (*pbVar2 == 0) goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar43 = CARRY1((byte)in_BX,*(byte *)((int)unaff_BP + (int)unaff_SI));
  in_BX = (uint *)CONCAT11((char)((uint)in_BX >> 8),
                           (byte)in_BX + *(byte *)((int)unaff_BP + (int)unaff_SI));
  puVar28 = (undefined1 *)piVar11;
code_r0x000138eb:
  *(undefined2 *)(puVar28 + -2) = uVar42;
  if (!bVar43) {
    puVar3 = puVar41;
    puVar41 = (uint *)((int)puVar41 + 1);
    *(byte *)puVar3 = 0x30;
    uVar10 = CONCAT11(0xaa,*(byte *)((int)unaff_BP + (int)puVar41) | 0x30) ^ 0x8a0;
    *(uint **)(puVar28 + -2) = in_BX;
    *(uint *)(puVar28 + -4) = uVar10;
    in_BX = (uint *)unaff_SI[0x15];
    uVar19 = (uVar19 | 0x3000) - *(int *)(byte *)((int)in_BX + (int)unaff_SI);
    bVar7 = (byte)(uVar10 >> 8);
    bVar8 = (char)uVar10 + 8;
    if (bVar8 != (byte)in_BX[-0x16c1]) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar28 + -6) = CONCAT11(bVar7,bVar8);
    *(uint *)(puVar28 + -8) = uVar14;
    *(uint *)(puVar28 + -10) = uVar19;
    *(uint **)(puVar28 + -0xc) = in_BX;
    *(undefined1 **)(puVar28 + -0xe) = puVar28 + -4;
    *(int **)(puVar28 + -0x10) = unaff_BP;
    *(uint **)(puVar28 + -0x12) = unaff_SI;
    *(uint **)(puVar28 + -0x14) = puVar41;
    uVar10 = *puVar41;
    cVar17 = (char)(uVar14 >> 8);
    bVar15 = cVar17 + bVar8;
    uVar14 = CONCAT11(bVar15,(char)uVar14);
    unaff_BP = (int *)0x874;
    if (SCARRY1(cVar17,bVar8)) {
      piVar11 = *(int **)(puVar28 + -0x14);
      puVar39 = *(uint **)((byte *)((int)in_BX + (int)puVar41) + -0x18);
      puVar3 = puVar39 + 0x43a;
      uVar4 = *puVar3;
      *puVar3 = *puVar3 + 0x809;
      uVar14 = 0x4379;
      puVar39[0x43a] =
           puVar39[0x43a] + CONCAT11(bVar7 | (byte)uVar10,bVar8 | bVar15) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar28 + -0x16) = 0x874;
      piVar11 = (int *)(puVar28 + -0x18);
      *(undefined2 *)(puVar28 + -0x18) = 0x874;
      puVar39 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar41 + 0x55) = *(int *)(byte *)((int)puVar41 + 0x55) + uVar19;
    unaff_SI = (uint *)((int)puVar39 + 1);
    out((byte)*puVar39,uVar19);
    uVar10 = CONCAT11((byte)((uint)in_BX >> 8) & ((byte *)((int)unaff_BP + (int)unaff_SI))[0x11],
                      (char)in_BX);
    bVar7 = (byte)uVar19;
    cVar48 = SBORROW1(bVar7,(byte)puVar39[0x39]);
    bVar8 = (byte)puVar39[0x39];
    cVar17 = (char)(bVar7 - bVar8) < '\0';
    bVar43 = bVar7 == bVar8;
    puVar33 = (undefined2 *)((int)piVar11 + -2);
    *(undefined2 *)((int)piVar11 + -2) = 0x396b;
    bVar8 = func_0x0001b3ed();
    iVar16 = extraout_DX_00;
    if (!bVar43) {
      *(byte *)(puVar39 + 6) = bVar8;
      *(undefined2 *)((int)puVar33 + -2) = 0x3973;
      puVar33 = (undefined2 *)((int)puVar33 + -2);
      bVar8 = func_0x0001b617();
      iVar16 = extraout_DX_01;
    }
    if (cVar48 != cVar17) {
      iVar16 = iVar16 + 1;
      puVar33[-1] = puVar41;
      puVar33[-2] = iVar16;
      puVar33[-3] = CONCAT11((char)(uVar14 >> 8),8);
      puVar33[-4] = uVar10;
      if (iVar16 == 0) {
LAB_1000_39c7:
        pcVar6 = (code *)swi(1);
        uVar51 = (*pcVar6)();
        return uVar51;
      }
      ((byte *)((int)unaff_BP + (int)puVar41))[0x6e] =
           ((byte *)((int)unaff_BP + (int)puVar41))[0x6e] | (byte)((uint)iVar16 >> 8);
code_r0x00013985:
      pbVar2 = (byte *)((int)puVar41 + uVar10 + 0x12);
      *(byte **)pbVar2 = (byte *)((int)puVar41 + *(int *)pbVar2 + 2);
      puVar29 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar29 + -2) = 0x399f;
      func_0x00018e51();
      pcVar6 = (code *)swi(3);
      uVar51 = (*pcVar6)();
      return uVar51;
    }
    bVar8 = bVar8 ^ *(byte *)((int)unaff_BP + (int)unaff_SI);
    in_AF = 9 < (bVar8 & 0xf) | in_AF;
    bVar8 = bVar8 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar33;
    bVar43 = bVar8 < ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1] ||
             bVar8 == ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1];
    puVar36 = (undefined2 *)CONCAT22(uVar9,puVar33);
    *puVar33 = 0x39ba;
    piVar52 = (int *)FUN_1000_a1b8();
    piVar11 = (int *)piVar52;
    if (bVar43) {
      if (uVar14 == 1) {
        do {
          iVar16 = 0x40;
          piVar12 = piVar11;
          do {
            uVar14 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar39 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar36 = puVar36 + -2;
              *puVar36 = unaff_DS;
              bVar8 = (byte)piVar12 | 0x17;
              bVar7 = (byte)((uint)piVar12 >> 8);
              if (bVar7 == (byte)unaff_SI[6]) {
                piVar12 = (int *)CONCAT11(bVar8 / 0x5e,bVar8 % 0x5e);
                puVar39 = puVar41;
                goto code_r0x00013a16;
              }
              uVar14 = CONCAT11(bVar7 & *(byte *)((int)unaff_BP + (int)unaff_SI),(byte)piVar12) |
                       0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar16 >> 8);
              *(byte *)((int)unaff_BP + (int)puVar41) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 2);
              piVar12 = (int *)*(undefined2 *)puVar36;
              puVar36 = (undefined2 *)
                        CONCAT22((int)((ulong)puVar36 >> 0x10),(undefined2 *)puVar36 + 1);
              puVar39 = unaff_SI + 8;
              puVar41 = unaff_SI;
            }
            iVar16 = iVar16 + -1;
            unaff_SI = puVar39;
          } while (iVar16 != 0);
          unaff_SI = (uint *)*(undefined2 *)puVar36;
          puVar36 = (undefined2 *)CONCAT22((int)((ulong)puVar36 >> 0x10),(undefined2 *)puVar36 + 1);
          puVar39 = puVar41;
code_r0x00013a16:
          uVar9 = (undefined2)((ulong)puVar36 >> 0x10);
          puVar30 = (undefined2 *)puVar36;
          if (0x1ef < uVar14) goto code_r0x00013a1c;
          ((byte *)((int)unaff_BP + (int)puVar39))[0x59] =
               ((byte *)((int)unaff_BP + (int)puVar39))[0x59] | (byte)uVar14;
          bVar8 = *(byte *)(uVar14 + puVar30[1]);
          puVar30[1] = unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar14 + ((byte)((char)unaff_BP + 1U) < bVar8);
          piVar11 = (int *)CONCAT11((char)((uint)unaff_BP >> 8),(char)unaff_BP + -0x3b);
          puVar41 = (uint *)puVar30[1];
          puVar36 = (undefined2 *)CONCAT22(uVar9,puVar30 + 2);
          unaff_SI = (uint *)0xc800;
          unaff_BP = piVar12;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)piVar52 >> 0x10),(char)piVar52);
    puVar3 = unaff_SI;
    bVar43 = CARRY2(*puVar3,(uint)piVar11);
    *puVar3 = (uint)(*puVar3 + (int)piVar11);
    bVar46 = (int)*puVar3 < 0;
    bVar45 = *puVar3 == 0;
    bVar8 = POPCOUNT(*puVar3 & 0xff);
    uVar14 = uVar14 - 1;
    if (uVar14 == 0 || bVar45) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  in_BX = (uint *)((int)in_BX + 1);
  puVar23 = puVar28 + -4;
  *(undefined2 *)(puVar28 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar19;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar23 = puVar35;
  if (bVar43) {
    puVar23 = puVar35 + -2;
    *(undefined2 *)(puVar35 + -2) = 0x3b67;
    uVar51 = func_0x000137e6();
    bVar8 = (byte)uVar51;
    if (bVar43) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar51;
  }
  *(int **)(puVar23 + -2) = unaff_BP;
  puVar35 = puVar23 + -4;
  *(int **)(puVar23 + -4) = unaff_BP;
  pbVar2 = (byte *)((int)in_BX + (int)unaff_SI);
  bVar8 = (byte)(uVar51 >> 8);
  bVar43 = CARRY1(*pbVar2,bVar8);
  *pbVar2 = *pbVar2 + bVar8;
  in_BX = (uint *)((int)in_BX + -1);
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar43 = bVar8 < 0x10;
  bVar47 = SBORROW1(bVar8,'\x10');
  bVar46 = (char)(bVar8 - 0x10) < '\0';
  bVar45 = bVar8 == 0x10;
  if (!bVar43) {
    if (7 < bVar8) {
      bVar47 = SBORROW1(bVar8,'\f');
      bVar46 = (char)(bVar8 - 0xc) < '\0';
      bVar45 = bVar8 == 0xc;
      bVar43 = true;
      if (bVar8 < 0xc) goto LAB_1000_383e;
    }
    if (bVar8 != 0) {
      bVar47 = SBORROW1(bVar8,'\x05');
      bVar46 = (char)(bVar8 - 5) < '\0';
      bVar45 = bVar8 == 5;
      bVar43 = true;
      if (bVar8 < 5) goto LAB_1000_383e;
    }
    bVar43 = bVar8 < 5;
    bVar47 = SBORROW1(bVar8,'\x05');
    bVar46 = (char)(bVar8 - 5) < '\0';
    bVar45 = bVar8 == 5;
    if (!bVar45) {
      uVar14 = CONCAT11(((byte *)((int)unaff_BP + (int)puVar41))[-0x80],0xb);
      pbVar2 = (byte *)((int)in_BX + (int)unaff_SI);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      piVar11 = (int *)(puVar23 + -2);
      *(undefined2 *)(puVar23 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)((int)in_BX + (int)unaff_SI) = *(byte *)((int)in_BX + (int)unaff_SI) & (byte)uVar14;
      LOCK();
      iVar16 = unaff_BP[0x39];
      *(char *)(unaff_BP + 0x39) = (char)((uint)extraout_DX >> 8);
      uVar19 = CONCAT11((char)iVar16,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar43) {
    *(undefined2 *)(puVar23 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar45 && bVar47 == bVar46) {
    return CONCAT22(unaff_BP[5],unaff_BP[7]);
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar8 ^ 0xf8) & 0xf) | in_AF;
  pbVar2 = (byte *)((int)in_BX + (int)puVar41) + 0x854;
  *pbVar2 = *pbVar2 & 0xb;
  uVar44 = *pbVar2 == 0;
  puVar27 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  piVar11 = (int *)(puVar27 + -2);
  *(undefined2 *)(puVar27 + -2) = 0x387a;
  uVar51 = func_0x0001b476();
  if (!(bool)uVar44) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar51;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  uVar42 = *puVar30;
  *(longdouble *)(uVar14 + (int)puVar39) = in_ST0;
  puVar36 = (undefined2 *)CONCAT22(uVar9,(undefined2 *)(puVar30[1] + -2));
  *(undefined2 *)(puVar30[1] + -2) = unaff_ES;
  uVar10 = puVar39[2];
  piVar11 = (int *)(uint)*(byte *)((int)puVar39 + -0x79);
  bVar43 = (byte)iVar16 < *(byte *)((int)unaff_BP + (int)unaff_SI);
  cVar17 = (byte)iVar16 - *(byte *)((int)unaff_BP + (int)unaff_SI);
  uVar14 = CONCAT11((char)((uint)iVar16 >> 8),cVar17);
  bVar46 = cVar17 < '\0';
  bVar45 = cVar17 == '\0';
  bVar8 = POPCOUNT(cVar17);
  LOCK();
  puVar41 = (uint *)unaff_BP[-0x17];
  unaff_BP[-0x17] = (int)puVar39;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar45) {
    *(byte *)(uVar10 + (int)unaff_SI) = *(byte *)(uVar10 + (int)unaff_SI) + 1;
    puVar31 = (undefined2 *)puVar36;
    puVar36 = (undefined2 *)CONCAT22((int)((ulong)puVar36 >> 0x10),puVar31 + -1);
    puVar31[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar46 << 7 | bVar45 << 6 | in_AF << 4 | ((bVar8 & 1) == 0) << 2 | 2 |
                          bVar43,(char)piVar11)) {
      ((byte *)((int)unaff_BP + (int)puVar41))[-0x54ee] =
           ((byte *)((int)unaff_BP + (int)puVar41))[-0x54ee] | (byte)(uVar10 >> 8);
      puVar3 = puVar41;
      puVar41 = (uint *)((int)puVar41 + 1);
      *(byte *)puVar3 = (char)piVar11 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = (int *)((int)unaff_BP + uVar14);
    pbVar2 = (byte *)((uVar10 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar3 = (uint *)((byte *)((int)unaff_BP + (int)puVar41) + 0x645);
    uVar19 = *puVar3;
    *puVar3 = *puVar3 - uVar14;
    bVar8 = ((char)(uVar10 >> 1) + (char)(uVar10 >> 2) + -0x10) - (uVar19 < uVar14) | 2;
    iVar16 = *(int *)(byte *)((int)puVar41 + 0x55);
code_r0x00013aab:
    *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) & bVar8;
    ((undefined2 *)puVar36)[-1] = unaff_BP;
    *(byte *)((int)unaff_BP + (int)unaff_SI) =
         *(byte *)((int)unaff_BP + (int)unaff_SI) & (byte)uVar14;
    puVar33 = (undefined2 *)0xf029;
    *(undefined2 *)0xf029 = unaff_BP;
    if (iVar16 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) | bVar8;
      pcVar6 = (code *)swi(1);
      uVar51 = (*pcVar6)();
      return uVar51;
    }
    uVar19 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar19 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar6 = (code *)swi(0x20);
    (*pcVar6)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar10 >> 8);
    puVar32 = (undefined2 *)puVar36;
    uVar9 = (undefined2)((ulong)puVar36 >> 0x10);
    puVar32[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + uVar10 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)puVar41);
    puVar41 = (uint *)puVar32[-1];
    unaff_SI = (uint *)*puVar32;
    unaff_BP = (int *)puVar32[1];
    uVar14 = puVar32[5];
    uVar13 = puVar32[6];
    uVar19 = CONCAT11((char)((uint)puVar32[3] >> 8),(byte)puVar32[3] | *(byte *)0x5d02) |
             *(uint *)((byte *)((int)unaff_BP + (int)puVar41) + 10);
    puVar32[6] = puVar41;
    pbVar2 = (byte *)((int)unaff_SI + uVar19 + 0x2c2);
    cVar48 = SCARRY1((char)uVar13,*pbVar2);
    bVar43 = (char)((char)uVar13 + *pbVar2) < '\0';
    puVar33 = puVar32 + 5;
    puVar32[5] = 0x3a83;
    uVar50 = func_0x00013e95();
    bVar8 = (byte)uVar50;
    out(0x6f,bVar8);
    *(undefined1 *)0x1108 = (char)uVar19;
    cVar17 = (char)((ulong)uVar50 >> 0x18);
    if (bVar43) {
      bVar15 = (byte)(uVar19 >> 8);
      puVar3 = (uint *)((int)puVar41 + -0x53);
      uVar5 = (uint)(bVar15 < (byte)(uVar14 >> 8));
      uVar10 = *puVar3;
      uVar4 = *puVar3;
      *puVar3 = uVar4 + 0xe02d + uVar5;
      bVar7 = *(byte *)((int)unaff_BP + (int)puVar41);
      bVar15 = bVar15 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar50 >> 8);
      in_BX = (uint *)CONCAT11(bVar15,(char)uVar19);
      if ((char)bVar15 < '\0') {
        bVar43 = unaff_SI[3] < 1000;
        if (!bVar43) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar33 + -2) = 0x3b26;
          puVar33 = (undefined2 *)((int)puVar33 + -2);
          uVar50 = func_0x00013966();
          if (!bVar43) goto LAB_1000_3b55_1;
        }
        puVar35 = (undefined1 *)((int)puVar33 + -2);
        *(undefined2 *)((int)puVar33 + -2) = 0x3b2d;
        uVar51 = FUN_1000_8cb7();
        uVar19 = (uint)(uVar51 >> 0x10);
        bVar43 = (byte)uVar51 < 0x5a;
        if (bVar43) {
          bVar43 = true;
          if ((byte)uVar51 < 0x50) goto LAB_1000_3b62;
          puVar28 = puVar35 + -2;
          *(undefined2 *)(puVar35 + -2) = 0x3b38;
          bVar43 = false;
          goto code_r0x000138eb;
        }
        puVar34 = puVar35 + -2;
        *(undefined2 *)(puVar35 + -2) = 0x3b42;
        uVar50 = FUN_1000_3607();
        bVar8 = (byte)uVar50;
        if (bVar43) {
          puVar23 = puVar34 + -2;
          *(undefined2 *)(puVar34 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar51 = CONCAT22((int)((ulong)uVar50 >> 0x10),
                          CONCAT11((char)((ulong)uVar50 >> 8),(char)uVar50 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar36 = (undefined2 *)ZEXT24((undefined1 *)((int)puVar33 + -2));
      *(undefined2 *)((int)puVar33 + -2) = unaff_CS;
      iVar16 = CONCAT11(cVar17 - ((byte *)((int)in_BX + (int)unaff_SI))[0x23c9],
                        (char)((ulong)uVar50 >> 0x10) + bVar7 +
                        (0x1fd2 < uVar10 || CARRY2(uVar4 + 0xe02d,uVar5)));
      ((byte *)((int)unaff_BP + (int)puVar41))[0x5555] =
           ((byte *)((int)unaff_BP + (int)puVar41))[0x5555] + (char)uVar14;
      goto code_r0x00013aab;
    }
    if (cVar48 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar17;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar19 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar33 + 10),*(undefined2 *)((int)puVar33 + 0xe));
}


