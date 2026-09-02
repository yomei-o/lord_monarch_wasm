/* 1000:7571 */

undefined2 __cdecl16near FUN_1000_7571(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *in_BX;
  undefined2 *puVar3;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x168e;
  do {
    for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = puVar3;
      puVar3 = puVar3 + 1;
      *puVar1 = 0xffff;
    }
    puVar3 = puVar3 + 0xf;
  } while (puVar3 < in_BX);
  out(0x7c,0);
  return in_AX;
}


