/* 1000:082c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00010848) overlaps instruction at (ram,0x00010846)
    */

void FUN_1000_082c(void)

{
  char *pcVar1;
  char cVar2;
  int in_AX;
  int iVar3;
  int in_CX;
  int iVar4;
  byte bVar5;
  int unaff_BP;
  char *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  *(int *)(unaff_BP + -0x50) = *(int *)(unaff_BP + -0x50) + in_AX + (uint)in_CF;
  pcVar1 = unaff_SI;
  *pcVar1 = *pcVar1 + (char)((uint)in_AX >> 8);
  if ((POPCOUNT(*pcVar1) & 1U) != 0) {
    cVar2 = *(char *)0x60e8 * '\x02';
    iVar4 = in_CX + -1;
    if (iVar4 != 0 && cVar2 != '\0') {
      *(char *)(unaff_BP + in_AX) = *(char *)(unaff_BP + in_AX) + cVar2;
      out(0x32,cVar2);
    }
    iVar3 = FUN_1000_08ae();
    bVar5 = (byte)((uint)iVar4 >> 8);
    if (!SCARRY2(iVar3,*(int *)0x32e6)) {
      *(int *)0x32e6 = iVar3 + *(int *)0x32e6;
    }
    FUN_1000_27a1();
    unaff_SI[unaff_BP + 0x6aa] = unaff_SI[unaff_BP + 0x6aa] ^ bVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


