/* 1000:85e0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000185fa) overlaps instruction at (ram,0x000185f7)
    */

void FUN_1000_85e0(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 in_AX;
  char cVar3;
  int in_CX;
  char in_DL;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  cVar3 = (char)((uint)in_AX >> 8);
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  cVar2 = (byte)in_AX + *(byte *)(in_BX + unaff_DI);
  *(char *)(in_BX + unaff_SI) =
       *(char *)(in_BX + unaff_SI) + in_DL + CARRY1((byte)in_AX,*(byte *)(in_BX + unaff_DI));
  if (SCARRY1(cVar3,*(char *)(in_BX + unaff_SI + 0x10))) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(char *)(in_BX + unaff_DI) = *(char *)(in_BX + unaff_DI) + cVar2;
  if (in_CX == 1) {
    if (0xfffd < unaff_SI || unaff_SI + 2 == 0) {
      pcVar1 = (char *)(unaff_BP + unaff_SI + 2);
      *pcVar1 = *pcVar1 + cVar2 + (0xfffd < unaff_SI);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in(0xd1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


