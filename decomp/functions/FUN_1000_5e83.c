/* 1000:5e83 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015eca) overlaps instruction at (ram,0x00015ec9)
    */

void FUN_1000_5e83(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  char in_CL;
  undefined2 *puVar6;
  undefined2 in_DX;
  int iVar7;
  byte extraout_DH;
  int in_BX;
  int iVar8;
  int unaff_BP;
  char *unaff_SI;
  undefined1 *puVar9;
  int unaff_DI;
  undefined2 *puVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte in_AF;
  int in_stack_00000000;
  
  *unaff_SI = *unaff_SI + in_CL + in_CF;
  do {
    bVar3 = in(in_DX);
  } while ((bVar3 & 0x80) != 0);
  uVar5 = in_stack_00000000 + 1U ^ 0x74;
  if ((unaff_SI[0x1d] != '\0') && ((*(byte *)0x538 & 2) == 0)) {
    iVar8 = 0x10;
    iVar7 = (int)((ulong)uVar5 * 0x10 >> 0x10);
    if (iVar7 != 0) {
      *(undefined1 *)(unaff_BP + unaff_DI) =
           (char)(CONCAT11(1,*(undefined1 *)(unaff_BP + unaff_DI)) >> 1);
    }
    out(iVar7,0x10);
    out(iVar7,0);
    cVar4 = FUN_1000_5ebc(uVar5,in_BX + uVar5);
    unaff_SI[iVar8 + -0x19fa] = unaff_SI[iVar8 + -0x19fa] | extraout_DH;
    out(0x37,(cVar4 - 0x18U) + (9 < (cVar4 - 0x18U & 0xf) | in_AF) * '\x06' & 0xf | 0x70);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar9 = (undefined1 *)0xd276;
  iVar7 = 8;
  out(0xa2,0x70);
  do {
    puVar1 = puVar9;
    puVar9 = puVar9 + 1;
    out(0xa0,*puVar1);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  func_0x0003bc3e();
  func_0x00015c60();
  puVar10 = (undefined2 *)0x0;
  for (puVar6 = (undefined2 *)&DAT_0000_3e80; puVar6 != (undefined2 *)0x0;
      puVar6 = (undefined2 *)((int)puVar6 + -1)) {
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    *puVar2 = 0xffff;
  }
  func_0x00017290();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


