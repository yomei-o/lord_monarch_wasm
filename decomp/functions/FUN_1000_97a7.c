/* 1000:97a7 */

undefined4 __cdecl16near FUN_1000_97a7(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 unaff_ES;
  
  puVar4 = (undefined2 *)0x5fdc;
  puVar3 = (undefined2 *)0x66be;
  iVar2 = 0x10;
  do {
    puVar1 = puVar4 + 1;
    *puVar4 = *puVar3;
    puVar4 = (undefined2 *)((int)puVar4 + 3);
    *(undefined1 *)puVar1 = *(undefined1 *)(puVar3 + 1);
    puVar3 = puVar3 + 0x28;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}


