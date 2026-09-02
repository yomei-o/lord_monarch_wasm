/* 1000:a307 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_a307(void)

{
  undefined2 *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  char extraout_DL;
  int in_BX;
  int iVar5;
  int unaff_BP;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar7;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 in_FPUTagWord;
  undefined2 in_FPULastInstructionOpcode;
  undefined4 in_FPUDataPointer;
  undefined4 in_FPUInstructionPointer;
  unkbyte10 in_ST0;
  unkbyte10 in_ST1;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  unkbyte10 in_ST6;
  unkbyte10 in_ST7;
  undefined4 uVar8;
  
  while (iVar5 = 0, in_BX != 0) {
    FUN_1000_a413();
  }
  do {
    uVar3 = FUN_1000_a3fe();
  } while (0x9f < uVar3);
  func_0x00015b69();
  FUN_1000_87bd();
  FUN_1000_8794();
  *(undefined2 *)0xd276 = 0x1720;
  *(undefined2 *)0xd27a = 0;
  do {
    iVar6 = 0x3a3a;
    iVar4 = 6;
    bVar2 = 0x80;
    do {
      bVar2 = bVar2 & *(byte *)(iVar6 + 0x1f);
      iVar6 = iVar6 + 0x20;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    bVar7 = 0;
  } while (bVar2 == 0);
  thunk_FUN_1000_88e6();
  bVar2 = (byte)iVar4;
  FUN_1000_336a();
  FUN_1000_5a02();
  uVar8 = func_0x00018878();
  out(0x1c,(char)uVar8);
  *(int *)(iVar5 + 0x32a5) = *(int *)(iVar5 + 0x32a5) + (int)((ulong)uVar8 >> 0x10) + (uint)bVar7;
  *(undefined2 *)0xb8b6 = (int)uVar8;
  FUN_1000_5b6a();
  FUN_1000_8859();
  func_0x00013363();
  FUN_1000_5a02();
  func_0x00018871();
  func_0x0001b563();
  iVar5 = CONCAT11((char)((uint)iVar5 >> 8) + *(char *)(unaff_BP + 0x4500),(char)iVar5);
  *(byte *)(iVar5 + 0x326d) = *(byte *)(iVar5 + 0x326d) & bVar2;
  puVar1 = (undefined2 *)(iVar5 + -0x3618);
  *puVar1 = in_FPUControlWord;
  puVar1[2] = in_FPUStatusWord;
  puVar1[4] = in_FPUTagWord;
  *(undefined4 *)(puVar1 + 10) = in_FPUDataPointer;
  *(undefined4 *)(puVar1 + 6) = in_FPUInstructionPointer;
  puVar1[9] = in_FPULastInstructionOpcode;
  *(unkbyte10 *)(puVar1 + 0xe) = in_ST0;
  *(unkbyte10 *)(puVar1 + 0x13) = in_ST1;
  *(unkbyte10 *)(puVar1 + 0x18) = in_ST2;
  *(unkbyte10 *)(puVar1 + 0x1d) = in_ST3;
  *(unkbyte10 *)(puVar1 + 0x22) = in_ST4;
  *(unkbyte10 *)(puVar1 + 0x27) = in_ST5;
  *(unkbyte10 *)(puVar1 + 0x2c) = in_ST6;
  *(unkbyte10 *)(puVar1 + 0x31) = in_ST7;
  *(char *)(iVar5 + 0x326d) = *(char *)(iVar5 + 0x326d) - extraout_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


