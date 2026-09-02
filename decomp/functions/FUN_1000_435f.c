/* 1000:435f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014392) overlaps instruction at (ram,0x00014390)
    */

void FUN_1000_435f(int param_1,undefined2 param_2,int param_3,undefined2 param_4,byte param_5,
                  uint param_6)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  uint in_AX;
  uint uVar5;
  int iVar6;
  char in_CL;
  int iVar7;
  undefined2 in_DX;
  int extraout_DX;
  int in_BX;
  byte bVar8;
  undefined2 *unaff_BP;
  uint *unaff_SI;
  undefined2 *unaff_DI;
  uint *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  char cVar11;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 in_FPUTagWord;
  undefined2 in_FPULastInstructionOpcode;
  undefined4 in_FPUDataPointer;
  undefined4 in_FPUInstructionPointer;
  longdouble in_ST0;
  unkbyte10 in_ST1;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  unkbyte10 in_ST6;
  unkbyte10 in_ST7;
  uint *in_stack_00000000;
  
  puVar9 = unaff_DI + 1;
  uVar4 = in(in_DX);
  *unaff_DI = uVar4;
  iVar7 = CONCAT11(10,in_CL + '\x01');
  if ((in_AX & 0x40a8) != 0) {
    uVar5 = in_AX & 0x40a8 | 10;
    cVar11 = 0x6dcb < uVar5;
    iVar6 = uVar5 + 0x9234;
    goto code_r0x0001439a;
  }
  uVar5 = in(in_DX);
  *puVar9 = uVar5;
  bVar10 = CARRY1(param_5,*(byte *)(param_1 + (int)in_stack_00000000));
  puVar3 = unaff_BP + 1;
  uVar4 = in(param_4);
  *unaff_BP = uVar4;
  while( true ) {
    puVar2 = puVar3;
    puVar3 = (undefined2 *)((int)puVar3 + 1);
    unaff_SI = (uint *)((int)in_stack_00000000 + 1);
    *(char *)puVar2 = (char)*in_stack_00000000;
    in_FPUInstructionPointer = 0x14374;
    in_ST0 = in_ST0 - (longdouble)*(float *)(in_stack_00000000 + 0x312);
    param_6 = param_6 + *(int *)0x7302 + (uint)bVar10 & 0xcdeb;
    if (param_6 == 0) break;
    bVar10 = false;
    in_stack_00000000 = unaff_SI;
  }
  cVar11 = (byte)((uint)param_3 >> 8) < (*(byte *)0xe805 & 0xd);
  puVar9 = (uint *)0xa11;
  iVar7 = 3;
  in_BX = param_3;
  while( true ) {
    FUN_1000_779e();
    iVar6 = extraout_DX;
code_r0x0001439a:
    uVar5 = *puVar9;
    bVar10 = puVar9 < (uint *)0xf604;
    puVar9 = puVar9 + 0x4fe;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) break;
    pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x8b0);
    bVar8 = (byte)((uint)in_BX >> 8);
    cVar11 = CARRY1(*pbVar1,bVar8);
    *pbVar1 = *pbVar1 + bVar8;
  }
  *(undefined2 *)0xab92 = 0xaeaa;
  if (puVar9 != (uint *)0x0) {
    if (bVar10) {
      *(uint *)0x3292 =
           (CONCAT11((char)((uint)iVar6 >> 8),((char)iVar6 + '\x04') - cVar11) ^ uVar5) * 0xa0 +
           0xa0f ^ 10;
    }
    bVar10 = false;
    FUN_1000_462f();
    if (!bVar10) {
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
  *(longdouble *)(puVar2 + 0xe) = in_ST0;
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


