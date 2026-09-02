/* 1000:0a14 */

void FUN_1000_0a14(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar4 = *(int *)0x34de + 1U & 3;
  *(uint *)0x34de = uVar4;
  puVar5 = (undefined1 *)(uVar4 * 4 + 0x2f6d);
  puVar6 = (undefined1 *)0x3e4a;
  for (iVar3 = 3; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  return;
}


