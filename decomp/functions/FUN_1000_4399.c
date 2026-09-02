/* 1000:4399 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_4399(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint uVar3;
  int in_CX;
  undefined2 extraout_DX;
  undefined2 in_DX;
  byte bVar4;
  int in_BX;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar5;
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
  
  while( true ) {
    uVar3 = *unaff_DI;
    bVar5 = unaff_DI < (uint *)0xf604;
    unaff_DI = unaff_DI + 0x4fe;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x8b0);
    bVar4 = (byte)((uint)in_BX >> 8);
    in_CF = CARRY1(*pbVar1,bVar4);
    *pbVar1 = *pbVar1 + bVar4;
    FUN_1000_779e();
    in_DX = extraout_DX;
  }
  *(undefined2 *)0xab92 = 0xaeaa;
  if (unaff_DI != (uint *)0x0) {
    if (bVar5) {
      *(uint *)0x3292 =
           (CONCAT11((char)((uint)in_DX >> 8),((char)in_DX + '\x04') - in_CF) ^ uVar3) * 0xa0 +
           0xa0f ^ 10;
    }
    bVar5 = false;
    FUN_1000_462f();
    if (!bVar5) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined2 *)0xdd94 = 0xddf0;
  puVar2 = (undefined2 *)(in_BX + ((uint)unaff_SI ^ *unaff_SI));
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
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


