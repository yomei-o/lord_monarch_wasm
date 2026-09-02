/* 1000:38de */

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

uint FUN_1000_38de(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte bVar10;
  undefined2 uVar9;
  uint in_CX;
  byte bVar11;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar12;
  uint in_BX;
  undefined1 *puVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  uint *puVar16;
  uint *puVar17;
  undefined1 *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *in_ESP;
  uint *puVar27;
  undefined2 uVar28;
  uint unaff_BP;
  uint *unaff_SI;
  uint *puVar29;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar30;
  byte in_AF;
  undefined1 uVar31;
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
  
code_r0x000138de:
  uVar9 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar16 = (uint *)((undefined1 *)in_ESP + -2);
  *(undefined2 *)((undefined1 *)in_ESP + -2) = 0x38e1;
  FUN_1000_7494();
  *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)in_CX;
  LOCK();
  uVar31 = *(undefined1 *)(unaff_BP + 0x72);
  *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
  uVar8 = CONCAT11(uVar31,(char)extraout_DX);
  UNLOCK();
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar30 = CARRY1((byte)in_BX,*(byte *)(unaff_BP + (int)unaff_SI));
  in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)(unaff_BP + (int)unaff_SI));
code_r0x000138eb:
  *(undefined2 *)((int)puVar16 + -2) = unaff_SS;
  if (!bVar30) {
    puVar27 = unaff_DI;
    unaff_DI = (uint *)((int)unaff_DI + 1);
    *(byte *)puVar27 = 0x30;
    uVar7 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
    *(uint *)((int)puVar16 + -2) = in_BX;
    *(uint *)((int)puVar16 + -4) = uVar7;
    in_BX = unaff_SI[0x15];
    uVar8 = (uVar8 | 0x3000) - *(int *)(byte *)(in_BX + (int)unaff_SI);
    bVar10 = (byte)(uVar7 >> 8);
    bVar6 = (char)uVar7 + 8;
    if (bVar6 != *(byte *)(in_BX + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(undefined2 *)((int)puVar16 + -6) = CONCAT11(bVar10,bVar6);
    *(uint *)((int)puVar16 + -8) = in_CX;
    *(uint *)((int)puVar16 + -10) = uVar8;
    *(uint *)((int)puVar16 + -0xc) = in_BX;
    *(undefined1 **)(undefined1 *)((int)puVar16 + -0xe) = (undefined1 *)((int)puVar16 + -4);
    *(uint *)((int)puVar16 + -0x10) = unaff_BP;
    *(undefined2 *)((int)puVar16 + -0x12) = unaff_SI;
    *(undefined2 *)((int)puVar16 + -0x14) = unaff_DI;
    uVar7 = *unaff_DI;
    cVar33 = (char)(in_CX >> 8);
    bVar11 = cVar33 + bVar6;
    in_CX = CONCAT11(bVar11,(char)in_CX);
    unaff_BP = 0x874;
    if (SCARRY1(cVar33,bVar6)) {
      puVar22 = (uint *)*(undefined2 *)((int)puVar16 + -0x14);
      unaff_SI = *(uint **)(byte *)((int)unaff_DI + (in_BX - 0x18));
      puVar27 = unaff_SI + 0x43a;
      uVar3 = *puVar27;
      *puVar27 = *puVar27 + 0x809;
      in_CX = 0x4379;
      unaff_SI[0x43a] =
           unaff_SI[0x43a] + CONCAT11(bVar10 | (byte)uVar7,bVar6 | bVar11) + (uint)(0xf7f6 < uVar3);
    }
    else {
      *(undefined2 *)((int)puVar16 + -0x16) = 0x874;
      puVar22 = (uint *)((int)puVar16 + -0x18);
      *(undefined2 *)((int)puVar16 + -0x18) = 0x874;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar8;
    puVar29 = (uint *)((int)unaff_SI + 1);
    out((byte)*unaff_SI,uVar8);
    uVar7 = CONCAT11((byte)(in_BX >> 8) & *(byte *)((int)puVar29 + unaff_BP + 0x11),(char)in_BX);
    bVar10 = (byte)uVar8;
    cVar36 = SBORROW1(bVar10,(byte)unaff_SI[0x39]);
    bVar6 = (byte)unaff_SI[0x39];
    cVar33 = (char)(bVar10 - bVar6) < '\0';
    bVar30 = bVar10 == bVar6;
    puVar17 = (uint *)((int)puVar22 + -2);
    *(undefined2 *)((int)puVar22 + -2) = 0x396b;
    bVar6 = func_0x0001b3ed();
    iVar12 = extraout_DX_00;
    if (!bVar30) {
      *(byte *)(unaff_SI + 6) = bVar6;
      *(undefined2 *)((int)puVar17 + -2) = 0x3973;
      puVar17 = (uint *)((int)puVar17 + -2);
      bVar6 = func_0x0001b617();
      iVar12 = extraout_DX_01;
    }
    if (cVar36 != cVar33) {
      iVar12 = iVar12 + 1;
      puVar17[-1] = (uint)unaff_DI;
      puVar17[-2] = iVar12;
      puVar17[-3] = CONCAT11((char)(in_CX >> 8),8);
      puVar17[-4] = uVar7;
      if (iVar12 == 0) {
LAB_1000_39c7:
        pcVar5 = (code *)swi(1);
        uVar8 = (*pcVar5)();
        return uVar8;
      }
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
      *pbVar1 = *pbVar1 | (byte)((uint)iVar12 >> 8);
code_r0x00013985:
      pbVar1 = (byte *)((int)unaff_DI + uVar7 + 0x12);
      *(byte **)pbVar1 = (byte *)((int)unaff_DI + *(int *)pbVar1 + 2);
      puVar18 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar18 + -2) = 0x399f;
      func_0x00018e51();
      pcVar5 = (code *)swi(3);
      uVar8 = (*pcVar5)();
      return uVar8;
    }
    bVar6 = bVar6 ^ *(byte *)(unaff_BP + (int)puVar29);
    in_AF = 9 < (bVar6 & 0xf) | in_AF;
    bVar6 = bVar6 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar17;
    pbVar1 = (byte *)((int)puVar29 + unaff_BP + 0x8b5f);
    bVar30 = bVar6 < *pbVar1 || bVar6 == *pbVar1;
    puVar27 = (uint *)CONCAT22(uVar9,puVar17);
    *puVar17 = 0x39ba;
    uVar37 = FUN_1000_a1b8();
    uVar8 = (uint)uVar37;
    if (bVar30) {
      if (in_CX == 1) {
        do {
          iVar12 = 0x40;
          uVar7 = uVar8;
          do {
            uVar8 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar22 = puVar29;
            if (((*puVar29 & 0x80) == 0) && ((puVar29[5] & 0x20) != 0)) {
              puVar27 = puVar27 + -2;
              *puVar27 = unaff_DS;
              bVar6 = (byte)uVar7 | 0x17;
              bVar10 = (byte)(uVar7 >> 8);
              if (bVar10 == (byte)puVar29[6]) {
                uVar7 = CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
                puVar22 = unaff_DI;
                goto code_r0x00013a16;
              }
              uVar8 = CONCAT11(bVar10 & *(byte *)(unaff_BP + (int)puVar29),(byte)uVar7) | 0x17;
              *(byte *)(puVar29 + 0x3931) = (byte)puVar29[0x3931] ^ (byte)((uint)iVar12 >> 8);
              *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
              uVar7 = *(uint *)puVar27;
              puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
              puVar22 = puVar29 + 8;
              unaff_DI = puVar29;
            }
            iVar12 = iVar12 + -1;
            puVar29 = puVar22;
          } while (iVar12 != 0);
          puVar29 = (uint *)*(uint *)puVar27;
          puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
          puVar22 = unaff_DI;
code_r0x00013a16:
          puVar19 = (uint *)puVar27;
          uVar9 = (undefined2)((ulong)puVar27 >> 0x10);
          if (0x1ef < uVar8) goto code_r0x00013a1c;
          pbVar1 = (byte *)((int)puVar22 + unaff_BP + 0x59);
          *pbVar1 = *pbVar1 | (byte)uVar8;
          bVar6 = *(byte *)(uVar8 + puVar19[1]);
          puVar19[1] = (uint)puVar29;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar8 + ((byte)((char)unaff_BP + 1U) < bVar6);
          uVar8 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
          unaff_DI = (uint *)puVar19[1];
          puVar27 = (uint *)CONCAT22(uVar9,puVar19 + 2);
          puVar29 = (uint *)0xc800;
          unaff_BP = uVar7;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)uVar37 >> 0x10),(char)uVar37);
    puVar2 = puVar29;
    bVar30 = CARRY2(*puVar2,uVar8);
    *puVar2 = *puVar2 + uVar8;
    bVar34 = (int)*puVar2 < 0;
    bVar32 = *puVar2 == 0;
    bVar6 = POPCOUNT(*puVar2 & 0xff);
    in_CX = in_CX - 1;
    if (in_CX == 0 || bVar32) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  in_BX = in_BX + 1;
  in_ESP = (undefined1 *)CONCAT22(uVar9,(undefined1 *)((int)puVar16 + -4));
  *(undefined2 *)((int)puVar16 + -4) = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar8;
  goto code_r0x000138de;
LAB_1000_381b:
  bVar6 = (byte)uVar7;
  bVar35 = SBORROW1(bVar6,'\x10');
  bVar34 = (char)(bVar6 - 0x10) < '\0';
  bVar32 = bVar6 == 0x10;
  bVar30 = true;
  if (0xf < bVar6) {
    cVar33 = '\x04';
    if (7 < bVar6) {
      bVar35 = SBORROW1(bVar6,'\f');
      bVar34 = (char)(bVar6 - 0xc) < '\0';
      bVar32 = bVar6 == 0xc;
      bVar30 = true;
      if (bVar6 < 0xc) goto LAB_1000_383e;
    }
    cVar33 = '\b';
    if (bVar6 != 0) {
      bVar35 = SBORROW1(bVar6,'\x05');
      bVar34 = (char)(bVar6 - 5) < '\0';
      bVar32 = bVar6 == 5;
      bVar30 = true;
      if (bVar6 < 5) goto LAB_1000_383e;
    }
    cVar33 = '\v';
    bVar30 = bVar6 < 5;
    bVar35 = SBORROW1(bVar6,'\x05');
    bVar34 = (char)(bVar6 - 5) < '\0';
    bVar32 = bVar6 == 5;
    if (!bVar32) {
      in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar1 = (byte *)(in_BX + (int)unaff_SI);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 == 0) goto code_r0x000138de;
      in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
      uVar9 = (undefined2)((ulong)in_ESP >> 0x10);
      pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x854);
      *pbVar1 = *pbVar1 & 0xb;
      uVar31 = *pbVar1 == 0;
      puVar15 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar16 = (uint *)(puVar15 + -2);
      *(undefined2 *)(puVar15 + -2) = 0x387a;
      uVar37 = func_0x0001b476();
      uVar8 = (uint)((ulong)uVar37 >> 0x10);
      if (!(bool)uVar31) {
        *(byte *)((int)unaff_SI + 0xb) = (byte)uVar37;
      }
      uVar7 = CONCAT11((char)((ulong)uVar37 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
      bVar6 = (byte)uVar7;
      *(byte *)(unaff_SI + 5) = bVar6;
      swi(4);
      pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
      *pbVar1 = *pbVar1 + bVar6;
      if ((POPCOUNT(*pbVar1) & 1U) != 0) {
        pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x33);
        bVar6 = *pbVar1;
        bVar11 = (byte)((ulong)uVar37 >> 0x10);
        bVar10 = *pbVar1;
        cVar33 = (char)((ulong)uVar37 >> 0x18) + *(byte *)(in_BX + (int)unaff_SI);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar33;
        pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar33,bVar11 + bVar10),
                                            (uVar7 + 0x5556) - (uint)CARRY1(bVar11,bVar6)) %
                                  (ulong)unaff_SI[0x410]);
        *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
             *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
        return *puVar16;
      }
      puVar22 = puVar16;
      if (*pbVar1 != 0) goto code_r0x000138e6;
      goto LAB_1000_3958;
    }
  }
LAB_1000_383e:
  if (bVar30) {
    *(undefined2 *)((undefined1 *)in_ESP + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar32 && bVar35 == bVar34) {
    return *(uint *)(unaff_BP + 0xe);
  }
LAB_1000_37ea_2:
  puVar13 = (undefined1 *)in_ESP;
  if (cVar33 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
    puVar14 = (undefined2 *)(puVar13 + -2);
    puVar13 = puVar13 + -2;
    *puVar14 = 0x37f3;
    func_0x0001b6c0();
  }
  return *(uint *)(puVar13 + 0xe);
code_r0x00013a1c:
  unaff_SS = *puVar19;
  *(longdouble *)(uVar8 + (int)puVar22) = in_ST0;
  puVar27 = (uint *)CONCAT22(uVar9,(uint *)(puVar19[1] + -2));
  *(undefined2 *)(puVar19[1] + -2) = unaff_ES;
  uVar7 = puVar22[2];
  uVar8 = (uint)*(byte *)((int)puVar22 + -0x79);
  bVar30 = (byte)iVar12 < *(byte *)(unaff_BP + (int)puVar29);
  cVar33 = (byte)iVar12 - *(byte *)(unaff_BP + (int)puVar29);
  in_CX = CONCAT11((char)((uint)iVar12 >> 8),cVar33);
  bVar34 = cVar33 < '\0';
  bVar32 = cVar33 == '\0';
  bVar6 = POPCOUNT(cVar33);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar22;
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
    *(byte *)(uVar7 + (int)puVar29) = *(byte *)(uVar7 + (int)puVar29) + 1;
    puVar20 = (uint *)puVar27;
    puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),puVar20 + -1);
    puVar20[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar34 << 7 | bVar32 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar30,(char)uVar8)) {
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar1 = *pbVar1 | (byte)(uVar7 >> 8);
      puVar2 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar2 = (char)uVar8 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar1 = (byte *)((uVar7 >> 2) + (int)puVar29);
    *pbVar1 = *pbVar1 - 0x15;
    puVar2 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar8 = *puVar2;
    *puVar2 = *puVar2 - in_CX;
    bVar6 = ((char)(uVar7 >> 1) + (char)(uVar7 >> 2) + -0x10) - (uVar8 < in_CX) | 2;
    iVar12 = *(int *)(byte *)((int)unaff_DI + 0x55);
    unaff_SI = puVar29;
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar6;
    ((uint *)puVar27)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)in_CX;
    puVar22 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar12 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar8 = (*pcVar5)();
      return uVar8;
    }
    uVar8 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar8 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar5 = (code *)swi(0x20);
    (*pcVar5)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar7 >> 8);
    puVar21 = (uint *)puVar27;
    uVar28 = (undefined2)((ulong)puVar27 >> 0x10);
    puVar21[-1] = unaff_ES;
    pbVar1 = (byte *)((int)puVar29 + uVar7 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
    unaff_DI = (uint *)puVar21[-1];
    unaff_SI = (uint *)*puVar21;
    unaff_BP = puVar21[1];
    in_CX = puVar21[5];
    uVar9 = puVar21[6];
    uVar8 = CONCAT11((char)(puVar21[3] >> 8),(byte)puVar21[3] | *(byte *)0x5d02) |
            *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar21[6] = (uint)unaff_DI;
    pbVar1 = (byte *)((int)unaff_SI + uVar8 + 0x2c2);
    cVar36 = SCARRY1((char)uVar9,*pbVar1);
    bVar30 = (char)((char)uVar9 + *pbVar1) < '\0';
    puVar22 = puVar21 + 5;
    puVar21[5] = 0x3a83;
    uVar37 = func_0x00013e95();
    bVar6 = (byte)uVar37;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar8;
    cVar33 = (char)((ulong)uVar37 >> 0x18);
    if (bVar30) {
      bVar11 = (byte)(uVar8 >> 8);
      puVar27 = (uint *)((int)unaff_DI + -0x53);
      uVar4 = (uint)(bVar11 < (byte)(in_CX >> 8));
      uVar7 = *puVar27;
      uVar3 = *puVar27;
      *puVar27 = uVar3 + 0xe02d + uVar4;
      bVar10 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar11 = bVar11 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar37 >> 8);
      in_BX = CONCAT11(bVar11,(char)uVar8);
      if ((char)bVar11 < '\0') {
        bVar30 = unaff_SI[3] < 1000;
        if (!bVar30) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar22 + -2) = 0x3b26;
          puVar22 = (uint *)((int)puVar22 + -2);
          uVar9 = func_0x00013966();
          if (!bVar30) goto LAB_1000_3b55_1;
        }
        in_ESP = (undefined1 *)CONCAT22(uVar28,(undefined1 *)((int)puVar22 + -2));
        *(undefined2 *)((int)puVar22 + -2) = 0x3b2d;
        uVar37 = FUN_1000_8cb7();
        uVar8 = (uint)((ulong)uVar37 >> 0x10);
        uVar7 = (uint)uVar37;
        bVar30 = (byte)uVar37 < 0x5a;
        puVar23 = (undefined1 *)in_ESP;
        if (bVar30) {
          bVar30 = true;
          if ((byte)uVar37 < 0x50) {
            do {
              if (bVar30) {
                puVar26 = (undefined1 *)in_ESP;
                in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar26 + -2);
                *(undefined2 *)(puVar26 + -2) = 0x3b67;
                uVar7 = func_0x000137e6();
                cVar33 = (char)in_CX;
                if (bVar30) goto LAB_1000_381b;
              }
              if (*(int *)0x3480 != 0) goto code_r0x00013b57;
              puVar25 = (undefined1 *)in_ESP;
              *(uint *)(puVar25 + -2) = unaff_BP;
              in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar25 + -4);
              *(uint *)(puVar25 + -4) = unaff_BP;
              pbVar1 = (byte *)(in_BX + (int)unaff_SI);
              bVar6 = (byte)(uVar7 >> 8);
              bVar30 = CARRY1(*pbVar1,bVar6);
              *pbVar1 = *pbVar1 + bVar6;
              in_BX = in_BX - 1;
            } while( true );
          }
          uVar9 = (undefined2)((ulong)in_ESP >> 0x10);
          puVar16 = (uint *)(puVar23 + -2);
          *(undefined2 *)(puVar23 + -2) = 0x3b38;
          bVar30 = false;
          goto code_r0x000138eb;
        }
        puVar24 = puVar23 + -2;
        *(undefined2 *)(puVar23 + -2) = 0x3b42;
        uVar9 = FUN_1000_3607();
        cVar33 = (char)in_CX;
        if (bVar30) {
          in_ESP = (undefined1 *)ZEXT24(puVar24 + -2);
          *(undefined2 *)(puVar24 + -2) = 0x3b47;
          goto LAB_1000_37ea_2;
        }
LAB_1000_3b55_1:
        uVar7 = CONCAT11((char)((uint)uVar9 >> 8),(char)uVar9 + -0x80) | 1;
code_r0x00013b57:
        *(byte *)unaff_SI = (byte)*unaff_SI | 1;
        return uVar7;
      }
      puVar27 = (uint *)ZEXT24((undefined1 *)((int)puVar22 + -2));
      *(undefined2 *)((int)puVar22 + -2) = unaff_CS;
      iVar12 = CONCAT11(cVar33 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar37 >> 0x10) + bVar10 +
                        (0x1fd2 < uVar7 || CARRY2(uVar3 + 0xe02d,uVar4)));
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar1 = *pbVar1 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar36 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar33;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar8 >> 8);
LAB_1000_3b12:
  return *(uint *)((int)puVar22 + 0xe);
}


