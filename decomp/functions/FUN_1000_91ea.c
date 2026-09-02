/* 1000:91ea */

undefined4 __cdecl16near FUN_1000_91ea(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  int extraout_DX;
  uint in_BX;
  undefined1 *puVar5;
  
  puVar5 = (undefined1 *)(((in_BX & 0xff) * 0x280 + (in_BX >> 8)) * 2 + 0x50d);
  iVar3 = (in_CX & 0xff) << 4;
  FUN_1000_724a();
  do {
    puVar1 = (undefined2 *)(puVar5 + 1);
    *puVar5 = 0xff;
    for (iVar4 = extraout_DX; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar1;
      puVar1 = puVar1 + 1;
      *puVar2 = 0xffff;
    }
    *(undefined1 *)puVar1 = 0xff;
    puVar5 = (undefined1 *)((int)puVar1 + (0x27 - ((in_CX >> 8) - 1)) * 2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


