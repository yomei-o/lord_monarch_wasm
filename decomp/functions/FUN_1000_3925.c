/* 1000:3925 */

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
/* WARNING: Removing unreachable block (ram,0x00013a25) */
/* WARNING: Removing unreachable block (ram,0x00013ace) */
/* WARNING: Removing unreachable block (ram,0x00013ada) */
/* WARNING: Removing unreachable block (ram,0x00013ad5) */
/* WARNING: Removing unreachable block (ram,0x00013add) */
/* WARNING: Removing unreachable block (ram,0x00013ae4) */
/* WARNING: Removing unreachable block (ram,0x00013947) */
/* WARNING: Removing unreachable block (ram,0x00013889) */
/* WARNING: Removing unreachable block (ram,0x000139ea) */
/* WARNING: Removing unreachable block (ram,0x0001384c) */

uint FUN_1000_3925(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  code *pcVar4;
  char in_AL;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte bVar10;
  undefined2 uVar8;
  uint uVar9;
  byte bVar11;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar12;
  uint uVar13;
  byte bVar14;
  undefined2 *puVar15;
  undefined1 *puVar16;
  uint *puVar17;
  uint *puVar18;
  undefined1 *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  uint *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  uint *in_ESP;
  undefined2 uVar28;
  uint *puVar27;
  uint unaff_BP;
  uint *unaff_SI;
  uint *puVar29;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  byte in_AF;
  undefined1 uVar30;
  bool bVar31;
  bool bVar32;
  char cVar33;
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
  
code_r0x00013925:
  bVar10 = *(byte *)(unaff_BP + (int)unaff_SI);
  puVar18 = (uint *)in_ESP;
  uVar7 = *puVar18;
  uVar28 = (undefined2)((ulong)in_ESP >> 0x10);
  unaff_SI = (uint *)((int)unaff_SI + -1);
  bVar14 = *(byte *)(unaff_BP + (int)unaff_SI);
  pbVar2 = (byte *)0xad20;
  bVar5 = *pbVar2;
  bVar11 = (byte)uVar7;
  *pbVar2 = *pbVar2 - bVar11;
  *(byte *)(unaff_BP + (int)unaff_DI) =
       *(byte *)(unaff_BP + (int)unaff_DI) + bVar11 + (bVar5 < bVar11);
  *(byte *)unaff_SI = (byte)*unaff_SI & (in_AL + bVar10) - bVar14;
  iVar12 = puVar18[2];
  unaff_BP = 0x874;
  puVar18[2] = 0x874;
  puVar17 = puVar18 + 1;
  puVar18[1] = 0x874;
  uVar13 = uVar7;
LAB_1000_3958:
  *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar13;
  puVar23 = (uint *)((int)unaff_SI + 1);
  out((byte)*unaff_SI,uVar13);
  uVar9 = CONCAT11((byte)((uint)iVar12 >> 8) & *(byte *)((int)puVar23 + unaff_BP + 0x11),
                   (char)iVar12);
  bVar10 = (byte)uVar13;
  cVar36 = SBORROW1(bVar10,(byte)unaff_SI[0x39]);
  bVar5 = (byte)unaff_SI[0x39];
  cVar33 = (char)(bVar10 - bVar5) < '\0';
  bVar31 = bVar10 == bVar5;
  puVar29 = (uint *)((int)puVar17 + -2);
  *(undefined2 *)((int)puVar17 + -2) = 0x396b;
  bVar5 = func_0x0001b3ed();
  iVar12 = extraout_DX_00;
  if (!bVar31) {
    *(byte *)(unaff_SI + 6) = bVar5;
    *(undefined2 *)((int)puVar29 + -2) = 0x3973;
    puVar29 = (uint *)((int)puVar29 + -2);
    bVar5 = func_0x0001b617();
    iVar12 = extraout_DX_01;
  }
  if (cVar36 != cVar33) {
    iVar12 = iVar12 + 1;
    puVar29[-1] = (uint)unaff_DI;
    puVar29[-2] = iVar12;
    puVar29[-3] = CONCAT11((char)(uVar7 >> 8),8);
    puVar29[-4] = uVar9;
    if (iVar12 == 0) {
LAB_1000_39c7:
      pcVar4 = (code *)swi(1);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
    pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
    *pbVar2 = *pbVar2 | (byte)((uint)iVar12 >> 8);
code_r0x00013985:
    pbVar2 = (byte *)((int)unaff_DI + uVar9 + 0x12);
    *(byte **)pbVar2 = (byte *)((int)unaff_DI + *(int *)pbVar2 + 2);
    puVar19 = (undefined1 *)0x2e1c;
    *(undefined2 *)0x2e1c = 0x3990;
    FUN_1000_8d53();
    *(undefined2 *)(puVar19 + -2) = 0x399f;
    func_0x00018e51();
    pcVar4 = (code *)swi(3);
    uVar7 = (*pcVar4)();
    return uVar7;
  }
  bVar5 = bVar5 ^ *(byte *)(unaff_BP + (int)puVar23);
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = bVar5 + in_AF * '\x06' & 0xf;
  unaff_DS = *puVar29;
  pbVar2 = (byte *)((int)puVar23 + unaff_BP + 0x8b5f);
  bVar31 = bVar5 < *pbVar2 || bVar5 == *pbVar2;
  puVar27 = (uint *)CONCAT22(uVar28,puVar29);
  *puVar29 = 0x39ba;
  uVar37 = FUN_1000_a1b8();
  uVar13 = (uint)uVar37;
  if (bVar31) {
    if (uVar7 == 1) {
      do {
        iVar12 = 0x40;
        uVar7 = uVar13;
        do {
          uVar13 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
          puVar29 = puVar23;
          if (((*puVar23 & 0x80) == 0) && ((puVar23[5] & 0x20) != 0)) {
            puVar27 = puVar27 + -2;
            *puVar27 = unaff_DS;
            bVar5 = (byte)uVar7 | 0x17;
            bVar10 = (byte)(uVar7 >> 8);
            if (bVar10 == (byte)puVar23[6]) {
              uVar7 = CONCAT11(bVar5 / 0x5e,bVar5 % 0x5e);
              puVar29 = unaff_DI;
              goto code_r0x00013a16;
            }
            uVar13 = CONCAT11(bVar10 & *(byte *)(unaff_BP + (int)puVar23),(byte)uVar7) | 0x17;
            *(byte *)(puVar23 + 0x3931) = (byte)puVar23[0x3931] ^ (byte)((uint)iVar12 >> 8);
            *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
            in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
            uVar7 = *(uint *)puVar27;
            puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
            puVar29 = puVar23 + 8;
            unaff_DI = puVar23;
          }
          iVar12 = iVar12 + -1;
          puVar23 = puVar29;
        } while (iVar12 != 0);
        puVar23 = (uint *)*(uint *)puVar27;
        puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
        puVar29 = unaff_DI;
code_r0x00013a16:
        puVar20 = (uint *)puVar27;
        uVar28 = (undefined2)((ulong)puVar27 >> 0x10);
        if (0x1ef < uVar13) goto code_r0x00013a1c;
        pbVar2 = (byte *)((int)puVar29 + unaff_BP + 0x59);
        *pbVar2 = *pbVar2 | (byte)uVar13;
        bVar5 = *(byte *)(uVar13 + puVar20[1]);
        puVar20[1] = (uint)puVar23;
        *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar13 + ((byte)((char)unaff_BP + 1U) < bVar5);
        uVar13 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
        unaff_DI = (uint *)puVar20[1];
        puVar27 = (uint *)CONCAT22(uVar28,puVar20 + 2);
        puVar23 = (uint *)0xc800;
        unaff_BP = uVar7;
      } while( true );
    }
    goto code_r0x00013985;
  }
  out((int)((ulong)uVar37 >> 0x10),(char)uVar37);
  puVar1 = puVar23;
  bVar31 = CARRY2(*puVar1,uVar13);
  *puVar1 = *puVar1 + uVar13;
  bVar34 = (int)*puVar1 < 0;
  bVar32 = *puVar1 == 0;
  bVar5 = POPCOUNT(*puVar1 & 0xff);
  uVar7 = uVar7 - 1;
  if (uVar7 == 0 || bVar32) goto LAB_1000_39c7;
  goto LAB_1000_3a35;
LAB_1000_381b:
  bVar5 = (byte)uVar9;
  bVar31 = bVar5 < 0x10;
  bVar35 = SBORROW1(bVar5,'\x10');
  bVar34 = (char)(bVar5 - 0x10) < '\0';
  bVar32 = bVar5 == 0x10;
  if (!bVar31) {
    cVar33 = '\x04';
    if (7 < bVar5) {
      bVar35 = SBORROW1(bVar5,'\f');
      bVar34 = (char)(bVar5 - 0xc) < '\0';
      bVar32 = bVar5 == 0xc;
      bVar31 = true;
      if (bVar5 < 0xc) goto LAB_1000_383e;
    }
    cVar33 = '\b';
    if (bVar5 != 0) {
      bVar35 = SBORROW1(bVar5,'\x05');
      bVar34 = (char)(bVar5 - 5) < '\0';
      bVar32 = bVar5 == 5;
      bVar31 = true;
      if (bVar5 < 5) goto LAB_1000_383e;
    }
    cVar33 = '\v';
    bVar31 = bVar5 < 5;
    bVar35 = SBORROW1(bVar5,'\x05');
    bVar34 = (char)(bVar5 - 5) < '\0';
    bVar32 = bVar5 == 5;
    if (!bVar32) {
      uVar7 = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar2 = (byte *)(iVar12 + (int)unaff_SI);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar5 ^ 0xf8) & 0xf) | in_AF;
      pbVar2 = (byte *)((int)unaff_DI + iVar12 + 0x854);
      *pbVar2 = *pbVar2 & 0xb;
      uVar30 = *pbVar2 == 0;
      puVar16 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar17 = (uint *)(puVar16 + -2);
      *(undefined2 *)(puVar16 + -2) = 0x387a;
      uVar37 = func_0x0001b476();
      uVar13 = (uint)((ulong)uVar37 >> 0x10);
      if (!(bool)uVar30) {
        *(byte *)((int)unaff_SI + 0xb) = (byte)uVar37;
      }
      uVar9 = CONCAT11((char)((ulong)uVar37 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
      bVar5 = (byte)uVar9;
      *(byte *)(unaff_SI + 5) = bVar5;
      swi(4);
      pbVar2 = (byte *)(unaff_BP + (int)unaff_SI);
      *pbVar2 = *pbVar2 + bVar5;
      if ((POPCOUNT(*pbVar2) & 1U) != 0) {
        pbVar2 = (byte *)((int)unaff_SI + iVar12 + 0x33);
        bVar5 = *pbVar2;
        bVar14 = (byte)((ulong)uVar37 >> 0x10);
        bVar10 = *pbVar2;
        cVar33 = (char)((ulong)uVar37 >> 0x18) + *(byte *)(iVar12 + (int)unaff_SI);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar33;
        pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar2 = *pbVar2 | (byte)(CONCAT22(CONCAT11(cVar33,bVar14 + bVar10),
                                            (uVar9 + 0x5556) - (uint)CARRY1(bVar14,bVar5)) %
                                  (ulong)unaff_SI[0x410]);
        *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
             *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
        return *puVar17;
      }
      if (*pbVar2 != 0) goto code_r0x000138e6;
      goto LAB_1000_3958;
    }
  }
LAB_1000_383e:
  if (bVar31) {
    *(undefined2 *)(puVar26 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar32 && bVar35 == bVar34) {
    return *(uint *)(unaff_BP + 0xe);
  }
  goto LAB_1000_37ea_2;
code_r0x00013a1c:
  unaff_SS = *puVar20;
  *(longdouble *)(uVar13 + (int)puVar29) = in_ST0;
  puVar27 = (uint *)CONCAT22(uVar28,(uint *)(puVar20[1] + -2));
  *(undefined2 *)(puVar20[1] + -2) = unaff_ES;
  uVar9 = puVar29[2];
  uVar13 = (uint)*(byte *)((int)puVar29 + -0x79);
  bVar31 = (byte)iVar12 < *(byte *)(unaff_BP + (int)puVar23);
  cVar33 = (byte)iVar12 - *(byte *)(unaff_BP + (int)puVar23);
  uVar7 = CONCAT11((char)((uint)iVar12 >> 8),cVar33);
  bVar34 = cVar33 < '\0';
  bVar32 = cVar33 == '\0';
  bVar5 = POPCOUNT(cVar33);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar29;
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
    *(byte *)(uVar9 + (int)puVar23) = *(byte *)(uVar9 + (int)puVar23) + 1;
    puVar21 = (uint *)puVar27;
    puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),puVar21 + -1);
    puVar21[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar34 << 7 | bVar32 << 6 | in_AF << 4 | ((bVar5 & 1) == 0) << 2 | 2 |
                          bVar31,(char)uVar13)) {
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar2 = *pbVar2 | (byte)(uVar9 >> 8);
      puVar1 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar1 = (char)uVar13 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + uVar7;
    pbVar2 = (byte *)((uVar9 >> 2) + (int)puVar23);
    *pbVar2 = *pbVar2 - 0x15;
    puVar1 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar13 = *puVar1;
    *puVar1 = *puVar1 - uVar7;
    bVar5 = ((char)(uVar9 >> 1) + (char)(uVar9 >> 2) + -0x10) - (uVar13 < uVar7) | 2;
    iVar12 = *(int *)(byte *)((int)unaff_DI + 0x55);
    unaff_SI = puVar23;
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar5;
    ((uint *)puVar27)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)uVar7;
    puVar23 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar12 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar5;
      pcVar4 = (code *)swi(1);
      uVar7 = (*pcVar4)();
      return uVar7;
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
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar9 >> 8);
    puVar22 = (uint *)puVar27;
    uVar28 = (undefined2)((ulong)puVar27 >> 0x10);
    puVar22[-1] = unaff_ES;
    pbVar2 = (byte *)((int)puVar23 + uVar9 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)unaff_DI);
    unaff_DI = (uint *)puVar22[-1];
    unaff_SI = (uint *)*puVar22;
    unaff_BP = puVar22[1];
    uVar7 = puVar22[5];
    uVar8 = puVar22[6];
    uVar13 = CONCAT11((char)(puVar22[3] >> 8),(byte)puVar22[3] | *(byte *)0x5d02) |
             *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar22[6] = (uint)unaff_DI;
    pbVar2 = (byte *)((int)unaff_SI + uVar13 + 0x2c2);
    cVar36 = SCARRY1((char)uVar8,*pbVar2);
    bVar31 = (char)((char)uVar8 + *pbVar2) < '\0';
    puVar23 = puVar22 + 5;
    puVar22[5] = 0x3a83;
    uVar37 = func_0x00013e95();
    bVar5 = (byte)uVar37;
    out(0x6f,bVar5);
    *(undefined1 *)0x1108 = (char)uVar13;
    cVar33 = (char)((ulong)uVar37 >> 0x18);
    if (bVar31) {
      bVar14 = (byte)(uVar13 >> 8);
      puVar27 = (uint *)((int)unaff_DI + -0x53);
      uVar3 = (uint)(bVar14 < (byte)(uVar7 >> 8));
      uVar9 = *puVar27;
      uVar6 = *puVar27;
      *puVar27 = uVar6 + 0xe02d + uVar3;
      bVar10 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar14 = bVar14 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar37 >> 8);
      iVar12 = CONCAT11(bVar14,(char)uVar13);
      if ((char)bVar14 < '\0') {
        bVar31 = unaff_SI[3] < 1000;
        if (!bVar31) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar23 + -2) = 0x3b26;
          puVar23 = (uint *)((int)puVar23 + -2);
          uVar8 = func_0x00013966();
          if (!bVar31) goto LAB_1000_3b55_1;
        }
        puVar25 = (undefined1 *)((int)puVar23 + -2);
        *(undefined2 *)((int)puVar23 + -2) = 0x3b2d;
        uVar37 = FUN_1000_8cb7();
        uVar13 = (uint)((ulong)uVar37 >> 0x10);
        uVar9 = (uint)uVar37;
        bVar31 = (byte)uVar37 < 0x5a;
        if (bVar31) {
          bVar31 = true;
          if ((byte)uVar37 < 0x50) {
            do {
              puVar26 = puVar25;
              if (bVar31) {
                puVar26 = puVar25 + -2;
                *(undefined2 *)(puVar25 + -2) = 0x3b67;
                uVar9 = func_0x000137e6();
                cVar33 = (char)uVar7;
                if (bVar31) goto LAB_1000_381b;
              }
              if (*(int *)0x3480 != 0) goto code_r0x00013b57;
              *(uint *)(puVar26 + -2) = unaff_BP;
              puVar25 = puVar26 + -4;
              *(uint *)(puVar26 + -4) = unaff_BP;
              pbVar2 = (byte *)(iVar12 + (int)unaff_SI);
              bVar5 = (byte)(uVar9 >> 8);
              bVar31 = CARRY1(*pbVar2,bVar5);
              *pbVar2 = *pbVar2 + bVar5;
              iVar12 = iVar12 + -1;
            } while( true );
          }
          puVar17 = (uint *)(puVar25 + -2);
          *(undefined2 *)(puVar25 + -2) = 0x3b38;
          bVar31 = false;
          while( true ) {
            *(undefined2 *)((int)puVar17 + -2) = unaff_SS;
            if (!bVar31) break;
            iVar12 = iVar12 + 1;
            puVar26 = (undefined1 *)((int)puVar17 + -4);
            *(undefined2 *)((int)puVar17 + -4) = 0x810;
            *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar13;
FUN_1000_38de:
            puVar17 = (uint *)(puVar26 + -2);
            *(undefined2 *)(puVar26 + -2) = 0x38e1;
            FUN_1000_7494();
            *(byte *)(iVar12 + (int)unaff_SI) = *(byte *)(iVar12 + (int)unaff_SI) & (byte)uVar7;
            LOCK();
            uVar30 = *(undefined1 *)(unaff_BP + 0x72);
            *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
            uVar13 = CONCAT11(uVar30,(char)extraout_DX);
            UNLOCK();
code_r0x000138e6:
            *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
            bVar31 = CARRY1((byte)iVar12,*(byte *)(unaff_BP + (int)unaff_SI));
            iVar12 = CONCAT11((char)((uint)iVar12 >> 8),
                              (byte)iVar12 + *(byte *)(unaff_BP + (int)unaff_SI));
          }
          puVar27 = unaff_DI;
          unaff_DI = (uint *)((int)unaff_DI + 1);
          *(byte *)puVar27 = 0x30;
          uVar6 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
          *(int *)((int)puVar17 + -2) = iVar12;
          *(uint *)((int)puVar17 + -4) = uVar6;
          uVar9 = unaff_SI[0x15];
          iVar12 = *(int *)(byte *)(uVar9 + (int)unaff_SI);
          in_AL = (char)uVar6 + '\b';
          if (in_AL != *(char *)(uVar9 + 0xd27e)) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *(undefined2 *)((int)puVar17 + -6) = CONCAT11((char)(uVar6 >> 8),in_AL);
          *(uint *)((int)puVar17 + -8) = uVar7;
          *(int *)((int)puVar17 + -10) = (uVar13 | 0x3000) - iVar12;
          *(uint *)((int)puVar17 + -0xc) = uVar9;
          *(undefined1 **)(undefined1 *)((int)puVar17 + -0xe) = (undefined1 *)((int)puVar17 + -4);
          *(uint *)((int)puVar17 + -0x10) = unaff_BP;
          *(undefined2 *)((int)puVar17 + -0x12) = unaff_SI;
          in_ESP = (uint *)CONCAT22(uVar28,(uint *)((int)puVar17 + -0x14));
          *(undefined2 *)((int)puVar17 + -0x14) = unaff_DI;
          goto code_r0x00013925;
        }
        puVar24 = puVar25 + -2;
        *(undefined2 *)(puVar25 + -2) = 0x3b42;
        uVar8 = FUN_1000_3607();
        cVar33 = (char)uVar7;
        if (bVar31) {
          puVar26 = puVar24 + -2;
          *(undefined2 *)(puVar24 + -2) = 0x3b47;
LAB_1000_37ea_2:
          if (cVar33 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
            puVar15 = (undefined2 *)(puVar26 + -2);
            puVar26 = puVar26 + -2;
            *puVar15 = 0x37f3;
            func_0x0001b6c0();
          }
          return *(uint *)(puVar26 + 0xe);
        }
LAB_1000_3b55_1:
        uVar9 = CONCAT11((char)((uint)uVar8 >> 8),(char)uVar8 + -0x80) | 1;
code_r0x00013b57:
        *(byte *)unaff_SI = (byte)*unaff_SI | 1;
        return uVar9;
      }
      puVar27 = (uint *)ZEXT24((undefined1 *)((int)puVar23 + -2));
      *(undefined2 *)((int)puVar23 + -2) = unaff_CS;
      iVar12 = CONCAT11(cVar33 - *(byte *)((int)unaff_SI + iVar12 + 0x23c9),
                        (char)((ulong)uVar37 >> 0x10) + bVar10 +
                        (0x1fd2 < uVar9 || CARRY2(uVar6 + 0xe02d,uVar3)));
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar2 = *pbVar2 + (char)uVar7;
      goto code_r0x00013aab;
    }
    if (cVar36 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar33;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar13 >> 8);
LAB_1000_3b12:
  return *(uint *)((int)puVar23 + 0xe);
}


