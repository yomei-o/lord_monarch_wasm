/* 1000:9f38 */

/* WARNING: Instruction at (ram,0x00019f4d) overlaps instruction at (ram,0x00019f4c)
    */
/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_9f38(void)

{
  byte *pbVar1;
  uint *puVar2;
  undefined2 *puVar3;
  undefined1 uVar4;
  undefined2 in_AX;
  int iVar5;
  uint uVar6;
  byte in_CL;
  byte bVar7;
  char extraout_DL;
  undefined2 in_DX;
  int iVar8;
  int extraout_DX;
  undefined2 extraout_DX_00;
  byte bVar9;
  int iVar10;
  undefined2 uVar11;
  int iVar12;
  int unaff_DI;
  uint *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
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
  
  iVar8 = (uint)(byte)((byte)((uint)in_DX >> 8) | (byte)in_DX) << 8;
  iVar10 = -0x2618;
  iVar12 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + -0x11);
  do {
    puVar13 = (uint *)(unaff_DI + 1);
    bVar7 = in_CL & *(byte *)(CONCAT11((char)((uint)iVar10 >> 8),(byte)iVar10 | in_CL) + -0x6f23);
    iVar5 = CONCAT11((char)((uint)iVar12 >> 8),(char)iVar12 + -0x2c);
    puVar2 = puVar13;
    uVar6 = *puVar2;
    *puVar2 = *puVar2 + 0x1745;
    pbVar1 = (byte *)((int)puVar13 + iVar5 + -0x4143);
    bVar9 = -*pbVar1 - 0x18;
    iVar10 = CONCAT11(bVar9 - (uVar6 < 0xe8bb),0xbb);
    *(char *)(iVar10 + (int)puVar13) =
         (*(char *)(iVar10 + (int)puVar13) - (char)((uint)iVar8 >> 8)) -
         (0xe8 < *pbVar1 || bVar9 < (uVar6 < 0xe8bb));
    FUN_1000_3b5a(&stack0x0000);
    thunk_EXT_FUN_d000_751b();
    iVar12 = iVar5 + 1;
    *(uint *)(iVar10 + 0x5a24) = *(uint *)(iVar10 + 0x5a24) ^ 0x5024;
    FUN_1000_3b5a();
    unaff_DI = FUN_1000_1302();
    *(byte *)(iVar5 + 0x11ea) = *(byte *)(iVar5 + 0x11ea) & (byte)unaff_DI;
    (*(code *)*(undefined2 *)(iVar10 + unaff_DI))();
    pbVar1 = (byte *)(iVar12 + unaff_DI + -0x416b);
    *pbVar1 = *pbVar1 | bVar7;
    in(0xd0);
    in_CL = bVar7 & *(byte *)0x11e9;
    iVar8 = extraout_DX;
  } while ((POPCOUNT(in_CL) & 1U) != 0);
  func_0x0001dd23();
  pbVar1 = (byte *)(iVar5 + 0x11ea);
  *pbVar1 = *pbVar1 & (byte)iVar10;
  if ('\0' < (char)*pbVar1) {
    func_0x00013b53();
    FUN_1000_5cfb();
    iVar8 = CONCAT11((char)((uint)iVar10 >> 8),(byte)iVar10 & *(byte *)(iVar5 + 0x315b));
    uVar4 = in(extraout_DX_00);
    *(undefined1 *)0x230c = uVar4;
    *(uint *)(iVar8 + 0x2d0c) = *(uint *)(iVar8 + 0x2d0c) ^ 0x230d;
    func_0x00013b51();
    uVar6 = FUN_1000_4ff9();
    *(byte *)0xad18 = *(byte *)0xad18 & (byte)uVar6;
    uVar6 = uVar6 & *(uint *)(uVar6 + 0x1097);
    bVar9 = (char)iVar8 + *(char *)(uVar6 + 0xe67);
    pbVar1 = (byte *)(uVar6 + 0xded);
    *pbVar1 = *pbVar1 & bVar9;
    puVar2 = (uint *)(CONCAT11((char)((uint)iVar8 >> 8),bVar9) + 0x2808);
    *puVar2 = *puVar2 ^ 0x230d;
    func_0x00013b4b();
    func_0x000199f3();
    *(uint *)0xd7bc = *(uint *)0xd7bc ^ 0x230d;
    *(uint *)0xd7bc = *(uint *)0xd7bc ^ 0x230d;
    func_0x0001feed();
    FUN_1000_8844();
    FUN_1000_8903();
    FUN_1000_3716();
    FUN_1000_3511();
    FUN_1000_34f7();
    return;
  }
  uVar11 = 0xbee8;
  in(0xb0);
  FUN_1000_5a02();
  func_0x00018871();
  func_0x0001b563();
  iVar8 = CONCAT11((char)((uint)uVar11 >> 8) + *(char *)(iVar5 + 0x4501),(char)uVar11);
  *(byte *)(iVar8 + 0x11e9) = *(byte *)(iVar8 + 0x11e9) & in_CL;
  puVar3 = (undefined2 *)(iVar8 + -0x3618);
  *puVar3 = in_FPUControlWord;
  puVar3[2] = in_FPUStatusWord;
  puVar3[4] = in_FPUTagWord;
  *(undefined4 *)(puVar3 + 10) = in_FPUDataPointer;
  *(undefined4 *)(puVar3 + 6) = in_FPUInstructionPointer;
  puVar3[9] = in_FPULastInstructionOpcode;
  *(unkbyte10 *)(puVar3 + 0xe) = in_ST0;
  *(unkbyte10 *)(puVar3 + 0x13) = in_ST1;
  *(unkbyte10 *)(puVar3 + 0x18) = in_ST2;
  *(unkbyte10 *)(puVar3 + 0x1d) = in_ST3;
  *(unkbyte10 *)(puVar3 + 0x22) = in_ST4;
  *(unkbyte10 *)(puVar3 + 0x27) = in_ST5;
  *(unkbyte10 *)(puVar3 + 0x2c) = in_ST6;
  *(unkbyte10 *)(puVar3 + 0x31) = in_ST7;
  *(char *)(iVar8 + 0x11e9) = *(char *)(iVar8 + 0x11e9) - extraout_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


