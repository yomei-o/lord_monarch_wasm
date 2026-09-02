/* 1000:38ed */

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

uint FUN_1000_38ed(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  uint uVar7;
  byte bVar9;
  undefined2 uVar8;
  uint in_CX;
  byte bVar10;
  undefined2 extraout_DX;
  uint in_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar11;
  uint in_BX;
  uint uVar12;
  undefined2 *puVar13;
  undefined1 *puVar14;
  uint *puVar15;
  uint *puVar16;
  undefined1 *puVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  uint *in_ESP;
  undefined2 uVar26;
  uint *puVar25;
  uint unaff_BP;
  uint *unaff_SI;
  uint *puVar27;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  byte in_AF;
  undefined1 uVar28;
  bool bVar29;
  bool bVar30;
  char cVar31;
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
  
  *(byte *)0xe872 = *(byte *)0xe872 | (byte)in_DX;
code_r0x000138f1:
  puVar15 = (uint *)in_ESP;
  uVar26 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar25 = unaff_DI;
  unaff_DI = (uint *)((int)unaff_DI + 1);
  *(byte *)puVar25 = 0x30;
  uVar7 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
  *puVar15 = in_BX;
  puVar15[-1] = uVar7;
  in_BX = unaff_SI[0x15];
  in_DX = (in_DX | 0x3000) - *(int *)(byte *)(in_BX + (int)unaff_SI);
  bVar9 = (byte)(uVar7 >> 8);
  bVar6 = (char)uVar7 + 8;
  if (bVar6 != *(byte *)(in_BX + 0xd27e)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  puVar15[-2] = CONCAT11(bVar9,bVar6);
  puVar15[-3] = in_CX;
  puVar15[-4] = in_DX;
  puVar15[-5] = in_BX;
  puVar15[-6] = (uint)(puVar15 + -1);
  puVar15[-7] = unaff_BP;
  puVar15[-8] = (uint)unaff_SI;
  puVar15[-9] = (uint)unaff_DI;
  uVar7 = *unaff_DI;
  cVar31 = (char)(in_CX >> 8);
  bVar10 = cVar31 + bVar6;
  in_CX = CONCAT11(bVar10,(char)in_CX);
  unaff_BP = 0x874;
  if (SCARRY1(cVar31,bVar6)) {
    puVar21 = (uint *)puVar15[-9];
    unaff_SI = *(uint **)(byte *)((int)unaff_DI + (in_BX - 0x18));
    puVar25 = unaff_SI + 0x43a;
    uVar12 = *puVar25;
    *puVar25 = *puVar25 + 0x809;
    in_CX = 0x4379;
    unaff_SI[0x43a] =
         unaff_SI[0x43a] + CONCAT11(bVar9 | (byte)uVar7,bVar6 | bVar10) + (uint)(0xf7f6 < uVar12);
  }
  else {
    puVar15[-10] = 0x874;
    puVar21 = puVar15 + -0xb;
    puVar15[-0xb] = 0x874;
  }
LAB_1000_3958:
  *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + in_DX;
  puVar27 = (uint *)((int)unaff_SI + 1);
  out((byte)*unaff_SI,in_DX);
  uVar7 = CONCAT11((byte)(in_BX >> 8) & *(byte *)((int)puVar27 + unaff_BP + 0x11),(char)in_BX);
  bVar9 = (byte)in_DX;
  cVar34 = SBORROW1(bVar9,(byte)unaff_SI[0x39]);
  bVar6 = (byte)unaff_SI[0x39];
  cVar31 = (char)(bVar9 - bVar6) < '\0';
  bVar29 = bVar9 == bVar6;
  puVar16 = (uint *)((int)puVar21 + -2);
  *(undefined2 *)((int)puVar21 + -2) = 0x396b;
  bVar6 = func_0x0001b3ed();
  iVar11 = extraout_DX_00;
  if (!bVar29) {
    *(byte *)(unaff_SI + 6) = bVar6;
    *(undefined2 *)((int)puVar16 + -2) = 0x3973;
    puVar16 = (uint *)((int)puVar16 + -2);
    bVar6 = func_0x0001b617();
    iVar11 = extraout_DX_01;
  }
  if (cVar34 != cVar31) {
    iVar11 = iVar11 + 1;
    puVar16[-1] = (uint)unaff_DI;
    puVar16[-2] = iVar11;
    puVar16[-3] = CONCAT11((char)(in_CX >> 8),8);
    puVar16[-4] = uVar7;
    if (iVar11 == 0) {
LAB_1000_39c7:
      pcVar5 = (code *)swi(1);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
    *pbVar1 = *pbVar1 | (byte)((uint)iVar11 >> 8);
code_r0x00013985:
    pbVar1 = (byte *)((int)unaff_DI + uVar7 + 0x12);
    *(byte **)pbVar1 = (byte *)((int)unaff_DI + *(int *)pbVar1 + 2);
    puVar17 = (undefined1 *)0x2e1c;
    *(undefined2 *)0x2e1c = 0x3990;
    FUN_1000_8d53();
    *(undefined2 *)(puVar17 + -2) = 0x399f;
    func_0x00018e51();
    pcVar5 = (code *)swi(3);
    uVar7 = (*pcVar5)();
    return uVar7;
  }
  bVar6 = bVar6 ^ *(byte *)(unaff_BP + (int)puVar27);
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * '\x06' & 0xf;
  unaff_DS = *puVar16;
  pbVar1 = (byte *)((int)puVar27 + unaff_BP + 0x8b5f);
  bVar29 = bVar6 < *pbVar1 || bVar6 == *pbVar1;
  puVar25 = (uint *)CONCAT22(uVar26,puVar16);
  *puVar16 = 0x39ba;
  uVar35 = FUN_1000_a1b8();
  uVar12 = (uint)uVar35;
  if (bVar29) {
    if (in_CX == 1) {
      do {
        iVar11 = 0x40;
        uVar7 = uVar12;
        do {
          uVar12 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
          puVar21 = puVar27;
          if (((*puVar27 & 0x80) == 0) && ((puVar27[5] & 0x20) != 0)) {
            puVar25 = puVar25 + -2;
            *puVar25 = unaff_DS;
            bVar6 = (byte)uVar7 | 0x17;
            bVar9 = (byte)(uVar7 >> 8);
            if (bVar9 == (byte)puVar27[6]) {
              uVar7 = CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
              puVar21 = unaff_DI;
              goto code_r0x00013a16;
            }
            uVar12 = CONCAT11(bVar9 & *(byte *)(unaff_BP + (int)puVar27),(byte)uVar7) | 0x17;
            *(byte *)(puVar27 + 0x3931) = (byte)puVar27[0x3931] ^ (byte)((uint)iVar11 >> 8);
            *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
            in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
            uVar7 = *(uint *)puVar25;
            puVar25 = (uint *)CONCAT22((int)((ulong)puVar25 >> 0x10),(uint *)puVar25 + 1);
            puVar21 = puVar27 + 8;
            unaff_DI = puVar27;
          }
          iVar11 = iVar11 + -1;
          puVar27 = puVar21;
        } while (iVar11 != 0);
        puVar27 = (uint *)*(uint *)puVar25;
        puVar25 = (uint *)CONCAT22((int)((ulong)puVar25 >> 0x10),(uint *)puVar25 + 1);
        puVar21 = unaff_DI;
code_r0x00013a16:
        puVar18 = (uint *)puVar25;
        uVar26 = (undefined2)((ulong)puVar25 >> 0x10);
        if (0x1ef < uVar12) goto code_r0x00013a1c;
        pbVar1 = (byte *)((int)puVar21 + unaff_BP + 0x59);
        *pbVar1 = *pbVar1 | (byte)uVar12;
        bVar6 = *(byte *)(uVar12 + puVar18[1]);
        puVar18[1] = (uint)puVar27;
        *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar12 + ((byte)((char)unaff_BP + 1U) < bVar6);
        uVar12 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
        unaff_DI = (uint *)puVar18[1];
        puVar25 = (uint *)CONCAT22(uVar26,puVar18 + 2);
        puVar27 = (uint *)0xc800;
        unaff_BP = uVar7;
      } while( true );
    }
    goto code_r0x00013985;
  }
  out((int)((ulong)uVar35 >> 0x10),(char)uVar35);
  puVar2 = puVar27;
  bVar29 = CARRY2(*puVar2,uVar12);
  *puVar2 = *puVar2 + uVar12;
  bVar32 = (int)*puVar2 < 0;
  bVar30 = *puVar2 == 0;
  bVar6 = POPCOUNT(*puVar2 & 0xff);
  in_CX = in_CX - 1;
  if (in_CX == 0 || bVar30) goto LAB_1000_39c7;
  goto LAB_1000_3a35;
LAB_1000_381b:
  bVar6 = (byte)uVar7;
  bVar29 = bVar6 < 0x10;
  bVar33 = SBORROW1(bVar6,'\x10');
  bVar32 = (char)(bVar6 - 0x10) < '\0';
  bVar30 = bVar6 == 0x10;
  if (!bVar29) {
    cVar31 = '\x04';
    if (7 < bVar6) {
      bVar33 = SBORROW1(bVar6,'\f');
      bVar32 = (char)(bVar6 - 0xc) < '\0';
      bVar30 = bVar6 == 0xc;
      bVar29 = true;
      if (bVar6 < 0xc) goto LAB_1000_383e;
    }
    cVar31 = '\b';
    if (bVar6 != 0) {
      bVar33 = SBORROW1(bVar6,'\x05');
      bVar32 = (char)(bVar6 - 5) < '\0';
      bVar30 = bVar6 == 5;
      bVar29 = true;
      if (bVar6 < 5) goto LAB_1000_383e;
    }
    cVar31 = '\v';
    bVar29 = bVar6 < 5;
    bVar33 = SBORROW1(bVar6,'\x05');
    bVar32 = (char)(bVar6 - 5) < '\0';
    bVar30 = bVar6 == 5;
    if (!bVar30) {
      in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar1 = (byte *)(in_BX + (int)unaff_SI);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 == 0) goto FUN_1000_38de;
      in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
      pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x854);
      *pbVar1 = *pbVar1 & 0xb;
      uVar28 = *pbVar1 == 0;
      puVar14 = (undefined1 *)0x322e;
      *(undefined2 *)0x322e = 0x3877;
      func_0x0001ab45();
      puVar21 = (uint *)(puVar14 + -2);
      *(undefined2 *)(puVar14 + -2) = 0x387a;
      uVar35 = func_0x0001b476();
      in_DX = (uint)((ulong)uVar35 >> 0x10);
      if (!(bool)uVar28) {
        *(byte *)((int)unaff_SI + 0xb) = (byte)uVar35;
      }
      uVar7 = CONCAT11((char)((ulong)uVar35 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
      bVar6 = (byte)uVar7;
      *(byte *)(unaff_SI + 5) = bVar6;
      swi(4);
      pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
      *pbVar1 = *pbVar1 + bVar6;
      if ((POPCOUNT(*pbVar1) & 1U) != 0) {
        pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x33);
        bVar6 = *pbVar1;
        bVar10 = (byte)((ulong)uVar35 >> 0x10);
        bVar9 = *pbVar1;
        cVar31 = (char)((ulong)uVar35 >> 0x18) + *(byte *)(in_BX + (int)unaff_SI);
        *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar31;
        pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
        *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar31,bVar10 + bVar9),
                                            (uVar7 + 0x5556) - (uint)CARRY1(bVar10,bVar6)) %
                                  (ulong)unaff_SI[0x410]);
        *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
             *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
        return *puVar21;
      }
      if (*pbVar1 != 0) goto code_r0x000138e6;
      goto LAB_1000_3958;
    }
  }
LAB_1000_383e:
  if (bVar29) {
    *(undefined2 *)(puVar24 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar30 && bVar33 == bVar32) {
    return *(uint *)(unaff_BP + 0xe);
  }
  goto LAB_1000_37ea_2;
code_r0x00013a1c:
  unaff_SS = *puVar18;
  *(longdouble *)(uVar12 + (int)puVar21) = in_ST0;
  puVar25 = (uint *)CONCAT22(uVar26,(uint *)(puVar18[1] + -2));
  *(undefined2 *)(puVar18[1] + -2) = unaff_ES;
  uVar7 = puVar21[2];
  uVar12 = (uint)*(byte *)((int)puVar21 + -0x79);
  bVar29 = (byte)iVar11 < *(byte *)(unaff_BP + (int)puVar27);
  cVar31 = (byte)iVar11 - *(byte *)(unaff_BP + (int)puVar27);
  in_CX = CONCAT11((char)((uint)iVar11 >> 8),cVar31);
  bVar32 = cVar31 < '\0';
  bVar30 = cVar31 == '\0';
  bVar6 = POPCOUNT(cVar31);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar21;
  UNLOCK();
  in_ST0 = in_ST1;
  in_ST1 = in_ST2;
  in_ST2 = in_ST3;
  in_ST3 = in_ST4;
  in_ST4 = in_ST5;
  in_ST5 = in_ST6;
  in_ST6 = in_ST7;
LAB_1000_3a35:
  if (bVar30) {
    *(byte *)(uVar7 + (int)puVar27) = *(byte *)(uVar7 + (int)puVar27) + 1;
    puVar19 = (uint *)puVar25;
    puVar25 = (uint *)CONCAT22((int)((ulong)puVar25 >> 0x10),puVar19 + -1);
    puVar19[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar32 << 7 | bVar30 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar29,(char)uVar12)) {
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar1 = *pbVar1 | (byte)(uVar7 >> 8);
      puVar2 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar2 = (char)uVar12 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar1 = (byte *)((uVar7 >> 2) + (int)puVar27);
    *pbVar1 = *pbVar1 - 0x15;
    puVar2 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar12 = *puVar2;
    *puVar2 = *puVar2 - in_CX;
    bVar6 = ((char)(uVar7 >> 1) + (char)(uVar7 >> 2) + -0x10) - (uVar12 < in_CX) | 2;
    iVar11 = *(int *)(byte *)((int)unaff_DI + 0x55);
    unaff_SI = puVar27;
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar6;
    ((uint *)puVar25)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)in_CX;
    puVar21 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar11 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    uVar7 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar7 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar5 = (code *)swi(0x20);
    (*pcVar5)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar7 >> 8);
    puVar20 = (uint *)puVar25;
    uVar26 = (undefined2)((ulong)puVar25 >> 0x10);
    puVar20[-1] = unaff_ES;
    pbVar1 = (byte *)((int)puVar27 + uVar7 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
    unaff_DI = (uint *)puVar20[-1];
    unaff_SI = (uint *)*puVar20;
    unaff_BP = puVar20[1];
    in_CX = puVar20[5];
    uVar8 = puVar20[6];
    uVar7 = CONCAT11((char)(puVar20[3] >> 8),(byte)puVar20[3] | *(byte *)0x5d02) |
            *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar20[6] = (uint)unaff_DI;
    pbVar1 = (byte *)((int)unaff_SI + uVar7 + 0x2c2);
    cVar34 = SCARRY1((char)uVar8,*pbVar1);
    bVar29 = (char)((char)uVar8 + *pbVar1) < '\0';
    puVar21 = puVar20 + 5;
    puVar20[5] = 0x3a83;
    uVar35 = func_0x00013e95();
    bVar6 = (byte)uVar35;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar7;
    cVar31 = (char)((ulong)uVar35 >> 0x18);
    if (bVar29) {
      bVar10 = (byte)(uVar7 >> 8);
      puVar25 = (uint *)((int)unaff_DI + -0x53);
      uVar4 = (uint)(bVar10 < (byte)(in_CX >> 8));
      uVar12 = *puVar25;
      uVar3 = *puVar25;
      *puVar25 = uVar3 + 0xe02d + uVar4;
      bVar9 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar10 = bVar10 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar35 >> 8);
      in_BX = CONCAT11(bVar10,(char)uVar7);
      if ((char)bVar10 < '\0') {
        bVar29 = unaff_SI[3] < 1000;
        if (!bVar29) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar21 + -2) = 0x3b26;
          puVar21 = (uint *)((int)puVar21 + -2);
          uVar8 = func_0x00013966();
          if (!bVar29) goto LAB_1000_3b55_1;
        }
        puVar23 = (undefined1 *)((int)puVar21 + -2);
        *(undefined2 *)((int)puVar21 + -2) = 0x3b2d;
        uVar35 = FUN_1000_8cb7();
        in_DX = (uint)((ulong)uVar35 >> 0x10);
        uVar7 = (uint)uVar35;
        bVar29 = (byte)uVar35 < 0x5a;
        if (bVar29) {
          bVar29 = true;
          if ((byte)uVar35 < 0x50) {
            do {
              puVar24 = puVar23;
              if (bVar29) {
                puVar24 = puVar23 + -2;
                *(undefined2 *)(puVar23 + -2) = 0x3b67;
                uVar7 = func_0x000137e6();
                cVar31 = (char)in_CX;
                if (bVar29) goto LAB_1000_381b;
              }
              if (*(int *)0x3480 != 0) goto code_r0x00013b57;
              *(uint *)(puVar24 + -2) = unaff_BP;
              puVar23 = puVar24 + -4;
              *(uint *)(puVar24 + -4) = unaff_BP;
              pbVar1 = (byte *)(in_BX + (int)unaff_SI);
              bVar6 = (byte)(uVar7 >> 8);
              bVar29 = CARRY1(*pbVar1,bVar6);
              *pbVar1 = *pbVar1 + bVar6;
              in_BX = in_BX - 1;
            } while( true );
          }
          puVar21 = (uint *)(puVar23 + -2);
          *(undefined2 *)(puVar23 + -2) = 0x3b38;
          bVar29 = false;
          while( true ) {
            in_ESP = (uint *)CONCAT22(uVar26,(uint *)((int)puVar21 + -2));
            *(undefined2 *)((int)puVar21 + -2) = unaff_SS;
            if (!bVar29) break;
            in_BX = in_BX + 1;
            puVar24 = (undefined1 *)((int)puVar21 + -4);
            *(undefined2 *)((int)puVar21 + -4) = 0x810;
            *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)in_DX;
FUN_1000_38de:
            puVar21 = (uint *)(puVar24 + -2);
            *(undefined2 *)(puVar24 + -2) = 0x38e1;
            FUN_1000_7494();
            *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)in_CX;
            LOCK();
            uVar28 = *(undefined1 *)(unaff_BP + 0x72);
            *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
            in_DX = CONCAT11(uVar28,(char)extraout_DX);
            UNLOCK();
code_r0x000138e6:
            *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
            bVar29 = CARRY1((byte)in_BX,*(byte *)(unaff_BP + (int)unaff_SI));
            in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)(unaff_BP + (int)unaff_SI));
          }
          goto code_r0x000138f1;
        }
        puVar22 = puVar23 + -2;
        *(undefined2 *)(puVar23 + -2) = 0x3b42;
        uVar8 = FUN_1000_3607();
        cVar31 = (char)in_CX;
        if (bVar29) {
          puVar24 = puVar22 + -2;
          *(undefined2 *)(puVar22 + -2) = 0x3b47;
LAB_1000_37ea_2:
          if (cVar31 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
            puVar13 = (undefined2 *)(puVar24 + -2);
            puVar24 = puVar24 + -2;
            *puVar13 = 0x37f3;
            func_0x0001b6c0();
          }
          return *(uint *)(puVar24 + 0xe);
        }
LAB_1000_3b55_1:
        uVar7 = CONCAT11((char)((uint)uVar8 >> 8),(char)uVar8 + -0x80) | 1;
code_r0x00013b57:
        *(byte *)unaff_SI = (byte)*unaff_SI | 1;
        return uVar7;
      }
      puVar25 = (uint *)ZEXT24((undefined1 *)((int)puVar21 + -2));
      *(undefined2 *)((int)puVar21 + -2) = unaff_CS;
      iVar11 = CONCAT11(cVar31 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar35 >> 0x10) + bVar9 +
                        (0x1fd2 < uVar12 || CARRY2(uVar3 + 0xe02d,uVar4)));
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar1 = *pbVar1 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar34 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar31;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar7 >> 8);
LAB_1000_3b12:
  return *(uint *)((int)puVar21 + 0xe);
}


