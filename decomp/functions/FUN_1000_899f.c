/* 1000:899f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_899f(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int *piVar4;
  undefined2 uVar5;
  byte bVar6;
  int in_AX;
  uint uVar7;
  int iVar8;
  int iVar9;
  char extraout_AH;
  byte bVar10;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  uint in_BX;
  int iVar11;
  int unaff_BP;
  int iVar12;
  int unaff_SI;
  int unaff_DI;
  byte *pbVar13;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar14;
  char cVar15;
  byte in_AF;
  byte bVar16;
  undefined4 uVar17;
  
  *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + 0x2200;
  pcVar3 = (char *)(in_BX + unaff_SI + 0x32);
  bVar6 = (byte)in_CX;
  *pcVar3 = *pcVar3 >> (bVar6 & 0x1f);
  iVar9 = CONCAT11((char)((uint)in_CX >> 8) + '\x01',bVar6);
  iVar11 = in_BX - 2;
  if (in_BX < 2) {
    LOCK();
    uVar5 = *(undefined2 *)(unaff_BP + unaff_SI);
    *(undefined2 *)(unaff_BP + unaff_SI) = in_DX;
    UNLOCK();
    bVar10 = in(uVar5);
    iVar8 = (uint)bVar10 * 0x80;
    pbVar13 = (byte *)(iVar8 + 0x2400);
    LOCK();
    iVar12 = *(int *)(unaff_BP + unaff_SI);
    *(int *)(unaff_BP + unaff_SI) = (int)register0x00000010;
    UNLOCK();
    *(undefined2 *)(iVar12 + -2) = unaff_CS;
    *(undefined2 *)(unaff_BP + 0xc) = 0;
    *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & 6;
    LOCK();
    *(int *)(iVar11 + unaff_SI) = iVar8 + *(int *)(unaff_BP + unaff_SI + 0x4212);
    UNLOCK();
    pcVar3 = (char *)(iVar11 + unaff_SI + 0x75);
    *pcVar3 = *pcVar3 + bVar6;
    iVar12 = unaff_BP + iVar9;
    *pbVar13 = *pbVar13 + (char)((uint)iVar11 >> 8);
    LOCK();
    piVar4 = (int *)(iVar12 + unaff_SI + 3);
    *piVar4 = *piVar4 + unaff_SI;
    UNLOCK();
    *(int *)(pbVar13 + iVar12 + 0x71) = *(int *)(pbVar13 + iVar12 + 0x71) + unaff_SI;
    *(int *)(iVar8 + 0x247c) = iVar9;
    *(int *)(iVar8 + 0x247e) = iVar9;
    *(int *)(iVar12 + 0xc) = iVar9;
    *pbVar13 = bVar6;
    cVar14 = '\0';
    if (bVar6 != 0) {
      cVar14 = '\x02';
    }
    puVar2 = (undefined1 *)(iVar12 + unaff_SI + 0x2b0);
    *puVar2 = *puVar2;
    *(char *)(iVar8 + 0x2401) = cVar14 + '\x01';
    pcVar3 = (char *)(iVar12 + unaff_SI + 0x55);
    *pcVar3 = *pcVar3 + 'V';
    *(undefined1 *)(iVar12 + unaff_SI + 0x610) = 0;
    bVar6 = (byte)((uint)uVar5 >> 9);
    *(undefined1 *)(iVar8 + 0x2402) = 2;
    *(byte *)(iVar12 + unaff_SI) = *(byte *)(iVar12 + unaff_SI) ^ 2;
    cVar14 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar12 + unaff_SI];
    *(byte *)(iVar8 + 0x2403) = bVar6;
    if (CONCAT11(cVar14,3) == 1) {
      *(byte *)(iVar8 + 0x2403) = bVar6;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  piVar4 = (int *)(iVar11 + unaff_DI + 2);
  *piVar4 = *piVar4 + in_AX;
  uVar7 = CONCAT11((char)((uint)in_AX >> 8),2) | 0x20bd;
  bVar10 = (byte)uVar7;
  bVar6 = bVar10 + 0x73;
  *(int *)(unaff_BP + unaff_SI) =
       *(int *)(unaff_BP + unaff_SI) + CONCAT11((char)(uVar7 >> 8),bVar6) + (uint)(0x8c < bVar10);
  bVar10 = 9 < (bVar6 & 0xf) | in_AF;
  pbVar1 = (byte *)(unaff_BP + 0x2f35);
  bVar6 = *pbVar1 + (byte)iVar11;
  cVar14 = CARRY1(*pbVar1,(byte)iVar11) || CARRY1(bVar6,bVar10);
  *pbVar1 = bVar6 + bVar10;
  FUN_1000_5bbb();
  uVar17 = FUN_1000_a3c1();
  cVar14 = (char)uVar17 + *(char *)0x2f35 + cVar14;
  out((int)((ulong)uVar17 >> 0x10),cVar14);
  iVar9 = CONCAT11((char)((ulong)uVar17 >> 8),cVar14) + -1;
  bVar6 = (byte)iVar9;
  bVar10 = 9 < (bVar6 & 0xf) | bVar10;
  *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)iVar11 + bVar10;
  bVar16 = ((CONCAT11((char)((uint)iVar9 >> 8) - bVar10,bVar6 + bVar10 * -6) & 0xff0f) + 0xbf2f &
           0x1000) != 0;
  cVar14 = -0x41;
  func_0x0001f1ba();
  bVar10 = cVar14 + (char)extraout_DX;
  *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)((uint)extraout_DX >> 8);
  uVar7 = CONCAT11(extraout_AH - bVar16,bVar16 * -6) & 0xff0f;
  pbVar1 = (byte *)(unaff_BP + 0x2f45);
  bVar6 = *pbVar1 + (byte)iVar11;
  cVar15 = CARRY1(*pbVar1,(byte)iVar11) || CARRY1(bVar6,bVar16);
  *pbVar1 = bVar6 + bVar16;
  func_0x00015bb1();
  cVar14 = func_0x0001ebb7();
  iVar9 = uVar7 + 1;
  pbVar1 = (byte *)(unaff_BP + iVar9 + -0x4167);
  *pbVar1 = *pbVar1 | (cVar14 + *(char *)(unaff_BP + uVar7) + cVar15) - 1U;
  pbVar1 = (byte *)(unaff_BP + -1 + iVar9);
  *pbVar1 = *pbVar1 & (byte)iVar11;
  iVar9 = iVar11;
  func_0x00015ba8();
  FUN_1000_20ae();
  *(byte *)(iVar9 + 0x2f75) = *(byte *)(iVar9 + 0x2f75) | 8;
  *(byte *)(unaff_BP + 0x5554) = *(byte *)(unaff_BP + 0x5554) & (byte)iVar9;
  FUN_1000_5ba1();
  FUN_1000_33a7();
  pbVar1 = (byte *)(unaff_BP + -1 + iVar11);
  *pbVar1 = *pbVar1 | (byte)((uint)iVar9 >> 8);
  *(byte *)(iVar9 + 0x3f5d) = *(byte *)(iVar9 + 0x3f5d) & bVar10;
  return;
}


