/* 1000:7157 */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_7157(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  code *pcVar4;
  char in_AL;
  undefined2 uVar5;
  int iVar6;
  int in_DX;
  int extraout_DX;
  undefined2 uVar7;
  byte *in_BX;
  uint uVar8;
  undefined2 *puVar9;
  int unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  byte *pbVar10;
  undefined2 *puVar11;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar12;
  undefined2 unaff_DS;
  char in_OF;
  unkbyte10 in_ST0;
  ulong uVar13;
  
  pcVar4 = (code *)swi(4);
  if (in_OF == '\x01') {
    in_AL = (*pcVar4)();
    in_DX = extraout_DX;
  }
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ (byte)in_BX;
  *(unkbyte10 *)(unaff_SI + unaff_BP + 0x60) = in_ST0;
  for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
    pbVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *pbVar2 = *pbVar1;
  }
  pbVar10 = unaff_DI + 0x43;
  if ((byte *)0xffbc < unaff_DI || in_DX == 1) {
    *(char *)0xb060 = *(char *)0xb060 + in_AL;
    unaff_SI = unaff_SI + (int)register0x00000010;
    for (iVar6 = 2000; iVar6 != 0; iVar6 = iVar6 + -1) {
      pbVar1 = pbVar10;
      pbVar10 = pbVar10 + 2;
      pbVar1[0] = 0;
      pbVar1[1] = 0;
    }
  }
  puVar11 = (undefined2 *)0x2000;
  uVar7 = 0x4aa;
  pbVar1 = in_BX;
  *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = 0x20;
  }
  uVar5 = 0xe1;
  uVar8 = (uint)&stack0x0000 & *(uint *)(in_BX + (int)unaff_SI + 8);
  *(undefined2 *)(uVar8 - 2) = 0x2000;
  *(undefined2 *)(uVar8 - 4) = 0;
  *(undefined2 *)(uVar8 - 6) = 0xe1;
  *(undefined2 *)(uVar8 - 8) = 0xe1;
  iVar6 = 0;
  do {
    pbVar10 = unaff_SI;
    unaff_SI = pbVar10 + -1;
    *unaff_SI = *unaff_SI & (byte)uVar5;
    uVar5 = *(undefined2 *)(uVar8 - 8);
    *(undefined2 *)(uVar8 - 8) = 0x2000;
    *unaff_SI = *unaff_SI - (char)((uint)uVar5 >> 8);
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & (byte)iVar6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar5 = *(undefined2 *)(uVar8 - 8);
  uVar12 = *(undefined2 *)(uVar8 - 6);
  iVar6 = *(int *)(uVar8 - 4);
  *(undefined2 *)(uVar8 - 4) = unaff_DS;
  pbVar1 = (byte *)(unaff_BP + iVar6 + -0x50);
  *pbVar1 = *pbVar1 ^ (byte)((uint)uVar12 >> 8);
  uVar12 = *(undefined2 *)(uVar8 - 4);
  pbVar1 = pbVar10 + -0x3fdf;
  *pbVar1 = *pbVar1 & 4;
  if (*pbVar1 != 0) {
    *(undefined2 *)(uVar8 - 4) = 0x4aa;
    puVar9 = (undefined2 *)(uVar8 - 6);
    *(undefined2 *)(uVar8 - 6) = 0x71d1;
    uVar13 = FUN_1000_71d9();
    uVar5 = CONCAT11((char)(uVar13 >> 0x18),
                     (char)((uint)((int)(uVar13 & 0xff00ff) * (int)((uVar13 & 0xff00ff) >> 0x10)) >>
                           8));
    uVar7 = *puVar9;
  }
  return CONCAT22(uVar7,uVar5);
}


