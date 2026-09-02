/* 1000:04b8 */

undefined4 __cdecl16near FUN_1000_04b8(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x3bd4 = 0;
  *(undefined2 *)0x3bd6 = 0;
  *(undefined2 *)0xc52c = 0;
  *(undefined2 *)&DAT_0000_32bf = 0;
  FUN_1000_bcf4();
  FUN_1000_026a();
  FUN_1000_02e1();
  FUN_1000_02f9();
  FUN_1000_0311();
  FUN_1000_0296();
  FUN_1000_a6a5();
  if (*(byte *)0x3c00 < 4) {
    FUN_1000_a62d();
    FUN_1000_a656();
  }
  FUN_1000_727a();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_7c9e();
  puVar4 = (undefined1 *)0x3eea;
  puVar5 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x2d; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = (undefined2 *)((int)puVar5 + 1);
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *(undefined1 *)puVar2 = *puVar1;
  }
  *(byte *)0x3483 = *(byte *)0x3483 ^ 1;
  FUN_1000_727a();
  FUN_1000_9355();
  FUN_1000_727a();
  FUN_1000_7c9e();
  FUN_1000_72ad();
  return CONCAT22(in_DX,in_AX);
}


