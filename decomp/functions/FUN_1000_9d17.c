/* 1000:9d17 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_9d17(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined2 in_DX;
  uint extraout_DX;
  char *pcVar5;
  uint *puVar6;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte in_stack_00000000;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + in_stack_00000000 + in_CF;
  LOCK();
  *(undefined2 *)(param_1 + 0x2f8d) = in_DX;
  UNLOCK();
  pbVar1 = (byte *)(unaff_BP + unaff_DI + -0x79);
  bVar4 = in_stack_00000000 + *pbVar1;
  *(char *)(unaff_BP + 0x2f8d) =
       *(char *)(unaff_BP + 0x2f8d) + bVar4 + CARRY1(in_stack_00000000,*pbVar1);
  FUN_1000_88e0();
  pcVar5 = (char *)(param_1 + -1);
  *(uint *)(unaff_BP + 0x2f8d) = *(uint *)(unaff_BP + 0x2f8d) ^ extraout_DX;
  iVar3 = CONCAT11((char)((uint)pcVar5 >> 8) + *pcVar5,(char)pcVar5);
  func_0x00015b69();
  puVar6 = (uint *)CONCAT11((char)((uint)iVar3 >> 8),(char)iVar3 + *(char *)(iVar3 + -0x4f87));
  *(undefined1 *)(unaff_BP + -0x6a42) = *(undefined1 *)(unaff_BP + -0x6a42);
  bVar2 = thunk_FUN_1000_3656();
  bVar2 = CARRY1(bVar2 | 0xbe,*(byte *)((int)puVar6 + 0x2f85));
  iVar3 = func_0x0001aff4();
  *(int *)(unaff_BP + 0x2f85) = *(int *)(unaff_BP + 0x2f85) + iVar3 + (uint)bVar2;
  pbVar1 = (byte *)(((uint)puVar6 & *puVar6) + 0x2f85);
  *pbVar1 = *pbVar1 & bVar4;
  *(undefined2 *)0x2f83 = 1;
  FUN_1000_5d66();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


