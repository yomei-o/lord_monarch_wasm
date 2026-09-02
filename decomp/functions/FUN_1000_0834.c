/* 1000:0834 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00010848) overlaps instruction at (ram,0x00010846)
    */

void FUN_1000_0834(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 in_AX;
  int iVar3;
  int in_CX;
  int iVar4;
  byte bVar5;
  int unaff_BP;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar1 = unaff_SI;
  *pcVar1 = *pcVar1 + (char)((uint)in_AX >> 8);
  if ((POPCOUNT(*pcVar1) & 1U) != 0) {
    cVar2 = *(char *)0x60e8 * '\x02';
    iVar4 = in_CX + -1;
    if (iVar4 != 0 && cVar2 != '\0') {
      *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + cVar2;
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


