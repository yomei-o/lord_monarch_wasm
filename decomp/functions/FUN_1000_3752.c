/* 1000:3752 */

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

ulong FUN_1000_3752(void)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  uint uVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined2 uVar12;
  undefined2 in_CX;
  uint uVar13;
  byte bVar14;
  char cVar16;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar15;
  uint in_BX;
  uint uVar17;
  byte bVar18;
  undefined1 *puVar19;
  int *piVar20;
  undefined2 *puVar21;
  undefined1 *puVar22;
  int *piVar23;
  uint *puVar24;
  undefined1 *puVar25;
  uint *puVar26;
  uint *puVar27;
  uint *puVar28;
  uint *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  int *in_ESP;
  uint *puVar32;
  int iVar33;
  int *piVar34;
  uint *unaff_SI;
  int iVar35;
  uint unaff_DI;
  uint *puVar36;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar37;
  byte in_AF;
  undefined1 uVar38;
  bool bVar39;
  bool bVar40;
  bool bVar41;
  char cVar42;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar43;
  ulong uVar44;
  undefined1 *puVar45;
  
  piVar34 = (int *)in_ESP;
  uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
  iVar15 = -*unaff_SI;
  uVar13 = (uint)(piVar34 < (undefined1 *)*unaff_SI);
  uVar17 = in_BX + *(uint *)(in_BX + unaff_DI);
  bVar37 = CARRY2(in_BX,*(uint *)(in_BX + unaff_DI)) || CARRY2(uVar17,uVar13);
  uVar17 = uVar17 + uVar13;
  puVar10 = (undefined1 *)((int)piVar34 + iVar15 + -3);
  *(undefined2 *)((int)piVar34 + iVar15 + -3) = 0x375c;
  uVar43 = func_0x0001ac4f();
  uVar13 = (uint)((ulong)uVar43 >> 0x10);
  if (!bVar37) {
    bVar6 = *(byte *)(unaff_DI + 0xd27e);
    uVar17 = CONCAT11((char)(uVar17 >> 8),bVar6);
    in_CX = 5;
    if ((bVar6 != 0) && ((bVar6 < 0xc || (0xf < bVar6)))) {
      in_CX = 4;
      unaff_DI = unaff_DI | *(uint *)(uVar17 + unaff_DI + 0xb);
      if (bVar6 != 5) {
        in_CX = 8;
      }
      *(uint *)(puVar10 + -2) = (uint)uVar43 | 0x6c72;
      *(uint *)(puVar10 + -4) = uVar13;
      uVar17 = uVar13;
      puVar10 = puVar10 + -4;
    }
  }
  *(undefined2 *)(puVar10 + -2) = in_CX;
  *(uint *)(puVar10 + -4) = uVar13;
  puVar19 = puVar10 + -6;
  *(undefined2 *)(puVar10 + -6) = 0x3799;
  uVar43 = func_0x0001ae87();
  *(int *)(puVar19 + -2) = (int)uVar43;
  *(uint *)(puVar19 + -4) = uVar17;
  *(undefined2 *)(puVar19 + -6) = 9;
  *(int *)(puVar19 + -8) = (int)((ulong)uVar43 >> 0x10);
  *(undefined2 *)(puVar19 + -10) = 0x37a1;
  uVar43 = func_0x0001af48();
  if ((uint)piVar34[-5] <= (uint)uVar43) {
    uVar17 = piVar34[-6];
    uVar43 = CONCAT22(piVar34[-8],piVar34[-5]);
  }
  *(uint *)(byte *)(uVar17 + (int)unaff_SI) =
       *(int *)(byte *)(uVar17 + (int)unaff_SI) + (int)((ulong)uVar43 >> 0x10) +
       (uint)((uint)uVar43 < (uint)piVar34[-1]);
  uVar7 = (uint)(byte)((char)uVar43 + (char)((ulong)uVar43 >> 8) * 't');
  *(char *)((int)piVar34 + (unaff_DI - 0x3a2)) = *(char *)((int)piVar34 + (unaff_DI - 0x3a2)) + -1;
  iVar15 = piVar34[-3];
  iVar33 = piVar34[-4];
  uVar13 = uVar7 - piVar34[7];
  uVar38 = uVar13 == 0;
  if (uVar7 < (uint)piVar34[7]) {
    uVar13 = unaff_SI[3] + uVar7 * -2;
    uVar38 = uVar13 == 0;
    if (uVar7 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar15;
      unaff_SI[4] = uVar17;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      piVar20 = piVar34 + -1;
      piVar34[-1] = 0x37e2;
      func_0x0001ab65();
      puVar10 = (undefined1 *)((int)piVar20 + -2);
      *(undefined2 *)((int)piVar20 + -2) = 0x37e5;
      bVar6 = func_0x0001b496();
      if (!(bool)uVar38) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar6;
        if ((byte)unaff_SI[5] == 0xb) {
          puVar21 = (undefined2 *)(puVar10 + -2);
          puVar10 = puVar10 + -2;
          *puVar21 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar10 + 10),*(undefined2 *)(puVar10 + 0xe));
    }
  }
  piVar23 = piVar34 + -1;
  piVar34[-1] = unaff_DS;
  puVar32 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar44 = CONCAT22(iVar33,CONCAT11(((int)uVar13 < 0) << 7 | uVar38 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar13 & 0xff) & 1U) == 0) << 2,(byte)*puVar32)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar32;
  if (unaff_DI != 0xffff) {
    iVar35 = *piVar34;
    iVar33 = piVar34[1];
    uVar8 = piVar34[6];
    pcVar1 = (char *)(iVar33 + iVar35);
    *pcVar1 = *pcVar1 + (byte)uVar8;
    iVar15 = piVar34[7];
    pbVar2 = (byte *)(iVar33 + iVar35);
    *pbVar2 = *pbVar2 ^ (byte)uVar8;
    *(int *)(iVar15 + -2) = iVar33;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar13 = iVar15 + *(int *)(byte *)((int)unaff_SI + uVar17 + 0xb44);
  puVar36 = (uint *)0x0;
code_r0x0001387f:
  uVar7 = (uint)(uVar44 >> 0x10);
  uVar9 = CONCAT11((char)(uVar44 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar6 = (byte)uVar9;
  *(byte *)(unaff_SI + 5) = bVar6;
  swi(4);
  pcVar1 = (char *)((int)piVar34 + (int)unaff_SI);
  *pcVar1 = *pcVar1 + bVar6;
  if ((POPCOUNT(*pcVar1) & 1U) != 0) {
    pbVar2 = (byte *)((int)unaff_SI + uVar17 + 0x33);
    bVar6 = *pbVar2;
    bVar14 = (byte)(uVar44 >> 0x10);
    bVar18 = *pbVar2;
    cVar16 = (char)(uVar44 >> 0x18) + *(byte *)(uVar17 + (int)unaff_SI);
    *(byte *)(puVar36 + 0x39) = (byte)puVar36[0x39] - cVar16;
    ((undefined1 *)((int)piVar34 + (int)puVar36))[-0x178e] =
         ((undefined1 *)((int)piVar34 + (int)puVar36))[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar16,bVar14 + bVar18),
                         (uVar9 + 0x5556) - (uint)CARRY1(bVar14,bVar6)) % (ulong)unaff_SI[0x410]);
    *(int *)((int)piVar34 + (int)puVar36) = *(int *)((int)piVar34 + (int)puVar36) >> 0x10;
    return CONCAT22(piVar23[1],*piVar23);
  }
  puVar29 = unaff_SI;
  if (*pcVar1 == '\0') goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar37 = CARRY1((byte)uVar17,*(byte *)((int)piVar34 + (int)unaff_SI));
  uVar17 = CONCAT11((char)(uVar17 >> 8),(byte)uVar17 + *(byte *)((int)piVar34 + (int)unaff_SI));
  puVar11 = (undefined1 *)piVar23;
code_r0x000138eb:
  *(undefined2 *)(puVar11 + -2) = unaff_SS;
  if (!bVar37) {
    puVar32 = puVar36;
    puVar36 = (uint *)((int)puVar36 + 1);
    *(byte *)puVar32 = 0x30;
    uVar9 = CONCAT11(0xaa,*(byte *)((int)piVar34 + (int)puVar36) | 0x30) ^ 0x8a0;
    *(uint *)(puVar11 + -2) = uVar17;
    *(uint *)(puVar11 + -4) = uVar9;
    uVar17 = unaff_SI[0x15];
    uVar7 = (uVar7 | 0x3000) - *(int *)(byte *)(uVar17 + (int)unaff_SI);
    bVar18 = (byte)(uVar9 >> 8);
    bVar6 = (char)uVar9 + 8;
    if (bVar6 != *(byte *)(uVar17 + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar11 + -6) = CONCAT11(bVar18,bVar6);
    *(uint *)(puVar11 + -8) = uVar13;
    *(uint *)(puVar11 + -10) = uVar7;
    *(uint *)(puVar11 + -0xc) = uVar17;
    *(undefined1 **)(puVar11 + -0xe) = puVar11 + -4;
    *(int **)(puVar11 + -0x10) = piVar34;
    *(uint **)(puVar11 + -0x12) = unaff_SI;
    *(uint **)(puVar11 + -0x14) = puVar36;
    uVar9 = *puVar36;
    cVar16 = (char)(uVar13 >> 8);
    bVar14 = cVar16 + bVar6;
    uVar13 = CONCAT11(bVar14,(char)uVar13);
    piVar34 = (int *)0x874;
    if (SCARRY1(cVar16,bVar6)) {
      piVar23 = *(int **)(puVar11 + -0x14);
      puVar29 = *(uint **)(byte *)((int)puVar36 + (uVar17 - 0x18));
      puVar32 = puVar29 + 0x43a;
      uVar4 = *puVar32;
      *puVar32 = *puVar32 + 0x809;
      uVar13 = 0x4379;
      puVar29[0x43a] =
           puVar29[0x43a] + CONCAT11(bVar18 | (byte)uVar9,bVar6 | bVar14) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar11 + -0x16) = 0x874;
      piVar23 = (int *)(puVar11 + -0x18);
      *(undefined2 *)(puVar11 + -0x18) = 0x874;
      puVar29 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar36 + 0x55) = *(int *)(byte *)((int)puVar36 + 0x55) + uVar7;
    unaff_SI = (uint *)((int)puVar29 + 1);
    out((byte)*puVar29,uVar7);
    uVar17 = CONCAT11((byte)(uVar17 >> 8) & ((undefined1 *)((int)piVar34 + (int)unaff_SI))[0x11],
                      (char)uVar17);
    bVar18 = (byte)uVar7;
    cVar42 = SBORROW1(bVar18,(byte)puVar29[0x39]);
    bVar6 = (byte)puVar29[0x39];
    cVar16 = (char)(bVar18 - bVar6) < '\0';
    bVar37 = bVar18 == bVar6;
    puVar24 = (uint *)((int)piVar23 + -2);
    *(undefined2 *)((int)piVar23 + -2) = 0x396b;
    bVar6 = func_0x0001b3ed();
    iVar15 = extraout_DX_00;
    if (!bVar37) {
      *(byte *)(puVar29 + 6) = bVar6;
      *(undefined2 *)((int)puVar24 + -2) = 0x3973;
      puVar24 = (uint *)((int)puVar24 + -2);
      bVar6 = func_0x0001b617();
      iVar15 = extraout_DX_01;
    }
    if (cVar42 != cVar16) {
      iVar15 = iVar15 + 1;
      puVar24[-1] = (uint)puVar36;
      puVar24[-2] = iVar15;
      puVar24[-3] = CONCAT11((char)(uVar13 >> 8),8);
      puVar24[-4] = uVar17;
      if (iVar15 == 0) {
LAB_1000_39c7:
        pcVar5 = (code *)swi(1);
        uVar44 = (*pcVar5)();
        return uVar44;
      }
      ((undefined1 *)((int)piVar34 + (int)puVar36))[0x6e] =
           ((undefined1 *)((int)piVar34 + (int)puVar36))[0x6e] | (byte)((uint)iVar15 >> 8);
code_r0x00013985:
      pbVar2 = (byte *)((int)puVar36 + uVar17 + 0x12);
      *(byte **)pbVar2 = (byte *)((int)puVar36 + *(int *)pbVar2 + 2);
      puVar25 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar25 + -2) = 0x399f;
      func_0x00018e51();
      pcVar5 = (code *)swi(3);
      uVar44 = (*pcVar5)();
      return uVar44;
    }
    in_AF = 9 < ((bVar6 ^ *(byte *)((int)piVar34 + (int)unaff_SI)) & 0xf) | in_AF;
    bVar6 = (bVar6 ^ *(byte *)((int)piVar34 + (int)unaff_SI)) + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar24;
    bVar37 = bVar6 < (byte)((undefined1 *)((int)piVar34 + (int)unaff_SI))[-0x74a1] ||
             bVar6 == ((undefined1 *)((int)piVar34 + (int)unaff_SI))[-0x74a1];
    puVar32 = (uint *)CONCAT22(uVar8,puVar24);
    *puVar24 = 0x39ba;
    puVar45 = (undefined1 *)FUN_1000_a1b8();
    puVar10 = (undefined1 *)puVar45;
    if (bVar37) {
      if (uVar13 == 1) {
        do {
          iVar15 = 0x40;
          puVar11 = puVar10;
          do {
            uVar17 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar29 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar32 = puVar32 + -2;
              *puVar32 = unaff_DS;
              bVar6 = (byte)puVar11 | 0x17;
              bVar18 = (byte)((uint)puVar11 >> 8);
              if (bVar18 == (byte)unaff_SI[6]) {
                puVar11 = (undefined1 *)CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
                puVar29 = puVar36;
                goto code_r0x00013a16;
              }
              uVar17 = CONCAT11(bVar18 & *(byte *)((int)piVar34 + (int)unaff_SI),(byte)puVar11) |
                       0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar15 >> 8);
              *(undefined1 *)((int)piVar34 + (int)puVar36) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)((int)piVar34 + 4);
              puVar11 = (undefined1 *)*(uint *)puVar32;
              puVar32 = (uint *)CONCAT22((int)((ulong)puVar32 >> 0x10),(uint *)puVar32 + 1);
              puVar29 = unaff_SI + 8;
              puVar36 = unaff_SI;
            }
            iVar15 = iVar15 + -1;
            unaff_SI = puVar29;
          } while (iVar15 != 0);
          unaff_SI = (uint *)*(uint *)puVar32;
          puVar32 = (uint *)CONCAT22((int)((ulong)puVar32 >> 0x10),(uint *)puVar32 + 1);
          puVar29 = puVar36;
code_r0x00013a16:
          uVar8 = (undefined2)((ulong)puVar32 >> 0x10);
          puVar26 = (uint *)puVar32;
          if (0x1ef < uVar17) goto code_r0x00013a1c;
          ((undefined1 *)((int)piVar34 + (int)puVar29))[0x59] =
               ((undefined1 *)((int)piVar34 + (int)puVar29))[0x59] | (byte)uVar17;
          bVar6 = *(byte *)(uVar17 + puVar26[1]);
          puVar26[1] = (uint)unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar17 + ((byte)((char)piVar34 + 1U) < bVar6);
          puVar10 = (undefined1 *)CONCAT11((char)((uint)piVar34 >> 8),(char)piVar34 + -0x3b);
          puVar36 = (uint *)puVar26[1];
          puVar32 = (uint *)CONCAT22(uVar8,puVar26 + 2);
          unaff_SI = (uint *)0xc800;
          piVar34 = (int *)puVar11;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)puVar45 >> 0x10),(char)puVar45);
    puVar3 = unaff_SI;
    bVar37 = CARRY2(*puVar3,(uint)puVar10);
    *puVar3 = (uint)(puVar10 + *puVar3);
    bVar40 = (int)*puVar3 < 0;
    bVar39 = *puVar3 == 0;
    bVar6 = POPCOUNT(*puVar3 & 0xff);
    uVar13 = uVar13 - 1;
    if (uVar13 == 0 || bVar39) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  uVar17 = uVar17 + 1;
  puVar10 = puVar11 + -4;
  *(undefined2 *)(puVar11 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar7;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar10 = puVar31;
  if (bVar37) {
    puVar10 = puVar31 + -2;
    *(undefined2 *)(puVar31 + -2) = 0x3b67;
    uVar44 = func_0x000137e6();
    bVar6 = (byte)uVar44;
    if (bVar37) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar44;
  }
  *(int **)(puVar10 + -2) = piVar34;
  puVar31 = puVar10 + -4;
  *(int **)(puVar10 + -4) = piVar34;
  pbVar2 = (byte *)(uVar17 + (int)unaff_SI);
  bVar6 = (byte)(uVar44 >> 8);
  bVar37 = CARRY1(*pbVar2,bVar6);
  *pbVar2 = *pbVar2 + bVar6;
  uVar17 = uVar17 - 1;
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar37 = bVar6 < 0x10;
  bVar41 = SBORROW1(bVar6,'\x10');
  bVar40 = (char)(bVar6 - 0x10) < '\0';
  bVar39 = bVar6 == 0x10;
  if (!bVar37) {
    if (7 < bVar6) {
      bVar41 = SBORROW1(bVar6,'\f');
      bVar40 = (char)(bVar6 - 0xc) < '\0';
      bVar39 = bVar6 == 0xc;
      bVar37 = true;
      if (bVar6 < 0xc) goto LAB_1000_383e;
    }
    if (bVar6 != 0) {
      bVar41 = SBORROW1(bVar6,'\x05');
      bVar40 = (char)(bVar6 - 5) < '\0';
      bVar39 = bVar6 == 5;
      bVar37 = true;
      if (bVar6 < 5) goto LAB_1000_383e;
    }
    bVar37 = bVar6 < 5;
    bVar41 = SBORROW1(bVar6,'\x05');
    bVar40 = (char)(bVar6 - 5) < '\0';
    bVar39 = bVar6 == 5;
    if (!bVar39) {
      uVar13 = CONCAT11(((undefined1 *)((int)piVar34 + (int)puVar36))[-0x80],0xb);
      pbVar2 = (byte *)(uVar17 + (int)unaff_SI);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      piVar23 = (int *)(puVar10 + -2);
      *(undefined2 *)(puVar10 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(uVar17 + (int)unaff_SI) = *(byte *)(uVar17 + (int)unaff_SI) & (byte)uVar13;
      LOCK();
      uVar38 = *(undefined1 *)((int)piVar34 + 0x72);
      *(undefined1 *)((int)piVar34 + 0x72) = (char)((uint)extraout_DX >> 8);
      uVar7 = CONCAT11(uVar38,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar37) {
    *(undefined2 *)(puVar10 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar39 && bVar41 == bVar40) {
    return CONCAT22(*(undefined2 *)((int)piVar34 + 10),*(undefined2 *)((int)piVar34 + 0xe));
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
  pbVar2 = (byte *)((int)puVar36 + uVar17 + 0x854);
  *pbVar2 = *pbVar2 & 0xb;
  uVar38 = *pbVar2 == 0;
  puVar22 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  piVar23 = (int *)(puVar22 + -2);
  *(undefined2 *)(puVar22 + -2) = 0x387a;
  uVar44 = func_0x0001b476();
  if (!(bool)uVar38) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar44;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar26;
  *(longdouble *)(uVar17 + (int)puVar29) = in_ST0;
  puVar32 = (uint *)CONCAT22(uVar8,(uint *)(puVar26[1] + -2));
  *(undefined2 *)(puVar26[1] + -2) = unaff_ES;
  uVar17 = puVar29[2];
  puVar10 = (undefined1 *)(uint)*(byte *)((int)puVar29 + -0x79);
  bVar37 = (byte)iVar15 < *(byte *)((int)piVar34 + (int)unaff_SI);
  cVar16 = (byte)iVar15 - *(byte *)((int)piVar34 + (int)unaff_SI);
  uVar13 = CONCAT11((char)((uint)iVar15 >> 8),cVar16);
  bVar40 = cVar16 < '\0';
  bVar39 = cVar16 == '\0';
  bVar6 = POPCOUNT(cVar16);
  LOCK();
  puVar36 = (uint *)*(undefined2 *)((int)piVar34 + -0x2e);
  *(undefined2 *)((int)piVar34 + -0x2e) = puVar29;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar39) {
    *(byte *)(uVar17 + (int)unaff_SI) = *(byte *)(uVar17 + (int)unaff_SI) + 1;
    puVar27 = (uint *)puVar32;
    puVar32 = (uint *)CONCAT22((int)((ulong)puVar32 >> 0x10),puVar27 + -1);
    puVar27[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar40 << 7 | bVar39 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar37,(char)puVar10)) {
      ((undefined1 *)((int)piVar34 + (int)puVar36))[-0x54ee] =
           ((undefined1 *)((int)piVar34 + (int)puVar36))[-0x54ee] | (byte)(uVar17 >> 8);
      puVar3 = puVar36;
      puVar36 = (uint *)((int)puVar36 + 1);
      *(byte *)puVar3 = (char)puVar10 + 0x3b;
      goto LAB_1000_3a63;
    }
    piVar34 = (int *)((int)piVar34 + uVar13);
    pbVar2 = (byte *)((uVar17 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar3 = (uint *)((undefined1 *)((int)piVar34 + (int)puVar36) + 0x645);
    uVar7 = *puVar3;
    *puVar3 = *puVar3 - uVar13;
    bVar6 = ((char)(uVar17 >> 1) + (char)(uVar17 >> 2) + -0x10) - (uVar7 < uVar13) | 2;
    iVar15 = *(int *)(byte *)((int)puVar36 + 0x55);
code_r0x00013aab:
    *(byte *)((int)piVar34 + (int)unaff_SI) = *(byte *)((int)piVar34 + (int)unaff_SI) & bVar6;
    ((uint *)puVar32)[-1] = (uint)piVar34;
    *(byte *)((int)piVar34 + (int)unaff_SI) = *(byte *)((int)piVar34 + (int)unaff_SI) & (byte)uVar13
    ;
    puVar29 = (uint *)0xf029;
    *(uint *)0xf029 = (uint)piVar34;
    if (iVar15 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)((int)piVar34 + (int)unaff_SI) = *(byte *)((int)piVar34 + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar44 = (*pcVar5)();
      return uVar44;
    }
    uVar17 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar17 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar5 = (code *)swi(0x20);
    (*pcVar5)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar17 >> 8);
    puVar28 = (uint *)puVar32;
    uVar8 = (undefined2)((ulong)puVar32 >> 0x10);
    puVar28[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + uVar17 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)puVar36);
    puVar36 = (uint *)puVar28[-1];
    unaff_SI = (uint *)*puVar28;
    piVar34 = (int *)puVar28[1];
    uVar13 = puVar28[5];
    uVar12 = puVar28[6];
    uVar17 = CONCAT11((char)(puVar28[3] >> 8),(byte)puVar28[3] | *(byte *)0x5d02) |
             *(uint *)((undefined1 *)((int)piVar34 + (int)puVar36) + 10);
    puVar28[6] = (uint)puVar36;
    pbVar2 = (byte *)((int)unaff_SI + uVar17 + 0x2c2);
    cVar42 = SCARRY1((char)uVar12,*pbVar2);
    bVar37 = (char)((char)uVar12 + *pbVar2) < '\0';
    puVar29 = puVar28 + 5;
    puVar28[5] = 0x3a83;
    uVar43 = func_0x00013e95();
    bVar6 = (byte)uVar43;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar17;
    cVar16 = (char)((ulong)uVar43 >> 0x18);
    if (bVar37) {
      bVar18 = (byte)(uVar17 >> 8);
      puVar32 = (uint *)((int)puVar36 + -0x53);
      uVar4 = (uint)(bVar18 < (byte)(uVar13 >> 8));
      uVar7 = *puVar32;
      uVar9 = *puVar32;
      *puVar32 = uVar9 + 0xe02d + uVar4;
      cVar42 = *(char *)((int)piVar34 + (int)puVar36);
      bVar18 = bVar18 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar43 >> 8);
      uVar17 = CONCAT11(bVar18,(char)uVar17);
      if ((char)bVar18 < '\0') {
        bVar37 = unaff_SI[3] < 1000;
        if (!bVar37) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar29 + -2) = 0x3b26;
          puVar29 = (uint *)((int)puVar29 + -2);
          uVar43 = func_0x00013966();
          if (!bVar37) goto LAB_1000_3b55_1;
        }
        puVar31 = (undefined1 *)((int)puVar29 + -2);
        *(undefined2 *)((int)puVar29 + -2) = 0x3b2d;
        uVar44 = FUN_1000_8cb7();
        uVar7 = (uint)(uVar44 >> 0x10);
        bVar37 = (byte)uVar44 < 0x5a;
        if (bVar37) {
          bVar37 = true;
          if ((byte)uVar44 < 0x50) goto LAB_1000_3b62;
          puVar11 = puVar31 + -2;
          *(undefined2 *)(puVar31 + -2) = 0x3b38;
          bVar37 = false;
          goto code_r0x000138eb;
        }
        puVar30 = puVar31 + -2;
        *(undefined2 *)(puVar31 + -2) = 0x3b42;
        uVar43 = FUN_1000_3607();
        bVar6 = (byte)uVar43;
        if (bVar37) {
          puVar10 = puVar30 + -2;
          *(undefined2 *)(puVar30 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar44 = CONCAT22((int)((ulong)uVar43 >> 0x10),
                          CONCAT11((char)((ulong)uVar43 >> 8),(char)uVar43 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar32 = (uint *)ZEXT24((undefined1 *)((int)puVar29 + -2));
      *(undefined2 *)((int)puVar29 + -2) = unaff_CS;
      iVar15 = CONCAT11(cVar16 - *(byte *)((int)unaff_SI + uVar17 + 0x23c9),
                        (char)((ulong)uVar43 >> 0x10) + cVar42 +
                        (0x1fd2 < uVar7 || CARRY2(uVar9 + 0xe02d,uVar4)));
      ((undefined1 *)((int)piVar34 + (int)puVar36))[0x5555] =
           ((undefined1 *)((int)piVar34 + (int)puVar36))[0x5555] + (char)uVar13;
      goto code_r0x00013aab;
    }
    if (cVar42 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar16;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar17 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar29 + 10),*(undefined2 *)((int)puVar29 + 0xe));
}


