/* 1000:89c6 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_89c6(void)

{
  int *piVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  char cVar9;
  int in_CX;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  int iVar10;
  int unaff_SI;
  undefined1 *unaff_DI;
  char *pcVar11;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  uVar5 = in(in_DX);
  *unaff_DI = uVar5;
  LOCK();
  uVar4 = *(undefined2 *)(unaff_BP + unaff_SI);
  *(undefined2 *)(unaff_BP + unaff_SI) = in_stack_00000000;
  UNLOCK();
  bVar6 = in(uVar4);
  iVar8 = (uint)bVar6 * 0x80;
  pcVar11 = (char *)(iVar8 + 0x2400);
  LOCK();
  iVar10 = *(int *)(unaff_BP + unaff_SI);
  *(int *)(unaff_BP + unaff_SI) = (int)&stack0xfffe;
  UNLOCK();
  *(undefined2 *)(iVar10 + -2) = unaff_CS;
  *(undefined2 *)(unaff_BP + 0xc) = 0;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & 6;
  LOCK();
  *(int *)(in_BX + unaff_SI) = iVar8 + *(int *)(unaff_BP + unaff_SI + 0x4212);
  UNLOCK();
  pcVar3 = (char *)(in_BX + unaff_SI + 0x75);
  cVar9 = (char)in_CX;
  *pcVar3 = *pcVar3 + cVar9;
  iVar10 = unaff_BP + in_CX;
  *pcVar11 = *pcVar11 + (char)((uint)in_BX >> 8);
  LOCK();
  piVar1 = (int *)(iVar10 + unaff_SI + 3);
  *piVar1 = *piVar1 + unaff_SI;
  UNLOCK();
  *(int *)(pcVar11 + iVar10 + 0x71) = *(int *)(pcVar11 + iVar10 + 0x71) + unaff_SI;
  *(int *)(iVar8 + 0x247c) = in_CX;
  *(int *)(iVar8 + 0x247e) = in_CX;
  *(int *)(iVar10 + 0xc) = in_CX;
  *pcVar11 = cVar9;
  cVar7 = '\0';
  if (cVar9 != '\0') {
    cVar7 = '\x02';
  }
  puVar2 = (undefined1 *)(iVar10 + unaff_SI + 0x2b0);
  *puVar2 = *puVar2;
  *(char *)(iVar8 + 0x2401) = cVar7 + '\x01';
  pcVar3 = (char *)(iVar10 + unaff_SI + 0x55);
  *pcVar3 = *pcVar3 + 'V';
  *(undefined1 *)(iVar10 + unaff_SI + 0x610) = 0;
  bVar6 = (byte)((uint)uVar4 >> 9);
  *(undefined1 *)(iVar8 + 0x2402) = 2;
  *(byte *)(iVar10 + unaff_SI) = *(byte *)(iVar10 + unaff_SI) ^ 2;
  cVar7 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar10 + unaff_SI];
  *(byte *)(iVar8 + 0x2403) = bVar6;
  if (CONCAT11(cVar7,3) == 1) {
    *(byte *)(iVar8 + 0x2403) = bVar6;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


