/* 1000:8844 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018853) overlaps instruction at (ram,0x00018852)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_8844(void)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  undefined2 in_AX;
  uint uVar10;
  uint uVar11;
  byte bVar13;
  int iVar12;
  char extraout_AH;
  uint in_CX;
  undefined2 uVar14;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int extraout_DX_01;
  undefined2 extraout_DX_02;
  uint uVar15;
  int iVar16;
  undefined2 *unaff_BP;
  int iVar17;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  char *pcVar18;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  bool in_ZF;
  bool bVar19;
  undefined4 uVar20;
  undefined2 *puStack_18;
  uint uStack_16;
  undefined2 *puStack_14;
  undefined1 *puStack_12;
  uint uStack_10;
  uint uStack_e;
  undefined2 uStack_c;
  uint uStack_a;
  
  *unaff_SI = in_AX;
  if (in_ZF) {
LAB_1000_88f9:
    in(in_DX);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_1000_884b:
  while( true ) {
    do {
      in_CX = in_CX & 0xff;
      FUN_1000_8a1a();
      unaff_DI = unaff_DI + -0x30;
      if (((int)unaff_DI < 0) ||
         (bVar19 = unaff_DI == (undefined2 *)0x1200, (undefined2 *)0x11ff < unaff_DI))
      goto FUN_1000_88e6;
      in_CX = CONCAT11((char)in_CX + (char)(in_CX >> 8),(char)in_CX);
      func_0x0001890b();
      if (bVar19) goto FUN_1000_88e6;
      uVar15 = in_CX >> 8;
      in_CX = in_CX & 0xff;
      in_DX = extraout_DX;
      if ((char)((uint)extraout_DX >> 8) == (char)uVar15) {
        FUN_1000_8a1a();
        in_DX = extraout_DX_00;
      }
      if (&stack0x000a < (undefined1 *)0x6040) goto LAB_1000_88f9;
      cVar8 = (char)in_DX;
      if (1 < (byte)(in_CX >> 8)) {
        cVar8 = (char)in_CX;
        unaff_SI = unaff_DI;
      }
      bVar7 = (cVar8 - (char)((uint)in_DX >> 8)) + 1;
      if (bVar7 < 3) goto FUN_1000_88e6;
    } while (-1 < (char)bVar7);
    uVar15 = *(int *)0x4402 + 2;
    bVar19 = uVar15 == 0x60;
    if ((uVar15 < 0x60) && (cVar8 = FUN_1000_8909(), !bVar19)) break;
FUN_1000_88e6:
    *(char *)((int)unaff_DI + (int)(unaff_BP + -0x1d1)) =
         *(char *)((int)unaff_DI + (int)(unaff_BP + -0x1d1)) + -1;
    unaff_DI = (undefined2 *)unaff_BP[-3];
    unaff_BP = unaff_BP + -3;
  }
  pbVar1 = (byte *)0x8a32;
  *pbVar1 = *pbVar1 & cVar8 - 1U;
  in_CX = in_CX - 1;
  if (in_CX == 0 || *pbVar1 != 0) {
    pbVar1 = (byte *)((int)unaff_SI + (int)unaff_BP + -0x3115);
    *pbVar1 = *pbVar1 & cVar8 - 1U;
    goto LAB_1000_884b;
  }
  uVar10 = *(uint *)((int)unaff_DI + (uVar15 - 0x60));
  iVar17 = extraout_DX_01;
  do {
    cVar8 = (char)((uint)iVar17 >> 8);
    uStack_16 = *(uint *)(uVar15 + (int)unaff_DI);
    if ((int)uStack_16 < 0) {
      cVar8 = cVar8 + -1;
      if (cVar8 == '\0') {
FUN_1000_8945:
        *(uint *)0x4402 = uVar15;
        *(char *)(uVar15 + uStack_16) = *(char *)(uVar15 + uStack_16) + '\x1e';
        return;
      }
      uVar15 = uVar15 + 2;
      piVar2 = (int *)((int)unaff_DI + (int)unaff_BP + 0xb1);
      *piVar2 = *piVar2 + -1;
      *(char *)((int)unaff_BP + (int)unaff_DI) =
           *(char *)((int)unaff_BP + (int)unaff_DI) + (char)(uVar10 >> 8);
      iVar17 = (int)*(char *)(uVar15 + uStack_16 + 0x1f);
      uVar10 = CONCAT11((char)((int)uVar10 % iVar17),(char)((int)uVar10 / iVar17));
    }
    uVar6 = *(uint *)((int)unaff_DI + (uVar15 - 0x60));
    uVar11 = uVar10;
    if (((uVar10 <= uVar6) || (uVar10 = uVar10 - uVar6, uVar11 = uVar6, uVar10 < 3)) &&
       (uVar10 = uVar11 + 1, uVar10 < uStack_16)) {
      *(uint *)0x4400 = uVar15;
      *(uint *)(uVar15 + (int)unaff_DI) = uVar10;
      cVar8 = (char)(uVar6 >> 8);
      uStack_c = CONCAT11(cVar8,0x40);
      uStack_10 = CONCAT11((char)(uVar15 >> 8),(char)uVar15 + *(char *)0x556e);
      uVar11 = uVar11 + 2;
      puStack_12 = &stack0xfff8;
      uStack_e = *(uint *)((int)unaff_DI + (uStack_10 - 0x60));
      bVar7 = (byte)uVar11;
      if (uStack_e < uVar11) {
        *(byte *)((int)unaff_BP + uStack_16) =
             *(byte *)((int)unaff_BP + uStack_16) ^ bVar7 - (byte)uStack_e;
        return;
      }
      bVar13 = bVar7 / 0x3d;
      if (!SBORROW2(uVar11,uStack_e)) {
        return;
      }
      uStack_a = CONCAT11(bVar13,bVar7 % 0x3d) ^ 4;
      pbVar1 = (byte *)((int)unaff_DI + (int)(unaff_BP + -0x3e08));
      bVar7 = *pbVar1;
      bVar9 = (byte)uStack_a;
      *pbVar1 = *pbVar1 + bVar9;
      LOCK();
      piVar2 = (int *)(uStack_10 + uStack_16 + 0x5d);
      *piVar2 = *piVar2 + -0x2b + (uint)CARRY1(bVar7,bVar9);
      UNLOCK();
      *(char *)((int)unaff_DI + (int)(unaff_BP + -0x3e08)) =
           *(char *)((int)unaff_DI + (int)(unaff_BP + -0x3e08)) + bVar9 + 0x60;
      pbVar1 = (byte *)((int)unaff_BP + (uStack_16 - 0x75));
      *pbVar1 = *pbVar1 & (byte)uStack_e;
      *(int *)(uStack_10 + uStack_16) = *(int *)(uStack_10 + uStack_16) + 0x2200;
      puVar3 = (undefined1 *)(uStack_10 + uStack_16 + 0x32);
      *puVar3 = *puVar3;
      bVar7 = cVar8 + 1;
      iVar17 = CONCAT11(bVar7,0x40);
      iVar16 = uStack_10 - 2;
      if (1 < uStack_10) {
        *(int *)((int)unaff_DI + uStack_10) =
             *(int *)((int)unaff_DI + uStack_10) + CONCAT11(bVar13,bVar9 + 0x60);
        uVar15 = CONCAT11(bVar13,2) | 0x20bd;
        bVar9 = (byte)uVar15;
        bVar13 = bVar9 + 0x73;
        *(int *)((int)unaff_BP + uStack_16) =
             *(int *)((int)unaff_BP + uStack_16) + CONCAT11((char)(uVar15 >> 8),bVar13) +
             (uint)(0x8c < bVar9);
        bVar7 = bVar7 | (byte)(uStack_e >> 8);
        in_AF = 9 < (bVar13 & 0xf) | in_AF;
        pbVar1 = (byte *)((int)unaff_BP + 0x2f35);
        bVar13 = *pbVar1 + (byte)iVar16;
        cVar8 = CARRY1(*pbVar1,(byte)iVar16) || CARRY1(bVar13,in_AF);
        *pbVar1 = bVar13 + in_AF;
        puStack_18 = unaff_DI;
        puStack_14 = unaff_BP;
        FUN_1000_5bbb();
        uVar20 = FUN_1000_a3c1();
        cVar8 = (char)uVar20 + *(char *)0x2f35 + cVar8;
        out((int)((ulong)uVar20 >> 0x10),cVar8);
        puStack_18 = (undefined2 *)(CONCAT11((char)((ulong)uVar20 >> 8),cVar8) + -1);
        in_AF = 9 < ((byte)puStack_18 & 0xf) | in_AF;
        *(char *)((int)unaff_BP + 0x2f3d) = *(char *)((int)unaff_BP + 0x2f3d) + (char)iVar16 + in_AF
        ;
        bVar13 = ((CONCAT11((char)((uint)puStack_18 >> 8) - in_AF,(byte)puStack_18 + in_AF * -6) &
                  0xff0f) + 0xbf2f & 0x1000) != 0;
        cVar8 = -0x41;
        func_0x0001f1ba();
        uVar14 = CONCAT11(bVar7,cVar8 + (char)extraout_DX_02);
        *(char *)((int)unaff_BP + 0x2f3d) =
             *(char *)((int)unaff_BP + 0x2f3d) + (char)((uint)extraout_DX_02 >> 8);
        uVar15 = CONCAT11(extraout_AH - bVar13,bVar13 * -6) & 0xff0f;
        pbVar1 = (byte *)((int)unaff_BP + 0x2f45);
        bVar7 = *pbVar1 + (byte)iVar16;
        cVar8 = CARRY1(*pbVar1,(byte)iVar16) || CARRY1(bVar7,bVar13);
        *pbVar1 = bVar7 + bVar13;
        puStack_18 = unaff_BP;
        func_0x00015bb1();
        puStack_18 = (undefined2 *)0x9c27;
        uVar20 = func_0x0001ebb7();
        uStack_e = (uint)((ulong)uVar20 >> 0x10);
        uStack_16 = uVar15 + 1;
        uStack_a = CONCAT11((char)((ulong)uVar20 >> 8),
                            (char)uVar20 + *(char *)((int)unaff_BP + uVar15) + cVar8) + -1;
        puStack_18 = (undefined2 *)0x3e9b;
        pbVar1 = (byte *)((int)unaff_BP + uVar15 + 0xbe9a);
        *pbVar1 = *pbVar1 | (byte)uStack_a;
        iVar17 = (int)unaff_BP + -1;
        *(byte *)(iVar17 + uStack_16) = *(byte *)(iVar17 + uStack_16) & (byte)iVar16;
        puStack_14 = unaff_BP;
        puStack_12 = &stack0xfff8;
        uStack_10 = iVar16;
        uStack_c = uVar14;
        func_0x00015ba8();
        bVar7 = (byte)uVar14;
        puStack_18 = (undefined2 *)0x9c42;
        FUN_1000_20ae();
        *(byte *)(iVar16 + 0x2f75) = *(byte *)(iVar16 + 0x2f75) | 8;
        *(byte *)(unaff_BP + 0x2aaa) = *(byte *)(unaff_BP + 0x2aaa) & (byte)iVar16;
        uStack_16 = 0x9c5c;
        puStack_14 = (undefined2 *)iVar17;
        FUN_1000_5ba1();
        puStack_14 = (undefined2 *)0x9c5f;
        FUN_1000_33a7();
        *(byte *)(iVar17 + uStack_10) = *(byte *)(iVar17 + uStack_10) | (byte)((uint)iVar16 >> 8);
        *(byte *)(iVar16 + 0x3f5d) = *(byte *)(iVar16 + 0x3f5d) & bVar7;
        return;
      }
      LOCK();
      uVar15 = *(uint *)((int)unaff_BP + uStack_16);
      *(uint *)((int)unaff_BP + uStack_16) = uStack_e;
      UNLOCK();
      bVar7 = in(uVar15);
      iVar12 = (uint)bVar7 * 0x80;
      pcVar18 = (char *)(iVar12 + 0x2400);
      LOCK();
      iVar5 = *(int *)((int)unaff_BP + uStack_16);
      *(int *)((int)unaff_BP + uStack_16) = (int)&puStack_18;
      UNLOCK();
      *(undefined2 *)(iVar5 + -2) = unaff_CS;
      unaff_BP[6] = 0;
      *(byte *)((int)unaff_BP + uStack_16) = *(byte *)((int)unaff_BP + uStack_16) & 6;
      LOCK();
      *(int *)(iVar16 + uStack_16) = iVar12 + *(int *)((int)unaff_BP + uStack_16 + 0x4212);
      UNLOCK();
      pcVar4 = (char *)(iVar16 + uStack_16 + 0x75);
      *pcVar4 = *pcVar4 + '@';
      *pcVar18 = *pcVar18 + (char)((uint)iVar16 >> 8);
      LOCK();
      piVar2 = (int *)((int)unaff_BP + uStack_16 + iVar17 + 3);
      *piVar2 = *piVar2 + uStack_16;
      UNLOCK();
      *(uint *)(pcVar18 + (int)unaff_BP + iVar17 + 0x71) =
           *(int *)(pcVar18 + (int)unaff_BP + iVar17 + 0x71) + uStack_16;
      *(int *)(iVar12 + 0x247c) = iVar17;
      *(int *)(iVar12 + 0x247e) = iVar17;
      *(int *)((int)unaff_BP + iVar17 + 0xc) = iVar17;
      *pcVar18 = '@';
      puVar3 = (undefined1 *)((int)unaff_BP + uStack_16 + iVar17 + 0x2b0);
      *puVar3 = *puVar3;
      *(undefined1 *)(iVar12 + 0x2401) = 3;
      pcVar4 = (char *)((int)unaff_BP + uStack_16 + iVar17 + 0x55);
      *pcVar4 = *pcVar4 + 'V';
      *(undefined1 *)((int)unaff_BP + uStack_16 + iVar17 + 0x610) = 0;
      bVar7 = (byte)(uVar15 >> 9);
      *(undefined1 *)(iVar12 + 0x2402) = 2;
      pbVar1 = (byte *)((int)unaff_BP + uStack_16 + iVar17);
      *pbVar1 = *pbVar1 ^ 2;
      cVar8 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[(int)unaff_BP + uStack_16 + iVar17]
      ;
      *(byte *)(iVar12 + 0x2403) = bVar7;
      if (CONCAT11(cVar8,3) == 1) {
        *(byte *)(iVar12 + 0x2403) = bVar7;
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar17 = (uint)(byte)(cVar8 - 1U) << 8;
    if ((byte)(cVar8 - 1U) == 0) goto FUN_1000_8945;
    uVar15 = uVar15 + 2;
  } while( true );
}


