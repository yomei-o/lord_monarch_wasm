/* 1000:a413 */

undefined4 FUN_1000_a413(void)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  undefined2 in_DX;
  int iVar4;
  int unaff_BP;
  int unaff_SI;
  byte *pbVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0x1c);
  *pcVar1 = *pcVar1 + (char)((uint)in_DX >> 8);
  iVar3 = *(int *)(*(int *)0x3e94 + 0x1c);
  pbVar5 = (byte *)0x0;
  iVar4 = 0;
  do {
    pbVar2 = pbVar5;
    pbVar5 = pbVar5 + 1;
    iVar4 = iVar4 + (uint)*pbVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(int *)0x347e = iVar4 - *(int *)(*(int *)0x3e94 + 0x12);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


