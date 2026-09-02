/* 1000:3c1a */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

void FUN_1000_3c1a(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint *puVar3;
  byte bVar4;
  int in_AX;
  undefined2 in_CX;
  byte bVar6;
  uint uVar5;
  undefined1 *in_DX;
  undefined1 *puVar7;
  uint *unaff_BP;
  undefined1 *puVar8;
  uint *unaff_SI;
  uint *puVar9;
  char *unaff_DI;
  uint uVar10;
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
  uint in_stack_00000000;
  undefined2 in_stack_0000003e;
  
  bVar6 = (char)unaff_SI[2] - 1;
  bVar4 = (byte)*(undefined2 *)unaff_DI;
  if (bVar6 < bVar4) {
    unaff_DI[0] = '\0';
    unaff_DI[1] = '\0';
  }
  else if ((bVar4 != bVar6) &&
          ((byte)(bVar4 - (char)((uint)*(undefined2 *)unaff_DI >> 8)) ==
           (byte)(((byte)unaff_SI[1] & 0x7f) - 1))) {
    *unaff_DI = *unaff_DI + -1;
  }
  uVar5 = *unaff_SI;
  uVar10 = unaff_SI[1];
  puVar9 = unaff_SI + 3;
  bVar4 = unaff_DI[1];
  *(int *)0xc54c = bVar4 + 1;
  if (-1 < (char)uVar10) {
    puVar9 = puVar9 + bVar4;
  }
  FUN_1000_3dc0(uVar10);
  uVar10 = ((uVar5 & 0xff) * 0x280 + (uVar5 >> 8)) * 2 + 0x50e;
  uVar5 = (uint)unaff_DI & 0xff;
  puVar8 = (undefined1 *)register0x00000010;
  if ((char)unaff_DI < '\0') {
    uVar5 = *puVar9;
    FUN_1000_54fb(uVar5);
    pbVar1 = (byte *)((int)unaff_BP + uVar5 + 0xcaa);
    bVar12 = *pbVar1 < 0xf1;
    *pbVar1 = *pbVar1 + 0xf;
    puVar2 = &stack0x003e;
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
    in_stack_0000003e = in_FPUControlWord;
    goto code_r0x00018496;
  }
  puVar9 = puVar9 + 1;
  do {
    func_0x000167fa(puVar9);
    iRam0001c54c = iRam0001c54c + 1;
    bVar11 = 0xfaff < uVar10;
    uVar10 = uVar10 + 0x500;
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  while( true ) {
    puVar9 = (uint *)((int)unaff_SI + 1);
    *(char *)unaff_SI = (char)in_stack_00000000;
    puVar8[(int)unaff_BP] = puVar8[(int)unaff_BP] + (char)((uint)in_DX >> 8) + bVar11;
    *(char *)(unaff_BP + 0x1b) = (char)unaff_BP[0x1b] << 1;
    bVar4 = (byte)(in_stack_00000000 >> 8);
    if ((byte)in_CX == bVar4) break;
    in_AX = in_AX + 1;
    unaff_BP[-0x3ffb] = (unaff_BP[-0x3ffb] - (int)&stack0x0002) - (uint)((byte)in_CX < bVar4);
    pbVar1 = puVar8 + (int)puVar9 + 7;
    bVar4 = (byte)((uint)in_CX >> 8);
    bVar12 = CARRY1(*pbVar1,bVar4);
    *pbVar1 = *pbVar1 + bVar4;
    uVar13 = FUN_1000_7a7c();
    in_CX = (undefined2)((ulong)uVar13 >> 0x10);
    in_stack_00000000 = (uint)uVar13;
    if (!bVar12) goto FUN_1000_84d0;
    do {
      while( true ) {
        unaff_SI = puVar9 + 1;
        in_AX = in_AX + -1;
        if (in_AX == 0) goto code_r0x000184d9;
        puVar7 = (undefined1 *)*unaff_SI;
        in_CX = CONCAT11((char)((uint)in_CX >> 8),(char)puVar9[-0x16c0]);
        if ((char)puVar9[-0x16c0] != '\x05') break;
        puVar8 = puVar7;
        puVar9 = unaff_SI;
        if (puVar7 < in_DX) {
FUN_1000_84d0:
          unaff_BP = puVar9;
          in_DX = puVar8;
          puVar8 = in_DX;
          puVar9 = unaff_BP;
        }
      }
      puVar8 = puVar7 + 8;
      puVar9 = unaff_SI;
    } while (((undefined1 *)0xfff7 < puVar7) || (bVar12 = in_DX < puVar8, in_DX <= puVar8));
code_r0x00018496:
    bVar4 = (byte)in_CX + in_DX[(int)unaff_BP];
    bVar11 = CARRY1((byte)in_CX,in_DX[(int)unaff_BP]) || CARRY1(bVar4,bVar12);
    in_CX = CONCAT11((char)((uint)in_CX >> 8),bVar4 + bVar12);
    puVar3 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *puVar3 = in_stack_00000000;
  }
  *(undefined2 *)(puVar8 + (int)unaff_BP) = 0xa6e2;
code_r0x000184d9:
  puVar7 = in_DX + -8;
  if (in_DX < (undefined1 *)0x8) {
    puVar7 = (undefined1 *)0x0;
  }
  else if ((undefined1 *)0x1ef < puVar7) {
    puVar8[0x5d] = puVar8[0x5d] | (byte)puVar7;
    return;
  }
  puVar7[(uint)unaff_BP >> 1] =
       (puVar7[(uint)unaff_BP >> 1] - (char)in_AX) - (((uint)unaff_BP & 1) != 0);
  return;
}


