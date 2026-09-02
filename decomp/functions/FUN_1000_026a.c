/* 1000:026a */

undefined2 __cdecl16near FUN_1000_026a(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  
  puVar3 = (undefined2 *)&DAT_0000_648c;
  for (iVar2 = 0x900; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  return in_AX;
}


