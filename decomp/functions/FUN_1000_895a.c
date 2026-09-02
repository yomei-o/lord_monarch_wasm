/* 1000:895a */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_895a(void)

{
  byte *pbVar1;
  char *pcVar2;
  int *piVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  int in_AX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char extraout_AH;
  byte bVar11;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  uint in_BX;
  int iVar12;
  int unaff_BP;
  int iVar13;
  undefined1 *unaff_SI;
  int unaff_DI;
  byte *pbVar14;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar15;
  char cVar16;
  byte in_AF;
  undefined4 uVar17;
  
  *(undefined2 *)(in_BX + unaff_DI + 0x240) = 0;
  out(*unaff_SI,in_DX);
  uVar7 = in_AX + 1;
  uVar8 = *(uint *)(in_BX + unaff_DI + -0x60);
  bVar6 = (byte)uVar7;
  if (uVar8 < uVar7) {
    unaff_SI[unaff_BP + 1] = unaff_SI[unaff_BP + 1] ^ bVar6 - (byte)uVar8;
    return;
  }
  if (SBORROW2(uVar7,uVar8)) {
    bVar5 = bVar6 % 0x3d ^ 4;
    pbVar1 = (byte *)(unaff_BP + unaff_DI + -0x7c10);
    bVar11 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar5;
    LOCK();
    *(uint *)(unaff_SI + in_BX + 0x5e) =
         *(int *)(unaff_SI + in_BX + 0x5e) + -0x2b + (uint)CARRY1(bVar11,bVar5);
    UNLOCK();
    pcVar2 = (char *)(unaff_BP + unaff_DI + -0x7c10);
    *pcVar2 = *pcVar2 + bVar5 + 0x60;
    unaff_SI[unaff_BP + -0x74] = unaff_SI[unaff_BP + -0x74] & (byte)uVar8;
    *(int *)(unaff_SI + in_BX + 1) = *(int *)(unaff_SI + in_BX + 1) + 0x2200;
    bVar11 = (byte)in_CX;
    unaff_SI[in_BX + 0x33] = (char)unaff_SI[in_BX + 0x33] >> (bVar11 & 0x1f);
    iVar10 = CONCAT11((char)((uint)in_CX >> 8) + '\x01',bVar11);
    iVar12 = in_BX - 2;
    if (in_BX < 2) {
      LOCK();
      uVar7 = *(uint *)(unaff_SI + unaff_BP + 1);
      *(uint *)(unaff_SI + unaff_BP + 1) = uVar8;
      UNLOCK();
      bVar6 = in(uVar7);
      iVar9 = (uint)bVar6 * 0x80;
      pbVar14 = (byte *)(iVar9 + 0x2400);
      LOCK();
      iVar13 = *(int *)(unaff_SI + unaff_BP + 1);
      *(undefined1 **)(unaff_SI + unaff_BP + 1) = &stack0xffe8;
      UNLOCK();
      *(undefined2 *)(iVar13 + -2) = unaff_CS;
      *(undefined2 *)(unaff_BP + 0xc) = 0;
      unaff_SI[unaff_BP + 1] = unaff_SI[unaff_BP + 1] & 6;
      LOCK();
      *(int *)(unaff_SI + (in_BX - 1)) = iVar9 + *(int *)(unaff_SI + unaff_BP + 0x4213);
      UNLOCK();
      unaff_SI[in_BX + 0x74] = unaff_SI[in_BX + 0x74] + bVar11;
      iVar13 = unaff_BP + iVar10;
      *pbVar14 = *pbVar14 + (char)((uint)iVar12 >> 8);
      LOCK();
      *(undefined1 **)(unaff_SI + iVar13 + 4) = unaff_SI + *(int *)(unaff_SI + iVar13 + 4) + 1;
      UNLOCK();
      *(undefined1 **)(pbVar14 + iVar13 + 0x71) = unaff_SI + *(int *)(pbVar14 + iVar13 + 0x71) + 1;
      *(int *)(iVar9 + 0x247c) = iVar10;
      *(int *)(iVar9 + 0x247e) = iVar10;
      *(int *)(iVar13 + 0xc) = iVar10;
      *pbVar14 = bVar11;
      cVar15 = '\0';
      if (bVar11 != 0) {
        cVar15 = '\x02';
      }
      unaff_SI[iVar13 + 0x2b1] = unaff_SI[iVar13 + 0x2b1];
      *(char *)(iVar9 + 0x2401) = cVar15 + '\x01';
      unaff_SI[iVar13 + 0x56] = unaff_SI[iVar13 + 0x56] + 'V';
      unaff_SI[iVar13 + 0x611] = 0;
      bVar6 = (byte)(uVar7 >> 9);
      *(undefined1 *)(iVar9 + 0x2402) = 2;
      unaff_SI[iVar13 + 1] = unaff_SI[iVar13 + 1] ^ 2;
      uVar4 = unaff_SI[(int)((char *)s__OOnly_cursor_position_0000_1601 + 0x10 + iVar13)];
      *(byte *)(iVar9 + 0x2403) = bVar6;
      if (CONCAT11(uVar4,3) == 1) {
        *(byte *)(iVar9 + 0x2403) = bVar6;
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    piVar3 = (int *)(iVar12 + unaff_DI + 2);
    *piVar3 = *piVar3 + CONCAT11(bVar6 / 0x3d,bVar5 + 0x60);
    uVar8 = CONCAT11(bVar6 / 0x3d,2) | 0x20bd;
    bVar11 = (byte)uVar8;
    bVar6 = bVar11 + 0x73;
    *(uint *)(unaff_SI + unaff_BP + 1) =
         *(int *)(unaff_SI + unaff_BP + 1) + CONCAT11((char)(uVar8 >> 8),bVar6) +
         (uint)(0x8c < bVar11);
    bVar11 = 9 < (bVar6 & 0xf) | in_AF;
    pbVar1 = (byte *)(unaff_BP + 0x2f35);
    bVar6 = *pbVar1 + (byte)iVar12;
    cVar15 = CARRY1(*pbVar1,(byte)iVar12) || CARRY1(bVar6,bVar11);
    *pbVar1 = bVar6 + bVar11;
    FUN_1000_5bbb();
    uVar17 = FUN_1000_a3c1();
    cVar15 = (char)uVar17 + *(char *)0x2f35 + cVar15;
    out((int)((ulong)uVar17 >> 0x10),cVar15);
    iVar10 = CONCAT11((char)((ulong)uVar17 >> 8),cVar15) + -1;
    bVar6 = (byte)iVar10;
    bVar11 = 9 < (bVar6 & 0xf) | bVar11;
    *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)iVar12 + bVar11;
    bVar5 = ((CONCAT11((char)((uint)iVar10 >> 8) - bVar11,bVar6 + bVar11 * -6) & 0xff0f) + 0xbf2f &
            0x1000) != 0;
    cVar15 = -0x41;
    func_0x0001f1ba();
    bVar11 = cVar15 + (char)extraout_DX;
    *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)((uint)extraout_DX >> 8);
    uVar8 = CONCAT11(extraout_AH - bVar5,bVar5 * -6) & 0xff0f;
    pbVar1 = (byte *)(unaff_BP + 0x2f45);
    bVar6 = *pbVar1 + (byte)iVar12;
    cVar16 = CARRY1(*pbVar1,(byte)iVar12) || CARRY1(bVar6,bVar5);
    *pbVar1 = bVar6 + bVar5;
    func_0x00015bb1();
    cVar15 = func_0x0001ebb7();
    iVar10 = uVar8 + 1;
    pbVar1 = (byte *)(unaff_BP + iVar10 + -0x4167);
    *pbVar1 = *pbVar1 | (cVar15 + *(char *)(unaff_BP + uVar8) + cVar16) - 1U;
    pbVar1 = (byte *)(unaff_BP + -1 + iVar10);
    *pbVar1 = *pbVar1 & (byte)iVar12;
    iVar10 = iVar12;
    func_0x00015ba8();
    FUN_1000_20ae();
    *(byte *)(iVar10 + 0x2f75) = *(byte *)(iVar10 + 0x2f75) | 8;
    *(byte *)(unaff_BP + 0x5554) = *(byte *)(unaff_BP + 0x5554) & (byte)iVar10;
    FUN_1000_5ba1();
    FUN_1000_33a7();
    pbVar1 = (byte *)(unaff_BP + -1 + iVar12);
    *pbVar1 = *pbVar1 | (byte)((uint)iVar10 >> 8);
    *(byte *)(iVar10 + 0x3f5d) = *(byte *)(iVar10 + 0x3f5d) & bVar11;
    return;
  }
  return;
}


