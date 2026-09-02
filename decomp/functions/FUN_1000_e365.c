/* 1000:e365 */

undefined4 __cdecl16near FUN_1000_e365(void)

{
  byte *pbVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  int extraout_DX;
  int iVar3;
  byte *pbVar4;
  undefined2 unaff_DS;
  undefined1 uVar5;
  
  uVar5 = 0;
  FUN_1000_6c3f();
  FUN_1000_6d3a();
  iVar3 = extraout_DX;
  if (!(bool)uVar5) {
    iVar2 = *(int *)(*(int *)0x3e94 + 0x1c);
    pbVar4 = (byte *)0x0;
    iVar3 = 0;
    do {
      pbVar1 = pbVar4;
      pbVar4 = pbVar4 + 1;
      iVar3 = iVar3 + (uint)*pbVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 - *(int *)(*(int *)0x3e94 + 0x12);
  }
  *(int *)0x347e = iVar3;
  return CONCAT22(in_DX,in_AX);
}


