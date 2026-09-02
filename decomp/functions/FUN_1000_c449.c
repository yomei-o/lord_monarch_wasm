/* 1000:c449 */

void __cdecl16near FUN_1000_c449(void)

{
  char *pcVar1;
  char *pcVar2;
  int in_CX;
  char *pcVar3;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  pcVar3 = (char *)s_0000000000_0000_32b0 + 10 + -in_CX;
  for (; in_CX != 0; in_CX = in_CX + -1) {
    pcVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar2 = *pcVar1;
  }
  return;
}


