/* 1000:02c3 */

undefined2 __cdecl16near FUN_1000_02c3(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar3 = (undefined2 *)&DAT_0000_d27e;
  for (iVar2 = 0x900; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = (undefined *)&DAT_0000_3030;
  }
  *(undefined1 *)0x3c08 = 0;
  *(undefined2 *)0x3bc2 = 0xffff;
  return in_AX;
}


