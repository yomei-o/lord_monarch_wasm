/* 1000:3b6d */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */
/* WARNING: Control flow encountered bad instruction data */
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
/* WARNING: Removing unreachable block (ram,0x00013a25) */
/* WARNING: Removing unreachable block (ram,0x00013ae4) */
/* WARNING: Removing unreachable block (ram,0x000139ea) */
/* WARNING: Removing unreachable block (ram,0x00013bfc) */
/* WARNING: Removing unreachable block (ram,0x0001384c) */

ulong FUN_1000_3b6d(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint *puVar3;
  code *pcVar4;
  byte bVar5;
  byte bVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined2 in_CX;
  byte bVar10;
  int iVar9;
  char extraout_DL;
  byte extraout_DL_00;
  char cVar11;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  undefined4 *in_BX;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  undefined2 *puVar15;
  undefined1 *puVar16;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined1 *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  uint *puVar25;
  uint *puVar26;
  undefined2 *puVar27;
  uint *puVar28;
  int iVar29;
  uint *puVar30;
  undefined2 uVar31;
  undefined4 in_ESP;
  uint unaff_BP;
  uint uVar32;
  uint *unaff_SI;
  uint *puVar33;
  uint *unaff_DI;
  uint uVar34;
  uint *puVar35;
  uint *puVar36;
  uint *puVar37;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint uVar38;
  bool bVar39;
  bool bVar40;
  byte in_AF;
  undefined1 uVar41;
  bool bVar42;
  bool bVar43;
  char cVar44;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 in_FPUTagWord;
  undefined2 in_FPULastInstructionOpcode;
  undefined4 in_FPUDataPointer;
  undefined4 in_FPUInstructionPointer;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  ulong uVar45;
  undefined4 uVar46;
  
  uVar31 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar33 = (uint *)((int)in_ESP + -2);
  *(undefined2 *)((int)in_ESP + -2) = 0x3b70;
  uVar45 = func_0x0001afab();
  bVar5 = (byte)(uVar45 >> 0x10);
  uVar38 = (uint)((ulong)*in_BX >> 0x10);
  pbVar12 = (byte *)(byte *)*in_BX;
  bVar6 = (byte)in_CX;
  bVar10 = (byte)((uint)in_CX >> 8) | (byte)*unaff_DI;
  uVar8 = CONCAT11(bVar10,bVar6);
  if ((POPCOUNT(bVar10) & 1U) == 0) {
    pbVar1 = pbVar12 + (int)unaff_SI;
    bVar5 = (byte)(uVar45 >> 8);
    bVar40 = CARRY1(*pbVar1,bVar5);
    *pbVar1 = *pbVar1 + bVar5;
    do {
      pbVar12 = pbVar12 + -1;
LAB_1000_3b62:
      puVar24 = (undefined1 *)puVar33;
      if (bVar40) {
        puVar24 = (undefined1 *)((int)puVar33 + -2);
        *(undefined2 *)((int)puVar33 + -2) = 0x3b67;
        uVar45 = func_0x000137e6();
        cVar11 = (char)uVar8;
        if (bVar40) {
          bVar5 = (byte)uVar45;
          bVar40 = bVar5 < 0x10;
          bVar43 = SBORROW1(bVar5,'\x10');
          bVar42 = (char)(bVar5 - 0x10) < '\0';
          bVar39 = bVar5 == 0x10;
          if (!bVar40) {
            cVar11 = '\x04';
            if (7 < bVar5) {
              bVar43 = SBORROW1(bVar5,'\f');
              bVar42 = (char)(bVar5 - 0xc) < '\0';
              bVar39 = bVar5 == 0xc;
              bVar40 = true;
              if (bVar5 < 0xc) goto LAB_1000_383e;
            }
            cVar11 = '\b';
            if (bVar5 != 0) {
              bVar43 = SBORROW1(bVar5,'\x05');
              bVar42 = (char)(bVar5 - 5) < '\0';
              bVar39 = bVar5 == 5;
              bVar40 = true;
              if (bVar5 < 5) goto LAB_1000_383e;
            }
            cVar11 = '\v';
            bVar40 = bVar5 < 5;
            bVar43 = SBORROW1(bVar5,'\x05');
            bVar42 = (char)(bVar5 - 5) < '\0';
            bVar39 = bVar5 == 5;
            if (!bVar39) {
              uVar8 = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
              pbVar1 = pbVar12 + (int)unaff_SI;
              *pbVar1 = *pbVar1 & 0xb;
              if (*pbVar1 == 0) goto FUN_1000_38de;
              in_AF = 9 < ((bVar5 ^ 0xf8) & 0xf) | in_AF;
              pbVar1 = pbVar12 + (int)unaff_DI + 0x854;
              *pbVar1 = *pbVar1 & 0xb;
              uVar41 = *pbVar1 == 0;
              puVar16 = (undefined1 *)0x322e;
              *(undefined2 *)0x322e = 0x3877;
              func_0x0001ab45();
              puVar17 = (undefined2 *)(puVar16 + -2);
              *(undefined2 *)(puVar16 + -2) = 0x387a;
              uVar46 = func_0x0001b476();
              uVar34 = (uint)((ulong)uVar46 >> 0x10);
              if (!(bool)uVar41) {
                *(byte *)((int)unaff_SI + 0xb) = (byte)uVar46;
              }
              uVar32 = CONCAT11((char)((ulong)uVar46 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
              bVar5 = (byte)uVar32;
              *(byte *)(unaff_SI + 5) = bVar5;
              swi(4);
              pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
              *pbVar1 = *pbVar1 + bVar5;
              if ((POPCOUNT(*pbVar1) & 1U) != 0) {
                bVar5 = (pbVar12 + (int)unaff_SI)[0x33];
                bVar10 = (byte)((ulong)uVar46 >> 0x10);
                bVar6 = (pbVar12 + (int)unaff_SI)[0x33];
                cVar11 = (char)((ulong)uVar46 >> 0x18) + pbVar12[(int)unaff_SI];
                *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar11;
                pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
                *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar11,bVar10 + bVar6),
                                                    (uVar32 + 0x5556) - (uint)CARRY1(bVar10,bVar5))
                                          % (ulong)unaff_SI[0x410]);
                *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
                     *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
                return CONCAT22(puVar17[1],*puVar17);
              }
              puVar33 = unaff_SI;
              puVar18 = puVar17;
              if (*pbVar1 == 0) goto LAB_1000_3958;
              do {
                *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
                bVar40 = CARRY1((byte)pbVar12,*(byte *)(unaff_BP + (int)unaff_SI));
                pbVar12 = (byte *)CONCAT11((char)((uint)pbVar12 >> 8),
                                           (byte)pbVar12 + *(byte *)(unaff_BP + (int)unaff_SI));
code_r0x000138eb:
                *(undefined2 *)((int)puVar17 + -2) = unaff_SS;
                if (!bVar40) {
                  puVar30 = unaff_DI;
                  unaff_DI = (uint *)((int)unaff_DI + 1);
                  *(byte *)puVar30 = 0x30;
                  uVar32 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
                  *(undefined2 *)((int)puVar17 + -2) = pbVar12;
                  *(uint *)((int)puVar17 + -4) = uVar32;
                  pbVar12 = (byte *)unaff_SI[0x15];
                  uVar34 = (uVar34 | 0x3000) - *(int *)(pbVar12 + (int)unaff_SI);
                  bVar6 = (byte)(uVar32 >> 8);
                  bVar5 = (char)uVar32 + 8;
                  if (bVar5 != pbVar12[-0x2d82]) {
                    do {
                    /* WARNING: Do nothing block with infinite loop */
                    } while( true );
                  }
                  *(undefined2 *)((int)puVar17 + -6) = CONCAT11(bVar6,bVar5);
                  *(uint *)((int)puVar17 + -8) = uVar8;
                  *(uint *)((int)puVar17 + -10) = uVar34;
                  *(undefined2 *)((int)puVar17 + -0xc) = pbVar12;
                  *(undefined1 **)(undefined1 *)((int)puVar17 + -0xe) =
                       (undefined1 *)((int)puVar17 + -4);
                  *(uint *)((int)puVar17 + -0x10) = unaff_BP;
                  *(undefined2 *)((int)puVar17 + -0x12) = unaff_SI;
                  *(undefined2 *)((int)puVar17 + -0x14) = unaff_DI;
                  uVar32 = *unaff_DI;
                  cVar11 = (char)(uVar8 >> 8);
                  bVar10 = cVar11 + bVar5;
                  uVar8 = CONCAT11(bVar10,(char)uVar8);
                  unaff_BP = 0x874;
                  if (SCARRY1(cVar11,bVar5)) {
                    puVar18 = (undefined2 *)*(undefined2 *)((int)puVar17 + -0x14);
                    puVar33 = *(uint **)(pbVar12 + (int)unaff_DI + -0x18);
                    puVar30 = puVar33 + 0x43a;
                    uVar13 = *puVar30;
                    *puVar30 = *puVar30 + 0x809;
                    uVar8 = 0x4379;
                    puVar33[0x43a] =
                         puVar33[0x43a] + CONCAT11(bVar6 | (byte)uVar32,bVar5 | bVar10) +
                         (uint)(0xf7f6 < uVar13);
                  }
                  else {
                    *(undefined2 *)((int)puVar17 + -0x16) = 0x874;
                    puVar18 = (undefined2 *)((int)puVar17 + -0x18);
                    *(undefined2 *)((int)puVar17 + -0x18) = 0x874;
                    puVar33 = unaff_SI;
                  }
LAB_1000_3958:
                  *(uint *)(byte *)((int)unaff_DI + 0x55) =
                       *(int *)(byte *)((int)unaff_DI + 0x55) + uVar34;
                  unaff_SI = (uint *)((int)puVar33 + 1);
                  out((byte)*puVar33,uVar34);
                  uVar32 = CONCAT11((byte)((uint)pbVar12 >> 8) &
                                    *(byte *)((int)unaff_SI + unaff_BP + 0x11),(char)pbVar12);
                  bVar6 = (byte)uVar34;
                  cVar44 = SBORROW1(bVar6,(byte)puVar33[0x39]);
                  bVar5 = (byte)puVar33[0x39];
                  cVar11 = (char)(bVar6 - bVar5) < '\0';
                  bVar40 = bVar6 == bVar5;
                  puVar36 = (uint *)((int)puVar18 + -2);
                  *(undefined2 *)((int)puVar18 + -2) = 0x396b;
                  bVar5 = func_0x0001b3ed();
                  iVar9 = extraout_DX_00;
                  if (!bVar40) {
                    *(byte *)(puVar33 + 6) = bVar5;
                    *(undefined2 *)((int)puVar36 + -2) = 0x3973;
                    puVar36 = (uint *)((int)puVar36 + -2);
                    bVar5 = func_0x0001b617();
                    iVar9 = extraout_DX_01;
                  }
                  if (cVar44 != cVar11) {
                    iVar9 = iVar9 + 1;
                    puVar36[-1] = (uint)unaff_DI;
                    puVar36[-2] = iVar9;
                    puVar36[-3] = CONCAT11((char)(uVar8 >> 8),8);
                    puVar36[-4] = uVar32;
                    if (iVar9 == 0) {
LAB_1000_39c7:
                      pcVar4 = (code *)swi(1);
                      uVar45 = (*pcVar4)();
                      return uVar45;
                    }
                    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
                    *pbVar1 = *pbVar1 | (byte)((uint)iVar9 >> 8);
code_r0x00013985:
                    pbVar1 = (byte *)((int)unaff_DI + uVar32 + 0x12);
                    *(byte **)pbVar1 = (byte *)((int)unaff_DI + *(int *)pbVar1 + 2);
                    puVar19 = (undefined1 *)0x2e1c;
                    *(undefined2 *)0x2e1c = 0x3990;
                    FUN_1000_8d53();
                    *(undefined2 *)(puVar19 + -2) = 0x399f;
                    func_0x00018e51();
                    pcVar4 = (code *)swi(3);
                    uVar45 = (*pcVar4)();
                    return uVar45;
                  }
                  bVar5 = bVar5 ^ *(byte *)(unaff_BP + (int)unaff_SI);
                  in_AF = 9 < (bVar5 & 0xf) | in_AF;
                  bVar5 = bVar5 + in_AF * '\x06' & 0xf;
                  uVar38 = *puVar36;
                  pbVar1 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
                  bVar40 = bVar5 < *pbVar1 || bVar5 == *pbVar1;
                  puVar30 = (uint *)CONCAT22(uVar31,puVar36);
                  *puVar36 = 0x39ba;
                  uVar46 = FUN_1000_a1b8();
                  uVar34 = (uint)uVar46;
                  if (bVar40) {
                    if (uVar8 == 1) {
                      do {
                        iVar9 = 0x40;
                        uVar8 = uVar34;
                        do {
                          uVar34 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          puVar33 = unaff_SI;
                          if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
                            puVar30 = puVar30 + -2;
                            *puVar30 = uVar38;
                            bVar5 = (byte)uVar8 | 0x17;
                            bVar6 = (byte)(uVar8 >> 8);
                            if (bVar6 == (byte)unaff_SI[6]) {
                              uVar8 = CONCAT11(bVar5 / 0x5e,bVar5 % 0x5e);
                              puVar33 = unaff_DI;
                              goto code_r0x00013a16;
                            }
                            uVar34 = CONCAT11(bVar6 & *(byte *)(unaff_BP + (int)unaff_SI),
                                              (byte)uVar8) | 0x17;
                            *(byte *)(unaff_SI + 0x3931) =
                                 (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar9 >> 8);
                            *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
                            in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
                            uVar8 = *(uint *)puVar30;
                            puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),
                                                       (uint *)puVar30 + 1);
                            puVar33 = unaff_SI + 8;
                            unaff_DI = unaff_SI;
                          }
                          iVar9 = iVar9 + -1;
                          unaff_SI = puVar33;
                        } while (iVar9 != 0);
                        unaff_SI = (uint *)*(uint *)puVar30;
                        puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),(uint *)puVar30 + 1
                                                  );
                        puVar33 = unaff_DI;
code_r0x00013a16:
                        uVar31 = (undefined2)((ulong)puVar30 >> 0x10);
                        puVar20 = (uint *)puVar30;
                        if (0x1ef < uVar34) goto code_r0x00013a1c;
                        pbVar1 = (byte *)((int)puVar33 + unaff_BP + 0x59);
                        *pbVar1 = *pbVar1 | (byte)uVar34;
                        bVar5 = *(byte *)(uVar34 + puVar20[1]);
                        puVar20[1] = (uint)unaff_SI;
                        *(char *)0xaaaa =
                             *(char *)0xaaaa + (byte)uVar34 + ((byte)((char)unaff_BP + 1U) < bVar5);
                        uVar34 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
                        unaff_DI = (uint *)puVar20[1];
                        puVar30 = (uint *)CONCAT22(uVar31,puVar20 + 2);
                        unaff_SI = (uint *)0xc800;
                        unaff_BP = uVar8;
                      } while( true );
                    }
                    goto code_r0x00013985;
                  }
                  out((int)((ulong)uVar46 >> 0x10),(char)uVar46);
                  puVar3 = unaff_SI;
                  bVar40 = CARRY2(*puVar3,uVar34);
                  *puVar3 = *puVar3 + uVar34;
                  bVar42 = (int)*puVar3 < 0;
                  bVar39 = *puVar3 == 0;
                  bVar5 = POPCOUNT(*puVar3 & 0xff);
                  uVar8 = uVar8 - 1;
                  if (uVar8 == 0 || bVar39) goto LAB_1000_39c7;
                  goto LAB_1000_3a35;
                }
                pbVar12 = pbVar12 + 1;
                puVar24 = (undefined1 *)((int)puVar17 + -4);
                *(undefined2 *)((int)puVar17 + -4) = 0x810;
                *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar34;
FUN_1000_38de:
                puVar17 = (undefined2 *)(puVar24 + -2);
                *(undefined2 *)(puVar24 + -2) = 0x38e1;
                FUN_1000_7494();
                pbVar12[(int)unaff_SI] = pbVar12[(int)unaff_SI] & (byte)uVar8;
                LOCK();
                uVar41 = *(undefined1 *)(unaff_BP + 0x72);
                *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
                uVar34 = CONCAT11(uVar41,(char)extraout_DX);
                UNLOCK();
              } while( true );
            }
          }
LAB_1000_383e:
          if (bVar40) {
            *(undefined2 *)(puVar24 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          if (!bVar39 && bVar43 == bVar42) {
            return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
          }
LAB_1000_37ea_2:
          if (cVar11 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
            puVar15 = (undefined2 *)(puVar24 + -2);
            puVar24 = puVar24 + -2;
            *puVar15 = 0x37f3;
            func_0x0001b6c0();
          }
          return CONCAT22(*(undefined2 *)(puVar24 + 10),*(undefined2 *)(puVar24 + 0xe));
        }
      }
      if (*(int *)0x3480 != 0) {
        *(byte *)unaff_SI = (byte)*unaff_SI | 1;
        return uVar45;
      }
      *(uint *)(puVar24 + -2) = unaff_BP;
      puVar33 = (uint *)(puVar24 + -4);
      *(uint *)(puVar24 + -4) = unaff_BP;
      pbVar1 = pbVar12 + (int)unaff_SI;
      bVar5 = (byte)(uVar45 >> 8);
      bVar40 = CARRY1(*pbVar1,bVar5);
      *pbVar1 = *pbVar1 + bVar5;
    } while( true );
  }
  uVar8 = (uint)(char)uVar45;
  if (bVar10 == 0) {
LAB_1000_3b8b:
    bVar6 = (byte)uVar8;
    bVar10 = bVar6 < 10;
    if ((((bVar6 == 10) || (bVar10 = bVar6 < 7, bVar6 == 7)) || (bVar10 = bVar6 < 9, bVar6 == 9)) ||
       ((bVar10 = bVar6 < 0xb, bVar6 == 0xb || (bVar10 = bVar6 < 6, bVar6 == 6)))) {
      *(undefined2 *)((int)puVar33 + -2) = 0x3ba2;
      puVar33 = (uint *)((int)puVar33 + -2);
      uVar8 = func_0x0001b56d();
      bVar5 = extraout_DL_00;
    }
    (pbVar12 + (int)unaff_DI)[-0x3d] =
         ((pbVar12 + (int)unaff_DI)[-0x3d] - (char)(uVar8 >> 8)) -
         (bVar5 < (byte)*unaff_DI || (byte)(bVar5 - (byte)*unaff_DI) < bVar10);
    return CONCAT22(*(undefined2 *)((int)puVar33 + 10),*(undefined2 *)((int)puVar33 + 0xe));
  }
  *puVar33 = 0x3b80;
  puVar36 = puVar33;
  uVar8 = func_0x0001aa17();
  uVar38 = *puVar36;
  puVar33 = puVar36 + 1;
  if (extraout_DL == '\0' && *(char *)ZEXT24(pbVar12 + (uVar8 & 0xff)) == '\0') {
    uVar8 = CONCAT11((char)(uVar8 >> 8),*(char *)ZEXT24(pbVar12 + (uVar8 & 0xff))) & 0x443a;
    *pbVar12 = *pbVar12 ^ bVar6;
    bVar5 = 0;
    goto LAB_1000_3b8b;
  }
  bVar10 = (byte)unaff_SI[2] - 1;
  bVar5 = (byte)*unaff_DI;
  if (bVar10 < bVar5) {
    *unaff_DI = 0;
  }
  else if ((bVar5 != bVar10) && ((byte)(bVar5 - (char)(*unaff_DI >> 8)) == (byte)(bVar6 - 1))) {
    *(byte *)unaff_DI = (byte)*unaff_DI - 1;
  }
  uVar8 = *unaff_SI;
  uVar34 = unaff_SI[1];
  puVar33 = unaff_SI + 3;
  bVar5 = *(byte *)((int)unaff_DI + 1);
  *(int *)0xc54c = bVar5 + 1;
  if (-1 < (char)uVar34) {
    puVar33 = puVar33 + bVar5;
  }
  *(uint *)((int)puVar36 + -1) = uVar34;
  puVar25 = (uint *)((int)puVar36 + -3);
  *(undefined2 *)((int)puVar36 + -3) = 0x3c61;
  FUN_1000_3dc0();
  puVar26 = puVar25 + 1;
  uVar34 = ((uVar8 & 0xff) * 0x280 + (uVar8 >> 8)) * 2 + 0x50e;
  uVar8 = *puVar25 & 0xff;
  if ((char)*puVar25 < '\0') {
    uVar8 = *puVar33;
    *puVar25 = uVar8;
    puVar28 = puVar25 + -1;
    puVar25[-1] = 0x3c9e;
    FUN_1000_54fb();
    pbVar1 = (byte *)(unaff_BP + uVar8 + 0xcaa);
    bVar40 = *pbVar1 < 0xf1;
    *pbVar1 = *pbVar1 + 0xf;
    puVar36 = (uint *)*puVar28;
    puVar33 = (uint *)puVar28[1];
    uVar32 = puVar28[2];
    uVar13 = puVar28[4];
    uVar34 = puVar28[5];
    iVar9 = puVar28[6];
    uVar8 = puVar28[7];
    uVar45 = ZEXT24(puVar28 + 8);
    puVar2 = (undefined2 *)(uVar32 + 0x3e);
    *puVar2 = in_FPUControlWord;
    puVar2[2] = in_FPUStatusWord;
    puVar2[4] = in_FPUTagWord;
    *(undefined4 *)(puVar2 + 10) = in_FPUDataPointer;
    *(undefined4 *)(puVar2 + 6) = in_FPUInstructionPointer;
    puVar2[9] = in_FPULastInstructionOpcode;
    *(longdouble *)(puVar2 + 0xe) = in_ST0;
    *(longdouble *)(puVar2 + 0x13) = in_ST1;
    *(longdouble *)(puVar2 + 0x18) = in_ST2;
    *(longdouble *)(puVar2 + 0x1d) = in_ST3;
    *(longdouble *)(puVar2 + 0x22) = in_ST4;
    *(longdouble *)(puVar2 + 0x27) = in_ST5;
    *(longdouble *)(puVar2 + 0x2c) = in_ST6;
    *(longdouble *)(puVar2 + 0x31) = in_ST7;
    goto code_r0x00018496;
  }
  puVar33 = puVar33 + 1;
  do {
    *(undefined2 *)((int)puVar26 + -2) = puVar33;
    puVar27 = (undefined2 *)((int)puVar26 + -4);
    *(undefined2 *)((int)puVar26 + -4) = 0x3c85;
    func_0x000167fa();
    iRam0001c54c = iRam0001c54c + 1;
    puVar33 = (uint *)*puVar27;
    puVar26 = puVar27 + 1;
    bVar39 = 0xfaff < uVar34;
    uVar34 = uVar34 + 0x500;
    uVar8 = uVar8 - 1;
  } while (uVar8 != 0);
  puVar35 = (uint *)puVar27[1];
  puVar33 = (uint *)puVar27[2];
  uVar32 = puVar27[3];
  uVar13 = puVar27[5];
  uVar34 = puVar27[6];
  iVar9 = puVar27[7];
  uVar8 = puVar27[8];
  uVar45 = ZEXT24(puVar27 + 9);
  while( true ) {
    puVar37 = (uint *)((int)puVar35 + 1);
    *(char *)puVar35 = (char)uVar8;
    *(char *)(uVar32 + (int)puVar33) =
         *(char *)(uVar32 + (int)puVar33) + (char)(uVar13 >> 8) + bVar39;
    *(char *)(puVar33 + 0x1b) = (char)puVar33[0x1b] << 1;
    bVar5 = (byte)(uVar8 >> 8);
    if ((byte)uVar34 == bVar5) break;
    iVar9 = iVar9 + 1;
    iVar29 = (int)uVar45;
    puVar33[-0x3ffb] = (puVar33[-0x3ffb] - iVar29) - (uint)((byte)uVar34 < bVar5);
    pbVar1 = (byte *)((int)puVar37 + uVar32 + 7);
    bVar5 = (byte)(uVar34 >> 8);
    bVar40 = CARRY1(*pbVar1,bVar5);
    *pbVar1 = *pbVar1 + bVar5;
    uVar45 = (ulong)(iVar29 - 2);
    *(undefined2 *)(iVar29 + -2) = 0x84b4;
    uVar46 = FUN_1000_7a7c();
    uVar34 = (uint)((ulong)uVar46 >> 0x10);
    uVar8 = (uint)uVar46;
    if (!bVar40) goto FUN_1000_84d0;
    do {
      while( true ) {
        puVar36 = puVar37 + 1;
        iVar9 = iVar9 + -1;
        if (iVar9 == 0) goto code_r0x000184d9;
        uVar14 = *puVar36;
        uVar34 = CONCAT11((char)(uVar34 >> 8),(char)puVar37[-0x16c0]);
        if ((char)puVar37[-0x16c0] != '\x05') break;
        uVar32 = uVar14;
        puVar37 = puVar36;
        if (uVar14 < uVar13) {
FUN_1000_84d0:
          puVar33 = puVar37;
          uVar13 = uVar32;
          uVar32 = uVar13;
          puVar37 = puVar33;
        }
      }
      uVar32 = uVar14 + 8;
      puVar37 = puVar36;
    } while ((0xfff7 < uVar14) || (bVar40 = uVar13 < uVar32, uVar13 <= uVar32));
code_r0x00018496:
    bVar5 = (byte)uVar34 + *(byte *)(uVar13 + (int)puVar33);
    bVar39 = CARRY1((byte)uVar34,*(byte *)(uVar13 + (int)puVar33)) || CARRY1(bVar5,bVar40);
    uVar34 = CONCAT11((char)(uVar34 >> 8),bVar5 + bVar40);
    puVar35 = puVar36 + 1;
    *puVar36 = uVar8;
  }
  *(undefined2 *)(uVar32 + (int)puVar33) = 0xa6e2;
code_r0x000184d9:
  uVar14 = uVar13 - 8;
  if (uVar13 < 8) {
    uVar14 = 0;
  }
  else if (0x1ef < uVar14) {
    *(byte *)(uVar32 + 0x5d) = *(byte *)(uVar32 + 0x5d) | (byte)uVar14;
    goto code_r0x000184fd;
  }
  uVar34 = (uint)puVar33 >> 1;
  uVar8 = CONCAT11((char)(uVar34 / 0x30),(char)(uVar34 % 0x30));
  *(char *)(uVar14 + uVar34) =
       (*(char *)(uVar14 + uVar34) - (char)iVar9) - (((uint)puVar33 & 1) != 0);
  uVar34 = uVar8;
code_r0x000184fd:
  return CONCAT22(uVar34,uVar8);
code_r0x00013a1c:
  unaff_SS = *puVar20;
  *(longdouble *)(uVar34 + (int)puVar33) = in_ST0;
  puVar30 = (uint *)CONCAT22(uVar31,(uint *)(puVar20[1] + -2));
  *(undefined2 *)(puVar20[1] + -2) = unaff_ES;
  uVar32 = puVar33[2];
  uVar34 = (uint)*(byte *)((int)puVar33 + -0x79);
  bVar40 = (byte)iVar9 < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar11 = (byte)iVar9 - *(byte *)(unaff_BP + (int)unaff_SI);
  uVar8 = CONCAT11((char)((uint)iVar9 >> 8),cVar11);
  bVar42 = cVar11 < '\0';
  bVar39 = cVar11 == '\0';
  bVar5 = POPCOUNT(cVar11);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar33;
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
    *(byte *)(uVar32 + (int)unaff_SI) = *(byte *)(uVar32 + (int)unaff_SI) + 1;
    puVar21 = (uint *)puVar30;
    puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),puVar21 + -1);
    puVar21[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar42 << 7 | bVar39 << 6 | in_AF << 4 | ((bVar5 & 1) == 0) << 2 | 2 |
                          bVar40,(char)uVar34)) {
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar1 = *pbVar1 | (byte)(uVar32 >> 8);
      puVar3 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar3 = (char)uVar34 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + uVar8;
    pbVar1 = (byte *)((uVar32 >> 2) + (int)unaff_SI);
    *pbVar1 = *pbVar1 - 0x15;
    puVar3 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar34 = *puVar3;
    *puVar3 = *puVar3 - uVar8;
    bVar5 = ((char)(uVar32 >> 1) + (char)(uVar32 >> 2) + -0x10) - (uVar34 < uVar8) | 2;
    iVar9 = *(int *)(byte *)((int)unaff_DI + 0x55);
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar5;
    ((uint *)puVar30)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)uVar8;
    puVar36 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar9 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar5;
      pcVar4 = (code *)swi(1);
      uVar45 = (*pcVar4)();
      return uVar45;
    }
    uVar34 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar34 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar4 = (code *)swi(0x20);
    (*pcVar4)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar32 >> 8);
    puVar22 = (uint *)puVar30;
    uVar31 = (undefined2)((ulong)puVar30 >> 0x10);
    puVar22[-1] = unaff_ES;
    pbVar1 = (byte *)((int)unaff_SI + uVar32 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
    unaff_DI = (uint *)puVar22[-1];
    unaff_SI = (uint *)*puVar22;
    unaff_BP = puVar22[1];
    uVar8 = puVar22[5];
    uVar7 = puVar22[6];
    uVar34 = CONCAT11((char)(puVar22[3] >> 8),(byte)puVar22[3] | *(byte *)0x5d02) |
             *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar22[6] = (uint)unaff_DI;
    pbVar1 = (byte *)((int)unaff_SI + uVar34 + 0x2c2);
    cVar44 = SCARRY1((char)uVar7,*pbVar1);
    bVar40 = (char)((char)uVar7 + *pbVar1) < '\0';
    puVar36 = puVar22 + 5;
    puVar22[5] = 0x3a83;
    uVar46 = func_0x00013e95();
    bVar5 = (byte)uVar46;
    out(0x6f,bVar5);
    *(undefined1 *)0x1108 = (char)uVar34;
    cVar11 = (char)((ulong)uVar46 >> 0x18);
    if (bVar40) {
      bVar10 = (byte)(uVar34 >> 8);
      puVar30 = (uint *)((int)unaff_DI + -0x53);
      uVar14 = (uint)(bVar10 < (byte)(uVar8 >> 8));
      uVar32 = *puVar30;
      uVar13 = *puVar30;
      *puVar30 = uVar13 + 0xe02d + uVar14;
      bVar6 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar10 = bVar10 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar46 >> 8);
      pbVar12 = (byte *)CONCAT11(bVar10,(char)uVar34);
      if ((char)bVar10 < '\0') {
        bVar40 = unaff_SI[3] < 1000;
        if (!bVar40) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar36 + -2) = 0x3b26;
          puVar36 = (uint *)((int)puVar36 + -2);
          uVar46 = func_0x00013966();
          if (!bVar40) goto LAB_1000_3b55_1;
        }
        puVar33 = (uint *)((int)puVar36 + -2);
        *(undefined2 *)((int)puVar36 + -2) = 0x3b2d;
        uVar45 = FUN_1000_8cb7();
        uVar34 = (uint)(uVar45 >> 0x10);
        bVar40 = (byte)uVar45 < 0x5a;
        if (bVar40) {
          bVar40 = true;
          if ((byte)uVar45 < 0x50) goto LAB_1000_3b62;
          puVar17 = (undefined2 *)((int)puVar33 + -2);
          *(undefined2 *)((int)puVar33 + -2) = 0x3b38;
          bVar40 = false;
          goto code_r0x000138eb;
        }
        puVar23 = (undefined1 *)((int)puVar33 + -2);
        *(undefined2 *)((int)puVar33 + -2) = 0x3b42;
        uVar46 = FUN_1000_3607();
        cVar11 = (char)uVar8;
        if (bVar40) {
          puVar24 = puVar23 + -2;
          *(undefined2 *)(puVar23 + -2) = 0x3b47;
          goto LAB_1000_37ea_2;
        }
LAB_1000_3b55_1:
        return CONCAT22((int)((ulong)uVar46 >> 0x10),
                        CONCAT11((char)((ulong)uVar46 >> 8),(char)uVar46 + -0x80)) | 1;
      }
      puVar30 = (uint *)ZEXT24((undefined1 *)((int)puVar36 + -2));
      *(undefined2 *)((int)puVar36 + -2) = unaff_CS;
      iVar9 = CONCAT11(cVar11 - (pbVar12 + (int)unaff_SI)[0x23c9],
                       (char)((ulong)uVar46 >> 0x10) + bVar6 +
                       (0x1fd2 < uVar32 || CARRY2(uVar13 + 0xe02d,uVar14)));
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar1 = *pbVar1 + (char)uVar8;
      goto code_r0x00013aab;
    }
    if (cVar44 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar11;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar34 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar36 + 10),*(undefined2 *)((int)puVar36 + 0xe));
}


