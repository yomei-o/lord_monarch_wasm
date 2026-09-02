/* 1000:856d */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018585) overlaps instruction at (ram,0x00018584)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_856d(void)

{
  undefined2 *puVar1;
  char *pcVar2;
  byte *pbVar3;
  uint *puVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined1 uVar8;
  byte bVar9;
  undefined2 in_AX;
  byte bVar11;
  uint uVar10;
  int in_CX;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
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
  
  bVar11 = (byte)((uint)in_AX >> 8);
  uVar8 = in(in_DX);
  LOCK();
  *(byte *)(unaff_BP + unaff_DI) = *(byte *)(unaff_BP + unaff_DI) | (byte)((uint)in_BX >> 8);
  UNLOCK();
  puVar1 = (undefined2 *)(unaff_BP + 0x18);
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
  iVar7 = *(int *)(in_BX + unaff_DI);
  *(int *)(iVar7 + -2) = in_CX;
  *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) ^ in_DX;
  uVar10 = CONCAT11(bVar11,uVar8) | 0x3a;
  *(char *)(unaff_SI + 8) = *(char *)(unaff_SI + 8) << 1;
  bVar12 = (byte)in_DX < bVar11;
  if ((byte)in_DX == bVar11) {
    pcVar2 = (char *)(in_BX + unaff_SI);
    cVar5 = *pcVar2;
    *pcVar2 = *pcVar2 + '\x01';
    bVar9 = (byte)uVar10;
    if (!SCARRY1(cVar5,'\x01')) {
      *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + 1;
      unaff_BP = *(int *)(unaff_SI + 2);
      pbVar3 = (byte *)(in_BX + unaff_SI + 2);
      *pbVar3 = *pbVar3 & bVar11;
      puVar4 = (uint *)(in_BX + unaff_SI);
      uVar6 = *puVar4;
      *puVar4 = *puVar4 + in_DX;
      pbVar3 = (byte *)(unaff_BP + unaff_SI);
      bVar12 = CARRY1(*pbVar3,bVar9) || CARRY1(*pbVar3 + bVar9,CARRY2(uVar6,in_DX));
      *pbVar3 = *pbVar3 + bVar9 + CARRY2(uVar6,in_DX);
    }
    *(uint *)(iVar7 + -4) = uVar10;
    *(int *)(iVar7 + -6) = in_CX;
    *(uint *)(iVar7 + -8) = in_DX;
    *(int *)(iVar7 + -10) = in_BX;
    *(int *)(iVar7 + -0xc) = iVar7 + -2;
    *(int *)(iVar7 + -0xe) = unaff_BP;
    *(uint *)(iVar7 + -0x10) = unaff_SI;
    *(int *)(iVar7 + -0x12) = unaff_DI;
    pcVar2 = (char *)(in_BX + unaff_SI + 0xe);
    *pcVar2 = *pcVar2 + (char)(in_DX >> 8) + bVar12;
    *(char *)(in_BX + unaff_DI) = *(char *)(in_BX + unaff_DI) + bVar9;
    if (in_CX != 1) {
      in(0xd1);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (0xfffd < unaff_SI || unaff_SI + 2 == 0) {
      pcVar2 = (char *)(unaff_BP + unaff_SI + 2);
      *pcVar2 = *pcVar2 + bVar9 + (0xfffd < unaff_SI);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


