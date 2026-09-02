/* 1000:88e0 */

/* WARNING: Instruction at (ram,0x000188e6) overlaps instruction at (ram,0x000188e4)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_88e0(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char extraout_AH;
  undefined2 uVar12;
  char cVar13;
  uint in_CX;
  int iVar14;
  undefined1 uVar16;
  int extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  undefined2 extraout_DX_02;
  uint uVar17;
  int iVar18;
  undefined1 *unaff_BP;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *unaff_SI;
  undefined1 *puVar21;
  char *pcVar22;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar23;
  byte in_AF;
  byte bVar24;
  bool bVar25;
  undefined4 uVar26;
  undefined1 *puStack_18;
  uint uStack_16;
  undefined1 *puStack_14;
  undefined1 *puStack_12;
  uint uStack_10;
  uint uStack_e;
  undefined2 uStack_c;
  undefined1 *puStack_a;
  byte bVar15;
  
  if (&stack0x0000 == unaff_BP) {
    return CONCAT22(*(undefined2 *)(iRam0000c4ec + 10),*(undefined2 *)(iRam0000c4ec + 0xe));
  }
LAB_1000_88e4:
  iVar14 = *(int *)(unaff_BP + -2);
  puVar19 = unaff_BP;
  do {
    unaff_BP = puVar19 + -6;
    puVar20 = *(undefined1 **)(puVar19 + -6);
    while( true ) {
      uVar16 = (undefined1)((uint)iVar14 >> 8);
      iVar14 = CONCAT11(uVar16,0xa0);
      puVar21 = puVar20 + -0x60;
      if (((int)puVar21 < 0) ||
         (bVar25 = puVar21 == (undefined1 *)0x1200, (undefined1 *)0x11ff < puVar21)) break;
      in_CX = CONCAT11(uVar16,(char)in_CX);
      func_0x0001890b();
      iVar14 = extraout_DX;
      if (bVar25) break;
      uVar17 = in_CX >> 8;
      in_CX = in_CX & 0xff;
      if ((char)((uint)extraout_DX >> 8) == (char)uVar17) {
        FUN_1000_8a1a();
        iVar14 = extraout_DX_00;
      }
      if (&stack0x0000 < (undefined1 *)0x6040) {
        in(iVar14);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      cVar8 = (char)iVar14;
      if (1 < (byte)(in_CX >> 8)) {
        cVar8 = (char)in_CX;
        unaff_SI = puVar21;
        puStack_a = puVar21;
      }
      bVar7 = (cVar8 - (char)((uint)iVar14 >> 8)) + 1;
      if (bVar7 < 3) goto LAB_1000_88e4;
      if ((char)bVar7 < '\0') {
        uVar17 = *(int *)0x4402 + 2;
        bVar25 = uVar17 == 0x60;
        if ((0x5f < uVar17) || (cVar8 = FUN_1000_8909(), bVar25)) goto LAB_1000_88e4;
        pbVar1 = (byte *)0x8a32;
        *pbVar1 = *pbVar1 & cVar8 - 1U;
        in_CX = in_CX - 1;
        if (in_CX != 0 && *pbVar1 == 0) {
          uVar9 = *(uint *)(puVar21 + (uVar17 - 0x60));
          iVar14 = extraout_DX_01;
          goto LAB_1000_8911;
        }
        unaff_BP[(int)(unaff_SI + -0x3115)] = unaff_BP[(int)(unaff_SI + -0x3115)] & cVar8 - 1U;
        iVar14 = extraout_DX_01;
      }
      iVar14 = (uint)(byte)-(((char)((uint)iVar14 >> 8) + '\x01') - (char)in_CX) << 8;
      puVar20 = puVar21;
    }
    unaff_BP[(int)(puVar20 + -0x402)] = unaff_BP[(int)(puVar20 + -0x402)] + -1;
    puVar19 = unaff_BP;
  } while( true );
LAB_1000_8911:
  uStack_16 = *(uint *)(puVar21 + uVar17);
  if ((int)uStack_16 < 0) {
    bVar7 = (byte)iVar14;
    cVar8 = (char)((uint)iVar14 >> 8) + -1;
    iVar14 = CONCAT11(cVar8,bVar7);
    if (cVar8 == '\0') {
FUN_1000_8945:
      *(uint *)0x4402 = uVar17;
      *(char *)(uVar17 + uStack_16) = *(char *)(uVar17 + uStack_16) + '\x1e';
      return CONCAT22(iVar14,uVar9);
    }
    uVar17 = uVar17 + 2;
    iVar14 = CONCAT11(cVar8,bVar7 ^ *(byte *)(uVar17 + uStack_16));
    *(int *)(unaff_BP + (int)(puVar20 + 0x51)) = *(int *)(unaff_BP + (int)(puVar20 + 0x51)) + -1;
    unaff_BP[(int)puVar21] = unaff_BP[(int)puVar21] + (char)(uVar9 >> 8);
    iVar18 = (int)*(char *)(uVar17 + uStack_16 + 0x1f);
    uVar9 = CONCAT11((char)((int)uVar9 % iVar18),(char)((int)uVar9 / iVar18));
  }
  uVar6 = *(uint *)(puVar21 + (uVar17 - 0x60));
  uVar10 = uVar9;
  if (((uVar9 <= uVar6) || (uVar9 = uVar9 - uVar6, uVar10 = uVar6, uVar9 < 3)) &&
     (uVar9 = uVar10 + 1, uVar9 < uStack_16)) {
    *(uint *)0x4400 = uVar17;
    *(uint *)(puVar21 + uVar17) = uVar9;
    cVar8 = (char)(uVar6 >> 8);
    uStack_c = CONCAT11(cVar8,0x40);
    uStack_10 = CONCAT11((char)(uVar17 >> 8),(char)uVar17 + *(char *)0x556e);
    uVar10 = uVar10 + 2;
    puStack_12 = &stack0xfff8;
    uStack_e = *(uint *)(puVar21 + (uStack_10 - 0x60));
    if (uStack_e < uVar10) {
      unaff_BP[uStack_16] = unaff_BP[uStack_16] ^ (byte)(uVar10 - uStack_e);
      return CONCAT22(uStack_e,uVar10 - uStack_e);
    }
    bVar7 = (byte)uVar10 / 0x3d;
    uVar17 = CONCAT11(bVar7,(byte)uVar10 % 0x3d);
    if (!SBORROW2(uVar10,uStack_e)) {
      return CONCAT22(unaff_SS,uVar17);
    }
    puStack_a = (undefined1 *)(uVar17 ^ 4);
    pbVar1 = unaff_BP + (int)(puVar20 + -0x7c70);
    bVar15 = *pbVar1;
    bVar24 = (byte)puStack_a;
    *pbVar1 = *pbVar1 + bVar24;
    LOCK();
    piVar2 = (int *)(uStack_10 + uStack_16 + 0x5d);
    *piVar2 = *piVar2 + -0x2b + (uint)CARRY1(bVar15,bVar24);
    UNLOCK();
    unaff_BP[(int)(puVar20 + -0x7c70)] = unaff_BP[(int)(puVar20 + -0x7c70)] + bVar24 + 0x60;
    unaff_BP[uStack_16 - 0x75] = unaff_BP[uStack_16 - 0x75] & (byte)uStack_e;
    *(int *)(uStack_10 + uStack_16) = *(int *)(uStack_10 + uStack_16) + 0x2200;
    puVar3 = (undefined1 *)(uStack_10 + uStack_16 + 0x32);
    *puVar3 = *puVar3;
    bVar15 = cVar8 + 1;
    iVar14 = CONCAT11(bVar15,0x40);
    iVar18 = uStack_10 - 2;
    if (1 < uStack_10) {
      *(int *)(puVar21 + uStack_10) = *(int *)(puVar21 + uStack_10) + CONCAT11(bVar7,bVar24 + 0x60);
      uVar17 = CONCAT11(bVar7,2) | 0x20bd;
      bVar24 = (byte)uVar17;
      bVar7 = bVar24 + 0x73;
      *(uint *)(unaff_BP + uStack_16) =
           *(int *)(unaff_BP + uStack_16) + CONCAT11((char)(uVar17 >> 8),bVar7) +
           (uint)(0x8c < bVar24);
      bVar15 = bVar15 | (byte)(uStack_e >> 8);
      in_AF = 9 < (bVar7 & 0xf) | in_AF;
      pbVar1 = puVar19 + 0x2f2f;
      bVar7 = *pbVar1 + (byte)iVar18;
      cVar8 = CARRY1(*pbVar1,(byte)iVar18) || CARRY1(bVar7,in_AF);
      *pbVar1 = bVar7 + in_AF;
      puStack_18 = puVar21;
      puStack_14 = unaff_BP;
      FUN_1000_5bbb();
      uVar26 = FUN_1000_a3c1();
      cVar8 = (char)uVar26 + *(char *)0x2f35 + cVar8;
      out((int)((ulong)uVar26 >> 0x10),cVar8);
      puStack_18 = (undefined1 *)(CONCAT11((char)((ulong)uVar26 >> 8),cVar8) + -1);
      in_AF = 9 < ((byte)puStack_18 & 0xf) | in_AF;
      puVar19[0x2f37] = puVar19[0x2f37] + (char)iVar18 + in_AF;
      bVar24 = ((CONCAT11((char)((uint)puStack_18 >> 8) - in_AF,(byte)puStack_18 + in_AF * -6) &
                0xff0f) + 0xbf2f & 0x1000) != 0;
      cVar8 = -0x41;
      func_0x0001f1ba();
      uVar12 = CONCAT11(bVar15,cVar8 + (char)extraout_DX_02);
      puVar19[0x2f37] = puVar19[0x2f37] + (char)((uint)extraout_DX_02 >> 8);
      uVar17 = CONCAT11(extraout_AH - bVar24,bVar24 * -6) & 0xff0f;
      pbVar1 = puVar19 + 0x2f3f;
      bVar7 = *pbVar1 + (byte)iVar18;
      cVar8 = CARRY1(*pbVar1,(byte)iVar18) || CARRY1(bVar7,bVar24);
      *pbVar1 = bVar7 + bVar24;
      puStack_18 = unaff_BP;
      func_0x00015bb1();
      puStack_18 = (undefined1 *)0x9c27;
      uVar26 = func_0x0001ebb7();
      uStack_e = (uint)((ulong)uVar26 >> 0x10);
      uStack_16 = uVar17 + 1;
      puStack_a = (undefined1 *)
                  (CONCAT11((char)((ulong)uVar26 >> 8),(char)uVar26 + unaff_BP[uVar17] + cVar8) + -1
                  );
      puStack_18 = (undefined1 *)0x3e9b;
      unaff_BP[uVar17 + 0xbe9a] = unaff_BP[uVar17 + 0xbe9a] | (byte)puStack_a;
      puVar20 = puVar19 + -7;
      bVar24 = 9 < ((byte)puStack_a & 0xf) | bVar24;
      cVar23 = '\0';
      puVar20[uStack_16] = puVar20[uStack_16] & (byte)iVar18;
      puStack_14 = unaff_BP;
      puStack_12 = &stack0xfff8;
      uStack_10 = iVar18;
      uStack_c = uVar12;
      func_0x00015ba8();
      bVar15 = (byte)uVar12;
      puStack_18 = (undefined1 *)0x9c42;
      cVar8 = FUN_1000_20ae();
      bVar7 = cVar8 + puVar19[0x2f0e] + cVar23;
      *(byte *)(iVar18 + 0x2f75) = *(byte *)(iVar18 + 0x2f75) | 8;
      puVar19[0x554e] = puVar19[0x554e] & (byte)iVar18;
      cVar23 = 0x99 < (bVar7 + (9 < (bVar7 & 0xf) | bVar24) * -6 & 0xf);
      uStack_16 = 0x9c5c;
      puStack_14 = puVar20;
      FUN_1000_5ba1();
      puStack_14 = (undefined1 *)0x9c5f;
      uVar12 = FUN_1000_33a7();
      cVar8 = puVar19[0x554d];
      cVar13 = (char)((uint)uVar12 >> 8);
      puVar20[uStack_10] = puVar20[uStack_10] | (byte)((uint)iVar18 >> 8);
      *(byte *)(iVar18 + 0x3f5d) = *(byte *)(iVar18 + 0x3f5d) & bVar15;
      return CONCAT22((int)cVar13 >> 7,CONCAT11(cVar13,(char)uVar12 + cVar8 + cVar23));
    }
    LOCK();
    uVar17 = *(uint *)(unaff_BP + uStack_16);
    *(uint *)(unaff_BP + uStack_16) = uStack_e;
    UNLOCK();
    bVar7 = in(uVar17);
    iVar11 = (uint)bVar7 * 0x80;
    pcVar22 = (char *)(iVar11 + 0x2400);
    LOCK();
    iVar5 = *(int *)(unaff_BP + uStack_16);
    *(undefined1 ***)(unaff_BP + uStack_16) = &puStack_18;
    UNLOCK();
    *(undefined2 *)(iVar5 + -2) = unaff_CS;
    *(undefined2 *)(puVar19 + 6) = 0;
    unaff_BP[uStack_16] = unaff_BP[uStack_16] & 6;
    LOCK();
    *(int *)(iVar18 + uStack_16) = iVar11 + *(int *)(unaff_BP + uStack_16 + 0x4212);
    UNLOCK();
    pcVar4 = (char *)(iVar18 + uStack_16 + 0x75);
    *pcVar4 = *pcVar4 + '@';
    puVar19 = unaff_BP + iVar14;
    *pcVar22 = *pcVar22 + (char)((uint)iVar18 >> 8);
    LOCK();
    *(uint *)(puVar19 + uStack_16 + 3) = *(int *)(puVar19 + uStack_16 + 3) + uStack_16;
    UNLOCK();
    *(uint *)(puVar19 + (int)pcVar22 + 0x71) = *(int *)(puVar19 + (int)pcVar22 + 0x71) + uStack_16;
    *(int *)(iVar11 + 0x247c) = iVar14;
    *(int *)(iVar11 + 0x247e) = iVar14;
    *(int *)(puVar19 + 0xc) = iVar14;
    *pcVar22 = '@';
    puVar19[uStack_16 + 0x2b0] = puVar19[uStack_16 + 0x2b0];
    *(undefined1 *)(iVar11 + 0x2401) = 3;
    puVar19[uStack_16 + 0x55] = puVar19[uStack_16 + 0x55] + 'V';
    puVar19[uStack_16 + 0x610] = 0;
    bVar7 = (byte)(uVar17 >> 9);
    *(undefined1 *)(iVar11 + 0x2402) = 2;
    puVar19[uStack_16] = puVar19[uStack_16] ^ 2;
    uVar16 = puVar19[uStack_16 + 0x1610];
    *(byte *)(iVar11 + 0x2403) = bVar7;
    if (CONCAT11(uVar16,3) == 1) {
      *(byte *)(iVar11 + 0x2403) = bVar7;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar8 = (char)((uint)iVar14 >> 8) + -1;
  iVar14 = CONCAT11(cVar8,(char)iVar14);
  if (cVar8 == '\0') goto FUN_1000_8945;
  uVar17 = uVar17 + 2;
  goto LAB_1000_8911;
}


