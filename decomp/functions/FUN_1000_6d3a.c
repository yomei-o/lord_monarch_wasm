/* 1000:6d3a */

void __cdecl16near FUN_1000_6d3a(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *unaff_SI;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool bVar8;
  
  pcVar7 = (char *)*(undefined2 *)0x3e82;
  iVar3 = 0xc0;
  do {
    if (*pcVar7 == '\0') break;
    iVar4 = 0xb;
    bVar8 = false;
    pcVar5 = unaff_SI;
    pcVar6 = pcVar7;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar2 = pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
      bVar8 = *pcVar1 == *pcVar2;
    } while (bVar8);
    if (bVar8) {
      *(undefined2 *)0x3e94 = pcVar7;
      return;
    }
    pcVar7 = pcVar7 + 0x20;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)0x3e92 = 0x80;
  return;
}


