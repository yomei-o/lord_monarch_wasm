/* 1000:6efd */

undefined2 __cdecl16near FUN_1000_6efd(void)

{
  undefined2 in_AX;
  int iVar1;
  char *pcVar2;
  undefined2 unaff_DS;
  
  pcVar2 = (char *)*(undefined2 *)0x3e82;
  iVar1 = 0xc0;
  while( true ) {
    if (*pcVar2 == '\0') {
      return in_AX;
    }
    if (*pcVar2 == -0x1b) break;
    pcVar2 = pcVar2 + 0x20;
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      *(undefined1 *)0x3e92 = 0xd0;
      return in_AX;
    }
  }
  return in_AX;
}


