/* 1000:97c3 */

undefined4 __cdecl16near FUN_1000_97c3(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x5fdc;
  iVar2 = 0x10;
  do {
    puVar1 = puVar3 + 1;
    *unaff_DI = *puVar3;
    puVar3 = (undefined2 *)((int)puVar3 + 3);
    *(undefined1 *)(unaff_DI + 1) = *(undefined1 *)puVar1;
    unaff_DI = unaff_DI + 0x28;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


