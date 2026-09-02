/* 1000:3b4b */

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

ulong FUN_1000_3b4b(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  code *pcVar4;
  byte bVar5;
  uint uVar6;
  byte bVar8;
  undefined2 uVar7;
  undefined2 in_AX;
  byte bVar9;
  uint in_CX;
  char cVar11;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar10;
  undefined2 in_DX;
  uint uVar12;
  undefined2 in_BX;
  uint uVar13;
  undefined1 *puVar14;
  undefined2 *puVar15;
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
  uint *puVar29;
  undefined2 uVar30;
  undefined1 *in_ESP;
  uint unaff_BP;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  char in_CF;
  bool bVar31;
  byte in_AF;
  bool bVar32;
  undefined1 uVar33;
  bool bVar34;
  bool bVar35;
  char cVar36;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar37;
  ulong uVar38;
  
  uVar38 = CONCAT22(in_DX,in_AX);
  out(0x72,(char)in_AX);
  uVar13 = CONCAT11((char)((uint)in_BX >> 8),((char)in_BX - (char)in_AX) - in_CF);
  do {
    do {
      if (*(int *)0x3480 != 0) {
code_r0x00013b57:
        *(byte *)unaff_SI = (byte)*unaff_SI | 1;
        return uVar38;
      }
      puVar27 = (undefined1 *)in_ESP;
      *(uint *)(puVar27 + -2) = unaff_BP;
      in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar27 + -4);
      *(uint *)(puVar27 + -4) = unaff_BP;
      pbVar2 = (byte *)(uVar13 + (int)unaff_SI);
      bVar5 = (byte)(uVar38 >> 8);
      bVar31 = CARRY1(*pbVar2,bVar5);
      *pbVar2 = *pbVar2 + bVar5;
      uVar13 = uVar13 - 1;
LAB_1000_3b62:
    } while (!bVar31);
    puVar28 = (undefined1 *)in_ESP;
    in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar28 + -2);
    *(undefined2 *)(puVar28 + -2) = 0x3b67;
    uVar38 = func_0x000137e6();
    cVar11 = (char)in_CX;
  } while (!bVar31);
  bVar5 = (byte)uVar38;
  bVar31 = bVar5 < 0x10;
  bVar35 = SBORROW1(bVar5,'\x10');
  bVar34 = (char)(bVar5 - 0x10) < '\0';
  bVar32 = bVar5 == 0x10;
  if (!bVar31) {
    cVar11 = '\x04';
    if (7 < bVar5) {
      bVar35 = SBORROW1(bVar5,'\f');
      bVar34 = (char)(bVar5 - 0xc) < '\0';
      bVar32 = bVar5 == 0xc;
      bVar31 = true;
      if (bVar5 < 0xc) goto LAB_1000_383e;
    }
    cVar11 = '\b';
    if (bVar5 != 0) {
      bVar35 = SBORROW1(bVar5,'\x05');
      bVar34 = (char)(bVar5 - 5) < '\0';
      bVar32 = bVar5 == 5;
      bVar31 = true;
      if (bVar5 < 5) goto LAB_1000_383e;
    }
    cVar11 = '\v';
    bVar31 = bVar5 < 5;
    bVar35 = SBORROW1(bVar5,'\x05');
    bVar34 = (char)(bVar5 - 5) < '\0';
    bVar32 = bVar5 == 5;
    if (!bVar32) {
      in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar2 = (byte *)(uVar13 + (int)unaff_SI);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar5 ^ 0xf8) & 0xf) | in_AF;
      uVar7 = (undefined2)((ulong)in_ESP >> 0x10);
      pbVar2 = (byte *)((int)unaff_DI + uVar13 + 0x854);
      *pbVar2 = *pbVar2 & 0xb;
      uVar33 = *pbVar2 == 0;
      puVar16 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar17 = (undefined2 *)(puVar16 + -2);
      *(undefined2 *)(puVar16 + -2) = 0x387a;
      uVar37 = func_0x0001b476();
      uVar12 = (uint)((ulong)uVar37 >> 0x10);
      if (!(bool)uVar33) {
        *(byte *)((int)unaff_SI + 0xb) = (byte)uVar37;
      }
      uVar6 = CONCAT11((char)((ulong)uVar37 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
      bVar5 = (byte)uVar6;
      *(byte *)(unaff_SI + 5) = bVar5;
      swi(4);
      pbVar2 = (byte *)(unaff_BP + (int)unaff_SI);
      *pbVar2 = *pbVar2 + bVar5;
      if ((POPCOUNT(*pbVar2) & 1U) != 0) {
        pbVar2 = (byte *)((int)unaff_SI + uVar13 + 0x33);
        bVar5 = *pbVar2;
        bVar9 = (byte)((ulong)uVar37 >> 0x10);
        bVar8 = *pbVar2;
        cVar11 = (char)((ulong)uVar37 >> 0x18) + *(byte *)(uVar13 + (int)unaff_SI);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar11;
        pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar2 = *pbVar2 | (byte)(CONCAT22(CONCAT11(cVar11,bVar9 + bVar8),
                                            (uVar6 + 0x5556) - (uint)CARRY1(bVar9,bVar5)) %
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
        bVar31 = CARRY1((byte)uVar13,*(byte *)(unaff_BP + (int)unaff_SI));
        uVar13 = CONCAT11((char)(uVar13 >> 8),(byte)uVar13 + *(byte *)(unaff_BP + (int)unaff_SI));
code_r0x000138eb:
        *(undefined2 *)((int)puVar17 + -2) = unaff_SS;
        if (!bVar31) {
          puVar29 = unaff_DI;
          unaff_DI = (uint *)((int)unaff_DI + 1);
          *(byte *)puVar29 = 0x30;
          uVar6 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
          *(uint *)((int)puVar17 + -2) = uVar13;
          *(uint *)((int)puVar17 + -4) = uVar6;
          uVar13 = unaff_SI[0x15];
          uVar12 = (uVar12 | 0x3000) - *(int *)(byte *)(uVar13 + (int)unaff_SI);
          bVar8 = (byte)(uVar6 >> 8);
          bVar5 = (char)uVar6 + 8;
          if (bVar5 != *(byte *)(uVar13 + 0xd27e)) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *(undefined2 *)((int)puVar17 + -6) = CONCAT11(bVar8,bVar5);
          *(uint *)((int)puVar17 + -8) = in_CX;
          *(uint *)((int)puVar17 + -10) = uVar12;
          *(uint *)((int)puVar17 + -0xc) = uVar13;
          *(undefined1 **)(undefined1 *)((int)puVar17 + -0xe) = (undefined1 *)((int)puVar17 + -4);
          *(uint *)((int)puVar17 + -0x10) = unaff_BP;
          *(undefined2 *)((int)puVar17 + -0x12) = unaff_SI;
          *(undefined2 *)((int)puVar17 + -0x14) = unaff_DI;
          uVar6 = *unaff_DI;
          cVar11 = (char)(in_CX >> 8);
          bVar9 = cVar11 + bVar5;
          in_CX = CONCAT11(bVar9,(char)in_CX);
          unaff_BP = 0x874;
          if (SCARRY1(cVar11,bVar5)) {
            puVar18 = (undefined2 *)*(undefined2 *)((int)puVar17 + -0x14);
            puVar24 = *(uint **)(byte *)((int)unaff_DI + (uVar13 - 0x18));
            puVar29 = puVar24 + 0x43a;
            uVar3 = *puVar29;
            *puVar29 = *puVar29 + 0x809;
            in_CX = 0x4379;
            puVar24[0x43a] =
                 puVar24[0x43a] + CONCAT11(bVar8 | (byte)uVar6,bVar5 | bVar9) +
                 (uint)(0xf7f6 < uVar3);
          }
          else {
            *(undefined2 *)((int)puVar17 + -0x16) = 0x874;
            puVar18 = (undefined2 *)((int)puVar17 + -0x18);
            *(undefined2 *)((int)puVar17 + -0x18) = 0x874;
            puVar24 = unaff_SI;
          }
LAB_1000_3958:
          *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar12;
          unaff_SI = (uint *)((int)puVar24 + 1);
          out((byte)*puVar24,uVar12);
          uVar13 = CONCAT11((byte)(uVar13 >> 8) & *(byte *)((int)unaff_SI + unaff_BP + 0x11),
                            (char)uVar13);
          bVar8 = (byte)uVar12;
          cVar36 = SBORROW1(bVar8,(byte)puVar24[0x39]);
          bVar5 = (byte)puVar24[0x39];
          cVar11 = (char)(bVar8 - bVar5) < '\0';
          bVar31 = bVar8 == bVar5;
          puVar19 = (uint *)((int)puVar18 + -2);
          *(undefined2 *)((int)puVar18 + -2) = 0x396b;
          bVar5 = func_0x0001b3ed();
          iVar10 = extraout_DX_00;
          if (!bVar31) {
            *(byte *)(puVar24 + 6) = bVar5;
            *(undefined2 *)((int)puVar19 + -2) = 0x3973;
            puVar19 = (uint *)((int)puVar19 + -2);
            bVar5 = func_0x0001b617();
            iVar10 = extraout_DX_01;
          }
          if (cVar36 != cVar11) {
            iVar10 = iVar10 + 1;
            puVar19[-1] = (uint)unaff_DI;
            puVar19[-2] = iVar10;
            puVar19[-3] = CONCAT11((char)(in_CX >> 8),8);
            puVar19[-4] = uVar13;
            if (iVar10 == 0) {
LAB_1000_39c7:
              pcVar4 = (code *)swi(1);
              uVar38 = (*pcVar4)();
              return uVar38;
            }
            pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
            *pbVar2 = *pbVar2 | (byte)((uint)iVar10 >> 8);
code_r0x00013985:
            pbVar2 = (byte *)((int)unaff_DI + uVar13 + 0x12);
            *(byte **)pbVar2 = (byte *)((int)unaff_DI + *(int *)pbVar2 + 2);
            puVar20 = (undefined1 *)0x2e1c;
            *(undefined2 *)0x2e1c = 0x3990;
            FUN_1000_8d53();
            *(undefined2 *)(puVar20 + -2) = 0x399f;
            func_0x00018e51();
            pcVar4 = (code *)swi(3);
            uVar38 = (*pcVar4)();
            return uVar38;
          }
          bVar5 = bVar5 ^ *(byte *)(unaff_BP + (int)unaff_SI);
          in_AF = 9 < (bVar5 & 0xf) | in_AF;
          bVar5 = bVar5 + in_AF * '\x06' & 0xf;
          unaff_DS = *puVar19;
          pbVar2 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
          bVar31 = bVar5 < *pbVar2 || bVar5 == *pbVar2;
          puVar29 = (uint *)CONCAT22(uVar7,puVar19);
          *puVar19 = 0x39ba;
          uVar37 = FUN_1000_a1b8();
          uVar12 = (uint)uVar37;
          if (bVar31) {
            if (in_CX == 1) {
              do {
                iVar10 = 0x40;
                uVar13 = uVar12;
                do {
                  uVar12 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
                  puVar24 = unaff_SI;
                  if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
                    puVar29 = puVar29 + -2;
                    *puVar29 = unaff_DS;
                    bVar5 = (byte)uVar13 | 0x17;
                    bVar8 = (byte)(uVar13 >> 8);
                    if (bVar8 == (byte)unaff_SI[6]) {
                      uVar13 = CONCAT11(bVar5 / 0x5e,bVar5 % 0x5e);
                      puVar24 = unaff_DI;
                      goto code_r0x00013a16;
                    }
                    uVar12 = CONCAT11(bVar8 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)uVar13) |
                             0x17;
                    *(byte *)(unaff_SI + 0x3931) =
                         (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar10 >> 8);
                    *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
                    in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
                    uVar13 = *(uint *)puVar29;
                    puVar29 = (uint *)CONCAT22((int)((ulong)puVar29 >> 0x10),(uint *)puVar29 + 1);
                    puVar24 = unaff_SI + 8;
                    unaff_DI = unaff_SI;
                  }
                  iVar10 = iVar10 + -1;
                  unaff_SI = puVar24;
                } while (iVar10 != 0);
                unaff_SI = (uint *)*(uint *)puVar29;
                puVar29 = (uint *)CONCAT22((int)((ulong)puVar29 >> 0x10),(uint *)puVar29 + 1);
                puVar24 = unaff_DI;
code_r0x00013a16:
                uVar7 = (undefined2)((ulong)puVar29 >> 0x10);
                puVar21 = (uint *)puVar29;
                if (0x1ef < uVar12) goto code_r0x00013a1c;
                pbVar2 = (byte *)((int)puVar24 + unaff_BP + 0x59);
                *pbVar2 = *pbVar2 | (byte)uVar12;
                bVar5 = *(byte *)(uVar12 + puVar21[1]);
                puVar21[1] = (uint)unaff_SI;
                *(char *)0xaaaa =
                     *(char *)0xaaaa + (byte)uVar12 + ((byte)((char)unaff_BP + 1U) < bVar5);
                uVar12 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
                unaff_DI = (uint *)puVar21[1];
                puVar29 = (uint *)CONCAT22(uVar7,puVar21 + 2);
                unaff_SI = (uint *)0xc800;
                unaff_BP = uVar13;
              } while( true );
            }
            goto code_r0x00013985;
          }
          out((int)((ulong)uVar37 >> 0x10),(char)uVar37);
          puVar1 = unaff_SI;
          bVar31 = CARRY2(*puVar1,uVar12);
          *puVar1 = *puVar1 + uVar12;
          bVar34 = (int)*puVar1 < 0;
          bVar32 = *puVar1 == 0;
          bVar5 = POPCOUNT(*puVar1 & 0xff);
          in_CX = in_CX - 1;
          if (in_CX == 0 || bVar32) goto LAB_1000_39c7;
          goto LAB_1000_3a35;
        }
        uVar13 = uVar13 + 1;
        in_ESP = (undefined1 *)CONCAT22(uVar7,(undefined1 *)((int)puVar17 + -4));
        *(undefined2 *)((int)puVar17 + -4) = 0x810;
        *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar12;
FUN_1000_38de:
        uVar7 = (undefined2)((ulong)in_ESP >> 0x10);
        puVar17 = (undefined2 *)((undefined1 *)in_ESP + -2);
        *(undefined2 *)((undefined1 *)in_ESP + -2) = 0x38e1;
        FUN_1000_7494();
        *(byte *)(uVar13 + (int)unaff_SI) = *(byte *)(uVar13 + (int)unaff_SI) & (byte)in_CX;
        LOCK();
        uVar33 = *(undefined1 *)(unaff_BP + 0x72);
        *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
        uVar12 = CONCAT11(uVar33,(char)extraout_DX);
        UNLOCK();
      } while( true );
    }
  }
LAB_1000_383e:
  if (bVar31) {
    *(undefined2 *)((undefined1 *)in_ESP + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar32 && bVar35 == bVar34) {
    return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
  }
LAB_1000_37ea_2:
  puVar14 = (undefined1 *)in_ESP;
  if (cVar11 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
    puVar15 = (undefined2 *)(puVar14 + -2);
    puVar14 = puVar14 + -2;
    *puVar15 = 0x37f3;
    func_0x0001b6c0();
  }
  return CONCAT22(*(undefined2 *)(puVar14 + 10),*(undefined2 *)(puVar14 + 0xe));
code_r0x00013a1c:
  unaff_SS = *puVar21;
  *(longdouble *)(uVar12 + (int)puVar24) = in_ST0;
  puVar29 = (uint *)CONCAT22(uVar7,(uint *)(puVar21[1] + -2));
  *(undefined2 *)(puVar21[1] + -2) = unaff_ES;
  uVar13 = puVar24[2];
  uVar12 = (uint)*(byte *)((int)puVar24 + -0x79);
  bVar31 = (byte)iVar10 < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar11 = (byte)iVar10 - *(byte *)(unaff_BP + (int)unaff_SI);
  in_CX = CONCAT11((char)((uint)iVar10 >> 8),cVar11);
  bVar34 = cVar11 < '\0';
  bVar32 = cVar11 == '\0';
  bVar5 = POPCOUNT(cVar11);
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
  if (bVar32) {
    *(byte *)(uVar13 + (int)unaff_SI) = *(byte *)(uVar13 + (int)unaff_SI) + 1;
    puVar22 = (uint *)puVar29;
    puVar29 = (uint *)CONCAT22((int)((ulong)puVar29 >> 0x10),puVar22 + -1);
    puVar22[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar34 << 7 | bVar32 << 6 | in_AF << 4 | ((bVar5 & 1) == 0) << 2 | 2 |
                          bVar31,(char)uVar12)) {
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar2 = *pbVar2 | (byte)(uVar13 >> 8);
      puVar1 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar1 = (char)uVar12 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar2 = (byte *)((uVar13 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar1 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 - in_CX;
    bVar5 = ((char)(uVar13 >> 1) + (char)(uVar13 >> 2) + -0x10) - (uVar12 < in_CX) | 2;
    iVar10 = *(int *)(byte *)((int)unaff_DI + 0x55);
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar5;
    ((uint *)puVar29)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)in_CX;
    puVar24 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar10 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar5;
      pcVar4 = (code *)swi(1);
      uVar38 = (*pcVar4)();
      return uVar38;
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
    pcVar4 = (code *)swi(0x20);
    (*pcVar4)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar13 >> 8);
    puVar23 = (uint *)puVar29;
    uVar30 = (undefined2)((ulong)puVar29 >> 0x10);
    puVar23[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + uVar13 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)unaff_DI);
    unaff_DI = (uint *)puVar23[-1];
    unaff_SI = (uint *)*puVar23;
    unaff_BP = puVar23[1];
    in_CX = puVar23[5];
    uVar7 = puVar23[6];
    uVar13 = CONCAT11((char)(puVar23[3] >> 8),(byte)puVar23[3] | *(byte *)0x5d02) |
             *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar23[6] = (uint)unaff_DI;
    pbVar2 = (byte *)((int)unaff_SI + uVar13 + 0x2c2);
    cVar36 = SCARRY1((char)uVar7,*pbVar2);
    bVar31 = (char)((char)uVar7 + *pbVar2) < '\0';
    puVar24 = puVar23 + 5;
    puVar23[5] = 0x3a83;
    uVar37 = func_0x00013e95();
    bVar5 = (byte)uVar37;
    out(0x6f,bVar5);
    *(undefined1 *)0x1108 = (char)uVar13;
    cVar11 = (char)((ulong)uVar37 >> 0x18);
    if (bVar31) {
      bVar9 = (byte)(uVar13 >> 8);
      puVar29 = (uint *)((int)unaff_DI + -0x53);
      uVar3 = (uint)(bVar9 < (byte)(in_CX >> 8));
      uVar12 = *puVar29;
      uVar6 = *puVar29;
      *puVar29 = uVar6 + 0xe02d + uVar3;
      bVar8 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar9 = bVar9 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar37 >> 8);
      uVar13 = CONCAT11(bVar9,(char)uVar13);
      if ((char)bVar9 < '\0') {
        bVar31 = unaff_SI[3] < 1000;
        if (!bVar31) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar24 + -2) = 0x3b26;
          puVar24 = (uint *)((int)puVar24 + -2);
          uVar37 = func_0x00013966();
          if (!bVar31) goto LAB_1000_3b55_1;
        }
        in_ESP = (undefined1 *)CONCAT22(uVar30,(undefined1 *)((int)puVar24 + -2));
        *(undefined2 *)((int)puVar24 + -2) = 0x3b2d;
        uVar38 = FUN_1000_8cb7();
        uVar12 = (uint)(uVar38 >> 0x10);
        bVar31 = (byte)uVar38 < 0x5a;
        puVar25 = (undefined1 *)in_ESP;
        if (bVar31) {
          bVar31 = true;
          if ((byte)uVar38 < 0x50) goto LAB_1000_3b62;
          uVar7 = (undefined2)((ulong)in_ESP >> 0x10);
          puVar17 = (undefined2 *)(puVar25 + -2);
          *(undefined2 *)(puVar25 + -2) = 0x3b38;
          bVar31 = false;
          goto code_r0x000138eb;
        }
        puVar26 = puVar25 + -2;
        *(undefined2 *)(puVar25 + -2) = 0x3b42;
        uVar37 = FUN_1000_3607();
        cVar11 = (char)in_CX;
        if (bVar31) {
          in_ESP = (undefined1 *)ZEXT24(puVar26 + -2);
          *(undefined2 *)(puVar26 + -2) = 0x3b47;
          goto LAB_1000_37ea_2;
        }
LAB_1000_3b55_1:
        uVar38 = CONCAT22((int)((ulong)uVar37 >> 0x10),
                          CONCAT11((char)((ulong)uVar37 >> 8),(char)uVar37 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar29 = (uint *)ZEXT24((undefined1 *)((int)puVar24 + -2));
      *(undefined2 *)((int)puVar24 + -2) = unaff_CS;
      iVar10 = CONCAT11(cVar11 - *(byte *)((int)unaff_SI + uVar13 + 0x23c9),
                        (char)((ulong)uVar37 >> 0x10) + bVar8 +
                        (0x1fd2 < uVar12 || CARRY2(uVar6 + 0xe02d,uVar3)));
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar2 = *pbVar2 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar36 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar11;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar13 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar24 + 10),*(undefined2 *)((int)puVar24 + 0xe));
}


