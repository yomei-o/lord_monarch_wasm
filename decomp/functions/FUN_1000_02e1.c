/* 1000:02e1 */

undefined2 __cdecl16near FUN_1000_02e1(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar3 = (undefined2 *)&DAT_0000_768e;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  *(undefined2 *)0x768c = 0;
  return in_AX;
}


