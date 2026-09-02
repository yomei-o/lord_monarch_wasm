/* 1000:e33b */

undefined3 __cdecl16near FUN_1000_e33b(void)

{
  int iVar1;
  char extraout_DL;
  char cVar2;
  char extraout_DH;
  int in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9aa6();
  *(undefined1 *)0x32d3 = 1;
  iVar1 = FUN_1000_c6fa();
  cVar2 = extraout_DL + -1;
  if (cVar2 == '\0') {
    in_BX = in_BX + 1;
    cVar2 = extraout_DH;
  }
  return CONCAT12(cVar2,iVar1 - in_BX);
}


