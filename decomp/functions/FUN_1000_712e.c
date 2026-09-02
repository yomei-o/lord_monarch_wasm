/* 1000:712e */

/* WARNING: Instruction at (ram,0x00017140) overlaps instruction at (ram,0x0001713e)
    */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_712e(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 uVar9;
  byte *pbVar10;
  uint uVar11;
  undefined2 *puVar12;
  uint unaff_BP;
  byte *unaff_DI;
  byte *pbVar13;
  undefined2 *puVar14;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar15;
  undefined2 unaff_DS;
  char cVar16;
  unkbyte10 in_ST0;
  ulong uVar17;
  byte *in_stack_00000000;
  
  pbVar10 = (byte *)*(undefined2 *)(unaff_BP + 6);
  iVar6 = 0x50 - *(int *)(unaff_BP + 4);
  iVar8 = *(int *)(unaff_BP + 4);
  while( true ) {
    *(uint *)(unaff_BP + 0x14) = *(uint *)(unaff_BP + 0x14) | unaff_BP;
    *unaff_DI = *in_stack_00000000;
    while( true ) {
      in_stack_00000000 = in_stack_00000000 + 1;
      iVar8 = iVar8 + -1;
      if (iVar8 == 0) break;
      out(*in_stack_00000000,0x7e);
      iVar6 = CONCAT11((char)((uint)iVar6 >> 8),(byte)iVar6 + 0xad + (0xf6 < (byte)iVar6));
    }
    unaff_DI = unaff_DI + iVar6 + 1;
    pbVar10 = pbVar10 + -1;
    if (pbVar10 == (byte *)0x0) break;
    unaff_DI[unaff_BP + 0x44e] = unaff_DI[unaff_BP + 0x44e];
  }
  cVar16 = '\0';
  cVar5 = func_0x00014a1f();
  pcVar4 = (code *)swi(4);
  iVar8 = extraout_DX;
  if (cVar16 == '\x01') {
    cVar5 = (*pcVar4)();
    iVar8 = extraout_DX_00;
  }
  in_stack_00000000[unaff_BP] = in_stack_00000000[unaff_BP] ^ (byte)pbVar10;
  *(unkbyte10 *)(in_stack_00000000 + unaff_BP + 0x60) = in_ST0;
  for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
    pbVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    pbVar1 = in_stack_00000000;
    in_stack_00000000 = in_stack_00000000 + 1;
    *pbVar2 = *pbVar1;
  }
  pbVar13 = unaff_DI + 0x43;
  if ((byte *)0xffbc < unaff_DI || iVar8 == 1) {
    *(char *)0xb060 = *(char *)0xb060 + cVar5;
    in_stack_00000000 = in_stack_00000000 + (int)&stack0x0002;
    for (iVar8 = 2000; iVar8 != 0; iVar8 = iVar8 + -1) {
      pbVar1 = pbVar13;
      pbVar13 = pbVar13 + 2;
      pbVar1[0] = 0;
      pbVar1[1] = 0;
    }
  }
  puVar14 = (undefined2 *)0x2000;
  uVar9 = 0x4aa;
  pbVar1 = pbVar10;
  *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
    puVar3 = puVar14;
    puVar14 = puVar14 + 1;
    *puVar3 = 0x20;
  }
  uVar7 = 0xe1;
  uVar11 = (uint)&stack0x0002 & *(uint *)(pbVar10 + (int)in_stack_00000000 + 8);
  *(undefined2 *)(uVar11 - 2) = 0x2000;
  *(undefined2 *)(uVar11 - 4) = 0;
  *(undefined2 *)(uVar11 - 6) = 0xe1;
  *(undefined2 *)(uVar11 - 8) = 0xe1;
  iVar8 = 0;
  do {
    pbVar10 = in_stack_00000000;
    in_stack_00000000 = pbVar10 + -1;
    *in_stack_00000000 = *in_stack_00000000 & (byte)uVar7;
    uVar7 = *(undefined2 *)(uVar11 - 8);
    *(undefined2 *)(uVar11 - 8) = 0x2000;
    *in_stack_00000000 = *in_stack_00000000 - (char)((uint)uVar7 >> 8);
    in_stack_00000000[unaff_BP] = in_stack_00000000[unaff_BP] & (byte)iVar8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar7 = *(undefined2 *)(uVar11 - 8);
  uVar15 = *(undefined2 *)(uVar11 - 6);
  iVar8 = *(int *)(uVar11 - 4);
  *(undefined2 *)(uVar11 - 4) = unaff_DS;
  pbVar1 = (byte *)(unaff_BP + iVar8 + -0x50);
  *pbVar1 = *pbVar1 ^ (byte)((uint)uVar15 >> 8);
  uVar15 = *(undefined2 *)(uVar11 - 4);
  pbVar1 = pbVar10 + -0x3fdf;
  *pbVar1 = *pbVar1 & 4;
  if (*pbVar1 != 0) {
    *(undefined2 *)(uVar11 - 4) = 0x4aa;
    puVar12 = (undefined2 *)(uVar11 - 6);
    *(undefined2 *)(uVar11 - 6) = 0x71d1;
    uVar17 = FUN_1000_71d9();
    uVar7 = CONCAT11((char)(uVar17 >> 0x18),
                     (char)((uint)((int)(uVar17 & 0xff00ff) * (int)((uVar17 & 0xff00ff) >> 0x10)) >>
                           8));
    uVar9 = *puVar12;
  }
  return CONCAT22(uVar9,uVar7);
}


