/* 1000:8909 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_8909(void)

{
  byte *pbVar1;
  char *pcVar2;
  int *piVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  char extraout_AH;
  byte bVar13;
  int in_DX;
  undefined2 extraout_DX;
  int in_BX;
  uint uVar14;
  int iVar15;
  int unaff_BP;
  int iVar16;
  int unaff_DI;
  char *pcVar17;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar18;
  char cVar19;
  byte in_AF;
  undefined4 uVar20;
  
  uVar9 = *(uint *)(in_BX + unaff_DI + -0x60);
  do {
    cVar18 = (char)((uint)in_DX >> 8);
    uVar5 = *(uint *)(in_BX + unaff_DI);
    if ((int)uVar5 < 0) {
      cVar18 = cVar18 + -1;
      if (cVar18 == '\0') {
FUN_1000_8945:
        *(int *)0x4402 = in_BX;
        *(char *)(in_BX + uVar5) = *(char *)(in_BX + uVar5) + '\x1e';
        return;
      }
      in_BX = in_BX + 2;
      piVar3 = (int *)(unaff_BP + unaff_DI + 0xb1);
      *piVar3 = *piVar3 + -1;
      *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + (char)(uVar9 >> 8);
      iVar12 = (int)*(char *)(in_BX + uVar5 + 0x1f);
      uVar9 = CONCAT11((char)((int)uVar9 % iVar12),(char)((int)uVar9 / iVar12));
    }
    uVar6 = *(uint *)(in_BX + unaff_DI + -0x60);
    uVar10 = uVar9;
    if (((uVar9 <= uVar6) || (uVar9 = uVar9 - uVar6, uVar10 = uVar6, uVar9 < 3)) &&
       (uVar9 = uVar10 + 1, uVar9 < uVar5)) {
      *(int *)0x4400 = in_BX;
      *(uint *)(in_BX + unaff_DI) = uVar9;
      uVar14 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)0x556e);
      uVar10 = uVar10 + 2;
      uVar9 = *(uint *)(uVar14 + unaff_DI + -0x60);
      bVar8 = (byte)uVar10;
      if (uVar9 < uVar10) {
        *(byte *)(unaff_BP + uVar5) = *(byte *)(unaff_BP + uVar5) ^ bVar8 - (byte)uVar9;
        return;
      }
      if (!SBORROW2(uVar10,uVar9)) {
        return;
      }
      bVar7 = bVar8 % 0x3d ^ 4;
      pbVar1 = (byte *)(unaff_BP + unaff_DI + -0x7c10);
      bVar13 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar7;
      LOCK();
      piVar3 = (int *)(uVar14 + uVar5 + 0x5d);
      *piVar3 = *piVar3 + -0x2b + (uint)CARRY1(bVar13,bVar7);
      UNLOCK();
      pcVar2 = (char *)(unaff_BP + unaff_DI + -0x7c10);
      *pcVar2 = *pcVar2 + bVar7 + 0x60;
      pbVar1 = (byte *)(unaff_BP + uVar5 + -0x75);
      *pbVar1 = *pbVar1 & (byte)uVar9;
      *(int *)(uVar14 + uVar5) = *(int *)(uVar14 + uVar5) + 0x2200;
      puVar4 = (undefined1 *)(uVar14 + uVar5 + 0x32);
      *puVar4 = *puVar4;
      iVar12 = CONCAT11((char)(uVar6 >> 8) + '\x01',0x40);
      iVar15 = uVar14 - 2;
      if (1 < uVar14) {
        piVar3 = (int *)(iVar15 + unaff_DI + 2);
        *piVar3 = *piVar3 + CONCAT11(bVar8 / 0x3d,bVar7 + 0x60);
        uVar9 = CONCAT11(bVar8 / 0x3d,2) | 0x20bd;
        bVar13 = (byte)uVar9;
        bVar8 = bVar13 + 0x73;
        *(int *)(unaff_BP + uVar5) =
             *(int *)(unaff_BP + uVar5) + CONCAT11((char)(uVar9 >> 8),bVar8) + (uint)(0x8c < bVar13)
        ;
        bVar13 = 9 < (bVar8 & 0xf) | in_AF;
        pbVar1 = (byte *)(unaff_BP + 0x2f35);
        bVar8 = *pbVar1 + (byte)iVar15;
        cVar18 = CARRY1(*pbVar1,(byte)iVar15) || CARRY1(bVar8,bVar13);
        *pbVar1 = bVar8 + bVar13;
        FUN_1000_5bbb();
        uVar20 = FUN_1000_a3c1();
        cVar18 = (char)uVar20 + *(char *)0x2f35 + cVar18;
        out((int)((ulong)uVar20 >> 0x10),cVar18);
        iVar12 = CONCAT11((char)((ulong)uVar20 >> 8),cVar18) + -1;
        bVar8 = (byte)iVar12;
        bVar13 = 9 < (bVar8 & 0xf) | bVar13;
        *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)iVar15 + bVar13;
        bVar7 = ((CONCAT11((char)((uint)iVar12 >> 8) - bVar13,bVar8 + bVar13 * -6) & 0xff0f) +
                 0xbf2f & 0x1000) != 0;
        cVar18 = -0x41;
        func_0x0001f1ba();
        bVar13 = cVar18 + (char)extraout_DX;
        *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)((uint)extraout_DX >> 8)
        ;
        uVar9 = CONCAT11(extraout_AH - bVar7,bVar7 * -6) & 0xff0f;
        pbVar1 = (byte *)(unaff_BP + 0x2f45);
        bVar8 = *pbVar1 + (byte)iVar15;
        cVar19 = CARRY1(*pbVar1,(byte)iVar15) || CARRY1(bVar8,bVar7);
        *pbVar1 = bVar8 + bVar7;
        func_0x00015bb1();
        cVar18 = func_0x0001ebb7();
        iVar12 = uVar9 + 1;
        pbVar1 = (byte *)(unaff_BP + iVar12 + -0x4167);
        *pbVar1 = *pbVar1 | (cVar18 + *(char *)(unaff_BP + uVar9) + cVar19) - 1U;
        pbVar1 = (byte *)(unaff_BP + -1 + iVar12);
        *pbVar1 = *pbVar1 & (byte)iVar15;
        iVar12 = iVar15;
        func_0x00015ba8();
        FUN_1000_20ae();
        *(byte *)(iVar12 + 0x2f75) = *(byte *)(iVar12 + 0x2f75) | 8;
        *(byte *)(unaff_BP + 0x5554) = *(byte *)(unaff_BP + 0x5554) & (byte)iVar12;
        FUN_1000_5ba1();
        FUN_1000_33a7();
        pbVar1 = (byte *)(unaff_BP + -1 + iVar15);
        *pbVar1 = *pbVar1 | (byte)((uint)iVar12 >> 8);
        *(byte *)(iVar12 + 0x3f5d) = *(byte *)(iVar12 + 0x3f5d) & bVar13;
        return;
      }
      LOCK();
      uVar6 = *(uint *)(unaff_BP + uVar5);
      *(uint *)(unaff_BP + uVar5) = uVar9;
      UNLOCK();
      bVar8 = in(uVar6);
      iVar11 = (uint)bVar8 * 0x80;
      pcVar17 = (char *)(iVar11 + 0x2400);
      LOCK();
      iVar16 = *(int *)(unaff_BP + uVar5);
      *(int *)(unaff_BP + uVar5) = (int)&stack0xffe6;
      UNLOCK();
      *(undefined2 *)(iVar16 + -2) = unaff_CS;
      *(undefined2 *)(unaff_BP + 0xc) = 0;
      *(byte *)(unaff_BP + uVar5) = *(byte *)(unaff_BP + uVar5) & 6;
      LOCK();
      *(int *)(iVar15 + uVar5) = iVar11 + *(int *)(unaff_BP + uVar5 + 0x4212);
      UNLOCK();
      pcVar2 = (char *)(iVar15 + uVar5 + 0x75);
      *pcVar2 = *pcVar2 + '@';
      iVar16 = unaff_BP + iVar12;
      *pcVar17 = *pcVar17 + (char)((uint)iVar15 >> 8);
      LOCK();
      piVar3 = (int *)(iVar16 + uVar5 + 3);
      *piVar3 = *piVar3 + uVar5;
      UNLOCK();
      *(uint *)(pcVar17 + iVar16 + 0x71) = *(int *)(pcVar17 + iVar16 + 0x71) + uVar5;
      *(int *)(iVar11 + 0x247c) = iVar12;
      *(int *)(iVar11 + 0x247e) = iVar12;
      *(int *)(iVar16 + 0xc) = iVar12;
      *pcVar17 = '@';
      puVar4 = (undefined1 *)(iVar16 + uVar5 + 0x2b0);
      *puVar4 = *puVar4;
      *(undefined1 *)(iVar11 + 0x2401) = 3;
      pcVar2 = (char *)(iVar16 + uVar5 + 0x55);
      *pcVar2 = *pcVar2 + 'V';
      *(undefined1 *)(iVar16 + uVar5 + 0x610) = 0;
      bVar8 = (byte)(uVar6 >> 9);
      *(undefined1 *)(iVar11 + 0x2402) = 2;
      *(byte *)(iVar16 + uVar5) = *(byte *)(iVar16 + uVar5) ^ 2;
      cVar18 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar16 + uVar5];
      *(byte *)(iVar11 + 0x2403) = bVar8;
      if (CONCAT11(cVar18,3) == 1) {
        *(byte *)(iVar11 + 0x2403) = bVar8;
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    in_DX = (uint)(byte)(cVar18 - 1U) << 8;
    if ((byte)(cVar18 - 1U) == 0) goto FUN_1000_8945;
    in_BX = in_BX + 2;
  } while( true );
}


