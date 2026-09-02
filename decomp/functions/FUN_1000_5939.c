/* 1000:5939 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_5939(char *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  byte bVar7;
  uint in_AX;
  undefined2 uVar8;
  int iVar9;
  undefined2 uVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined1 *puVar13;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *puVar14;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar15;
  int in_stack_00000000;
  
  uVar12 = (uint)&stack0x0004 ^ *(uint *)(unaff_SI + in_stack_00000000 + -0x17f6);
  uVar10 = CONCAT11((char)((uint)in_stack_00000000 >> 8),(char)in_stack_00000000 - *param_1);
  cVar6 = (char)(in_AX ^ *(uint *)(unaff_SI + in_stack_00000000)) + '\x1c';
  uVar8 = CONCAT11((char)((in_AX ^ *(uint *)(unaff_SI + in_stack_00000000)) >> 8),cVar6);
  puVar13 = (undefined1 *)(uVar12 - 2);
  *(undefined2 *)(uVar12 - 2) = uVar8;
  if (cVar6 < '\0') {
    *(int *)(uVar12 - 4) = unaff_BP;
    bVar15 = false;
    uVar10 = *(undefined2 *)(uVar12 - 4);
    puVar13 = (undefined1 *)(uVar12 - 4);
                    /* WARNING: Call to offcut address within same function */
    *(undefined2 *)(uVar12 - 4) = 0x5955;
    uVar8 = func_0x00015974();
    if (bVar15) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_BP = unaff_BP + 1;
    *unaff_SI = *unaff_SI & (byte)uVar8;
  }
  pbVar2 = (byte *)(param_1 + -0x10);
  bVar3 = *pbVar2;
  bVar7 = (byte)uVar8;
  *pbVar2 = *pbVar2 + bVar7;
  *unaff_SI = *unaff_SI + bVar7 + CARRY1(bVar3,bVar7);
  *(byte **)(puVar13 + -2) = unaff_SI;
  *(undefined2 *)(puVar13 + -4) = uVar10;
  *(byte **)(puVar13 + -6) = unaff_SI;
  puVar11 = puVar13 + -8;
  *(undefined2 *)(puVar13 + -8) = 0x58f8;
  cVar6 = FUN_1000_5ab6();
  *param_1 = cVar6;
  *(int *)(puVar11 + -2) = unaff_BP;
  puVar14 = *(undefined1 **)(puVar11 + -2);
  puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
  pcVar1 = puVar5 + *(int *)(puVar11 + 6);
  *pcVar1 = *pcVar1 + (char)((uint)*(undefined2 *)(puVar11 + 0xc) >> 8);
  puVar4 = puVar14 + 1;
  *puVar14 = *puVar5;
  *puVar4 = 0x20;
  for (iVar9 = 10; puVar4 = puVar4 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar4 = 0;
  }
  return CONCAT22(*(undefined2 *)(puVar11 + 0x1a),*(undefined2 *)(puVar11 + 0x1e));
}


