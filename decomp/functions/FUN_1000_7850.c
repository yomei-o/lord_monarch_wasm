/* 1000:7850 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000178bd) overlaps instruction at (ram,0x000178bc)
    */
/* WARNING: Removing unreachable block (ram,0x00017860) */
/* WARNING: Removing unreachable block (ram,0x00017892) */

uint FUN_1000_7850(void)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  undefined2 in_AX;
  byte bVar10;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bVar11;
  undefined2 in_CX;
  byte bVar12;
  undefined2 in_DX;
  char cVar13;
  int in_BX;
  byte bVar14;
  int unaff_BP;
  byte *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar15;
  bool in_PF;
  
  bVar10 = (byte)((uint)in_AX >> 8);
  bVar6 = (byte)in_AX;
  bVar11 = (byte)in_CX;
  if (in_PF) {
    bVar12 = (byte)((uint)in_CX >> 8) | *unaff_SI;
    *(char **)unaff_SI = unaff_DI + *(int *)unaff_SI;
    bVar15 = 0x8d < bVar6;
    bVar6 = bVar6 + 0x72;
    unaff_DI = unaff_DI + -1;
code_r0x00017879:
    *(char *)0xaa10 = *(char *)0xaa10 + bVar12 + bVar15;
    cVar4 = (char)in_DX + unaff_SI[in_BX + 0x10];
    cVar13 = (char)((uint)in_DX >> 8);
    bVar12 = unaff_SI[unaff_BP + 0x4c4];
    *(int *)(unaff_BP + 0x7e87) =
         *(int *)(unaff_BP + 0x7e87) + ((byte)(bVar6 + bVar10 * '\x02') | 0x10a7);
    *(byte **)(unaff_SI + in_BX + 0x4702) = unaff_SI;
    if ((int)&stack0x0003 < 0) {
      *(byte **)(unaff_SI + in_BX + 2) = unaff_SI;
      cVar3 = *(char *)0xd089;
      *(uint *)(unaff_SI + in_BX + -0x56) = CONCAT11(cVar13,cVar4 + *unaff_DI);
      pcVar2 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *pcVar2 = cVar4;
      bVar6 = unaff_SI[in_BX + -0x77];
      *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ bVar11 + bVar12;
      if ((3 < (byte)(cVar4 - 0x14U)) &&
         (iVar7 = CONCAT11(cVar13 + cVar3 + bVar6,cVar4 - 8U), (byte)(cVar4 - 8U) != unaff_SI[0xc]))
      goto LAB_1000_78d9;
    }
  }
  else {
    bVar12 = (byte)in_BX;
    bVar14 = (byte)((uint)in_BX >> 8);
    in_BX = CONCAT11(bVar14,bVar12 + bVar14);
    *(undefined1 **)(unaff_SI + in_BX) =
         &stack0x0000 + (uint)CARRY1(bVar12,bVar14) + *(int *)(unaff_SI + in_BX);
    *(undefined1 **)(unaff_SI + in_BX) =
         &stack0xfffe + (uint)(0x7f < bVar6) + *(int *)(unaff_SI + in_BX);
    unaff_SI[in_BX + -0x172e] = unaff_SI[in_BX + -0x172e] | bVar6 + 0x80;
    swi(4);
    bVar10 = (bVar10 & unaff_SI[in_BX]) + 0x20;
    *(byte *)(in_BX + 0x504e) = bVar10;
    unaff_SI[0xd] = unaff_SI[0xd] << (bVar11 & 0x1f);
    bVar11 = 0x10;
    bVar12 = 10;
    bVar6 = (bVar6 + 0x80 | 8) - 1;
    bVar15 = bVar6 < 4;
    if (!bVar15) goto code_r0x00017879;
  }
  bVar15 = false;
  iVar7 = FUN_1000_7aec();
  if (!bVar15) {
    (unaff_SI + 6)[0] = 0;
    (unaff_SI + 6)[1] = 0;
    unaff_SI[0xb] = 0xff;
    if ((unaff_SI[10] & 0x20) == 0) {
      iVar5 = (uint)(unaff_SI < (byte *)*(undefined2 *)0x32bf) +
              *(int *)(unaff_SI + unaff_BP + -0x41);
      bVar6 = unaff_SI[in_BX + iVar5];
      unaff_SI[in_BX + iVar5 + 0x5b] = unaff_SI[in_BX + iVar5 + 0x5b] + (char)in_BX;
      return (uint)(byte)((char)iVar7 + 0x80U ^ bVar6);
    }
    unaff_SI[0xe] = 3;
    LOCK();
    *(int *)(unaff_DI + -0x5cee) = unaff_BP;
    UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_1000_78d9:
  uVar8 = iVar7 + 2;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar9 = *puVar1;
  *puVar1 = *puVar1 - uVar8;
  if (uVar9 < uVar8 || *puVar1 == 0) {
    uVar9 = FUN_1000_1845();
    return uVar9;
  }
  return uVar8;
}


