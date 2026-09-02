/* 1000:3c62 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

void FUN_1000_3c62(uint *param_1,uint param_2,undefined2 param_3,uint param_4,undefined2 param_5,
                  int param_6,uint param_7)

{
  byte *pbVar1;
  undefined2 *puVar2;
  char *pcVar3;
  uint *puVar4;
  int iVar5;
  byte bVar6;
  byte in_CL;
  uint uVar7;
  uint in_BX;
  int unaff_BP;
  int *unaff_SI;
  int *piVar8;
  uint uVar9;
  uint *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
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
  undefined4 uVar13;
  uint *in_stack_00000000;
  
  uVar9 = ((in_BX & 0xff) * 0x280 + (in_BX >> 8)) * 2 + 0x50e;
  uVar7 = (uint)in_CL;
  if ((char)in_CL < '\0') {
    iVar5 = *unaff_SI;
    FUN_1000_54fb(iVar5);
    pbVar1 = (byte *)(unaff_BP + iVar5 + 0xcaa);
    bVar12 = *pbVar1 < 0xf1;
    *pbVar1 = *pbVar1 + 0xf;
    puVar2 = (undefined2 *)(param_2 + 0x3e);
    *puVar2 = in_FPUControlWord;
    puVar2[2] = in_FPUStatusWord;
    puVar2[4] = in_FPUTagWord;
    *(undefined4 *)(puVar2 + 10) = in_FPUDataPointer;
    *(undefined4 *)(puVar2 + 6) = in_FPUInstructionPointer;
    puVar2[9] = in_FPULastInstructionOpcode;
    *(unkbyte10 *)(puVar2 + 0xe) = in_ST0;
    *(unkbyte10 *)(puVar2 + 0x13) = in_ST1;
    *(unkbyte10 *)(puVar2 + 0x18) = in_ST2;
    *(unkbyte10 *)(puVar2 + 0x1d) = in_ST3;
    *(unkbyte10 *)(puVar2 + 0x22) = in_ST4;
    *(unkbyte10 *)(puVar2 + 0x27) = in_ST5;
    *(unkbyte10 *)(puVar2 + 0x2c) = in_ST6;
    *(unkbyte10 *)(puVar2 + 0x31) = in_ST7;
    goto code_r0x00018496;
  }
  piVar8 = unaff_SI + 1;
  do {
    func_0x000167fa(piVar8);
    iRam0001c54c = iRam0001c54c + 1;
    bVar11 = 0xfaff < uVar9;
    uVar9 = uVar9 + 0x500;
    uVar7 = uVar7 - 1;
  } while (uVar7 != 0);
  while( true ) {
    puVar10 = (uint *)((int)in_stack_00000000 + 1);
    *(char *)in_stack_00000000 = (char)param_7;
    *(char *)(param_2 + (int)param_1) =
         *(char *)(param_2 + (int)param_1) + (char)(param_4 >> 8) + bVar11;
    *(char *)(param_1 + 0x1b) = (char)param_1[0x1b] << 1;
    bVar6 = (byte)(param_7 >> 8);
    if ((byte)param_5 == bVar6) break;
    param_6 = param_6 + 1;
    param_1[-0x3ffb] = (param_1[-0x3ffb] - (int)&stack0x0010) - (uint)((byte)param_5 < bVar6);
    pbVar1 = (byte *)((int)puVar10 + param_2 + 7);
    bVar6 = (byte)((uint)param_5 >> 8);
    bVar12 = CARRY1(*pbVar1,bVar6);
    *pbVar1 = *pbVar1 + bVar6;
    uVar13 = FUN_1000_7a7c();
    param_5 = (undefined2)((ulong)uVar13 >> 0x10);
    param_7 = (uint)uVar13;
    if (!bVar12) goto FUN_1000_84d0;
    do {
      while( true ) {
        in_stack_00000000 = puVar10 + 1;
        param_6 = param_6 + -1;
        if (param_6 == 0) goto code_r0x000184d9;
        uVar7 = *in_stack_00000000;
        param_5 = CONCAT11((char)((uint)param_5 >> 8),(char)puVar10[-0x16c0]);
        if ((char)puVar10[-0x16c0] != '\x05') break;
        param_2 = uVar7;
        puVar10 = in_stack_00000000;
        if (uVar7 < param_4) {
FUN_1000_84d0:
          param_1 = puVar10;
          param_4 = param_2;
          param_2 = param_4;
          puVar10 = param_1;
        }
      }
      param_2 = uVar7 + 8;
      puVar10 = in_stack_00000000;
    } while ((0xfff7 < uVar7) || (bVar12 = param_4 < param_2, param_4 <= param_2));
code_r0x00018496:
    bVar6 = (byte)param_5 + *(byte *)(param_4 + (int)param_1);
    bVar11 = CARRY1((byte)param_5,*(byte *)(param_4 + (int)param_1)) || CARRY1(bVar6,bVar12);
    param_5 = CONCAT11((char)((uint)param_5 >> 8),bVar6 + bVar12);
    puVar4 = in_stack_00000000;
    in_stack_00000000 = in_stack_00000000 + 1;
    *puVar4 = param_7;
  }
  *(undefined2 *)(param_2 + (int)param_1) = 0xa6e2;
code_r0x000184d9:
  uVar7 = param_4 - 8;
  if (param_4 < 8) {
    uVar7 = 0;
  }
  else if (0x1ef < uVar7) {
    *(byte *)(param_2 + 0x5d) = *(byte *)(param_2 + 0x5d) | (byte)uVar7;
    return;
  }
  pcVar3 = (char *)(uVar7 + ((uint)param_1 >> 1));
  *pcVar3 = (*pcVar3 - (char)param_6) - (((uint)param_1 & 1) != 0);
  return;
}


