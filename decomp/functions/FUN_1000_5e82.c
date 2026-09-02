/* 1000:5e82 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015eca) overlaps instruction at (ram,0x00015ec9)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_5e82(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  byte bVar3;
  uint uVar4;
  char in_CL;
  undefined2 *puVar5;
  undefined2 in_DX;
  int iVar6;
  byte extraout_DH;
  int in_BX;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined1 *puVar10;
  int unaff_BP;
  char *unaff_SI;
  undefined1 *puVar11;
  int unaff_DI;
  undefined2 *puVar12;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte in_AF;
  int *in_stack_00000000;
  
  *unaff_SI = *unaff_SI + in_CL + in_CF;
  do {
    bVar3 = in(in_DX);
  } while ((bVar3 & 0x80) != 0);
  iVar6 = *in_stack_00000000;
  *in_stack_00000000 = unaff_BP;
  uVar4 = iVar6 + 1U ^ 0x74;
  if ((unaff_SI[0x1d] != '\0') && ((*(byte *)0x538 & 2) == 0)) {
    in_stack_00000000[-1] = in_DX;
    in_stack_00000000[-2] = in_BX + uVar4;
    in_stack_00000000[-3] = uVar4;
    iVar7 = 0x10;
    iVar6 = (int)((ulong)uVar4 * 0x10 >> 0x10);
    if (iVar6 != 0) {
      *(undefined1 *)(unaff_BP + unaff_DI) =
           (char)(CONCAT11(1,*(undefined1 *)(unaff_BP + unaff_DI)) >> 1);
    }
    out(iVar6,0x10);
    out(iVar6,0);
    piVar8 = in_stack_00000000 + -4;
    in_stack_00000000[-4] = 0x5eb8;
    iVar6 = FUN_1000_5ebc();
    *(int *)((int)piVar8 + -2) = iVar6 + -0x3418;
    unaff_SI[iVar7 + -0x19fa] = unaff_SI[iVar7 + -0x19fa] | extraout_DH;
    bVar3 = (byte)(iVar6 + -0x3418);
    out(0x37,bVar3 + (9 < (bVar3 & 0xf) | in_AF) * '\x06' & 0xf | 0x70);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in_stack_00000000[-1] = unaff_DS;
  puVar11 = (undefined1 *)0xd276;
  iVar6 = 8;
  out(0xa2,0x70);
  do {
    puVar1 = puVar11;
    puVar11 = puVar11 + 1;
    out(0xa0,*puVar1);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  in_stack_00000000[-2] = unaff_CS;
  piVar9 = in_stack_00000000 + -3;
  in_stack_00000000[-3] = 0x5ee0;
  func_0x0003bc3e();
  puVar10 = (undefined1 *)((int)piVar9 + -2);
  *(undefined2 *)((int)piVar9 + -2) = 0x5ee6;
  func_0x00015c60();
  puVar12 = (undefined2 *)0x0;
  for (puVar5 = (undefined2 *)&DAT_0000_3e80; puVar5 != (undefined2 *)0x0;
      puVar5 = (undefined2 *)((int)puVar5 + -1)) {
    puVar2 = puVar12;
    puVar12 = puVar12 + 1;
    *puVar2 = 0xffff;
  }
  *(undefined2 *)(puVar10 + -2) = 0x5ef9;
  func_0x00017290();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


