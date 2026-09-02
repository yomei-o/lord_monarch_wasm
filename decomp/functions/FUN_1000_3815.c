/* 1000:3815 */

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
/* WARNING: Removing unreachable block (ram,0x00013a25) */
/* WARNING: Removing unreachable block (ram,0x00013ae4) */
/* WARNING: Removing unreachable block (ram,0x000139ea) */
/* WARNING: Removing unreachable block (ram,0x0001384c) */

ulong FUN_1000_3815(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  undefined2 in_AX;
  uint uVar7;
  byte bVar9;
  undefined2 uVar8;
  uint in_CX;
  byte bVar10;
  char cVar12;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar11;
  uint in_BX;
  uint uVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined2 *puVar17;
  undefined2 *puVar18;
  uint *puVar19;
  undefined1 *puVar20;
  uint *puVar21;
  uint *puVar22;
  uint *puVar23;
  uint *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *in_ESP;
  uint *puVar29;
  undefined2 uVar30;
  uint unaff_BP;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  undefined1 in_CF;
  byte in_AF;
  bool in_ZF;
  bool bVar31;
  undefined1 uVar32;
  bool bVar33;
  char in_SF;
  bool bVar34;
  char in_OF;
  char cVar35;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar36;
  ulong uVar37;
  
  cVar12 = (char)in_CX;
  bVar6 = (byte)in_AX;
  bVar31 = true;
  if (!in_ZF) {
    if (bVar6 < 0xc) goto LAB_1000_381f;
LAB_1000_381b:
    cVar12 = (char)in_CX;
    bVar6 = (byte)in_AX;
    in_CF = bVar6 < 0x10;
    in_OF = SBORROW1(bVar6,'\x10');
    in_SF = (char)(bVar6 - 0x10) < '\0';
    bVar31 = bVar6 == 0x10;
    if (!(bool)in_CF) {
LAB_1000_381f:
      cVar12 = '\x04';
      if (7 < bVar6) {
        in_OF = SBORROW1(bVar6,'\f');
        in_SF = (char)(bVar6 - 0xc) < '\0';
        bVar31 = bVar6 == 0xc;
        in_CF = true;
        if (bVar6 < 0xc) goto LAB_1000_383e;
      }
      cVar12 = '\b';
      if (bVar6 != 0) {
        in_OF = SBORROW1(bVar6,'\x05');
        in_SF = (char)(bVar6 - 5) < '\0';
        bVar31 = bVar6 == 5;
        in_CF = true;
        if (bVar6 < 5) goto LAB_1000_383e;
      }
      cVar12 = '\v';
      in_CF = bVar6 < 5;
      in_OF = SBORROW1(bVar6,'\x05');
      in_SF = (char)(bVar6 - 5) < '\0';
      bVar31 = bVar6 == 5;
      if (!bVar31) {
        in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
        pbVar2 = (byte *)(in_BX + (int)unaff_SI);
        *pbVar2 = *pbVar2 & 0xb;
        if (*pbVar2 == 0) goto FUN_1000_38de;
        in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
        uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
        pbVar2 = (byte *)((int)unaff_DI + in_BX + 0x854);
        *pbVar2 = *pbVar2 & 0xb;
        uVar32 = *pbVar2 == 0;
        puVar16 = (undefined1 *)0x322e;
        *(undefined2 *)0x322e = 0x3877;
        func_0x0001ab45();
        puVar17 = (undefined2 *)(puVar16 + -2);
        *(undefined2 *)(puVar16 + -2) = 0x387a;
        uVar36 = func_0x0001b476();
        uVar13 = (uint)((ulong)uVar36 >> 0x10);
        if (!(bool)uVar32) {
          *(byte *)((int)unaff_SI + 0xb) = (byte)uVar36;
        }
        uVar7 = CONCAT11((char)((ulong)uVar36 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
        bVar6 = (byte)uVar7;
        *(byte *)(unaff_SI + 5) = bVar6;
        swi(4);
        pbVar2 = (byte *)(unaff_BP + (int)unaff_SI);
        *pbVar2 = *pbVar2 + bVar6;
        if ((POPCOUNT(*pbVar2) & 1U) != 0) {
          pbVar2 = (byte *)((int)unaff_SI + in_BX + 0x33);
          bVar6 = *pbVar2;
          bVar10 = (byte)((ulong)uVar36 >> 0x10);
          bVar9 = *pbVar2;
          cVar12 = (char)((ulong)uVar36 >> 0x18) + *(byte *)(in_BX + (int)unaff_SI);
          *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar12;
          pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
          *pbVar2 = *pbVar2 | (byte)(CONCAT22(CONCAT11(cVar12,bVar10 + bVar9),
                                              (uVar7 + 0x5556) - (uint)CARRY1(bVar10,bVar6)) %
                                    (ulong)unaff_SI[0x410]);
          *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
               *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
          return CONCAT22(puVar17[1],*puVar17);
        }
        puVar24 = unaff_SI;
        puVar18 = puVar17;
        if (*pbVar2 == 0) goto LAB_1000_3958;
        do {
          *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
          bVar31 = CARRY1((byte)in_BX,*(byte *)(unaff_BP + (int)unaff_SI));
          in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)(unaff_BP + (int)unaff_SI));
code_r0x000138eb:
          *(undefined2 *)((int)puVar17 + -2) = unaff_SS;
          if (!bVar31) {
            puVar29 = unaff_DI;
            unaff_DI = (uint *)((int)unaff_DI + 1);
            *(byte *)puVar29 = 0x30;
            uVar7 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
            *(uint *)((int)puVar17 + -2) = in_BX;
            *(uint *)((int)puVar17 + -4) = uVar7;
            in_BX = unaff_SI[0x15];
            uVar13 = (uVar13 | 0x3000) - *(int *)(byte *)(in_BX + (int)unaff_SI);
            bVar9 = (byte)(uVar7 >> 8);
            bVar6 = (char)uVar7 + 8;
            if (bVar6 != *(byte *)(in_BX + 0xd27e)) {
              do {
                    /* WARNING: Do nothing block with infinite loop */
              } while( true );
            }
            *(undefined2 *)((int)puVar17 + -6) = CONCAT11(bVar9,bVar6);
            *(uint *)((int)puVar17 + -8) = in_CX;
            *(uint *)((int)puVar17 + -10) = uVar13;
            *(uint *)((int)puVar17 + -0xc) = in_BX;
            *(undefined1 **)(undefined1 *)((int)puVar17 + -0xe) = (undefined1 *)((int)puVar17 + -4);
            *(uint *)((int)puVar17 + -0x10) = unaff_BP;
            *(undefined2 *)((int)puVar17 + -0x12) = unaff_SI;
            *(undefined2 *)((int)puVar17 + -0x14) = unaff_DI;
            uVar7 = *unaff_DI;
            cVar12 = (char)(in_CX >> 8);
            bVar10 = cVar12 + bVar6;
            in_CX = CONCAT11(bVar10,(char)in_CX);
            unaff_BP = 0x874;
            if (SCARRY1(cVar12,bVar6)) {
              puVar18 = (undefined2 *)*(undefined2 *)((int)puVar17 + -0x14);
              puVar24 = *(uint **)(byte *)((int)unaff_DI + (in_BX - 0x18));
              puVar29 = puVar24 + 0x43a;
              uVar3 = *puVar29;
              *puVar29 = *puVar29 + 0x809;
              in_CX = 0x4379;
              puVar24[0x43a] =
                   puVar24[0x43a] + CONCAT11(bVar9 | (byte)uVar7,bVar6 | bVar10) +
                   (uint)(0xf7f6 < uVar3);
            }
            else {
              *(undefined2 *)((int)puVar17 + -0x16) = 0x874;
              puVar18 = (undefined2 *)((int)puVar17 + -0x18);
              *(undefined2 *)((int)puVar17 + -0x18) = 0x874;
              puVar24 = unaff_SI;
            }
LAB_1000_3958:
            *(uint *)(byte *)((int)unaff_DI + 0x55) =
                 *(int *)(byte *)((int)unaff_DI + 0x55) + uVar13;
            unaff_SI = (uint *)((int)puVar24 + 1);
            out((byte)*puVar24,uVar13);
            uVar7 = CONCAT11((byte)(in_BX >> 8) & *(byte *)((int)unaff_SI + unaff_BP + 0x11),
                             (char)in_BX);
            bVar9 = (byte)uVar13;
            cVar35 = SBORROW1(bVar9,(byte)puVar24[0x39]);
            bVar6 = (byte)puVar24[0x39];
            cVar12 = (char)(bVar9 - bVar6) < '\0';
            bVar31 = bVar9 == bVar6;
            puVar19 = (uint *)((int)puVar18 + -2);
            *(undefined2 *)((int)puVar18 + -2) = 0x396b;
            bVar6 = func_0x0001b3ed();
            iVar11 = extraout_DX_00;
            if (!bVar31) {
              *(byte *)(puVar24 + 6) = bVar6;
              *(undefined2 *)((int)puVar19 + -2) = 0x3973;
              puVar19 = (uint *)((int)puVar19 + -2);
              bVar6 = func_0x0001b617();
              iVar11 = extraout_DX_01;
            }
            if (cVar35 != cVar12) {
              iVar11 = iVar11 + 1;
              puVar19[-1] = (uint)unaff_DI;
              puVar19[-2] = iVar11;
              puVar19[-3] = CONCAT11((char)(in_CX >> 8),8);
              puVar19[-4] = uVar7;
              if (iVar11 == 0) {
LAB_1000_39c7:
                pcVar5 = (code *)swi(1);
                uVar37 = (*pcVar5)();
                return uVar37;
              }
              pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
              *pbVar2 = *pbVar2 | (byte)((uint)iVar11 >> 8);
code_r0x00013985:
              pbVar2 = (byte *)((int)unaff_DI + uVar7 + 0x12);
              *(byte **)pbVar2 = (byte *)((int)unaff_DI + *(int *)pbVar2 + 2);
              puVar20 = (undefined1 *)0x2e1c;
              *(undefined2 *)0x2e1c = 0x3990;
              FUN_1000_8d53();
              *(undefined2 *)(puVar20 + -2) = 0x399f;
              func_0x00018e51();
              pcVar5 = (code *)swi(3);
              uVar37 = (*pcVar5)();
              return uVar37;
            }
            bVar6 = bVar6 ^ *(byte *)(unaff_BP + (int)unaff_SI);
            in_AF = 9 < (bVar6 & 0xf) | in_AF;
            bVar6 = bVar6 + in_AF * '\x06' & 0xf;
            unaff_DS = *puVar19;
            pbVar2 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
            bVar31 = bVar6 < *pbVar2 || bVar6 == *pbVar2;
            puVar29 = (uint *)CONCAT22(uVar8,puVar19);
            *puVar19 = 0x39ba;
            uVar36 = FUN_1000_a1b8();
            uVar13 = (uint)uVar36;
            if (bVar31) {
              if (in_CX == 1) {
                do {
                  iVar11 = 0x40;
                  uVar7 = uVar13;
                  do {
                    uVar13 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    puVar24 = unaff_SI;
                    if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
                      puVar29 = puVar29 + -2;
                      *puVar29 = unaff_DS;
                      bVar6 = (byte)uVar7 | 0x17;
                      bVar9 = (byte)(uVar7 >> 8);
                      if (bVar9 == (byte)unaff_SI[6]) {
                        uVar7 = CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
                        puVar24 = unaff_DI;
                        goto code_r0x00013a16;
                      }
                      uVar13 = CONCAT11(bVar9 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)uVar7) |
                               0x17;
                      *(byte *)(unaff_SI + 0x3931) =
                           (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar11 >> 8);
                      *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
                      in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
                      uVar7 = *(uint *)puVar29;
                      puVar29 = (uint *)CONCAT22((int)((ulong)puVar29 >> 0x10),(uint *)puVar29 + 1);
                      puVar24 = unaff_SI + 8;
                      unaff_DI = unaff_SI;
                    }
                    iVar11 = iVar11 + -1;
                    unaff_SI = puVar24;
                  } while (iVar11 != 0);
                  unaff_SI = (uint *)*(uint *)puVar29;
                  puVar29 = (uint *)CONCAT22((int)((ulong)puVar29 >> 0x10),(uint *)puVar29 + 1);
                  puVar24 = unaff_DI;
code_r0x00013a16:
                  uVar8 = (undefined2)((ulong)puVar29 >> 0x10);
                  puVar21 = (uint *)puVar29;
                  if (0x1ef < uVar13) goto code_r0x00013a1c;
                  pbVar2 = (byte *)((int)puVar24 + unaff_BP + 0x59);
                  *pbVar2 = *pbVar2 | (byte)uVar13;
                  bVar6 = *(byte *)(uVar13 + puVar21[1]);
                  puVar21[1] = (uint)unaff_SI;
                  *(char *)0xaaaa =
                       *(char *)0xaaaa + (byte)uVar13 + ((byte)((char)unaff_BP + 1U) < bVar6);
                  uVar13 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
                  unaff_DI = (uint *)puVar21[1];
                  puVar29 = (uint *)CONCAT22(uVar8,puVar21 + 2);
                  unaff_SI = (uint *)0xc800;
                  unaff_BP = uVar7;
                } while( true );
              }
              goto code_r0x00013985;
            }
            out((int)((ulong)uVar36 >> 0x10),(char)uVar36);
            puVar1 = unaff_SI;
            bVar31 = CARRY2(*puVar1,uVar13);
            *puVar1 = *puVar1 + uVar13;
            bVar34 = (int)*puVar1 < 0;
            bVar33 = *puVar1 == 0;
            bVar6 = POPCOUNT(*puVar1 & 0xff);
            in_CX = in_CX - 1;
            if (in_CX == 0 || bVar33) goto LAB_1000_39c7;
            goto LAB_1000_3a35;
          }
          in_BX = in_BX + 1;
          in_ESP = (undefined1 *)CONCAT22(uVar8,(undefined1 *)((int)puVar17 + -4));
          *(undefined2 *)((int)puVar17 + -4) = 0x810;
          *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar13;
FUN_1000_38de:
          uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
          puVar17 = (undefined2 *)((undefined1 *)in_ESP + -2);
          *(undefined2 *)((undefined1 *)in_ESP + -2) = 0x38e1;
          FUN_1000_7494();
          *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)in_CX;
          LOCK();
          uVar32 = *(undefined1 *)(unaff_BP + 0x72);
          *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
          uVar13 = CONCAT11(uVar32,(char)extraout_DX);
          UNLOCK();
        } while( true );
      }
    }
  }
LAB_1000_383e:
  puVar15 = (undefined1 *)in_ESP;
  if ((bool)in_CF) {
    *(undefined2 *)(puVar15 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar31 && in_OF == in_SF) {
    return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
  }
LAB_1000_37ea_2:
  if (cVar12 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
    puVar14 = (undefined2 *)(puVar15 + -2);
    puVar15 = puVar15 + -2;
    *puVar14 = 0x37f3;
    func_0x0001b6c0();
  }
  return CONCAT22(*(undefined2 *)(puVar15 + 10),*(undefined2 *)(puVar15 + 0xe));
LAB_1000_3b62:
  if (bVar31) {
    puVar28 = (undefined1 *)in_ESP;
    in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar28 + -2);
    *(undefined2 *)(puVar28 + -2) = 0x3b67;
    uVar37 = func_0x000137e6();
    in_AX = (undefined2)uVar37;
    if (bVar31) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar37;
  }
  puVar27 = (undefined1 *)in_ESP;
  *(uint *)(puVar27 + -2) = unaff_BP;
  in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar27 + -4);
  *(uint *)(puVar27 + -4) = unaff_BP;
  pbVar2 = (byte *)(in_BX + (int)unaff_SI);
  bVar6 = (byte)(uVar37 >> 8);
  bVar31 = CARRY1(*pbVar2,bVar6);
  *pbVar2 = *pbVar2 + bVar6;
  in_BX = in_BX - 1;
  goto LAB_1000_3b62;
code_r0x00013a1c:
  unaff_SS = *puVar21;
  *(longdouble *)(uVar13 + (int)puVar24) = in_ST0;
  puVar29 = (uint *)CONCAT22(uVar8,(uint *)(puVar21[1] + -2));
  *(undefined2 *)(puVar21[1] + -2) = unaff_ES;
  uVar7 = puVar24[2];
  uVar13 = (uint)*(byte *)((int)puVar24 + -0x79);
  bVar31 = (byte)iVar11 < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar12 = (byte)iVar11 - *(byte *)(unaff_BP + (int)unaff_SI);
  in_CX = CONCAT11((char)((uint)iVar11 >> 8),cVar12);
  bVar34 = cVar12 < '\0';
  bVar33 = cVar12 == '\0';
  bVar6 = POPCOUNT(cVar12);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar24;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar33) {
    *(byte *)(uVar7 + (int)unaff_SI) = *(byte *)(uVar7 + (int)unaff_SI) + 1;
    puVar22 = (uint *)puVar29;
    puVar29 = (uint *)CONCAT22((int)((ulong)puVar29 >> 0x10),puVar22 + -1);
    puVar22[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar34 << 7 | bVar33 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar31,(char)uVar13)) {
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar2 = *pbVar2 | (byte)(uVar7 >> 8);
      puVar1 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar1 = (char)uVar13 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar2 = (byte *)((uVar7 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar1 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar13 = *puVar1;
    *puVar1 = *puVar1 - in_CX;
    bVar6 = ((char)(uVar7 >> 1) + (char)(uVar7 >> 2) + -0x10) - (uVar13 < in_CX) | 2;
    iVar11 = *(int *)(byte *)((int)unaff_DI + 0x55);
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar6;
    ((uint *)puVar29)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)in_CX;
    puVar24 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar11 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar37 = (*pcVar5)();
      return uVar37;
    }
    uVar13 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar13 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar5 = (code *)swi(0x20);
    (*pcVar5)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar7 >> 8);
    puVar23 = (uint *)puVar29;
    uVar30 = (undefined2)((ulong)puVar29 >> 0x10);
    puVar23[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + uVar7 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)unaff_DI);
    unaff_DI = (uint *)puVar23[-1];
    unaff_SI = (uint *)*puVar23;
    unaff_BP = puVar23[1];
    in_CX = puVar23[5];
    uVar8 = puVar23[6];
    uVar13 = CONCAT11((char)(puVar23[3] >> 8),(byte)puVar23[3] | *(byte *)0x5d02) |
             *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar23[6] = (uint)unaff_DI;
    pbVar2 = (byte *)((int)unaff_SI + uVar13 + 0x2c2);
    cVar35 = SCARRY1((char)uVar8,*pbVar2);
    bVar31 = (char)((char)uVar8 + *pbVar2) < '\0';
    puVar24 = puVar23 + 5;
    puVar23[5] = 0x3a83;
    uVar36 = func_0x00013e95();
    bVar6 = (byte)uVar36;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar13;
    cVar12 = (char)((ulong)uVar36 >> 0x18);
    if (bVar31) {
      bVar10 = (byte)(uVar13 >> 8);
      puVar29 = (uint *)((int)unaff_DI + -0x53);
      uVar4 = (uint)(bVar10 < (byte)(in_CX >> 8));
      uVar7 = *puVar29;
      uVar3 = *puVar29;
      *puVar29 = uVar3 + 0xe02d + uVar4;
      bVar9 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar10 = bVar10 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar36 >> 8);
      in_BX = CONCAT11(bVar10,(char)uVar13);
      if ((char)bVar10 < '\0') {
        bVar31 = unaff_SI[3] < 1000;
        if (!bVar31) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar24 + -2) = 0x3b26;
          puVar24 = (uint *)((int)puVar24 + -2);
          uVar36 = func_0x00013966();
          if (!bVar31) goto LAB_1000_3b55_1;
        }
        in_ESP = (undefined1 *)CONCAT22(uVar30,(undefined1 *)((int)puVar24 + -2));
        *(undefined2 *)((int)puVar24 + -2) = 0x3b2d;
        uVar37 = FUN_1000_8cb7();
        uVar13 = (uint)(uVar37 >> 0x10);
        bVar31 = (byte)uVar37 < 0x5a;
        puVar25 = (undefined1 *)in_ESP;
        if (bVar31) {
          bVar31 = true;
          if ((byte)uVar37 < 0x50) goto LAB_1000_3b62;
          uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
          puVar17 = (undefined2 *)(puVar25 + -2);
          *(undefined2 *)(puVar25 + -2) = 0x3b38;
          bVar31 = false;
          goto code_r0x000138eb;
        }
        puVar26 = puVar25 + -2;
        *(undefined2 *)(puVar25 + -2) = 0x3b42;
        uVar36 = FUN_1000_3607();
        cVar12 = (char)in_CX;
        if (bVar31) {
          puVar15 = puVar26 + -2;
          *(undefined2 *)(puVar26 + -2) = 0x3b47;
          goto LAB_1000_37ea_2;
        }
LAB_1000_3b55_1:
        uVar37 = CONCAT22((int)((ulong)uVar36 >> 0x10),
                          CONCAT11((char)((ulong)uVar36 >> 8),(char)uVar36 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar29 = (uint *)ZEXT24((undefined1 *)((int)puVar24 + -2));
      *(undefined2 *)((int)puVar24 + -2) = unaff_CS;
      iVar11 = CONCAT11(cVar12 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar36 >> 0x10) + bVar9 +
                        (0x1fd2 < uVar7 || CARRY2(uVar3 + 0xe02d,uVar4)));
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar2 = *pbVar2 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar35 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar12;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar13 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar24 + 10),*(undefined2 *)((int)puVar24 + 0xe));
}


