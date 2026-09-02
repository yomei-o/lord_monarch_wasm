/* 1000:9355 */

undefined4 __cdecl16near FUN_1000_9355(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  int iVar3;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  
  if (*(int *)0x34c8 != 0) {
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_724a();
  puVar4 = (undefined2 *)0x666f;
  iVar1 = 0x80;
  do {
    *puVar4 = 0xffff;
    *(undefined2 *)((int)puVar4 + 3) = 0xffff;
    puVar4[3] = 0xffff;
    *(undefined2 *)((int)puVar4 + 9) = 0xffff;
    *(undefined1 *)(puVar4 + 6) = 0xff;
    puVar4 = puVar4 + -0x28;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  out(0x7c,0);
  iVar3 = 0x3484;
  iVar1 = 2;
  if ((*(byte *)0x3482 & 1) != 0) {
    iVar1 = 6;
  }
  iVar2 = 4;
  do {
    *(undefined2 *)(iVar1 + iVar3) = 0;
    *(undefined2 *)(iVar1 + iVar3 + 2) = 0;
    FUN_1000_97c3();
    iVar3 = iVar3 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(iVar1 + iVar3) = 0;
  *(undefined2 *)(iVar1 + iVar3 + 2) = 0;
  return CONCAT22(in_DX,in_AX);
}


