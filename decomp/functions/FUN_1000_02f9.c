/* 1000:02f9 */

undefined2 __cdecl16near FUN_1000_02f9(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)&DAT_0000_2400;
  for (iVar2 = 0x1000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
  return in_AX;
}


