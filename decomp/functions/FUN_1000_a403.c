/* 1000:a403 */

undefined4 FUN_1000_a403(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint in_AX;
  int iVar3;
  int extraout_DX;
  int iVar4;
  uint in_BX;
  int unaff_BP;
  byte *pbVar5;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  undefined2 in_stack_0000000c;
  undefined2 in_stack_00000010;
  
  puVar1 = (uint *)(unaff_BP + -0x30);
  bVar6 = CARRY2(*puVar1,in_BX) || CARRY2(*puVar1 + in_BX,(uint)(in_AX < *unaff_DI));
  *puVar1 = *puVar1 + in_BX + (uint)(in_AX < *unaff_DI);
  *(undefined1 *)(unaff_BP + 0x3302) = (char)(in_BX >> 8);
  func_0x00012dd6();
  iVar4 = extraout_DX;
  if (!bVar6) {
    iVar3 = *(int *)(*(int *)0x3e94 + 0x1c);
    pbVar5 = (byte *)0x0;
    iVar4 = 0;
    do {
      pbVar2 = pbVar5;
      pbVar5 = pbVar5 + 1;
      iVar4 = iVar4 + (uint)*pbVar2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar4 = iVar4 - *(int *)(*(int *)0x3e94 + 0x12);
  }
  *(int *)0x347e = iVar4;
  return CONCAT22(in_stack_0000000c,in_stack_00000010);
}


