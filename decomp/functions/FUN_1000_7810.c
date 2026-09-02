/* 1000:7810 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000178bd) overlaps instruction at (ram,0x000178bc)
    */
/* WARNING: Removing unreachable block (ram,0x00017860) */
/* WARNING: Removing unreachable block (ram,0x00017892) */

uint FUN_1000_7810(int param_1,byte *param_2)

{
  byte *pbVar1;
  uint *puVar2;
  double dVar3;
  char *pcVar4;
  char cVar5;
  code *pcVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  char cVar13;
  undefined2 in_CX;
  byte bVar14;
  uint in_BX;
  uint uVar15;
  byte bVar16;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  char *pcVar17;
  int unaff_ES;
  uint unaff_SS;
  char cVar18;
  bool bVar19;
  undefined4 in_CR0;
  longdouble in_ST0;
  undefined2 in_stack_00000000;
  
  *(int *)(unaff_SI + unaff_BP) = (int)in_CR0;
  dVar3 = *(double *)(unaff_SI + unaff_BP + 0x2187);
  uVar15 = in_BX & *(uint *)(unaff_BP + unaff_DI + -0x78);
  LOCK();
  pcVar17 = (char *)*(int *)(unaff_BP + -0x2e);
  *(int *)(unaff_BP + -0x2e) = unaff_DI;
  UNLOCK();
  if ((int)uVar15 < 0) {
    pbVar1 = unaff_SI + unaff_BP;
    *pbVar1 = *pbVar1 | (byte)(unaff_SS >> 8);
    bVar14 = (byte)(unaff_SS / unaff_SI[0xc]);
    uVar11 = CONCAT11((char)(unaff_SS % (uint)unaff_SI[0xc]),bVar14);
    if ((char)*pbVar1 < '\0') {
      unaff_SI[uVar15] = unaff_SI[uVar15] + (char)in_CR0;
      cVar18 = false;
      uVar15 = CONCAT11((byte)(uVar15 >> 8) | unaff_SI[-0x2e],(char)uVar15);
      goto code_r0x00017842;
    }
    *(int *)(pcVar17 + uVar15) = (int)ROUND(in_ST0 * (longdouble)dVar3);
    bVar19 = false;
    *(byte *)0x8004 = *(byte *)0x8004 & bVar14;
code_r0x00017859:
    *(uint *)(unaff_SI + uVar15) = (int)&stack0x0002 + (uint)bVar19 + *(int *)(unaff_SI + uVar15);
FUN_1000_785c:
    unaff_SI[uVar15 + 0xe8d2] = unaff_SI[uVar15 + 0xe8d2] | (byte)uVar11;
    swi(4);
    cVar18 = ((byte)(uVar11 >> 8) & unaff_SI[uVar15]) + 0x20;
    *(char *)(uVar15 + 0x504e) = cVar18;
    unaff_SI[0xd] = unaff_SI[0xd] << ((byte)in_CX & 0x1f);
    cVar13 = '\x10';
    bVar14 = 10;
    bVar8 = ((byte)uVar11 | 8) - 1;
    bVar19 = bVar8 < 4;
    if (!bVar19) goto code_r0x00017879;
  }
  else {
    bVar12 = (byte)in_CX;
    bVar8 = (bVar12 & 0x1f) % 9;
    bVar14 = unaff_SI[uVar15];
    uVar11 = (uint)bVar14 << bVar8;
    unaff_SI[uVar15] = (byte)uVar11 | bVar14 >> 9 - bVar8;
    bVar14 = (bVar8 != 0) * ((uVar11 & 0x100) != 0);
    pbVar1 = unaff_SI + unaff_BP;
    bVar8 = *pbVar1;
    bVar16 = *pbVar1 + bVar12;
    cVar18 = CARRY1(*pbVar1,bVar12) || CARRY1(bVar16,bVar14);
    *pbVar1 = bVar16 + bVar14;
    if ((SCARRY1(bVar8,bVar12) != SCARRY1(bVar16,bVar14)) != (char)*pbVar1 < '\0') {
      pcVar6 = (code *)swi(1);
      uVar15 = (*pcVar6)();
      return uVar15;
    }
code_r0x00017842:
    uVar9 = FUN_1000_8435();
    unaff_SI[uVar15] = unaff_SI[uVar15] + (char)in_CR0 + cVar18;
    uVar11 = uVar9 | 2;
    bVar14 = (byte)((ulong)in_CR0 >> 8);
    param_1 = unaff_BP;
    param_2 = unaff_SI;
    if (0x2e < bVar14) goto FUN_1000_785c;
    cVar18 = (char)(uVar9 >> 8);
    bVar8 = (byte)uVar11;
    if ((POPCOUNT(bVar14 - 0x2f) & 1U) != 0) {
      bVar14 = (byte)uVar15;
      bVar16 = (byte)(uVar15 >> 8);
      uVar15 = CONCAT11(bVar16,bVar14 + bVar16);
      *(uint *)(unaff_SI + uVar15) =
           (int)&stack0x0002 + (uint)CARRY1(bVar14,bVar16) + *(int *)(unaff_SI + uVar15);
      bVar19 = 0x7f < bVar8;
      uVar11 = CONCAT11(cVar18,bVar8 + 0x80);
      param_1 = unaff_ES;
      goto code_r0x00017859;
    }
    cVar13 = (char)in_CX;
    bVar14 = (byte)((uint)in_CX >> 8) | *unaff_SI;
    *(char **)unaff_SI = pcVar17 + *(int *)unaff_SI;
    bVar19 = 0x8d < bVar8;
    bVar8 = bVar8 + 0x72;
    pcVar17 = pcVar17 + -1;
code_r0x00017879:
    *(char *)0xaa10 = *(char *)0xaa10 + bVar14 + bVar19;
    cVar5 = (char)in_CR0 + unaff_SI[uVar15 + 0x10];
    bVar14 = unaff_SI[unaff_BP + 0x4c4];
    *(int *)(unaff_BP + 0x7e87) =
         *(int *)(unaff_BP + 0x7e87) + ((byte)(bVar8 + cVar18 * '\x02') | 0x10a7);
    *(byte **)(unaff_SI + uVar15 + 0x4702) = unaff_SI;
    if ((int)&stack0x0002 + 1 < 0) {
      *(byte **)(unaff_SI + uVar15 + 2) = unaff_SI;
      cVar18 = *(char *)0xd089;
      *(int *)(unaff_SI + (uVar15 - 0x56)) =
           (int)CONCAT31((int3)((ulong)in_CR0 >> 8),cVar5 + *pcVar17);
      pcVar4 = pcVar17;
      pcVar17 = pcVar17 + 1;
      *pcVar4 = cVar5;
      bVar8 = unaff_SI[uVar15 - 0x77];
      *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ cVar13 + bVar14;
      if ((3 < (byte)(cVar5 - 0x14U)) &&
         (iVar10 = CONCAT11((char)((ulong)in_CR0 >> 8) + cVar18 + bVar8,cVar5 - 8U),
         (byte)(cVar5 - 8U) != unaff_SI[0xc])) goto LAB_1000_78d9;
    }
  }
  bVar19 = false;
  iVar10 = FUN_1000_7aec();
  if (!bVar19) {
    (unaff_SI + 6)[0] = 0;
    (unaff_SI + 6)[1] = 0;
    unaff_SI[0xb] = 0xff;
    if ((unaff_SI[10] & 0x20) == 0) {
      iVar7 = (uint)(unaff_SI < (byte *)*(undefined2 *)0x32bf) +
              *(int *)(unaff_SI + unaff_BP + -0x41);
      bVar14 = unaff_SI[uVar15 + iVar7];
      unaff_SI[uVar15 + iVar7 + 0x5b] = unaff_SI[uVar15 + iVar7 + 0x5b] + (char)uVar15;
      return (uint)(byte)((char)iVar10 + 0x80U ^ bVar14);
    }
    unaff_SI[0xe] = 3;
    LOCK();
    *(int *)(pcVar17 + -0x5cee) = unaff_BP;
    UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_1000_78d9:
  uVar11 = iVar10 + 2;
  puVar2 = (uint *)(unaff_SI + 6);
  uVar15 = *puVar2;
  *puVar2 = *puVar2 - uVar11;
  if (uVar15 < uVar11 || *puVar2 == 0) {
    uVar15 = FUN_1000_1845();
    return uVar15;
  }
  return uVar11;
}


