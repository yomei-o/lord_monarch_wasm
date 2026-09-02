/* 1000:5936 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_5936(char *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  byte bVar7;
  int in_AX;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  undefined2 uVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined1 *puVar14;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *puVar15;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar16;
  int in_stack_00000000;
  
  uVar13 = (uint)&stack0x0004 ^ *(uint *)(unaff_SI + in_stack_00000000 + -0x17f6);
  uVar8 = in_AX + 0x58e5U ^ *(uint *)(unaff_SI + in_stack_00000000);
  uVar11 = CONCAT11((char)((uint)in_stack_00000000 >> 8),(char)in_stack_00000000 - *param_1);
  cVar6 = (char)uVar8 + '\x1c';
  uVar9 = CONCAT11((char)(uVar8 >> 8),cVar6);
  puVar14 = (undefined1 *)(uVar13 - 2);
  *(undefined2 *)(uVar13 - 2) = uVar9;
  if (cVar6 < '\0') {
    *(int *)(uVar13 - 4) = unaff_BP;
    bVar16 = false;
    uVar11 = *(undefined2 *)(uVar13 - 4);
    puVar14 = (undefined1 *)(uVar13 - 4);
                    /* WARNING: Call to offcut address within same function */
    *(undefined2 *)(uVar13 - 4) = 0x5955;
    uVar9 = func_0x00015974();
    if (bVar16) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_BP = unaff_BP + 1;
    *unaff_SI = *unaff_SI & (byte)uVar9;
  }
  pbVar2 = (byte *)(param_1 + -0x10);
  bVar3 = *pbVar2;
  bVar7 = (byte)uVar9;
  *pbVar2 = *pbVar2 + bVar7;
  *unaff_SI = *unaff_SI + bVar7 + CARRY1(bVar3,bVar7);
  *(byte **)(puVar14 + -2) = unaff_SI;
  *(undefined2 *)(puVar14 + -4) = uVar11;
  *(byte **)(puVar14 + -6) = unaff_SI;
  puVar12 = puVar14 + -8;
  *(undefined2 *)(puVar14 + -8) = 0x58f8;
  cVar6 = FUN_1000_5ab6();
  *param_1 = cVar6;
  *(int *)(puVar12 + -2) = unaff_BP;
  puVar15 = *(undefined1 **)(puVar12 + -2);
  puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
  pcVar1 = puVar5 + *(int *)(puVar12 + 6);
  *pcVar1 = *pcVar1 + (char)((uint)*(undefined2 *)(puVar12 + 0xc) >> 8);
  puVar4 = puVar15 + 1;
  *puVar15 = *puVar5;
  *puVar4 = 0x20;
  for (iVar10 = 10; puVar4 = puVar4 + 1, iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar4 = 0;
  }
  return CONCAT22(*(undefined2 *)(puVar12 + 0x1a),*(undefined2 *)(puVar12 + 0x1e));
}


