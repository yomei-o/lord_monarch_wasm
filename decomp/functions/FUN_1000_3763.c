/* 1000:3763 */

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

ulong FUN_1000_3763(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  uint in_AX;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  byte bVar11;
  int *piVar10;
  undefined2 uVar12;
  uint uVar13;
  byte bVar14;
  uint in_DX;
  char cVar16;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar15;
  undefined2 in_BX;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined1 *puVar20;
  int *piVar21;
  undefined2 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  uint *puVar26;
  undefined1 *puVar27;
  uint *puVar28;
  uint *puVar29;
  uint *puVar30;
  uint *puVar31;
  undefined1 *puVar32;
  undefined1 *puVar33;
  undefined4 in_ESP;
  undefined2 uVar35;
  uint *puVar34;
  int *unaff_BP;
  int iVar36;
  uint *unaff_SI;
  int iVar37;
  uint unaff_DI;
  uint *puVar38;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar39;
  byte in_AF;
  undefined1 uVar40;
  bool bVar41;
  bool bVar42;
  bool bVar43;
  char cVar44;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar45;
  ulong uVar46;
  int *piVar47;
  
  bVar6 = *(byte *)(unaff_DI + 0xd27e);
  uVar17 = CONCAT11((char)((uint)in_BX >> 8),bVar6);
  uVar12 = 5;
  if ((bVar6 != 0) && ((bVar6 < 0xc || (0xf < bVar6)))) {
    uVar12 = 4;
    unaff_DI = unaff_DI | *(uint *)(uVar17 + unaff_DI + 0xb);
    if (bVar6 != 5) {
      uVar12 = 8;
    }
    iVar18 = (int)in_ESP;
    *(uint *)(iVar18 + -2) = in_AX | 0x6c72;
    in_ESP = CONCAT22((int)((ulong)in_ESP >> 0x10),iVar18 + -4);
    *(uint *)(iVar18 + -4) = in_DX;
    uVar17 = in_DX;
  }
  iVar19 = (int)in_ESP;
  uVar35 = (undefined2)((ulong)in_ESP >> 0x10);
  *(undefined2 *)(iVar19 + -2) = uVar12;
  *(uint *)(iVar19 + -4) = in_DX;
  puVar20 = (undefined1 *)(iVar19 + -6);
  *(undefined2 *)(iVar19 + -6) = 0x3799;
  uVar45 = func_0x0001ae87();
  *(int *)(puVar20 + -2) = (int)uVar45;
  *(uint *)(puVar20 + -4) = uVar17;
  *(undefined2 *)(puVar20 + -6) = 9;
  *(int *)(puVar20 + -8) = (int)((ulong)uVar45 >> 0x10);
  *(undefined2 *)(puVar20 + -10) = 0x37a1;
  uVar45 = func_0x0001af48();
  if ((uint)unaff_BP[-5] <= (uint)uVar45) {
    uVar17 = unaff_BP[-6];
    uVar45 = CONCAT22(unaff_BP[-8],unaff_BP[-5]);
  }
  *(uint *)(byte *)(uVar17 + (int)unaff_SI) =
       *(int *)(byte *)(uVar17 + (int)unaff_SI) + (int)((ulong)uVar45 >> 0x10) +
       (uint)((uint)uVar45 < (uint)unaff_BP[-1]);
  uVar7 = (uint)(byte)((char)uVar45 + (char)((ulong)uVar45 >> 8) * 't');
  pcVar2 = (char *)((int)unaff_BP + (unaff_DI - 0x3a2));
  *pcVar2 = *pcVar2 + -1;
  iVar15 = unaff_BP[-3];
  iVar36 = unaff_BP[-4];
  uVar13 = uVar7 - unaff_BP[7];
  uVar40 = uVar13 == 0;
  if (uVar7 < (uint)unaff_BP[7]) {
    uVar13 = unaff_SI[3] + uVar7 * -2;
    uVar40 = uVar13 == 0;
    if (uVar7 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar15;
      unaff_SI[4] = uVar17;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      piVar21 = unaff_BP + -1;
      unaff_BP[-1] = 0x37e2;
      func_0x0001ab65();
      puVar23 = (undefined1 *)((int)piVar21 + -2);
      *(undefined2 *)((int)piVar21 + -2) = 0x37e5;
      bVar6 = func_0x0001b496();
      if (!(bool)uVar40) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar6;
        if ((byte)unaff_SI[5] == 0xb) {
          puVar22 = (undefined2 *)(puVar23 + -2);
          puVar23 = puVar23 + -2;
          *puVar22 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar23 + 10),*(undefined2 *)(puVar23 + 0xe));
    }
  }
  piVar9 = unaff_BP + -1;
  unaff_BP[-1] = unaff_DS;
  puVar34 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar46 = CONCAT22(iVar36,CONCAT11(((int)uVar13 < 0) << 7 | uVar40 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar13 & 0xff) & 1U) == 0) << 2,(byte)*puVar34)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar34;
  if (unaff_DI != 0xffff) {
    iVar37 = *unaff_BP;
    iVar36 = unaff_BP[1];
    uVar12 = unaff_BP[6];
    pcVar2 = (char *)(iVar36 + iVar37);
    *pcVar2 = *pcVar2 + (byte)uVar12;
    iVar15 = unaff_BP[7];
    pbVar1 = (byte *)(iVar36 + iVar37);
    *pbVar1 = *pbVar1 ^ (byte)uVar12;
    *(int *)(iVar15 + -2) = iVar36;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar13 = iVar15 + *(int *)(byte *)((int)unaff_SI + uVar17 + 0xb44);
  puVar38 = (uint *)0x0;
code_r0x0001387f:
  uVar7 = (uint)(uVar46 >> 0x10);
  uVar8 = CONCAT11((char)(uVar46 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar6 = (byte)uVar8;
  *(byte *)(unaff_SI + 5) = bVar6;
  swi(4);
  pbVar1 = (byte *)((int)unaff_BP + (int)unaff_SI);
  *pbVar1 = *pbVar1 + bVar6;
  if ((POPCOUNT(*pbVar1) & 1U) != 0) {
    pbVar1 = (byte *)((int)unaff_SI + uVar17 + 0x33);
    bVar6 = *pbVar1;
    bVar14 = (byte)(uVar46 >> 0x10);
    bVar11 = *pbVar1;
    cVar16 = (char)(uVar46 >> 0x18) + *(byte *)(uVar17 + (int)unaff_SI);
    *(byte *)(puVar38 + 0x39) = (byte)puVar38[0x39] - cVar16;
    ((byte *)((int)unaff_BP + (int)puVar38))[-0x178e] =
         ((byte *)((int)unaff_BP + (int)puVar38))[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar16,bVar14 + bVar11),
                         (uVar8 + 0x5556) - (uint)CARRY1(bVar14,bVar6)) % (ulong)unaff_SI[0x410]);
    *(int *)(byte *)((int)unaff_BP + (int)puVar38) =
         *(int *)(byte *)((int)unaff_BP + (int)puVar38) >> 0x10;
    return CONCAT22(piVar9[1],*piVar9);
  }
  puVar31 = unaff_SI;
  if (*pbVar1 == 0) goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar39 = CARRY1((byte)uVar17,*(byte *)((int)unaff_BP + (int)unaff_SI));
  uVar17 = CONCAT11((char)(uVar17 >> 8),(byte)uVar17 + *(byte *)((int)unaff_BP + (int)unaff_SI));
  puVar25 = (undefined1 *)piVar9;
code_r0x000138eb:
  *(undefined2 *)(puVar25 + -2) = unaff_SS;
  if (!bVar39) {
    puVar34 = puVar38;
    puVar38 = (uint *)((int)puVar38 + 1);
    *(byte *)puVar34 = 0x30;
    uVar8 = CONCAT11(0xaa,*(byte *)((int)unaff_BP + (int)puVar38) | 0x30) ^ 0x8a0;
    *(uint *)(puVar25 + -2) = uVar17;
    *(uint *)(puVar25 + -4) = uVar8;
    uVar17 = unaff_SI[0x15];
    uVar7 = (uVar7 | 0x3000) - *(int *)(byte *)(uVar17 + (int)unaff_SI);
    bVar11 = (byte)(uVar8 >> 8);
    bVar6 = (char)uVar8 + 8;
    if (bVar6 != *(byte *)(uVar17 + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar25 + -6) = CONCAT11(bVar11,bVar6);
    *(uint *)(puVar25 + -8) = uVar13;
    *(uint *)(puVar25 + -10) = uVar7;
    *(uint *)(puVar25 + -0xc) = uVar17;
    *(undefined1 **)(puVar25 + -0xe) = puVar25 + -4;
    *(int **)(puVar25 + -0x10) = unaff_BP;
    *(uint **)(puVar25 + -0x12) = unaff_SI;
    *(uint **)(puVar25 + -0x14) = puVar38;
    uVar8 = *puVar38;
    cVar16 = (char)(uVar13 >> 8);
    bVar14 = cVar16 + bVar6;
    uVar13 = CONCAT11(bVar14,(char)uVar13);
    unaff_BP = (int *)0x874;
    if (SCARRY1(cVar16,bVar6)) {
      piVar9 = *(int **)(puVar25 + -0x14);
      puVar31 = *(uint **)(byte *)((int)puVar38 + (uVar17 - 0x18));
      puVar34 = puVar31 + 0x43a;
      uVar4 = *puVar34;
      *puVar34 = *puVar34 + 0x809;
      uVar13 = 0x4379;
      puVar31[0x43a] =
           puVar31[0x43a] + CONCAT11(bVar11 | (byte)uVar8,bVar6 | bVar14) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar25 + -0x16) = 0x874;
      piVar9 = (int *)(puVar25 + -0x18);
      *(undefined2 *)(puVar25 + -0x18) = 0x874;
      puVar31 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar38 + 0x55) = *(int *)(byte *)((int)puVar38 + 0x55) + uVar7;
    unaff_SI = (uint *)((int)puVar31 + 1);
    out((byte)*puVar31,uVar7);
    uVar17 = CONCAT11((byte)(uVar17 >> 8) & ((byte *)((int)unaff_BP + (int)unaff_SI))[0x11],
                      (char)uVar17);
    bVar11 = (byte)uVar7;
    cVar44 = SBORROW1(bVar11,(byte)puVar31[0x39]);
    bVar6 = (byte)puVar31[0x39];
    cVar16 = (char)(bVar11 - bVar6) < '\0';
    bVar39 = bVar11 == bVar6;
    puVar26 = (uint *)((int)piVar9 + -2);
    *(undefined2 *)((int)piVar9 + -2) = 0x396b;
    bVar6 = func_0x0001b3ed();
    iVar15 = extraout_DX_00;
    if (!bVar39) {
      *(byte *)(puVar31 + 6) = bVar6;
      *(undefined2 *)((int)puVar26 + -2) = 0x3973;
      puVar26 = (uint *)((int)puVar26 + -2);
      bVar6 = func_0x0001b617();
      iVar15 = extraout_DX_01;
    }
    if (cVar44 != cVar16) {
      iVar15 = iVar15 + 1;
      puVar26[-1] = (uint)puVar38;
      puVar26[-2] = iVar15;
      puVar26[-3] = CONCAT11((char)(uVar13 >> 8),8);
      puVar26[-4] = uVar17;
      if (iVar15 == 0) {
LAB_1000_39c7:
        pcVar5 = (code *)swi(1);
        uVar46 = (*pcVar5)();
        return uVar46;
      }
      ((byte *)((int)unaff_BP + (int)puVar38))[0x6e] =
           ((byte *)((int)unaff_BP + (int)puVar38))[0x6e] | (byte)((uint)iVar15 >> 8);
code_r0x00013985:
      pbVar1 = (byte *)((int)puVar38 + uVar17 + 0x12);
      *(byte **)pbVar1 = (byte *)((int)puVar38 + *(int *)pbVar1 + 2);
      puVar27 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar27 + -2) = 0x399f;
      func_0x00018e51();
      pcVar5 = (code *)swi(3);
      uVar46 = (*pcVar5)();
      return uVar46;
    }
    bVar6 = bVar6 ^ *(byte *)((int)unaff_BP + (int)unaff_SI);
    in_AF = 9 < (bVar6 & 0xf) | in_AF;
    bVar6 = bVar6 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar26;
    bVar39 = bVar6 < ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1] ||
             bVar6 == ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1];
    puVar34 = (uint *)CONCAT22(uVar35,puVar26);
    *puVar26 = 0x39ba;
    piVar47 = (int *)FUN_1000_a1b8();
    piVar9 = (int *)piVar47;
    if (bVar39) {
      if (uVar13 == 1) {
        do {
          iVar15 = 0x40;
          piVar10 = piVar9;
          do {
            uVar17 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar31 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar34 = puVar34 + -2;
              *puVar34 = unaff_DS;
              bVar6 = (byte)piVar10 | 0x17;
              bVar11 = (byte)((uint)piVar10 >> 8);
              if (bVar11 == (byte)unaff_SI[6]) {
                piVar10 = (int *)CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
                puVar31 = puVar38;
                goto code_r0x00013a16;
              }
              uVar17 = CONCAT11(bVar11 & *(byte *)((int)unaff_BP + (int)unaff_SI),(byte)piVar10) |
                       0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar15 >> 8);
              *(byte *)((int)unaff_BP + (int)puVar38) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 2);
              piVar10 = (int *)*(uint *)puVar34;
              puVar34 = (uint *)CONCAT22((int)((ulong)puVar34 >> 0x10),(uint *)puVar34 + 1);
              puVar31 = unaff_SI + 8;
              puVar38 = unaff_SI;
            }
            iVar15 = iVar15 + -1;
            unaff_SI = puVar31;
          } while (iVar15 != 0);
          unaff_SI = (uint *)*(uint *)puVar34;
          puVar34 = (uint *)CONCAT22((int)((ulong)puVar34 >> 0x10),(uint *)puVar34 + 1);
          puVar31 = puVar38;
code_r0x00013a16:
          uVar12 = (undefined2)((ulong)puVar34 >> 0x10);
          puVar28 = (uint *)puVar34;
          if (0x1ef < uVar17) goto code_r0x00013a1c;
          ((byte *)((int)unaff_BP + (int)puVar31))[0x59] =
               ((byte *)((int)unaff_BP + (int)puVar31))[0x59] | (byte)uVar17;
          bVar6 = *(byte *)(uVar17 + puVar28[1]);
          puVar28[1] = (uint)unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar17 + ((byte)((char)unaff_BP + 1U) < bVar6);
          piVar9 = (int *)CONCAT11((char)((uint)unaff_BP >> 8),(char)unaff_BP + -0x3b);
          puVar38 = (uint *)puVar28[1];
          puVar34 = (uint *)CONCAT22(uVar12,puVar28 + 2);
          unaff_SI = (uint *)0xc800;
          unaff_BP = piVar10;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)piVar47 >> 0x10),(char)piVar47);
    puVar3 = unaff_SI;
    bVar39 = CARRY2(*puVar3,(uint)piVar9);
    *puVar3 = *puVar3 + (int)piVar9;
    bVar42 = (int)*puVar3 < 0;
    bVar41 = *puVar3 == 0;
    bVar6 = POPCOUNT(*puVar3 & 0xff);
    uVar13 = uVar13 - 1;
    if (uVar13 == 0 || bVar41) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  uVar17 = uVar17 + 1;
  puVar23 = puVar25 + -4;
  *(undefined2 *)(puVar25 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar7;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar23 = puVar33;
  if (bVar39) {
    puVar23 = puVar33 + -2;
    *(undefined2 *)(puVar33 + -2) = 0x3b67;
    uVar46 = func_0x000137e6();
    bVar6 = (byte)uVar46;
    if (bVar39) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar46;
  }
  *(int **)(puVar23 + -2) = unaff_BP;
  puVar33 = puVar23 + -4;
  *(int **)(puVar23 + -4) = unaff_BP;
  pbVar1 = (byte *)(uVar17 + (int)unaff_SI);
  bVar6 = (byte)(uVar46 >> 8);
  bVar39 = CARRY1(*pbVar1,bVar6);
  *pbVar1 = *pbVar1 + bVar6;
  uVar17 = uVar17 - 1;
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar39 = bVar6 < 0x10;
  bVar43 = SBORROW1(bVar6,'\x10');
  bVar42 = (char)(bVar6 - 0x10) < '\0';
  bVar41 = bVar6 == 0x10;
  if (!bVar39) {
    if (7 < bVar6) {
      bVar43 = SBORROW1(bVar6,'\f');
      bVar42 = (char)(bVar6 - 0xc) < '\0';
      bVar41 = bVar6 == 0xc;
      bVar39 = true;
      if (bVar6 < 0xc) goto LAB_1000_383e;
    }
    if (bVar6 != 0) {
      bVar43 = SBORROW1(bVar6,'\x05');
      bVar42 = (char)(bVar6 - 5) < '\0';
      bVar41 = bVar6 == 5;
      bVar39 = true;
      if (bVar6 < 5) goto LAB_1000_383e;
    }
    bVar39 = bVar6 < 5;
    bVar43 = SBORROW1(bVar6,'\x05');
    bVar42 = (char)(bVar6 - 5) < '\0';
    bVar41 = bVar6 == 5;
    if (!bVar41) {
      uVar13 = CONCAT11(((byte *)((int)unaff_BP + (int)puVar38))[-0x80],0xb);
      pbVar1 = (byte *)(uVar17 + (int)unaff_SI);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      piVar9 = (int *)(puVar23 + -2);
      *(undefined2 *)(puVar23 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(uVar17 + (int)unaff_SI) = *(byte *)(uVar17 + (int)unaff_SI) & (byte)uVar13;
      LOCK();
      iVar15 = unaff_BP[0x39];
      *(char *)(unaff_BP + 0x39) = (char)((uint)extraout_DX >> 8);
      uVar7 = CONCAT11((char)iVar15,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar39) {
    *(undefined2 *)(puVar23 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar41 && bVar43 == bVar42) {
    return CONCAT22(unaff_BP[5],unaff_BP[7]);
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
  pbVar1 = (byte *)((int)puVar38 + uVar17 + 0x854);
  *pbVar1 = *pbVar1 & 0xb;
  uVar40 = *pbVar1 == 0;
  puVar24 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  piVar9 = (int *)(puVar24 + -2);
  *(undefined2 *)(puVar24 + -2) = 0x387a;
  uVar46 = func_0x0001b476();
  if (!(bool)uVar40) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar46;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar28;
  *(longdouble *)(uVar17 + (int)puVar31) = in_ST0;
  puVar34 = (uint *)CONCAT22(uVar12,(uint *)(puVar28[1] + -2));
  *(undefined2 *)(puVar28[1] + -2) = unaff_ES;
  uVar17 = puVar31[2];
  piVar9 = (int *)(uint)*(byte *)((int)puVar31 + -0x79);
  bVar39 = (byte)iVar15 < *(byte *)((int)unaff_BP + (int)unaff_SI);
  cVar16 = (byte)iVar15 - *(byte *)((int)unaff_BP + (int)unaff_SI);
  uVar13 = CONCAT11((char)((uint)iVar15 >> 8),cVar16);
  bVar42 = cVar16 < '\0';
  bVar41 = cVar16 == '\0';
  bVar6 = POPCOUNT(cVar16);
  LOCK();
  puVar38 = (uint *)unaff_BP[-0x17];
  unaff_BP[-0x17] = (int)puVar31;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar41) {
    *(byte *)(uVar17 + (int)unaff_SI) = *(byte *)(uVar17 + (int)unaff_SI) + 1;
    puVar29 = (uint *)puVar34;
    puVar34 = (uint *)CONCAT22((int)((ulong)puVar34 >> 0x10),puVar29 + -1);
    puVar29[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar42 << 7 | bVar41 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar39,(char)piVar9)) {
      ((byte *)((int)unaff_BP + (int)puVar38))[-0x54ee] =
           ((byte *)((int)unaff_BP + (int)puVar38))[-0x54ee] | (byte)(uVar17 >> 8);
      puVar3 = puVar38;
      puVar38 = (uint *)((int)puVar38 + 1);
      *(byte *)puVar3 = (char)piVar9 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = (int *)((int)unaff_BP + uVar13);
    pbVar1 = (byte *)((uVar17 >> 2) + (int)unaff_SI);
    *pbVar1 = *pbVar1 - 0x15;
    puVar3 = (uint *)((byte *)((int)unaff_BP + (int)puVar38) + 0x645);
    uVar7 = *puVar3;
    *puVar3 = *puVar3 - uVar13;
    bVar6 = ((char)(uVar17 >> 1) + (char)(uVar17 >> 2) + -0x10) - (uVar7 < uVar13) | 2;
    iVar15 = *(int *)(byte *)((int)puVar38 + 0x55);
code_r0x00013aab:
    *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) & bVar6;
    ((uint *)puVar34)[-1] = (uint)unaff_BP;
    *(byte *)((int)unaff_BP + (int)unaff_SI) =
         *(byte *)((int)unaff_BP + (int)unaff_SI) & (byte)uVar13;
    puVar31 = (uint *)0xf029;
    *(uint *)0xf029 = (uint)unaff_BP;
    if (iVar15 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar46 = (*pcVar5)();
      return uVar46;
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
    puVar30 = (uint *)puVar34;
    uVar35 = (undefined2)((ulong)puVar34 >> 0x10);
    puVar30[-1] = unaff_ES;
    pbVar1 = (byte *)((int)unaff_SI + uVar17 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)puVar38);
    puVar38 = (uint *)puVar30[-1];
    unaff_SI = (uint *)*puVar30;
    unaff_BP = (int *)puVar30[1];
    uVar13 = puVar30[5];
    uVar12 = puVar30[6];
    uVar17 = CONCAT11((char)(puVar30[3] >> 8),(byte)puVar30[3] | *(byte *)0x5d02) |
             *(uint *)((byte *)((int)unaff_BP + (int)puVar38) + 10);
    puVar30[6] = (uint)puVar38;
    pbVar1 = (byte *)((int)unaff_SI + uVar17 + 0x2c2);
    cVar44 = SCARRY1((char)uVar12,*pbVar1);
    bVar39 = (char)((char)uVar12 + *pbVar1) < '\0';
    puVar31 = puVar30 + 5;
    puVar30[5] = 0x3a83;
    uVar45 = func_0x00013e95();
    bVar6 = (byte)uVar45;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar17;
    cVar16 = (char)((ulong)uVar45 >> 0x18);
    if (bVar39) {
      bVar14 = (byte)(uVar17 >> 8);
      puVar34 = (uint *)((int)puVar38 + -0x53);
      uVar4 = (uint)(bVar14 < (byte)(uVar13 >> 8));
      uVar7 = *puVar34;
      uVar8 = *puVar34;
      *puVar34 = uVar8 + 0xe02d + uVar4;
      bVar11 = *(byte *)((int)unaff_BP + (int)puVar38);
      bVar14 = bVar14 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar45 >> 8);
      uVar17 = CONCAT11(bVar14,(char)uVar17);
      if ((char)bVar14 < '\0') {
        bVar39 = unaff_SI[3] < 1000;
        if (!bVar39) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar31 + -2) = 0x3b26;
          puVar31 = (uint *)((int)puVar31 + -2);
          uVar45 = func_0x00013966();
          if (!bVar39) goto LAB_1000_3b55_1;
        }
        puVar33 = (undefined1 *)((int)puVar31 + -2);
        *(undefined2 *)((int)puVar31 + -2) = 0x3b2d;
        uVar46 = FUN_1000_8cb7();
        uVar7 = (uint)(uVar46 >> 0x10);
        bVar39 = (byte)uVar46 < 0x5a;
        if (bVar39) {
          bVar39 = true;
          if ((byte)uVar46 < 0x50) goto LAB_1000_3b62;
          puVar25 = puVar33 + -2;
          *(undefined2 *)(puVar33 + -2) = 0x3b38;
          bVar39 = false;
          goto code_r0x000138eb;
        }
        puVar32 = puVar33 + -2;
        *(undefined2 *)(puVar33 + -2) = 0x3b42;
        uVar45 = FUN_1000_3607();
        bVar6 = (byte)uVar45;
        if (bVar39) {
          puVar23 = puVar32 + -2;
          *(undefined2 *)(puVar32 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar46 = CONCAT22((int)((ulong)uVar45 >> 0x10),
                          CONCAT11((char)((ulong)uVar45 >> 8),(char)uVar45 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar34 = (uint *)ZEXT24((undefined1 *)((int)puVar31 + -2));
      *(undefined2 *)((int)puVar31 + -2) = unaff_CS;
      iVar15 = CONCAT11(cVar16 - *(byte *)((int)unaff_SI + uVar17 + 0x23c9),
                        (char)((ulong)uVar45 >> 0x10) + bVar11 +
                        (0x1fd2 < uVar7 || CARRY2(uVar8 + 0xe02d,uVar4)));
      ((byte *)((int)unaff_BP + (int)puVar38))[0x5555] =
           ((byte *)((int)unaff_BP + (int)puVar38))[0x5555] + (char)uVar13;
      goto code_r0x00013aab;
    }
    if (cVar44 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar16;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar17 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar31 + 10),*(undefined2 *)((int)puVar31 + 0xe));
}


