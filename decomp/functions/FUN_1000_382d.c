/* 1000:382d */

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

ulong FUN_1000_382d(void)

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
  char in_CL;
  byte bVar11;
  uint uVar10;
  char cVar13;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar12;
  uint in_BX;
  uint uVar14;
  undefined2 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined2 *puVar18;
  undefined2 *puVar19;
  uint *puVar20;
  undefined1 *puVar21;
  uint *puVar22;
  uint *puVar23;
  uint *puVar24;
  uint *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *in_ESP;
  uint *puVar30;
  undefined2 uVar31;
  uint unaff_BP;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar32;
  byte in_AF;
  bool bVar33;
  undefined1 uVar34;
  bool bVar35;
  bool bVar36;
  char cVar37;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar38;
  ulong uVar39;
  
code_r0x0001382d:
  bVar6 = (byte)in_AX;
  if (bVar6 != 0) {
    bVar36 = SBORROW1(bVar6,'\x05');
    bVar35 = (char)(bVar6 - 5) < '\0';
    bVar33 = bVar6 == 5;
    bVar32 = true;
    if (bVar6 < 5) {
LAB_1000_383e:
      puVar16 = (undefined1 *)in_ESP;
      if (bVar32) {
        *(undefined2 *)(puVar16 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (!bVar33 && bVar36 == bVar35) {
        return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
      }
LAB_1000_37ea_2:
      if (in_CL == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
        puVar15 = (undefined2 *)(puVar16 + -2);
        puVar16 = puVar16 + -2;
        *puVar15 = 0x37f3;
        func_0x0001b6c0();
      }
      return CONCAT22(*(undefined2 *)(puVar16 + 10),*(undefined2 *)(puVar16 + 0xe));
    }
  }
  in_CL = '\v';
  bVar32 = bVar6 < 5;
  bVar36 = SBORROW1(bVar6,'\x05');
  bVar35 = (char)(bVar6 - 5) < '\0';
  bVar33 = bVar6 == 5;
  if (!bVar33) {
    uVar10 = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
    pbVar2 = (byte *)(in_BX + (int)unaff_SI);
    *pbVar2 = *pbVar2 & 0xb;
    if (*pbVar2 == 0) goto FUN_1000_38de;
    in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
    uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
    pbVar2 = (byte *)((int)unaff_DI + in_BX + 0x854);
    *pbVar2 = *pbVar2 & 0xb;
    uVar34 = *pbVar2 == 0;
    puVar17 = (undefined1 *)0x322e;
    *(undefined2 *)0x322e = 0x3877;
    func_0x0001ab45();
    puVar18 = (undefined2 *)(puVar17 + -2);
    *(undefined2 *)(puVar17 + -2) = 0x387a;
    uVar38 = func_0x0001b476();
    uVar14 = (uint)((ulong)uVar38 >> 0x10);
    if (!(bool)uVar34) {
      *(byte *)((int)unaff_SI + 0xb) = (byte)uVar38;
    }
    uVar7 = CONCAT11((char)((ulong)uVar38 >> 8),(byte)unaff_SI[5]) & 0xffd0 | 5;
    bVar6 = (byte)uVar7;
    *(byte *)(unaff_SI + 5) = bVar6;
    swi(4);
    pbVar2 = (byte *)(unaff_BP + (int)unaff_SI);
    *pbVar2 = *pbVar2 + bVar6;
    if ((POPCOUNT(*pbVar2) & 1U) != 0) {
      pbVar2 = (byte *)((int)unaff_SI + in_BX + 0x33);
      bVar6 = *pbVar2;
      bVar11 = (byte)((ulong)uVar38 >> 0x10);
      bVar9 = *pbVar2;
      cVar13 = (char)((ulong)uVar38 >> 0x18) + *(byte *)(in_BX + (int)unaff_SI);
      *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar13;
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
      *pbVar2 = *pbVar2 | (byte)(CONCAT22(CONCAT11(cVar13,bVar11 + bVar9),
                                          (uVar7 + 0x5556) - (uint)CARRY1(bVar11,bVar6)) %
                                (ulong)unaff_SI[0x410]);
      *(int *)(byte *)(unaff_BP + (int)unaff_DI) =
           *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
      return CONCAT22(puVar18[1],*puVar18);
    }
    puVar25 = unaff_SI;
    puVar19 = puVar18;
    if (*pbVar2 == 0) goto LAB_1000_3958;
    do {
      *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
      bVar32 = CARRY1((byte)in_BX,*(byte *)(unaff_BP + (int)unaff_SI));
      in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)(unaff_BP + (int)unaff_SI));
code_r0x000138eb:
      *(undefined2 *)((int)puVar18 + -2) = unaff_SS;
      if (!bVar32) {
        puVar30 = unaff_DI;
        unaff_DI = (uint *)((int)unaff_DI + 1);
        *(byte *)puVar30 = 0x30;
        uVar7 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
        *(uint *)((int)puVar18 + -2) = in_BX;
        *(uint *)((int)puVar18 + -4) = uVar7;
        in_BX = unaff_SI[0x15];
        uVar14 = (uVar14 | 0x3000) - *(int *)(byte *)(in_BX + (int)unaff_SI);
        bVar9 = (byte)(uVar7 >> 8);
        bVar6 = (char)uVar7 + 8;
        if (bVar6 != *(byte *)(in_BX + 0xd27e)) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        *(undefined2 *)((int)puVar18 + -6) = CONCAT11(bVar9,bVar6);
        *(uint *)((int)puVar18 + -8) = uVar10;
        *(uint *)((int)puVar18 + -10) = uVar14;
        *(uint *)((int)puVar18 + -0xc) = in_BX;
        *(undefined1 **)(undefined1 *)((int)puVar18 + -0xe) = (undefined1 *)((int)puVar18 + -4);
        *(uint *)((int)puVar18 + -0x10) = unaff_BP;
        *(undefined2 *)((int)puVar18 + -0x12) = unaff_SI;
        *(undefined2 *)((int)puVar18 + -0x14) = unaff_DI;
        uVar7 = *unaff_DI;
        cVar13 = (char)(uVar10 >> 8);
        bVar11 = cVar13 + bVar6;
        uVar10 = CONCAT11(bVar11,(char)uVar10);
        unaff_BP = 0x874;
        if (SCARRY1(cVar13,bVar6)) {
          puVar19 = (undefined2 *)*(undefined2 *)((int)puVar18 + -0x14);
          puVar25 = *(uint **)(byte *)((int)unaff_DI + (in_BX - 0x18));
          puVar30 = puVar25 + 0x43a;
          uVar3 = *puVar30;
          *puVar30 = *puVar30 + 0x809;
          uVar10 = 0x4379;
          puVar25[0x43a] =
               puVar25[0x43a] + CONCAT11(bVar9 | (byte)uVar7,bVar6 | bVar11) +
               (uint)(0xf7f6 < uVar3);
        }
        else {
          *(undefined2 *)((int)puVar18 + -0x16) = 0x874;
          puVar19 = (undefined2 *)((int)puVar18 + -0x18);
          *(undefined2 *)((int)puVar18 + -0x18) = 0x874;
          puVar25 = unaff_SI;
        }
LAB_1000_3958:
        *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + uVar14;
        unaff_SI = (uint *)((int)puVar25 + 1);
        out((byte)*puVar25,uVar14);
        uVar7 = CONCAT11((byte)(in_BX >> 8) & *(byte *)((int)unaff_SI + unaff_BP + 0x11),(char)in_BX
                        );
        bVar9 = (byte)uVar14;
        cVar37 = SBORROW1(bVar9,(byte)puVar25[0x39]);
        bVar6 = (byte)puVar25[0x39];
        cVar13 = (char)(bVar9 - bVar6) < '\0';
        bVar32 = bVar9 == bVar6;
        puVar20 = (uint *)((int)puVar19 + -2);
        *(undefined2 *)((int)puVar19 + -2) = 0x396b;
        bVar6 = func_0x0001b3ed();
        iVar12 = extraout_DX_00;
        if (!bVar32) {
          *(byte *)(puVar25 + 6) = bVar6;
          *(undefined2 *)((int)puVar20 + -2) = 0x3973;
          puVar20 = (uint *)((int)puVar20 + -2);
          bVar6 = func_0x0001b617();
          iVar12 = extraout_DX_01;
        }
        if (cVar37 != cVar13) {
          iVar12 = iVar12 + 1;
          puVar20[-1] = (uint)unaff_DI;
          puVar20[-2] = iVar12;
          puVar20[-3] = CONCAT11((char)(uVar10 >> 8),8);
          puVar20[-4] = uVar7;
          if (iVar12 == 0) {
LAB_1000_39c7:
            pcVar5 = (code *)swi(1);
            uVar39 = (*pcVar5)();
            return uVar39;
          }
          pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
          *pbVar2 = *pbVar2 | (byte)((uint)iVar12 >> 8);
code_r0x00013985:
          pbVar2 = (byte *)((int)unaff_DI + uVar7 + 0x12);
          *(byte **)pbVar2 = (byte *)((int)unaff_DI + *(int *)pbVar2 + 2);
          puVar21 = (undefined1 *)0x2e1c;
          *(undefined2 *)0x2e1c = 0x3990;
          FUN_1000_8d53();
          *(undefined2 *)(puVar21 + -2) = 0x399f;
          func_0x00018e51();
          pcVar5 = (code *)swi(3);
          uVar39 = (*pcVar5)();
          return uVar39;
        }
        bVar6 = bVar6 ^ *(byte *)(unaff_BP + (int)unaff_SI);
        in_AF = 9 < (bVar6 & 0xf) | in_AF;
        bVar6 = bVar6 + in_AF * '\x06' & 0xf;
        unaff_DS = *puVar20;
        pbVar2 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
        bVar32 = bVar6 < *pbVar2 || bVar6 == *pbVar2;
        puVar30 = (uint *)CONCAT22(uVar8,puVar20);
        *puVar20 = 0x39ba;
        uVar38 = FUN_1000_a1b8();
        uVar14 = (uint)uVar38;
        if (bVar32) {
          if (uVar10 == 1) {
            do {
              iVar12 = 0x40;
              uVar10 = uVar14;
              do {
                uVar14 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
                puVar25 = unaff_SI;
                if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
                  puVar30 = puVar30 + -2;
                  *puVar30 = unaff_DS;
                  bVar6 = (byte)uVar10 | 0x17;
                  bVar9 = (byte)(uVar10 >> 8);
                  if (bVar9 == (byte)unaff_SI[6]) {
                    uVar10 = CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
                    puVar25 = unaff_DI;
                    goto code_r0x00013a16;
                  }
                  uVar14 = CONCAT11(bVar9 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)uVar10) | 0x17
                  ;
                  *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar12 >> 8);
                  *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
                  in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
                  uVar10 = *(uint *)puVar30;
                  puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),(uint *)puVar30 + 1);
                  puVar25 = unaff_SI + 8;
                  unaff_DI = unaff_SI;
                }
                iVar12 = iVar12 + -1;
                unaff_SI = puVar25;
              } while (iVar12 != 0);
              unaff_SI = (uint *)*(uint *)puVar30;
              puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),(uint *)puVar30 + 1);
              puVar25 = unaff_DI;
code_r0x00013a16:
              uVar8 = (undefined2)((ulong)puVar30 >> 0x10);
              puVar22 = (uint *)puVar30;
              if (0x1ef < uVar14) goto code_r0x00013a1c;
              pbVar2 = (byte *)((int)puVar25 + unaff_BP + 0x59);
              *pbVar2 = *pbVar2 | (byte)uVar14;
              bVar6 = *(byte *)(uVar14 + puVar22[1]);
              puVar22[1] = (uint)unaff_SI;
              *(char *)0xaaaa =
                   *(char *)0xaaaa + (byte)uVar14 + ((byte)((char)unaff_BP + 1U) < bVar6);
              uVar14 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
              unaff_DI = (uint *)puVar22[1];
              puVar30 = (uint *)CONCAT22(uVar8,puVar22 + 2);
              unaff_SI = (uint *)0xc800;
              unaff_BP = uVar10;
            } while( true );
          }
          goto code_r0x00013985;
        }
        out((int)((ulong)uVar38 >> 0x10),(char)uVar38);
        puVar1 = unaff_SI;
        bVar32 = CARRY2(*puVar1,uVar14);
        *puVar1 = *puVar1 + uVar14;
        bVar35 = (int)*puVar1 < 0;
        bVar33 = *puVar1 == 0;
        bVar6 = POPCOUNT(*puVar1 & 0xff);
        uVar10 = uVar10 - 1;
        if (uVar10 == 0 || bVar33) goto LAB_1000_39c7;
        goto LAB_1000_3a35;
      }
      in_BX = in_BX + 1;
      in_ESP = (undefined1 *)CONCAT22(uVar8,(undefined1 *)((int)puVar18 + -4));
      *(undefined2 *)((int)puVar18 + -4) = 0x810;
      *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)uVar14;
FUN_1000_38de:
      uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
      puVar18 = (undefined2 *)((undefined1 *)in_ESP + -2);
      *(undefined2 *)((undefined1 *)in_ESP + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)uVar10;
      LOCK();
      uVar34 = *(undefined1 *)(unaff_BP + 0x72);
      *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
      uVar14 = CONCAT11(uVar34,(char)extraout_DX);
      UNLOCK();
    } while( true );
  }
  goto LAB_1000_383e;
LAB_1000_3b62:
  if (bVar32) {
    puVar29 = (undefined1 *)in_ESP;
    in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar29 + -2);
    *(undefined2 *)(puVar29 + -2) = 0x3b67;
    uVar39 = func_0x000137e6();
    in_AX = (undefined2)uVar39;
    in_CL = (char)uVar10;
    if (bVar32) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar39;
  }
  puVar28 = (undefined1 *)in_ESP;
  *(uint *)(puVar28 + -2) = unaff_BP;
  in_ESP = (undefined1 *)CONCAT22((int)((ulong)in_ESP >> 0x10),puVar28 + -4);
  *(uint *)(puVar28 + -4) = unaff_BP;
  pbVar2 = (byte *)(in_BX + (int)unaff_SI);
  bVar6 = (byte)(uVar39 >> 8);
  bVar32 = CARRY1(*pbVar2,bVar6);
  *pbVar2 = *pbVar2 + bVar6;
  in_BX = in_BX - 1;
  goto LAB_1000_3b62;
LAB_1000_381b:
  bVar6 = (byte)uVar39;
  bVar36 = SBORROW1(bVar6,'\x10');
  bVar35 = (char)(bVar6 - 0x10) < '\0';
  bVar33 = bVar6 == 0x10;
  bVar32 = true;
  if (bVar6 < 0x10) goto LAB_1000_383e;
  in_CL = '\x04';
  if (7 < bVar6) {
    bVar36 = SBORROW1(bVar6,'\f');
    bVar35 = (char)(bVar6 - 0xc) < '\0';
    bVar33 = bVar6 == 0xc;
    bVar32 = true;
    if (bVar6 < 0xc) goto LAB_1000_383e;
  }
  in_CL = '\b';
  goto code_r0x0001382d;
code_r0x00013a1c:
  unaff_SS = *puVar22;
  *(longdouble *)(uVar14 + (int)puVar25) = in_ST0;
  puVar30 = (uint *)CONCAT22(uVar8,(uint *)(puVar22[1] + -2));
  *(undefined2 *)(puVar22[1] + -2) = unaff_ES;
  uVar7 = puVar25[2];
  uVar14 = (uint)*(byte *)((int)puVar25 + -0x79);
  bVar32 = (byte)iVar12 < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar13 = (byte)iVar12 - *(byte *)(unaff_BP + (int)unaff_SI);
  uVar10 = CONCAT11((char)((uint)iVar12 >> 8),cVar13);
  bVar35 = cVar13 < '\0';
  bVar33 = cVar13 == '\0';
  bVar6 = POPCOUNT(cVar13);
  LOCK();
  unaff_DI = (uint *)*(undefined2 *)(unaff_BP - 0x2e);
  *(undefined2 *)(unaff_BP - 0x2e) = puVar25;
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
    puVar23 = (uint *)puVar30;
    puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),puVar23 + -1);
    puVar23[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar35 << 7 | bVar33 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar32,(char)uVar14)) {
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar2 = *pbVar2 | (byte)(uVar7 >> 8);
      puVar1 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar1 = (char)uVar14 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + uVar10;
    pbVar2 = (byte *)((uVar7 >> 2) + (int)unaff_SI);
    *pbVar2 = *pbVar2 - 0x15;
    puVar1 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar14 = *puVar1;
    *puVar1 = *puVar1 - uVar10;
    bVar6 = ((char)(uVar7 >> 1) + (char)(uVar7 >> 2) + -0x10) - (uVar14 < uVar10) | 2;
    iVar12 = *(int *)(byte *)((int)unaff_DI + 0x55);
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar6;
    ((uint *)puVar30)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)uVar10;
    puVar25 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar12 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar39 = (*pcVar5)();
      return uVar39;
    }
    uVar14 = CONCAT11(1,*(undefined1 *)0x3c00);
    if (((*unaff_SI & 0x80) != 0) || (*(byte *)((int)unaff_SI + 0xb) != 0xff)) goto LAB_1000_3b12;
    if ((byte)unaff_SI[5] != 0) {
code_r0x00013b04:
      if ((byte)uVar14 == (byte)unaff_SI[6]) goto LAB_1000_3b12;
      goto code_r0x00013b09;
    }
  }
  else {
LAB_1000_3a63:
    pcVar5 = (code *)swi(0x20);
    (*pcVar5)();
    *(byte *)0x7479 = *(byte *)0x7479 | (byte)(uVar7 >> 8);
    puVar24 = (uint *)puVar30;
    uVar31 = (undefined2)((ulong)puVar30 >> 0x10);
    puVar24[-1] = unaff_ES;
    pbVar2 = (byte *)((int)unaff_SI + uVar7 + 0x222);
    *(byte **)pbVar2 = (byte *)(*(int *)pbVar2 + (int)unaff_DI);
    unaff_DI = (uint *)puVar24[-1];
    unaff_SI = (uint *)*puVar24;
    unaff_BP = puVar24[1];
    uVar10 = puVar24[5];
    uVar8 = puVar24[6];
    uVar14 = CONCAT11((char)(puVar24[3] >> 8),(byte)puVar24[3] | *(byte *)0x5d02) |
             *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar24[6] = (uint)unaff_DI;
    pbVar2 = (byte *)((int)unaff_SI + uVar14 + 0x2c2);
    cVar37 = SCARRY1((char)uVar8,*pbVar2);
    bVar32 = (char)((char)uVar8 + *pbVar2) < '\0';
    puVar25 = puVar24 + 5;
    puVar24[5] = 0x3a83;
    uVar38 = func_0x00013e95();
    bVar6 = (byte)uVar38;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar14;
    cVar13 = (char)((ulong)uVar38 >> 0x18);
    if (bVar32) {
      bVar11 = (byte)(uVar14 >> 8);
      puVar30 = (uint *)((int)unaff_DI + -0x53);
      uVar4 = (uint)(bVar11 < (byte)(uVar10 >> 8));
      uVar7 = *puVar30;
      uVar3 = *puVar30;
      *puVar30 = uVar3 + 0xe02d + uVar4;
      bVar9 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar11 = bVar11 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar38 >> 8);
      in_BX = CONCAT11(bVar11,(char)uVar14);
      if ((char)bVar11 < '\0') {
        bVar32 = unaff_SI[3] < 1000;
        if (!bVar32) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar25 + -2) = 0x3b26;
          puVar25 = (uint *)((int)puVar25 + -2);
          uVar38 = func_0x00013966();
          if (!bVar32) goto LAB_1000_3b55_1;
        }
        in_ESP = (undefined1 *)CONCAT22(uVar31,(undefined1 *)((int)puVar25 + -2));
        *(undefined2 *)((int)puVar25 + -2) = 0x3b2d;
        uVar39 = FUN_1000_8cb7();
        uVar14 = (uint)(uVar39 >> 0x10);
        bVar32 = (byte)uVar39 < 0x5a;
        puVar26 = (undefined1 *)in_ESP;
        if (bVar32) {
          bVar32 = true;
          if ((byte)uVar39 < 0x50) goto LAB_1000_3b62;
          uVar8 = (undefined2)((ulong)in_ESP >> 0x10);
          puVar18 = (undefined2 *)(puVar26 + -2);
          *(undefined2 *)(puVar26 + -2) = 0x3b38;
          bVar32 = false;
          goto code_r0x000138eb;
        }
        puVar27 = puVar26 + -2;
        *(undefined2 *)(puVar26 + -2) = 0x3b42;
        uVar38 = FUN_1000_3607();
        in_CL = (char)uVar10;
        if (bVar32) {
          puVar16 = puVar27 + -2;
          *(undefined2 *)(puVar27 + -2) = 0x3b47;
          goto LAB_1000_37ea_2;
        }
LAB_1000_3b55_1:
        uVar39 = CONCAT22((int)((ulong)uVar38 >> 0x10),
                          CONCAT11((char)((ulong)uVar38 >> 8),(char)uVar38 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar30 = (uint *)ZEXT24((undefined1 *)((int)puVar25 + -2));
      *(undefined2 *)((int)puVar25 + -2) = unaff_CS;
      iVar12 = CONCAT11(cVar13 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar38 >> 0x10) + bVar9 +
                        (0x1fd2 < uVar7 || CARRY2(uVar3 + 0xe02d,uVar4)));
      pbVar2 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar2 = *pbVar2 + (char)uVar10;
      goto code_r0x00013aab;
    }
    if (cVar37 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar13;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar14 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar25 + 10),*(undefined2 *)((int)puVar25 + 0xe));
}


