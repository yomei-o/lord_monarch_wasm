/* 1000:58dc */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_58dc(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 in_BL;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int unaff_BP;
  int unaff_SI;
  undefined1 *unaff_DI;
  undefined1 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar6 = (uint)&stack0x0000 | *(uint *)(CONCAT11(*(undefined1 *)0x4589,in_BL) + unaff_SI);
  puVar7 = (undefined1 *)(uVar6 - 2);
  *(undefined2 *)(uVar6 - 2) = 0x58ed;
  FUN_1000_5a6c();
  *(undefined2 *)(unaff_DI + 0x1c) = 0;
  *(undefined2 *)(unaff_DI + 0x1e) = 0;
  puVar8 = puVar7 + -2;
  *(undefined2 *)(puVar7 + -2) = 0x58f8;
  uVar4 = FUN_1000_5ab6();
  *unaff_DI = uVar4;
  *(int *)(puVar8 + -2) = unaff_BP + 1;
  puVar9 = *(undefined1 **)(puVar8 + -2);
  puVar3 = (undefined1 *)*(undefined2 *)0x3e8c;
  pcVar1 = puVar3 + *(int *)(puVar8 + 6);
  *pcVar1 = *pcVar1 + (char)((uint)*(undefined2 *)(puVar8 + 0xc) >> 8);
  puVar2 = puVar9 + 1;
  *puVar9 = *puVar3;
  *puVar2 = 0x20;
  for (iVar5 = 10; puVar2 = puVar2 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
  }
  return CONCAT22(*(undefined2 *)(puVar8 + 0x1a),*(undefined2 *)(puVar8 + 0x1e));
}


