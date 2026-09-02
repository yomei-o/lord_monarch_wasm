/* 1000:74c6 */

undefined2 __cdecl16near FUN_1000_74c6(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  FUN_1000_724a();
  puVar4 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  puVar4 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  out(0x7c,0);
  iVar5 = 0x3484;
  iVar3 = 6;
  do {
    *(undefined2 *)(iVar5 + 2) = 0;
    *(undefined2 *)(iVar5 + 4) = 0;
    *(undefined2 *)(iVar5 + 6) = 0;
    *(undefined2 *)(iVar5 + 8) = 0;
    iVar5 = iVar5 + 10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return in_AX;
}


