/* 1000:c6bc */

void __cdecl16near FUN_1000_c6bc(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)0x280b;
  puVar5 = (undefined2 *)0xd276;
  for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  return;
}


