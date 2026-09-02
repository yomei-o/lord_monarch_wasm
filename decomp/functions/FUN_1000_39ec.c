/* 1000:39ec */

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

uint FUN_1000_39ec(void)

{
  byte *pbVar1;
  uint uVar2;
  code *pcVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint in_AX;
  byte bVar10;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  int in_CX;
  uint uVar11;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar12;
  uint in_BX;
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
  
code_r0x000139ec:
  uVar8 = in_BX;
  puVar23 = unaff_SI;
  if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
    puVar27 = in_ESP + -2;
    *puVar27 = unaff_DS;
    bVar4 = (byte)in_AX | 0x17;
    bVar10 = (byte)(in_AX >> 8);
    if (bVar10 != (byte)unaff_SI[6]) {
      uVar8 = CONCAT11(bVar10 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)in_AX) | 0x17;
      pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x7263);
      *pbVar1 = *pbVar1 ^ (byte)((uint)in_CX >> 8);
      *(byte *)(unaff_BP + (int)unaff_DI) = *(byte *)(unaff_BP + (int)unaff_DI) | (byte)(in_BX >> 8)
      ;
      in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
      in_AX = *(uint *)puVar27;
      in_ESP = (uint *)CONCAT22((int)((ulong)puVar27 >> 0x10),(uint *)puVar27 + 1);
      puVar23 = unaff_SI + 8;
      unaff_DI = unaff_SI;
      goto LAB_1000_3a13;
    }
    in_AX = CONCAT11(bVar4 / 0x5e,bVar4 % 0x5e);
    puVar29 = unaff_DI;
code_r0x00013a16:
    puVar20 = (uint *)puVar27;
    uVar7 = (undefined2)((ulong)puVar27 >> 0x10);
    if (0x1ef < in_BX) {
      unaff_SS = *puVar20;
      *(longdouble *)(in_BX + (int)puVar29) = in_ST0;
      in_ESP = (uint *)CONCAT22(uVar7,(uint *)(puVar20[1] + -2));
      *(undefined2 *)(puVar20[1] + -2) = unaff_ES;
      uVar8 = puVar29[2];
      uVar6 = (uint)*(byte *)((int)puVar29 + -0x79);
      bVar30 = (byte)in_CX < *(byte *)(unaff_BP + (int)puVar23);
      cVar5 = (byte)in_CX - *(byte *)(unaff_BP + (int)puVar23);
      uVar11 = CONCAT11((char)((uint)in_CX >> 8),cVar5);
      bVar33 = cVar5 < '\0';
      bVar32 = cVar5 == '\0';
      bVar4 = POPCOUNT(cVar5);
      LOCK();
      unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
      *(undefined2 *)(unaff_BP - 0x2e) = puVar29;
      UNLOCK();
      in_AX = unaff_BP;
      in_ST0 = in_ST1;
      in_ST1 = in_ST2;
      in_ST2 = in_ST3;
      in_ST3 = in_ST4;
      in_ST4 = in_ST5;
      in_ST5 = in_ST6;
      in_ST6 = in_ST7;
LAB_1000_3a35:
      if (bVar32) {
        *(byte *)(uVar8 + (int)puVar23) = *(byte *)(uVar8 + (int)puVar23) + 1;
        puVar21 = (uint *)in_ESP;
        in_ESP = (uint *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar21 + -1);
        puVar21[-1] = unaff_ES;
        if (0xbbc4 < CONCAT11(bVar33 << 7 | 0x40U | in_AF << 4 | ((bVar4 & 1) == 0) << 2 | 2 |
                              bVar30,(char)uVar6)) {
          pbVar1 = (byte *)((int)unaff_DI + in_AX + 0xab12);
          *pbVar1 = *pbVar1 | (byte)(uVar8 >> 8);
          puVar27 = unaff_DI;
          unaff_DI = (uint *)((int)unaff_DI + 1);
          *(byte *)puVar27 = (char)uVar6 + 0x3b;
          goto LAB_1000_3a63;
        }
        in_AX = in_AX + uVar11;
        pbVar1 = (byte *)((uVar8 >> 2) + (int)puVar23);
        *pbVar1 = *pbVar1 - 0x15;
        puVar27 = (uint *)((int)unaff_DI + in_AX + 0x645);
        uVar6 = *puVar27;
        *puVar27 = *puVar27 - uVar11;
        bVar4 = ((char)(uVar8 >> 1) + (char)(uVar8 >> 2) + -0x10) - (uVar6 < uVar11) | 2;
        iVar12 = *(int *)(byte *)((int)unaff_DI + 0x55);
        puVar29 = puVar23;
code_r0x00013aab:
        *(byte *)(in_AX + (int)puVar29) = *(byte *)(in_AX + (int)puVar29) & bVar4;
        ((uint *)in_ESP)[-1] = in_AX;
        *(byte *)(in_AX + (int)puVar29) = *(byte *)(in_AX + (int)puVar29) & (byte)uVar11;
        puVar23 = (uint *)0xf029;
        *(uint *)0xf029 = in_AX;
        if (iVar12 != *(int *)0x32bb) {
          *(undefined2 *)0xf027 = 0x3ac4;
          func_0x0001afc1();
          *(byte *)(in_AX + (int)puVar29) = *(byte *)(in_AX + (int)puVar29) | bVar4;
          pcVar3 = (code *)swi(1);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        uVar8 = CONCAT11(1,*(undefined1 *)0x3c00);
        if (((*puVar29 & 0x80) != 0) || (*(byte *)((int)puVar29 + 0xb) != 0xff)) goto LAB_1000_3b12;
        if ((byte)puVar29[5] != 0) {
code_r0x00013b04:
          if ((byte)uVar8 == (byte)puVar29[6]) goto LAB_1000_3b12;
          goto code_r0x00013b09;
        }
LAB_1000_3b0f:
        *(byte *)(puVar29 + 5) = (byte)(uVar8 >> 8);
LAB_1000_3b12:
        return *(uint *)((int)puVar23 + 0xe);
      }
LAB_1000_3a63:
      pcVar3 = (code *)swi(0x20);
      (*pcVar3)();
      *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar8 >> 8);
      puVar22 = (uint *)in_ESP;
      uVar28 = (undefined2)((ulong)in_ESP >> 0x10);
      puVar22[-1] = unaff_ES;
      pbVar1 = (byte *)((int)puVar23 + uVar8 + 0x222);
      *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
      unaff_DI = (uint *)puVar22[-1];
      puVar29 = (uint *)*puVar22;
      in_AX = puVar22[1];
      uVar11 = puVar22[5];
      uVar7 = puVar22[6];
      uVar8 = CONCAT11((char)(puVar22[3] >> 8),(byte)puVar22[3] | *(byte *)0x5d02) |
              *(uint *)((int)unaff_DI + in_AX + 10);
      puVar22[6] = (uint)unaff_DI;
      pbVar1 = (byte *)((int)puVar29 + uVar8 + 0x2c2);
      cVar35 = SCARRY1((char)uVar7,*pbVar1);
      bVar30 = (char)((char)uVar7 + *pbVar1) < '\0';
      puVar23 = puVar22 + 5;
      puVar22[5] = 0x3a83;
      uVar36 = func_0x00013e95();
      bVar4 = (byte)uVar36;
      out(0x6f,bVar4);
      *(undefined1 *)0x1108 = (char)uVar8;
      cVar5 = (char)((ulong)uVar36 >> 0x18);
      if (!bVar30) {
        if ((bool)cVar35 == bVar30) {
          *(byte *)((int)puVar29 + 0xb) = *(byte *)((int)puVar29 + 0xb) + cVar5;
          goto code_r0x00013b04;
        }
code_r0x00013b09:
        if ((byte)puVar29[5] != 2) goto LAB_1000_3b12;
        goto LAB_1000_3b0f;
      }
      bVar13 = (byte)(uVar8 >> 8);
      puVar27 = (uint *)((int)unaff_DI + -0x53);
      uVar2 = (uint)(bVar13 < (byte)(uVar11 >> 8));
      uVar6 = *puVar27;
      uVar9 = *puVar27;
      *puVar27 = uVar9 + 0xe02d + uVar2;
      bVar10 = *(byte *)(in_AX + (int)unaff_DI);
      bVar13 = bVar13 + (byte)puVar29[0x1015] | (byte)((ulong)uVar36 >> 8);
      uVar8 = CONCAT11(bVar13,(char)uVar8);
      if (-1 < (char)bVar13) {
        in_ESP = (uint *)ZEXT24((undefined1 *)((int)puVar23 + -2));
        *(undefined2 *)((int)puVar23 + -2) = unaff_CS;
        iVar12 = CONCAT11(cVar5 - *(byte *)((int)puVar29 + uVar8 + 0x23c9),
                          (char)((ulong)uVar36 >> 0x10) + bVar10 +
                          (0x1fd2 < uVar6 || CARRY2(uVar9 + 0xe02d,uVar2)));
        pbVar1 = (byte *)((int)unaff_DI + in_AX + 0x5555);
        *pbVar1 = *pbVar1 + (char)uVar11;
        goto code_r0x00013aab;
      }
      bVar30 = puVar29[3] < 1000;
      if (!bVar30) {
                    /* WARNING: Call to offcut address within same function */
        *(undefined2 *)((int)puVar23 + -2) = 0x3b26;
        puVar23 = (uint *)((int)puVar23 + -2);
        cVar5 = func_0x00013966();
        if (!bVar30) goto LAB_1000_3b55_1;
      }
      puVar25 = (undefined1 *)((int)puVar23 + -2);
      *(undefined2 *)((int)puVar23 + -2) = 0x3b2d;
      uVar36 = FUN_1000_8cb7();
      uVar6 = (uint)((ulong)uVar36 >> 0x10);
      uVar9 = (uint)uVar36;
      bVar30 = (byte)uVar36 < 0x5a;
      if (!bVar30) {
        puVar24 = puVar25 + -2;
        *(undefined2 *)(puVar25 + -2) = 0x3b42;
        cVar5 = FUN_1000_3607();
        cVar35 = (char)uVar11;
        if (!bVar30) {
LAB_1000_3b55_1:
          uVar9 = (byte)(cVar5 + 0x80) | 1;
code_r0x00013b57:
          *(byte *)puVar29 = (byte)*puVar29 | 1;
          return uVar9;
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
            uVar9 = func_0x000137e6();
            cVar35 = (char)uVar11;
            if (bVar30) goto LAB_1000_381b;
          }
          if (*(int *)0x3480 != 0) goto code_r0x00013b57;
          *(uint *)(puVar26 + -2) = in_AX;
          puVar25 = puVar26 + -4;
          *(uint *)(puVar26 + -4) = in_AX;
          pbVar1 = (byte *)(uVar8 + (int)puVar29);
          bVar4 = (byte)(uVar9 >> 8);
          bVar30 = CARRY1(*pbVar1,bVar4);
          *pbVar1 = *pbVar1 + bVar4;
          uVar8 = uVar8 - 1;
        } while( true );
      }
      puVar16 = (uint *)(puVar25 + -2);
      *(undefined2 *)(puVar25 + -2) = 0x3b38;
      bVar30 = false;
      while( true ) {
        *(undefined2 *)((int)puVar16 + -2) = unaff_SS;
        if (!bVar30) break;
        uVar8 = uVar8 + 1;
        puVar26 = (undefined1 *)((int)puVar16 + -4);
        *(undefined2 *)((int)puVar16 + -4) = 0x810;
        *(byte *)(puVar29 + 1) = (byte)puVar29[1] | (byte)uVar6;
FUN_1000_38de:
        puVar16 = (uint *)(puVar26 + -2);
        *(undefined2 *)(puVar26 + -2) = 0x38e1;
        FUN_1000_7494();
        *(byte *)(uVar8 + (int)puVar29) = *(byte *)(uVar8 + (int)puVar29) & (byte)uVar11;
        LOCK();
        uVar31 = *(undefined1 *)(in_AX + 0x72);
        *(undefined1 *)(in_AX + 0x72) = (char)((uint)extraout_DX >> 8);
        uVar6 = CONCAT11(uVar31,(char)extraout_DX);
        UNLOCK();
code_r0x000138e6:
        *(uint *)((int)puVar29 + 0x31) = *(uint *)((int)puVar29 + 0x31) & (uint)puVar29;
        bVar30 = CARRY1((byte)uVar8,*(byte *)(in_AX + (int)puVar29));
        uVar8 = CONCAT11((char)(uVar8 >> 8),(byte)uVar8 + *(byte *)(in_AX + (int)puVar29));
      }
      puVar27 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar27 = 0x30;
      uVar9 = CONCAT11(0xaa,*(byte *)(in_AX + (int)unaff_DI) | 0x30) ^ 0x8a0;
      *(uint *)((int)puVar16 + -2) = uVar8;
      *(uint *)((int)puVar16 + -4) = uVar9;
      uVar8 = puVar29[0x15];
      uVar6 = (uVar6 | 0x3000) - *(int *)(byte *)(uVar8 + (int)puVar29);
      bVar10 = (byte)(uVar9 >> 8);
      bVar4 = (char)uVar9 + 8;
      if (bVar4 != *(byte *)(uVar8 + 0xd27e)) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      *(undefined2 *)((int)puVar16 + -6) = CONCAT11(bVar10,bVar4);
      *(uint *)((int)puVar16 + -8) = uVar11;
      *(uint *)((int)puVar16 + -10) = uVar6;
      *(uint *)((int)puVar16 + -0xc) = uVar8;
      *(undefined1 **)(undefined1 *)((int)puVar16 + -0xe) = (undefined1 *)((int)puVar16 + -4);
      *(uint *)((int)puVar16 + -0x10) = in_AX;
      *(undefined2 *)((int)puVar16 + -0x12) = puVar29;
      *(undefined2 *)((int)puVar16 + -0x14) = unaff_DI;
      uVar9 = *unaff_DI;
      cVar5 = (char)(uVar11 >> 8);
      bVar13 = cVar5 + bVar4;
      uVar11 = CONCAT11(bVar13,(char)uVar11);
      in_AX = 0x874;
      if (SCARRY1(cVar5,bVar4)) {
        puVar17 = (uint *)*(undefined2 *)((int)puVar16 + -0x14);
        puVar29 = *(uint **)(byte *)((int)unaff_DI + (uVar8 - 0x18));
        puVar27 = puVar29 + 0x43a;
        uVar2 = *puVar27;
        *puVar27 = *puVar27 + 0x809;
        uVar11 = 0x4379;
        puVar29[0x43a] =
             puVar29[0x43a] + CONCAT11(bVar10 | (byte)uVar9,bVar4 | bVar13) + (uint)(0xf7f6 < uVar2)
        ;
      }
      else {
        *(undefined2 *)((int)puVar16 + -0x16) = 0x874;
        puVar17 = (uint *)((int)puVar16 + -0x18);
        *(undefined2 *)((int)puVar16 + -0x18) = 0x874;
      }
      goto LAB_1000_3958;
    }
    pbVar1 = (byte *)((int)puVar29 + unaff_BP + 0x59);
    *pbVar1 = *pbVar1 | (byte)in_BX;
    bVar4 = *(byte *)(in_BX + puVar20[1]);
    puVar20[1] = (uint)puVar23;
    *(char *)0xaaaa = *(char *)0xaaaa + (byte)in_BX + ((byte)((char)unaff_BP + 1U) < bVar4);
    uVar6 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
    unaff_DI = (uint *)puVar20[1];
    in_ESP = (uint *)CONCAT22(uVar7,puVar20 + 2);
    puVar23 = (uint *)0xc800;
    goto LAB_1000_39e6;
  }
LAB_1000_3a13:
  in_CX = in_CX + -1;
  uVar6 = in_AX;
  if (in_CX == 0) {
    puVar27 = (uint *)CONCAT22((int)((ulong)in_ESP >> 0x10),(uint *)in_ESP + 1);
    in_BX = uVar8;
    puVar23 = (uint *)*(uint *)in_ESP;
    puVar29 = unaff_DI;
    goto code_r0x00013a16;
  }
  goto FUN_1000_39e9;
code_r0x000139bc:
  if (uVar11 != 1) {
code_r0x00013985:
    pbVar1 = (byte *)((int)unaff_DI + uVar8 + 0x12);
    *(byte **)pbVar1 = (byte *)((int)unaff_DI + *(int *)pbVar1 + 2);
    puVar19 = (undefined1 *)0x2e1c;
    *(undefined2 *)0x2e1c = 0x3990;
    FUN_1000_8d53();
    *(undefined2 *)(puVar19 + -2) = 0x399f;
    func_0x00018e51();
    pcVar3 = (code *)swi(3);
    uVar8 = (*pcVar3)();
    return uVar8;
  }
LAB_1000_39e6:
  in_CX = 0x40;
  unaff_BP = in_AX;
FUN_1000_39e9:
  in_BX = 0xffff;
  in_AX = uVar6;
  unaff_SI = puVar23;
  goto code_r0x000139ec;
LAB_1000_381b:
  bVar4 = (byte)uVar9;
  bVar30 = bVar4 < 0x10;
  bVar34 = SBORROW1(bVar4,'\x10');
  bVar33 = (char)(bVar4 - 0x10) < '\0';
  bVar32 = bVar4 == 0x10;
  if (!bVar30) {
    cVar35 = '\x04';
    if (7 < bVar4) {
      bVar34 = SBORROW1(bVar4,'\f');
      bVar33 = (char)(bVar4 - 0xc) < '\0';
      bVar32 = bVar4 == 0xc;
      bVar30 = true;
      if (bVar4 < 0xc) goto LAB_1000_383e;
    }
    cVar35 = '\b';
    if (bVar4 != 0) {
      bVar34 = SBORROW1(bVar4,'\x05');
      bVar33 = (char)(bVar4 - 5) < '\0';
      bVar32 = bVar4 == 5;
      bVar30 = true;
      if (bVar4 < 5) goto LAB_1000_383e;
    }
    cVar35 = '\v';
    bVar30 = bVar4 < 5;
    bVar34 = SBORROW1(bVar4,'\x05');
    bVar33 = (char)(bVar4 - 5) < '\0';
    bVar32 = bVar4 == 5;
    if (!bVar32) {
      uVar11 = CONCAT11(*(byte *)((int)unaff_DI + (in_AX - 0x80)),0xb);
      pbVar1 = (byte *)(uVar8 + (int)puVar29);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar4 ^ 0xf8) & 0xf) | in_AF;
      pbVar1 = (byte *)((int)unaff_DI + uVar8 + 0x854);
      *pbVar1 = *pbVar1 & 0xb;
      uVar31 = *pbVar1 == 0;
      puVar15 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar16 = (uint *)(puVar15 + -2);
      *(undefined2 *)(puVar15 + -2) = 0x387a;
      uVar36 = func_0x0001b476();
      uVar6 = (uint)((ulong)uVar36 >> 0x10);
      if (!(bool)uVar31) {
        *(byte *)((int)puVar29 + 0xb) = (byte)uVar36;
      }
      uVar9 = CONCAT11((char)((ulong)uVar36 >> 8),(byte)puVar29[5]) & 0xffd0 | 5;
      bVar4 = (byte)uVar9;
      *(byte *)(puVar29 + 5) = bVar4;
      swi(4);
      pbVar1 = (byte *)(in_AX + (int)puVar29);
      *pbVar1 = *pbVar1 + bVar4;
      if ((POPCOUNT(*pbVar1) & 1U) != 0) {
        pbVar1 = (byte *)((int)puVar29 + uVar8 + 0x33);
        bVar4 = *pbVar1;
        bVar13 = (byte)((ulong)uVar36 >> 0x10);
        bVar10 = *pbVar1;
        cVar5 = (char)((ulong)uVar36 >> 0x18) + *(byte *)(uVar8 + (int)puVar29);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar5;
        pbVar1 = (byte *)((int)unaff_DI + in_AX + 0xe872);
        *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar5,bVar13 + bVar10),
                                            (uVar9 + 0x5556) - (uint)CARRY1(bVar13,bVar4)) %
                                  (ulong)puVar29[0x410]);
        *(int *)(byte *)(in_AX + (int)unaff_DI) = *(int *)(byte *)(in_AX + (int)unaff_DI) >> 0x10;
        return *puVar16;
      }
      puVar17 = puVar16;
      if (*pbVar1 != 0) goto code_r0x000138e6;
LAB_1000_3958:
      *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar6;
      puVar23 = (uint *)((int)puVar29 + 1);
      out((byte)*puVar29,uVar6);
      uVar8 = CONCAT11((byte)(uVar8 >> 8) & *(byte *)((int)puVar23 + in_AX + 0x11),(char)uVar8);
      bVar10 = (byte)uVar6;
      cVar35 = SBORROW1(bVar10,(byte)puVar29[0x39]);
      bVar4 = (byte)puVar29[0x39];
      cVar5 = (char)(bVar10 - bVar4) < '\0';
      bVar30 = bVar10 == bVar4;
      puVar18 = (uint *)((int)puVar17 + -2);
      *(undefined2 *)((int)puVar17 + -2) = 0x396b;
      bVar4 = func_0x0001b3ed();
      iVar12 = extraout_DX_00;
      if (!bVar30) {
        *(byte *)(puVar29 + 6) = bVar4;
        *(undefined2 *)((int)puVar18 + -2) = 0x3973;
        puVar18 = (uint *)((int)puVar18 + -2);
        bVar4 = func_0x0001b617();
        iVar12 = extraout_DX_01;
      }
      if (cVar35 == cVar5) {
        bVar4 = bVar4 ^ *(byte *)(in_AX + (int)puVar23);
        in_AF = 9 < (bVar4 & 0xf) | in_AF;
        bVar4 = bVar4 + in_AF * '\x06' & 0xf;
        unaff_DS = *puVar18;
        pbVar1 = (byte *)((int)puVar23 + in_AX + 0x8b5f);
        bVar30 = bVar4 < *pbVar1 || bVar4 == *pbVar1;
        in_ESP = (uint *)CONCAT22(uVar28,puVar18);
        *puVar18 = 0x39ba;
        uVar36 = FUN_1000_a1b8();
        uVar6 = (uint)uVar36;
        if (bVar30) goto code_r0x000139bc;
        out((int)((ulong)uVar36 >> 0x10),(char)uVar36);
        puVar27 = puVar23;
        bVar30 = CARRY2(*puVar27,uVar6);
        *puVar27 = *puVar27 + uVar6;
        bVar33 = (int)*puVar27 < 0;
        bVar32 = *puVar27 == 0;
        bVar4 = POPCOUNT(*puVar27 & 0xff);
        uVar11 = uVar11 - 1;
        if (uVar11 != 0 && !bVar32) goto LAB_1000_3a35;
      }
      else {
        iVar12 = iVar12 + 1;
        puVar18[-1] = (uint)unaff_DI;
        puVar18[-2] = iVar12;
        puVar18[-3] = CONCAT11((char)(uVar11 >> 8),8);
        puVar18[-4] = uVar8;
        if (iVar12 != 0) {
          pbVar1 = (byte *)((int)unaff_DI + in_AX + 0x6e);
          *pbVar1 = *pbVar1 | (byte)((uint)iVar12 >> 8);
          goto code_r0x00013985;
        }
      }
      pcVar3 = (code *)swi(1);
      uVar8 = (*pcVar3)();
      return uVar8;
    }
  }
LAB_1000_383e:
  if (bVar30) {
    *(undefined2 *)(puVar26 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar32 && bVar34 == bVar33) {
    return *(uint *)(in_AX + 0xe);
  }
LAB_1000_37ea_2:
  if (cVar35 == '\0' && *(byte *)(in_AX + (int)unaff_DI) == 0) {
    puVar14 = (undefined2 *)(puVar26 + -2);
    puVar26 = puVar26 + -2;
    *puVar14 = 0x37f3;
    func_0x0001b6c0();
  }
  return *(uint *)(puVar26 + 0xe);
}


