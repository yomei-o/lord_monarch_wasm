/* 1000:3094 */

/* WARNING: Instruction at (ram,0x0001320c) overlaps instruction at (ram,0x0001320b)
    */
/* WARNING: Removing unreachable block (ram,0x0001315b) */
/* WARNING: Removing unreachable block (ram,0x000131e6) */

uint FUN_1000_3094(undefined2 param_1,byte *param_2)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  undefined8 uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  char cVar10;
  byte bVar11;
  undefined1 extraout_AL;
  undefined2 uVar12;
  int iVar13;
  undefined2 uVar14;
  uint uVar15;
  undefined1 extraout_AH;
  uint uVar16;
  undefined4 in_EAX;
  byte bVar17;
  uint *puVar18;
  undefined4 in_ECX;
  undefined4 uVar19;
  uint *puVar20;
  ulong uVar21;
  uint uVar22;
  ulong in_EDX;
  ulong uVar23;
  ulong uVar24;
  byte *pbVar25;
  int iVar26;
  byte *in_EBX;
  ulong uVar27;
  byte *unaff_BP;
  uint *unaff_SI;
  undefined2 *puVar28;
  uint *puVar29;
  uint *in_EDI;
  uint unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar30;
  char cVar31;
  bool bVar32;
  byte in_AF;
  byte bVar33;
  byte in_TF;
  byte in_IF;
  bool bVar34;
  byte in_NT;
  byte bStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_6;
  undefined1 uVar35;
  undefined1 uVar36;
  byte abStack_3 [3];
  
  uVar14 = (undefined2)in_EDX;
  puVar29 = (uint *)in_EDI;
  bVar34 = false;
  abStack_3[2] = (byte)((uint)&stack0x0000 >> 8);
  pbVar25 = (byte *)in_EBX;
  *pbVar25 = *pbVar25 | (byte)(in_EDX >> 8);
  uVar19 = CONCAT22((int)((ulong)in_ECX >> 0x10),(uint)abStack_3[0]);
  if ((int)(*(int *)(byte *)((int)puVar29 + 0x39) - (uint)abStack_3[0]) < 0) {
    unaff_ES = (uint)((ulong)*(undefined2 **)(unaff_SI + 3) >> 0x10);
    puVar28 = (undefined2 *)*(undefined2 **)(unaff_SI + 3);
    abStack_3[0] = 0xcd;
    abStack_3[1] = 0x30;
    FUN_1000_9fe0();
    abStack_3[2] = (byte)unaff_BP;
    abStack_3[1] = (byte)((uint)unaff_BP >> 8);
    in_EDI = (uint *)ZEXT24((byte *)((int)puVar29 + 1U));
    bVar8 = in(uVar14);
    *(byte *)puVar29 = bVar8;
    *(int *)((byte *)in_EBX + (int)((int)puVar29 + 1U)) =
         *(int *)((byte *)in_EBX + (int)((int)puVar29 + 1U)) + 1;
    abStack_3[0] = abStack_3[2];
    uVar12 = FUN_1000_3809();
    unaff_SI = puVar28 + 1;
    out(*puVar28,uVar14);
    iVar13 = CONCAT11((char)((uint)uVar12 >> 8),((byte)uVar12 | 0x89) + (char)((ulong)uVar19 >> 8))
             + *unaff_SI + (uint)CARRY1((byte)((uint)uVar14 >> 8),(unaff_BP + (int)unaff_SI)[5]);
    *(int *)0x8765 = *(int *)0x8765 + iVar13;
    uVar22 = CONCAT11((char)((uint)iVar13 >> 8),*(undefined1 *)(puVar28 + 7));
    in_EDX = 0x226;
  }
  else {
    uVar22 = CONCAT11((char)((ulong)in_EAX >> 8) + pbVar25[0x44],
                      (byte)in_EAX & (pbVar25 + (int)unaff_SI)[0x62]) | 0xba;
  }
  puVar29 = (uint *)in_EDI;
  abStack_3[1] = (byte)in_EDX;
  abStack_3[2] = (byte)(in_EDX >> 8);
  abStack_3[0] = (byte)(unaff_ES >> 8);
  bVar8 = abStack_3[0];
  if (((char)(uVar22 + 1) == (char)((char)(uVar22 + 1 >> 8) + -0x14)) &&
     (in_EBX = (byte *)(ulong)puVar29[-0xdbf], puVar29[-0xdbf] != 0)) {
    abStack_3[0] = 0x31;
    uVar14 = func_0x00019c5d();
    puVar29 = (uint *)in_EDI;
    uVar22 = (uint)in_EDX;
    pbVar25 = (byte *)in_EBX;
    if (((byte)uVar14 == pbVar25[0xc]) ||
       (((byte)((uint)uVar14 >> 8) == pbVar25[0xc] || (unaff_SI[3] <= *(uint *)(pbVar25 + 6)))))
    goto LAB_1000_3155;
    abStack_3[0] = 0x31;
    bVar6 = func_0x00019113();
    uVar22 = uVar22 ^ *(uint *)(unaff_BP + (int)(uint *)in_EDI);
    in_EDX = (ulong)uVar22;
    abStack_3[1] = (byte)unaff_CS;
    bVar5 = abStack_3[1];
    abStack_3[2] = (byte)((uint)unaff_CS >> 8);
    bVar11 = abStack_3[2];
    abStack_3[0] = (in_NT & 1) * '@' | (in_IF & 1) * '\x02' | in_TF & 1;
    bVar33 = 9 < (bVar6 & 0xf) | in_AF;
    uStack_6 = 0x28;
    uVar14 = FUN_1000_9171(((int)uVar22 < 0) * -0x80 | (uVar22 == 0) * '@' | (in_AF & 1) * '\x10' |
                           ((POPCOUNT(uVar22 & 0xff) & 1U) == 0) * '\x04');
    puVar18 = (uint *)in_EDI;
    unaff_SI = (uint *)((uint)unaff_SI ^ *(uint *)(unaff_BP + (int)puVar18));
    bVar7 = (byte)((uint)uVar14 >> 8);
    bVar6 = (byte)uVar14;
    bVar33 = 9 < (bVar6 & 0xf) | bVar33;
    uVar22 = CONCAT11(bVar7 + (byte)*puVar18,
                      bVar6 + bVar33 * '\x06' + (0x99 < bVar6 || CARRY1(bVar7,(byte)*puVar18)) * '`'
                     ) ^ *(uint *)(unaff_BP + (int)unaff_SI);
    abStack_3[0] = (byte)unaff_DS;
    abStack_3[1] = (byte)((uint)unaff_DS >> 8);
    uVar16 = (uint)in_EDX;
    uVar23 = (ulong)((uint)pbVar25 & uVar16);
    bVar7 = (char)uVar22 + 0xb0;
    bVar17 = (byte)uVar19;
    bVar30 = CARRY1(bVar7,bVar17);
    bVar7 = bVar7 + bVar17;
    bVar6 = bVar7 + 4;
    param_2 = unaff_BP;
    if ((SCARRY1(bVar7,'\x04') != SCARRY1(bVar6,bVar30)) != (char)(bVar6 + bVar30) < '\0') {
      uVar15 = *unaff_SI;
      *unaff_SI = uVar15 << 4 | (uint)(CONCAT12(0xfb < bVar7 || CARRY1(bVar6,bVar30),uVar15) >> 0xd)
      ;
      LOCK();
      uVar16 = *(uint *)(unaff_BP + (int)puVar18 + 0x2d3);
      *(uint *)(unaff_BP + (int)puVar18 + 0x2d3) =
           CONCAT11((char)(uVar22 >> 8),(bVar6 + bVar30 + 'y') - ((uVar15 & 0x1000) != 0)) & 0x7504;
      UNLOCK();
      puVar29 = puVar18 + 1;
      puVar3 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *puVar18 = *puVar3;
      bVar33 = (byte)uVar16;
      abStack_3[0] = (byte)(uVar16 >> 8);
      bVar6 = false;
      *(byte *)0x724c = *(byte *)0x724c & bVar17;
      abStack_3[1] = bVar5;
      abStack_3[2] = bVar11;
      goto code_r0x00013151;
    }
LAB_1000_31b8:
    uVar35 = 0xbb;
    uVar36 = 0x31;
    cVar10 = FUN_1000_900c();
    *(byte *)((int)unaff_SI + 0xf) = cVar10 + 1;
    bVar6 = *(byte *)((int)unaff_SI + 1) < 4;
    bVar8 = *(byte *)((int)unaff_SI + 1) - 4;
    uVar21 = 4;
    uStack_8 = (undefined1)uVar16;
    uVar9 = (undefined1)(uVar16 >> 8);
    do {
      iVar13 = (int)uVar23;
      uStack_a = (undefined1)uVar23;
      bStack_b = (byte)(uVar21 >> 8);
      bVar11 = func_0x000190bb(bVar8);
      bVar30 = !CARRY1(bVar11 + 0x3e,bVar6);
      bVar32 = bVar11 < 0xc2 && bVar30;
      bVar5 = bStack_b << 1;
      bVar6 = 0xfd < (byte)uVar21;
      bVar8 = (byte)uVar21 + 2;
      uVar22 = iVar13 - 1;
      uVar21 = (ulong)uVar22;
    } while (uVar22 != 0);
    uVar27 = (ulong)CONCAT11(uVar9,uStack_8);
    uVar23 = (ulong)CONCAT11(uVar35,uStack_6);
    puVar29 = (uint *)in_EDI;
    if (bVar5 != 0 || bVar32) {
      bVar8 = bVar5 & 7 | bVar32;
      if ((bVar5 & 7) == 0 && (bVar11 >= 0xc2 || !bVar30)) {
        bVar8 = FUN_1000_900a(uVar36);
code_r0x00013203:
        cVar10 = '\x02';
        if (0x31 < bVar8) {
          cVar10 = -2;
        }
      }
      else {
        cVar10 = '\0';
        if (bVar8 == 2) {
          *unaff_SI = (uint)(abStack_3 + *unaff_SI);
        }
        else {
          in_EDI = (uint *)ZEXT24((byte *)((int)puVar29 + (uint)bVar34 * -2 + 1));
          puVar3 = unaff_SI;
          unaff_SI = (uint *)((int)unaff_SI + (uint)bVar34 * -2 + 1);
          *(uint *)(unaff_BP + (int)unaff_SI + 0x14) =
               (*(int *)(unaff_BP + (int)unaff_SI + 0x14) - CONCAT11(uVar35,uStack_6)) -
               (uint)((byte)*puVar3 < (byte)*puVar29);
          cVar10 = -2;
          if (bVar8 != 4) {
            bVar8 = FUN_1000_900a(uVar36);
            goto code_r0x00013203;
          }
        }
      }
      *(byte *)((int)unaff_SI + 1) = cVar10 + *(byte *)((int)unaff_SI + 1) & 6;
      goto LAB_1000_3264;
    }
    pbVar1 = (byte *)((int)puVar29 + CONCAT11(uVar9,uStack_8) + 4);
    *(byte **)pbVar1 = (byte *)(*(int *)pbVar1 + (int)puVar29);
    uVar14 = 0;
    while( true ) {
      FUN_1000_83b9(bVar8,(char)uVar14);
      bVar30 = false;
      *(byte *)0x7140 = *(byte *)0x7140 & (byte)uVar23;
      func_0x00019118();
      uVar22 = CONCAT11(uStack_a,bStack_b);
      iVar13 = 0x3220;
      if (!bVar30) {
        uVar19 = 0xaa1c;
        iVar13 = -0x55e4;
        puVar29 = (uint *)in_EDI;
        in_EDI = (uint *)ZEXT24((byte *)((int)puVar29 + (uint)bVar34 * -2 + 1));
        *(byte *)puVar29 = bStack_b;
        uVar22 = CONCAT11(uStack_a,bStack_b + 0x85);
        if ((byte)(bStack_b + 0x85) == '\0') {
          *(byte *)((int)unaff_SI + 1) = 0;
          pcVar2 = (char *)((int)uVar27 + -0x2d81);
          cVar10 = *pcVar2;
          *pcVar2 = *pcVar2 + -1;
          if (cVar10 == '\0') {
            unaff_ES = (uint)bVar8;
            unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] - 0x1d;
            uVar22 = FUN_1000_3e2e();
          }
          goto LAB_1000_3261_2;
        }
      }
      uVar22 = CONCAT11((char)(uVar22 >> 8),(char)uVar22 + '\x01');
      if (iVar13 == 1) break;
      pbVar1 = (byte *)((int)(uint *)in_EDI + (int)uVar27 + 0x50);
      *pbVar1 = *pbVar1 + (char)uVar23;
    }
    uVar19 = 0;
LAB_1000_3261_2:
    uVar21 = CONCAT31((int3)((ulong)uVar19 >> 8),
                      (byte)uVar19 | (unaff_BP + (int)(uint *)in_EDI)[0x644]);
  }
  else {
LAB_1000_3155:
    bVar33 = (byte)in_EBX;
    abStack_3[0] = (byte)((ulong)in_EBX >> 8);
    bVar6 = CARRY1(bVar33,unaff_BP[(int)puVar29]);
    uVar23 = (ulong)in_EBX & 0xffffff00;
code_r0x00013151:
    uVar16 = (uint)(in_EDX >> 8);
    uVar14 = func_0x0001914f(bVar33);
    *(uint *)(unaff_BP + (int)puVar29 + 2) =
         *(int *)(unaff_BP + (int)puVar29 + 2) + 0x1b + (uint)bVar6;
    abStack_3[1] = 0x10;
    abStack_3[2] = (byte)(uVar23 >> 8);
    puVar20 = (uint *)CONCAT31((int3)((ulong)uVar19 >> 8),(byte)uVar19 + (byte)*puVar29);
    puVar18 = (uint *)puVar20;
    LOCK();
    puVar3 = (uint *)((int)puVar29 + ((uint)unaff_BP | (uint)puVar18) + 0x1073);
    uVar22 = *puVar3;
    *puVar3 = CONCAT11((char)((uint)uVar14 >> 8),(char)uVar14 + -0x18) +
              *(int *)(unaff_BP + (int)puVar29 + 0x8f3) + (uint)CARRY1((byte)uVar19,(byte)*puVar29);
    UNLOCK();
    uVar23 = (ulong)((int)CONCAT31((int3)(uVar23 >> 8),0x10) + 1);
    unaff_BP = (byte *)(((uint)unaff_BP | (uint)puVar18) + (int)puVar18);
    uVar22 = uVar22 | 0x7fc3;
    in_EDI = (uint *)(ulong)((uint)puVar18 & *(uint *)(unaff_BP + 0x15));
    out(0x13,CONCAT11((char)(uVar22 >> 8),(char)uVar22 + ')'));
    (unaff_BP + (int)unaff_SI)[0x12aa] =
         (unaff_BP + (int)unaff_SI)[0x12aa] & (byte)((ulong)uVar19 >> 8);
    uStack_6 = 0x8c;
    bVar6 = 0;
    abStack_3[0] = bVar8;
    func_0x0001cdfd((char)unaff_ES);
    uVar9 = 0x8f;
    abStack_3[0] = 0x31;
    bVar8 = FUN_1000_9127();
    bVar34 = (bVar6 & 4) != 0;
    bVar33 = 0;
    if ((bVar6 & 8) == 0) {
      pbVar1 = (byte *)((int)unaff_SI + (int)uVar23 + -0x17f6);
      *pbVar1 = *pbVar1 + (char)(uVar16 >> 8);
      unaff_SI = (uint *)puVar20;
      uStack_6 = SUB41(puVar20,0);
      goto LAB_1000_31b8;
    }
    puVar29 = (uint *)in_EDI;
    if ((bVar8 < 0xd0) || (bVar8 == 0xed)) {
      uVar4 = rdmsr(puVar20);
      uVar16 = (uint)((qword)uVar4 >> 0x20);
      in(0x8a);
      *unaff_SI = (uint)(unaff_BP + *unaff_SI);
      goto LAB_1000_31b8;
    }
    uStack_6 = 0x9f;
    uVar9 = FUN_1000_334f(uVar9);
    out(uVar16,uVar9);
    in_EDI = (uint *)ZEXT24(puVar29 + (uint)bVar34 * -2 + 1);
    uVar22 = in(uVar16);
    *puVar29 = uVar22;
    puVar3 = (uint *)((long)*(int *)(byte *)((int)unaff_SI + (int)uVar23 + 6) * 0x10);
    unaff_SI = (uint *)puVar3;
    cVar31 = (uint *)(long)(int)unaff_SI != puVar3;
    abStack_3[0] = 0x31;
    cVar10 = FUN_1000_334c();
    pbVar1 = (byte *)((int)unaff_SI + 0xf);
    *pbVar1 = *pbVar1 - 1;
    if (*pbVar1 == 0) goto LAB_1000_31b8;
    *(byte *)unaff_SI = (byte)*unaff_SI & 0xfb;
    uVar21 = CONCAT31((int3)((ulong)puVar20 >> 8),
                      (byte)puVar20 ^ (unaff_BP + (int)(uint *)in_EDI)[0x84f]);
    uVar23 = (ulong)*(uint *)((int)CONCAT31((int3)(uVar23 >> 8),(char)uVar23 + cVar10 + 'J' + cVar31
                                           ) + 10);
LAB_1000_3264:
    uVar22 = unaff_SI[3];
  }
  uVar16 = (uint)(uVar22 >> 1 < (uint)uVar21);
  uVar15 = -(int)uVar23;
  iVar13 = uVar15 - uVar16;
  puVar29 = (uint *)in_EDI;
  if ((((int)uVar23 == 0 && uVar16 <= uVar15) && iVar13 != 0) ||
     ((iVar13 == 0 && (uVar22 >> 1 != (uint)uVar21)))) {
    bVar30 = (uint *)0xfffd < puVar29;
    in_EDI = (uint *)ZEXT24(puVar29 + 1);
    unaff_SI = unaff_SI + (uint)bVar34 * -2 + 1;
    uStack_9 = (undefined1)unaff_SS;
    uStack_8 = (undefined1)((uint)unaff_SS >> 8);
LAB_1000_32ab:
    uVar27 = ZEXT24(unaff_SI);
    FUN_1000_a393();
    iVar13 = CONCAT11(extraout_AH,extraout_AL);
    if (!bVar30) {
      iVar13 = (int)uVar27;
      uVar22 = *(uint *)(iVar13 + 6);
      *(byte *)(iVar13 + (int)unaff_SI) = *(byte *)(iVar13 + (int)unaff_SI) ^ (byte)uVar23;
      bVar8 = (byte)(uVar23 >> 8);
      *(byte *)(unaff_SI + 0x18) = (byte)unaff_SI[0x18] + bVar8;
      unaff_SI[3] = uVar22;
      *(int *)(iVar13 + 6) = *(int *)(iVar13 + 6) - uVar22;
      *(byte *)((int)unaff_SI + iVar13 + 0x4404) = (byte)(uVar27 >> 8);
      *(byte *)((int)unaff_SI + -0x7789) = *(byte *)((int)unaff_SI + -0x7789) | bVar8;
      return (uint)uVar21;
    }
    while( true ) {
      bVar8 = (byte)((uint)iVar13 >> 8);
      puVar29 = (uint *)in_EDI;
      uVar22 = (uint)uVar23;
      bVar6 = (char)iVar13 + 2;
      iVar13 = (int)uVar21 + -1;
      cVar10 = (char)iVar13;
      if (iVar13 == 0) break;
      iVar26 = (int)uVar27;
      pbVar1 = (byte *)((int)puVar29 + iVar26 + 2);
      *pbVar1 = *pbVar1 + (char)(uVar23 >> 8);
      pbVar1 = (byte *)(iVar26 + (int)puVar29);
      uVar9 = CARRY1(*pbVar1,bVar8);
      bVar33 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar8;
      if (SCARRY1(bVar33,bVar8)) {
        pbVar1 = (byte *)((int)unaff_SI + iVar26 + -0x2f);
        bVar34 = CARRY1(*pbVar1,bVar6) || CARRY1(*pbVar1 + bVar6,uVar9);
        *pbVar1 = *pbVar1 + bVar6 + uVar9;
        uVar16 = FUN_1000_5c96();
        iVar13 = CONCAT11(bVar8,bVar6) + 1;
        if (bVar34 || iVar13 == 0) {
          uVar16 = FUN_1000_3ec3();
        }
        uVar15 = (uVar22 >> 4) + 1;
        puVar3 = unaff_SI + 3;
        uVar22 = *puVar3;
        *puVar3 = *puVar3 - uVar15;
        bVar34 = *puVar3 == 0;
        if (uVar22 < uVar15 || bVar34) {
          pbVar1 = (byte *)(iVar13 + (int)unaff_SI);
          *pbVar1 = *pbVar1 + cVar10 + (uVar22 < uVar15);
          puVar29 = (uint *)((uint)puVar29 | uVar16);
          bVar34 = puVar29 == (uint *)0x0;
        }
        if (bVar34) {
          if ((uVar15 & 0x1010) != 0) {
            if ((uVar15 & 0x10) == 0) {
              return unaff_ES;
            }
            if ((uVar15 & 0x1000) == 0) goto LAB_1000_33eb;
          }
          uVar15 = uVar15 & 0xf0f;
          if (uVar15 != 0x303) {
            if ((char)(uVar15 >> 8) == '\x03') goto LAB_1000_33eb;
            if ((char)uVar15 == '\x03') {
              return unaff_ES;
            }
          }
          if (puVar29[3] <= unaff_SI[3]) {
            return unaff_ES;
          }
        }
LAB_1000_33eb:
        puVar29[3] = uVar16;
        uVar22 = FUN_1000_9f38();
        return uVar22;
      }
      uVar24 = uVar23;
      if (!(bool)uVar9) {
        func_0x000190d4();
        iVar13 = 0x32e8;
        FUN_1000_32fe();
        if (!(bool)uVar9) {
          uVar15 = 0;
          goto LAB_1000_32f5;
        }
      }
      uVar21 = uVar23 & 0xffff;
      uVar23 = uVar24;
    }
  }
  else {
    uStack_9 = 0x16;
    uStack_8 = 0;
    bVar8 = (byte)iVar13;
    uVar22 = CONCAT11((char)((uint)iVar13 >> 8),
                      bVar8 + (9 < (bVar8 & 0xf) | bVar33) * '\x06' +
                      (0x99 < bVar8 || CARRY1((byte)uVar23,(byte)*unaff_SI)) * '`');
    uVar23 = (ulong)CONCAT11((byte)(uVar23 >> 8) ^ unaff_BP[-0x75],(byte)uVar23 + (byte)*unaff_SI);
    pbVar1 = unaff_BP + (int)puVar29;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    if (*(int *)pbVar1 != 0) {
      uVar22 = 0xffff;
    }
    uVar16 = unaff_SI[3];
    uVar15 = uVar22 - uVar16;
    if (uVar16 <= uVar22 && uVar15 != 0) {
      uVar15 = (uVar15 >> 2) + 1;
      bVar30 = CARRY2(uVar15,uVar16);
      uVar15 = uVar15 + uVar16;
      if (!bVar30) goto LAB_1000_32ab;
      unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + (char)uVar21 + bVar30;
      unaff_SI[3] = uVar15;
    }
LAB_1000_32f5:
    *(byte *)((int)unaff_SI + 1) = (byte)uVar15 & 7;
  }
  return CONCAT11(uStack_8,uStack_9);
}


