/* 1000:8859 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_8859(void)

{
  char *pcVar1;
  byte *pbVar2;
  int *piVar3;
  undefined1 *puVar4;
  uint uVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  byte bVar12;
  int iVar11;
  char extraout_AH;
  uint in_CX;
  undefined2 uVar13;
  int in_DX;
  int extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  undefined2 extraout_DX_02;
  uint uVar14;
  int iVar15;
  uint unaff_BP;
  int iVar16;
  int iVar17;
  uint unaff_SI;
  uint unaff_DI;
  char *pcVar18;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  bool bVar19;
  undefined4 uVar20;
  uint uStack_18;
  uint uStack_16;
  uint uStack_14;
  undefined1 *puStack_12;
  uint uStack_10;
  uint uStack_e;
  undefined2 uStack_c;
  uint uStack_a;
  
  do {
    unaff_DI = unaff_DI + (int)(char)in_DX;
    if (((int)unaff_DI < 0) || (bVar19 = unaff_DI == 0x1200, 0x11ff < unaff_DI)) {
FUN_1000_88e6:
      cVar7 = (char)((uint)in_DX >> 8);
      pcVar1 = (char *)(unaff_BP + unaff_DI + -0x3a2);
      *pcVar1 = *pcVar1 + -1;
      unaff_DI = *(uint *)(unaff_BP - 6);
      unaff_BP = unaff_BP - 6;
    }
    else {
      in_CX = CONCAT11((char)((uint)in_DX >> 8),(char)in_CX);
      func_0x0001890b();
      in_DX = extraout_DX;
      if (bVar19) goto FUN_1000_88e6;
      uVar14 = in_CX >> 8;
      in_CX = in_CX & 0xff;
      iVar17 = extraout_DX;
      if ((char)((uint)extraout_DX >> 8) == (char)uVar14) {
        FUN_1000_8a1a();
        iVar17 = extraout_DX_00;
      }
      if (&stack0x000a < (undefined1 *)0x6040) {
        in(iVar17);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      cVar7 = (char)iVar17;
      if (1 < (byte)(in_CX >> 8)) {
        cVar7 = (char)in_CX;
        unaff_SI = unaff_DI;
      }
      bVar6 = (cVar7 - (char)((uint)iVar17 >> 8)) + 1;
      if (bVar6 < 3) {
LAB_1000_88e4:
        in_DX = *(int *)(unaff_BP - 2);
        goto FUN_1000_88e6;
      }
      if ((char)bVar6 < '\0') {
        uVar14 = *(int *)0x4402 + 2;
        bVar19 = uVar14 == 0x60;
        if ((0x5f < uVar14) || (cVar7 = FUN_1000_8909(), bVar19)) goto LAB_1000_88e4;
        pbVar2 = (byte *)0x8a32;
        *pbVar2 = *pbVar2 & cVar7 - 1U;
        in_CX = in_CX - 1;
        if (in_CX != 0 && *pbVar2 == 0) break;
        pbVar2 = (byte *)(unaff_BP + unaff_SI + -0x3115);
        *pbVar2 = *pbVar2 & cVar7 - 1U;
        iVar17 = extraout_DX_01;
      }
      cVar7 = -(((char)((uint)iVar17 >> 8) + '\x01') - (char)in_CX);
    }
    in_DX = CONCAT11(cVar7,0xa0);
  } while( true );
  uVar9 = *(uint *)(uVar14 + unaff_DI + -0x60);
  iVar17 = extraout_DX_01;
  do {
    cVar7 = (char)((uint)iVar17 >> 8);
    uStack_16 = *(uint *)(uVar14 + unaff_DI);
    if ((int)uStack_16 < 0) {
      cVar7 = cVar7 + -1;
      if (cVar7 == '\0') {
FUN_1000_8945:
        *(uint *)0x4402 = uVar14;
        *(char *)(uVar14 + uStack_16) = *(char *)(uVar14 + uStack_16) + '\x1e';
        return;
      }
      uVar14 = uVar14 + 2;
      piVar3 = (int *)(unaff_BP + unaff_DI + 0xb1);
      *piVar3 = *piVar3 + -1;
      *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + (char)(uVar9 >> 8);
      iVar17 = (int)*(char *)(uVar14 + uStack_16 + 0x1f);
      uVar9 = CONCAT11((char)((int)uVar9 % iVar17),(char)((int)uVar9 / iVar17));
    }
    uVar5 = *(uint *)(uVar14 + unaff_DI + -0x60);
    uVar10 = uVar9;
    if (((uVar9 <= uVar5) || (uVar9 = uVar9 - uVar5, uVar10 = uVar5, uVar9 < 3)) &&
       (uVar9 = uVar10 + 1, uVar9 < uStack_16)) {
      *(uint *)0x4400 = uVar14;
      *(uint *)(uVar14 + unaff_DI) = uVar9;
      cVar7 = (char)(uVar5 >> 8);
      uStack_c = CONCAT11(cVar7,0x40);
      uStack_10 = CONCAT11((char)(uVar14 >> 8),(char)uVar14 + *(char *)0x556e);
      uVar10 = uVar10 + 2;
      puStack_12 = &stack0xfff8;
      uStack_e = *(uint *)(uStack_10 + unaff_DI + -0x60);
      bVar6 = (byte)uVar10;
      if (uStack_e < uVar10) {
        *(byte *)(unaff_BP + uStack_16) = *(byte *)(unaff_BP + uStack_16) ^ bVar6 - (byte)uStack_e;
        return;
      }
      bVar12 = bVar6 / 0x3d;
      if (!SBORROW2(uVar10,uStack_e)) {
        return;
      }
      uStack_a = CONCAT11(bVar12,bVar6 % 0x3d) ^ 4;
      pbVar2 = (byte *)(unaff_BP + unaff_DI + -0x7c10);
      bVar6 = *pbVar2;
      bVar8 = (byte)uStack_a;
      *pbVar2 = *pbVar2 + bVar8;
      LOCK();
      piVar3 = (int *)(uStack_10 + uStack_16 + 0x5d);
      *piVar3 = *piVar3 + -0x2b + (uint)CARRY1(bVar6,bVar8);
      UNLOCK();
      pcVar1 = (char *)(unaff_BP + unaff_DI + -0x7c10);
      *pcVar1 = *pcVar1 + bVar8 + 0x60;
      pbVar2 = (byte *)(unaff_BP + uStack_16 + -0x75);
      *pbVar2 = *pbVar2 & (byte)uStack_e;
      *(int *)(uStack_10 + uStack_16) = *(int *)(uStack_10 + uStack_16) + 0x2200;
      puVar4 = (undefined1 *)(uStack_10 + uStack_16 + 0x32);
      *puVar4 = *puVar4;
      bVar6 = cVar7 + 1;
      iVar17 = CONCAT11(bVar6,0x40);
      iVar15 = uStack_10 - 2;
      if (1 < uStack_10) {
        piVar3 = (int *)(iVar15 + unaff_DI + 2);
        *piVar3 = *piVar3 + CONCAT11(bVar12,bVar8 + 0x60);
        uVar14 = CONCAT11(bVar12,2) | 0x20bd;
        bVar8 = (byte)uVar14;
        bVar12 = bVar8 + 0x73;
        *(int *)(unaff_BP + uStack_16) =
             *(int *)(unaff_BP + uStack_16) + CONCAT11((char)(uVar14 >> 8),bVar12) +
             (uint)(0x8c < bVar8);
        bVar6 = bVar6 | (byte)(uStack_e >> 8);
        in_AF = 9 < (bVar12 & 0xf) | in_AF;
        pbVar2 = (byte *)(unaff_BP + 0x2f35);
        bVar12 = *pbVar2 + (byte)iVar15;
        cVar7 = CARRY1(*pbVar2,(byte)iVar15) || CARRY1(bVar12,in_AF);
        *pbVar2 = bVar12 + in_AF;
        uStack_18 = unaff_DI;
        uStack_14 = unaff_BP;
        FUN_1000_5bbb();
        uVar20 = FUN_1000_a3c1();
        cVar7 = (char)uVar20 + *(char *)0x2f35 + cVar7;
        out((int)((ulong)uVar20 >> 0x10),cVar7);
        uStack_18 = CONCAT11((char)((ulong)uVar20 >> 8),cVar7) - 1;
        in_AF = 9 < ((byte)uStack_18 & 0xf) | in_AF;
        *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)iVar15 + in_AF;
        bVar12 = ((CONCAT11((char)(uStack_18 >> 8) - in_AF,(byte)uStack_18 + in_AF * -6) & 0xff0f) +
                  0xbf2f & 0x1000) != 0;
        cVar7 = -0x41;
        func_0x0001f1ba();
        uVar13 = CONCAT11(bVar6,cVar7 + (char)extraout_DX_02);
        *(char *)(unaff_BP + 0x2f3d) =
             *(char *)(unaff_BP + 0x2f3d) + (char)((uint)extraout_DX_02 >> 8);
        uVar14 = CONCAT11(extraout_AH - bVar12,bVar12 * -6) & 0xff0f;
        pbVar2 = (byte *)(unaff_BP + 0x2f45);
        bVar6 = *pbVar2 + (byte)iVar15;
        cVar7 = CARRY1(*pbVar2,(byte)iVar15) || CARRY1(bVar6,bVar12);
        *pbVar2 = bVar6 + bVar12;
        uStack_18 = unaff_BP;
        func_0x00015bb1();
        uStack_18 = 0x9c27;
        uVar20 = func_0x0001ebb7();
        uStack_e = (uint)((ulong)uVar20 >> 0x10);
        uStack_16 = uVar14 + 1;
        uStack_a = CONCAT11((char)((ulong)uVar20 >> 8),
                            (char)uVar20 + *(char *)(unaff_BP + uVar14) + cVar7) + -1;
        uStack_18 = 0x3e9b;
        pbVar2 = (byte *)(unaff_BP + uStack_16 + -0x4167);
        *pbVar2 = *pbVar2 | (byte)uStack_a;
        iVar17 = unaff_BP - 1;
        *(byte *)(iVar17 + uStack_16) = *(byte *)(iVar17 + uStack_16) & (byte)iVar15;
        uStack_14 = unaff_BP;
        puStack_12 = &stack0xfff8;
        uStack_10 = iVar15;
        uStack_c = uVar13;
        func_0x00015ba8();
        bVar6 = (byte)uVar13;
        uStack_18 = 0x9c42;
        FUN_1000_20ae();
        *(byte *)(iVar15 + 0x2f75) = *(byte *)(iVar15 + 0x2f75) | 8;
        *(byte *)(unaff_BP + 0x5554) = *(byte *)(unaff_BP + 0x5554) & (byte)iVar15;
        uStack_16 = 0x9c5c;
        uStack_14 = iVar17;
        FUN_1000_5ba1();
        uStack_14 = 0x9c5f;
        FUN_1000_33a7();
        *(byte *)(iVar17 + uStack_10) = *(byte *)(iVar17 + uStack_10) | (byte)((uint)iVar15 >> 8);
        *(byte *)(iVar15 + 0x3f5d) = *(byte *)(iVar15 + 0x3f5d) & bVar6;
        return;
      }
      LOCK();
      uVar14 = *(uint *)(unaff_BP + uStack_16);
      *(uint *)(unaff_BP + uStack_16) = uStack_e;
      UNLOCK();
      bVar6 = in(uVar14);
      iVar11 = (uint)bVar6 * 0x80;
      pcVar18 = (char *)(iVar11 + 0x2400);
      LOCK();
      iVar16 = *(int *)(unaff_BP + uStack_16);
      *(int *)(unaff_BP + uStack_16) = (int)&uStack_18;
      UNLOCK();
      *(undefined2 *)(iVar16 + -2) = unaff_CS;
      *(undefined2 *)(unaff_BP + 0xc) = 0;
      *(byte *)(unaff_BP + uStack_16) = *(byte *)(unaff_BP + uStack_16) & 6;
      LOCK();
      *(int *)(iVar15 + uStack_16) = iVar11 + *(int *)(unaff_BP + uStack_16 + 0x4212);
      UNLOCK();
      pcVar1 = (char *)(iVar15 + uStack_16 + 0x75);
      *pcVar1 = *pcVar1 + '@';
      iVar16 = unaff_BP + iVar17;
      *pcVar18 = *pcVar18 + (char)((uint)iVar15 >> 8);
      LOCK();
      piVar3 = (int *)(iVar16 + uStack_16 + 3);
      *piVar3 = *piVar3 + uStack_16;
      UNLOCK();
      *(uint *)(pcVar18 + iVar16 + 0x71) = *(int *)(pcVar18 + iVar16 + 0x71) + uStack_16;
      *(int *)(iVar11 + 0x247c) = iVar17;
      *(int *)(iVar11 + 0x247e) = iVar17;
      *(int *)(iVar16 + 0xc) = iVar17;
      *pcVar18 = '@';
      puVar4 = (undefined1 *)(iVar16 + uStack_16 + 0x2b0);
      *puVar4 = *puVar4;
      *(undefined1 *)(iVar11 + 0x2401) = 3;
      pcVar1 = (char *)(iVar16 + uStack_16 + 0x55);
      *pcVar1 = *pcVar1 + 'V';
      *(undefined1 *)(iVar16 + uStack_16 + 0x610) = 0;
      bVar6 = (byte)(uVar14 >> 9);
      *(undefined1 *)(iVar11 + 0x2402) = 2;
      *(byte *)(iVar16 + uStack_16) = *(byte *)(iVar16 + uStack_16) ^ 2;
      cVar7 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar16 + uStack_16];
      *(byte *)(iVar11 + 0x2403) = bVar6;
      if (CONCAT11(cVar7,3) == 1) {
        *(byte *)(iVar11 + 0x2403) = bVar6;
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar17 = (uint)(byte)(cVar7 - 1U) << 8;
    if ((byte)(cVar7 - 1U) == 0) goto FUN_1000_8945;
    uVar14 = uVar14 + 2;
  } while( true );
}


