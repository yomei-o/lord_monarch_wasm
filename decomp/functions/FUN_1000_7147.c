/* 1000:7147 */

/* WARNING: Instruction at (ram,0x00017143) overlaps instruction at (ram,0x00017140)
    */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_7147(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  code *pcVar4;
  char cVar5;
  int in_AX;
  undefined2 uVar6;
  int in_CX;
  int iVar7;
  int iVar8;
  undefined2 in_DX;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 uVar9;
  byte *in_BX;
  uint uVar10;
  undefined2 *puVar11;
  uint unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  byte *pbVar12;
  undefined2 *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar14;
  undefined2 unaff_DS;
  char cVar15;
  unkbyte10 in_ST0;
  ulong uVar16;
  
  while( true ) {
    *unaff_DI = *unaff_SI;
    while( true ) {
      unaff_SI = unaff_SI + 1;
      in_CX = in_CX + -1;
      if (in_CX == 0) break;
      out(*unaff_SI,in_DX);
      in_AX = CONCAT11((char)((uint)in_AX >> 8),(byte)in_AX + 0xad + (0xf6 < (byte)in_AX));
    }
    unaff_DI = unaff_DI + in_AX + 1;
    in_BX = in_BX + -1;
    if (in_BX == (byte *)0x0) break;
    unaff_DI[unaff_BP + 0x44e] = unaff_DI[unaff_BP + 0x44e];
    *(uint *)(unaff_BP + 0x14) = *(uint *)(unaff_BP + 0x14) | unaff_BP;
  }
  cVar15 = '\0';
  cVar5 = func_0x00014a1f();
  pcVar4 = (code *)swi(4);
  iVar8 = extraout_DX;
  if (cVar15 == '\x01') {
    cVar5 = (*pcVar4)();
    iVar8 = extraout_DX_00;
  }
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ (byte)in_BX;
  *(unkbyte10 *)(unaff_SI + unaff_BP + 0x60) = in_ST0;
  for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
    pbVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *pbVar2 = *pbVar1;
  }
  pbVar12 = unaff_DI + 0x43;
  if ((byte *)0xffbc < unaff_DI || iVar8 == 1) {
    *(char *)0xb060 = *(char *)0xb060 + cVar5;
    unaff_SI = unaff_SI + (int)&stack0x0002;
    for (iVar8 = 2000; iVar8 != 0; iVar8 = iVar8 + -1) {
      pbVar1 = pbVar12;
      pbVar12 = pbVar12 + 2;
      pbVar1[0] = 0;
      pbVar1[1] = 0;
    }
  }
  puVar13 = (undefined2 *)0x2000;
  uVar9 = 0x4aa;
  pbVar1 = in_BX;
  *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
    puVar3 = puVar13;
    puVar13 = puVar13 + 1;
    *puVar3 = 0x20;
  }
  uVar6 = 0xe1;
  uVar10 = (uint)&stack0x0002 & *(uint *)(in_BX + (int)unaff_SI + 8);
  *(undefined2 *)(uVar10 - 2) = 0x2000;
  *(undefined2 *)(uVar10 - 4) = 0;
  *(undefined2 *)(uVar10 - 6) = 0xe1;
  *(undefined2 *)(uVar10 - 8) = 0xe1;
  iVar8 = 0;
  do {
    pbVar12 = unaff_SI;
    unaff_SI = pbVar12 + -1;
    *unaff_SI = *unaff_SI & (byte)uVar6;
    uVar6 = *(undefined2 *)(uVar10 - 8);
    *(undefined2 *)(uVar10 - 8) = 0x2000;
    *unaff_SI = *unaff_SI - (char)((uint)uVar6 >> 8);
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & (byte)iVar8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar6 = *(undefined2 *)(uVar10 - 8);
  uVar14 = *(undefined2 *)(uVar10 - 6);
  iVar8 = *(int *)(uVar10 - 4);
  *(undefined2 *)(uVar10 - 4) = unaff_DS;
  pbVar1 = (byte *)(unaff_BP + iVar8 + -0x50);
  *pbVar1 = *pbVar1 ^ (byte)((uint)uVar14 >> 8);
  uVar14 = *(undefined2 *)(uVar10 - 4);
  pbVar1 = pbVar12 + -0x3fdf;
  *pbVar1 = *pbVar1 & 4;
  if (*pbVar1 != 0) {
    *(undefined2 *)(uVar10 - 4) = 0x4aa;
    puVar11 = (undefined2 *)(uVar10 - 6);
    *(undefined2 *)(uVar10 - 6) = 0x71d1;
    uVar16 = FUN_1000_71d9();
    uVar6 = CONCAT11((char)(uVar16 >> 0x18),
                     (char)((uint)((int)(uVar16 & 0xff00ff) * (int)((uVar16 & 0xff00ff) >> 0x10)) >>
                           8));
    uVar9 = *puVar11;
  }
  return CONCAT22(uVar9,uVar6);
}


