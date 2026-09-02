/* 1000:89d3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_89d3(void)

{
  int *piVar1;
  undefined1 *puVar2;
  char *pcVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  char cVar7;
  int in_CX;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  int iVar8;
  int unaff_SI;
  char *pcVar9;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  bVar4 = in(in_DX);
  iVar6 = (uint)bVar4 * 0x80;
  pcVar9 = (char *)(iVar6 + 0x2400);
  LOCK();
  iVar8 = *(int *)(unaff_BP + unaff_SI);
  *(int *)(unaff_BP + unaff_SI) = (int)register0x00000010;
  UNLOCK();
  *(undefined2 *)(iVar8 + -2) = unaff_CS;
  *(undefined2 *)(unaff_BP + 0xc) = 0;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & 6;
  LOCK();
  *(int *)(in_BX + unaff_SI) = iVar6 + *(int *)(unaff_BP + unaff_SI + 0x4212);
  UNLOCK();
  pcVar3 = (char *)(in_BX + unaff_SI + 0x75);
  cVar7 = (char)in_CX;
  *pcVar3 = *pcVar3 + cVar7;
  iVar8 = unaff_BP + in_CX;
  *pcVar9 = *pcVar9 + (char)((uint)in_BX >> 8);
  LOCK();
  piVar1 = (int *)(iVar8 + unaff_SI + 3);
  *piVar1 = *piVar1 + unaff_SI;
  UNLOCK();
  *(int *)(pcVar9 + iVar8 + 0x71) = *(int *)(pcVar9 + iVar8 + 0x71) + unaff_SI;
  *(int *)(iVar6 + 0x247c) = in_CX;
  *(int *)(iVar6 + 0x247e) = in_CX;
  *(int *)(iVar8 + 0xc) = in_CX;
  *pcVar9 = cVar7;
  cVar5 = '\0';
  if (cVar7 != '\0') {
    cVar5 = '\x02';
  }
  puVar2 = (undefined1 *)(iVar8 + unaff_SI + 0x2b0);
  *puVar2 = *puVar2;
  *(char *)(iVar6 + 0x2401) = cVar5 + '\x01';
  pcVar3 = (char *)(iVar8 + unaff_SI + 0x55);
  *pcVar3 = *pcVar3 + 'V';
  *(undefined1 *)(iVar8 + unaff_SI + 0x610) = 0;
  bVar4 = (byte)((uint)in_DX >> 9);
  *(undefined1 *)(iVar6 + 0x2402) = 2;
  *(byte *)(iVar8 + unaff_SI) = *(byte *)(iVar8 + unaff_SI) ^ 2;
  cVar5 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar8 + unaff_SI];
  *(byte *)(iVar6 + 0x2403) = bVar4;
  if (CONCAT11(cVar5,3) == 1) {
    *(byte *)(iVar6 + 0x2403) = bVar4;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


