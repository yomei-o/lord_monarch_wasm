/* 1000:977e */

undefined4 __cdecl16near FUN_1000_977e(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 in_DX;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  
  puVar7 = (undefined2 *)0x5f1c;
  uVar2 = 0xa800;
  do {
    uVar3 = uVar2;
    puVar6 = (undefined2 *)0x28c;
    iVar5 = 0x10;
    do {
      puVar1 = puVar7 + 1;
      *puVar7 = *puVar6;
      puVar7 = (undefined2 *)((int)puVar7 + 3);
      *(undefined1 *)puVar1 = *(undefined1 *)(puVar6 + 1);
      puVar6 = puVar6 + 0x28;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    uVar4 = uVar3 + 0x800;
    uVar2 = uVar4;
  } while ((uVar4 < 0xb801) || (uVar2 = uVar3 + 0x2800, uVar4 < 0xe000));
  return CONCAT22(in_DX,in_AX);
}


