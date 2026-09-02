/* 1000:7885 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000178bd) overlaps instruction at (ram,0x000178bc)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00017892) */

uint FUN_1000_7885(void)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  int in_AX;
  char cVar11;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char in_CL;
  undefined2 in_DX;
  int in_BX;
  uint uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int unaff_BP;
  uint unaff_SI;
  int iVar15;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar16;
  
  cVar3 = *(char *)(unaff_BP + unaff_SI + 0x4c4);
  *(int *)(unaff_BP + 0x7e87) = *(int *)(unaff_BP + 0x7e87) + in_AX;
  uVar12 = (uint)&stack0x0000 & *(uint *)(in_BX + unaff_SI);
  puVar14 = (undefined1 *)(uVar12 - 2);
  *(undefined2 *)(uVar12 - 2) = unaff_CS;
  *(uint *)(in_BX + unaff_SI + 0x4702) = unaff_SI;
  if ((int)uVar12 < 0) {
    *(uint *)(in_BX + unaff_SI + 2) = unaff_SI;
    cVar4 = *(char *)0xd089;
    cVar11 = (char)((uint)in_DX >> 8);
    cVar7 = (char)in_DX;
    *(undefined2 *)(in_BX + unaff_SI + -0x56) = CONCAT11(cVar11,cVar7 + *unaff_DI);
    pcVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *pcVar2 = cVar7;
    cVar5 = *(char *)(in_BX + unaff_SI + -0x77);
    *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ in_CL + cVar3;
    puVar13 = (undefined1 *)(uVar12 - 2);
    if ((3 < (byte)(cVar7 - 0x14U)) &&
       (iVar8 = CONCAT11(cVar11 + cVar4 + cVar5,cVar7 + -8), puVar13 = (undefined1 *)(uVar12 - 2),
       (char)(cVar7 + -8) != *(char *)(unaff_SI + 0xc))) goto LAB_1000_78d9;
  }
  else {
    puVar13 = (undefined1 *)(uVar12 - 3);
    *(undefined2 *)(uVar12 - 3) = unaff_SS;
  }
  bVar16 = false;
  puVar14 = puVar13 + -2;
  *(undefined2 *)(puVar13 + -2) = 0x78d5;
  iVar8 = FUN_1000_7aec();
  if (!bVar16) {
    *(undefined2 *)(unaff_SI + 6) = 0;
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    if ((*(byte *)(unaff_SI + 10) & 0x20) != 0) {
      *(undefined1 *)(unaff_SI + 0xe) = 3;
      LOCK();
      *(int *)(unaff_DI + -0x5cee) = unaff_BP;
      UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar15 = unaff_SI + *(int *)(unaff_BP + unaff_SI + -0x41) + (uint)(unaff_SI < *(uint *)0x32bf);
    bVar6 = *(byte *)(in_BX + iVar15);
    pcVar2 = (char *)(in_BX + iVar15 + 0x5b);
    *pcVar2 = *pcVar2 + (char)in_BX;
    return (uint)(byte)((char)iVar8 + 0x80U ^ bVar6);
  }
LAB_1000_78d9:
  *(undefined2 *)(puVar14 + -2) = unaff_SS;
  *(uint *)(puVar14 + -4) = unaff_SI;
  uVar9 = iVar8 + 2;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar10 = *puVar1;
  *puVar1 = *puVar1 - uVar9;
  if (uVar9 <= uVar10 && *puVar1 != 0) {
    return uVar9;
  }
  *(undefined2 *)(puVar14 + -6) = 0x78e7;
  uVar10 = FUN_1000_1845();
  return uVar10;
}


