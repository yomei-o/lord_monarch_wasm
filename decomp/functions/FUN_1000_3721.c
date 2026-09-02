/* 1000:3721 */

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

ulong FUN_1000_3721(void)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  code *pcVar6;
  byte in_AL;
  byte bVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint in_CX;
  uint uVar12;
  byte bVar13;
  undefined2 in_DX;
  char cVar16;
  undefined2 extraout_DX;
  uint uVar14;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar15;
  uint *in_BX;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  undefined2 *puVar20;
  undefined2 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  undefined1 *puVar26;
  undefined2 *puVar27;
  undefined1 *puVar28;
  undefined2 *puVar29;
  undefined2 *puVar30;
  undefined2 *puVar31;
  undefined2 *puVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined2 *in_ESP;
  undefined2 uVar36;
  undefined2 *puVar35;
  uint unaff_BP;
  int iVar37;
  undefined1 *puVar38;
  int unaff_SI;
  uint *puVar39;
  int iVar40;
  uint *puVar41;
  uint unaff_DI;
  uint *puVar42;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
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
  undefined4 uVar49;
  ulong uVar50;
  undefined1 *puVar51;
  uint uVar5;
  
  puVar39 = (uint *)((unaff_SI - in_BX[0x318]) - (uint)(in_AL < 2 || (byte)(in_AL - 2) < in_CF));
  puVar20 = (undefined2 *)in_ESP;
  uVar8 = *puVar20;
  uVar36 = (undefined2)((ulong)in_ESP >> 0x10);
  *in_BX = *in_BX ^ unaff_BP;
  puVar3 = (uint *)((int)puVar39 + unaff_BP + 0x55);
  uVar12 = *puVar3;
  *puVar3 = *puVar3 >> 0xd;
  puVar3 = puVar39;
  iVar15 = (in_CX & 3) - (*puVar3 & 3);
  *puVar3 = *puVar3 + (uint)(0 < iVar15) * iVar15;
  uVar17 = CONCAT11(((char)((uint)in_BX >> 8) - (char)uVar8) - ((uVar12 >> 0xc & 1) != 0),
                    (char)in_BX);
  LOCK();
  uVar12 = *(uint *)(unaff_BP - 0x2e);
  *(uint *)(unaff_BP - 0x2e) = unaff_DI;
  UNLOCK();
  *puVar20 = uVar8;
  puVar20[-1] = in_CX;
  puVar20[-2] = in_DX;
  puVar20[-3] = uVar17;
  puVar20[-4] = puVar20 + 1;
  puVar20[-5] = unaff_BP;
  puVar20[-6] = puVar39;
  puVar20[-7] = uVar12;
  puVar3 = (uint *)(unaff_BP + (int)puVar39);
  uVar18 = *puVar3;
  uVar14 = *puVar3;
  *puVar3 = *puVar3 - unaff_BP;
  uVar9 = *puVar3;
  uVar4 = *puVar3;
  uVar5 = *puVar3;
  puVar20[-8] = unaff_CS;
  puVar20[-9] = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar14,unaff_BP) * 0x800 |
                (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                (uint)((int)uVar9 < 0) * 0x80 | (uint)(uVar4 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10
                | (uint)((POPCOUNT(uVar5 & 0xff) & 1U) == 0) * 4 | (uint)(uVar18 < unaff_BP);
  puVar21 = puVar20 + -10;
  puVar20[-10] = 0x3743;
  FUN_1000_3c36();
  puVar22 = (undefined1 *)((int)puVar21 + -2);
  *(undefined2 *)((int)puVar21 + -2) = 0x3746;
  uVar49 = func_0x0001a7d4();
  *(int *)(puVar22 + -2) = (int)uVar49;
  cVar16 = *(char *)(uVar12 + 0xc070);
  *(undefined2 *)(puVar22 + -4) = unaff_ES;
  *(int *)(puVar22 + -6) =
       CONCAT11((char)((ulong)uVar49 >> 8),(char)uVar49 + cVar16 + -0x25) + 0x534f;
  *(uint *)(puVar22 + -8) = in_CX;
  *(int *)(puVar22 + -10) = (int)((ulong)uVar49 >> 0x10);
  *(uint *)(puVar22 + -0xc) = uVar17;
  *(undefined1 **)(puVar22 + -0xe) = puVar22 + -4;
  *(uint *)(puVar22 + -0x10) = unaff_BP;
  *(uint **)(puVar22 + -0x12) = puVar39;
  puVar38 = puVar22 + -0x14;
  *(uint *)(puVar22 + -0x14) = uVar12;
  iVar15 = -*puVar39;
  uVar14 = (uint)(puVar22 + -0x14 < (undefined1 *)*puVar39);
  uVar18 = uVar17 + *(uint *)(uVar17 + uVar12);
  bVar43 = CARRY2(uVar17,*(uint *)(uVar17 + uVar12)) || CARRY2(uVar18,uVar14);
  uVar18 = uVar18 + uVar14;
  puVar10 = puVar22 + iVar15 + -0x17;
  *(undefined2 *)(puVar22 + iVar15 + -0x17) = 0x375c;
  uVar49 = func_0x0001ac4f();
  uVar14 = (uint)((ulong)uVar49 >> 0x10);
  if (!bVar43) {
    bVar7 = *(byte *)(uVar12 + 0xd27e);
    uVar18 = CONCAT11((char)(uVar18 >> 8),bVar7);
    in_CX = 5;
    if ((bVar7 != 0) && ((bVar7 < 0xc || (0xf < bVar7)))) {
      in_CX = 4;
      uVar12 = uVar12 | *(uint *)(uVar18 + uVar12 + 0xb);
      if (bVar7 != 5) {
        in_CX = 8;
      }
      *(uint *)(puVar10 + -2) = (uint)uVar49 | 0x6c72;
      *(uint *)(puVar10 + -4) = uVar14;
      uVar18 = uVar14;
      puVar10 = puVar10 + -4;
    }
  }
  *(uint *)(puVar10 + -2) = in_CX;
  *(uint *)(puVar10 + -4) = uVar14;
  puVar23 = puVar10 + -6;
  *(undefined2 *)(puVar10 + -6) = 0x3799;
  uVar49 = func_0x0001ae87();
  *(int *)(puVar23 + -2) = (int)uVar49;
  *(uint *)(puVar23 + -4) = uVar18;
  *(undefined2 *)(puVar23 + -6) = 9;
  *(int *)(puVar23 + -8) = (int)((ulong)uVar49 >> 0x10);
  *(undefined2 *)(puVar23 + -10) = 0x37a1;
  uVar49 = func_0x0001af48();
  if (*(uint *)(puVar22 + -0x1e) <= (uint)uVar49) {
    uVar18 = *(uint *)(puVar22 + -0x20);
    uVar49 = CONCAT22(*(undefined2 *)(puVar22 + -0x24),*(undefined2 *)(puVar22 + -0x1e));
  }
  *(uint *)(byte *)(uVar18 + (int)puVar39) =
       *(int *)(byte *)(uVar18 + (int)puVar39) + (int)((ulong)uVar49 >> 0x10) +
       (uint)((uint)uVar49 < *(uint *)(puVar22 + -0x16));
  uVar9 = (uint)(byte)((char)uVar49 + (char)((ulong)uVar49 >> 8) * 't');
  puVar22[uVar12 - 0x3b6] = puVar22[uVar12 - 0x3b6] + -1;
  iVar15 = *(int *)(puVar22 + -0x1a);
  uVar8 = *(undefined2 *)(puVar22 + -0x1c);
  uVar14 = uVar9 - *(uint *)(puVar22 + -6);
  uVar44 = uVar14 == 0;
  if (uVar9 < *(uint *)(puVar22 + -6)) {
    uVar14 = puVar39[3] + uVar9 * -2;
    uVar44 = uVar14 == 0;
    if (uVar9 * 2 <= puVar39[3]) {
      *(byte *)(puVar39 + 5) = (byte)iVar15;
      puVar39[4] = uVar18;
      *(byte *)((int)puVar39 + 0xf) = 4;
      puVar24 = puVar22 + -0x16;
      *(undefined2 *)(puVar22 + -0x16) = 0x37e2;
      func_0x0001ab65();
      puVar10 = puVar24 + -2;
      *(undefined2 *)(puVar24 + -2) = 0x37e5;
      bVar7 = func_0x0001b496();
      if (!(bool)uVar44) {
code_r0x000137e7:
        *(byte *)((int)puVar39 + 0xb) = bVar7;
        if ((byte)puVar39[5] == 0xb) {
          puVar25 = (undefined2 *)(puVar10 + -2);
          puVar10 = puVar10 + -2;
          *puVar25 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar10 + 10),*(undefined2 *)(puVar10 + 0xe));
    }
  }
  puVar32 = (undefined2 *)(puVar22 + -0x16);
  *(undefined2 *)(puVar22 + -0x16) = unaff_DS;
  puVar3 = puVar39;
  puVar39 = (uint *)((int)puVar39 + 1);
  uVar50 = CONCAT22(uVar8,CONCAT11(((int)uVar14 < 0) << 7 | uVar44 << 6 | in_AF << 4 |
                                   ((POPCOUNT(uVar14 & 0xff) & 1U) == 0) << 2,(byte)*puVar3)) |
           0x300;
  *(byte *)puVar39 = (byte)*puVar39 & (byte)*puVar3;
  if (uVar12 != 0xffff) {
    iVar40 = *(int *)(puVar22 + -0x14);
    iVar37 = *(int *)(puVar22 + -0x12);
    uVar8 = *(undefined2 *)(puVar22 + -8);
    pcVar1 = (char *)(iVar37 + iVar40);
    *pcVar1 = *pcVar1 + (byte)uVar8;
    iVar15 = *(int *)(puVar22 + -6);
    pbVar2 = (byte *)(iVar37 + iVar40);
    *pbVar2 = *pbVar2 ^ (byte)uVar8;
    *(int *)(iVar15 + -2) = iVar37;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar12 = iVar15 + *(int *)(byte *)((int)puVar39 + uVar18 + 0xb44);
  puVar42 = (uint *)0x0;
code_r0x0001387f:
  uVar14 = (uint)(uVar50 >> 0x10);
  uVar9 = CONCAT11((char)(uVar50 >> 8),(byte)puVar39[5]) & 0xffd0 | 5;
  bVar7 = (byte)uVar9;
  *(byte *)(puVar39 + 5) = bVar7;
  swi(4);
  pcVar1 = puVar38 + (int)puVar39;
  *pcVar1 = *pcVar1 + bVar7;
  if ((POPCOUNT(*pcVar1) & 1U) != 0) {
    pbVar2 = (byte *)((int)puVar39 + uVar18 + 0x33);
    bVar7 = *pbVar2;
    bVar13 = (byte)(uVar50 >> 0x10);
    bVar19 = *pbVar2;
    cVar16 = (char)(uVar50 >> 0x18) + *(byte *)(uVar18 + (int)puVar39);
    *(byte *)(puVar42 + 0x39) = (byte)puVar42[0x39] - cVar16;
    (puVar38 + (int)puVar42)[-0x178e] =
         (puVar38 + (int)puVar42)[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar16,bVar13 + bVar19),
                         (uVar9 + 0x5556) - (uint)CARRY1(bVar13,bVar7)) % (ulong)puVar39[0x410]);
    *(int *)(puVar38 + (int)puVar42) = *(int *)(puVar38 + (int)puVar42) >> 0x10;
    return CONCAT22(puVar32[1],*puVar32);
  }
  puVar41 = puVar39;
  if (*pcVar1 == '\0') goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)puVar39 + 0x31) = *(uint *)((int)puVar39 + 0x31) & (uint)puVar39;
  bVar43 = CARRY1((byte)uVar18,puVar38[(int)puVar39]);
  uVar18 = CONCAT11((char)(uVar18 >> 8),(byte)uVar18 + puVar38[(int)puVar39]);
  puVar11 = (undefined1 *)puVar32;
code_r0x000138eb:
  *(undefined2 *)(puVar11 + -2) = unaff_SS;
  if (!bVar43) {
    puVar3 = puVar42;
    puVar42 = (uint *)((int)puVar42 + 1);
    *(byte *)puVar3 = 0x30;
    uVar9 = CONCAT11(0xaa,puVar38[(int)puVar42] | 0x30) ^ 0x8a0;
    *(uint *)(puVar11 + -2) = uVar18;
    *(uint *)(puVar11 + -4) = uVar9;
    uVar18 = puVar39[0x15];
    uVar14 = (uVar14 | 0x3000) - *(int *)(byte *)(uVar18 + (int)puVar39);
    bVar19 = (byte)(uVar9 >> 8);
    bVar7 = (char)uVar9 + 8;
    if (bVar7 != *(byte *)(uVar18 + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar11 + -6) = CONCAT11(bVar19,bVar7);
    *(uint *)(puVar11 + -8) = uVar12;
    *(uint *)(puVar11 + -10) = uVar14;
    *(uint *)(puVar11 + -0xc) = uVar18;
    *(undefined1 **)(puVar11 + -0xe) = puVar11 + -4;
    *(undefined1 **)(puVar11 + -0x10) = puVar38;
    *(uint **)(puVar11 + -0x12) = puVar39;
    *(uint **)(puVar11 + -0x14) = puVar42;
    uVar9 = *puVar42;
    cVar16 = (char)(uVar12 >> 8);
    bVar13 = cVar16 + bVar7;
    uVar12 = CONCAT11(bVar13,(char)uVar12);
    puVar38 = (undefined1 *)0x874;
    if (SCARRY1(cVar16,bVar7)) {
      puVar32 = *(undefined2 **)(puVar11 + -0x14);
      puVar41 = *(uint **)(byte *)((int)puVar42 + (uVar18 - 0x18));
      puVar3 = puVar41 + 0x43a;
      uVar4 = *puVar3;
      *puVar3 = *puVar3 + 0x809;
      uVar12 = 0x4379;
      puVar41[0x43a] =
           puVar41[0x43a] + CONCAT11(bVar19 | (byte)uVar9,bVar7 | bVar13) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar11 + -0x16) = 0x874;
      puVar32 = (undefined2 *)(puVar11 + -0x18);
      *(undefined2 *)(puVar11 + -0x18) = 0x874;
      puVar41 = puVar39;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar42 + 0x55) = *(int *)(byte *)((int)puVar42 + 0x55) + uVar14;
    puVar39 = (uint *)((int)puVar41 + 1);
    out((byte)*puVar41,uVar14);
    uVar18 = CONCAT11((byte)(uVar18 >> 8) & (puVar38 + (int)puVar39)[0x11],(char)uVar18);
    bVar19 = (byte)uVar14;
    cVar48 = SBORROW1(bVar19,(byte)puVar41[0x39]);
    bVar7 = (byte)puVar41[0x39];
    cVar16 = (char)(bVar19 - bVar7) < '\0';
    bVar43 = bVar19 == bVar7;
    puVar27 = (undefined2 *)((int)puVar32 + -2);
    *(undefined2 *)((int)puVar32 + -2) = 0x396b;
    bVar7 = func_0x0001b3ed();
    iVar15 = extraout_DX_00;
    if (!bVar43) {
      *(byte *)(puVar41 + 6) = bVar7;
      *(undefined2 *)((int)puVar27 + -2) = 0x3973;
      puVar27 = (undefined2 *)((int)puVar27 + -2);
      bVar7 = func_0x0001b617();
      iVar15 = extraout_DX_01;
    }
    if (cVar48 != cVar16) {
      iVar15 = iVar15 + 1;
      puVar27[-1] = puVar42;
      puVar27[-2] = iVar15;
      puVar27[-3] = CONCAT11((char)(uVar12 >> 8),8);
      puVar27[-4] = uVar18;
      if (iVar15 == 0) {
LAB_1000_39c7:
        pcVar6 = (code *)swi(1);
        uVar50 = (*pcVar6)();
        return uVar50;
      }
      (puVar38 + (int)puVar42)[0x6e] = (puVar38 + (int)puVar42)[0x6e] | (byte)((uint)iVar15 >> 8);
code_r0x00013985:
      pbVar2 = (byte *)((int)puVar42 + uVar18 + 0x12);
      *(byte **)pbVar2 = (byte *)((int)puVar42 + *(int *)pbVar2 + 2);
      puVar28 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar28 + -2) = 0x399f;
      func_0x00018e51();
      pcVar6 = (code *)swi(3);
      uVar50 = (*pcVar6)();
      return uVar50;
    }
    in_AF = 9 < ((bVar7 ^ puVar38[(int)puVar39]) & 0xf) | in_AF;
    bVar7 = (bVar7 ^ puVar38[(int)puVar39]) + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar27;
    bVar43 = bVar7 < (byte)(puVar38 + (int)puVar39)[-0x74a1] ||
             bVar7 == (puVar38 + (int)puVar39)[-0x74a1];
    puVar35 = (undefined2 *)CONCAT22(uVar36,puVar27);
    *puVar27 = 0x39ba;
    puVar51 = (undefined1 *)FUN_1000_a1b8();
    puVar10 = (undefined1 *)puVar51;
    if (bVar43) {
      if (uVar12 == 1) {
        do {
          iVar15 = 0x40;
          puVar11 = puVar10;
          do {
            uVar12 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar41 = puVar39;
            if (((*puVar39 & 0x80) == 0) && ((puVar39[5] & 0x20) != 0)) {
              puVar35 = puVar35 + -2;
              *puVar35 = unaff_DS;
              bVar7 = (byte)puVar11 | 0x17;
              bVar19 = (byte)((uint)puVar11 >> 8);
              if (bVar19 == (byte)puVar39[6]) {
                puVar11 = (undefined1 *)CONCAT11(bVar7 / 0x5e,bVar7 % 0x5e);
                puVar41 = puVar42;
                goto code_r0x00013a16;
              }
              uVar12 = CONCAT11(bVar19 & puVar38[(int)puVar39],(byte)puVar11) | 0x17;
              *(byte *)(puVar39 + 0x3931) = (byte)puVar39[0x3931] ^ (byte)((uint)iVar15 >> 8);
              puVar38[(int)puVar42] = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(puVar38 + 4);
              puVar11 = (undefined1 *)*(undefined2 *)puVar35;
              puVar35 = (undefined2 *)
                        CONCAT22((int)((ulong)puVar35 >> 0x10),(undefined2 *)puVar35 + 1);
              puVar41 = puVar39 + 8;
              puVar42 = puVar39;
            }
            iVar15 = iVar15 + -1;
            puVar39 = puVar41;
          } while (iVar15 != 0);
          puVar39 = (uint *)*(undefined2 *)puVar35;
          puVar35 = (undefined2 *)CONCAT22((int)((ulong)puVar35 >> 0x10),(undefined2 *)puVar35 + 1);
          puVar41 = puVar42;
code_r0x00013a16:
          uVar8 = (undefined2)((ulong)puVar35 >> 0x10);
          puVar29 = (undefined2 *)puVar35;
          if (0x1ef < uVar12) goto code_r0x00013a1c;
          (puVar38 + (int)puVar41)[0x59] = (puVar38 + (int)puVar41)[0x59] | (byte)uVar12;
          bVar7 = *(byte *)(uVar12 + puVar29[1]);
          puVar29[1] = puVar39;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar12 + ((byte)((char)puVar38 + 1U) < bVar7);
          puVar10 = (undefined1 *)CONCAT11((char)((uint)puVar38 >> 8),(char)puVar38 + -0x3b);
          puVar42 = (uint *)puVar29[1];
          puVar35 = (undefined2 *)CONCAT22(uVar8,puVar29 + 2);
          puVar39 = (uint *)0xc800;
          puVar38 = puVar11;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)puVar51 >> 0x10),(char)puVar51);
    puVar3 = puVar39;
    bVar43 = CARRY2(*puVar3,(uint)puVar10);
    *puVar3 = (uint)(puVar10 + *puVar3);
    bVar46 = (int)*puVar3 < 0;
    bVar45 = *puVar3 == 0;
    bVar7 = POPCOUNT(*puVar3 & 0xff);
    uVar12 = uVar12 - 1;
    if (uVar12 == 0 || bVar45) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  uVar18 = uVar18 + 1;
  puVar10 = puVar11 + -4;
  *(undefined2 *)(puVar11 + -4) = 0x810;
  *(byte *)(puVar39 + 1) = (byte)puVar39[1] | (byte)uVar14;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar10 = puVar34;
  if (bVar43) {
    puVar10 = puVar34 + -2;
    *(undefined2 *)(puVar34 + -2) = 0x3b67;
    uVar50 = func_0x000137e6();
    bVar7 = (byte)uVar50;
    if (bVar43) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)puVar39 = (byte)*puVar39 | 1;
    return uVar50;
  }
  *(undefined1 **)(puVar10 + -2) = puVar38;
  puVar34 = puVar10 + -4;
  *(undefined1 **)(puVar10 + -4) = puVar38;
  pbVar2 = (byte *)(uVar18 + (int)puVar39);
  bVar7 = (byte)(uVar50 >> 8);
  bVar43 = CARRY1(*pbVar2,bVar7);
  *pbVar2 = *pbVar2 + bVar7;
  uVar18 = uVar18 - 1;
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
      uVar12 = CONCAT11((puVar38 + (int)puVar42)[-0x80],0xb);
      pbVar2 = (byte *)(uVar18 + (int)puVar39);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      puVar32 = (undefined2 *)(puVar10 + -2);
      *(undefined2 *)(puVar10 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(uVar18 + (int)puVar39) = *(byte *)(uVar18 + (int)puVar39) & (byte)uVar12;
      LOCK();
      uVar44 = puVar38[0x72];
      puVar38[0x72] = (char)((uint)extraout_DX >> 8);
      uVar14 = CONCAT11(uVar44,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar43) {
    *(undefined2 *)(puVar10 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar45 && bVar47 == bVar46) {
    return CONCAT22(*(undefined2 *)(puVar38 + 10),*(undefined2 *)(puVar38 + 0xe));
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar7 ^ 0xf8) & 0xf) | in_AF;
  pbVar2 = (byte *)((int)puVar42 + uVar18 + 0x854);
  *pbVar2 = *pbVar2 & 0xb;
  uVar44 = *pbVar2 == 0;
  puVar26 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  puVar32 = (undefined2 *)(puVar26 + -2);
  *(undefined2 *)(puVar26 + -2) = 0x387a;
  uVar50 = func_0x0001b476();
  if (!(bool)uVar44) {
    *(byte *)((int)puVar39 + 0xb) = (byte)uVar50;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar29;
  *(longdouble *)(uVar12 + (int)puVar41) = in_ST0;
  puVar35 = (undefined2 *)CONCAT22(uVar8,(undefined2 *)(puVar29[1] + -2));
  *(undefined2 *)(puVar29[1] + -2) = unaff_ES;
  uVar18 = puVar41[2];
  puVar10 = (undefined1 *)(uint)*(byte *)((int)puVar41 + -0x79);
  bVar43 = (byte)iVar15 < (byte)puVar38[(int)puVar39];
  cVar16 = (byte)iVar15 - puVar38[(int)puVar39];
  uVar12 = CONCAT11((char)((uint)iVar15 >> 8),cVar16);
  bVar46 = cVar16 < '\0';
  bVar45 = cVar16 == '\0';
  bVar7 = POPCOUNT(cVar16);
  LOCK();
  puVar42 = *(uint **)(puVar38 + -0x2e);
  *(uint **)(puVar38 + -0x2e) = puVar41;
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
    *(byte *)(uVar18 + (int)puVar39) = *(byte *)(uVar18 + (int)puVar39) + 1;
    puVar30 = (undefined2 *)puVar35;
    puVar35 = (undefined2 *)CONCAT22((int)((ulong)puVar35 >> 0x10),puVar30 + -1);
    puVar30[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar46 << 7 | bVar45 << 6 | in_AF << 4 | ((bVar7 & 1) == 0) << 2 | 2 |
                          bVar43,(char)puVar10)) {
      (puVar38 + (int)puVar42)[-0x54ee] = (puVar38 + (int)puVar42)[-0x54ee] | (byte)(uVar18 >> 8);
      puVar3 = puVar42;
      puVar42 = (uint *)((int)puVar42 + 1);
      *(byte *)puVar3 = (char)puVar10 + 0x3b;
      goto LAB_1000_3a63;
    }
    puVar38 = puVar38 + uVar12;
    pbVar2 = (byte *)((uVar18 >> 2) + (int)puVar39);
    *pbVar2 = *pbVar2 - 0x15;
    puVar3 = (uint *)(puVar38 + (int)puVar42 + 0x645);
    uVar14 = *puVar3;
    *puVar3 = *puVar3 - uVar12;
    bVar7 = ((char)(uVar18 >> 1) + (char)(uVar18 >> 2) + -0x10) - (uVar14 < uVar12) | 2;
    iVar15 = *(int *)(byte *)((int)puVar42 + 0x55);
code_r0x00013aab:
    puVar38[(int)puVar39] = puVar38[(int)puVar39] & bVar7;
    ((undefined2 *)puVar35)[-1] = puVar38;
    puVar38[(int)puVar39] = puVar38[(int)puVar39] & (byte)uVar12;
    puVar32 = (undefined2 *)0xf029;
    *(undefined2 *)0xf029 = puVar38;
    if (iVar15 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      puVar38[(int)puVar39] = puVar38[(int)puVar39] | bVar7;
      pcVar6 = (code *)swi(1);
      uVar50 = (*pcVar6)();
      return uVar50;
    }
    uVar18 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*puVar39 & 0x80) != 0) || (*(byte *)((int)puVar39 + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)puVar39[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar18 == (byte)puVar39[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar6 = (code *)swi(0x20);
    (*pcVar6)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar18 >> 8);
    puVar31 = (undefined2 *)puVar35;
    uVar36 = (undefined2)((ulong)puVar35 >> 0x10);
    puVar31[-1] = unaff_ES;
    pbVar2 = (byte *)((int)puVar39 + uVar18 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)puVar42);
    puVar42 = (uint *)puVar31[-1];
    puVar39 = (uint *)*puVar31;
    puVar38 = (undefined1 *)puVar31[1];
    uVar12 = puVar31[5];
    uVar8 = puVar31[6];
    uVar18 = CONCAT11((char)((uint)puVar31[3] >> 8),(byte)puVar31[3] | *(byte *)0x5d02) |
             *(uint *)(puVar38 + (int)puVar42 + 10);
    puVar31[6] = puVar42;
    pbVar2 = (byte *)((int)puVar39 + uVar18 + 0x2c2);
    cVar48 = SCARRY1((char)uVar8,*pbVar2);
    bVar43 = (char)((char)uVar8 + *pbVar2) < '\0';
    puVar32 = puVar31 + 5;
    puVar31[5] = 0x3a83;
    uVar49 = func_0x00013e95();
    bVar7 = (byte)uVar49;
    out(0x6f,bVar7);
    *(undefined1 *)0x1108 = (char)uVar18;
    cVar16 = (char)((ulong)uVar49 >> 0x18);
    if (bVar43) {
      bVar19 = (byte)(uVar18 >> 8);
      puVar3 = (uint *)((int)puVar42 + -0x53);
      uVar4 = (uint)(bVar19 < (byte)(uVar12 >> 8));
      uVar14 = *puVar3;
      uVar9 = *puVar3;
      *puVar3 = uVar9 + 0xe02d + uVar4;
      cVar48 = puVar38[(int)puVar42];
      bVar19 = bVar19 + (byte)puVar39[0x1015] | (byte)((ulong)uVar49 >> 8);
      uVar18 = CONCAT11(bVar19,(char)uVar18);
      if ((char)bVar19 < '\0') {
        bVar43 = puVar39[3] < 1000;
        if (!bVar43) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar32 + -2) = 0x3b26;
          puVar32 = (undefined2 *)((int)puVar32 + -2);
          uVar49 = func_0x00013966();
          if (!bVar43) goto LAB_1000_3b55_1;
        }
        puVar34 = (undefined1 *)((int)puVar32 + -2);
        *(undefined2 *)((int)puVar32 + -2) = 0x3b2d;
        uVar50 = FUN_1000_8cb7();
        uVar14 = (uint)(uVar50 >> 0x10);
        bVar43 = (byte)uVar50 < 0x5a;
        if (bVar43) {
          bVar43 = true;
          if ((byte)uVar50 < 0x50) goto LAB_1000_3b62;
          puVar11 = puVar34 + -2;
          *(undefined2 *)(puVar34 + -2) = 0x3b38;
          bVar43 = false;
          goto code_r0x000138eb;
        }
        puVar33 = puVar34 + -2;
        *(undefined2 *)(puVar34 + -2) = 0x3b42;
        uVar49 = FUN_1000_3607();
        bVar7 = (byte)uVar49;
        if (bVar43) {
          puVar10 = puVar33 + -2;
          *(undefined2 *)(puVar33 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar50 = CONCAT22((int)((ulong)uVar49 >> 0x10),
                          CONCAT11((char)((ulong)uVar49 >> 8),(char)uVar49 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar35 = (undefined2 *)ZEXT24((undefined1 *)((int)puVar32 + -2));
      *(undefined2 *)((int)puVar32 + -2) = unaff_CS;
      iVar15 = CONCAT11(cVar16 - *(byte *)((int)puVar39 + uVar18 + 0x23c9),
                        (char)((ulong)uVar49 >> 0x10) + cVar48 +
                        (0x1fd2 < uVar14 || CARRY2(uVar9 + 0xe02d,uVar4)));
      (puVar38 + (int)puVar42)[0x5555] = (puVar38 + (int)puVar42)[0x5555] + (char)uVar12;
      goto code_r0x00013aab;
    }
    if (cVar48 == '\0') {
      *(byte *)((int)puVar39 + 0xb) = *(byte *)((int)puVar39 + 0xb) + cVar16;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)puVar39[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(puVar39 + 5) = (byte)(uVar18 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar32 + 10),*(undefined2 *)((int)puVar32 + 0xe));
}


