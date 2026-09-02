/* 1000:35c6 */

void FUN_1000_35c6(void)

{
  char cVar1;
  code *pcVar2;
  byte extraout_AH;
  byte in_BL;
  undefined2 *unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  func_0x00013d2f();
  *(byte *)((int)unaff_BP + unaff_DI) = *(byte *)((int)unaff_BP + unaff_DI) | in_BL;
  *(byte *)(unaff_DI + 0x3a64) = *(byte *)(unaff_DI + 0x3a64) ^ extraout_AH;
  cVar1 = '\x19';
  do {
    unaff_BP = unaff_BP + -1;
    register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + -2);
    *(undefined2 *)register0x00000010 = *unaff_BP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


