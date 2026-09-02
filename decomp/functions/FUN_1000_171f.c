/* 1000:171f */

undefined4 FUN_1000_171f(int param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  char *pcVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  char cVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uStack000e;
  undefined2 in_stack_00000014;
  undefined2 in_stack_00000016;
  undefined2 in_stack_0000001a;
  
  cVar5 = (char)((uint)param_4 >> 8);
  uStack000e = 0x1724;
  FUN_1000_48a5();
  pcVar1 = (char *)(param_2 + param_1 + -0x5000);
  *pcVar1 = *pcVar1 + cVar5;
  FUN_1000_6e8e();
  puVar6 = (undefined2 *)0x648c;
  puVar7 = (undefined2 *)0x6d8c;
  for (iVar4 = 0x240; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar3 = puVar7;
    puVar7 = puVar7 + 1;
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar3 = *puVar2;
  }
  return CONCAT22(in_stack_0000001a,in_stack_00000016);
}


