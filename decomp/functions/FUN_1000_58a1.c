/* 1000:58a1 */

void FUN_1000_58a1(void)

{
  char *pcVar1;
  char *pcVar2;
  int in_CX;
  int iVar3;
  int in_BX;
  int unaff_BP;
  char *pcVar4;
  char *unaff_DI;
  char *pcVar5;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  
  do {
    if (*unaff_DI == '\0') break;
    pcVar4 = (char *)*(undefined2 *)(unaff_BP + -2);
    iVar3 = 0xb;
    bVar6 = false;
    pcVar5 = unaff_DI;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar2 = pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar1 = pcVar4;
      pcVar4 = pcVar4 + 1;
      bVar6 = *pcVar1 == *pcVar2;
    } while (bVar6);
    if (bVar6) {
      *(int *)(pcVar4 + in_BX + 0x2627) = in_BX;
      return;
    }
    unaff_DI = unaff_DI + 0x20;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  *(undefined1 *)0x3e92 = 0x80;
  return;
}


