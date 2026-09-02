/* 1000:3c36 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

void FUN_1000_3c36(uint *param_1,uint *param_2,uint param_3,undefined2 param_4,uint param_5,
                  undefined2 param_6,int param_7,uint param_8)

{
  byte *pbVar1;
  undefined2 *puVar2;
  char *pcVar3;
  uint *puVar4;
  undefined2 in_AX;
  byte bVar5;
  char in_CL;
  uint uVar6;
  int unaff_BP;
  uint *unaff_SI;
  uint *puVar7;
  char *unaff_DI;
  uint uVar8;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  bool bVar10;
  bool in_ZF;
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
  undefined4 uVar11;
  byte in_stack_00000000;
  
  if ((!in_ZF) && ((char)((char)in_AX - (char)((uint)in_AX >> 8)) == in_CL)) {
    *unaff_DI = *unaff_DI + -1;
  }
  uVar6 = *unaff_SI;
  uVar8 = unaff_SI[1];
  puVar7 = unaff_SI + 3;
  bVar5 = unaff_DI[1];
  *(int *)0xc54c = bVar5 + 1;
  if (-1 < (char)uVar8) {
    puVar7 = puVar7 + bVar5;
  }
  FUN_1000_3dc0(uVar8);
  uVar8 = ((uVar6 & 0xff) * 0x280 + (uVar6 >> 8)) * 2 + 0x50e;
  uVar6 = (uint)in_stack_00000000;
  if ((char)in_stack_00000000 < '\0') {
    uVar6 = *puVar7;
    FUN_1000_54fb();
    pbVar1 = (byte *)(unaff_BP + uVar6 + 0xcaa);
    bVar10 = *pbVar1 < 0xf1;
    *pbVar1 = *pbVar1 + 0xf;
    puVar2 = (undefined2 *)(param_3 + 0x3e);
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
  do {
    func_0x000167fa();
    iRam0001c54c = iRam0001c54c + 1;
    bVar9 = 0xfaff < uVar8;
    uVar8 = uVar8 + 0x500;
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  while( true ) {
    puVar7 = (uint *)((int)param_1 + 1);
    *(char *)param_1 = (char)param_8;
    *(char *)(param_3 + (int)param_2) =
         *(char *)(param_3 + (int)param_2) + (char)(param_5 >> 8) + bVar9;
    *(char *)(param_2 + 0x1b) = (char)param_2[0x1b] << 1;
    bVar5 = (byte)(param_8 >> 8);
    if ((byte)param_6 == bVar5) break;
    param_7 = param_7 + 1;
    param_2[-0x3ffb] = (param_2[-0x3ffb] - (int)&stack0x0012) - (uint)((byte)param_6 < bVar5);
    pbVar1 = (byte *)((int)puVar7 + param_3 + 7);
    bVar5 = (byte)((uint)param_6 >> 8);
    bVar10 = CARRY1(*pbVar1,bVar5);
    *pbVar1 = *pbVar1 + bVar5;
    uVar11 = FUN_1000_7a7c();
    param_6 = (undefined2)((ulong)uVar11 >> 0x10);
    param_8 = (uint)uVar11;
    if (!bVar10) goto FUN_1000_84d0;
    do {
      while( true ) {
        param_1 = puVar7 + 1;
        param_7 = param_7 + -1;
        if (param_7 == 0) goto code_r0x000184d9;
        uVar6 = *param_1;
        param_6 = CONCAT11((char)((uint)param_6 >> 8),(char)puVar7[-0x16c0]);
        if ((char)puVar7[-0x16c0] != '\x05') break;
        param_3 = uVar6;
        puVar7 = param_1;
        if (uVar6 < param_5) {
FUN_1000_84d0:
          param_2 = puVar7;
          param_5 = param_3;
          param_3 = param_5;
          puVar7 = param_2;
        }
      }
      param_3 = uVar6 + 8;
      puVar7 = param_1;
    } while ((0xfff7 < uVar6) || (bVar10 = param_5 < param_3, param_5 <= param_3));
code_r0x00018496:
    bVar5 = (byte)param_6 + *(byte *)(param_5 + (int)param_2);
    bVar9 = CARRY1((byte)param_6,*(byte *)(param_5 + (int)param_2)) || CARRY1(bVar5,bVar10);
    param_6 = CONCAT11((char)((uint)param_6 >> 8),bVar5 + bVar10);
    puVar4 = param_1;
    param_1 = param_1 + 1;
    *puVar4 = param_8;
  }
  *(undefined2 *)(param_3 + (int)param_2) = 0xa6e2;
code_r0x000184d9:
  uVar6 = param_5 - 8;
  if (param_5 < 8) {
    uVar6 = 0;
  }
  else if (0x1ef < uVar6) {
    *(byte *)(param_3 + 0x5d) = *(byte *)(param_3 + 0x5d) | (byte)uVar6;
    return;
  }
  pcVar3 = (char *)(uVar6 + ((uint)param_2 >> 1));
  *pcVar3 = (*pcVar3 - (char)param_7) - (((uint)param_2 & 1) != 0);
  return;
}


