/* 1000:39b6 */

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
/* WARNING: Removing unreachable block (ram,0x00013ace) */
/* WARNING: Removing unreachable block (ram,0x00013ada) */
/* WARNING: Removing unreachable block (ram,0x00013ad5) */
/* WARNING: Removing unreachable block (ram,0x00013add) */
/* WARNING: Removing unreachable block (ram,0x00013889) */
/* WARNING: Removing unreachable block (ram,0x00013a25) */
/* WARNING: Removing unreachable block (ram,0x00013ae4) */
/* WARNING: Removing unreachable block (ram,0x000139ea) */
/* WARNING: Removing unreachable block (ram,0x0001384c) */

uint FUN_1000_39b6(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  code *pcVar4;
  byte bVar5;
  byte bVar9;
  uint uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint in_CX;
  int iVar10;
  char cVar11;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  uint in_BX;
  uint uVar12;
  byte bVar13;
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
  uint *in_ESP;
  uint *puVar26;
  undefined2 uVar27;
  uint unaff_BP;
  uint *unaff_SI;
  uint *puVar28;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  undefined1 in_CF;
  bool bVar29;
  byte in_AF;
  undefined1 uVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  char cVar34;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar35;
  
code_r0x000139b6:
  puVar26 = (uint *)CONCAT22((int)((ulong)in_ESP >> 0x10),(uint *)in_ESP + -1);
  ((uint *)in_ESP)[-1] = 0x39ba;
  uVar35 = FUN_1000_a1b8();
  uVar12 = (uint)uVar35;
  if (!(bool)in_CF) {
    out((int)((ulong)uVar35 >> 0x10),(char)uVar35);
    puVar1 = unaff_SI;
    bVar29 = CARRY2(*puVar1,uVar12) || CARRY2(*puVar1 + uVar12,(uint)(byte)in_CF);
    *puVar1 = *puVar1 + uVar12 + (uint)(byte)in_CF;
    bVar32 = (int)*puVar1 < 0;
    bVar31 = *puVar1 == 0;
    bVar5 = POPCOUNT(*puVar1 & 0xff);
    in_CX = in_CX - 1;
    if (in_CX != 0 && !bVar31) goto LAB_1000_3a35;
    goto LAB_1000_39c7;
  }
  if (in_CX == 1) {
    do {
      iVar10 = 0x40;
      uVar6 = uVar12;
      do {
        uVar12 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
        puVar28 = unaff_SI;
        if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
          puVar26 = puVar26 + -2;
          *puVar26 = unaff_DS;
          bVar5 = (byte)uVar6 | 0x17;
          bVar9 = (byte)(uVar6 >> 8);
          if (bVar9 == (byte)unaff_SI[6]) {
            uVar6 = CONCAT11(bVar5 / 0x5e,bVar5 % 0x5e);
            puVar28 = unaff_DI;
            goto code_r0x00013a16;
          }
          uVar12 = CONCAT11(bVar9 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)uVar6) | 0x17;
          *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar10 >> 8);
          *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
          in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
          uVar6 = *(uint *)puVar26;
          puVar26 = (uint *)CONCAT22((int)((ulong)puVar26 >> 0x10),(uint *)puVar26 + 1);
          puVar28 = unaff_SI + 8;
          unaff_DI = unaff_SI;
        }
        iVar10 = iVar10 + -1;
        unaff_SI = puVar28;
      } while (iVar10 != 0);
      unaff_SI = (uint *)*(uint *)puVar26;
      puVar26 = (uint *)CONCAT22((int)((ulong)puVar26 >> 0x10),(uint *)puVar26 + 1);
      puVar28 = unaff_DI;
code_r0x00013a16:
      puVar19 = (uint *)puVar26;
      uVar7 = (undefined2)((ulong)puVar26 >> 0x10);
      if (0x1ef < uVar12) goto code_r0x00013a1c;
      pbVar2 = (byte *)((int)puVar28 + unaff_BP + 0x59);
      *pbVar2 = *pbVar2 | (byte)uVar12;
      bVar5 = *(byte *)(uVar12 + puVar19[1]);
      puVar19[1] = (uint)unaff_SI;
      *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar12 + ((byte)((char)unaff_BP + 1U) < bVar5);
      uVar12 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
      unaff_DI = (uint *)puVar19[1];
      puVar26 = (uint *)CONCAT22(uVar7,puVar19 + 2);
      unaff_SI = (uint *)0xc800;
      unaff_BP = uVar6;
    } while( true );
  }
  goto code_r0x00013985;
LAB_1000_381b:
  bVar5 = (byte)uVar8;
  bVar29 = bVar5 < 0x10;
  bVar33 = SBORROW1(bVar5,'\x10');
  bVar32 = (char)(bVar5 - 0x10) < '\0';
  bVar31 = bVar5 == 0x10;
  if (!bVar29) {
    cVar11 = '\x04';
    if (7 < bVar5) {
      bVar33 = SBORROW1(bVar5,'\f');
      bVar32 = (char)(bVar5 - 0xc) < '\0';
      bVar31 = bVar5 == 0xc;
      bVar29 = true;
      if (bVar5 < 0xc) goto LAB_1000_383e;
    }
    cVar11 = '\b';
    if (bVar5 != 0) {
      bVar33 = SBORROW1(bVar5,'\x05');
      bVar32 = (char)(bVar5 - 5) < '\0';
      bVar31 = bVar5 == 5;
      bVar29 = true;
      if (bVar5 < 5) goto LAB_1000_383e;
    }
    cVar11 = '\v';
    bVar29 = bVar5 < 5;
    bVar33 = SBORROW1(bVar5,'\x05');
    bVar32 = (char)(bVar5 - 5) < '\0';
    bVar31 = bVar5 == 5;
    if (!bVar31) {
      in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar2 = (byte *)(uVar12 + (int)puVar28);
      *pbVar2 = *pbVar2 & 0xb;
      if (*pbVar2 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar5 ^ 0xf8) & 0xf) | in_AF;
      pbVar2 = (byte *)((int)unaff_DI + uVar12 + 0x854);
      *pbVar2 = *pbVar2 & 0xb;
      uVar30 = *pbVar2 == 0;
      puVar15 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar16 = (uint *)(puVar15 + -2);
      *(undefined2 *)(puVar15 + -2) = 0x387a;
      uVar35 = func_0x0001b476();
      uVar6 = (uint)((ulong)uVar35 >> 0x10);
      if (!(bool)uVar30) {
        *(byte *)((int)puVar28 + 0xb) = (byte)uVar35;
      }
      uVar8 = CONCAT11((char)((ulong)uVar35 >> 8),(byte)puVar28[5]) & 0xffd0 | 5;
      bVar5 = (byte)uVar8;
      *(byte *)(puVar28 + 5) = bVar5;
      swi(4);
      pbVar2 = (byte *)(unaff_BP + (int)puVar28);
      *pbVar2 = *pbVar2 + bVar5;
      if ((POPCOUNT(*pbVar2) & 1U) != 0) {
        pbVar2 = (byte *)((int)puVar28 + uVar12 + 0x33);
        bVar5 = *pbVar2;
        bVar13 = (byte)((ulong)uVar35 >> 0x10);
        bVar9 = *pbVar2;
        cVar11 = (char)((ulong)uVar35 >> 0x18) + *(byte *)(uVar12 + (int)puVar28);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar11;
        pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar2 = *pbVar2 | (byte)(CONCAT22(CONCAT11(cVar11,bVar13 + bVar9),
                                            (uVar8 + 0x5556) - (uint)CARRY1(bVar13,bVar5)) %
                                  (ulong)puVar28[0x410]);
        *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
             *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
        return *puVar16;
      }
      puVar22 = puVar16;
      if (*pbVar2 != 0) goto code_r0x000138e6;
      goto LAB_1000_3958;
    }
  }
LAB_1000_383e:
  if (bVar29) {
    *(undefined2 *)(puVar25 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar31 && bVar33 == bVar32) {
    return *(uint *)(unaff_BP + 0xe);
  }
  goto LAB_1000_37ea_2;
code_r0x00013a1c:
  unaff_SS = *puVar19;
  *(longdouble *)(uVar12 + (int)puVar28) = in_ST0;
  puVar26 = (uint *)CONCAT22(uVar7,(uint *)(puVar19[1] + -2));
  *(undefined2 *)(puVar19[1] + -2) = unaff_ES;
  in_BX = puVar28[2];
  uVar12 = (uint)*(byte *)((int)puVar28 + -0x79);
  bVar29 = (byte)iVar10 < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar11 = (byte)iVar10 - *(byte *)(unaff_BP + (int)unaff_SI);
  in_CX = CONCAT11((char)((uint)iVar10 >> 8),cVar11);
  bVar32 = cVar11 < '\0';
  bVar31 = cVar11 == '\0';
  bVar5 = POPCOUNT(cVar11);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar28;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar31) {
    *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) + 1;
    puVar20 = (uint *)puVar26;
    puVar26 = (uint *)CONCAT22((int)((ulong)puVar26 >> 0x10),puVar20 + -1);
    puVar20[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar32 << 7 | bVar31 << 6 | in_AF << 4 | ((bVar5 & 1) == 0) << 2 | 2 |
                          bVar29,(char)uVar12)) {
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar2 = *pbVar2 | (byte)(in_BX >> 8);
      puVar1 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar1 = (char)uVar12 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar2 = (byte *)((in_BX >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar1 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 - in_CX;
    bVar5 = ((char)(in_BX >> 1) + (char)(in_BX >> 2) + -0x10) - (uVar12 < in_CX) | 2;
    iVar10 = *(int *)(byte *)((int)unaff_DI + 0x55);
    puVar28 = unaff_SI;
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)puVar28) = *(byte *)(unaff_BP + (int)puVar28) & bVar5;
    ((uint *)puVar26)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)puVar28) = *(byte *)(unaff_BP + (int)puVar28) & (byte)in_CX;
    puVar22 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar10 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)puVar28) = *(byte *)(unaff_BP + (int)puVar28) | bVar5;
      pcVar4 = (code *)swi(1);
      uVar12 = (*pcVar4)();
      return uVar12;
    }
    uVar12 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*puVar28 & 0x80) != 0) || (*(byte *)((int)puVar28 + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)puVar28[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar12 == (byte)puVar28[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar4 = (code *)swi(0x20);
    (*pcVar4)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(in_BX >> 8);
    puVar21 = (uint *)puVar26;
    uVar27 = (undefined2)((ulong)puVar26 >> 0x10);
    puVar21[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + in_BX + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)unaff_DI);
    unaff_DI = (uint *)puVar21[-1];
    puVar28 = (uint *)*puVar21;
    unaff_BP = puVar21[1];
    in_CX = puVar21[5];
    uVar7 = puVar21[6];
    uVar12 = CONCAT11((char)(puVar21[3] >> 8),(byte)puVar21[3] | *(byte *)0x5d02) |
             *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar21[6] = (uint)unaff_DI;
    pbVar2 = (byte *)((int)puVar28 + uVar12 + 0x2c2);
    cVar34 = SCARRY1((char)uVar7,*pbVar2);
    bVar29 = (char)((char)uVar7 + *pbVar2) < '\0';
    puVar22 = puVar21 + 5;
    puVar21[5] = 0x3a83;
    uVar35 = func_0x00013e95();
    bVar5 = (byte)uVar35;
    out(0x6f,bVar5);
    *(undefined1 *)0x1108 = (char)uVar12;
    cVar11 = (char)((ulong)uVar35 >> 0x18);
    if (bVar29) {
      bVar13 = (byte)(uVar12 >> 8);
      puVar26 = (uint *)((int)unaff_DI + -0x53);
      uVar3 = (uint)(bVar13 < (byte)(in_CX >> 8));
      uVar6 = *puVar26;
      uVar8 = *puVar26;
      *puVar26 = uVar8 + 0xe02d + uVar3;
      bVar9 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar13 = bVar13 + (byte)puVar28[0x1015] | (byte)((ulong)uVar35 >> 8);
      uVar12 = CONCAT11(bVar13,(char)uVar12);
      if ((char)bVar13 < '\0') {
        bVar29 = puVar28[3] < 1000;
        if (!bVar29) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar22 + -2) = 0x3b26;
          puVar22 = (uint *)((int)puVar22 + -2);
          uVar7 = func_0x00013966();
          if (!bVar29) goto LAB_1000_3b55_1;
        }
        puVar24 = (undefined1 *)((int)puVar22 + -2);
        *(undefined2 *)((int)puVar22 + -2) = 0x3b2d;
        uVar35 = FUN_1000_8cb7();
        uVar6 = (uint)((ulong)uVar35 >> 0x10);
        uVar8 = (uint)uVar35;
        bVar29 = (byte)uVar35 < 0x5a;
        if (bVar29) {
          bVar29 = true;
          if ((byte)uVar35 < 0x50) {
            do {
              puVar25 = puVar24;
              if (bVar29) {
                puVar25 = puVar24 + -2;
                *(undefined2 *)(puVar24 + -2) = 0x3b67;
                uVar8 = func_0x000137e6();
                cVar11 = (char)in_CX;
                if (bVar29) goto LAB_1000_381b;
              }
              if (*(int *)0x3480 != 0) goto code_r0x00013b57;
              *(uint *)(puVar25 + -2) = unaff_BP;
              puVar24 = puVar25 + -4;
              *(uint *)(puVar25 + -4) = unaff_BP;
              pbVar2 = (byte *)(uVar12 + (int)puVar28);
              bVar5 = (byte)(uVar8 >> 8);
              bVar29 = CARRY1(*pbVar2,bVar5);
              *pbVar2 = *pbVar2 + bVar5;
              uVar12 = uVar12 - 1;
            } while( true );
          }
          puVar16 = (uint *)(puVar24 + -2);
          *(undefined2 *)(puVar24 + -2) = 0x3b38;
          bVar29 = false;
          while( true ) {
            *(undefined2 *)((int)puVar16 + -2) = unaff_SS;
            if (!bVar29) break;
            uVar12 = uVar12 + 1;
            puVar25 = (undefined1 *)((int)puVar16 + -4);
            *(undefined2 *)((int)puVar16 + -4) = 0x810;
            *(byte *)(puVar28 + 1) = (byte)puVar28[1] | (byte)uVar6;
FUN_1000_38de:
            puVar16 = (uint *)(puVar25 + -2);
            *(undefined2 *)(puVar25 + -2) = 0x38e1;
            FUN_1000_7494();
            *(byte *)(uVar12 + (int)puVar28) = *(byte *)(uVar12 + (int)puVar28) & (byte)in_CX;
            LOCK();
            uVar30 = *(undefined1 *)(unaff_BP + 0x72);
            *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
            uVar6 = CONCAT11(uVar30,(char)extraout_DX);
            UNLOCK();
code_r0x000138e6:
            *(uint *)((int)puVar28 + 0x31) = *(uint *)((int)puVar28 + 0x31) & (uint)puVar28;
            bVar29 = CARRY1((byte)uVar12,*(byte *)(unaff_BP + (int)puVar28));
            uVar12 = CONCAT11((char)(uVar12 >> 8),(byte)uVar12 + *(byte *)(unaff_BP + (int)puVar28))
            ;
          }
          puVar26 = unaff_DI;
          unaff_DI = (uint *)((int)unaff_DI + 1);
          *(byte *)puVar26 = 0x30;
          uVar8 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
          *(uint *)((int)puVar16 + -2) = uVar12;
          *(uint *)((int)puVar16 + -4) = uVar8;
          uVar12 = puVar28[0x15];
          uVar6 = (uVar6 | 0x3000) - *(int *)(byte *)(uVar12 + (int)puVar28);
          bVar9 = (byte)(uVar8 >> 8);
          bVar5 = (char)uVar8 + 8;
          if (bVar5 != *(byte *)(uVar12 + 0xd27e)) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *(undefined2 *)((int)puVar16 + -6) = CONCAT11(bVar9,bVar5);
          *(uint *)((int)puVar16 + -8) = in_CX;
          *(uint *)((int)puVar16 + -10) = uVar6;
          *(uint *)((int)puVar16 + -0xc) = uVar12;
          *(undefined1 **)(undefined1 *)((int)puVar16 + -0xe) = (undefined1 *)((int)puVar16 + -4);
          *(uint *)((int)puVar16 + -0x10) = unaff_BP;
          *(undefined2 *)((int)puVar16 + -0x12) = puVar28;
          *(undefined2 *)((int)puVar16 + -0x14) = unaff_DI;
          uVar8 = *unaff_DI;
          cVar11 = (char)(in_CX >> 8);
          bVar13 = cVar11 + bVar5;
          in_CX = CONCAT11(bVar13,(char)in_CX);
          unaff_BP = 0x874;
          if (SCARRY1(cVar11,bVar5)) {
            puVar22 = (uint *)*(undefined2 *)((int)puVar16 + -0x14);
            puVar28 = *(uint **)(byte *)((int)unaff_DI + (uVar12 - 0x18));
            puVar26 = puVar28 + 0x43a;
            uVar3 = *puVar26;
            *puVar26 = *puVar26 + 0x809;
            in_CX = 0x4379;
            puVar28[0x43a] =
                 puVar28[0x43a] + CONCAT11(bVar9 | (byte)uVar8,bVar5 | bVar13) +
                 (uint)(0xf7f6 < uVar3);
          }
          else {
            *(undefined2 *)((int)puVar16 + -0x16) = 0x874;
            puVar22 = (uint *)((int)puVar16 + -0x18);
            *(undefined2 *)((int)puVar16 + -0x18) = 0x874;
          }
LAB_1000_3958:
          *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar6;
          unaff_SI = (uint *)((int)puVar28 + 1);
          out((byte)*puVar28,uVar6);
          in_BX = CONCAT11((byte)(uVar12 >> 8) & *(byte *)((int)unaff_SI + unaff_BP + 0x11),
                           (char)uVar12);
          bVar9 = (byte)uVar6;
          cVar34 = SBORROW1(bVar9,(byte)puVar28[0x39]);
          bVar5 = (byte)puVar28[0x39];
          cVar11 = (char)(bVar9 - bVar5) < '\0';
          bVar29 = bVar9 == bVar5;
          puVar17 = (uint *)((int)puVar22 + -2);
          *(undefined2 *)((int)puVar22 + -2) = 0x396b;
          bVar5 = func_0x0001b3ed();
          iVar10 = extraout_DX_00;
          if (!bVar29) {
            *(byte *)(puVar28 + 6) = bVar5;
            *(undefined2 *)((int)puVar17 + -2) = 0x3973;
            puVar17 = (uint *)((int)puVar17 + -2);
            bVar5 = func_0x0001b617();
            iVar10 = extraout_DX_01;
          }
          if (cVar34 != cVar11) {
            iVar10 = iVar10 + 1;
            puVar17[-1] = (uint)unaff_DI;
            puVar17[-2] = iVar10;
            puVar17[-3] = CONCAT11((char)(in_CX >> 8),8);
            puVar17[-4] = in_BX;
            if (iVar10 == 0) {
LAB_1000_39c7:
              pcVar4 = (code *)swi(1);
              uVar12 = (*pcVar4)();
              return uVar12;
            }
            pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
            *pbVar2 = *pbVar2 | (byte)((uint)iVar10 >> 8);
code_r0x00013985:
            pbVar2 = (byte *)((int)unaff_DI + in_BX + 0x12);
            *(byte **)pbVar2 = (byte *)((int)unaff_DI + *(int *)pbVar2 + 2);
            puVar18 = (undefined1 *)0x2e1c;
            *(undefined2 *)0x2e1c = 0x3990;
            FUN_1000_8d53();
            *(undefined2 *)(puVar18 + -2) = 0x399f;
            func_0x00018e51();
            pcVar4 = (code *)swi(3);
            uVar12 = (*pcVar4)();
            return uVar12;
          }
          bVar5 = bVar5 ^ *(byte *)(unaff_BP + (int)unaff_SI);
          in_AF = 9 < (bVar5 & 0xf) | in_AF;
          bVar5 = bVar5 + in_AF * '\x06' & 0xf;
          unaff_DS = *puVar17;
          in_ESP = (uint *)CONCAT22(uVar27,puVar17 + 1);
          pbVar2 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
          in_CF = bVar5 < *pbVar2 || bVar5 == *pbVar2;
          goto code_r0x000139b6;
        }
        puVar23 = puVar24 + -2;
        *(undefined2 *)(puVar24 + -2) = 0x3b42;
        uVar7 = FUN_1000_3607();
        cVar11 = (char)in_CX;
        if (bVar29) {
          puVar25 = puVar23 + -2;
          *(undefined2 *)(puVar23 + -2) = 0x3b47;
LAB_1000_37ea_2:
          if (cVar11 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
            puVar14 = (undefined2 *)(puVar25 + -2);
            puVar25 = puVar25 + -2;
            *puVar14 = 0x37f3;
            func_0x0001b6c0();
          }
          return *(uint *)(puVar25 + 0xe);
        }
LAB_1000_3b55_1:
        uVar8 = CONCAT11((char)((uint)uVar7 >> 8),(char)uVar7 + -0x80) | 1;
code_r0x00013b57:
        *(byte *)puVar28 = (byte)*puVar28 | 1;
        return uVar8;
      }
      puVar26 = (uint *)ZEXT24((undefined1 *)((int)puVar22 + -2));
      *(undefined2 *)((int)puVar22 + -2) = unaff_CS;
      iVar10 = CONCAT11(cVar11 - *(byte *)((int)puVar28 + uVar12 + 0x23c9),
                        (char)((ulong)uVar35 >> 0x10) + bVar9 +
                        (0x1fd2 < uVar6 || CARRY2(uVar8 + 0xe02d,uVar3)));
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar2 = *pbVar2 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar34 == '\0') {
      *(byte *)((int)puVar28 + 0xb) = *(byte *)((int)puVar28 + 0xb) + cVar11;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)puVar28[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(puVar28 + 5) = (byte)(uVar12 >> 8);
LAB_1000_3b12:
  return *(uint *)((int)puVar22 + 0xe);
}


