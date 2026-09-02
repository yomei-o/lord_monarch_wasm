/* 1000:371a */

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

ulong FUN_1000_371a(void)

{
  uint *puVar1;
  char *pcVar2;
  byte *pbVar3;
  uint uVar4;
  code *pcVar6;
  byte bVar7;
  undefined2 in_AX;
  undefined2 uVar8;
  uint uVar9;
  int *piVar10;
  byte bVar13;
  int *piVar11;
  undefined2 uVar12;
  uint in_CX;
  uint uVar14;
  byte bVar15;
  undefined2 in_DX;
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
  undefined2 *puVar23;
  undefined2 *puVar24;
  undefined2 *puVar25;
  int *piVar26;
  undefined2 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined2 *puVar32;
  undefined2 *puVar33;
  undefined2 *puVar34;
  undefined2 *puVar35;
  undefined1 *puVar36;
  undefined1 *puVar37;
  undefined2 *in_ESP;
  undefined2 *puVar38;
  int *unaff_BP;
  int iVar39;
  uint *unaff_SI;
  int iVar40;
  uint *puVar41;
  uint unaff_DI;
  uint *puVar42;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar43;
  byte in_AF;
  bool in_ZF;
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
  undefined4 uVar49;
  ulong uVar50;
  int *piVar51;
  uint uVar5;
  
  uVar49 = CONCAT22(in_DX,in_AX);
  uVar14 = unaff_DI;
  if (in_ZF) {
LAB_1000_3777:
    puVar42 = (uint *)((ulong)uVar49 >> 0x10);
    if ((bool)in_CF) goto FUN_1000_3790_1;
  }
  else {
    bVar13 = (byte)in_DX;
    *(char *)((int)in_BX + unaff_DI) = *(char *)((int)in_BX + unaff_DI) - bVar13;
    pbVar3 = (byte *)((int)in_BX + unaff_DI + 0x3d);
    bVar7 = *pbVar3;
    unaff_SI = (uint *)((int)unaff_SI +
                       (-(uint)((byte)in_AX < 2 || (byte)((byte)in_AX - 2) < CARRY1(bVar13,*pbVar3))
                       - in_BX[0x318]));
    puVar20 = (undefined2 *)in_ESP;
    uVar8 = *puVar20;
    uVar12 = (undefined2)((ulong)in_ESP >> 0x10);
    *in_BX = *in_BX ^ (uint)unaff_BP;
    puVar1 = (uint *)((byte *)((int)unaff_BP + (int)unaff_SI) + 0x55);
    uVar14 = *puVar1;
    *puVar1 = *puVar1 >> 0xd;
    puVar1 = unaff_SI;
    iVar16 = (in_CX & 3) - (*puVar1 & 3);
    *puVar1 = *puVar1 + (uint)(0 < iVar16) * iVar16;
    uVar18 = CONCAT11(((char)((uint)in_BX >> 8) - (char)uVar8) - ((uVar14 >> 0xc & 1) != 0),
                      (char)in_BX);
    LOCK();
    uVar14 = unaff_BP[-0x17];
    unaff_BP[-0x17] = unaff_DI;
    UNLOCK();
    *puVar20 = uVar8;
    puVar20[-1] = in_CX;
    puVar20[-2] = CONCAT11((char)((uint)in_DX >> 8),bVar13 + bVar7);
    puVar20[-3] = uVar18;
    puVar20[-4] = puVar20 + 1;
    puVar20[-5] = unaff_BP;
    puVar20[-6] = unaff_SI;
    puVar20[-7] = uVar14;
    puVar1 = (uint *)((int)unaff_BP + (int)unaff_SI);
    piVar10 = (int *)*puVar1;
    uVar19 = *puVar1;
    *puVar1 = *puVar1 - (int)unaff_BP;
    uVar9 = *puVar1;
    uVar4 = *puVar1;
    uVar5 = *puVar1;
    puVar20[-8] = unaff_CS;
    puVar20[-9] = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar19,(int)unaff_BP) * 0x800 |
                  (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                  (uint)((int)uVar9 < 0) * 0x80 | (uint)(uVar4 == 0) * 0x40 |
                  (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT(uVar5 & 0xff) & 1U) == 0) * 4 |
                  (uint)(piVar10 < unaff_BP);
    puVar21 = puVar20 + -10;
    puVar20[-10] = 0x3743;
    FUN_1000_3c36();
    puVar22 = (undefined1 *)((int)puVar21 + -2);
    *(undefined2 *)((int)puVar21 + -2) = 0x3746;
    uVar49 = func_0x0001a7d4();
    *(int *)(puVar22 + -2) = (int)uVar49;
    cVar17 = *(char *)(uVar14 + 0xc070);
    *(undefined2 *)(puVar22 + -4) = unaff_ES;
    *(int *)(puVar22 + -6) =
         CONCAT11((char)((ulong)uVar49 >> 8),(char)uVar49 + cVar17 + -0x25) + 0x534f;
    *(uint *)(puVar22 + -8) = in_CX;
    *(int *)(puVar22 + -10) = (int)((ulong)uVar49 >> 0x10);
    *(uint *)(puVar22 + -0xc) = uVar18;
    *(undefined1 **)(puVar22 + -0xe) = puVar22 + -4;
    *(int **)(puVar22 + -0x10) = unaff_BP;
    *(uint **)(puVar22 + -0x12) = unaff_SI;
    unaff_BP = (int *)(puVar22 + -0x14);
    *(uint *)(puVar22 + -0x14) = uVar14;
    iVar16 = -*unaff_SI;
    uVar19 = (uint)(puVar22 + -0x14 < (undefined1 *)*unaff_SI);
    uVar9 = uVar18 + *(uint *)(uVar18 + uVar14);
    bVar43 = CARRY2(uVar18,*(uint *)(uVar18 + uVar14)) || CARRY2(uVar9,uVar19);
    in_BX = (uint *)(uVar9 + uVar19);
    in_ESP = (undefined2 *)CONCAT22(uVar12,puVar22 + iVar16 + -0x17);
    *(undefined2 *)(puVar22 + iVar16 + -0x17) = 0x375c;
    uVar49 = func_0x0001ac4f();
    puVar42 = (uint *)((ulong)uVar49 >> 0x10);
    if (bVar43) goto FUN_1000_3790_1;
    bVar7 = *(byte *)(uVar14 + 0xd27e);
    in_BX = (uint *)CONCAT11((char)((uint)in_BX >> 8),bVar7);
    in_CX = 5;
    unaff_BP = (int *)(puVar22 + -0x14);
    if (bVar7 == 0) goto FUN_1000_3790_1;
    unaff_BP = (int *)(puVar22 + -0x14);
    if (0xb < bVar7) {
      in_CF = bVar7 < 0x10;
      unaff_BP = (int *)(puVar22 + -0x14);
      goto LAB_1000_3777;
    }
  }
  puVar42 = (uint *)((ulong)uVar49 >> 0x10);
  in_CX = 4;
  uVar14 = uVar14 | *(uint *)((int)in_BX + uVar14 + 0xb);
  if ((char)in_BX != '\x05') {
    in_CX = 8;
  }
  puVar23 = (undefined2 *)in_ESP;
  puVar23[-1] = (uint)uVar49 | 0x6c72;
  in_ESP = (undefined2 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar23 + -2);
  puVar23[-2] = puVar42;
  in_BX = puVar42;
FUN_1000_3790_1:
  puVar24 = (undefined2 *)in_ESP;
  uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar24[-1] = in_CX;
  puVar24[-2] = puVar42;
  puVar25 = puVar24 + -3;
  puVar24[-3] = 0x3799;
  uVar49 = func_0x0001ae87();
  *(undefined2 *)((int)puVar25 + -2) = (int)uVar49;
  *(undefined2 *)((int)puVar25 + -4) = in_BX;
  *(undefined2 *)((int)puVar25 + -6) = 9;
  *(undefined2 *)((int)puVar25 + -8) = (int)((ulong)uVar49 >> 0x10);
  *(undefined2 *)((int)puVar25 + -10) = 0x37a1;
  uVar49 = func_0x0001af48();
  if ((uint)unaff_BP[-5] <= (uint)uVar49) {
    in_BX = (uint *)unaff_BP[-6];
    uVar49 = CONCAT22(unaff_BP[-8],unaff_BP[-5]);
  }
  *(uint *)(byte *)((int)in_BX + (int)unaff_SI) =
       *(int *)(byte *)((int)in_BX + (int)unaff_SI) + (int)((ulong)uVar49 >> 0x10) +
       (uint)((uint)uVar49 < (uint)unaff_BP[-1]);
  uVar9 = (uint)(byte)((char)uVar49 + (char)((ulong)uVar49 >> 8) * 't');
  pcVar2 = (char *)((int)unaff_BP + (uVar14 - 0x3a2));
  *pcVar2 = *pcVar2 + -1;
  iVar16 = unaff_BP[-3];
  iVar39 = unaff_BP[-4];
  uVar19 = uVar9 - unaff_BP[7];
  uVar44 = uVar19 == 0;
  if (uVar9 < (uint)unaff_BP[7]) {
    uVar19 = unaff_SI[3] + uVar9 * -2;
    uVar44 = uVar19 == 0;
    if (uVar9 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar16;
      unaff_SI[4] = (uint)in_BX;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      piVar26 = unaff_BP + -1;
      unaff_BP[-1] = 0x37e2;
      func_0x0001ab65();
      puVar28 = (undefined1 *)((int)piVar26 + -2);
      *(undefined2 *)((int)piVar26 + -2) = 0x37e5;
      bVar7 = func_0x0001b496();
      if (!(bool)uVar44) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar7;
        if ((byte)unaff_SI[5] == 0xb) {
          puVar27 = (undefined2 *)(puVar28 + -2);
          puVar28 = puVar28 + -2;
          *puVar27 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar28 + 10),*(undefined2 *)(puVar28 + 0xe));
    }
  }
  piVar10 = unaff_BP + -1;
  unaff_BP[-1] = unaff_DS;
  puVar1 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar50 = CONCAT22(iVar39,CONCAT11(((int)uVar19 < 0) << 7 | uVar44 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar19 & 0xff) & 1U) == 0) << 2,(byte)*puVar1)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar1;
  if (uVar14 != 0xffff) {
    iVar40 = *unaff_BP;
    iVar39 = unaff_BP[1];
    uVar8 = unaff_BP[6];
    pcVar2 = (char *)(iVar39 + iVar40);
    *pcVar2 = *pcVar2 + (byte)uVar8;
    iVar16 = unaff_BP[7];
    pbVar3 = (byte *)(iVar39 + iVar40);
    *pbVar3 = *pbVar3 ^ (byte)uVar8;
    *(int *)(iVar16 + -2) = iVar39;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar14 = iVar16 + *(int *)((byte *)((int)in_BX + (int)unaff_SI) + 0xb44);
  puVar42 = (uint *)0x0;
code_r0x0001387f:
  uVar19 = (uint)(uVar50 >> 0x10);
  uVar9 = CONCAT11((char)(uVar50 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar7 = (byte)uVar9;
  *(byte *)(unaff_SI + 5) = bVar7;
  swi(4);
  pbVar3 = (byte *)((int)unaff_BP + (int)unaff_SI);
  *pbVar3 = *pbVar3 + bVar7;
  if ((POPCOUNT(*pbVar3) & 1U) != 0) {
    bVar7 = ((byte *)((int)in_BX + (int)unaff_SI))[0x33];
    bVar15 = (byte)(uVar50 >> 0x10);
    bVar13 = ((byte *)((int)in_BX + (int)unaff_SI))[0x33];
    cVar17 = (char)(uVar50 >> 0x18) + *(byte *)((int)in_BX + (int)unaff_SI);
    *(byte *)(puVar42 + 0x39) = (byte)puVar42[0x39] - cVar17;
    ((byte *)((int)unaff_BP + (int)puVar42))[-0x178e] =
         ((byte *)((int)unaff_BP + (int)puVar42))[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar17,bVar15 + bVar13),
                         (uVar9 + 0x5556) - (uint)CARRY1(bVar15,bVar7)) % (ulong)unaff_SI[0x410]);
    *(int *)(byte *)((int)unaff_BP + (int)puVar42) =
         *(int *)(byte *)((int)unaff_BP + (int)puVar42) >> 0x10;
    return CONCAT22(piVar10[1],*piVar10);
  }
  puVar41 = unaff_SI;
  if (*pbVar3 == 0) goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar43 = CARRY1((byte)in_BX,*(byte *)((int)unaff_BP + (int)unaff_SI));
  in_BX = (uint *)CONCAT11((char)((uint)in_BX >> 8),
                           (byte)in_BX + *(byte *)((int)unaff_BP + (int)unaff_SI));
  puVar30 = (undefined1 *)piVar10;
code_r0x000138eb:
  *(undefined2 *)(puVar30 + -2) = unaff_SS;
  if (!bVar43) {
    puVar1 = puVar42;
    puVar42 = (uint *)((int)puVar42 + 1);
    *(byte *)puVar1 = 0x30;
    uVar9 = CONCAT11(0xaa,*(byte *)((int)unaff_BP + (int)puVar42) | 0x30) ^ 0x8a0;
    *(uint **)(puVar30 + -2) = in_BX;
    *(uint *)(puVar30 + -4) = uVar9;
    in_BX = (uint *)unaff_SI[0x15];
    uVar19 = (uVar19 | 0x3000) - *(int *)(byte *)((int)in_BX + (int)unaff_SI);
    bVar13 = (byte)(uVar9 >> 8);
    bVar7 = (char)uVar9 + 8;
    if (bVar7 != (byte)in_BX[-0x16c1]) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar30 + -6) = CONCAT11(bVar13,bVar7);
    *(uint *)(puVar30 + -8) = uVar14;
    *(uint *)(puVar30 + -10) = uVar19;
    *(uint **)(puVar30 + -0xc) = in_BX;
    *(undefined1 **)(puVar30 + -0xe) = puVar30 + -4;
    *(int **)(puVar30 + -0x10) = unaff_BP;
    *(uint **)(puVar30 + -0x12) = unaff_SI;
    *(uint **)(puVar30 + -0x14) = puVar42;
    uVar9 = *puVar42;
    cVar17 = (char)(uVar14 >> 8);
    bVar15 = cVar17 + bVar7;
    uVar14 = CONCAT11(bVar15,(char)uVar14);
    unaff_BP = (int *)0x874;
    if (SCARRY1(cVar17,bVar7)) {
      piVar10 = *(int **)(puVar30 + -0x14);
      puVar41 = *(uint **)((byte *)((int)in_BX + (int)puVar42) + -0x18);
      puVar1 = puVar41 + 0x43a;
      uVar4 = *puVar1;
      *puVar1 = *puVar1 + 0x809;
      uVar14 = 0x4379;
      puVar41[0x43a] =
           puVar41[0x43a] + CONCAT11(bVar13 | (byte)uVar9,bVar7 | bVar15) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar30 + -0x16) = 0x874;
      piVar10 = (int *)(puVar30 + -0x18);
      *(undefined2 *)(puVar30 + -0x18) = 0x874;
      puVar41 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar42 + 0x55) = *(int *)(byte *)((int)puVar42 + 0x55) + uVar19;
    unaff_SI = (uint *)((int)puVar41 + 1);
    out((byte)*puVar41,uVar19);
    uVar9 = CONCAT11((byte)((uint)in_BX >> 8) & ((byte *)((int)unaff_BP + (int)unaff_SI))[0x11],
                     (char)in_BX);
    bVar13 = (byte)uVar19;
    cVar48 = SBORROW1(bVar13,(byte)puVar41[0x39]);
    bVar7 = (byte)puVar41[0x39];
    cVar17 = (char)(bVar13 - bVar7) < '\0';
    bVar43 = bVar13 == bVar7;
    puVar35 = (undefined2 *)((int)piVar10 + -2);
    *(undefined2 *)((int)piVar10 + -2) = 0x396b;
    bVar7 = func_0x0001b3ed();
    iVar16 = extraout_DX_00;
    if (!bVar43) {
      *(byte *)(puVar41 + 6) = bVar7;
      *(undefined2 *)((int)puVar35 + -2) = 0x3973;
      puVar35 = (undefined2 *)((int)puVar35 + -2);
      bVar7 = func_0x0001b617();
      iVar16 = extraout_DX_01;
    }
    if (cVar48 != cVar17) {
      iVar16 = iVar16 + 1;
      puVar35[-1] = puVar42;
      puVar35[-2] = iVar16;
      puVar35[-3] = CONCAT11((char)(uVar14 >> 8),8);
      puVar35[-4] = uVar9;
      if (iVar16 == 0) {
LAB_1000_39c7:
        pcVar6 = (code *)swi(1);
        uVar50 = (*pcVar6)();
        return uVar50;
      }
      ((byte *)((int)unaff_BP + (int)puVar42))[0x6e] =
           ((byte *)((int)unaff_BP + (int)puVar42))[0x6e] | (byte)((uint)iVar16 >> 8);
code_r0x00013985:
      pbVar3 = (byte *)((int)puVar42 + uVar9 + 0x12);
      *(byte **)pbVar3 = (byte *)((int)puVar42 + *(int *)pbVar3 + 2);
      puVar31 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar31 + -2) = 0x399f;
      func_0x00018e51();
      pcVar6 = (code *)swi(3);
      uVar50 = (*pcVar6)();
      return uVar50;
    }
    bVar7 = bVar7 ^ *(byte *)((int)unaff_BP + (int)unaff_SI);
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    bVar7 = bVar7 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar35;
    bVar43 = bVar7 < ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1] ||
             bVar7 == ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1];
    puVar38 = (undefined2 *)CONCAT22(uVar8,puVar35);
    *puVar35 = 0x39ba;
    piVar51 = (int *)FUN_1000_a1b8();
    piVar10 = (int *)piVar51;
    if (bVar43) {
      if (uVar14 == 1) {
        do {
          iVar16 = 0x40;
          piVar11 = piVar10;
          do {
            uVar14 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar41 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar38 = puVar38 + -2;
              *puVar38 = unaff_DS;
              bVar7 = (byte)piVar11 | 0x17;
              bVar13 = (byte)((uint)piVar11 >> 8);
              if (bVar13 == (byte)unaff_SI[6]) {
                piVar11 = (int *)CONCAT11(bVar7 / 0x5e,bVar7 % 0x5e);
                puVar41 = puVar42;
                goto code_r0x00013a16;
              }
              uVar14 = CONCAT11(bVar13 & *(byte *)((int)unaff_BP + (int)unaff_SI),(byte)piVar11) |
                       0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar16 >> 8);
              *(byte *)((int)unaff_BP + (int)puVar42) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 2);
              piVar11 = (int *)*(undefined2 *)puVar38;
              puVar38 = (undefined2 *)
                        CONCAT22((int)((ulong)puVar38 >> 0x10),(undefined2 *)puVar38 + 1);
              puVar41 = unaff_SI + 8;
              puVar42 = unaff_SI;
            }
            iVar16 = iVar16 + -1;
            unaff_SI = puVar41;
          } while (iVar16 != 0);
          unaff_SI = (uint *)*(undefined2 *)puVar38;
          puVar38 = (undefined2 *)CONCAT22((int)((ulong)puVar38 >> 0x10),(undefined2 *)puVar38 + 1);
          puVar41 = puVar42;
code_r0x00013a16:
          uVar8 = (undefined2)((ulong)puVar38 >> 0x10);
          puVar32 = (undefined2 *)puVar38;
          if (0x1ef < uVar14) goto code_r0x00013a1c;
          ((byte *)((int)unaff_BP + (int)puVar41))[0x59] =
               ((byte *)((int)unaff_BP + (int)puVar41))[0x59] | (byte)uVar14;
          bVar7 = *(byte *)(uVar14 + puVar32[1]);
          puVar32[1] = unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar14 + ((byte)((char)unaff_BP + 1U) < bVar7);
          piVar10 = (int *)CONCAT11((char)((uint)unaff_BP >> 8),(char)unaff_BP + -0x3b);
          puVar42 = (uint *)puVar32[1];
          puVar38 = (undefined2 *)CONCAT22(uVar8,puVar32 + 2);
          unaff_SI = (uint *)0xc800;
          unaff_BP = piVar11;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)piVar51 >> 0x10),(char)piVar51);
    puVar1 = unaff_SI;
    bVar43 = CARRY2(*puVar1,(uint)piVar10);
    *puVar1 = (uint)(*puVar1 + (int)piVar10);
    bVar46 = (int)*puVar1 < 0;
    bVar45 = *puVar1 == 0;
    bVar7 = POPCOUNT(*puVar1 & 0xff);
    uVar14 = uVar14 - 1;
    if (uVar14 == 0 || bVar45) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  in_BX = (uint *)((int)in_BX + 1);
  puVar28 = puVar30 + -4;
  *(undefined2 *)(puVar30 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar19;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar28 = puVar37;
  if (bVar43) {
    puVar28 = puVar37 + -2;
    *(undefined2 *)(puVar37 + -2) = 0x3b67;
    uVar50 = func_0x000137e6();
    bVar7 = (byte)uVar50;
    if (bVar43) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar50;
  }
  *(int **)(puVar28 + -2) = unaff_BP;
  puVar37 = puVar28 + -4;
  *(int **)(puVar28 + -4) = unaff_BP;
  pbVar3 = (byte *)((int)in_BX + (int)unaff_SI);
  bVar7 = (byte)(uVar50 >> 8);
  bVar43 = CARRY1(*pbVar3,bVar7);
  *pbVar3 = *pbVar3 + bVar7;
  in_BX = (uint *)((int)in_BX + -1);
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar43 = bVar7 < 0x10;
  bVar47 = SBORROW1(bVar7,'\x10');
  bVar46 = (char)(bVar7 - 0x10) < '\0';
  bVar45 = bVar7 == 0x10;
  if (!bVar43) {
    if (7 < bVar7) {
      bVar47 = SBORROW1(bVar7,'\f');
      bVar46 = (char)(bVar7 - 0xc) < '\0';
      bVar45 = bVar7 == 0xc;
      bVar43 = true;
      if (bVar7 < 0xc) goto LAB_1000_383e;
    }
    if (bVar7 != 0) {
      bVar47 = SBORROW1(bVar7,'\x05');
      bVar46 = (char)(bVar7 - 5) < '\0';
      bVar45 = bVar7 == 5;
      bVar43 = true;
      if (bVar7 < 5) goto LAB_1000_383e;
    }
    bVar43 = bVar7 < 5;
    bVar47 = SBORROW1(bVar7,'\x05');
    bVar46 = (char)(bVar7 - 5) < '\0';
    bVar45 = bVar7 == 5;
    if (!bVar45) {
      uVar14 = CONCAT11(((byte *)((int)unaff_BP + (int)puVar42))[-0x80],0xb);
      pbVar3 = (byte *)((int)in_BX + (int)unaff_SI);
      *pbVar3 = *pbVar3 & 0xb;
      if (*pbVar3 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      piVar10 = (int *)(puVar28 + -2);
      *(undefined2 *)(puVar28 + -2) = 0x38e1;
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
    *(undefined2 *)(puVar28 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar45 && bVar47 == bVar46) {
    return CONCAT22(unaff_BP[5],unaff_BP[7]);
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar7 ^ 0xf8) & 0xf) | in_AF;
  pbVar3 = (byte *)((int)in_BX + (int)puVar42) + 0x854;
  *pbVar3 = *pbVar3 & 0xb;
  uVar44 = *pbVar3 == 0;
  puVar29 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  piVar10 = (int *)(puVar29 + -2);
  *(undefined2 *)(puVar29 + -2) = 0x387a;
  uVar50 = func_0x0001b476();
  if (!(bool)uVar44) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar50;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar32;
  *(longdouble *)(uVar14 + (int)puVar41) = in_ST0;
  puVar38 = (undefined2 *)CONCAT22(uVar8,(undefined2 *)(puVar32[1] + -2));
  *(undefined2 *)(puVar32[1] + -2) = unaff_ES;
  uVar9 = puVar41[2];
  piVar10 = (int *)(uint)*(byte *)((int)puVar41 + -0x79);
  bVar43 = (byte)iVar16 < *(byte *)((int)unaff_BP + (int)unaff_SI);
  cVar17 = (byte)iVar16 - *(byte *)((int)unaff_BP + (int)unaff_SI);
  uVar14 = CONCAT11((char)((uint)iVar16 >> 8),cVar17);
  bVar46 = cVar17 < '\0';
  bVar45 = cVar17 == '\0';
  bVar7 = POPCOUNT(cVar17);
  LOCK();
  puVar42 = (uint *)unaff_BP[-0x17];
  unaff_BP[-0x17] = (int)puVar41;
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
    *(byte *)(uVar9 + (int)unaff_SI) = *(byte *)(uVar9 + (int)unaff_SI) + 1;
    puVar33 = (undefined2 *)puVar38;
    puVar38 = (undefined2 *)CONCAT22((int)((ulong)puVar38 >> 0x10),puVar33 + -1);
    puVar33[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar46 << 7 | bVar45 << 6 | in_AF << 4 | ((bVar7 & 1) == 0) << 2 | 2 |
                          bVar43,(char)piVar10)) {
      ((byte *)((int)unaff_BP + (int)puVar42))[-0x54ee] =
           ((byte *)((int)unaff_BP + (int)puVar42))[-0x54ee] | (byte)(uVar9 >> 8);
      puVar1 = puVar42;
      puVar42 = (uint *)((int)puVar42 + 1);
      *(byte *)puVar1 = (char)piVar10 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = (int *)((int)unaff_BP + uVar14);
    pbVar3 = (byte *)((uVar9 >> 2) + (int)unaff_SI);
    *pbVar3 = *pbVar3 - 0x15;
    puVar1 = (uint *)((byte *)((int)unaff_BP + (int)puVar42) + 0x645);
    uVar19 = *puVar1;
    *puVar1 = *puVar1 - uVar14;
    bVar7 = ((char)(uVar9 >> 1) + (char)(uVar9 >> 2) + -0x10) - (uVar19 < uVar14) | 2;
    iVar16 = *(int *)(byte *)((int)puVar42 + 0x55);
code_r0x00013aab:
    *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) & bVar7;
    ((undefined2 *)puVar38)[-1] = unaff_BP;
    *(byte *)((int)unaff_BP + (int)unaff_SI) =
         *(byte *)((int)unaff_BP + (int)unaff_SI) & (byte)uVar14;
    puVar35 = (undefined2 *)0xf029;
    *(undefined2 *)0xf029 = unaff_BP;
    if (iVar16 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) | bVar7;
      pcVar6 = (code *)swi(1);
      uVar50 = (*pcVar6)();
      return uVar50;
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
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar9 >> 8);
    puVar34 = (undefined2 *)puVar38;
    uVar8 = (undefined2)((ulong)puVar38 >> 0x10);
    puVar34[-1] = unaff_ES;
    pbVar3 = (byte *)((int)unaff_SI + uVar9 + 0x222);
    *(byte **)pbVar3 = (byte *)(*(int *)pbVar3 + (int)puVar42);
    puVar42 = (uint *)puVar34[-1];
    unaff_SI = (uint *)*puVar34;
    unaff_BP = (int *)puVar34[1];
    uVar14 = puVar34[5];
    uVar12 = puVar34[6];
    uVar19 = CONCAT11((char)((uint)puVar34[3] >> 8),(byte)puVar34[3] | *(byte *)0x5d02) |
             *(uint *)((byte *)((int)unaff_BP + (int)puVar42) + 10);
    puVar34[6] = puVar42;
    pbVar3 = (byte *)((int)unaff_SI + uVar19 + 0x2c2);
    cVar48 = SCARRY1((char)uVar12,*pbVar3);
    bVar43 = (char)((char)uVar12 + *pbVar3) < '\0';
    puVar35 = puVar34 + 5;
    puVar34[5] = 0x3a83;
    uVar49 = func_0x00013e95();
    bVar7 = (byte)uVar49;
    out(0x6f,bVar7);
    *(undefined1 *)0x1108 = (char)uVar19;
    cVar17 = (char)((ulong)uVar49 >> 0x18);
    if (bVar43) {
      bVar15 = (byte)(uVar19 >> 8);
      puVar1 = (uint *)((int)puVar42 + -0x53);
      uVar5 = (uint)(bVar15 < (byte)(uVar14 >> 8));
      uVar9 = *puVar1;
      uVar4 = *puVar1;
      *puVar1 = uVar4 + 0xe02d + uVar5;
      bVar13 = *(byte *)((int)unaff_BP + (int)puVar42);
      bVar15 = bVar15 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar49 >> 8);
      in_BX = (uint *)CONCAT11(bVar15,(char)uVar19);
      if ((char)bVar15 < '\0') {
        bVar43 = unaff_SI[3] < 1000;
        if (!bVar43) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar35 + -2) = 0x3b26;
          puVar35 = (undefined2 *)((int)puVar35 + -2);
          uVar49 = func_0x00013966();
          if (!bVar43) goto LAB_1000_3b55_1;
        }
        puVar37 = (undefined1 *)((int)puVar35 + -2);
        *(undefined2 *)((int)puVar35 + -2) = 0x3b2d;
        uVar50 = FUN_1000_8cb7();
        uVar19 = (uint)(uVar50 >> 0x10);
        bVar43 = (byte)uVar50 < 0x5a;
        if (bVar43) {
          bVar43 = true;
          if ((byte)uVar50 < 0x50) goto LAB_1000_3b62;
          puVar30 = puVar37 + -2;
          *(undefined2 *)(puVar37 + -2) = 0x3b38;
          bVar43 = false;
          goto code_r0x000138eb;
        }
        puVar36 = puVar37 + -2;
        *(undefined2 *)(puVar37 + -2) = 0x3b42;
        uVar49 = FUN_1000_3607();
        bVar7 = (byte)uVar49;
        if (bVar43) {
          puVar28 = puVar36 + -2;
          *(undefined2 *)(puVar36 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar50 = CONCAT22((int)((ulong)uVar49 >> 0x10),
                          CONCAT11((char)((ulong)uVar49 >> 8),(char)uVar49 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar38 = (undefined2 *)ZEXT24((undefined1 *)((int)puVar35 + -2));
      *(undefined2 *)((int)puVar35 + -2) = unaff_CS;
      iVar16 = CONCAT11(cVar17 - ((byte *)((int)in_BX + (int)unaff_SI))[0x23c9],
                        (char)((ulong)uVar49 >> 0x10) + bVar13 +
                        (0x1fd2 < uVar9 || CARRY2(uVar4 + 0xe02d,uVar5)));
      ((byte *)((int)unaff_BP + (int)puVar42))[0x5555] =
           ((byte *)((int)unaff_BP + (int)puVar42))[0x5555] + (char)uVar14;
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
  return CONCAT22(*(undefined2 *)((int)puVar35 + 10),*(undefined2 *)((int)puVar35 + 0xe));
}


