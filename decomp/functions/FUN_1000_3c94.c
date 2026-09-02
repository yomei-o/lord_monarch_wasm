/* 1000:3c94 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

void FUN_1000_3c94(uint *param_1,uint param_2,undefined2 param_3,uint param_4,undefined2 param_5,
                  int param_6,uint param_7)

{
  undefined2 *puVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  int unaff_BP;
  int *unaff_SI;
  uint *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
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
  undefined4 uVar12;
  uint *in_stack_00000000;
  
  iVar4 = *unaff_SI;
  FUN_1000_54fb(iVar4);
  pbVar2 = (byte *)(unaff_BP + iVar4 + 0xcaa);
  bVar11 = *pbVar2 < 0xf1;
  *pbVar2 = *pbVar2 + 0xf;
  puVar1 = (undefined2 *)(param_2 + 0x3e);
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
  while( true ) {
    bVar6 = *(byte *)(param_4 + (int)param_1);
    bVar5 = (byte)param_5 + *(byte *)(param_4 + (int)param_1);
    bVar8 = (byte)((uint)param_5 >> 8);
    bVar7 = bVar5 + bVar11;
    *in_stack_00000000 = param_7;
    puVar10 = (uint *)((int)in_stack_00000000 + 3);
    *(char *)(in_stack_00000000 + 1) = (char)param_7;
    *(char *)(param_2 + (int)param_1) =
         *(char *)(param_2 + (int)param_1) + (char)(param_4 >> 8) +
         (CARRY1((byte)param_5,bVar6) || CARRY1(bVar5,bVar11));
    *(char *)(param_1 + 0x1b) = (char)param_1[0x1b] << 1;
    bVar6 = (byte)(param_7 >> 8);
    if (bVar7 == bVar6) break;
    param_6 = param_6 + 1;
    param_1[-0x3ffb] = (param_1[-0x3ffb] - (int)&stack0x0010) - (uint)(bVar7 < bVar6);
    pbVar2 = (byte *)((int)puVar10 + param_2 + 7);
    bVar11 = CARRY1(*pbVar2,bVar8);
    *pbVar2 = *pbVar2 + bVar8;
    uVar12 = FUN_1000_7a7c();
    param_5 = (undefined2)((ulong)uVar12 >> 0x10);
    param_7 = (uint)uVar12;
    uVar9 = param_2;
    if (!bVar11) goto FUN_1000_84d0;
    do {
      while( true ) {
        in_stack_00000000 = puVar10 + 1;
        param_6 = param_6 + -1;
        if (param_6 == 0) goto code_r0x000184d9;
        uVar9 = *in_stack_00000000;
        param_5 = CONCAT11((char)((uint)param_5 >> 8),(char)puVar10[-0x16c0]);
        if ((char)puVar10[-0x16c0] != '\x05') break;
        param_2 = uVar9;
        puVar10 = in_stack_00000000;
        if (uVar9 < param_4) {
FUN_1000_84d0:
          param_1 = puVar10;
          param_4 = uVar9;
          param_2 = param_4;
          puVar10 = param_1;
        }
      }
      param_2 = uVar9 + 8;
      puVar10 = in_stack_00000000;
    } while ((0xfff7 < uVar9) || (bVar11 = param_4 < param_2, param_4 <= param_2));
  }
  *(undefined2 *)(param_2 + (int)param_1) = 0xa6e2;
code_r0x000184d9:
  uVar9 = param_4 - 8;
  if (param_4 < 8) {
    uVar9 = 0;
  }
  else if (0x1ef < uVar9) {
    *(byte *)(param_2 + 0x5d) = *(byte *)(param_2 + 0x5d) | (byte)uVar9;
    return;
  }
  pcVar3 = (char *)(uVar9 + ((uint)param_1 >> 1));
  *pcVar3 = (*pcVar3 - (char)param_6) - (((uint)param_1 & 1) != 0);
  return;
}


