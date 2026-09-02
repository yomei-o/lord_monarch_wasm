/* 1000:38cb */

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

uint FUN_1000_38cb(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  undefined2 in_AX;
  uint uVar9;
  undefined2 uVar10;
  uint in_CX;
  int in_DX;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar11;
  uint in_BX;
  uint uVar12;
  byte bVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  uint *puVar16;
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
  undefined1 in_CF;
  bool bVar30;
  byte in_AF;
  undefined1 uVar31;
  undefined1 in_ZF;
  bool bVar32;
  char in_SF;
  bool bVar33;
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
  ulong uVar36;
  undefined4 uVar37;
  
  do {
    bVar8 = *(byte *)0x5108;
    uVar31 = (undefined1)((uint)in_AX >> 8);
    in_AX = CONCAT11(uVar31,bVar8);
    cVar7 = (char)(in_BX >> 8);
    puVar16 = (uint *)in_ESP;
    uVar28 = (undefined2)((ulong)in_ESP >> 0x10);
    if (!(bool)in_CF) {
      if ((bool)in_ZF || in_OF != in_SF) {
        in_CX = CONCAT11((char)(in_CX >> 8),(char)in_CX + *(byte *)(in_BX + (int)unaff_SI));
        in_DX = in_DX + 1;
        puVar16[-1] = in_AX;
        puVar16[-2] = in_CX;
        puVar16[-3] = in_DX;
        puVar16[-4] = in_BX;
        puVar16[-5] = (uint)puVar16;
        puVar16[-6] = unaff_BP;
        puVar16[-7] = (uint)unaff_SI;
        puVar17 = puVar16 + -8;
        puVar16[-8] = (uint)unaff_DI;
        in_BX = CONCAT11(cVar7 + bVar8,(char)in_BX);
        goto code_r0x000138d9;
      }
      in_BX = in_BX + 1;
      break;
    }
    bVar8 = bVar8 | (byte)unaff_SI[3];
    if (0x13 < CONCAT11(uVar31,bVar8)) {
      puVar18 = puVar16 + -1;
      puVar16[-1] = 0x38f3;
      uVar36 = func_0x0001f137();
      pbVar1 = (byte *)((int)unaff_SI + unaff_BP + 0x8aa);
      *pbVar1 = *pbVar1 ^ (byte)(in_CX >> 8);
      *(byte *)(unaff_SI + 5) = 3;
      goto code_r0x000138fb;
    }
    bVar6 = bVar8 - 0x12;
    in_BX = CONCAT11(cVar7 + (byte)unaff_SI[-0x2af1],(char)in_BX);
    puVar27 = unaff_DI;
    unaff_DI = (uint *)((int)unaff_DI + 1);
    *(byte *)puVar27 = bVar6;
    in_CF = 0xc4 < bVar6;
    in_OF = SCARRY1(bVar6,';');
    cVar7 = bVar8 + 0x29;
    in_AX = CONCAT11(uVar31,cVar7);
    in_SF = cVar7 < '\0';
    in_ZF = true;
  } while (cVar7 == '\0');
LAB_1000_3948:
  uVar12 = in_CX >> 8;
  unaff_SI = *(uint **)(byte *)((int)unaff_DI + (in_BX - 0x18));
  puVar27 = (uint *)(unaff_BP + (int)unaff_SI);
  uVar9 = *puVar27;
  *puVar27 = *puVar27 + 0x809;
  in_CX = 0x4379;
  *(uint *)(byte *)(unaff_BP + (int)unaff_SI) =
       *(int *)(byte *)(unaff_BP + (int)unaff_SI) +
       CONCAT11((char)((uint)in_AX >> 8),(byte)in_AX | (byte)uVar12) + (uint)(0xf7f6 < uVar9);
LAB_1000_3958:
  *(int *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + in_DX;
  puVar23 = (uint *)((int)unaff_SI + 1);
  out((byte)*unaff_SI,in_DX);
  uVar9 = CONCAT11((byte)(in_BX >> 8) & *(byte *)((int)puVar23 + unaff_BP + 0x11),(char)in_BX);
  bVar6 = (byte)in_DX;
  cVar35 = SBORROW1(bVar6,(byte)unaff_SI[0x39]);
  bVar8 = (byte)unaff_SI[0x39];
  cVar7 = (char)(bVar6 - bVar8) < '\0';
  bVar30 = bVar6 == bVar8;
  uVar28 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar29 = (uint *)in_ESP + -1;
  ((uint *)in_ESP)[-1] = 0x396b;
  bVar8 = func_0x0001b3ed();
  iVar11 = extraout_DX_00;
  if (!bVar30) {
    *(byte *)(unaff_SI + 6) = bVar8;
    *(undefined2 *)((int)puVar29 + -2) = 0x3973;
    puVar29 = (uint *)((int)puVar29 + -2);
    bVar8 = func_0x0001b617();
    iVar11 = extraout_DX_01;
  }
  if (cVar35 != cVar7) {
    iVar11 = iVar11 + 1;
    puVar29[-1] = (uint)unaff_DI;
    puVar29[-2] = iVar11;
    puVar29[-3] = CONCAT11((char)(in_CX >> 8),8);
    puVar29[-4] = uVar9;
    if (iVar11 == 0) {
LAB_1000_39c7:
      pcVar5 = (code *)swi(1);
      uVar9 = (*pcVar5)();
      return uVar9;
    }
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
    *pbVar1 = *pbVar1 | (byte)((uint)iVar11 >> 8);
code_r0x00013985:
    pbVar1 = (byte *)((int)unaff_DI + uVar9 + 0x12);
    *(byte **)pbVar1 = (byte *)((int)unaff_DI + *(int *)pbVar1 + 2);
    puVar19 = (undefined1 *)0x2e1c;
    *(undefined2 *)0x2e1c = 0x3990;
    FUN_1000_8d53();
    *(undefined2 *)(puVar19 + -2) = 0x399f;
    func_0x00018e51();
    pcVar5 = (code *)swi(3);
    uVar9 = (*pcVar5)();
    return uVar9;
  }
  bVar8 = bVar8 ^ *(byte *)(unaff_BP + (int)puVar23);
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = bVar8 + in_AF * '\x06' & 0xf;
  unaff_DS = *puVar29;
  pbVar1 = (byte *)((int)puVar23 + unaff_BP + 0x8b5f);
  bVar30 = bVar8 < *pbVar1 || bVar8 == *pbVar1;
  puVar27 = (uint *)CONCAT22(uVar28,puVar29);
  *puVar29 = 0x39ba;
  uVar37 = FUN_1000_a1b8();
  uVar12 = (uint)uVar37;
  if (bVar30) {
    if (in_CX == 1) {
      do {
        iVar11 = 0x40;
        uVar9 = uVar12;
        do {
          uVar12 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
          puVar29 = puVar23;
          if (((*puVar23 & 0x80) == 0) && ((puVar23[5] & 0x20) != 0)) {
            puVar27 = puVar27 + -2;
            *puVar27 = unaff_DS;
            bVar8 = (byte)uVar9 | 0x17;
            bVar6 = (byte)(uVar9 >> 8);
            if (bVar6 == (byte)puVar23[6]) {
              uVar9 = CONCAT11(bVar8 / 0x5e,bVar8 % 0x5e);
              puVar29 = unaff_DI;
              goto code_r0x00013a16;
            }
            uVar12 = CONCAT11(bVar6 & *(byte *)(unaff_BP + (int)puVar23),(byte)uVar9) | 0x17;
            *(byte *)(puVar23 + 0x3931) = (byte)puVar23[0x3931] ^ (byte)((uint)iVar11 >> 8);
            *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
            in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
            uVar9 = *(uint *)puVar27;
            puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
            puVar29 = puVar23 + 8;
            unaff_DI = puVar23;
          }
          iVar11 = iVar11 + -1;
          puVar23 = puVar29;
        } while (iVar11 != 0);
        puVar23 = (uint *)*(uint *)puVar27;
        puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
        puVar29 = unaff_DI;
code_r0x00013a16:
        puVar20 = (uint *)puVar27;
        uVar28 = (undefined2)((ulong)puVar27 >> 0x10);
        if (0x1ef < uVar12) goto code_r0x00013a1c;
        pbVar1 = (byte *)((int)puVar29 + unaff_BP + 0x59);
        *pbVar1 = *pbVar1 | (byte)uVar12;
        bVar8 = *(byte *)(uVar12 + puVar20[1]);
        puVar20[1] = (uint)puVar23;
        *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar12 + ((byte)((char)unaff_BP + 1U) < bVar8);
        uVar12 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
        unaff_DI = (uint *)puVar20[1];
        puVar27 = (uint *)CONCAT22(uVar28,puVar20 + 2);
        puVar23 = (uint *)0xc800;
        unaff_BP = uVar9;
      } while( true );
    }
    goto code_r0x00013985;
  }
  out((int)((ulong)uVar37 >> 0x10),(char)uVar37);
  puVar2 = puVar23;
  bVar30 = CARRY2(*puVar2,uVar12);
  *puVar2 = *puVar2 + uVar12;
  bVar33 = (int)*puVar2 < 0;
  bVar32 = *puVar2 == 0;
  bVar8 = POPCOUNT(*puVar2 & 0xff);
  in_CX = in_CX - 1;
  if (in_CX == 0 || bVar32) goto LAB_1000_39c7;
  goto LAB_1000_3a35;
LAB_1000_381b:
  bVar8 = (byte)uVar9;
  bVar30 = bVar8 < 0x10;
  bVar34 = SBORROW1(bVar8,'\x10');
  bVar33 = (char)(bVar8 - 0x10) < '\0';
  bVar32 = bVar8 == 0x10;
  if (!bVar30) {
    cVar7 = '\x04';
    if (7 < bVar8) {
      bVar34 = SBORROW1(bVar8,'\f');
      bVar33 = (char)(bVar8 - 0xc) < '\0';
      bVar32 = bVar8 == 0xc;
      bVar30 = true;
      if (bVar8 < 0xc) goto LAB_1000_383e;
    }
    cVar7 = '\b';
    if (bVar8 != 0) {
      bVar34 = SBORROW1(bVar8,'\x05');
      bVar33 = (char)(bVar8 - 5) < '\0';
      bVar32 = bVar8 == 5;
      bVar30 = true;
      if (bVar8 < 5) goto LAB_1000_383e;
    }
    cVar7 = '\v';
    bVar30 = bVar8 < 5;
    bVar34 = SBORROW1(bVar8,'\x05');
    bVar33 = (char)(bVar8 - 5) < '\0';
    bVar32 = bVar8 == 5;
    if (!bVar32) {
      in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar1 = (byte *)(in_BX + (int)unaff_SI);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar8 ^ 0xf8) & 0xf) | in_AF;
      pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x854);
      *pbVar1 = *pbVar1 & 0xb;
      uVar31 = *pbVar1 == 0;
      puVar15 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      in_ESP = (uint *)CONCAT22(uVar28,puVar15 + -2);
      *(undefined2 *)(puVar15 + -2) = 0x387a;
      uVar37 = func_0x0001b476();
      in_DX = (int)((ulong)uVar37 >> 0x10);
      if (!(bool)uVar31) {
        *(byte *)((int)unaff_SI + 0xb) = (byte)uVar37;
      }
      uVar9 = CONCAT11((char)((ulong)uVar37 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
      bVar8 = (byte)uVar9;
      *(byte *)(unaff_SI + 5) = bVar8;
      swi(4);
      pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
      *pbVar1 = *pbVar1 + bVar8;
      if ((POPCOUNT(*pbVar1) & 1U) != 0) {
        pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x33);
        bVar8 = *pbVar1;
        bVar13 = (byte)((ulong)uVar37 >> 0x10);
        bVar6 = *pbVar1;
        cVar7 = (char)((ulong)uVar37 >> 0x18) + *(byte *)(in_BX + (int)unaff_SI);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar7;
        pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar7,bVar13 + bVar6),
                                            (uVar9 + 0x5556) - (uint)CARRY1(bVar13,bVar8)) %
                                  (ulong)unaff_SI[0x410]);
        *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
             *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
        return *(uint *)in_ESP;
      }
      if (*pbVar1 != 0) goto code_r0x000138e6;
      goto LAB_1000_3958;
    }
  }
LAB_1000_383e:
  if (bVar30) {
    *(undefined2 *)(puVar26 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar32 && bVar34 == bVar33) {
    return *(uint *)(unaff_BP + 0xe);
  }
  goto LAB_1000_37ea_2;
code_r0x00013a1c:
  unaff_SS = *puVar20;
  *(longdouble *)(uVar12 + (int)puVar29) = in_ST0;
  puVar27 = (uint *)CONCAT22(uVar28,(uint *)(puVar20[1] + -2));
  *(undefined2 *)(puVar20[1] + -2) = unaff_ES;
  uVar9 = puVar29[2];
  uVar12 = (uint)*(byte *)((int)puVar29 + -0x79);
  bVar30 = (byte)iVar11 < *(byte *)(unaff_BP + (int)puVar23);
  cVar7 = (byte)iVar11 - *(byte *)(unaff_BP + (int)puVar23);
  in_CX = CONCAT11((char)((uint)iVar11 >> 8),cVar7);
  bVar33 = cVar7 < '\0';
  bVar32 = cVar7 == '\0';
  bVar8 = POPCOUNT(cVar7);
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
    if (0xbbc4 < CONCAT11(bVar33 << 7 | bVar32 << 6 | in_AF << 4 | ((bVar8 & 1) == 0) << 2 | 2 |
                          bVar30,(char)uVar12)) {
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar1 = *pbVar1 | (byte)(uVar9 >> 8);
      puVar2 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar2 = (char)uVar12 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar1 = (byte *)((uVar9 >> 2) + (int)puVar23);
    *pbVar1 = *pbVar1 - 0x15;
    puVar2 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar12 = *puVar2;
    *puVar2 = *puVar2 - in_CX;
    bVar8 = ((char)(uVar9 >> 1) + (char)(uVar9 >> 2) + -0x10) - (uVar12 < in_CX) | 2;
    iVar11 = *(int *)(byte *)((int)unaff_DI + 0x55);
    unaff_SI = puVar23;
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar8;
    ((uint *)puVar27)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)in_CX;
    puVar23 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar11 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar8;
      pcVar5 = (code *)swi(1);
      uVar9 = (*pcVar5)();
      return uVar9;
    }
    uVar9 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar9 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar5 = (code *)swi(0x20);
    (*pcVar5)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar9 >> 8);
    puVar22 = (uint *)puVar27;
    uVar28 = (undefined2)((ulong)puVar27 >> 0x10);
    puVar22[-1] = unaff_ES;
    pbVar1 = (byte *)((int)puVar23 + uVar9 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
    unaff_DI = (uint *)puVar22[-1];
    unaff_SI = (uint *)*puVar22;
    unaff_BP = puVar22[1];
    in_CX = puVar22[5];
    uVar10 = puVar22[6];
    uVar9 = CONCAT11((char)(puVar22[3] >> 8),(byte)puVar22[3] | *(byte *)0x5d02) |
            *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar22[6] = (uint)unaff_DI;
    pbVar1 = (byte *)((int)unaff_SI + uVar9 + 0x2c2);
    cVar35 = SCARRY1((char)uVar10,*pbVar1);
    bVar30 = (char)((char)uVar10 + *pbVar1) < '\0';
    puVar23 = puVar22 + 5;
    puVar22[5] = 0x3a83;
    uVar37 = func_0x00013e95();
    bVar8 = (byte)uVar37;
    out(0x6f,bVar8);
    *(undefined1 *)0x1108 = (char)uVar9;
    cVar7 = (char)((ulong)uVar37 >> 0x18);
    if (bVar30) {
      bVar13 = (byte)(uVar9 >> 8);
      puVar27 = (uint *)((int)unaff_DI + -0x53);
      uVar4 = (uint)(bVar13 < (byte)(in_CX >> 8));
      uVar12 = *puVar27;
      uVar3 = *puVar27;
      *puVar27 = uVar3 + 0xe02d + uVar4;
      bVar6 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar13 = bVar13 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar37 >> 8);
      in_BX = CONCAT11(bVar13,(char)uVar9);
      if ((char)bVar13 < '\0') {
        bVar30 = unaff_SI[3] < 1000;
        if (!bVar30) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar23 + -2) = 0x3b26;
          puVar23 = (uint *)((int)puVar23 + -2);
          uVar10 = func_0x00013966();
          if (!bVar30) goto LAB_1000_3b55_1;
        }
        puVar25 = (undefined1 *)((int)puVar23 + -2);
        *(undefined2 *)((int)puVar23 + -2) = 0x3b2d;
        uVar37 = FUN_1000_8cb7();
        in_DX = (int)((ulong)uVar37 >> 0x10);
        uVar9 = (uint)uVar37;
        bVar30 = (byte)uVar37 < 0x5a;
        if (bVar30) {
          bVar30 = true;
          if ((byte)uVar37 < 0x50) {
            do {
              puVar26 = puVar25;
              if (bVar30) {
                puVar26 = puVar25 + -2;
                *(undefined2 *)(puVar25 + -2) = 0x3b67;
                uVar9 = func_0x000137e6();
                cVar7 = (char)in_CX;
                if (bVar30) goto LAB_1000_381b;
              }
              if (*(int *)0x3480 != 0) goto code_r0x00013b57;
              *(uint *)(puVar26 + -2) = unaff_BP;
              puVar25 = puVar26 + -4;
              *(uint *)(puVar26 + -4) = unaff_BP;
              pbVar1 = (byte *)(in_BX + (int)unaff_SI);
              bVar8 = (byte)(uVar9 >> 8);
              bVar30 = CARRY1(*pbVar1,bVar8);
              *pbVar1 = *pbVar1 + bVar8;
              in_BX = in_BX - 1;
            } while( true );
          }
          in_ESP = (uint *)CONCAT22(uVar28,puVar25 + -2);
          *(undefined2 *)(puVar25 + -2) = 0x3b38;
          bVar30 = false;
          while( true ) {
            in_AX = 0x810;
            puVar18 = (uint *)in_ESP;
            uVar28 = (undefined2)((ulong)in_ESP >> 0x10);
            puVar17 = puVar18 + -1;
            puVar18[-1] = unaff_SS;
            if (!bVar30) break;
code_r0x000138d9:
            in_BX = in_BX + 1;
            puVar26 = (undefined1 *)((int)puVar17 + -2);
            *(undefined2 *)((int)puVar17 + -2) = in_AX;
            *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)in_DX;
FUN_1000_38de:
            in_ESP = (uint *)CONCAT22(uVar28,puVar26 + -2);
            *(undefined2 *)(puVar26 + -2) = 0x38e1;
            FUN_1000_7494();
            *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)in_CX;
            LOCK();
            uVar31 = *(undefined1 *)(unaff_BP + 0x72);
            *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
            in_DX = CONCAT11(uVar31,(char)extraout_DX);
            UNLOCK();
code_r0x000138e6:
            *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
            bVar30 = CARRY1((byte)in_BX,*(byte *)(unaff_BP + (int)unaff_SI));
            in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)(unaff_BP + (int)unaff_SI));
          }
          puVar27 = unaff_DI;
          unaff_DI = (uint *)((int)unaff_DI + 1);
          *(byte *)puVar27 = 0x30;
          uVar36 = CONCAT22(in_DX,CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30)) |
                   0x30000000;
code_r0x000138fb:
          uVar9 = (uint)uVar36 ^ 0x8a0;
          *(uint *)((int)puVar18 + -2) = in_BX;
          *(uint *)((int)puVar18 + -4) = uVar9;
          in_BX = unaff_SI[0x15];
          in_DX = (int)(uVar36 >> 0x10) - *(int *)(byte *)(in_BX + (int)unaff_SI);
          bVar8 = (byte)(uVar9 >> 8);
          cVar7 = (char)uVar9 + '\b';
          if (cVar7 != *(char *)(in_BX + 0xd27e)) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *(undefined2 *)((int)puVar18 + -6) = CONCAT11(bVar8,cVar7);
          *(uint *)((int)puVar18 + -8) = in_CX;
          *(int *)((int)puVar18 + -10) = in_DX;
          *(uint *)((int)puVar18 + -0xc) = in_BX;
          *(undefined1 **)(undefined1 *)((int)puVar18 + -0xe) = (undefined1 *)((int)puVar18 + -4);
          *(uint *)((int)puVar18 + -0x10) = unaff_BP;
          *(undefined2 *)((int)puVar18 + -0x12) = unaff_SI;
          *(undefined2 *)((int)puVar18 + -0x14) = unaff_DI;
          in_AX = CONCAT11(bVar8 | (byte)*unaff_DI,cVar7);
          cVar35 = (char)(in_CX >> 8);
          in_CX = CONCAT11(cVar35 + cVar7,(char)in_CX);
          unaff_BP = 0x874;
          if (!SCARRY1(cVar35,cVar7)) {
            *(undefined2 *)((int)puVar18 + -0x16) = 0x874;
            in_ESP = (uint *)CONCAT22(uVar28,(uint *)((int)puVar18 + -0x18));
            *(undefined2 *)((int)puVar18 + -0x18) = 0x874;
            goto LAB_1000_3958;
          }
          in_ESP = (uint *)CONCAT22(uVar28,(uint *)*(undefined2 *)((int)puVar18 + -0x14));
          goto LAB_1000_3948;
        }
        puVar24 = puVar25 + -2;
        *(undefined2 *)(puVar25 + -2) = 0x3b42;
        uVar10 = FUN_1000_3607();
        cVar7 = (char)in_CX;
        if (bVar30) {
          puVar26 = puVar24 + -2;
          *(undefined2 *)(puVar24 + -2) = 0x3b47;
LAB_1000_37ea_2:
          if (cVar7 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
            puVar14 = (undefined2 *)(puVar26 + -2);
            puVar26 = puVar26 + -2;
            *puVar14 = 0x37f3;
            func_0x0001b6c0();
          }
          return *(uint *)(puVar26 + 0xe);
        }
LAB_1000_3b55_1:
        uVar9 = CONCAT11((char)((uint)uVar10 >> 8),(char)uVar10 + -0x80) | 1;
code_r0x00013b57:
        *(byte *)unaff_SI = (byte)*unaff_SI | 1;
        return uVar9;
      }
      puVar27 = (uint *)ZEXT24((undefined1 *)((int)puVar23 + -2));
      *(undefined2 *)((int)puVar23 + -2) = unaff_CS;
      iVar11 = CONCAT11(cVar7 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar37 >> 0x10) + bVar6 +
                        (0x1fd2 < uVar12 || CARRY2(uVar3 + 0xe02d,uVar4)));
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar1 = *pbVar1 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar35 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar7;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar9 >> 8);
LAB_1000_3b12:
  return *(uint *)((int)puVar23 + 0xe);
}


