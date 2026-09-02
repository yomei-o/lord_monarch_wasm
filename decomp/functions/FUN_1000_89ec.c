/* 1000:89ec */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */

void FUN_1000_89ec(void)

{
  int *piVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char cVar4;
  int in_AX;
  char cVar5;
  int in_CX;
  byte in_DH;
  int in_BX;
  int unaff_BP;
  int iVar6;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & 6;
  LOCK();
  *(int *)(in_BX + unaff_SI) = in_AX + *(int *)(unaff_BP + unaff_SI + 0x4212);
  UNLOCK();
  pcVar3 = (char *)(in_BX + unaff_SI + 0x75);
  cVar5 = (char)in_CX;
  *pcVar3 = *pcVar3 + cVar5;
  iVar6 = unaff_BP + in_CX;
  *unaff_DI = *unaff_DI + (char)((uint)in_BX >> 8);
  LOCK();
  piVar1 = (int *)(iVar6 + unaff_SI + 3);
  *piVar1 = *piVar1 + unaff_SI;
  UNLOCK();
  *(int *)(unaff_DI + iVar6 + 0x71) = *(int *)(unaff_DI + iVar6 + 0x71) + unaff_SI;
  *(int *)(unaff_DI + 0x7c) = in_CX;
  *(int *)(unaff_DI + 0x7e) = in_CX;
  *(int *)(iVar6 + 0xc) = in_CX;
  *unaff_DI = cVar5;
  cVar4 = '\0';
  if (cVar5 != '\0') {
    cVar4 = '\x02';
  }
  puVar2 = (undefined1 *)(iVar6 + unaff_SI + 0x2b0);
  *puVar2 = *puVar2;
  unaff_DI[1] = cVar4 + '\x01';
  pcVar3 = (char *)(iVar6 + unaff_SI + 0x55);
  *pcVar3 = *pcVar3 + 'V';
  *(undefined1 *)(iVar6 + unaff_SI + 0x610) = 0;
  unaff_DI[2] = '\x02';
  *(byte *)(iVar6 + unaff_SI) = *(byte *)(iVar6 + unaff_SI) ^ 2;
  cVar4 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar6 + unaff_SI];
  unaff_DI[3] = in_DH >> 1;
  if (CONCAT11(cVar4,3) == 1) {
    unaff_DI[3] = in_DH >> 1;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


