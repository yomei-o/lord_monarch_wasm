/* 1000:48a5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018aa7) overlaps instruction at (ram,0x00018aa5)
    */

void FUN_1000_48a5(void)

{
  int *piVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char cVar4;
  int in_AX;
  byte bVar5;
  undefined2 in_CX;
  byte in_DH;
  int in_BX;
  byte bVar7;
  int unaff_BP;
  int iVar8;
  int unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iVar6;
  
  bVar7 = (byte)((uint)in_BX >> 8);
  if (in_BX == 0) {
    *(undefined1 *)(unaff_BP + unaff_SI) = *(undefined1 *)(unaff_BP + unaff_SI);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar5 = (byte)in_CX | bVar7;
  iVar6 = CONCAT11((char)((uint)in_CX >> 8),bVar5);
  LOCK();
  *(int *)(in_BX + unaff_SI) = in_AX + 1 + *(int *)(unaff_BP + unaff_SI + 0x4212);
  UNLOCK();
  pcVar3 = (char *)(in_BX + unaff_SI + 0x75);
  *pcVar3 = *pcVar3 + bVar5;
  iVar8 = unaff_BP + iVar6;
  *unaff_DI = *unaff_DI + bVar7;
  LOCK();
  piVar1 = (int *)(iVar8 + unaff_SI + 3);
  *piVar1 = *piVar1 + unaff_SI;
  UNLOCK();
  *(int *)(unaff_DI + iVar8 + 0x71) = *(int *)(unaff_DI + iVar8 + 0x71) + unaff_SI;
  *(int *)(unaff_DI + 0x7c) = iVar6;
  *(int *)(unaff_DI + 0x7e) = iVar6;
  *(int *)(iVar8 + 0xc) = iVar6;
  *unaff_DI = bVar5;
  cVar4 = '\0';
  if (bVar5 != 0) {
    cVar4 = '\x02';
  }
  puVar2 = (undefined1 *)(iVar8 + unaff_SI + 0x2b0);
  *puVar2 = *puVar2;
  unaff_DI[1] = cVar4 + 1;
  pcVar3 = (char *)(iVar8 + unaff_SI + 0x55);
  *pcVar3 = *pcVar3 + 'V';
  *(undefined1 *)(iVar8 + unaff_SI + 0x610) = 0;
  unaff_DI[2] = 2;
  *(byte *)(iVar8 + unaff_SI) = *(byte *)(iVar8 + unaff_SI) ^ 2;
  cVar4 = ((char *)s__OOnly_cursor_position_0000_1601 + 0xf)[iVar8 + unaff_SI];
  unaff_DI[3] = in_DH >> 1;
  if (CONCAT11(cVar4,3) == 1) {
    unaff_DI[3] = in_DH >> 1;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


