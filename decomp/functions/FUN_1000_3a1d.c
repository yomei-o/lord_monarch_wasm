/* 1000:3a1d */

/* WARNING: Instruction at (ram,0x00013ade) overlaps instruction at (ram,0x00013add)
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
/* WARNING: Removing unreachable block (ram,0x000139ea) */
/* WARNING: Removing unreachable block (ram,0x00013889) */
/* WARNING: Removing unreachable block (ram,0x00013ace) */
/* WARNING: Removing unreachable block (ram,0x00013ada) */
/* WARNING: Removing unreachable block (ram,0x00013ad5) */
/* WARNING: Removing unreachable block (ram,0x00013add) */
/* WARNING: Removing unreachable block (ram,0x00013a25) */
/* WARNING: Removing unreachable block (ram,0x00013ae4) */
/* WARNING: Removing unreachable block (ram,0x0001384c) */

uint FUN_1000_3a1d(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  byte bVar11;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  int in_CX;
  uint uVar12;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar13;
  uint in_BX;
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
  uint *puVar27;
  uint *in_ESP;
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
  bool bVar33;
  bool bVar34;
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
  
code_r0x00013a1d:
  *(longdouble *)(in_BX + (int)unaff_DI) = in_ST0;
  puVar27 = (uint *)CONCAT22((int)((ulong)in_ESP >> 0x10),(uint *)(*(uint *)in_ESP + -2));
  *(undefined2 *)(*(uint *)in_ESP + -2) = unaff_ES;
  uVar9 = unaff_DI[2];
  uVar7 = (uint)*(byte *)((int)unaff_DI + -0x79);
  bVar30 = (byte)in_CX < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar6 = (byte)in_CX - *(byte *)(unaff_BP + (int)unaff_SI);
  uVar12 = CONCAT11((char)((uint)in_CX >> 8),cVar6);
  bVar33 = cVar6 < '\0';
  bVar32 = cVar6 == '\0';
  bVar5 = POPCOUNT(cVar6);
  LOCK();
  puVar29 = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = unaff_DI;
  UNLOCK();
  unaff_DI = puVar29;
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar32) {
    *(byte *)(uVar9 + (int)unaff_SI) = *(byte *)(uVar9 + (int)unaff_SI) + 1;
    puVar21 = (uint *)puVar27;
    puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),puVar21 + -1);
    puVar21[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar33 << 7 | 0x40U | in_AF << 4 | ((bVar5 & 1) == 0) << 2 | 2 | bVar30,
                          (char)uVar7)) {
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar2 = *pbVar2 | (byte)(uVar9 >> 8);
      puVar1 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar1 = (char)uVar7 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + uVar12;
    pbVar2 = (byte *)((uVar9 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar1 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar7 = *puVar1;
    *puVar1 = *puVar1 - uVar12;
    bVar5 = ((char)(uVar9 >> 1) + (char)(uVar9 >> 2) + -0x10) - (uVar7 < uVar12) | 2;
    iVar13 = *(int *)(byte *)((int)unaff_DI + 0x55);
    puVar29 = unaff_SI;
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)puVar29) = *(byte *)(unaff_BP + (int)puVar29) & bVar5;
    ((uint *)puVar27)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)puVar29) = *(byte *)(unaff_BP + (int)puVar29) & (byte)uVar12;
    puVar23 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar13 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)puVar29) = *(byte *)(unaff_BP + (int)puVar29) | bVar5;
      pcVar4 = (code *)swi(1);
      uVar9 = (*pcVar4)();
      return uVar9;
    }
    uVar9 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*puVar29 & 0x80) != 0) || (*(byte *)((int)puVar29 + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)puVar29[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar9 == (byte)puVar29[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
LAB_1000_3b0f:
    *(byte *)(puVar29 + 5) = (byte)(uVar9 >> 8);
LAB_1000_3b12:
    return *(uint *)((int)puVar23 + 0xe);
  }
LAB_1000_3a63:
  pcVar4 = (code *)swi(0x20);
  (*pcVar4)();
  *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar9 >> 8);
  puVar22 = (uint *)puVar27;
  uVar28 = (undefined2)((ulong)puVar27 >> 0x10);
  puVar22[-1] = unaff_ES;
  pbVar2 = (byte *)((int)unaff_SI + uVar9 + 0x222);
  *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)unaff_DI);
  unaff_DI = (uint *)puVar22[-1];
  puVar29 = (uint *)*puVar22;
  unaff_BP = puVar22[1];
  uVar12 = puVar22[5];
  uVar8 = puVar22[6];
  uVar9 = CONCAT11((char)(puVar22[3] >> 8),(byte)puVar22[3] | *(byte *)0x5d02) |
          *(uint *)((int)unaff_DI + unaff_BP + 10);
  puVar22[6] = (uint)unaff_DI;
  pbVar2 = (byte *)((int)puVar29 + uVar9 + 0x2c2);
  cVar35 = SCARRY1((char)uVar8,*pbVar2);
  bVar30 = (char)((char)uVar8 + *pbVar2) < '\0';
  puVar23 = puVar22 + 5;
  puVar22[5] = 0x3a83;
  uVar36 = func_0x00013e95();
  bVar5 = (byte)uVar36;
  out(0x6f,bVar5);
  *(undefined1 *)0x1108 = (char)uVar9;
  cVar6 = (char)((ulong)uVar36 >> 0x18);
  if (!bVar30) {
    if ((bool)cVar35 == bVar30) {
      *(byte *)((int)puVar29 + 0xb) = *(byte *)((int)puVar29 + 0xb) + cVar6;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)puVar29[5] != 2) goto LAB_1000_3b12;
    goto LAB_1000_3b0f;
  }
  bVar14 = (byte)(uVar9 >> 8);
  puVar27 = (uint *)((int)unaff_DI + -0x53);
  uVar3 = (uint)(bVar14 < (byte)(uVar12 >> 8));
  uVar7 = *puVar27;
  uVar10 = *puVar27;
  *puVar27 = uVar10 + 0xe02d + uVar3;
  bVar11 = *(byte *)(unaff_BP + (int)unaff_DI);
  bVar14 = bVar14 + (byte)puVar29[0x1015] | (byte)((ulong)uVar36 >> 8);
  uVar9 = CONCAT11(bVar14,(char)uVar9);
  if (-1 < (char)bVar14) {
    puVar27 = (uint *)ZEXT24((undefined1 *)((int)puVar23 + -2));
    *(undefined2 *)((int)puVar23 + -2) = unaff_CS;
    iVar13 = CONCAT11(cVar6 - *(byte *)((int)puVar29 + uVar9 + 0x23c9),
                      (char)((ulong)uVar36 >> 0x10) + bVar11 +
                      (0x1fd2 < uVar7 || CARRY2(uVar10 + 0xe02d,uVar3)));
    pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
    *pbVar2 = *pbVar2 + (char)uVar12;
    goto code_r0x00013aab;
  }
  bVar30 = puVar29[3] < 1000;
  if (!bVar30) {
                    /* WARNING: Call to offcut address within same function */
    *(undefined2 *)((int)puVar23 + -2) = 0x3b26;
    puVar23 = (uint *)((int)puVar23 + -2);
    cVar6 = func_0x00013966();
    if (!bVar30) goto LAB_1000_3b55_1;
  }
  puVar25 = (undefined1 *)((int)puVar23 + -2);
  *(undefined2 *)((int)puVar23 + -2) = 0x3b2d;
  uVar36 = FUN_1000_8cb7();
  uVar7 = (uint)((ulong)uVar36 >> 0x10);
  uVar10 = (uint)uVar36;
  bVar30 = (byte)uVar36 < 0x5a;
  if (!bVar30) {
    puVar24 = puVar25 + -2;
    *(undefined2 *)(puVar25 + -2) = 0x3b42;
    cVar6 = FUN_1000_3607();
    cVar35 = (char)uVar12;
    if (!bVar30) {
LAB_1000_3b55_1:
      uVar10 = (byte)(cVar6 + 0x80) | 1;
code_r0x00013b57:
      *(byte *)puVar29 = (byte)*puVar29 | 1;
      return uVar10;
    }
    puVar26 = puVar24 + -2;
    *(undefined2 *)(puVar24 + -2) = 0x3b47;
    goto LAB_1000_37ea_2;
  }
  bVar30 = true;
  if ((byte)uVar36 < 0x50) {
    do {
      puVar26 = puVar25;
      if (bVar30) {
        puVar26 = puVar25 + -2;
        *(undefined2 *)(puVar25 + -2) = 0x3b67;
        uVar10 = func_0x000137e6();
        cVar35 = (char)uVar12;
        if (bVar30) goto LAB_1000_381b;
      }
      if (*(int *)0x3480 != 0) goto code_r0x00013b57;
      *(uint *)(puVar26 + -2) = unaff_BP;
      puVar25 = puVar26 + -4;
      *(uint *)(puVar26 + -4) = unaff_BP;
      pbVar2 = (byte *)(uVar9 + (int)puVar29);
      bVar5 = (byte)(uVar10 >> 8);
      bVar30 = CARRY1(*pbVar2,bVar5);
      *pbVar2 = *pbVar2 + bVar5;
      uVar9 = uVar9 - 1;
    } while( true );
  }
  puVar17 = (uint *)(puVar25 + -2);
  *(undefined2 *)(puVar25 + -2) = 0x3b38;
  bVar30 = false;
  while( true ) {
    *(undefined2 *)((int)puVar17 + -2) = unaff_SS;
    if (!bVar30) break;
    uVar9 = uVar9 + 1;
    puVar26 = (undefined1 *)((int)puVar17 + -4);
    *(undefined2 *)((int)puVar17 + -4) = 0x810;
    *(byte *)(puVar29 + 1) = (byte)puVar29[1] | (byte)uVar7;
FUN_1000_38de:
    puVar17 = (uint *)(puVar26 + -2);
    *(undefined2 *)(puVar26 + -2) = 0x38e1;
    FUN_1000_7494();
    *(byte *)(uVar9 + (int)puVar29) = *(byte *)(uVar9 + (int)puVar29) & (byte)uVar12;
    LOCK();
    uVar31 = *(undefined1 *)(unaff_BP + 0x72);
    *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
    uVar7 = CONCAT11(uVar31,(char)extraout_DX);
    UNLOCK();
code_r0x000138e6:
    *(uint *)((int)puVar29 + 0x31) = *(uint *)((int)puVar29 + 0x31) & (uint)puVar29;
    bVar30 = CARRY1((byte)uVar9,*(byte *)(unaff_BP + (int)puVar29));
    uVar9 = CONCAT11((char)(uVar9 >> 8),(byte)uVar9 + *(byte *)(unaff_BP + (int)puVar29));
  }
  puVar27 = unaff_DI;
  unaff_DI = (uint *)((int)unaff_DI + 1);
  *(byte *)puVar27 = 0x30;
  uVar10 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
  *(uint *)((int)puVar17 + -2) = uVar9;
  *(uint *)((int)puVar17 + -4) = uVar10;
  uVar9 = puVar29[0x15];
  uVar7 = (uVar7 | 0x3000) - *(int *)(byte *)(uVar9 + (int)puVar29);
  bVar11 = (byte)(uVar10 >> 8);
  bVar5 = (char)uVar10 + 8;
  if (bVar5 != *(byte *)(uVar9 + 0xd27e)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined2 *)((int)puVar17 + -6) = CONCAT11(bVar11,bVar5);
  *(uint *)((int)puVar17 + -8) = uVar12;
  *(uint *)((int)puVar17 + -10) = uVar7;
  *(uint *)((int)puVar17 + -0xc) = uVar9;
  *(undefined1 **)(undefined1 *)((int)puVar17 + -0xe) = (undefined1 *)((int)puVar17 + -4);
  *(uint *)((int)puVar17 + -0x10) = unaff_BP;
  *(undefined2 *)((int)puVar17 + -0x12) = puVar29;
  *(undefined2 *)((int)puVar17 + -0x14) = unaff_DI;
  uVar10 = *unaff_DI;
  cVar6 = (char)(uVar12 >> 8);
  bVar14 = cVar6 + bVar5;
  uVar12 = CONCAT11(bVar14,(char)uVar12);
  unaff_BP = 0x874;
  if (SCARRY1(cVar6,bVar5)) {
    puVar23 = (uint *)*(undefined2 *)((int)puVar17 + -0x14);
    puVar29 = *(uint **)(byte *)((int)unaff_DI + (uVar9 - 0x18));
    puVar27 = puVar29 + 0x43a;
    uVar3 = *puVar27;
    *puVar27 = *puVar27 + 0x809;
    uVar12 = 0x4379;
    puVar29[0x43a] =
         puVar29[0x43a] + CONCAT11(bVar11 | (byte)uVar10,bVar5 | bVar14) + (uint)(0xf7f6 < uVar3);
  }
  else {
    *(undefined2 *)((int)puVar17 + -0x16) = 0x874;
    puVar23 = (uint *)((int)puVar17 + -0x18);
    *(undefined2 *)((int)puVar17 + -0x18) = 0x874;
  }
  goto LAB_1000_3958;
code_r0x000139bc:
  if (uVar12 != 1) {
code_r0x00013985:
    pbVar2 = (byte *)((int)unaff_DI + uVar9 + 0x12);
    *(byte **)pbVar2 = (byte *)((int)unaff_DI + *(int *)pbVar2 + 2);
    puVar19 = (undefined1 *)0x2e1c;
    *(undefined2 *)0x2e1c = 0x3990;
    FUN_1000_8d53();
    *(undefined2 *)(puVar19 + -2) = 0x399f;
    func_0x00018e51();
    pcVar4 = (code *)swi(3);
    uVar9 = (*pcVar4)();
    return uVar9;
  }
  do {
    in_CX = 0x40;
    uVar9 = uVar7;
    do {
      in_BX = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
      puVar29 = unaff_SI;
      if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
        puVar27 = puVar27 + -2;
        *puVar27 = unaff_DS;
        bVar5 = (byte)uVar9 | 0x17;
        bVar11 = (byte)(uVar9 >> 8);
        if (bVar11 == (byte)unaff_SI[6]) {
          uVar9 = CONCAT11(bVar5 / 0x5e,bVar5 % 0x5e);
          goto code_r0x00013a16;
        }
        in_BX = CONCAT11(bVar11 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)uVar9) | 0x17;
        *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)in_CX >> 8);
        *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
        in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
        uVar9 = *(uint *)puVar27;
        puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
        puVar29 = unaff_SI + 8;
        unaff_DI = unaff_SI;
      }
      in_CX = in_CX + -1;
      unaff_SI = puVar29;
    } while (in_CX != 0);
    unaff_SI = (uint *)*(uint *)puVar27;
    puVar27 = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
code_r0x00013a16:
    puVar20 = (uint *)puVar27;
    uVar8 = (undefined2)((ulong)puVar27 >> 0x10);
    if (0x1ef < in_BX) break;
    pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x59);
    *pbVar2 = *pbVar2 | (byte)in_BX;
    bVar5 = *(byte *)(in_BX + puVar20[1]);
    puVar20[1] = (uint)unaff_SI;
    *(char *)0xaaaa = *(char *)0xaaaa + (byte)in_BX + ((byte)((char)unaff_BP + 1U) < bVar5);
    uVar7 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
    unaff_DI = (uint *)puVar20[1];
    puVar27 = (uint *)CONCAT22(uVar8,puVar20 + 2);
    unaff_SI = (uint *)0xc800;
    unaff_BP = uVar9;
  } while( true );
  unaff_SS = *puVar20;
  in_ESP = (uint *)CONCAT22(uVar8,puVar20 + 1);
  goto code_r0x00013a1d;
LAB_1000_381b:
  bVar5 = (byte)uVar10;
  bVar30 = bVar5 < 0x10;
  bVar34 = SBORROW1(bVar5,'\x10');
  bVar33 = (char)(bVar5 - 0x10) < '\0';
  bVar32 = bVar5 == 0x10;
  if (!bVar30) {
    cVar35 = '\x04';
    if (7 < bVar5) {
      bVar34 = SBORROW1(bVar5,'\f');
      bVar33 = (char)(bVar5 - 0xc) < '\0';
      bVar32 = bVar5 == 0xc;
      bVar30 = true;
      if (bVar5 < 0xc) goto LAB_1000_383e;
    }
    cVar35 = '\b';
    if (bVar5 != 0) {
      bVar34 = SBORROW1(bVar5,'\x05');
      bVar33 = (char)(bVar5 - 5) < '\0';
      bVar32 = bVar5 == 5;
      bVar30 = true;
      if (bVar5 < 5) goto LAB_1000_383e;
    }
    cVar35 = '\v';
    bVar30 = bVar5 < 5;
    bVar34 = SBORROW1(bVar5,'\x05');
    bVar33 = (char)(bVar5 - 5) < '\0';
    bVar32 = bVar5 == 5;
    if (!bVar32) {
      uVar12 = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar2 = (byte *)(uVar9 + (int)puVar29);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar5 ^ 0xf8) & 0xf) | in_AF;
      pbVar2 = (byte *)((int)unaff_DI + uVar9 + 0x854);
      *pbVar2 = *pbVar2 & 0xb;
      uVar31 = *pbVar2 == 0;
      puVar16 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar17 = (uint *)(puVar16 + -2);
      *(undefined2 *)(puVar16 + -2) = 0x387a;
      uVar36 = func_0x0001b476();
      uVar7 = (uint)((ulong)uVar36 >> 0x10);
      if (!(bool)uVar31) {
        *(byte *)((int)puVar29 + 0xb) = (byte)uVar36;
      }
      uVar10 = CONCAT11((char)((ulong)uVar36 >> 8),(byte)puVar29[5]) & 0xffd0 | 5;
      bVar5 = (byte)uVar10;
      *(byte *)(puVar29 + 5) = bVar5;
      swi(4);
      pbVar2 = (byte *)(unaff_BP + (int)puVar29);
      *pbVar2 = *pbVar2 + bVar5;
      if ((POPCOUNT(*pbVar2) & 1U) != 0) {
        pbVar2 = (byte *)((int)puVar29 + uVar9 + 0x33);
        bVar5 = *pbVar2;
        bVar14 = (byte)((ulong)uVar36 >> 0x10);
        bVar11 = *pbVar2;
        cVar6 = (char)((ulong)uVar36 >> 0x18) + *(byte *)(uVar9 + (int)puVar29);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar6;
        pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar2 = *pbVar2 | (byte)(CONCAT22(CONCAT11(cVar6,bVar14 + bVar11),
                                            (uVar10 + 0x5556) - (uint)CARRY1(bVar14,bVar5)) %
                                  (ulong)puVar29[0x410]);
        *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
             *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
        return *puVar17;
      }
      puVar23 = puVar17;
      if (*pbVar2 != 0) goto code_r0x000138e6;
LAB_1000_3958:
      *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar7;
      unaff_SI = (uint *)((int)puVar29 + 1);
      out((byte)*puVar29,uVar7);
      uVar9 = CONCAT11((byte)(uVar9 >> 8) & *(byte *)((int)unaff_SI + unaff_BP + 0x11),(char)uVar9);
      bVar11 = (byte)uVar7;
      cVar35 = SBORROW1(bVar11,(byte)puVar29[0x39]);
      bVar5 = (byte)puVar29[0x39];
      cVar6 = (char)(bVar11 - bVar5) < '\0';
      bVar30 = bVar11 == bVar5;
      puVar18 = (uint *)((int)puVar23 + -2);
      *(undefined2 *)((int)puVar23 + -2) = 0x396b;
      bVar5 = func_0x0001b3ed();
      iVar13 = extraout_DX_00;
      if (!bVar30) {
        *(byte *)(puVar29 + 6) = bVar5;
        *(undefined2 *)((int)puVar18 + -2) = 0x3973;
        puVar18 = (uint *)((int)puVar18 + -2);
        bVar5 = func_0x0001b617();
        iVar13 = extraout_DX_01;
      }
      if (cVar35 == cVar6) {
        bVar5 = bVar5 ^ *(byte *)(unaff_BP + (int)unaff_SI);
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * '\x06' & 0xf;
        unaff_DS = *puVar18;
        pbVar2 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
        bVar30 = bVar5 < *pbVar2 || bVar5 == *pbVar2;
        puVar27 = (uint *)CONCAT22(uVar28,puVar18);
        *puVar18 = 0x39ba;
        uVar36 = FUN_1000_a1b8();
        uVar7 = (uint)uVar36;
        if (bVar30) goto code_r0x000139bc;
        out((int)((ulong)uVar36 >> 0x10),(char)uVar36);
        puVar1 = unaff_SI;
        bVar30 = CARRY2(*puVar1,uVar7);
        *puVar1 = *puVar1 + uVar7;
        bVar33 = (int)*puVar1 < 0;
        bVar32 = *puVar1 == 0;
        bVar5 = POPCOUNT(*puVar1 & 0xff);
        uVar12 = uVar12 - 1;
        if (uVar12 != 0 && !bVar32) goto LAB_1000_3a35;
      }
      else {
        iVar13 = iVar13 + 1;
        puVar18[-1] = (uint)unaff_DI;
        puVar18[-2] = iVar13;
        puVar18[-3] = CONCAT11((char)(uVar12 >> 8),8);
        puVar18[-4] = uVar9;
        if (iVar13 != 0) {
          pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
          *pbVar2 = *pbVar2 | (byte)((uint)iVar13 >> 8);
          goto code_r0x00013985;
        }
      }
      pcVar4 = (code *)swi(1);
      uVar9 = (*pcVar4)();
      return uVar9;
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
LAB_1000_37ea_2:
  if (cVar35 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
    puVar15 = (undefined2 *)(puVar26 + -2);
    puVar26 = puVar26 + -2;
    *puVar15 = 0x37f3;
    func_0x0001b6c0();
  }
  return *(uint *)(puVar26 + 0xe);
}


