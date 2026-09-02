/* 1000:5e88 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015eca) overlaps instruction at (ram,0x00015ec9)
    */

void FUN_1000_5e88(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 in_DX;
  int iVar8;
  byte extraout_DH;
  int in_BX;
  int iVar9;
  int unaff_BP;
  int unaff_SI;
  undefined1 *puVar10;
  int unaff_DI;
  undefined2 *puVar11;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  byte in_AF;
  int in_stack_00000000;
  
  while ((bool)in_CF) {
    bVar4 = in(in_DX);
    in_CF = (bVar4 & 0x80) != 0;
  }
  uVar6 = in_stack_00000000 + 1U ^ 0x74;
  if ((*(char *)(unaff_SI + 0x1d) != '\0') && ((*(byte *)0x538 & 2) == 0)) {
    iVar9 = 0x10;
    iVar8 = (int)((ulong)uVar6 * 0x10 >> 0x10);
    if (iVar8 != 0) {
      *(undefined1 *)(unaff_BP + unaff_DI) =
           (char)(CONCAT11(1,*(undefined1 *)(unaff_BP + unaff_DI)) >> 1);
    }
    out(iVar8,0x10);
    out(iVar8,0);
    cVar5 = FUN_1000_5ebc(uVar6,in_BX + uVar6);
    pbVar1 = (byte *)(iVar9 + unaff_SI + -0x19fa);
    *pbVar1 = *pbVar1 | extraout_DH;
    out(0x37,(cVar5 - 0x18U) + (9 < (cVar5 - 0x18U & 0xf) | in_AF) * '\x06' & 0xf | 0x70);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar10 = (undefined1 *)0xd276;
  iVar8 = 8;
  out(0xa2,0x70);
  do {
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    out(0xa0,*puVar2);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  func_0x0003bc3e();
  func_0x00015c60();
  puVar11 = (undefined2 *)0x0;
  for (puVar7 = (undefined2 *)&DAT_0000_3e80; puVar7 != (undefined2 *)0x0;
      puVar7 = (undefined2 *)((int)puVar7 + -1)) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = 0xffff;
  }
  func_0x00017290();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


