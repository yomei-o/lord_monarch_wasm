/* 1000:72e3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000178a8) overlaps instruction at (ram,0x000178a7)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00017360) */

uint FUN_1000_72e3(uint param_1)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  uint *puVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  char in_AL;
  byte bVar13;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  byte bVar14;
  uint in_CX;
  int iVar15;
  byte in_DL;
  byte bVar16;
  char cVar18;
  int in_BX;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int unaff_BP;
  uint *unaff_SI;
  int unaff_DI;
  uint *puVar22;
  undefined2 unaff_ES;
  byte unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar23;
  bool bVar24;
  byte in_stack_00000000;
  undefined2 uStack_6;
  byte bVar4;
  char cVar17;
  
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + in_AL;
  pbVar1 = (byte *)(unaff_BP + 1);
  *pbVar1 = *pbVar1 & in_DL;
  bVar14 = (byte)in_CX;
  if (*pbVar1 == 0) {
    uVar12 = *(uint *)0x3be2;
    iVar19 = *(int *)0x3be4;
    bVar16 = (byte)iVar19;
    bVar13 = (char)((uint)iVar19 >> 8) - (char)(uVar12 >> 8);
    if ('\x05' < (char)bVar13) {
      return CONCAT11(bVar13,bVar16);
    }
    pbVar1 = (byte *)(iVar19 + (int)unaff_SI);
    bVar3 = *pbVar1;
    bVar4 = *pbVar1;
    *pbVar1 = bVar4 + bVar16 + (bVar13 < 6);
    if (CARRY1(bVar3,bVar16) || CARRY1(bVar4 + bVar16,bVar13 < 6)) {
      uVar12 = uVar12 & 0xff;
    }
    bVar16 = bVar16 - (char)uVar12;
    uVar11 = CONCAT11(bVar13,bVar16);
    if ('\x05' < (char)bVar16) {
      *(char *)0x80d3 = *(char *)0x80d3 + bVar16 + (bVar16 < 0x21);
      out(0xc4,bVar16);
      iVar19 = unaff_DI * 2;
      *(uint *)(iVar19 + -0x4252) = uVar11;
      *(undefined2 *)(iVar19 + -0x3d82) = 0;
      *(undefined2 *)(iVar19 + 0x1212) = 0x8348;
      *(undefined2 *)(unaff_BP + (int)unaff_SI) = 0xc480;
      uVar12 = func_0x0001b63b(0x1077);
      return uVar12;
    }
    puVar5 = (uint *)((int)unaff_SI + iVar19 + 0x21ea);
    *puVar5 = *puVar5 << (bVar14 & 0xf) | *puVar5 >> 0x10 - (bVar14 & 0xf);
    bVar23 = (in_CX & 0x1f) == 0;
    *(char *)(unaff_BP + (int)unaff_SI) =
         *(char *)(unaff_BP + (int)unaff_SI) + (char)uVar12 +
         (bVar23 * (bVar16 < 6) | !bVar23 * ((*puVar5 & 1) != 0));
    pbVar1 = (byte *)(iVar19 + unaff_DI + -0x1dea);
    *pbVar1 = *pbVar1 >> (bVar14 & 7) | *pbVar1 << 8 - (bVar14 & 7);
  }
  else {
    iVar19 = in_BX + *(int *)((int)unaff_SI + in_BX + 0x10);
    bVar14 = bVar14 + *(char *)(iVar19 + (int)unaff_SI);
    *(byte *)(iVar19 + (int)unaff_SI) = *(byte *)(iVar19 + (int)unaff_SI) ^ in_DL;
    pbVar1 = (byte *)((int)unaff_SI + iVar19 + 0x24fe);
    *pbVar1 = *pbVar1 | unaff_CS;
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ in_stack_00000000;
    iVar19 = iVar19 + *(int *)((int)unaff_SI + iVar19 + 0x40);
    pbVar1 = (byte *)(unaff_BP + unaff_DI);
    *pbVar1 = *pbVar1 | in_stack_00000000;
    if (-1 < (char)*pbVar1) {
      *(uint *)(iVar19 + (int)unaff_SI) = *(uint *)(iVar19 + (int)unaff_SI) & param_1;
      bVar14 = in_stack_00000000 - 0x2d;
      cVar17 = (char)param_1;
      cVar18 = (char)(param_1 >> 8);
      bVar16 = cVar17 - 8;
      bVar23 = bVar16 < 0x24;
      bVar24 = bVar16 == 0x24;
      if (!bVar23) {
        *(char *)0x80d3 = *(char *)0x80d3 + bVar14;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      pcVar10 = (char *)CONCAT11(bVar16,bVar14);
      puVar22 = (uint *)0x768e;
      iVar15 = 0x80;
      do {
        if (iVar15 == 0) break;
        iVar15 = iVar15 + -1;
        puVar5 = puVar22;
        puVar22 = puVar22 + 1;
        bVar23 = pcVar10 < (char *)*puVar5;
        bVar24 = pcVar10 == (char *)*puVar5;
      } while (!bVar24);
      if (!bVar24) {
        uVar12 = *(uint *)0x108c;
        *(byte *)(unaff_SI + -0x1fe7) = (char)unaff_SI[-0x1fe7] + bVar14 + bVar23;
        do {
          uVar12 = uVar12 + 1 & 0x7f;
          bVar13 = *(byte *)(uVar12 + 0x788e);
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0 && bVar14 != bVar13);
        if (bVar14 == bVar13) {
          *(uint *)0x768c = uVar12;
          *(undefined2 *)(uVar12 * 2 + 0x768e) = pcVar10;
          iVar19 = CONCAT11(cVar18,bVar16) * 8 + 0x3000;
          puVar22 = (uint *)((uint)(byte)(((char)uVar12 + -0x80) - bVar14) * 0x80);
          *(byte *)0x33a6 = *(byte *)0x33a6 ^ (byte)((uint)iVar15 >> 8);
          *(undefined2 **)0xc54a = &uStack_6;
          uVar12 = *unaff_SI;
          uVar11 = unaff_SI[0x10];
          uVar8 = unaff_SI[0x20];
          uVar20 = unaff_SI[0x30] & uVar8 & uVar11 & uVar12;
          uVar21 = ~uVar20;
          puVar22[0x30] = unaff_SI[0x30] & uVar20 | unaff_SI[0x30] & uVar21;
          puVar22[0x20] = unaff_SI[0x20] & uVar20 | uVar8 & uVar21;
          puVar22[0x10] = unaff_SI[0x10] & uVar20 | uVar11 & uVar21;
          *puVar22 = *unaff_SI & uVar20 | uVar12 & uVar21;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        puVar22 = (uint *)(pcVar10 + 1);
        *pcVar10 = in_stack_00000000 + 0x5c + (bVar14 < bVar13);
        iVar19 = CONCAT11(cVar18,bVar16);
      }
      *(undefined2 *)((int)unaff_SI + iVar19 + 2) = unaff_SI;
      cVar6 = *(char *)0xd089;
      *(undefined2 *)((int)unaff_SI + iVar19 + -0x56) = CONCAT11(cVar18,bVar16 + (char)*puVar22);
      *(byte *)puVar22 = bVar16;
      cVar7 = *(char *)((int)unaff_SI + iVar19 + -0x77);
      *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ (byte)iVar15;
      if (((byte)(cVar17 - 0x1cU) < 4) ||
         (iVar15 = CONCAT11(cVar18 + cVar6 + cVar7,cVar17 + -0x10),
         (char)(cVar17 + -0x10) == (char)unaff_SI[6])) {
        bVar23 = false;
        iVar15 = FUN_1000_7aec();
        if (!bVar23) {
          unaff_SI[3] = 0;
          *(undefined1 *)((int)unaff_SI + 0xb) = 0xff;
          if ((unaff_SI[5] & 0x20) == 0) {
            iVar9 = (uint)(unaff_SI < (uint *)*(undefined2 *)0x32bf) +
                    *(int *)((int)unaff_SI + unaff_BP + -0x41);
            bVar14 = *(byte *)((int)unaff_SI + iVar19 + iVar9);
            pcVar2 = (char *)((int)unaff_SI + iVar19 + iVar9 + 0x5b);
            *pcVar2 = *pcVar2 + (char)iVar19;
            return (uint)(byte)((char)iVar15 + 0x80U ^ bVar14);
          }
          *(undefined1 *)(unaff_SI + 7) = 3;
          LOCK();
          *(int *)((int)puVar22 + -0x5ced) = unaff_BP;
          UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      uVar11 = iVar15 + 2;
      puVar5 = unaff_SI + 3;
      uVar12 = *puVar5;
      *puVar5 = *puVar5 - uVar11;
      if (uVar12 < uVar11 || *puVar5 == 0) {
        uStack_6 = 0x78e7;
        uVar12 = FUN_1000_1845();
        return uVar12;
      }
      return uVar11;
    }
    puVar5 = (uint *)((int)unaff_SI + iVar19 + 0x21ea);
    *puVar5 = *puVar5 << (bVar14 & 0xf) | *puVar5 >> 0x10 - (bVar14 & 0xf);
    pcVar2 = (char *)((int)unaff_SI + iVar19 + 0x60);
    *pcVar2 = *pcVar2 + (char)iVar19 + ((bVar14 & 0x1f) != 0) * ((*puVar5 & 1) != 0);
    uVar11 = (uint)in_stack_00000000;
    if (CONCAT11((char)(in_CX >> 8),bVar14) == 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return uVar11;
}


