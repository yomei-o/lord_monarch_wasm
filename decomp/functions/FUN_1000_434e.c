/* 1000:434e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014392) overlaps instruction at (ram,0x00014390)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_434e(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  undefined2 in_AX;
  uint uVar6;
  int iVar7;
  byte bVar8;
  undefined2 uVar9;
  int iVar10;
  undefined2 in_DX;
  int extraout_DX;
  int in_BX;
  int iVar11;
  byte bVar12;
  undefined2 *puVar13;
  undefined2 *puVar15;
  undefined1 *puVar16;
  undefined2 unaff_BP;
  double *unaff_SI;
  double *pdVar17;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar18;
  char cVar19;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 in_FPUTagWord;
  undefined2 in_FPULastInstructionOpcode;
  undefined4 in_FPUDataPointer;
  undefined4 uVar20;
  longdouble in_ST0;
  longdouble in_ST1;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  unkbyte10 in_ST6;
  unkbyte10 in_ST7;
  unkbyte10 Var21;
  undefined2 *puVar14;
  
  puVar5 = (undefined2 *)*(undefined2 *)(in_BX + (int)unaff_DI);
  iVar11 = CONCAT11((char)((uint)in_BX >> 8),
                    (byte)in_BX | *(byte *)((int)unaff_DI + in_BX + -0x1701));
  uVar20 = 0x1435d;
  Var21 = to_bcd(in_ST0 / (longdouble)*unaff_SI);
  *(unkbyte10 *)((int)unaff_DI + 0x6d) = Var21;
  puVar13 = puVar5 + -1;
  puVar5[-1] = unaff_BP;
  iVar10 = 0xae4;
  uVar6 = (CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + -0x2b) ^ 0x6f) & 0x40a8;
  Var21 = in_ST7;
  if (uVar6 != 0) {
    uVar6 = uVar6 | 10;
    cVar19 = 0x6dcb < uVar6;
    iVar7 = uVar6 + 0x9234;
    goto code_r0x0001439a;
  }
  uVar6 = in(in_DX);
  *unaff_DI = uVar6;
  pdVar17 = (double *)*puVar5;
  iVar11 = puVar5[3];
  uVar9 = puVar5[5];
  uVar6 = puVar5[6];
  pbVar1 = (byte *)(puVar5[1] + (int)pdVar17);
  bVar8 = (byte)uVar9;
  bVar18 = CARRY1(bVar8,*pbVar1);
  bVar12 = *pbVar1;
  puVar3 = (undefined2 *)puVar5[-1] + 1;
  uVar4 = in(puVar5[4]);
  *(undefined2 *)puVar5[-1] = uVar4;
  puVar13 = puVar5 + 6;
  puVar5[6] = CONCAT11((char)((uint)uVar9 >> 8),bVar8 + bVar12);
  while( true ) {
    puVar2 = puVar3;
    puVar3 = (undefined2 *)((int)puVar3 + 1);
    unaff_SI = (double *)((int)pdVar17 + 1);
    *(undefined1 *)puVar2 = *(undefined1 *)pdVar17;
    uVar20 = 0x14374;
    in_ST1 = in_ST1 - (longdouble)*(float *)((int)pdVar17 + 0x624);
    uVar6 = uVar6 + *(int *)0x7302 + (uint)bVar18 & 0xcdeb;
    if (uVar6 == 0) break;
    bVar18 = false;
    pdVar17 = unaff_SI;
  }
  cVar19 = (byte)((uint)iVar11 >> 8) < (*(byte *)0xe805 & 0xd);
  unaff_DI = (uint *)0xa11;
  iVar10 = 3;
  while( true ) {
    puVar14 = (undefined2 *)((int)puVar13 + -2);
    puVar13 = (undefined2 *)((int)puVar13 + -2);
    *puVar14 = 0x4399;
    FUN_1000_779e();
    iVar7 = extraout_DX;
code_r0x0001439a:
    uVar6 = *unaff_DI;
    bVar18 = unaff_DI < (uint *)0xf604;
    unaff_DI = unaff_DI + 0x4fe;
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) break;
    pbVar1 = (byte *)((int)unaff_SI + iVar11 + 0x8b0);
    bVar12 = (byte)((uint)iVar11 >> 8);
    cVar19 = CARRY1(*pbVar1,bVar12);
    *pbVar1 = *pbVar1 + bVar12;
  }
  *(undefined2 *)0xab92 = 0xaeaa;
  if (unaff_DI != (uint *)0x0) {
    if (bVar18) {
      unaff_DI = (uint *)((CONCAT11((char)((uint)iVar7 >> 8),((char)iVar7 + '\x04') - cVar19) ^
                          uVar6) * 0xa0 + 0xa0f ^ 10);
      *(undefined2 *)0x3292 = unaff_DI;
      puVar15 = (undefined2 *)((int)puVar13 + -2);
      puVar13 = (undefined2 *)((int)puVar13 + -2);
      *puVar15 = unaff_DI;
    }
    bVar18 = false;
    puVar16 = (undefined1 *)((int)puVar13 + -2);
    *(undefined2 *)((int)puVar13 + -2) = 0x43cf;
    FUN_1000_462f();
    *(uint **)(puVar16 + -2) = unaff_DI;
    if (!bVar18) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined2 *)0xdd94 = 0xddf0;
  puVar2 = (undefined2 *)(iVar11 + ((uint)unaff_SI ^ *(uint *)unaff_SI));
  *puVar2 = in_FPUControlWord;
  puVar2[2] = in_FPUStatusWord;
  puVar2[4] = in_FPUTagWord;
  *(undefined4 *)(puVar2 + 10) = in_FPUDataPointer;
  *(undefined4 *)(puVar2 + 6) = uVar20;
  puVar2[9] = in_FPULastInstructionOpcode;
  *(longdouble *)(puVar2 + 0xe) = in_ST1;
  *(unkbyte10 *)(puVar2 + 0x13) = in_ST2;
  *(unkbyte10 *)(puVar2 + 0x18) = in_ST3;
  *(unkbyte10 *)(puVar2 + 0x1d) = in_ST4;
  *(unkbyte10 *)(puVar2 + 0x22) = in_ST5;
  *(unkbyte10 *)(puVar2 + 0x27) = in_ST6;
  *(unkbyte10 *)(puVar2 + 0x2c) = in_ST7;
  *(unkbyte10 *)(puVar2 + 0x31) = Var21;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


