/* 1000:753b */

undefined2 __cdecl16near FUN_1000_753b(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  FUN_1000_724a();
  puVar3 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  puVar3 = (undefined2 *)0x0;
  for (puVar2 = (undefined2 *)&DAT_0000_3e80; puVar2 != (undefined2 *)0x0;
      puVar2 = (undefined2 *)((int)puVar2 + -1)) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  FUN_1000_727a();
  out(0x7c,0);
  return in_AX;
}


