/* 1000:13a2 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011539) overlaps instruction at (ram,0x00011538)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x000115ef) */
/* WARNING: Removing unreachable block (ram,0x00011641) */
/* WARNING: Removing unreachable block (ram,0x000115f1) */
/* WARNING: Removing unreachable block (ram,0x000113ba) */
/* WARNING: Removing unreachable block (ram,0x000113bb) */

void FUN_1000_13a2(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  undefined2 *puVar4;
  long lVar5;
  byte *pbVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  char extraout_DL;
  char cVar15;
  char extraout_DH;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  char extraout_DH_00;
  char extraout_DH_01;
  undefined1 in_BL;
  int iVar16;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined2 *puVar19;
  undefined2 *puVar20;
  undefined2 *puVar21;
  int unaff_BP;
  undefined2 *puVar22;
  int iVar23;
  undefined1 *puVar24;
  byte *unaff_SI;
  byte *pbVar25;
  undefined1 *unaff_DI;
  byte *pbVar26;
  undefined2 *puVar27;
  undefined2 unaff_ES;
  int unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool bVar28;
  undefined1 uVar29;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar30;
  undefined2 in_stack_00002770;
  int in_stack_00002778;
  byte *in_stack_0000277a;
  undefined1 *in_stack_0000277c;
  undefined2 *in_stack_00002780;
  int in_stack_00002784;
  undefined2 in_stack_00002786;
  
  iVar14 = (int)((long)*(int *)(unaff_SI + unaff_BP) * 0x51);
  bVar28 = (long)iVar14 != (long)*(int *)(unaff_SI + unaff_BP) * 0x51;
  uVar11 = FUN_1000_14e4();
  bVar10 = (byte)iVar14;
  bVar8 = (char)uVar11 + (char)((uint)uVar11 >> 8) * '(';
  uVar13 = (uint)bVar8;
  uVar12 = CONCAT11((uVar13 == 0) << 6 | in_AF << 4 | ((POPCOUNT(uVar13) & 1U) == 0) << 2 | 2 |
                    bVar28,bVar8);
  *unaff_SI = bVar8;
  bVar8 = 0xfe;
  if (!bVar28 && uVar13 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar7 = (byte)(uVar12 / (byte)unaff_DI[-0x55a9]);
  uVar13 = CONCAT11((char)(uVar12 % (uint)(byte)unaff_DI[-0x55a9]),bVar7);
  puVar17 = (undefined2 *)CONCAT11(0xc,in_BL);
  pbVar1 = unaff_SI;
  *pbVar1 = *pbVar1 - 1;
  if (*pbVar1 == 0) {
    uVar29 = in(0xd2fe);
    *unaff_DI = uVar29;
    *unaff_SI = bVar7;
    pbVar1 = (byte *)((int)puVar17 + (int)(unaff_DI + 1));
    *pbVar1 = *pbVar1 ^ bVar7;
    iVar14 = CONCAT11(0x5b,bVar10);
    puVar27 = (undefined2 *)(unaff_DI + 2);
    uVar29 = in(0xd2fe);
    unaff_DI[1] = uVar29;
    *(int *)((byte *)((int)puVar17 + (int)unaff_SI) + 4) = unaff_CS;
    while (bVar28 = 0xf3 < bVar8, bVar8 = bVar8 + 0xc, bVar28) {
      iVar14 = iVar14 - *(int *)(unaff_SI + 0x448);
    }
    bVar28 = (uVar13 | 0x60e8) == 0;
    bVar8 = FUN_1000_0dff();
    unaff_BP = unaff_CS;
    if (bVar28) {
      puVar22 = (undefined2 *)(unaff_CS + -1);
      *unaff_SI = *unaff_SI - (char)puVar17;
      if ((bVar8 | 0x74) != 0) {
        *(byte *)((int)puVar17 + (int)unaff_SI) = *(byte *)((int)puVar17 + (int)unaff_SI) ^ 0x42;
        pbVar1 = (byte *)((int)puVar17 + (int)puVar27 + 0x41f5);
        *pbVar1 = ~*pbVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      puVar21 = (undefined2 *)&stack0xfffa;
      cVar15 = '\x02';
      do {
        puVar22 = puVar22 + -1;
        puVar21 = puVar21 + -1;
        *puVar21 = *puVar22;
        cVar15 = cVar15 + -1;
      } while ('\0' < cVar15);
code_r0x00011538:
      if ((undefined2 *)(*(uint *)0x3bc6 & 0xfffe) != puVar17) {
        func_0x000108b9();
        *(undefined2 *)0x3bc6 = puVar17;
        FUN_1000_5b6a();
        func_0x000108d8();
      }
      FUN_1000_7885();
      FUN_1000_6e9a();
      FUN_1000_08f7();
      *(uint *)0x3bc6 = *(uint *)0x3bc6 | 1;
      func_0x00015b6b();
      puVar24 = &stack0xfffa;
LAB_1000_156e:
      *(undefined2 *)0x3bc6 = in_stack_00002770;
      *(undefined1 *)0x32d4 = 0x1e;
      uVar11 = 0;
      *(undefined2 *)0x32e6 = 0;
      *(undefined2 *)0x32e8 = 0;
      do {
        *(undefined2 *)0x32ea = uVar11;
        *(undefined2 *)0x32ec = uVar11;
        in_stack_00002770 = 0x1588;
        bVar8 = FUN_1000_27c5();
        puVar22 = puVar27 + 1;
        cVar15 = (char)((uint)puVar17 >> 8);
        if ((bVar8 & 0x6f) != 0) {
          *unaff_SI = *unaff_SI + cVar15;
          ((byte *)((int)puVar17 + (int)unaff_SI))[-0x58] =
               ((byte *)((int)puVar17 + (int)unaff_SI))[-0x58] & (byte)iVar14;
          unaff_SI[3] = unaff_SI[3] & (byte)((uint)extraout_DX_00 >> 8);
code_r0x000115a6:
          uVar13 = FUN_1000_6e80();
          cVar15 = extraout_DH_01;
          goto code_r0x00011666;
        }
        puVar17 = (undefined2 *)CONCAT11(cVar15,(char)puVar17 + (char)((uint)iVar14 >> 8));
        uVar13 = in(extraout_DX_00);
        bVar28 = *(byte *)0x3c00 == 4;
        if (*(byte *)0x3c00 < 4) {
          uVar13 = uVar13 + 0xb7e0;
          if ((uVar13 & 0x20) != 0) goto code_r0x000115a6;
          bVar28 = (uVar13 & 0x40) == 0;
        }
        uVar30 = CONCAT22(extraout_DX_00,uVar13);
        bVar8 = 0;
        if (!bVar28) {
          do {
            LOCK();
            *(undefined1 *)((int)puVar17 + (int)puVar22) = (char)((ulong)uVar30 >> 0x10);
            UNLOCK();
            bVar10 = (byte)uVar30 + 0x30;
            uVar29 = 0xcf < (byte)uVar30 || CARRY1(bVar10,bVar8);
            puVar4 = puVar22;
            puVar22 = puVar22 + 1;
            *puVar4 = CONCAT11((char)((ulong)uVar30 >> 8),bVar10 + bVar8);
            func_0x0001c4cb();
            while (FUN_1000_4980(), (bool)uVar29) {
              while ((uVar29 = *(int *)0x3bc2 != -1, *(int *)0x3bc2 != -1 &&
                     (uVar29 = 0, *(int *)0x3bd4 != 0))) {
                unaff_SI[0x34] = unaff_SI[0x34] & (byte)iVar14;
                FUN_1000_16c6();
              }
            }
            FUN_1000_6e79();
            uVar13 = (uint)puVar24 & 0xff;
            bVar8 = CARRY2(uVar13,uVar13);
            puVar17 = (undefined2 *)(uVar13 * 2);
            (*(code *)*(undefined2 *)((int)puVar17 + 0x202d))();
            FUN_1000_48ac();
            FUN_1000_786d();
            FUN_1000_6e7c();
            uVar30 = FUN_1000_4919();
          } while( true );
        }
        uVar29 = 0;
        bVar28 = false;
        if (*(char *)0x32e5 != '\0') goto LAB_1000_15e1;
        FUN_1000_96a4();
        if ((iVar14 == 0) || (func_0x0001a96b(), (bool)uVar29)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        *(int *)((int)puVar17 + (int)puVar22) = iVar14;
        *(byte *)((int)puVar17 + (int)unaff_SI) =
             *(byte *)((int)puVar17 + (int)unaff_SI) + extraout_DL;
        puVar27 = (undefined2 *)(in_stack_00002778 + -0x40fa);
        *in_stack_0000277a = *in_stack_0000277a + (char)((uint)in_stack_00002780 >> 8);
        *in_stack_0000277a = *in_stack_0000277a ^ (byte)((uint)in_stack_00002786 >> 8);
        unaff_SI = in_stack_0000277a + 1;
        in_stack_00002786 = 0x15d8;
        iVar14 = in_stack_00002784;
        puVar17 = in_stack_00002780;
        FUN_1000_7885();
        uVar11 = FUN_1000_6e8e();
        puVar24 = in_stack_0000277c;
      } while( true );
    }
  }
  else {
    pcVar2 = (char *)((int)puVar17 + uVar13 + 0x217);
    *pcVar2 = *pcVar2 + -0x2e;
    out(0x27,CONCAT11(0xba,bVar10));
    puVar17 = (undefined2 *)CONCAT11(0xc,*(char *)0x37b3 + '\x17');
    in_AF = 9 < (bVar10 & 0xf) | in_AF;
  }
  uVar11 = *puVar17;
  *puVar17 = 0x1452;
  cVar9 = FUN_1000_712e();
  puVar17[-1] = unaff_BP;
  puVar17[-2] = unaff_BP;
  pbVar26 = (byte *)puVar17[-1];
  pbVar25 = (byte *)*puVar17;
  iVar23 = puVar17[1];
  iVar16 = puVar17[3];
  cVar15 = (char)((uint)puVar17[4] >> 8);
  bVar8 = (byte)puVar17[6];
  puVar19 = puVar17 + 7;
  lVar5 = (long)*(int *)(pbVar25 + iVar16) * 0x11f;
  iVar14 = (int)lVar5;
  if (cVar9 != '\x15') {
    *pbVar25 = (*pbVar25 - bVar8) - (iVar14 != lVar5);
    pbVar6 = (byte *)puVar17[7];
    *(char *)(iVar23 + -3) = *(char *)(iVar23 + -3) + (char)lVar5 + (bVar8 < *pbVar6);
    puVar18 = puVar17 + 7;
                    /* WARNING: Call to offcut address within same function */
    puVar17[7] = 0x146d;
    func_0x000170e1();
    puVar19 = (undefined2 *)((int)puVar18 + -2);
    *(undefined2 *)((int)puVar18 + -2) = 0x1470;
    bVar8 = FUN_1000_0cfe();
    pbVar26 = pbVar6 + -1;
    pbVar1 = pbVar25;
    pbVar25 = pbVar25 + -1;
    *pbVar6 = *pbVar1;
    pbVar25[iVar16] = pbVar25[iVar16] & (byte)iVar14;
    iVar23 = iVar23 + iVar14;
    cVar15 = extraout_DH;
  }
  bVar10 = bVar8 + (9 < (bVar8 & 0xf) | in_AF) * '\x06' + (0x99 < bVar8) * '`';
  iVar14 = CONCAT11(((char)((uint)iVar16 >> 8) - cVar15) -
                    (0x8a < bVar10 || CARRY1(bVar10 + 0x75,0x99 < bVar8)),(char)iVar16);
  *(undefined2 *)((int)puVar19 + -3) = uVar11;
  if (puVar19 != (undefined2 *)0x1) {
    *(long *)(iVar14 + -0x75) = (long)ROUND(in_ST0);
    pbVar25[-0x2777] = pbVar25[-0x2777] + 1;
    bVar8 = *(byte *)(iVar14 + -0x318c);
    out(0x7e,bVar8);
    pshufw(SUB108(in_ST0,0),*(undefined8 *)(pbVar25 + iVar23 + -1),0x97);
    if (bVar8 == pbVar25[iVar23 + -1]) {
      pbVar25[iVar23 + -1] = bVar8;
    }
    *(int *)((int)puVar19 + -5) = iVar23;
    uVar13 = *(uint *)((int)puVar19 + -5);
    *(undefined2 *)((int)puVar19 + -5) = unaff_DS;
    pbVar26[0x4c] = 0x72;
    pbVar26[-4] = 0x72;
    puVar3 = (uint *)(pbVar26 + -5);
    iVar14 = (uVar13 & 3) - (*puVar3 & 3);
    *puVar3 = *puVar3 + (uint)(0 < iVar14) * iVar14;
    *(undefined2 *)((int)puVar19 + -5) = unaff_ES;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar20 = (undefined2 *)0xfffc;
  *(undefined2 *)0xfffc = 0x1484;
  func_0x00010d23();
                    /* WARNING: Call to offcut address within same function */
  *puVar20 = 0x148c;
  uVar29 = func_0x000170dc();
  out(extraout_DX,uVar29);
  return;
LAB_1000_15e1:
  uVar13 = FUN_1000_96a0();
  if (iVar14 != 0) {
    pbVar1 = puVar24 + (int)puVar22 + 0x8aa;
    *pbVar1 = *pbVar1 & (byte)((uint)iVar14 >> 8);
    if ((POPCOUNT(*pbVar1) & 1U) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar15 = extraout_DH_00;
  if (bVar28) goto code_r0x00011666;
  FUN_1000_6e83();
  puVar27 = puVar22;
  goto LAB_1000_156e;
code_r0x00011666:
  *(uint *)0xfde9 = *(uint *)0xfde9 & uVar13;
  *(char *)((int)puVar17 + (int)puVar22) = *(char *)((int)puVar17 + (int)puVar22) + '\x01';
  *(byte *)0xf270 = *(byte *)0xf270 & (byte)((uint)iVar14 >> 8);
  ((byte *)((int)puVar17 + (int)unaff_SI))[-0x17fe] =
       ((byte *)((int)puVar17 + (int)unaff_SI))[-0x17fe] + cVar15;
  puVar27 = puVar27 + 2;
  pbVar1 = unaff_SI;
  unaff_SI = unaff_SI + 2;
  *puVar22 = *(undefined2 *)pbVar1;
  XRELEASE();
  *(undefined2 *)0x3bc6 = 5;
  func_0x00015b6b();
  if (*(char *)0x34d6 != '\0') {
    func_0x0001c1e1();
  }
  func_0x000108d8();
                    /* WARNING: Call to offcut address within same function */
  func_0x00011693();
  puVar17 = (undefined2 *)((uint)(byte)((char)(*(uint *)0x3bc4 / 10) - 1) * 2 + 0x10);
  goto code_r0x00011538;
}


