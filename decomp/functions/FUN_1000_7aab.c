/* 1000:7aab */

undefined4 __cdecl16near FUN_1000_7aab(void)

{
  undefined1 *puVar1;
  undefined2 in_AX;
  char cVar2;
  int in_CX;
  int iVar3;
  undefined2 in_DX;
  undefined1 *unaff_DI;
  
  FUN_1000_724a();
  cVar2 = '\x10';
  iVar3 = in_CX;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar1 = 0xff;
    }
    unaff_DI = unaff_DI + (0x50 - in_CX);
    cVar2 = cVar2 + -1;
    iVar3 = in_CX;
  } while (cVar2 != '\0');
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


