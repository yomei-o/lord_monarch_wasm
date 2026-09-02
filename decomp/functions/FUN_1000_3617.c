/* 1000:3617 */

void FUN_1000_3617(void)

{
  char cVar1;
  code *pcVar2;
  byte in_AH;
  undefined2 *puVar3;
  undefined2 *unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)(unaff_DI + 0x3a64) = *(byte *)(unaff_DI + 0x3a64) ^ in_AH;
  puVar3 = (undefined2 *)&stack0xfffe;
  cVar1 = '\x19';
  do {
    unaff_BP = unaff_BP + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *unaff_BP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


