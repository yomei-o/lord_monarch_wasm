/* 1000:3790 */

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

ulong FUN_1000_3790(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  byte bVar7;
  undefined2 in_AX;
  undefined2 uVar8;
  uint uVar9;
  int *piVar10;
  byte bVar13;
  int *piVar11;
  undefined2 uVar12;
  undefined2 in_CX;
  uint uVar14;
  byte bVar15;
  uint in_DX;
  char cVar17;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar16;
  uint uVar18;
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
  uint *puVar34;
  int *unaff_BP;
  int iVar35;
  uint *unaff_SI;
  int iVar36;
  int unaff_DI;
  uint *puVar37;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar38;
  byte in_AF;
  undefined1 uVar39;
  bool bVar40;
  bool bVar41;
  bool bVar42;
  char cVar43;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar44;
  ulong uVar45;
  int *piVar46;
  
  iVar19 = (int)in_ESP;
  uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
  *(undefined2 *)(iVar19 + -2) = in_AX;
  *(uint *)(iVar19 + -4) = in_DX;
  *(undefined2 *)(iVar19 + -6) = in_CX;
  *(uint *)(iVar19 + -8) = in_DX;
  puVar20 = (undefined1 *)(iVar19 + -10);
  *(undefined2 *)(iVar19 + -10) = 0x3799;
  uVar44 = func_0x0001ae87();
  *(int *)(puVar20 + -2) = (int)uVar44;
  *(uint *)(puVar20 + -4) = in_DX;
  *(undefined2 *)(puVar20 + -6) = 9;
  *(int *)(puVar20 + -8) = (int)((ulong)uVar44 >> 0x10);
  *(undefined2 *)(puVar20 + -10) = 0x37a1;
  uVar44 = func_0x0001af48();
  if ((uint)unaff_BP[-5] <= (uint)uVar44) {
    in_DX = unaff_BP[-6];
    uVar44 = CONCAT22(unaff_BP[-8],unaff_BP[-5]);
  }
  *(uint *)(byte *)(in_DX + (int)unaff_SI) =
       *(int *)(byte *)(in_DX + (int)unaff_SI) + (int)((ulong)uVar44 >> 0x10) +
       (uint)((uint)uVar44 < (uint)unaff_BP[-1]);
  uVar18 = (uint)(byte)((char)uVar44 + (char)((ulong)uVar44 >> 8) * 't');
  pcVar2 = (char *)((int)unaff_BP + unaff_DI + -0x3a2);
  *pcVar2 = *pcVar2 + -1;
  iVar16 = unaff_BP[-3];
  iVar35 = unaff_BP[-4];
  uVar14 = uVar18 - unaff_BP[7];
  uVar39 = uVar14 == 0;
  if (uVar18 < (uint)unaff_BP[7]) {
    uVar14 = unaff_SI[3] + uVar18 * -2;
    uVar39 = uVar14 == 0;
    if (uVar18 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar16;
      unaff_SI[4] = in_DX;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      piVar21 = unaff_BP + -1;
      unaff_BP[-1] = 0x37e2;
      func_0x0001ab65();
      puVar23 = (undefined1 *)((int)piVar21 + -2);
      *(undefined2 *)((int)piVar21 + -2) = 0x37e5;
      bVar7 = func_0x0001b496();
      if (!(bool)uVar39) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar7;
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
  piVar10 = unaff_BP + -1;
  unaff_BP[-1] = unaff_DS;
  puVar34 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar45 = CONCAT22(iVar35,CONCAT11(((int)uVar14 < 0) << 7 | uVar39 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar14 & 0xff) & 1U) == 0) << 2,(byte)*puVar34)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar34;
  if (unaff_DI != -1) {
    iVar36 = *unaff_BP;
    iVar35 = unaff_BP[1];
    uVar8 = unaff_BP[6];
    pcVar2 = (char *)(iVar35 + iVar36);
    *pcVar2 = *pcVar2 + (byte)uVar8;
    iVar16 = unaff_BP[7];
    pbVar1 = (byte *)(iVar35 + iVar36);
    *pbVar1 = *pbVar1 ^ (byte)uVar8;
    *(int *)(iVar16 + -2) = iVar35;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar14 = iVar16 + *(int *)(byte *)((int)unaff_SI + in_DX + 0xb44);
  puVar37 = (uint *)0x0;
code_r0x0001387f:
  uVar18 = (uint)(uVar45 >> 0x10);
  uVar9 = CONCAT11((char)(uVar45 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar7 = (byte)uVar9;
  *(byte *)(unaff_SI + 5) = bVar7;
  swi(4);
  pbVar1 = (byte *)((int)unaff_BP + (int)unaff_SI);
  *pbVar1 = *pbVar1 + bVar7;
  if ((POPCOUNT(*pbVar1) & 1U) != 0) {
    pbVar1 = (byte *)((int)unaff_SI + in_DX + 0x33);
    bVar7 = *pbVar1;
    bVar15 = (byte)(uVar45 >> 0x10);
    bVar13 = *pbVar1;
    cVar17 = (char)(uVar45 >> 0x18) + *(byte *)(in_DX + (int)unaff_SI);
    *(byte *)(puVar37 + 0x39) = (byte)puVar37[0x39] - cVar17;
    ((byte *)((int)unaff_BP + (int)puVar37))[-0x178e] =
         ((byte *)((int)unaff_BP + (int)puVar37))[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar17,bVar15 + bVar13),
                         (uVar9 + 0x5556) - (uint)CARRY1(bVar15,bVar7)) % (ulong)unaff_SI[0x410]);
    *(int *)(byte *)((int)unaff_BP + (int)puVar37) =
         *(int *)(byte *)((int)unaff_BP + (int)puVar37) >> 0x10;
    return CONCAT22(piVar10[1],*piVar10);
  }
  puVar31 = unaff_SI;
  if (*pbVar1 == 0) goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar38 = CARRY1((byte)in_DX,*(byte *)((int)unaff_BP + (int)unaff_SI));
  in_DX = CONCAT11((char)(in_DX >> 8),(byte)in_DX + *(byte *)((int)unaff_BP + (int)unaff_SI));
  puVar25 = (undefined1 *)piVar10;
code_r0x000138eb:
  *(undefined2 *)(puVar25 + -2) = unaff_SS;
  if (!bVar38) {
    puVar34 = puVar37;
    puVar37 = (uint *)((int)puVar37 + 1);
    *(byte *)puVar34 = 0x30;
    uVar9 = CONCAT11(0xaa,*(byte *)((int)unaff_BP + (int)puVar37) | 0x30) ^ 0x8a0;
    *(uint *)(puVar25 + -2) = in_DX;
    *(uint *)(puVar25 + -4) = uVar9;
    in_DX = unaff_SI[0x15];
    uVar18 = (uVar18 | 0x3000) - *(int *)(byte *)(in_DX + (int)unaff_SI);
    bVar13 = (byte)(uVar9 >> 8);
    bVar7 = (char)uVar9 + 8;
    if (bVar7 != *(byte *)(in_DX + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar25 + -6) = CONCAT11(bVar13,bVar7);
    *(uint *)(puVar25 + -8) = uVar14;
    *(uint *)(puVar25 + -10) = uVar18;
    *(uint *)(puVar25 + -0xc) = in_DX;
    *(undefined1 **)(puVar25 + -0xe) = puVar25 + -4;
    *(int **)(puVar25 + -0x10) = unaff_BP;
    *(uint **)(puVar25 + -0x12) = unaff_SI;
    *(uint **)(puVar25 + -0x14) = puVar37;
    uVar9 = *puVar37;
    cVar17 = (char)(uVar14 >> 8);
    bVar15 = cVar17 + bVar7;
    uVar14 = CONCAT11(bVar15,(char)uVar14);
    unaff_BP = (int *)0x874;
    if (SCARRY1(cVar17,bVar7)) {
      piVar10 = *(int **)(puVar25 + -0x14);
      puVar31 = *(uint **)(byte *)((int)puVar37 + (in_DX - 0x18));
      puVar34 = puVar31 + 0x43a;
      uVar4 = *puVar34;
      *puVar34 = *puVar34 + 0x809;
      uVar14 = 0x4379;
      puVar31[0x43a] =
           puVar31[0x43a] + CONCAT11(bVar13 | (byte)uVar9,bVar7 | bVar15) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar25 + -0x16) = 0x874;
      piVar10 = (int *)(puVar25 + -0x18);
      *(undefined2 *)(puVar25 + -0x18) = 0x874;
      puVar31 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar37 + 0x55) = *(int *)(byte *)((int)puVar37 + 0x55) + uVar18;
    unaff_SI = (uint *)((int)puVar31 + 1);
    out((byte)*puVar31,uVar18);
    uVar9 = CONCAT11((byte)(in_DX >> 8) & ((byte *)((int)unaff_BP + (int)unaff_SI))[0x11],
                     (char)in_DX);
    bVar13 = (byte)uVar18;
    cVar43 = SBORROW1(bVar13,(byte)puVar31[0x39]);
    bVar7 = (byte)puVar31[0x39];
    cVar17 = (char)(bVar13 - bVar7) < '\0';
    bVar38 = bVar13 == bVar7;
    puVar26 = (uint *)((int)piVar10 + -2);
    *(undefined2 *)((int)piVar10 + -2) = 0x396b;
    bVar7 = func_0x0001b3ed();
    iVar16 = extraout_DX_00;
    if (!bVar38) {
      *(byte *)(puVar31 + 6) = bVar7;
      *(undefined2 *)((int)puVar26 + -2) = 0x3973;
      puVar26 = (uint *)((int)puVar26 + -2);
      bVar7 = func_0x0001b617();
      iVar16 = extraout_DX_01;
    }
    if (cVar43 != cVar17) {
      iVar16 = iVar16 + 1;
      puVar26[-1] = (uint)puVar37;
      puVar26[-2] = iVar16;
      puVar26[-3] = CONCAT11((char)(uVar14 >> 8),8);
      puVar26[-4] = uVar9;
      if (iVar16 == 0) {
LAB_1000_39c7:
        pcVar6 = (code *)swi(1);
        uVar45 = (*pcVar6)();
        return uVar45;
      }
      ((byte *)((int)unaff_BP + (int)puVar37))[0x6e] =
           ((byte *)((int)unaff_BP + (int)puVar37))[0x6e] | (byte)((uint)iVar16 >> 8);
code_r0x00013985:
      pbVar1 = (byte *)((int)puVar37 + uVar9 + 0x12);
      *(byte **)pbVar1 = (byte *)((int)puVar37 + *(int *)pbVar1 + 2);
      puVar27 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar27 + -2) = 0x399f;
      func_0x00018e51();
      pcVar6 = (code *)swi(3);
      uVar45 = (*pcVar6)();
      return uVar45;
    }
    bVar7 = bVar7 ^ *(byte *)((int)unaff_BP + (int)unaff_SI);
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    bVar7 = bVar7 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar26;
    bVar38 = bVar7 < ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1] ||
             bVar7 == ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1];
    puVar34 = (uint *)CONCAT22(uVar8,puVar26);
    *puVar26 = 0x39ba;
    piVar46 = (int *)FUN_1000_a1b8();
    piVar10 = (int *)piVar46;
    if (bVar38) {
      if (uVar14 == 1) {
        do {
          iVar16 = 0x40;
          piVar11 = piVar10;
          do {
            uVar14 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar31 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar34 = puVar34 + -2;
              *puVar34 = unaff_DS;
              bVar7 = (byte)piVar11 | 0x17;
              bVar13 = (byte)((uint)piVar11 >> 8);
              if (bVar13 == (byte)unaff_SI[6]) {
                piVar11 = (int *)CONCAT11(bVar7 / 0x5e,bVar7 % 0x5e);
                puVar31 = puVar37;
                goto code_r0x00013a16;
              }
              uVar14 = CONCAT11(bVar13 & *(byte *)((int)unaff_BP + (int)unaff_SI),(byte)piVar11) |
                       0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar16 >> 8);
              *(byte *)((int)unaff_BP + (int)puVar37) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 2);
              piVar11 = (int *)*(uint *)puVar34;
              puVar34 = (uint *)CONCAT22((int)((ulong)puVar34 >> 0x10),(uint *)puVar34 + 1);
              puVar31 = unaff_SI + 8;
              puVar37 = unaff_SI;
            }
            iVar16 = iVar16 + -1;
            unaff_SI = puVar31;
          } while (iVar16 != 0);
          unaff_SI = (uint *)*(uint *)puVar34;
          puVar34 = (uint *)CONCAT22((int)((ulong)puVar34 >> 0x10),(uint *)puVar34 + 1);
          puVar31 = puVar37;
code_r0x00013a16:
          uVar8 = (undefined2)((ulong)puVar34 >> 0x10);
          puVar28 = (uint *)puVar34;
          if (0x1ef < uVar14) goto code_r0x00013a1c;
          ((byte *)((int)unaff_BP + (int)puVar31))[0x59] =
               ((byte *)((int)unaff_BP + (int)puVar31))[0x59] | (byte)uVar14;
          bVar7 = *(byte *)(uVar14 + puVar28[1]);
          puVar28[1] = (uint)unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar14 + ((byte)((char)unaff_BP + 1U) < bVar7);
          piVar10 = (int *)CONCAT11((char)((uint)unaff_BP >> 8),(char)unaff_BP + -0x3b);
          puVar37 = (uint *)puVar28[1];
          puVar34 = (uint *)CONCAT22(uVar8,puVar28 + 2);
          unaff_SI = (uint *)0xc800;
          unaff_BP = piVar11;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)piVar46 >> 0x10),(char)piVar46);
    puVar3 = unaff_SI;
    bVar38 = CARRY2(*puVar3,(uint)piVar10);
    *puVar3 = *puVar3 + (int)piVar10;
    bVar41 = (int)*puVar3 < 0;
    bVar40 = *puVar3 == 0;
    bVar7 = POPCOUNT(*puVar3 & 0xff);
    uVar14 = uVar14 - 1;
    if (uVar14 == 0 || bVar40) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  in_DX = in_DX + 1;
  puVar23 = puVar25 + -4;
  *(undefined2 *)(puVar25 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar18;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar23 = puVar33;
  if (bVar38) {
    puVar23 = puVar33 + -2;
    *(undefined2 *)(puVar33 + -2) = 0x3b67;
    uVar45 = func_0x000137e6();
    bVar7 = (byte)uVar45;
    if (bVar38) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar45;
  }
  *(int **)(puVar23 + -2) = unaff_BP;
  puVar33 = puVar23 + -4;
  *(int **)(puVar23 + -4) = unaff_BP;
  pbVar1 = (byte *)(in_DX + (int)unaff_SI);
  bVar7 = (byte)(uVar45 >> 8);
  bVar38 = CARRY1(*pbVar1,bVar7);
  *pbVar1 = *pbVar1 + bVar7;
  in_DX = in_DX - 1;
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar38 = bVar7 < 0x10;
  bVar42 = SBORROW1(bVar7,'\x10');
  bVar41 = (char)(bVar7 - 0x10) < '\0';
  bVar40 = bVar7 == 0x10;
  if (!bVar38) {
    if (7 < bVar7) {
      bVar42 = SBORROW1(bVar7,'\f');
      bVar41 = (char)(bVar7 - 0xc) < '\0';
      bVar40 = bVar7 == 0xc;
      bVar38 = true;
      if (bVar7 < 0xc) goto LAB_1000_383e;
    }
    if (bVar7 != 0) {
      bVar42 = SBORROW1(bVar7,'\x05');
      bVar41 = (char)(bVar7 - 5) < '\0';
      bVar40 = bVar7 == 5;
      bVar38 = true;
      if (bVar7 < 5) goto LAB_1000_383e;
    }
    bVar38 = bVar7 < 5;
    bVar42 = SBORROW1(bVar7,'\x05');
    bVar41 = (char)(bVar7 - 5) < '\0';
    bVar40 = bVar7 == 5;
    if (!bVar40) {
      uVar14 = CONCAT11(((byte *)((int)unaff_BP + (int)puVar37))[-0x80],0xb);
      pbVar1 = (byte *)(in_DX + (int)unaff_SI);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      piVar10 = (int *)(puVar23 + -2);
      *(undefined2 *)(puVar23 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(in_DX + (int)unaff_SI) = *(byte *)(in_DX + (int)unaff_SI) & (byte)uVar14;
      LOCK();
      iVar16 = unaff_BP[0x39];
      *(char *)(unaff_BP + 0x39) = (char)((uint)extraout_DX >> 8);
      uVar18 = CONCAT11((char)iVar16,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar38) {
    *(undefined2 *)(puVar23 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar40 && bVar42 == bVar41) {
    return CONCAT22(unaff_BP[5],unaff_BP[7]);
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar7 ^ 0xf8) & 0xf) | in_AF;
  pbVar1 = (byte *)((int)puVar37 + in_DX + 0x854);
  *pbVar1 = *pbVar1 & 0xb;
  uVar39 = *pbVar1 == 0;
  puVar24 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  piVar10 = (int *)(puVar24 + -2);
  *(undefined2 *)(puVar24 + -2) = 0x387a;
  uVar45 = func_0x0001b476();
  if (!(bool)uVar39) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar45;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar28;
  *(longdouble *)(uVar14 + (int)puVar31) = in_ST0;
  puVar34 = (uint *)CONCAT22(uVar8,(uint *)(puVar28[1] + -2));
  *(undefined2 *)(puVar28[1] + -2) = unaff_ES;
  uVar9 = puVar31[2];
  piVar10 = (int *)(uint)*(byte *)((int)puVar31 + -0x79);
  bVar38 = (byte)iVar16 < *(byte *)((int)unaff_BP + (int)unaff_SI);
  cVar17 = (byte)iVar16 - *(byte *)((int)unaff_BP + (int)unaff_SI);
  uVar14 = CONCAT11((char)((uint)iVar16 >> 8),cVar17);
  bVar41 = cVar17 < '\0';
  bVar40 = cVar17 == '\0';
  bVar7 = POPCOUNT(cVar17);
  LOCK();
  puVar37 = (uint *)unaff_BP[-0x17];
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
  if (bVar40) {
    *(byte *)(uVar9 + (int)unaff_SI) = *(byte *)(uVar9 + (int)unaff_SI) + 1;
    puVar29 = (uint *)puVar34;
    puVar34 = (uint *)CONCAT22((int)((ulong)puVar34 >> 0x10),puVar29 + -1);
    puVar29[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar41 << 7 | bVar40 << 6 | in_AF << 4 | ((bVar7 & 1) == 0) << 2 | 2 |
                          bVar38,(char)piVar10)) {
      ((byte *)((int)unaff_BP + (int)puVar37))[-0x54ee] =
           ((byte *)((int)unaff_BP + (int)puVar37))[-0x54ee] | (byte)(uVar9 >> 8);
      puVar3 = puVar37;
      puVar37 = (uint *)((int)puVar37 + 1);
      *(byte *)puVar3 = (char)piVar10 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = (int *)((int)unaff_BP + uVar14);
    pbVar1 = (byte *)((uVar9 >> 2) + (int)unaff_SI);
    *pbVar1 = *pbVar1 - 0x15;
    puVar3 = (uint *)((byte *)((int)unaff_BP + (int)puVar37) + 0x645);
    uVar18 = *puVar3;
    *puVar3 = *puVar3 - uVar14;
    bVar7 = ((char)(uVar9 >> 1) + (char)(uVar9 >> 2) + -0x10) - (uVar18 < uVar14) | 2;
    iVar16 = *(int *)(byte *)((int)puVar37 + 0x55);
code_r0x00013aab:
    *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) & bVar7;
    ((uint *)puVar34)[-1] = (uint)unaff_BP;
    *(byte *)((int)unaff_BP + (int)unaff_SI) =
         *(byte *)((int)unaff_BP + (int)unaff_SI) & (byte)uVar14;
    puVar31 = (uint *)0xf029;
    *(uint *)0xf029 = (uint)unaff_BP;
    if (iVar16 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) | bVar7;
      pcVar6 = (code *)swi(1);
      uVar45 = (*pcVar6)();
      return uVar45;
    }
    uVar18 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar18 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar6 = (code *)swi(0x20);
    (*pcVar6)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar9 >> 8);
    puVar30 = (uint *)puVar34;
    uVar8 = (undefined2)((ulong)puVar34 >> 0x10);
    puVar30[-1] = unaff_ES;
    pbVar1 = (byte *)((int)unaff_SI + uVar9 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)puVar37);
    puVar37 = (uint *)puVar30[-1];
    unaff_SI = (uint *)*puVar30;
    unaff_BP = (int *)puVar30[1];
    uVar14 = puVar30[5];
    uVar12 = puVar30[6];
    uVar18 = CONCAT11((char)(puVar30[3] >> 8),(byte)puVar30[3] | *(byte *)0x5d02) |
             *(uint *)((byte *)((int)unaff_BP + (int)puVar37) + 10);
    puVar30[6] = (uint)puVar37;
    pbVar1 = (byte *)((int)unaff_SI + uVar18 + 0x2c2);
    cVar43 = SCARRY1((char)uVar12,*pbVar1);
    bVar38 = (char)((char)uVar12 + *pbVar1) < '\0';
    puVar31 = puVar30 + 5;
    puVar30[5] = 0x3a83;
    uVar44 = func_0x00013e95();
    bVar7 = (byte)uVar44;
    out(0x6f,bVar7);
    *(undefined1 *)0x1108 = (char)uVar18;
    cVar17 = (char)((ulong)uVar44 >> 0x18);
    if (bVar38) {
      bVar15 = (byte)(uVar18 >> 8);
      puVar34 = (uint *)((int)puVar37 + -0x53);
      uVar5 = (uint)(bVar15 < (byte)(uVar14 >> 8));
      uVar9 = *puVar34;
      uVar4 = *puVar34;
      *puVar34 = uVar4 + 0xe02d + uVar5;
      bVar13 = *(byte *)((int)unaff_BP + (int)puVar37);
      bVar15 = bVar15 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar44 >> 8);
      in_DX = CONCAT11(bVar15,(char)uVar18);
      if ((char)bVar15 < '\0') {
        bVar38 = unaff_SI[3] < 1000;
        if (!bVar38) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar31 + -2) = 0x3b26;
          puVar31 = (uint *)((int)puVar31 + -2);
          uVar44 = func_0x00013966();
          if (!bVar38) goto LAB_1000_3b55_1;
        }
        puVar33 = (undefined1 *)((int)puVar31 + -2);
        *(undefined2 *)((int)puVar31 + -2) = 0x3b2d;
        uVar45 = FUN_1000_8cb7();
        uVar18 = (uint)(uVar45 >> 0x10);
        bVar38 = (byte)uVar45 < 0x5a;
        if (bVar38) {
          bVar38 = true;
          if ((byte)uVar45 < 0x50) goto LAB_1000_3b62;
          puVar25 = puVar33 + -2;
          *(undefined2 *)(puVar33 + -2) = 0x3b38;
          bVar38 = false;
          goto code_r0x000138eb;
        }
        puVar32 = puVar33 + -2;
        *(undefined2 *)(puVar33 + -2) = 0x3b42;
        uVar44 = FUN_1000_3607();
        bVar7 = (byte)uVar44;
        if (bVar38) {
          puVar23 = puVar32 + -2;
          *(undefined2 *)(puVar32 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar45 = CONCAT22((int)((ulong)uVar44 >> 0x10),
                          CONCAT11((char)((ulong)uVar44 >> 8),(char)uVar44 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar34 = (uint *)ZEXT24((undefined1 *)((int)puVar31 + -2));
      *(undefined2 *)((int)puVar31 + -2) = unaff_CS;
      iVar16 = CONCAT11(cVar17 - *(byte *)((int)unaff_SI + in_DX + 0x23c9),
                        (char)((ulong)uVar44 >> 0x10) + bVar13 +
                        (0x1fd2 < uVar9 || CARRY2(uVar4 + 0xe02d,uVar5)));
      ((byte *)((int)unaff_BP + (int)puVar37))[0x5555] =
           ((byte *)((int)unaff_BP + (int)puVar37))[0x5555] + (char)uVar14;
      goto code_r0x00013aab;
    }
    if (cVar43 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar17;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar18 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar31 + 10),*(undefined2 *)((int)puVar31 + 0xe));
}


