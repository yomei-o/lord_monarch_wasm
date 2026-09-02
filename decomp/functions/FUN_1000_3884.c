/* 1000:3884 */

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

ulong FUN_1000_3884(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  uint in_AX;
  uint uVar7;
  byte bVar9;
  undefined2 uVar8;
  uint in_CX;
  byte bVar10;
  uint in_DX;
  char cVar12;
  undefined2 extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar11;
  uint in_BX;
  uint uVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  undefined2 *puVar16;
  uint *puVar17;
  undefined1 *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  undefined2 *in_ESP;
  undefined2 uVar27;
  uint *puVar26;
  uint unaff_BP;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  uint unaff_DS;
  bool bVar28;
  byte in_AF;
  undefined1 uVar29;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  char cVar33;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  ulong uVar34;
  undefined4 uVar35;
  
code_r0x00013884:
  bVar6 = (byte)(in_AX | 5);
  *(byte *)(unaff_SI + 5) = bVar6;
  swi(4);
  pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
  *pbVar1 = *pbVar1 + bVar6;
  if ((POPCOUNT(*pbVar1) & 1U) != 0) {
    pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x33);
    bVar6 = *pbVar1;
    bVar9 = *pbVar1;
    cVar12 = (char)(in_DX >> 8) + *(byte *)(in_BX + (int)unaff_SI);
    *(byte *)(unaff_DI + 0x39) = (byte)unaff_DI[0x39] - cVar12;
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xe872);
    *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar12,(byte)in_DX + bVar9),
                                        ((in_AX | 5) + 0x5556) - (uint)CARRY1((byte)in_DX,bVar6)) %
                              (ulong)unaff_SI[0x410]);
    *(int *)(byte *)(unaff_BP + (int)unaff_DI) = *(int *)(byte *)(unaff_BP + (int)unaff_DI) >> 0x10;
    return CONCAT22(((undefined2 *)in_ESP)[1],*(undefined2 *)in_ESP);
  }
  puVar22 = unaff_SI;
  if (*pbVar1 == 0) goto LAB_1000_3958;
code_r0x000138e6:
  *(uint *)((int)unaff_SI + 0x31) = *(uint *)((int)unaff_SI + 0x31) & (uint)unaff_SI;
  bVar28 = CARRY1((byte)in_BX,*(byte *)(unaff_BP + (int)unaff_SI));
  in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX + *(byte *)(unaff_BP + (int)unaff_SI));
code_r0x000138eb:
  puVar16 = (undefined2 *)in_ESP;
  uVar27 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar16[-1] = unaff_SS;
  if (!bVar28) {
    puVar26 = unaff_DI;
    unaff_DI = (uint *)((int)unaff_DI + 1);
    *(byte *)puVar26 = 0x30;
    uVar7 = CONCAT11(0xaa,*(byte *)(unaff_BP + (int)unaff_DI) | 0x30) ^ 0x8a0;
    puVar16[-1] = in_BX;
    puVar16[-2] = uVar7;
    in_BX = unaff_SI[0x15];
    in_DX = (in_DX | 0x3000) - *(int *)(byte *)(in_BX + (int)unaff_SI);
    bVar9 = (byte)(uVar7 >> 8);
    bVar6 = (char)uVar7 + 8;
    if (bVar6 != *(byte *)(in_BX + 0xd27e)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    puVar16[-3] = CONCAT11(bVar9,bVar6);
    puVar16[-4] = in_CX;
    puVar16[-5] = in_DX;
    puVar16[-6] = in_BX;
    puVar16[-7] = puVar16 + -2;
    puVar16[-8] = unaff_BP;
    puVar16[-9] = unaff_SI;
    puVar16[-10] = unaff_DI;
    uVar7 = *unaff_DI;
    cVar12 = (char)(in_CX >> 8);
    bVar10 = cVar12 + bVar6;
    in_CX = CONCAT11(bVar10,(char)in_CX);
    unaff_BP = 0x874;
    if (SCARRY1(cVar12,bVar6)) {
      in_ESP = (undefined2 *)CONCAT22(uVar27,(undefined2 *)puVar16[-10]);
      puVar22 = *(uint **)(byte *)((int)unaff_DI + (in_BX - 0x18));
      puVar26 = puVar22 + 0x43a;
      uVar13 = *puVar26;
      *puVar26 = *puVar26 + 0x809;
      in_CX = 0x4379;
      puVar22[0x43a] =
           puVar22[0x43a] + CONCAT11(bVar9 | (byte)uVar7,bVar6 | bVar10) + (uint)(0xf7f6 < uVar13);
    }
    else {
      puVar16[-0xb] = 0x874;
      in_ESP = (undefined2 *)CONCAT22(uVar27,puVar16 + -0xc);
      puVar16[-0xc] = 0x874;
      puVar22 = unaff_SI;
    }
LAB_1000_3958:
    *(uint *)(byte *)((int)unaff_DI + 0x55) = *(int *)(byte *)((int)unaff_DI + 0x55) + in_DX;
    unaff_SI = (uint *)((int)puVar22 + 1);
    out((byte)*puVar22,in_DX);
    uVar7 = CONCAT11((byte)(in_BX >> 8) & *(byte *)((int)unaff_SI + unaff_BP + 0x11),(char)in_BX);
    bVar9 = (byte)in_DX;
    cVar33 = SBORROW1(bVar9,(byte)puVar22[0x39]);
    bVar6 = (byte)puVar22[0x39];
    cVar12 = (char)(bVar9 - bVar6) < '\0';
    bVar28 = bVar9 == bVar6;
    uVar27 = (undefined2)((ulong)in_ESP >> 0x10);
    puVar17 = (undefined2 *)in_ESP + -1;
    ((undefined2 *)in_ESP)[-1] = 0x396b;
    bVar6 = func_0x0001b3ed();
    iVar11 = extraout_DX_00;
    if (!bVar28) {
      *(byte *)(puVar22 + 6) = bVar6;
      *(undefined2 *)((int)puVar17 + -2) = 0x3973;
      puVar17 = (uint *)((int)puVar17 + -2);
      bVar6 = func_0x0001b617();
      iVar11 = extraout_DX_01;
    }
    if (cVar33 != cVar12) {
      iVar11 = iVar11 + 1;
      puVar17[-1] = (uint)unaff_DI;
      puVar17[-2] = iVar11;
      puVar17[-3] = CONCAT11((char)(in_CX >> 8),8);
      puVar17[-4] = uVar7;
      if (iVar11 == 0) {
LAB_1000_39c7:
        pcVar5 = (code *)swi(1);
        uVar34 = (*pcVar5)();
        return uVar34;
      }
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x6e);
      *pbVar1 = *pbVar1 | (byte)((uint)iVar11 >> 8);
code_r0x00013985:
      pbVar1 = (byte *)((int)unaff_DI + uVar7 + 0x12);
      *(byte **)pbVar1 = (byte *)((int)unaff_DI + *(int *)pbVar1 + 2);
      puVar18 = (undefined1 *)0x2e1c;
      *(undefined2 *)0x2e1c = 0x3990;
      FUN_1000_8d53();
      *(undefined2 *)(puVar18 + -2) = 0x399f;
      func_0x00018e51();
      pcVar5 = (code *)swi(3);
      uVar34 = (*pcVar5)();
      return uVar34;
    }
    bVar6 = bVar6 ^ *(byte *)(unaff_BP + (int)unaff_SI);
    in_AF = 9 < (bVar6 & 0xf) | in_AF;
    bVar6 = bVar6 + in_AF * '\x06' & 0xf;
    unaff_DS = *puVar17;
    pbVar1 = (byte *)((int)unaff_SI + unaff_BP + 0x8b5f);
    bVar28 = bVar6 < *pbVar1 || bVar6 == *pbVar1;
    puVar26 = (uint *)CONCAT22(uVar27,puVar17);
    *puVar17 = 0x39ba;
    uVar35 = FUN_1000_a1b8();
    uVar13 = (uint)uVar35;
    if (bVar28) {
      if (in_CX == 1) {
        do {
          iVar11 = 0x40;
          uVar7 = uVar13;
          do {
            uVar13 = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
            puVar22 = unaff_SI;
            if (((*unaff_SI & 0x80) == 0) && ((unaff_SI[5] & 0x20) != 0)) {
              puVar26 = puVar26 + -2;
              *puVar26 = unaff_DS;
              bVar6 = (byte)uVar7 | 0x17;
              bVar9 = (byte)(uVar7 >> 8);
              if (bVar9 == (byte)unaff_SI[6]) {
                uVar7 = CONCAT11(bVar6 / 0x5e,bVar6 % 0x5e);
                puVar22 = unaff_DI;
                goto code_r0x00013a16;
              }
              uVar13 = CONCAT11(bVar9 & *(byte *)(unaff_BP + (int)unaff_SI),(byte)uVar7) | 0x17;
              *(byte *)(unaff_SI + 0x3931) = (byte)unaff_SI[0x3931] ^ (byte)((uint)iVar11 >> 8);
              *(byte *)(unaff_BP + (int)unaff_DI) = 0xff;
              in_ST0 = in_ST0 / (longdouble)*(float *)(unaff_BP + 4);
              uVar7 = *(uint *)puVar26;
              puVar26 = (uint *)CONCAT22((int)((ulong)puVar26 >> 0x10),(uint *)puVar26 + 1);
              puVar22 = unaff_SI + 8;
              unaff_DI = unaff_SI;
            }
            iVar11 = iVar11 + -1;
            unaff_SI = puVar22;
          } while (iVar11 != 0);
          unaff_SI = (uint *)*(uint *)puVar26;
          puVar26 = (uint *)CONCAT22((int)((ulong)puVar26 >> 0x10),(uint *)puVar26 + 1);
          puVar22 = unaff_DI;
code_r0x00013a16:
          uVar27 = (undefined2)((ulong)puVar26 >> 0x10);
          puVar19 = (uint *)puVar26;
          if (0x1ef < uVar13) goto code_r0x00013a1c;
          pbVar1 = (byte *)((int)puVar22 + unaff_BP + 0x59);
          *pbVar1 = *pbVar1 | (byte)uVar13;
          bVar6 = *(byte *)(uVar13 + puVar19[1]);
          puVar19[1] = (uint)unaff_SI;
          *(char *)0xaaaa = *(char *)0xaaaa + (byte)uVar13 + ((byte)((char)unaff_BP + 1U) < bVar6);
          uVar13 = CONCAT11((char)(unaff_BP >> 8),(char)unaff_BP + -0x3b);
          unaff_DI = (uint *)puVar19[1];
          puVar26 = (uint *)CONCAT22(uVar27,puVar19 + 2);
          unaff_SI = (uint *)0xc800;
          unaff_BP = uVar7;
        } while( true );
      }
      goto code_r0x00013985;
    }
    out((int)((ulong)uVar35 >> 0x10),(char)uVar35);
    puVar2 = unaff_SI;
    bVar28 = CARRY2(*puVar2,uVar13);
    *puVar2 = *puVar2 + uVar13;
    bVar31 = (int)*puVar2 < 0;
    bVar30 = *puVar2 == 0;
    bVar6 = POPCOUNT(*puVar2 & 0xff);
    in_CX = in_CX - 1;
    if (in_CX == 0 || bVar30) goto LAB_1000_39c7;
    goto LAB_1000_3a35;
  }
  in_BX = in_BX + 1;
  puVar25 = puVar16 + -2;
  puVar16[-2] = 0x810;
  *(byte *)(unaff_SI + 1) = (byte)unaff_SI[1] | (byte)in_DX;
  goto FUN_1000_38de;
LAB_1000_3b62:
  puVar25 = (undefined2 *)puVar24;
  if (bVar28) {
    puVar25 = (undefined2 *)(puVar24 + -2);
    *(undefined2 *)(puVar24 + -2) = 0x3b67;
    uVar34 = func_0x000137e6();
    cVar12 = (char)in_CX;
    if (bVar28) goto LAB_1000_381b;
  }
  if (*(int *)0x3480 != 0) {
code_r0x00013b57:
    *(byte *)unaff_SI = (byte)*unaff_SI | 1;
    return uVar34;
  }
  *(uint *)((int)puVar25 + -2) = unaff_BP;
  puVar24 = (undefined1 *)((int)puVar25 + -4);
  *(uint *)((int)puVar25 + -4) = unaff_BP;
  pbVar1 = (byte *)(in_BX + (int)unaff_SI);
  bVar6 = (byte)(uVar34 >> 8);
  bVar28 = CARRY1(*pbVar1,bVar6);
  *pbVar1 = *pbVar1 + bVar6;
  in_BX = in_BX - 1;
  goto LAB_1000_3b62;
code_r0x0001386c:
  in_AF = 9 < ((bVar6 ^ 0xf8) & 0xf) | in_AF;
  pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x854);
  *pbVar1 = *pbVar1 & 0xb;
  uVar29 = *pbVar1 == 0;
  puVar15 = (undefined1 *)0x322e;
  *(undefined2 *)0x322e = 0x3877;
  func_0x0001ab45();
  in_ESP = (undefined2 *)CONCAT22(uVar27,puVar15 + -2);
  *(undefined2 *)(puVar15 + -2) = 0x387a;
  uVar35 = func_0x0001b476();
  in_DX = (uint)((ulong)uVar35 >> 0x10);
  if (!(bool)uVar29) {
    *(byte *)((int)unaff_SI + 0xb) = (byte)uVar35;
  }
  in_AX = CONCAT11((char)((ulong)uVar35 >> 8),(byte)unaff_SI[5]) & 0xffd0;
  goto code_r0x00013884;
LAB_1000_381b:
  bVar6 = (byte)uVar34;
  bVar28 = bVar6 < 0x10;
  bVar32 = SBORROW1(bVar6,'\x10');
  bVar31 = (char)(bVar6 - 0x10) < '\0';
  bVar30 = bVar6 == 0x10;
  if (!bVar28) {
    cVar12 = '\x04';
    if (7 < bVar6) {
      bVar32 = SBORROW1(bVar6,'\f');
      bVar31 = (char)(bVar6 - 0xc) < '\0';
      bVar30 = bVar6 == 0xc;
      bVar28 = true;
      if (bVar6 < 0xc) goto LAB_1000_383e;
    }
    cVar12 = '\b';
    if (bVar6 != 0) {
      bVar32 = SBORROW1(bVar6,'\x05');
      bVar31 = (char)(bVar6 - 5) < '\0';
      bVar30 = bVar6 == 5;
      bVar28 = true;
      if (bVar6 < 5) goto LAB_1000_383e;
    }
    cVar12 = '\v';
    bVar28 = bVar6 < 5;
    bVar32 = SBORROW1(bVar6,'\x05');
    bVar31 = (char)(bVar6 - 5) < '\0';
    bVar30 = bVar6 == 5;
    if (!bVar30) {
      in_CX = CONCAT11(*(byte *)((int)unaff_DI + (unaff_BP - 0x80)),0xb);
      pbVar1 = (byte *)(in_BX + (int)unaff_SI);
      *pbVar1 = *pbVar1 & 0xb;
      if (*pbVar1 != 0) goto code_r0x0001386c;
FUN_1000_38de:
      in_ESP = (undefined2 *)CONCAT22(uVar27,(undefined2 *)((int)puVar25 + -2));
      *(undefined2 *)((int)puVar25 + -2) = 0x38e1;
      FUN_1000_7494();
      *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)in_CX;
      LOCK();
      uVar29 = *(undefined1 *)(unaff_BP + 0x72);
      *(undefined1 *)(unaff_BP + 0x72) = (char)((uint)extraout_DX >> 8);
      in_DX = CONCAT11(uVar29,(char)extraout_DX);
      UNLOCK();
      goto code_r0x000138e6;
    }
  }
LAB_1000_383e:
  if (bVar28) {
    *(undefined2 *)((int)puVar25 + -2) = unaff_CS;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!bVar30 && bVar32 == bVar31) {
    return CONCAT22(*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xe));
  }
LAB_1000_37ea_2:
  if (cVar12 == '\0' && *(byte *)(unaff_BP + (int)unaff_DI) == 0) {
    puVar14 = (undefined2 *)((int)puVar25 + -2);
    puVar25 = (undefined2 *)((int)puVar25 + -2);
    *puVar14 = 0x37f3;
    func_0x0001b6c0();
  }
  return CONCAT22(*(undefined2 *)((int)puVar25 + 10),*(undefined2 *)((int)puVar25 + 0xe));
code_r0x00013a1c:
  unaff_SS = *puVar19;
  *(longdouble *)(uVar13 + (int)puVar22) = in_ST0;
  puVar26 = (uint *)CONCAT22(uVar27,(uint *)(puVar19[1] + -2));
  *(undefined2 *)(puVar19[1] + -2) = unaff_ES;
  uVar7 = puVar22[2];
  uVar13 = (uint)*(byte *)((int)puVar22 + -0x79);
  bVar28 = (byte)iVar11 < *(byte *)(unaff_BP + (int)unaff_SI);
  cVar12 = (byte)iVar11 - *(byte *)(unaff_BP + (int)unaff_SI);
  in_CX = CONCAT11((char)((uint)iVar11 >> 8),cVar12);
  bVar31 = cVar12 < '\0';
  bVar30 = cVar12 == '\0';
  bVar6 = POPCOUNT(cVar12);
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
  if (bVar30) {
    *(byte *)(uVar7 + (int)unaff_SI) = *(byte *)(uVar7 + (int)unaff_SI) + 1;
    puVar20 = (uint *)puVar26;
    puVar26 = (uint *)CONCAT22((int)((ulong)puVar26 >> 0x10),puVar20 + -1);
    puVar20[-1] = unaff_ES;
    if (0xbbc4 < CONCAT11(bVar31 << 7 | bVar30 << 6 | in_AF << 4 | ((bVar6 & 1) == 0) << 2 | 2 |
                          bVar28,(char)uVar13)) {
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xab12);
      *pbVar1 = *pbVar1 | (byte)(uVar7 >> 8);
      puVar2 = unaff_DI;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      *(byte *)puVar2 = (char)uVar13 + 0x3b;
      goto LAB_1000_3a63;
    }
    unaff_BP = unaff_BP + in_CX;
    pbVar1 = (byte *)((uVar7 >> 2) + (int)unaff_SI);
    *pbVar1 = *pbVar1 - 0x15;
    puVar2 = (uint *)((int)unaff_DI + unaff_BP + 0x645);
    uVar13 = *puVar2;
    *puVar2 = *puVar2 - in_CX;
    bVar6 = ((char)(uVar7 >> 1) + (char)(uVar7 >> 2) + -0x10) - (uVar13 < in_CX) | 2;
    iVar11 = *(int *)(byte *)((int)unaff_DI + 0x55);
code_r0x00013aab:
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar6;
    ((uint *)puVar26)[-1] = unaff_BP;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & (byte)in_CX;
    puVar22 = (uint *)0xf029;
    *(uint *)0xf029 = unaff_BP;
    if (iVar11 != *(int *)0x32bb) {
      *(undefined2 *)0xf027 = 0x3ac4;
      func_0x0001afc1();
      *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) | bVar6;
      pcVar5 = (code *)swi(1);
      uVar34 = (*pcVar5)();
      return uVar34;
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
    puVar21 = (uint *)puVar26;
    uVar27 = (undefined2)((ulong)puVar26 >> 0x10);
    puVar21[-1] = unaff_ES;
    pbVar1 = (byte *)((int)unaff_SI + uVar7 + 0x222);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
    unaff_DI = (uint *)puVar21[-1];
    unaff_SI = (uint *)*puVar21;
    unaff_BP = puVar21[1];
    in_CX = puVar21[5];
    uVar8 = puVar21[6];
    uVar7 = CONCAT11((char)(puVar21[3] >> 8),(byte)puVar21[3] | *(byte *)0x5d02) |
            *(uint *)((int)unaff_DI + unaff_BP + 10);
    puVar21[6] = (uint)unaff_DI;
    pbVar1 = (byte *)((int)unaff_SI + uVar7 + 0x2c2);
    cVar33 = SCARRY1((char)uVar8,*pbVar1);
    bVar28 = (char)((char)uVar8 + *pbVar1) < '\0';
    puVar22 = puVar21 + 5;
    puVar21[5] = 0x3a83;
    uVar35 = func_0x00013e95();
    bVar6 = (byte)uVar35;
    out(0x6f,bVar6);
    *(undefined1 *)0x1108 = (char)uVar7;
    cVar12 = (char)((ulong)uVar35 >> 0x18);
    if (bVar28) {
      bVar10 = (byte)(uVar7 >> 8);
      puVar26 = (uint *)((int)unaff_DI + -0x53);
      uVar4 = (uint)(bVar10 < (byte)(in_CX >> 8));
      uVar13 = *puVar26;
      uVar3 = *puVar26;
      *puVar26 = uVar3 + 0xe02d + uVar4;
      bVar9 = *(byte *)(unaff_BP + (int)unaff_DI);
      bVar10 = bVar10 + (byte)unaff_SI[0x1015] | (byte)((ulong)uVar35 >> 8);
      in_BX = CONCAT11(bVar10,(char)uVar7);
      if ((char)bVar10 < '\0') {
        bVar28 = unaff_SI[3] < 1000;
        if (!bVar28) {
                    /* WARNING: Call to offcut address within same function */
          *(undefined2 *)((int)puVar22 + -2) = 0x3b26;
          puVar22 = (uint *)((int)puVar22 + -2);
          uVar35 = func_0x00013966();
          if (!bVar28) goto LAB_1000_3b55_1;
        }
        puVar24 = (undefined1 *)((int)puVar22 + -2);
        *(undefined2 *)((int)puVar22 + -2) = 0x3b2d;
        uVar34 = FUN_1000_8cb7();
        in_DX = (uint)(uVar34 >> 0x10);
        bVar28 = (byte)uVar34 < 0x5a;
        if (bVar28) {
          bVar28 = true;
          if ((byte)uVar34 < 0x50) goto LAB_1000_3b62;
          in_ESP = (undefined2 *)CONCAT22(uVar27,puVar24 + -2);
          *(undefined2 *)(puVar24 + -2) = 0x3b38;
          bVar28 = false;
          goto code_r0x000138eb;
        }
        puVar23 = puVar24 + -2;
        *(undefined2 *)(puVar24 + -2) = 0x3b42;
        uVar35 = FUN_1000_3607();
        cVar12 = (char)in_CX;
        if (bVar28) {
          puVar25 = (undefined2 *)(puVar23 + -2);
          *(undefined2 *)(puVar23 + -2) = 0x3b47;
          goto LAB_1000_37ea_2;
        }
LAB_1000_3b55_1:
        uVar34 = CONCAT22((int)((ulong)uVar35 >> 0x10),
                          CONCAT11((char)((ulong)uVar35 >> 8),(char)uVar35 + -0x80)) | 1;
        goto code_r0x00013b57;
      }
      puVar26 = (uint *)ZEXT24((undefined1 *)((int)puVar22 + -2));
      *(undefined2 *)((int)puVar22 + -2) = unaff_CS;
      iVar11 = CONCAT11(cVar12 - *(byte *)((int)unaff_SI + in_BX + 0x23c9),
                        (char)((ulong)uVar35 >> 0x10) + bVar9 +
                        (0x1fd2 < uVar13 || CARRY2(uVar3 + 0xe02d,uVar4)));
      pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x5555);
      *pbVar1 = *pbVar1 + (char)in_CX;
      goto code_r0x00013aab;
    }
    if (cVar33 == '\0') {
      *(byte *)((int)unaff_SI + 0xb) = *(byte *)((int)unaff_SI + 0xb) + cVar12;
      goto code_r0x00013b04;
    }
code_r0x00013b09:
    if ((byte)unaff_SI[5] != 2) goto LAB_1000_3b12;
  }
  *(byte *)(unaff_SI + 5) = (byte)(uVar7 >> 8);
LAB_1000_3b12:
  return CONCAT22(*(undefined2 *)((int)puVar22 + 10),*(undefined2 *)((int)puVar22 + 0xe));
}


