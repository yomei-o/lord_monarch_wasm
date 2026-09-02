/* 1000:3769 */

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

ulong FUN_1000_3769(void)

{
  char *pcVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  byte bVar7;
  uint in_AX;
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
  uint in_BX;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined1 *puVar21;
  int *piVar22;
  undefined2 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  uint *puVar27;
  undefined1 *puVar28;
  uint *puVar29;
  uint *puVar30;
  uint *puVar31;
  uint *puVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined4 in_ESP;
  uint *puVar35;
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
  
  pbVar3 = (byte *)((int)unaff_SI + in_BX + 0xfb);
  *pbVar3 = *pbVar3 + (char)in_AX;
  if ((*pbVar3 != 0) && ((bVar7 = (byte)in_BX, bVar7 < 0xc || (0xf < bVar7)))) {
    in_CX = 4;
    unaff_DI = unaff_DI | *(uint *)(in_BX + unaff_DI + 0xb);
    if (bVar7 != 5) {
      in_CX = 8;
    }
    iVar19 = (int)in_ESP;
    *(uint *)(iVar19 + -2) = in_AX | 0x6c72;
    in_ESP = CONCAT22((int)((ulong)in_ESP >> 0x10),iVar19 + -4);
    *(uint *)(iVar19 + -4) = in_DX;
    in_BX = in_DX;
  }
  iVar20 = (int)in_ESP;
  uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
  *(undefined2 *)(iVar20 + -2) = in_CX;
  *(uint *)(iVar20 + -4) = in_DX;
  puVar21 = (undefined1 *)(iVar20 + -6);
  *(undefined2 *)(iVar20 + -6) = 0x3799;
  uVar45 = func_0x0001ae87();
  *(int *)(puVar21 + -2) = (int)uVar45;
  *(uint *)(puVar21 + -4) = in_BX;
  *(undefined2 *)(puVar21 + -6) = 9;
  *(int *)(puVar21 + -8) = (int)((ulong)uVar45 >> 0x10);
  *(undefined2 *)(puVar21 + -10) = 0x37a1;
  uVar45 = func_0x0001af48();
  if ((uint)unaff_BP[-5] <= (uint)uVar45) {
    in_BX = unaff_BP[-6];
    uVar45 = CONCAT22(unaff_BP[-8],unaff_BP[-5]);
  }
  *(uint *)(byte *)(in_BX + (int)unaff_SI) =
       *(int *)(byte *)(in_BX + (int)unaff_SI) + (int)((ulong)uVar45 >> 0x10) +
       (uint)((uint)uVar45 < (uint)unaff_BP[-1]);
  uVar18 = (uint)(byte)((char)uVar45 + (char)((ulong)uVar45 >> 8) * 't');
  pcVar1 = (char *)((int)unaff_BP + (unaff_DI - 0x3a2));
  *pcVar1 = *pcVar1 + -1;
  iVar16 = unaff_BP[-3];
  iVar36 = unaff_BP[-4];
  uVar14 = uVar18 - unaff_BP[7];
  uVar40 = uVar14 == 0;
  if (uVar18 < (uint)unaff_BP[7]) {
    uVar14 = unaff_SI[3] + uVar18 * -2;
    uVar40 = uVar14 == 0;
    if (uVar18 * 2 <= unaff_SI[3]) {
      *(byte *)(unaff_SI + 5) = (byte)iVar16;
      unaff_SI[4] = in_BX;
      *(byte *)((int)unaff_SI + 0xf) = 4;
      piVar22 = unaff_BP + -1;
      unaff_BP[-1] = 0x37e2;
      func_0x0001ab65();
      puVar24 = (undefined1 *)((int)piVar22 + -2);
      *(undefined2 *)((int)piVar22 + -2) = 0x37e5;
      bVar7 = func_0x0001b496();
      if (!(bool)uVar40) {
code_r0x000137e7:
        *(byte *)((int)unaff_SI + 0xb) = bVar7;
        if ((byte)unaff_SI[5] == 0xb) {
          puVar23 = (undefined2 *)(puVar24 + -2);
          puVar24 = puVar24 + -2;
          *puVar23 = 0x37f3;
          func_0x0001b6c0();
        }
      }
      return CONCAT22(*(undefined2 *)(puVar24 + 10),*(undefined2 *)(puVar24 + 0xe));
    }
  }
  piVar10 = unaff_BP + -1;
  unaff_BP[-1] = unaff_DS;
  puVar35 = unaff_SI;
  unaff_SI = (uint *)((int)unaff_SI + 1);
  uVar46 = CONCAT22(iVar36,CONCAT11(((int)uVar14 < 0) << 7 | uVar40 << 6 | in_AF << 4 |
                                    ((POPCOUNT(uVar14 & 0xff) & 1U) == 0) << 2,(byte)*puVar35)) |
           0x300;
  *(byte *)unaff_SI = (byte)*unaff_SI & (byte)*puVar35;
  if (unaff_DI != 0xffff) {
    iVar37 = *unaff_BP;
    iVar36 = unaff_BP[1];
    uVar8 = unaff_BP[6];
    pcVar1 = (char *)(iVar36 + iVar37);
    *pcVar1 = *pcVar1 + (byte)uVar8;
    iVar16 = unaff_BP[7];
    pbVar3 = (byte *)(iVar36 + iVar37);
    *pbVar3 = *pbVar3 ^ (byte)uVar8;
    *(int *)(iVar16 + -2) = iVar36;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar14 = iVar16 + *(int *)(byte *)((int)unaff_SI + in_BX + 0xb44);
  puVar38 = (uint *)0x0;
code_r0x0001387f:
  uVar18 = (uint)(uVar46 >> 0x10);
  uVar9 = CONCAT11((char)(uVar46 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
  bVar7 = (byte)uVar9;
  *(byte *)(unaff_SI + 5) = bVar7;
  swi(4);
  pbVar3 = (byte *)((int)unaff_BP + (int)unaff_SI);
  *pbVar3 = *pbVar3 + bVar7;
  if ((POPCOUNT(*pbVar3) & 1U) != 0) {
    pbVar3 = (byte *)((int)unaff_SI + in_BX + 0x33);
    bVar7 = *pbVar3;
    bVar15 = (byte)(uVar46 >> 0x10);
    bVar13 = *pbVar3;
    cVar17 = (char)(uVar46 >> 0x18) + *(byte *)(in_BX + (int)unaff_SI);
    *(byte *)(puVar38 + 0x39) = (byte)puVar38[0x39] - cVar17;
    ((byte *)((int)unaff_BP + (int)puVar38))[-0x178e] =
         ((byte *)((int)unaff_BP + (int)puVar38))[-0x178e] |
         (byte)(CONCAT22(CONCAT11(cVar17,bVar15 + bVar13),
                         (uVar9 + 0x5556) - (uint)CARRY1(bVar15,bVar7)) % (ulong)unaff_SI[0x410]);
    *(int *)(byte *)((int)unaff_BP + (int)puVar38) =
         *(int *)(byte *)((int)unaff_BP + (int)puVar38) >> 0x10;
    return CONCAT22(piVar10[1],*piVar10);
  }
  puVar32 = unaff_SI;
  if (*pbVar3 == 0) goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar39 = CARRY1((byte)in_BX,*(byte *)((int)unaff_BP + (int)unaff_SI));
  in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)((int)unaff_BP + (int)unaff_SI));
  puVar26 = (undefined1 *)piVar10;
code_r0x000138eb:
  *(undefined2 *)(puVar26 + -2) = unaff_SS;
  if (!bVar39) {
    puVar35 = puVar38;
    puVar38 = (uint *)((int)puVar38 + 1);
    *(byte *)puVar35 = 0x30;
    uVar9 = CONCAT11(0xaa,*(byte *)((int)unaff_BP + (int)puVar38) | 0x30) ^ 0x8a0;
    *(uint *)(puVar26 + -2) = in_BX;
    *(uint *)(puVar26 + -4) = uVar9;
    in_BX = unaff_SI[0x15];
    uVar18 = (uVar18 | 0x3000) - *(int *)(byte *)(in_BX + (int)unaff_SI);
    bVar13 = (byte)(uVar9 >> 8);
    bVar7 = (char)uVar9 + 8;
    if (bVar7 != *(byte *)(in_BX + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(uint *)(puVar26 + -6) = CONCAT11(bVar13,bVar7);
    *(uint *)(puVar26 + -8) = uVar14;
    *(uint *)(puVar26 + -10) = uVar18;
    *(uint *)(puVar26 + -0xc) = in_BX;
    *(undefined1 **)(puVar26 + -0xe) = puVar26 + -4;
    *(int **)(puVar26 + -0x10) = unaff_BP;
    *(uint **)(puVar26 + -0x12) = unaff_SI;
    *(uint **)(puVar26 + -0x14) = puVar38;
    uVar9 = *puVar38;
    cVar17 = (char)(uVar14 >> 8);
    bVar15 = cVar17 + bVar7;
    uVar14 = CONCAT11(bVar15,(char)uVar14);
    unaff_BP = (int *)0x874;
    if (SCARRY1(cVar17,bVar7)) {
      piVar10 = *(int **)(puVar26 + -0x14);
      puVar32 = *(uint **)(byte *)((int)puVar38 + (in_BX - 0x18));
      puVar35 = puVar32 + 0x43a;
      uVar4 = *puVar35;
      *puVar35 = *puVar35 + 0x809;
      uVar14 = 0x4379;
      puVar32[0x43a] =
           puVar32[0x43a] + CONCAT11(bVar13 | (byte)uVar9,bVar7 | bVar15) + (uint)(0xf7f6 < uVar4);
    }
    else {
      *(undefined2 *)(puVar26 + -0x16) = 0x874;
      piVar10 = (int *)(puVar26 + -0x18);
      *(undefined2 *)(puVar26 + -0x18) = 0x874;
      puVar32 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)puVar38 + 0x55) = *(int *)(byte *)((int)puVar38 + 0x55) + uVar18;
    unaff_SI = (uint *)((int)puVar32 + 1);
    out((byte)*puVar32,uVar18);
    uVar9 = CONCAT11((byte)(in_BX >> 8) & ((byte *)((int)unaff_BP + (int)unaff_SI))[0x11],
                     (char)in_BX);
    bVar13 = (byte)uVar18;
    cVar44 = SBORROW1(bVar13,(byte)puVar32[0x39]);
    bVar7 = (byte)puVar32[0x39];
    cVar17 = (char)(bVar13 - bVar7) < '\0';
    bVar39 = bVar13 == bVar7;
    puVar27 = (uint *)((int)piVar10 + -2);
    *(undefined2 *)((int)piVar10 + -2) = 0x396b;
    bVar7 = func_0x0001b3ed();
    iVar16 = extraout_DX_00;
    if (!bVar39) {
      *(byte *)(puVar32 + 6) = bVar7;
      *(undefined2 *)((int)puVar27 + -2) = 0x3973;
      puVar27 = (uint *)((int)puVar27 + -2);
      bVar7 = func_0x0001b617();
      iVar16 = extraout_DX_01;
    }
    if (cVar44 != cVar17) {
      iVar16 = iVar16 + 1;
      puVar27[-1] = (uint)puVar38;
      puVar27[-2] = iVar16;
      puVar27[-3] = CONCAT11((char)(uVar14 >> 8),8);
      puVar27[-4] = uVar9;
      if (iVar16 == 0) {
LAB_1000_39c7:
        pcVar6 = (code *)swi(1);
        uVar46 = (*pcVar6)();
        return uVar46;
      }
      ((byte *)((int)unaff_BP + (int)puVar38))[0x6e] =
           ((byte *)((int)unaff_BP + (int)puVar38))[0x6e] | (byte)((uint)iVar16 >> 8);
code_r0x00013985:
      pbVar3 = (byte *)((int)puVar38 + uVar9 + 0x12);
      *(byte **)pbVar3 = (byte *)((int)puVar38 + *(int *)pbVar3 + 2);
      puVar28 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar28 + -2) = 0x399f;
      func_0x00018e51();
      pcVar6 = (code *)swi(3);
      uVar46 = (*pcVar6)();
      return uVar46;
    }
    bVar7 = bVar7 ^ *(byte *)((int)unaff_BP + (int)unaff_SI);
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    bVar7 = bVar7 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar27;
    bVar39 = bVar7 < ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1] ||
             bVar7 == ((byte *)((int)unaff_BP + (int)unaff_SI))[-0x74a1];
    puVar35 = (uint *)CONCAT22(uVar8,puVar27);
    *puVar27 = 0x39ba;
    piVar47 = (int *)FUN_1000_a1b8();
    piVar10 = (int *)piVar47;
    if (bVar39) {
      if (uVar14 == 1) {
        do {
          iVar16 = 0x40;
          piVar11 = piVar10;
          do {
            uVar14 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar32 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar35 = puVar35 + -2;
              *puVar35 = unaff_DS;
              bVar7 = (byte)piVar11 | 0x17;
              bVar13 = (byte)((uint)piVar11 >> 8);
              if (bVar13 == (byte)unaff_SI[6]) {
                piVar11 = (int *)CONCAT11(bVar7 / 0x5e,bVar7 % 0x5e);
                puVar32 = puVar38;
                goto code_r0x00013a16;
              }
              uVar14 = CONCAT11(bVar13 & *(byte *)((int)unaff_BP + (int)unaff_SI),(byte)piVar11) |
                       0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar16 >> 8);
              *(byte *)((int)unaff_BP + (int)puVar38) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 2);
              piVar11 = (int *)*(uint *)puVar35;
              puVar35 = (uint *)CONCAT22((int)((ulong)puVar35 >> 0x10),(uint *)puVar35 + 1);
              puVar32 = unaff_SI + 8;
              puVar38 = unaff_SI;
            }
            iVar16 = iVar16 + -1;
            unaff_SI = puVar32;
          } while (iVar16 != 0);
          unaff_SI = (uint *)*(uint *)puVar35;
          puVar35 = (uint *)CONCAT22((int)((ulong)puVar35 >> 0x10),(uint *)puVar35 + 1);
          puVar32 = puVar38;
code_r0x00013a16:
          uVar8 = (undefined2)((ulong)puVar35 >> 0x10);
          puVar29 = (uint *)puVar35;
          if (0x1ef < uVar14) goto code_r0x00013a1c;
          ((byte *)((int)unaff_BP + (int)puVar32))[0x59] =
               ((byte *)((int)unaff_BP + (int)puVar32))[0x59] | (byte)uVar14;
          bVar7 = *(byte *)(uVar14 + puVar29[1]);
          puVar29[1] = (uint)unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar14 + ((byte)((char)unaff_BP + 1U) < bVar7);
          piVar10 = (int *)CONCAT11((char)((uint)unaff_BP >> 8),(char)unaff_BP + -0x3b);
          puVar38 = (uint *)puVar29[1];
          puVar35 = (uint *)CONCAT22(uVar8,puVar29 + 2);
          unaff_SI = (uint *)0xc800;
          unaff_BP = piVar11;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)piVar47 >> 0x10),(char)piVar47);
    puVar2 = unaff_SI;
    bVar39 = CARRY2(*puVar2,(uint)piVar10);
    *puVar2 = *puVar2 + (int)piVar10;
    bVar42 = (int)*puVar2 < 0;
    bVar41 = *puVar2 == 0;
    bVar7 = POPCOUNT(*puVar2 & 0xff);
    uVar14 = uVar14 - 1;
    if (uVar14 == 0 || bVar41) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  in_BX = in_BX + 1;
  puVar24 = puVar26 + -4;
  *(undefined2 *)(puVar26 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar18;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar24 = puVar34;
  if (bVar39) {
    puVar24 = puVar34 + -2;
    *(undefined2 *)(puVar34 + -2) = 0x3b67;
    uVar46 = func_0x000137e6();
    bVar7 = (byte)uVar46;
    if (bVar39) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar46;
  }
  *(int **)(puVar24 + -2) = unaff_BP;
  puVar34 = puVar24 + -4;
  *(int **)(puVar24 + -4) = unaff_BP;
  pbVar3 = (byte *)(in_BX + (int)unaff_SI);
  bVar7 = (byte)(uVar46 >> 8);
  bVar39 = CARRY1(*pbVar3,bVar7);
  *pbVar3 = *pbVar3 + bVar7;
  in_BX = in_BX - 1;
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar39 = bVar7 < 0x10;
  bVar43 = SBORROW1(bVar7,'\x10');
  bVar42 = (char)(bVar7 - 0x10) < '\0';
  bVar41 = bVar7 == 0x10;
  if (!bVar39) {
    if (7 < bVar7) {
      bVar43 = SBORROW1(bVar7,'\f');
      bVar42 = (char)(bVar7 - 0xc) < '\0';
      bVar41 = bVar7 == 0xc;
      bVar39 = true;
      if (bVar7 < 0xc) goto LAB_1000_383e;
    }
    if (bVar7 != 0) {
      bVar43 = SBORROW1(bVar7,'\x05');
      bVar42 = (char)(bVar7 - 5) < '\0';
      bVar41 = bVar7 == 5;
      bVar39 = true;
      if (bVar7 < 5) goto LAB_1000_383e;
    }
    bVar39 = bVar7 < 5;
    bVar43 = SBORROW1(bVar7,'\x05');
    bVar42 = (char)(bVar7 - 5) < '\0';
    bVar41 = bVar7 == 5;
    if (!bVar41) {
      uVar14 = CONCAT11(((byte *)((int)unaff_BP + (int)puVar38))[-0x80],0xb);
      pbVar3 = (byte *)(in_BX + (int)unaff_SI);
      *pbVar3 = *pbVar3 & 0xb;
      if (*pbVar3 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      piVar10 = (int *)(puVar24 + -2);
      *(undefined2 *)(puVar24 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)uVar14;
      LOCK();
      iVar16 = unaff_BP[0x39];
      *(char *)(unaff_BP + 0x39) = (char)((uint)extraout_DX >> 8);
      uVar18 = CONCAT11((char)iVar16,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar39) {
    *(undefined2 *)(puVar24 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar41 && bVar43 == bVar42) {
    return CONCAT22(unaff_BP[5],unaff_BP[7]);
  }
  goto code_r0x000137e7;
code_r0x0001386c:
  in_AF = 9 < ((bVar7 ^ 0xf8) & 0xf) | in_AF;
  pbVar3 = (byte *)((int)puVar38 + in_BX + 0x854);
  *pbVar3 = *pbVar3 & 0xb;
  uVar40 = *pbVar3 == 0;
  puVar25 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  piVar10 = (int *)(puVar25 + -2);
  *(undefined2 *)(puVar25 + -2) = 0x387a;
  uVar46 = func_0x0001b476();
  if (!(bool)uVar40) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar46;
  }
  goto code_r0x0001387f;
code_r0x00013a1c:
  unaff_SS = *puVar29;
  *(longdouble *)(uVar14 + (int)puVar32) = in_ST0;
  puVar35 = (uint *)CONCAT22(uVar8,(uint *)(puVar29[1] + -2));
  *(undefined2 *)(puVar29[1] + -2) = unaff_ES;
  uVar9 = puVar32[2];
  piVar10 = (int *)(uint)*(byte *)((int)puVar32 + -0x79);
  bVar39 = (byte)iVar16 < *(byte *)((int)unaff_BP + (int)unaff_SI);
  cVar17 = (byte)iVar16 - *(byte *)((int)unaff_BP + (int)unaff_SI);
  uVar14 = CONCAT11((char)((uint)iVar16 >> 8),cVar17);
  bVar42 = cVar17 < '\0';
  bVar41 = cVar17 == '\0';
  bVar7 = POPCOUNT(cVar17);
  LOCK();
  puVar38 = (uint *)unaff_BP[-0x17];
  unaff_BP[-0x17] = (int)puVar32;
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
    *(byte *)(uVar9 + (int)unaff_SI) = *(byte *)(uVar9 + (int)unaff_SI) + 1;
    puVar30 = (uint *)puVar35;
    puVar35 = (uint *)CONCAT22((int)((ulong)puVar35 >> 0x10),puVar30 + -1);
    puVar30[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar42 << 7 | bVar41 << 6 | in_AF << 4 | ((bVar7 & 1) == 0) << 2 | 2 |
                          bVar39,(char)piVar10)) {
      ((byte *)((int)unaff_BP + (int)puVar38))[-0x54ee] =
           ((byte *)((int)unaff_BP + (int)puVar38))[-0x54ee] | (byte)(uVar9 >> 8);
      puVar2 = puVar38;
      puVar38 = (uint *)((int)puVar38 + 1);
      *(byte *)puVar2 = (char)piVar10 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = (int *)((int)unaff_BP + uVar14);
    pbVar3 = (byte *)((uVar9 >> 2) + (int)unaff_SI);
    *pbVar3 = *pbVar3 - 0x15;
    puVar2 = (uint *)((byte *)((int)unaff_BP + (int)puVar38) + 0x645);
    uVar18 = *puVar2;
    *puVar2 = *puVar2 - uVar14;
    bVar7 = ((char)(uVar9 >> 1) + (char)(uVar9 >> 2) + -0x10) - (uVar18 < uVar14) | 2;
    iVar16 = *(int *)(byte *)((int)puVar38 + 0x55);
code_r0x00013aab:
    *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) & bVar7;
    ((uint *)puVar35)[-1] = (uint)unaff_BP;
    *(byte *)((int)unaff_BP + (int)unaff_SI) =
         *(byte *)((int)unaff_BP + (int)unaff_SI) & (byte)uVar14;
    puVar32 = (uint *)0xf029;
    *(uint *)0xf029 = (uint)unaff_BP;
    if (iVar16 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)((int)unaff_BP + (int)unaff_SI) = *(byte *)((int)unaff_BP + (int)unaff_SI) | bVar7;
      pcVar6 = (code *)swi(1);
      uVar46 = (*pcVar6)();
      return uVar46;
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
    puVar31 = (uint *)puVar35;
    uVar8 = (undefined2)((ulong)puVar35 >> 0x10);
    puVar31[-1] = unaff_ES;
    pbVar3 = (byte *)((int)unaff_SI + uVar9 + 0x222);
    *(byte **)pbVar3 = (byte *)(*(int *)pbVar3 + (int)puVar38);
    puVar38 = (uint *)puVar31[-1];
    unaff_SI = (uint *)*puVar31;
    unaff_BP = (int *)puVar31[1];
    uVar14 = puVar31[5];
    uVar12 = puVar31[6];
    uVar18 = CONCAT11((char)(puVar31[3] >> 8),(byte)puVar31[3] | *(byte *)0x5d02) |
             *(uint *)((byte *)((int)unaff_BP + (int)puVar38) + 10);
    puVar31[6] = (uint)puVar38;
    pbVar3 = (byte *)((int)unaff_SI + uVar18 + 0x2c2);
    cVar44 = SCARRY1((char)uVar12,*pbVar3);
    bVar39 = (char)((char)uVar12 + *pbVar3) < '\0';
    puVar32 = puVar31 + 5;
    puVar31[5] = 0x3a83;
    uVar45 = func_0x00013e95();
    bVar7 = (byte)uVar45;
    out(0x6f,bVar7);
    *(undefined1 *)0x1108 = (char)uVar18;
    cVar17 = (char)((ulong)uVar45 >> 0x18);
    if (bVar39) {
      bVar15 = (byte)(uVar18 >> 8);
      puVar35 = (uint *)((int)puVar38 + -0x53);
      uVar5 = (uint)(bVar15 < (byte)(uVar14 >> 8));
      uVar9 = *puVar35;
      uVar4 = *puVar35;
      *puVar35 = uVar4 + 0xe02d + uVar5;
      bVar13 = *(byte *)((int)unaff_BP + (int)puVar38);
      bVar15 = bVar15 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar45 >> 8);
      in_BX = CONCAT11(bVar15,(char)uVar18);
      if ((char)bVar15 < '\0') {
        bVar39 = unaff_SI[3] < 1000;
        if (!bVar39) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar32 + -2) = 0x3b26;
          puVar32 = (uint *)((int)puVar32 + -2);
          uVar45 = func_0x00013966();
          if (!bVar39) goto LAB_1000_3b55_1;
        }
        puVar34 = (undefined1 *)((int)puVar32 + -2);
        *(undefined2 *)((int)puVar32 + -2) = 0x3b2d;
        uVar46 = FUN_1000_8cb7();
        uVar18 = (uint)(uVar46 >> 0x10);
        bVar39 = (byte)uVar46 < 0x5a;
        if (bVar39) {
          bVar39 = true;
          if ((byte)uVar46 < 0x50) goto LAB_1000_3b62;
          puVar26 = puVar34 + -2;
          *(undefined2 *)(puVar34 + -2) = 0x3b38;
          bVar39 = false;
          goto code_r0x000138eb;
        }
        puVar33 = puVar34 + -2;
        *(undefined2 *)(puVar34 + -2) = 0x3b42;
        uVar45 = FUN_1000_3607();
        bVar7 = (byte)uVar45;
        if (bVar39) {
          puVar24 = puVar33 + -2;
          *(undefined2 *)(puVar33 + -2) = 0x3b47;
          goto code_r0x000137e7;
        }
LAB_1000_3b55_1:
        uVar46 = CONCAT22((int)((ulong)uVar45 >> 0x10),
                          CONCAT11((char)((ulong)uVar45 >> 8),(char)uVar45 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar35 = (uint *)ZEXT24((undefined1 *)((int)puVar32 + -2));
      *(undefined2 *)((int)puVar32 + -2) = unaff_CS;
      iVar16 = CONCAT11(cVar17 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar45 >> 0x10) + bVar13 +
                        (0x1fd2 < uVar9 || CARRY2(uVar4 + 0xe02d,uVar5)));
      ((byte *)((int)unaff_BP + (int)puVar38))[0x5555] =
           ((byte *)((int)unaff_BP + (int)puVar38))[0x5555] + (char)uVar14;
      goto code_r0x00013aab;
    }
    if (cVar44 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar17;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar18 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar32 + 10),*(undefined2 *)((int)puVar32 + 0xe));
}


