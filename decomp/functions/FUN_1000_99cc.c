/* 1000:99cc */

undefined4 __cdecl16near FUN_1000_99cc(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  
  out(0x68,0);
  puVar3 = (undefined2 *)0x0;
  for (iVar2 = 2000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0x20;
  }
  puVar3 = (undefined2 *)0x2000;
  for (iVar2 = 2000; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xe1;
  }
  return CONCAT22(in_DX,in_AX);
}


