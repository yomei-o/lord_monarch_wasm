/* 1000:7874 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000178bd) overlaps instruction at (ram,0x000178bc)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00017892) */

uint FUN_1000_7874(void)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  undefined2 in_AX;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined2 in_CX;
  undefined2 in_DX;
  char cVar12;
  int in_BX;
  uint uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  int unaff_BP;
  int *unaff_SI;
  char *unaff_DI;
  char *pcVar16;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar17;
  
  *unaff_SI = (int)(unaff_DI + *unaff_SI);
  pcVar16 = unaff_DI + -1;
  *(char *)0xaa10 = *(char *)0xaa10 + (char)((uint)in_CX >> 8) + (0x8d < (byte)in_AX);
  cVar7 = (char)in_DX + *(char *)((int)unaff_SI + in_BX + 0x10);
  cVar12 = (char)((uint)in_DX >> 8);
  cVar3 = *(char *)((int)unaff_SI + unaff_BP + 0x4c4);
  *(int *)(unaff_BP + 0x7e87) =
       *(int *)(unaff_BP + 0x7e87) +
       ((byte)((byte)in_AX + 0x72 + (char)((uint)in_AX >> 8) * '\x02') | 0x10a7);
  uVar13 = (uint)&stack0x0000 & *(uint *)(in_BX + (int)unaff_SI);
  puVar15 = (undefined1 *)(uVar13 - 2);
  *(undefined2 *)(uVar13 - 2) = unaff_CS;
  *(undefined2 *)((int)unaff_SI + in_BX + 0x4702) = unaff_SI;
  if ((int)uVar13 < 0) {
    *(undefined2 *)((int)unaff_SI + in_BX + 2) = unaff_SI;
    cVar4 = *(char *)0xd089;
    *(undefined2 *)((int)unaff_SI + in_BX + -0x56) = CONCAT11(cVar12,cVar7 + *pcVar16);
    *pcVar16 = cVar7;
    cVar5 = *(char *)((int)unaff_SI + in_BX + -0x77);
    *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ (char)in_CX + cVar3;
    puVar14 = (undefined1 *)(uVar13 - 2);
    pcVar16 = unaff_DI;
    if ((3 < (byte)(cVar7 - 0x14U)) &&
       (iVar9 = CONCAT11(cVar12 + cVar4 + cVar5,cVar7 + -8), puVar14 = (undefined1 *)(uVar13 - 2),
       (char)(cVar7 + -8) != (char)unaff_SI[6])) goto LAB_1000_78d9;
  }
  else {
    puVar14 = (undefined1 *)(uVar13 - 3);
    *(undefined2 *)(uVar13 - 3) = unaff_SS;
  }
  bVar17 = false;
  puVar15 = puVar14 + -2;
  *(undefined2 *)(puVar14 + -2) = 0x78d5;
  iVar9 = FUN_1000_7aec();
  if (!bVar17) {
    unaff_SI[3] = 0;
    *(undefined1 *)((int)unaff_SI + 0xb) = 0xff;
    if ((*(byte *)(unaff_SI + 5) & 0x20) != 0) {
      *(undefined1 *)(unaff_SI + 7) = 3;
      LOCK();
      *(int *)(pcVar16 + -0x5cee) = unaff_BP;
      UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar8 = (uint)(unaff_SI < (int *)*(undefined2 *)0x32bf) +
            *(int *)((int)unaff_SI + unaff_BP + -0x41);
    bVar6 = *(byte *)((int)unaff_SI + in_BX + iVar8);
    pcVar2 = (char *)((int)unaff_SI + in_BX + iVar8 + 0x5b);
    *pcVar2 = *pcVar2 + (char)in_BX;
    return (uint)(byte)((char)iVar9 + 0x80U ^ bVar6);
  }
LAB_1000_78d9:
  *(undefined2 *)(puVar15 + -2) = unaff_SS;
  *(int **)(puVar15 + -4) = unaff_SI;
  uVar10 = iVar9 + 2;
  puVar1 = (uint *)(unaff_SI + 3);
  uVar11 = *puVar1;
  *puVar1 = *puVar1 - uVar10;
  if (uVar10 <= uVar11 && *puVar1 != 0) {
    return uVar10;
  }
  *(undefined2 *)(puVar15 + -6) = 0x78e7;
  uVar11 = FUN_1000_1845();
  return uVar11;
}


