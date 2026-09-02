/* 1000:7860 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000178bd) overlaps instruction at (ram,0x000178bc)
    */
/* WARNING: Removing unreachable block (ram,0x00017892) */

uint FUN_1000_7860(void)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  code *pcVar6;
  byte bVar7;
  undefined2 in_AX;
  char cVar11;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte in_CL;
  undefined2 in_DX;
  char cVar12;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  int iVar13;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar14;
  char in_OF;
  undefined4 uVar15;
  
  uVar15 = CONCAT22(in_DX,in_AX);
  pcVar6 = (code *)swi(4);
  if (in_OF == '\x01') {
    uVar15 = (*pcVar6)();
  }
  cVar11 = ((byte)((ulong)uVar15 >> 8) & *(byte *)(in_BX + unaff_SI)) + 0x20;
  *(char *)(in_BX + 0x504e) = cVar11;
  *(char *)(unaff_SI + 0xd) = *(char *)(unaff_SI + 0xd) << (in_CL & 0x1f);
  bVar7 = ((byte)uVar15 | 8) - 1;
  if (3 < bVar7) {
    *(char *)0xaa10 = *(char *)0xaa10 + '\n';
    cVar5 = (char)((ulong)uVar15 >> 0x10) + *(char *)(in_BX + unaff_SI + 0x10);
    cVar12 = (char)((ulong)uVar15 >> 0x18);
    cVar3 = *(char *)(unaff_BP + unaff_SI + 0x4c4);
    *(int *)(unaff_BP + 0x7e87) =
         *(int *)(unaff_BP + 0x7e87) + ((byte)(bVar7 + cVar11 * '\x02') | 0x10a7);
    *(uint *)(in_BX + unaff_SI + 0x4702) = unaff_SI;
    if ((int)&stack0x0001 < 0) {
      *(uint *)(in_BX + unaff_SI + 2) = unaff_SI;
      cVar11 = *(char *)0xd089;
      *(undefined2 *)(in_BX + unaff_SI + -0x56) = CONCAT11(cVar12,cVar5 + *unaff_DI);
      pcVar2 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *pcVar2 = cVar5;
      cVar4 = *(char *)(in_BX + unaff_SI + -0x77);
      *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ cVar3 + 0x10U;
      if ((3 < (byte)(cVar5 - 0x14U)) &&
         (iVar8 = CONCAT11(cVar12 + cVar11 + cVar4,cVar5 + -8),
         (char)(cVar5 + -8) != *(char *)(unaff_SI + 0xc))) goto LAB_1000_78d9;
    }
  }
  bVar14 = false;
  iVar8 = FUN_1000_7aec();
  if (!bVar14) {
    *(undefined2 *)(unaff_SI + 6) = 0;
    *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    if ((*(byte *)(unaff_SI + 10) & 0x20) == 0) {
      iVar13 = unaff_SI + *(int *)(unaff_BP + unaff_SI + -0x41) + (uint)(unaff_SI < *(uint *)0x32bf)
      ;
      bVar7 = *(byte *)(in_BX + iVar13);
      pcVar2 = (char *)(in_BX + iVar13 + 0x5b);
      *pcVar2 = *pcVar2 + (char)in_BX;
      return (uint)(byte)((char)iVar8 + 0x80U ^ bVar7);
    }
    *(undefined1 *)(unaff_SI + 0xe) = 3;
    LOCK();
    *(int *)(unaff_DI + -0x5cee) = unaff_BP;
    UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_1000_78d9:
  uVar9 = iVar8 + 2;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar10 = *puVar1;
  *puVar1 = *puVar1 - uVar9;
  if (uVar10 < uVar9 || *puVar1 == 0) {
    uVar10 = FUN_1000_1845();
    return uVar10;
  }
  return uVar9;
}


