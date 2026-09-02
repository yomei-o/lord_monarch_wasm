/* 1000:2a9c */

/* WARNING: Instruction at (ram,0x00012cda) overlaps instruction at (ram,0x00012cd8)
    */
/* WARNING: Control flow encountered bad instruction data */

uint FUN_1000_2a9c(void)

{
  uint *puVar1;
  uint uVar2;
  byte bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  byte bVar12;
  uint uVar11;
  char extraout_AH;
  int in_CX;
  uint uVar13;
  byte *pbVar14;
  undefined4 in_EDX;
  byte *pbVar15;
  byte bVar16;
  char cVar18;
  byte *pbVar17;
  int unaff_BP;
  uint uVar19;
  uint *unaff_SI;
  uint *puVar20;
  uint *puVar21;
  byte *pbVar22;
  uint *puVar23;
  byte *unaff_ES;
  int unaff_SS;
  undefined2 unaff_DS;
  bool bVar24;
  bool bVar25;
  undefined1 uVar26;
  uint in_stack_0000000a;
  byte *pbVar27;
  uint uVar3;
  uint uVar4;
  
  bVar12 = 0;
  cVar18 = '\0';
  cVar6 = *(char *)0x3c00;
  do {
    if (((*unaff_SI & 8) == 0) && (cVar6 != cVar18)) {
      if (unaff_SI[8] == 0) {
        in_EDX = CONCAT22((int)((ulong)in_EDX >> 0x10),unaff_SI[7]);
        bVar5 = (byte)(unaff_SI[7] >> 8);
        bVar16 = 0x12 - bVar5;
        if (0x12 < bVar5 || bVar16 == 0) goto LAB_1000_2abd;
      }
      else {
LAB_1000_2abd:
        bVar16 = 1;
      }
      if ((byte)unaff_SI[9] != bVar16) {
        if ((byte)unaff_SI[9] < bVar16) {
          *(char *)(unaff_SI + 9) = (char)unaff_SI[9] + '\x01';
        }
        else {
          *(char *)(unaff_SI + 9) = (char)unaff_SI[9] + -1;
        }
      }
    }
    cVar18 = cVar18 + '\x01';
    unaff_SI = unaff_SI + 0xb;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  *(undefined1 *)(unaff_BP + -0x11) = *(undefined1 *)(unaff_BP + -0x11);
  uVar13 = 0xab8f;
  pbVar15 = (byte *)CONCAT22((int)((ulong)in_EDX >> 0x10),(byte *)0x1418);
  pbVar17 = (byte *)0x804;
  puVar20 = (uint *)0x1200;
  uVar19 = 0x2e;
  puVar23 = (uint *)*(undefined2 *)0x3bea;
  uVar9 = CONCAT11(5,(byte)puVar23[-0x16c1]);
  if ((byte)puVar23[-0x16c1] == 5) {
    pbVar22 = (byte *)0x33c2;
    uVar10 = 0x505;
  }
  else {
    while ((bVar5 = (byte)uVar9, 0x13 < bVar5 && (bVar5 < 0x18))) {
      *(byte *)(puVar20 + 0x402) = (byte)puVar20[0x402] + 9;
      puVar23 = (uint *)0x301;
LAB_1000_2b17:
      bVar12 = 1;
      if (puVar20 <= puVar23) {
        puVar23 = (uint *)((int)puVar23 - (int)puVar20);
      }
      uVar13 = uVar13 - 1;
      if (uVar13 == 0) {
        *(undefined2 *)0x3bea = puVar23;
        return uVar9;
      }
      *(char *)(puVar20 + 0x17) = (char)(byte)puVar20[0x17] >> ((byte)uVar13 & 0x1f);
      unaff_ES = (byte *)((ulong)*(uint **)(byte *)((int)puVar20 + 0x13) >> 0x10);
      puVar20 = (uint *)*(uint **)(byte *)((int)puVar20 + 0x13);
    }
    bVar5 = bVar5 - 8;
    uVar9 = (uint)bVar5;
    if (3 < bVar5) goto LAB_1000_2b17;
    iVar7 = 0x33c2;
    uVar9 = (uint)bVar5;
    puVar20 = (uint *)*(undefined2 *)(uVar9 * 2 + 0x12ef);
    puVar1 = puVar20 + 0x402;
    *(byte *)puVar1 = (byte)*puVar1 + 0x18 + CARRY2(uVar9,uVar9);
    if ((byte)*puVar1 == 0) {
      *(byte *)((int)puVar20 + 0x43) = *(byte *)((int)puVar20 + 0x43);
      puVar20[0x17] = (uint)(puVar20[0x17] + (int)puVar23);
      pbVar27 = (byte *)CONCAT22(0x33c2,unaff_ES);
      puVar1 = puVar20;
      *(byte *)puVar1 = (byte)*puVar1 + 8;
      if (((byte)*puVar1 == 0) || (*(int *)0x347e == 0)) {
        FUN_1000_4b3d();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      func_0x0001a53d();
      cVar18 = (char)pbVar15;
      bVar16 = (char)((ulong)pbVar15 >> 8) + 1;
      pbVar15 = (byte *)CONCAT22((int)((ulong)pbVar15 >> 0x10),
                                 (byte *)CONCAT11(bVar16 * '\x10',cVar18));
      bVar5 = *(byte *)((int)puVar23 + -0x2d81) + bVar16;
      cVar6 = bVar5 + bVar16;
      if (CARRY1(bVar5,bVar16)) {
        cVar6 = -1;
      }
      uVar9 = CONCAT11(bVar16,cVar6) & 0xd222;
      if (uVar9 == 0) {
        puVar1 = puVar23;
        puVar23 = (uint *)((int)puVar23 + (uint)bVar12 * -2 + 1);
        *(byte *)(puVar20 + 0x17) = (byte)puVar20[0x17] + cVar18 + ((byte)*puVar1 != 0);
        bVar24 = true;
        pbVar27 = (byte *)(ulong)CONCAT21(0x2b94,(char)pbVar27);
        uVar10 = func_0x0001af11();
        if (!bVar24) {
          uVar9 = CONCAT11(100,(char)uVar10);
          goto code_r0x00012b9b;
        }
      }
      else {
code_r0x00012b9b:
        pbVar17 = (byte *)0x410;
        bVar5 = (char)uVar9 + 4;
        pbVar22 = (byte *)((int)puVar23 + (uint)bVar12 * -2 + 1);
        *(byte *)puVar23 = bVar5;
        pbVar27 = (byte *)(ulong)CONCAT21(0x2e,(char)pbVar27);
        puVar23 = (uint *)(pbVar22 + (uint)bVar12 * -2 + 1);
        uVar10 = CONCAT11((char)(uVar9 >> 8),((char)uVar9 + '|') - (bVar5 < *pbVar22));
        if (*(byte *)((int)puVar23 + -0x2d81) < 200) goto LAB_1000_2c73;
      }
      puVar20 = (uint *)puVar23[-0xdc1];
      bVar24 = false;
      if (puVar20 == (uint *)0x0) {
        uVar10 = func_0x0001a512();
        if (!bVar24) {
          uVar13 = CONCAT11((char)(uVar13 >> 8),0x30);
          uVar10 = CONCAT11((char)(((uint)puVar23 >> 1) / 0x30),(char)(((uint)puVar23 >> 1) % 0x30))
          ;
          *(undefined2 *)0x2 = uVar10;
          *(undefined2 *)0x4 = puVar23;
          *(undefined2 *)0x8 = uVar10;
          *(undefined1 *)0x0 = 0;
          *(undefined1 *)0x1 = 6;
          puVar23[-0xdc1] = 0;
          *(undefined1 *)0xa = 1;
          LOCK();
          bVar12 = *(byte *)((int)puVar23 + -0x2d81);
          *(byte *)((int)puVar23 + -0x2d81) = 1;
          UNLOCK();
          iVar7 = bVar12 - 1;
          *(int *)0x6 = iVar7;
          pbVar17 = (byte *)pbVar27;
          *(byte *)0x0 = *(byte *)0x0 ^ 0x30;
          *(undefined1 *)0xc = (char)iVar7;
          goto LAB_1000_2c73;
        }
        *pbVar15 = *pbVar15 ^ (byte)uVar13;
      }
      pbVar14 = (byte *)pbVar15;
      if ((byte)uVar10 == (byte)puVar20[6]) {
        uVar9 = CONCAT11((char)((uint)uVar10 >> 8),(byte)uVar10 & (pbVar17 + (int)puVar20)[100]);
        puVar1 = puVar20 + 3;
        uVar11 = *puVar1;
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + uVar9;
        uVar3 = *puVar1;
        uVar4 = *puVar1;
        if (CARRY2(uVar11,uVar9)) {
          puVar20[3] = 0xffff;
        }
        if ((int)uVar3 < 0) {
          uVar11 = uVar9;
          if (uVar4 == 0 || !SCARRY2(uVar2,uVar9)) {
            while ((char)(pbVar17 + (int)puVar23)[-0x56] < '\0') {
              *(byte *)puVar20 = (byte)*puVar20 | (byte)uVar9;
              pbVar15 = (byte *)(ulong)CONCAT11((byte)((uint)pbVar14 >> 8) | (byte)puVar20[0x1a],
                                                (char)pbVar14);
              puVar1 = puVar20;
              bVar25 = CARRY2(*puVar1,(uint)pbVar17);
              *puVar1 = (uint)(pbVar17 + *puVar1);
LAB_1000_2c9b_2:
              pbVar22 = (byte *)((ulong)pbVar27 >> 0x10);
              bVar12 = (byte)(uVar9 >> 8);
              pbVar14 = (byte *)(byte *)CONCAT31((int3)((ulong)pbVar15 >> 8),
                                                 (char)pbVar15 + -0x80 + bVar25);
              bVar5 = in(pbVar14);
              bVar24 = false;
              (pbVar17 + (int)puVar20)[0x8fc] = (pbVar17 + (int)puVar20)[0x8fc] | bVar5;
code_r0x00012ca5:
              if (bVar24) {
                uVar19 = CONCAT11(bVar12,bVar5) & 0x3ff;
                bVar5 = (byte)(uVar19 >> 8);
                bVar12 = (byte)uVar19;
                uVar26 = bVar12 < bVar5;
                bVar24 = SBORROW1(bVar12,bVar5);
                cVar6 = bVar12 - bVar5;
                if (bVar12 != bVar5) goto LAB_1000_2d0a;
              }
              pbVar27 = (byte *)CONCAT22(pbVar22,(byte *)0x2cb1);
              uVar9 = func_0x0001a4c2();
            }
            out(pbVar14,uVar9);
            *(byte *)((int)puVar23 + uVar9 + 599) = (byte)uVar13;
            cVar6 = func_0x0001b538(pbVar27);
            unaff_ES = (byte *)0x2000;
            pbVar14 = (byte *)CONCAT11(cVar6 + '\b',pbVar17[0x12]);
            puVar20 = (uint *)0x0;
            uVar13 = 0x900;
            puVar23 = (uint *)0x2;
            uVar11 = *(uint *)0xd27e;
            uVar19 = uVar9;
          }
          if (((char)uVar11 == (char)((uint)pbVar14 >> 8)) && (*puVar20 < 0x4000)) {
            uVar9 = ((uint)pbVar14 & 0xff) * (uVar11 >> 8);
            if ((char)(uVar9 >> 8) != '\0') {
              puVar1 = (uint *)(pbVar17 + 0xe);
              uVar11 = *puVar1;
              *puVar1 = *puVar1 + uVar9;
              *(uint *)(pbVar17 + 0x10) = *(int *)(pbVar17 + 0x10) + (uint)CARRY2(uVar11,uVar9);
              *(byte *)(puVar20 + -0x16c0) = (byte)puVar20[-0x16c0] - (char)uVar9;
              if (uVar13 - 1 != 0) {
                pbVar15 = (byte *)((int)puVar23 + uVar19 + 0x7e84);
                bVar12 = (byte)(uVar13 - 1);
                *pbVar15 = *pbVar15 + bVar12;
                ((byte *)((int)puVar20 + 1) + (int)puVar23)[uVar19] =
                     (char)((byte *)((int)puVar20 + 1) + (int)puVar23)[uVar19] >> (bVar12 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
                halt_baddata();
              }
            }
          }
          return in_stack_0000000a;
        }
        puVar23 = (uint *)((uint)puVar23 ^ (uint)pbVar14);
      }
    }
    else {
      *(byte *)((int)puVar23 + 0x7bd) = *(byte *)((int)puVar23 + 0x7bd) + 0x18;
      iVar8 = uVar9 + puVar20[0x402];
      while( true ) {
        bVar12 = (byte)((uint)iVar8 >> 8);
        if (bVar12 == (byte)puVar23[-0x16c1]) {
          puVar20[0x402] = (puVar20[0x402] + 0xebe8) - (uint)(bVar12 < (byte)puVar23[-0x16c1]);
          in(0x1418);
          unaff_SS = iVar7;
        }
        iVar8 = (uint)bVar12 << 8;
        bVar24 = (uint *)0xffa5 < puVar23;
        puVar23 = puVar23 + 0x2d;
        uVar13 = iVar7 - 1;
        if (uVar13 == 0) break;
        iVar7 = 3;
      }
      pbVar27 = (byte *)0x2c6a0000;
      uVar9 = func_0x0001a4ee();
      bVar25 = true;
      if (bVar24) goto LAB_1000_2c9b_2;
    }
LAB_1000_2c73:
    uVar13 = CONCAT11((char)(uVar13 >> 8),(byte)uVar13 | *pbVar17);
    *(byte *)(puVar20 + 6) = 4;
    puVar20[3] = 200;
    *(byte *)((int)puVar20 + 0xb) = 0xff;
    uVar10 = in(0x20);
    pbVar22 = unaff_ES;
  }
  pbVar14 = (byte *)pbVar15;
  puVar21 = (uint *)((int)puVar20 + -1);
  pbVar17[(int)puVar21] = pbVar17[(int)puVar21] + (char)pbVar17;
  puVar1 = (uint *)(pbVar17 + (int)puVar21);
  *puVar1 = *puVar1 ^ uVar13;
  if (*puVar1 == 0) {
    bVar12 = (byte)uVar10;
    uVar26 = 0x17 < bVar12;
    uVar19 = CONCAT11((char)((uint)uVar10 >> 8),bVar12 - 0x18);
    if ((byte)(bVar12 - 0x18) != '\0' && '\x17' < (char)bVar12) {
      if (!(bool)uVar26) {
        return uVar19;
      }
      cVar18 = CARRY2((uint)pbVar17,uVar19);
      pbVar17 = pbVar17 + uVar19;
      FUN_1000_91b2();
      bVar12 = (byte)((uint)*(undefined2 *)(byte *)((int)puVar20 + 1) >> 8);
      cVar6 = func_0x0001a45f();
      if ((bool)cVar18) {
        return (uint)(byte)(cVar6 + *(byte *)((int)puVar20 + 0x2d) + 1);
      }
      FUN_1000_9213();
      *(byte *)((int)puVar20 + 0x2d) = (*(byte *)((int)puVar20 + 0x2d) - extraout_AH) - cVar18;
      bVar24 = false;
      *(byte *)((int)puVar23 + 0x5d) = *(byte *)((int)puVar23 + 0x5d) ^ bVar12;
      uVar19 = FUN_1000_343c();
      if (!bVar24) {
        return uVar19;
      }
      uVar19 = func_0x000134ff();
      if (bVar24) {
        uVar9 = *(uint *)(pbVar17 + 0x1287);
        puVar20[0x17] = puVar20[0x17] | (uint)puVar21;
        return (uint)(byte)(((char)uVar19 + '\x18') - (uVar9 < 0x5c));
      }
      return uVar19;
    }
  }
  else {
    while( true ) {
      bVar24 = (byte)uVar10 < 0x14;
      bVar12 = (byte)((uint)uVar10 >> 8);
      bVar5 = -bVar24;
      uVar10 = CONCAT11(bVar12,bVar5);
      pbVar27 = (byte *)((int)puVar20 + 0x2d);
      *pbVar27 = *pbVar27 + (char)((uint)pbVar17 >> 8) + bVar24;
      if (*pbVar27 == 0) break;
      *(byte *)((int)puVar20 + 0x7b) = *(byte *)((int)puVar20 + 0x7b) | (byte)((ulong)pbVar15 >> 8);
    }
    uVar26 = false;
    bVar24 = false;
    bVar12 = bVar12 | pbVar17[(int)puVar21];
    uVar19 = CONCAT11(bVar12,bVar5);
    cVar6 = '\0';
    puVar20 = puVar21;
    if (bVar12 != 0) {
      bVar12 = (byte)puVar23[-0x16bf] - 8;
      bVar24 = bVar12 < 8;
      goto code_r0x00012ca5;
    }
LAB_1000_2d0a:
    if (bVar24 != cVar6 < '\0') {
      pbVar17 = pbVar17 + uVar19;
      goto code_r0x00012d12;
    }
    uVar19 = FUN_1000_a08e();
    puVar21 = puVar20;
  }
  puVar20 = puVar21;
  if ((bool)uVar26) {
    return uVar19;
  }
code_r0x00012d12:
  FUN_1000_38b6();
  bVar12 = *(byte *)((int)puVar20 + 0xb);
  bVar24 = bVar12 < pbVar17[(int)puVar23] ||
           (byte)(bVar12 - pbVar17[(int)puVar23]) < (bVar12 != 0xff);
  uVar19 = FUN_1000_342c();
  if (bVar24) {
    return (uint)*(byte *)0x42e;
  }
  return uVar19;
}


