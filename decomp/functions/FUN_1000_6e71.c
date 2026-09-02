/* 1000:6e71 */

undefined4
FUN_1000_6e71(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  char *pcVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int in_BX;
  char cVar5;
  int unaff_BP;
  int unaff_SI;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar1 = (char *)(in_BX + unaff_SI + 0x18e8);
  cVar5 = (char)((uint)in_BX >> 8);
  *pcVar1 = *pcVar1 + cVar5;
  pcVar1 = (char *)(unaff_BP + unaff_SI + -0x5000);
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
  return CONCAT22(param_4,param_2);
}


