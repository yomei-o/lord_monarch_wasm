/* 1000:372f */

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

ulong FUN_1000_372f(void)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  code *pcVar6;
  byte bVar7;
  undefined2 in_AX;
  undefined2 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined2 uVar12;
  uint in_CX;
  uint uVar13;
  byte bVar14;
  undefined2 in_DX;
  char cVar17;
  undefined2 extraout_DX;
  uint uVar15;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar16;
  undefined2 in_BX;
  uint uVar18;
  uint uVar19;
  byte bVar20;
  int iVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined2 *puVar26;
  undefined1 *puVar27;
  undefined2 *puVar28;
  uint *puVar29;
  undefined1 *puVar30;
  uint *puVar31;
  uint *puVar32;
  uint *puVar33;
  uint *puVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  undefined4 in_ESP;
  uint *puVar37;
  uint unaff_BP;
  int iVar38;
  undefined1 *puVar39;
  uint *unaff_SI;
  int iVar40;
  uint unaff_DI;
  uint *puVar41;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar42;
  byte in_AF;
  undefined1 uVar43;
  bool bVar44;
  bool bVar45;
  byte in_TF;
  byte in_IF;
  bool bVar46;
  char cVar47;
  byte in_NT;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar48;
  ulong uVar49;
  undefined1 *puVar50;
  uint uVar5;
  
  puVar37 = (uint *)((int)unaff_SI + unaff_BP + 0x55);
  uVar13 = *puVar37;
  *puVar37 = *puVar37 >> 0xd;
  puVar37 = unaff_SI;
  iVar16 = (in_CX & 3) - (*puVar37 & 3);
  *puVar37 = *puVar37 + (uint)(0 < iVar16) * iVar16;
  uVar18 = CONCAT11(((char)((uint)in_BX >> 8) - (char)in_AX) - ((uVar13 >> 0xc & 1) != 0),
                    (char)in_BX);
  LOCK();
  uVar13 = *(uint *)(unaff_BP - 0x2e);
  *(uint *)(unaff_BP - 0x2e) = unaff_DI;
  UNLOCK();
  iVar21 = (int)in_ESP;
  uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
  *(undefined2 *)(iVar21 + -2) = in_AX;
  *(uint *)(iVar21 + -4) = in_CX;
  *(undefined2 *)(iVar21 + -6) = in_DX;
  *(uint *)(iVar21 + -8) = uVar18;
  *(int *)(iVar21 + -10) = iVar21;
  *(uint *)(iVar21 + -0xc) = unaff_BP;
  *(undefined2 *)(iVar21 + -0xe) = unaff_SI;
  *(uint *)(iVar21 + -0x10) = uVar13;
  puVar37 = (uint *)(unaff_BP + (int)unaff_SI);
  uVar19 = *puVar37;
  uVar15 = *puVar37;
  *puVar37 = *puVar37 - unaff_BP;
  uVar9 = *puVar37;
  uVar4 = *puVar37;
  uVar5 = *puVar37;
  *(undefined2 *)(iVar21 + -0x12) = unaff_CS;
  *(uint *)(iVar21 + -0x14) =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar15,unaff_BP) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)uVar9 < 0) * 0x80 |
       (uint)(uVar4 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT(uVar5 & 0xff) & 1U) == 0) * 4 | (uint)(uVar19 < unaff_BP);
  puVar22 = (undefined1 *)(iVar21 + -0x16);
  *(undefined2 *)(iVar21 + -0x16) = 0x3743;
  FUN_1000_3c36();
  puVar23 = puVar22 + -2;
  *(undefined2 *)(puVar22 + -2) = 0x3746;
  uVar48 = func_0x0001a7d4();
  *(int *)(puVar23 + -2) = (int)uVar48;
  cVar17 = *(char *)(uVar13 + 0xc070);
  *(undefined2 *)(puVar23 + -4) = unaff_ES;
  *(int *)(puVar23 + -6) =
       CONCAT11((char)((ulong)uVar48 >> 8),(char)uVar48 + cVar17 + -0x25) + 0x534f;
  *(uint *)(puVar23 + -8) = in_CX;
  *(int *)(puVar23 + -10) = (int)((ulong)uVar48 >> 0x10);
  *(uint *)(puVar23 + -0xc) = uVar18;
  *(int *)((int)puVar23 + -0xe) = (int)puVar23 + -4;
  *(uint *)(puVar23 + -0x10) = unaff_BP;
  *(uint **)(puVar23 + -0x12) = unaff_SI;
  puVar39 = puVar23 + -0x14;
  *(uint *)(puVar23 + -0x14) = uVar13;
  iVar16 = -*unaff_SI;
  uVar15 = (uint)(puVar23 + -0x14 < (undefined1 *)*unaff_SI);
  uVar19 = uVar18 + *(uint *)(uVar18 + uVar13);
  bVar42 = CARRY2(uVar18,*(uint *)(uVar18 + uVar13)) || CARRY2(uVar19,uVar15);
  uVar19 = uVar19 + uVar15;
  puVar10 = puVar23 + iVar16 + -0x17;
  *(undefined2 *)(puVar23 + iVar16 + -0x17) = 0x375c;
  uVar48 = func_0x0001ac4f();
  uVar15 = (uint)((ulong)uVar48 >> 0x10);
  if (!bVar42) {
    bVar7 = *(byte *)(uVar13 + 0xd27e);
    uVar19 = CONCAT11((char)(uVar19 >> 8),bVar7);
    in_CX = 5;
    if ((bVar7 != 0) && ((bVar7 < 0xc || (0xf < bVar7)))) {
      in_CX = 4;
      uVar13 = uVar13 | *(uint *)(uVar19 + uVar13 + 0xb);
      if (bVar7 != 5) {
        in_CX = 8;
      }
      *(uint *)(puVar10 + -2) = (uint)uVar48 | 0x6c72;
      *(uint *)(puVar10 + -4) = uVar15;
      uVar19 = uVar15;
      puVar10 = puVar10 + -4;
    }
  }
  *(uint *)(puVar10 + -2) = in_CX;
  *(uint *)(puVar10 + -4) = uVar15;
  puVar24 = puVar10 + -6;
  *(undefined2 *)(puVar10 + -6) = 0x3799;
  uVar48 = func_0x0001ae87();
  *(int *)(puVar24 + -2) = (int)uVar48;
  *(uint *)(puVar24 + -4) = uVar19;
  *(undefined2 *)(puVar24 + -6) = 9;
  *(int *)(puVar24 + -8) = (int)((ulong)uVar48 >> 0x10);
  *(undefined2 *)(puVar24 + -10) = 0x37a1;
  uVar48 = func_0x0001af48();
  if (*(uint *)(puVar23 + -0x1e) <= (uint)uVar48) {
    uVar19 = *(uint *)(puVar23 + -0x20);
    uVar48 = CONCAT22(*(undefined2 *)(puVar23 + -0x24),*(undefined2 *)(puVar23 + -0x1e));
  }
  *(uint *)(byte *)(uVar19 + (int)unaff_SI) =
       *(int *)(byte *)(uVar19 + (int)unaff_SI) + (int)((ulong)uVar48 >> 0x10) +
       (uint)((uint)uVar48 < *(uint *)(puVar23 + -0x16));
  uVar9 = (uint)(byte)((char)uVar48 + (char)((ulong)uVar48 >> 8) * 't');
  puVar23[uVar13 - 0x3b6] = puVar23[uVar13 - 0x3b6] + -1;
  iVar16 = *(int *)(puVar23 + -0x1a);
  uVar12 = *(undefined2 *)(puVar23 + -0x1c);
  uVar15 = uVar9 - *(uint *)(puVar23 + -6);
  uVar43 = uVar15 == 0;
  if (uVar9 < *(uint *)(puVar23 + -6)) {
    uVar15 = unaff_SI[3] + uVar9 * -2;
    uVar43 = uVar15 == 0;
    if (uVar9 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar16;
      unaff_SI[4] = uVar19;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      puVar25 = puVar23 + -0x16;
      *(undefined2 *)(puVar23 + -0x16) = 0x37e2;
      func_0x0001ab65();
      puVar10 = puVar25 + -2;
      *(undefined2 *)(puVar25 + -2) = 0x37e5;
      bVar7 = func_0x0001b496();
      if (!(bool)uVar43) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar7;
        if ((byte)unaff_SI[5] == 0xb) {
          puVar26 = (undefined2 *)(puVar10 + -2);
          puVar10 = puVar10 + -2;
          *puVar26 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar10 + 10),*(undefined2 *)(puVar10 + 0xe));
    }
  }
  puVar28 = (undefined2 *)(puVar23 + -0x16);
  *(uint *)(puVar23 + -0x16) = unaff_DS;
  puVar37 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar49 = CONCAT22(uVar12,CONCAT11(((int)uVar15 < 0) << 7 | uVar43 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar15 & 0xff) & 1U) == 0) << 2,(byte)*puVar37)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar37;
  if (uVar13 != 0xffff) {
    iVar40 = *(int *)(puVar23 + -0x14);
    iVar38 = *(int *)(puVar23 + -0x12);
    uVar8 = *(undefined2 *)(puVar23 + -8);
    pcVar1 = (char *)(iVar38 + iVar40);
    *pcVar1 = *pcVar1 + (byte)uVar8;
    iVar16 = *(int *)(puVar23 + -6);
    pbVar2 = (byte *)(iVar38 + iVar40);
    *pbVar2 = *pbVar2 ^ (byte)uVar8;
    *(int *)(iVar16 + -2) = iVar38;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar13 = iVar16 + *(int *)(byte *)((int)unaff_SI + uVar19 + 0xb44);
  puVar41 = (uint *)0x0;
code_r0x0001387f:
  uVar15 = (uint)(uVar49 >> 0x10);
  uVar9 = CONCAT11((char)(uVar49 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar7 = (byte)uVar9;
  *(byte *)(unaff_SI + 5) = bVar7;
  swi(4);
  pcVar1 = puVar39 + (int)unaff_SI;
  *pcVar1 = *pcVar1 + bVar7;
  if ((POPCOUNT(*pcVar1) & 1U) != 0) {
    pbVar2 = (byte *)((int)unaff_SI + uVar19 + 0x33);
    bVar7 = *pbVar2;
    bVar14 = (byte)(uVar49 >> 0x10);
    bVar20 = *pbVar2;
    cVar17 = (char)(uVar49 >> 0x18) + *(byte *)(uVar19 + (int)unaff_SI);
    *(byte *)(puVar41 + 0x39) = (byte)puVar41[0x39] - cVar17;
    (puVar39 + (int)puVar41)[-0x178e] =
         (puVar39 + (int)puVar41)[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar17,bVar14 + bVar20),
                         (uVar9 + 0x5556) - (uint)CARRY1(bVar14,bVar7)) % (ulong)unaff_SI[0x410]);
    *(int *)(puVar39 + (int)puVar41) = *(int *)(puVar39 + (int)puVar41) >> 0x10;
    return CONCAT22(puVar28[1],*puVar28);
  }
  puVar34 = unaff_SI;
  if (*pcVar1 == '\0') goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar42 = CARRY1((byte)uVar19,puVar39[(int)unaff_SI]);
  uVar19 = CONCAT11((char)(uVar19 >> 8),(byte)uVar19 + puVar39[(int)unaff_SI]);
  puVar11 = (undefined1 *)puVar28;
code_r0x000138eb:
  *(undefined2 *)(puVar11 + -2) = unaff_SS;
  if (!bVar42) {
    puVar37 = puVar41;
    puVar41 = (uint *)((int)puVar41 + 1);
    *(byte *)puVar37 = 0x30;
    uVar9 = CONCAT11(0xaa,puVar39[(int)puVar41] | 0x30) ^ 0x8a0;
    *(uint *)(puVar11 + -2) = uVar19;
    *(uint *)(puVar11 + -4) = uVar9;
    uVar19 = unaff_SI[0x15];
    uVar15 = (uVar15 | 0x3000) - *(int *)(byte *)(uVar19 + (int)unaff_SI);
    bVar20 = (byte)(uVar9 >> 8);
    bVar7 = (char)uVar9 + 8;
    if (bVar7 != *(byte *)(uVar19 + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar11 + -6) = CONCAT11(bVar20,bVar7);
    *(uint *)(puVar11 + -8) = uVar13;
    *(uint *)(puVar11 + -10) = uVar15;
    *(uint *)(puVar11 + -0xc) = uVar19;
    *(undefined1 **)(puVar11 + -0xe) = puVar11 + -4;
    *(undefined1 **)(puVar11 + -0x10) = puVar39;
    *(uint **)(puVar11 + -0x12) = unaff_SI;
    *(uint **)(puVar11 + -0x14) = puVar41;
    uVar9 = *puVar41;
    cVar17 = (char)(uVar13 >> 8);
    bVar14 = cVar17 + bVar7;
    uVar13 = CONCAT11(bVar14,(char)uVar13);
    puVar39 = (undefined1 *)0x874;
    if (SCARRY1(cVar17,bVar7)) {
      puVar28 = *(undefined2 **)(puVar11 + -0x14);
      puVar34 = *(uint **)(byte *)((int)puVar41 + (uVar19 - 0x18));
      puVar37 = puVar34 + 0x43a;
      uVar4 = *puVar37;
      *puVar37 = *puVar37 + 0x809;
      uVar13 = 0x4379;
      puVar34[0x43a] =
           puVar34[0x43a] + CONCAT11(bVar20 | (byte)uVar9,bVar7 | bVar14) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar11 + -0x16) = 0x874;
      puVar28 = (undefined2 *)(puVar11 + -0x18);
      *(undefined2 *)(puVar11 + -0x18) = 0x874;
      puVar34 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar41 + 0x55) = *(int *)(byte *)((int)puVar41 + 0x55) + uVar15;
    unaff_SI = (uint *)((int)puVar34 + 1);
    out((byte)*puVar34,uVar15);
    uVar19 = CONCAT11((byte)(uVar19 >> 8) & (puVar39 + (int)unaff_SI)[0x11],(char)uVar19);
    bVar20 = (byte)uVar15;
    cVar47 = SBORROW1(bVar20,(byte)puVar34[0x39]);
    bVar7 = (byte)puVar34[0x39];
    cVar17 = (char)(bVar20 - bVar7) < '\0';
    bVar42 = bVar20 == bVar7;
    puVar29 = (uint *)((int)puVar28 + -2);
    *(undefined2 *)((int)puVar28 + -2) = 0x396b;
    bVar7 = func_0x0001b3ed();
    iVar16 = extraout_DX_00;
    if (!bVar42) {
      *(byte *)(puVar34 + 6) = bVar7;
      *(undefined2 *)((int)puVar29 + -2) = 0x3973;
      puVar29 = (uint *)((int)puVar29 + -2);
      bVar7 = func_0x0001b617();
      iVar16 = extraout_DX_01;
    }
    if (cVar47 != cVar17) {
      iVar16 = iVar16 + 1;
      puVar29[-1] = (uint)puVar41;
      puVar29[-2] = iVar16;
      puVar29[-3] = CONCAT11((char)(uVar13 >> 8),8);
      puVar29[-4] = uVar19;
      if (iVar16 == 0) {
LAB_1000_39c7:
        pcVar6 = (code *)swi(1);
        uVar49 = (*pcVar6)();
        return uVar49;
      }
      (puVar39 + (int)puVar41)[0x6e] = (puVar39 + (int)puVar41)[0x6e] | (byte)((uint)iVar16 >> 8);
code_r0x00013985:
      pbVar2 = (byte *)((int)puVar41 + uVar19 + 0x12);
      *(byte **)pbVar2 = (byte *)((int)puVar41 + *(int *)pbVar2 + 2);
      puVar30 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar30 + -2) = 0x399f;
      func_0x00018e51();
      pcVar6 = (code *)swi(3);
      uVar49 = (*pcVar6)();
      return uVar49;
    }
    in_AF = 9 < ((bVar7 ^ puVar39[(int)unaff_SI]) & 0xf) | in_AF;
    bVar7 = (bVar7 ^ puVar39[(int)unaff_SI]) + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar29;
    bVar42 = bVar7 < (byte)(puVar39 + (int)unaff_SI)[-0x74a1] ||
             bVar7 == (puVar39 + (int)unaff_SI)[-0x74a1];
    puVar37 = (uint *)CONCAT22(uVar8,puVar29);
    *puVar29 = 0x39ba;
    puVar50 = (undefined1 *)FUN_1000_a1b8();
    puVar10 = (undefined1 *)puVar50;
    if (bVar42) {
      if (uVar13 == 1) {
        do {
          iVar16 = 0x40;
          puVar11 = puVar10;
          do {
            uVar13 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar34 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar37 = puVar37 + -2;
              *puVar37 = unaff_DS;
              bVar7 = (byte)puVar11 | 0x17;
              bVar20 = (byte)((uint)puVar11 >> 8);
              if (bVar20 == (byte)unaff_SI[6]) {
                puVar11 = (undefined1 *)CONCAT11(bVar7 / 0x5e,bVar7 % 0x5e);
                puVar34 = puVar41;
                goto code_r0x00013a16;
              }
              uVar13 = CONCAT11(bVar20 & puVar39[(int)unaff_SI],(byte)puVar11) | 0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar16 >> 8);
              puVar39[(int)puVar41] = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(puVar39 + 4);
              puVar11 = (undefined1 *)*(uint *)puVar37;
              puVar37 = (uint *)CONCAT22((int)((ulong)puVar37 >> 0x10),(uint *)puVar37 + 1);
              puVar34 = unaff_SI + 8;
              puVar41 = unaff_SI;
            }
            iVar16 = iVar16 + -1;
            unaff_SI = puVar34;
          } while (iVar16 != 0);
          unaff_SI = (uint *)*(uint *)puVar37;
          puVar37 = (uint *)CONCAT22((int)((ulong)puVar37 >> 0x10),(uint *)puVar37 + 1);
          puVar34 = puVar41;
code_r0x00013a16:
          uVar8 = (undefined2)((ulong)puVar37 >> 0x10);
          puVar31 = (uint *)puVar37;
          if (0x1ef < uVar13) goto code_r0x00013a1c;
          (puVar39 + (int)puVar34)[0x59] = (puVar39 + (int)puVar34)[0x59] | (byte)uVar13;
          bVar7 = *(byte *)(uVar13 + puVar31[1]);
          puVar31[1] = (uint)unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar13 + ((byte)((char)puVar39 + 1U) < bVar7);
          puVar10 = (undefined1 *)CONCAT11((char)((uint)puVar39 >> 8),(char)puVar39 + -0x3b);
          puVar41 = (uint *)puVar31[1];
          puVar37 = (uint *)CONCAT22(uVar8,puVar31 + 2);
          unaff_SI = (uint *)0xc800;
          puVar39 = puVar11;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)puVar50 >> 0x10),(char)puVar50);
    puVar3 = unaff_SI;
    bVar42 = CARRY2(*puVar3,(uint)puVar10);
    *puVar3 = (uint)(puVar10 + *puVar3);
    bVar45 = (int)*puVar3 < 0;
    bVar44 = *puVar3 == 0;
    bVar7 = POPCOUNT(*puVar3 & 0xff);
    uVar13 = uVar13 - 1;
    if (uVar13 == 0 || bVar44) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  uVar19 = uVar19 + 1;
  puVar10 = puVar11 + -4;
  *(undefined2 *)(puVar11 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar15;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar10 = puVar36;
  if (bVar42) {
    puVar10 = puVar36 + -2;
    *(undefined2 *)(puVar36 + -2) = 0x3b67;
    uVar49 = func_0x000137e6();
    bVar7 = (byte)uVar49;
    if (bVar42) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar49;
  }
  *(undefined1 **)(puVar10 + -2) = puVar39;
  puVar36 = puVar10 + -4;
  *(undefined1 **)(puVar10 + -4) = puVar39;
  pbVar2 = (byte *)(uVar19 + (int)unaff_SI);
  bVar7 = (byte)(uVar49 >> 8);
  bVar42 = CARRY1(*pbVar2,bVar7);
  *pbVar2 = *pbVar2 + bVar7;
  uVar19 = uVar19 - 1;
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar42 = bVar7 < 0x10;
  bVar46 = SBORROW1(bVar7,'\x10');
  bVar45 = (char)(bVar7 - 0x10) < '\0';
  bVar44 = bVar7 == 0x10;
  if (!bVar42) {
    if (7 < bVar7) {
      bVar46 = SBORROW1(bVar7,'\f');
      bVar45 = (char)(bVar7 - 0xc) < '\0';
      bVar44 = bVar7 == 0xc;
      bVar42 = true;
      if (bVar7 < 0xc) goto LAB_1000_383e;
    }
    if (bVar7 != 0) {
      bVar46 = SBORROW1(bVar7,'\x05');
      bVar45 = (char)(bVar7 - 5) < '\0';
      bVar44 = bVar7 == 5;
      bVar42 = true;
      if (bVar7 < 5) goto LAB_1000_383e;
    }
    bVar42 = bVar7 < 5;
    bVar46 = SBORROW1(bVar7,'\x05');
    bVar45 = (char)(bVar7 - 5) < '\0';
    bVar44 = bVar7 == 5;
    if (!bVar44) {
      uVar13 = CONCAT11((puVar39 + (int)puVar41)[-0x80],0xb);
      pbVar2 = (byte *)(uVar19 + (int)unaff_SI);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      puVar28 = (undefined2 *)(puVar10 + -2);
      *(undefined2 *)(puVar10 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(uVar19 + (int)unaff_SI) = *(byte *)(uVar19 + (int)unaff_SI) & (byte)uVar13;
      LOCK();
      uVar43 = puVar39[0x72];
      puVar39[0x72] = (char)((uint)extraout_DX >> 8);
      uVar15 = CONCAT11(uVar43,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar42) {
    *(undefined2 *)(puVar10 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar44 && bVar46 == bVar45) {
    return CONCAT22(*(undefined2 *)(puVar39 + 10),*(undefined2 *)(puVar39 + 0xe));
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar7 ^ 0xf8) & 0xf) | in_AF;
  pbVar2 = (byte *)((int)puVar41 + uVar19 + 0x854);
  *pbVar2 = *pbVar2 & 0xb;
  uVar43 = *pbVar2 == 0;
  puVar27 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  puVar28 = (undefined2 *)(puVar27 + -2);
  *(undefined2 *)(puVar27 + -2) = 0x387a;
  uVar49 = func_0x0001b476();
  if (!(bool)uVar43) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar49;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar31;
  *(longdouble *)(uVar13 + (int)puVar34) = in_ST0;
  puVar37 = (uint *)CONCAT22(uVar8,(uint *)(puVar31[1] + -2));
  *(undefined2 *)(puVar31[1] + -2) = unaff_ES;
  uVar19 = puVar34[2];
  puVar10 = (undefined1 *)(uint)*(byte *)((int)puVar34 + -0x79);
  bVar42 = (byte)iVar16 < (byte)puVar39[(int)unaff_SI];
  cVar17 = (byte)iVar16 - puVar39[(int)unaff_SI];
  uVar13 = CONCAT11((char)((uint)iVar16 >> 8),cVar17);
  bVar45 = cVar17 < '\0';
  bVar44 = cVar17 == '\0';
  bVar7 = POPCOUNT(cVar17);
  LOCK();
  puVar41 = *(uint **)(puVar39 + -0x2e);
  *(uint **)(puVar39 + -0x2e) = puVar34;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar44) {
    *(byte *)(uVar19 + (int)unaff_SI) = *(byte *)(uVar19 + (int)unaff_SI) + 1;
    puVar32 = (uint *)puVar37;
    puVar37 = (uint *)CONCAT22((int)((ulong)puVar37 >> 0x10),puVar32 + -1);
    puVar32[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar45 << 7 | bVar44 << 6 | in_AF << 4 | ((bVar7 & 1) == 0) << 2 | 2 |
                          bVar42,(char)puVar10)) {
      (puVar39 + (int)puVar41)[-0x54ee] = (puVar39 + (int)puVar41)[-0x54ee] | (byte)(uVar19 >> 8);
      puVar3 = puVar41;
      puVar41 = (uint *)((int)puVar41 + 1);
      *(byte *)puVar3 = (char)puVar10 + 0x3b;
      goto LAB_1000_3a63;
    }
    puVar39 = puVar39 + uVar13;
    pbVar2 = (byte *)((uVar19 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar3 = (uint *)(puVar39 + (int)puVar41 + 0x645);
    uVar15 = *puVar3;
    *puVar3 = *puVar3 - uVar13;
    bVar7 = ((char)(uVar19 >> 1) + (char)(uVar19 >> 2) + -0x10) - (uVar15 < uVar13) | 2;
    iVar16 = *(int *)(byte *)((int)puVar41 + 0x55);
code_r0x00013aab:
    puVar39[(int)unaff_SI] = puVar39[(int)unaff_SI] & bVar7;
    ((uint *)puVar37)[-1] = (uint)puVar39;
    puVar39[(int)unaff_SI] = puVar39[(int)unaff_SI] & (byte)uVar13;
    puVar34 = (uint *)0xf029;
    *(uint *)0xf029 = (uint)puVar39;
    if (iVar16 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      puVar39[(int)unaff_SI] = puVar39[(int)unaff_SI] | bVar7;
      pcVar6 = (code *)swi(1);
      uVar49 = (*pcVar6)();
      return uVar49;
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
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar19 >> 8);
    puVar33 = (uint *)puVar37;
    uVar8 = (undefined2)((ulong)puVar37 >> 0x10);
    puVar33[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + uVar19 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)puVar41);
    puVar41 = (uint *)puVar33[-1];
    unaff_SI = (uint *)*puVar33;
    puVar39 = (undefined1 *)puVar33[1];
    uVar13 = puVar33[5];
    uVar12 = puVar33[6];
    uVar19 = CONCAT11((char)(puVar33[3] >> 8),(byte)puVar33[3] | *(byte *)0x5d02) |
             *(uint *)(puVar39 + (int)puVar41 + 10);
    puVar33[6] = (uint)puVar41;
    pbVar2 = (byte *)((int)unaff_SI + uVar19 + 0x2c2);
    cVar47 = SCARRY1((char)uVar12,*pbVar2);
    bVar42 = (char)((char)uVar12 + *pbVar2) < '\0';
    puVar34 = puVar33 + 5;
    puVar33[5] = 0x3a83;
    uVar48 = func_0x00013e95();
    bVar7 = (byte)uVar48;
    out(0x6f,bVar7);
    *(undefined1 *)0x1108 = (char)uVar19;
    cVar17 = (char)((ulong)uVar48 >> 0x18);
    if (bVar42) {
      bVar20 = (byte)(uVar19 >> 8);
      puVar37 = (uint *)((int)puVar41 + -0x53);
      uVar4 = (uint)(bVar20 < (byte)(uVar13 >> 8));
      uVar15 = *puVar37;
      uVar9 = *puVar37;
      *puVar37 = uVar9 + 0xe02d + uVar4;
      cVar47 = puVar39[(int)puVar41];
      bVar20 = bVar20 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar48 >> 8);
      uVar19 = CONCAT11(bVar20,(char)uVar19);
      if ((char)bVar20 < '\0') {
        bVar42 = unaff_SI[3] < 1000;
        if (!bVar42) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar34 + -2) = 0x3b26;
          puVar34 = (uint *)((int)puVar34 + -2);
          uVar48 = func_0x00013966();
          if (!bVar42) goto LAB_1000_3b55_1;
        }
        puVar36 = (undefined1 *)((int)puVar34 + -2);
        *(undefined2 *)((int)puVar34 + -2) = 0x3b2d;
        uVar49 = FUN_1000_8cb7();
        uVar15 = (uint)(uVar49 >> 0x10);
        bVar42 = (byte)uVar49 < 0x5a;
        if (bVar42) {
          bVar42 = true;
          if ((byte)uVar49 < 0x50) goto LAB_1000_3b62;
          puVar11 = puVar36 + -2;
          *(undefined2 *)(puVar36 + -2) = 0x3b38;
          bVar42 = false;
          goto code_r0x000138eb;
        }
        puVar35 = puVar36 + -2;
        *(undefined2 *)(puVar36 + -2) = 0x3b42;
        uVar48 = FUN_1000_3607();
        bVar7 = (byte)uVar48;
        if (bVar42) {
          puVar10 = puVar35 + -2;
          *(undefined2 *)(puVar35 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar49 = CONCAT22((int)((ulong)uVar48 >> 0x10),
                          CONCAT11((char)((ulong)uVar48 >> 8),(char)uVar48 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar37 = (uint *)ZEXT24((undefined1 *)((int)puVar34 + -2));
      *(undefined2 *)((int)puVar34 + -2) = unaff_CS;
      iVar16 = CONCAT11(cVar17 - *(byte *)((int)unaff_SI + uVar19 + 0x23c9),
                        (char)((ulong)uVar48 >> 0x10) + cVar47 +
                        (0x1fd2 < uVar15 || CARRY2(uVar9 + 0xe02d,uVar4)));
      (puVar39 + (int)puVar41)[0x5555] = (puVar39 + (int)puVar41)[0x5555] + (char)uVar13;
      goto code_r0x00013aab;
    }
    if (cVar47 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar17;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar19 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar34 + 10),*(undefined2 *)((int)puVar34 + 0xe));
}


