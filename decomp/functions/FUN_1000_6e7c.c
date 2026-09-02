/* 1000:6e7c */

undefined4 FUN_1000_6e7c(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 in_stack_00000000;
  
  puVar4 = (undefined2 *)0x648c;
  puVar5 = (undefined2 *)0x6d8c;
  for (iVar3 = 0x240; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  return CONCAT22(param_3,param_1);
}


