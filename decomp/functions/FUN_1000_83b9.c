/* 1000:83b9 */

/* WARNING: Instruction at (ram,0x0001320c) overlaps instruction at (ram,0x0001320b)
    */
/* WARNING: Removing unreachable block (ram,0x000131e6) */

uint FUN_1000_83b9(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  undefined1 uVar10;
  char cVar11;
  byte bVar12;
  undefined1 extraout_AL;
  undefined2 uVar13;
  uint uVar14;
  undefined1 extraout_AH;
  uint uVar15;
  int iVar16;
  byte bVar17;
  uint *puVar18;
  int iVar19;
  uint *puVar20;
  ulong uVar22;
  undefined4 in_ECX;
  uint uVar23;
  ulong uVar24;
  ulong uVar25;
  undefined4 in_EDX;
  uint in_BX;
  byte *unaff_BP;
  uint *unaff_SI;
  uint *unaff_DI;
  uint unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar26;
  char cVar27;
  bool bVar28;
  byte bVar29;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  bool bVar30;
  byte in_NT;
  byte bStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_13;
  undefined1 uVar31;
  undefined1 uVar32;
  byte abStack_10 [6];
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined2 uStack_8;
  undefined2 uStack_4;
  undefined2 uStack_2;
  undefined4 uVar21;
  
  bVar30 = false;
  uVar13 = (undefined2)CONCAT31((int3)((ulong)in_EDX >> 8),(byte)in_EDX | (byte)in_ECX);
  uStack_2 = 0x83be;
  iVar16 = FUN_1000_8a81();
  uStack_2 = (undefined2)in_ECX;
  uStack_a = SUB21(unaff_BP,0);
  uVar10 = uStack_a;
  uStack_9 = (undefined1)((uint)unaff_BP >> 8);
  uVar31 = uStack_9;
  abStack_10[4] = (byte)unaff_SI;
  abStack_10[5] = (byte)((uint)unaff_SI >> 8);
  abStack_10[3] = (byte)((uint)unaff_DI >> 8);
  uVar24 = 0x226;
  abStack_10[1] = 0x26;
  abStack_10[2] = 2;
  abStack_10[0] = (byte)(unaff_ES >> 8);
  bVar9 = abStack_10[0];
  uStack_4 = uVar13;
  uStack_8 = &stack0x0002;
  if (((char)(iVar16 + 1) == (char)((char)((uint)(iVar16 + 1) >> 8) + -0x14)) &&
     (in_BX = unaff_DI[-0xdbf], uStack_8 = &stack0x0002, in_BX != 0)) {
    abStack_10[0] = 0x31;
    uStack_8 = &stack0x0002;
    uVar13 = func_0x00019c5d();
    uVar23 = (uint)uVar24;
    if (((char)uVar13 == *(char *)(in_BX + 0xc)) ||
       (((char)((uint)uVar13 >> 8) == *(char *)(in_BX + 0xc) ||
        (unaff_SI[3] <= *(uint *)(in_BX + 6))))) goto LAB_1000_3155;
    abStack_10[0] = 0x31;
    bVar7 = func_0x00019113();
    uVar23 = uVar23 ^ *(uint *)(unaff_BP + (int)unaff_DI);
    uVar24 = (ulong)uVar23;
    abStack_10[1] = (byte)unaff_CS;
    bVar5 = abStack_10[1];
    abStack_10[2] = (byte)((uint)unaff_CS >> 8);
    bVar12 = abStack_10[2];
    abStack_10[0] = (in_NT & 1) * '@' | (in_IF & 1) * '\x02' | in_TF & 1;
    bVar29 = 9 < (bVar7 & 0xf) | in_AF;
    uStack_13 = 0x28;
    uVar13 = FUN_1000_9171(((int)uVar23 < 0) * -0x80 | (uVar23 == 0) * '@' | (in_AF & 1) * '\x10' |
                           ((POPCOUNT(uVar23 & 0xff) & 1U) == 0) * '\x04');
    uStack_8 = (undefined1 *)CONCAT11(uStack_8._1_1_,uVar31);
    unaff_SI = (uint *)((uint)unaff_SI ^ *(uint *)(unaff_BP + (int)unaff_DI));
    bVar8 = (byte)((uint)uVar13 >> 8);
    bVar7 = (byte)uVar13;
    bVar29 = 9 < (bVar7 & 0xf) | bVar29;
    uVar23 = CONCAT11(bVar8 + (byte)*unaff_DI,
                      bVar7 + bVar29 * '\x06' +
                      (0x99 < bVar7 || CARRY1(bVar8,(byte)*unaff_DI)) * '`') ^
             *(uint *)(unaff_BP + (int)unaff_SI);
    abStack_10[0] = (byte)unaff_DS;
    abStack_10[1] = (byte)((uint)unaff_DS >> 8);
    uVar15 = (uint)uVar24;
    in_BX = in_BX & uVar15;
    bVar8 = (char)uVar23 + 0xb0;
    bVar17 = (byte)in_ECX;
    bVar26 = CARRY1(bVar8,bVar17);
    bVar8 = bVar8 + bVar17;
    bVar7 = bVar8 + 4;
    abStack_10[5] = uVar10;
    uStack_a = uVar31;
    uStack_9 = uVar10;
    puVar6 = (undefined1 *)CONCAT11(uStack_8._1_1_,uVar31);
    if ((SCARRY1(bVar8,'\x04') != SCARRY1(bVar7,bVar26)) != (char)(bVar7 + bVar26) < '\0') {
      uVar14 = *unaff_SI;
      *unaff_SI = uVar14 << 4 | (uint)(CONCAT12(0xfb < bVar8 || CARRY1(bVar7,bVar26),uVar14) >> 0xd)
      ;
      LOCK();
      uVar15 = *(uint *)(unaff_BP + (int)unaff_DI + 0x2d3);
      *(uint *)(unaff_BP + (int)unaff_DI + 0x2d3) =
           CONCAT11((char)(uVar23 >> 8),(bVar7 + bVar26 + 'y') - ((uVar14 & 0x1000) != 0)) & 0x7504;
      UNLOCK();
      puVar20 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      puVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *puVar20 = *puVar3;
      bVar29 = (byte)uVar15;
      abStack_10[0] = (byte)(uVar15 >> 8);
      bVar7 = false;
      *(byte *)0x724c = *(byte *)0x724c & bVar17;
      abStack_10[1] = bVar5;
      abStack_10[2] = bVar12;
      goto code_r0x00013151;
    }
LAB_1000_31b8:
    uVar31 = 0xbb;
    uVar32 = 0x31;
    uStack_8 = puVar6;
    cVar11 = FUN_1000_900c();
    *(byte *)((int)unaff_SI + 0xf) = cVar11 + 1;
    bVar7 = *(byte *)((int)unaff_SI + 1) < 4;
    bVar9 = *(byte *)((int)unaff_SI + 1) - 4;
    uVar22 = 4;
    uStack_15 = (undefined1)uVar15;
    uVar10 = (undefined1)(uVar15 >> 8);
    do {
      uStack_17 = (undefined1)in_BX;
      bStack_18 = (byte)(uVar22 >> 8);
      uVar23 = in_BX;
      bVar12 = func_0x000190bb(bVar9);
      bVar26 = !CARRY1(bVar12 + 0x3e,bVar7);
      bVar28 = bVar12 < 0xc2 && bVar26;
      bVar5 = bStack_18 << 1;
      bVar7 = 0xfd < (byte)uVar22;
      bVar9 = (byte)uVar22 + 2;
      uVar15 = in_BX - 1;
      uVar22 = (ulong)uVar15;
      in_BX = uVar23;
    } while (uVar15 != 0);
    iVar16 = CONCAT11(uVar10,uStack_15);
    uVar24 = (ulong)CONCAT11(uVar31,uStack_13);
    if (bVar5 != 0 || bVar28) {
      bVar9 = bVar5 & 7 | bVar28;
      if ((bVar5 & 7) == 0 && (bVar12 >= 0xc2 || !bVar26)) {
        bVar9 = FUN_1000_900a(uVar32);
code_r0x00013203:
        cVar11 = '\x02';
        if (0x31 < bVar9) {
          cVar11 = -2;
        }
      }
      else {
        cVar11 = '\0';
        if (bVar9 == 2) {
          *unaff_SI = (uint)(abStack_10 + *unaff_SI);
        }
        else {
          puVar20 = unaff_DI;
          unaff_DI = (uint *)((int)unaff_DI + (uint)bVar30 * -2 + 1);
          puVar3 = unaff_SI;
          unaff_SI = (uint *)((int)unaff_SI + (uint)bVar30 * -2 + 1);
          *(uint *)(unaff_BP + (int)unaff_SI + 0x14) =
               (*(int *)(unaff_BP + (int)unaff_SI + 0x14) - CONCAT11(uVar31,uStack_13)) -
               (uint)((byte)*puVar3 < (byte)*puVar20);
          cVar11 = -2;
          if (bVar9 != 4) {
            bVar9 = FUN_1000_900a(uVar32);
            goto code_r0x00013203;
          }
        }
      }
      *(byte *)((int)unaff_SI + 1) = cVar11 + *(byte *)((int)unaff_SI + 1) & 6;
      goto LAB_1000_3264;
    }
    pbVar1 = (byte *)((int)unaff_DI + iVar16 + 4);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)unaff_DI);
    uVar13 = 0;
    while( true ) {
      FUN_1000_83b9(bVar9,(char)uVar13);
      bVar26 = false;
      *(byte *)0x7140 = *(byte *)0x7140 & (byte)uVar24;
      func_0x00019118();
      uVar23 = CONCAT11(uStack_17,bStack_18);
      iVar19 = 0x3220;
      if (!bVar26) {
        uVar21 = 0xaa1c;
        iVar19 = -0x55e4;
        puVar3 = unaff_DI;
        unaff_DI = (uint *)((int)unaff_DI + (uint)bVar30 * -2 + 1);
        *(byte *)puVar3 = bStack_18;
        uVar23 = CONCAT11(uStack_17,bStack_18 + 0x85);
        if ((byte)(bStack_18 + 0x85) == '\0') {
          *(byte *)((int)unaff_SI + 1) = 0;
          pcVar2 = (char *)(iVar16 + -0x2d81);
          cVar11 = *pcVar2;
          *pcVar2 = *pcVar2 + -1;
          if (cVar11 == '\0') {
            unaff_ES = (uint)bVar9;
            unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] - 0x1d;
            uVar23 = FUN_1000_3e2e();
          }
          goto LAB_1000_3261_2;
        }
      }
      uVar23 = CONCAT11((char)(uVar23 >> 8),(char)uVar23 + '\x01');
      if (iVar19 == 1) break;
      pbVar1 = (byte *)((int)unaff_DI + iVar16 + 0x50);
      *pbVar1 = *pbVar1 + (char)uVar24;
    }
    uVar21 = 0;
LAB_1000_3261_2:
    uVar22 = CONCAT31((int3)((ulong)uVar21 >> 8),(byte)uVar21 | (unaff_BP + (int)unaff_DI)[0x644]);
  }
  else {
LAB_1000_3155:
    bVar29 = (byte)in_BX;
    abStack_10[0] = (byte)(in_BX >> 8);
    bVar7 = CARRY1(bVar29,unaff_BP[(int)unaff_DI]);
    in_BX = in_BX & 0xff00;
code_r0x00013151:
    uVar15 = (uint)(uVar24 >> 8);
    uVar10 = (undefined1)(in_BX >> 8);
    uVar13 = func_0x0001914f(bVar29);
    *(uint *)(unaff_BP + (int)unaff_DI + 2) =
         *(int *)(unaff_BP + (int)unaff_DI + 2) + 0x1b + (uint)bVar7;
    abStack_10[3] = 0x6d;
    abStack_10[4] = 0;
    abStack_10[1] = 0x10;
    puVar20 = (uint *)CONCAT31((int3)((ulong)in_ECX >> 8),(byte)in_ECX + (byte)*unaff_DI);
    puVar18 = (uint *)puVar20;
    LOCK();
    puVar3 = (uint *)((int)unaff_DI + ((uint)unaff_BP | (uint)puVar18) + 0x1073);
    uVar23 = *puVar3;
    *puVar3 = CONCAT11((char)((uint)uVar13 >> 8),(char)uVar13 + -0x18) +
              *(int *)(unaff_BP + (int)unaff_DI + 0x8f3) +
              (uint)CARRY1((byte)in_ECX,(byte)*unaff_DI);
    UNLOCK();
    in_BX = CONCAT11(uVar10,0x10) + 1;
    unaff_BP = (byte *)(((uint)unaff_BP | (uint)puVar18) + (int)puVar18);
    uVar23 = uVar23 | 0x7fc3;
    unaff_DI = (uint *)((uint)puVar18 & *(uint *)(unaff_BP + 0x15));
    out(0x13,CONCAT11((char)(uVar23 >> 8),(char)uVar23 + ')'));
    (unaff_BP + (int)unaff_SI)[0x12aa] =
         (unaff_BP + (int)unaff_SI)[0x12aa] & (byte)((ulong)in_ECX >> 8);
    uStack_13 = 0x8c;
    bVar7 = 0;
    abStack_10[0] = bVar9;
    abStack_10[2] = uVar10;
    func_0x0001cdfd();
    uVar10 = 0x8f;
    abStack_10[0] = 0x31;
    bVar9 = FUN_1000_9127();
    bVar30 = (bVar7 & 4) != 0;
    bVar29 = 0;
    puVar6 = uStack_8;
    if ((bVar7 & 8) == 0) {
      pbVar1 = (byte *)((int)unaff_SI + in_BX + 0xe80a);
      *pbVar1 = *pbVar1 + (char)(uVar15 >> 8);
      unaff_SI = (uint *)puVar20;
      uStack_13 = SUB41(puVar20,0);
      goto LAB_1000_31b8;
    }
    if ((bVar9 < 0xd0) || (bVar9 == 0xed)) {
      uVar4 = rdmsr(puVar20);
      uVar15 = (uint)((qword)uVar4 >> 0x20);
      in(0x8a);
      *unaff_SI = (uint)(unaff_BP + *unaff_SI);
      goto LAB_1000_31b8;
    }
    uStack_13 = 0x9f;
    uVar10 = FUN_1000_334f(uVar10);
    out(uVar15,uVar10);
    puVar3 = unaff_DI;
    unaff_DI = unaff_DI + (uint)bVar30 * -2 + 1;
    uVar23 = in(uVar15);
    *puVar3 = uVar23;
    puVar3 = (uint *)((long)*(int *)(byte *)((int)unaff_SI + in_BX + 6) * 0x10);
    unaff_SI = (uint *)puVar3;
    cVar27 = (uint *)(long)(int)unaff_SI != puVar3;
    abStack_10[0] = 0x31;
    cVar11 = FUN_1000_334c();
    pbVar1 = (byte *)((int)unaff_SI + 0xf);
    *pbVar1 = *pbVar1 - 1;
    puVar6 = uStack_8;
    if (*pbVar1 == 0) goto LAB_1000_31b8;
    *(byte *)unaff_SI = (byte)*unaff_SI & 0xfb;
    uVar22 = CONCAT31((int3)((ulong)puVar20 >> 8),(byte)puVar20 ^ (unaff_BP + (int)unaff_DI)[0x84f])
    ;
    uVar24 = (ulong)*(uint *)(CONCAT11((char)(in_BX >> 8),(char)in_BX + cVar11 + 'J' + cVar27) + 10)
    ;
LAB_1000_3264:
    uVar23 = unaff_SI[3];
  }
  uVar15 = (uint)(uVar23 >> 1 < (uint)uVar22);
  uVar14 = -(int)uVar24;
  iVar16 = uVar14 - uVar15;
  if ((((int)uVar24 == 0 && uVar15 <= uVar14) && iVar16 != 0) ||
     ((iVar16 == 0 && (uVar23 >> 1 != (uint)uVar22)))) {
    bVar26 = (uint *)0xfffd < unaff_DI;
    unaff_DI = unaff_DI + 1;
    unaff_SI = unaff_SI + (uint)bVar30 * -2 + 1;
    uStack_16 = (undefined1)unaff_SS;
    uStack_15 = (undefined1)((uint)unaff_SS >> 8);
LAB_1000_32ab:
    puVar18 = unaff_SI;
    FUN_1000_a393();
    iVar16 = CONCAT11(extraout_AH,extraout_AL);
    if (!bVar26) {
      uVar23 = puVar18[3];
      *(byte *)((int)puVar18 + (int)unaff_SI) =
           *(byte *)((int)puVar18 + (int)unaff_SI) ^ (byte)uVar24;
      bVar9 = (byte)(uVar24 >> 8);
      *(byte *)(unaff_SI + 0x18) = (byte)unaff_SI[0x18] + bVar9;
      unaff_SI[3] = uVar23;
      puVar18[3] = puVar18[3] - uVar23;
      ((byte *)((int)puVar18 + (int)unaff_SI))[0x4404] = (byte)((uint)puVar18 >> 8);
      *(byte *)((int)unaff_SI + -0x7789) = *(byte *)((int)unaff_SI + -0x7789) | bVar9;
      return (uint)uVar22;
    }
    while( true ) {
      bVar9 = (byte)((uint)iVar16 >> 8);
      uVar23 = (uint)uVar24;
      bVar7 = (char)iVar16 + 2;
      iVar16 = (int)uVar22 + -1;
      cVar11 = (char)iVar16;
      if (iVar16 == 0) break;
      ((byte *)((int)puVar18 + (int)unaff_DI))[2] =
           ((byte *)((int)puVar18 + (int)unaff_DI))[2] + (char)(uVar24 >> 8);
      pbVar1 = (byte *)((int)puVar18 + (int)unaff_DI);
      uVar10 = CARRY1(*pbVar1,bVar9);
      bVar29 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar9;
      if (SCARRY1(bVar29,bVar9)) {
        pbVar1 = (byte *)((int)puVar18 + (int)unaff_SI) + -0x2f;
        bVar30 = CARRY1(*pbVar1,bVar7) || CARRY1(*pbVar1 + bVar7,uVar10);
        *pbVar1 = *pbVar1 + bVar7 + uVar10;
        uVar15 = FUN_1000_5c96();
        iVar16 = CONCAT11(bVar9,bVar7) + 1;
        if (bVar30 || iVar16 == 0) {
          uVar15 = FUN_1000_3ec3();
        }
        uVar14 = (uVar23 >> 4) + 1;
        puVar3 = unaff_SI + 3;
        uVar23 = *puVar3;
        *puVar3 = *puVar3 - uVar14;
        bVar30 = *puVar3 == 0;
        if (uVar23 < uVar14 || bVar30) {
          pbVar1 = (byte *)(iVar16 + (int)unaff_SI);
          *pbVar1 = *pbVar1 + cVar11 + (uVar23 < uVar14);
          unaff_DI = (uint *)((uint)unaff_DI | uVar15);
          bVar30 = unaff_DI == (uint *)0x0;
        }
        if (bVar30) {
          if ((uVar14 & 0x1010) != 0) {
            if ((uVar14 & 0x10) == 0) {
              return unaff_ES;
            }
            if ((uVar14 & 0x1000) == 0) goto LAB_1000_33eb;
          }
          uVar14 = uVar14 & 0xf0f;
          if (uVar14 != 0x303) {
            if ((char)(uVar14 >> 8) == '\x03') goto LAB_1000_33eb;
            if ((char)uVar14 == '\x03') {
              return unaff_ES;
            }
          }
          if (unaff_DI[3] <= unaff_SI[3]) {
            return unaff_ES;
          }
        }
LAB_1000_33eb:
        unaff_DI[3] = uVar15;
        uVar23 = FUN_1000_9f38();
        return uVar23;
      }
      uVar25 = uVar24;
      if (!(bool)uVar10) {
        func_0x000190d4();
        iVar16 = 0x32e8;
        FUN_1000_32fe();
        if (!(bool)uVar10) {
          uVar14 = 0;
          goto LAB_1000_32f5;
        }
      }
      uVar22 = uVar24 & 0xffff;
      uVar24 = uVar25;
    }
  }
  else {
    uStack_16 = 0x16;
    uStack_15 = 0;
    bVar9 = (byte)iVar16;
    uVar23 = CONCAT11((char)((uint)iVar16 >> 8),
                      bVar9 + (9 < (bVar9 & 0xf) | bVar29) * '\x06' +
                      (0x99 < bVar9 || CARRY1((byte)uVar24,(byte)*unaff_SI)) * '`');
    uVar24 = (ulong)CONCAT11((byte)(uVar24 >> 8) ^ unaff_BP[-0x75],(byte)uVar24 + (byte)*unaff_SI);
    pbVar1 = unaff_BP + (int)unaff_DI;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    if (*(int *)pbVar1 != 0) {
      uVar23 = 0xffff;
    }
    uVar15 = unaff_SI[3];
    uVar14 = uVar23 - uVar15;
    if (uVar15 <= uVar23 && uVar14 != 0) {
      uVar14 = (uVar14 >> 2) + 1;
      bVar26 = CARRY2(uVar14,uVar15);
      uVar14 = uVar14 + uVar15;
      if (!bVar26) goto LAB_1000_32ab;
      unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + (char)uVar22 + bVar26;
      unaff_SI[3] = uVar14;
    }
LAB_1000_32f5:
    *(byte *)((int)unaff_SI + 1) = (byte)uVar14 & 7;
  }
  return CONCAT11(uStack_15,uStack_16);
}


