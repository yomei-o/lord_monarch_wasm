/* 1000:06e7 */

undefined4 __cdecl16near FUN_1000_06e7(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 in_CX;
  int iVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined2 unaff_ES;
  undefined2 in_stack_00000000;
  
  puVar4 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar1 = puVar4;
    puVar4 = (undefined2 *)((int)puVar4 + 1);
    *(undefined1 *)puVar1 = 0;
  }
  puVar5 = (undefined1 *)((int)puVar4 + 3);
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = 0;
  }
  FUN_1000_7518();
  puVar5 = (undefined1 *)0x5f1c;
  for (iVar3 = 0x30; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = 0xff;
  }
  for (iVar3 = 0x90; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = 0;
  }
  FUN_1000_759b();
  FUN_1000_49bb();
  FUN_1000_4be9();
  FUN_1000_7518();
  return CONCAT22(in_CX,in_stack_00000000);
}


