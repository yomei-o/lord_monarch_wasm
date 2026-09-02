/* 1000:9836 */

undefined4 __cdecl16near FUN_1000_9836(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  puVar6 = (undefined2 *)0xc8e;
  puVar5 = (undefined2 *)&DAT_0000_8000;
  iVar3 = 0x130;
  do {
    for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar6;
      puVar6 = puVar6 + 1;
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar2 = *puVar1;
    }
    puVar6 = puVar6 + 0x12;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT22(in_DX,in_AX);
}


