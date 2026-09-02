/* 1000:0d42 */

/* WARNING: Instruction at (ram,0x00010d21) overlaps instruction at (ram,0x00010d20)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

uint FUN_1000_0d42(void)

{
  uint *puVar1;
  char *pcVar2;
  uint uVar3;
  code *pcVar4;
  byte bVar5;
  int iVar6;
  undefined1 extraout_AH;
  int *in_AX;
  uint uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  int iVar10;
  int in_CX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 in_DX;
  undefined1 *in_BX;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int unaff_BP;
  int unaff_SI;
  int *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  byte bVar15;
  byte in_AF;
  char in_SF;
  char in_OF;
  undefined4 uVar16;
  
  while( true ) {
    iVar10 = in_CX;
    if (in_OF == in_SF) {
      pcVar4 = (code *)swi(3);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
    while( true ) {
      bVar15 = ((byte)in_AX | 0x75) + 0x20;
      iVar6 = CONCAT11((char)((uint)in_AX >> 8),bVar15);
      unaff_BP = unaff_BP + iVar6;
      *unaff_DI = *unaff_DI + -0x75;
      in_CX = CONCAT11((char)((uint)iVar10 >> 8),
                       (char)iVar10 + *(char *)(unaff_BP + unaff_SI + 0x4307));
      if (bVar15 < 0xf0) break;
      FUN_1000_0ffc();
      in_AX = (int *)CONCAT11(extraout_AH,*in_BX);
      in_BX = in_BX + 1;
      iVar10 = in_CX;
      in_DX = extraout_DX;
    }
    puVar1 = (uint *)0x8820;
    uVar7 = *puVar1;
    uVar3 = *puVar1;
    *puVar1 = uVar3 + 5;
    if (0xfffb < uVar7 || 0xfffe < uVar3 + 4) break;
    func_0x000112b0();
    uVar9 = *in_BX;
    in_OF = SCARRY2((int)in_BX,1);
    in_BX = in_BX + 1;
    in_SF = (int)in_BX < 0;
    *(undefined2 *)(unaff_SI + 2) = in_BX;
    in_AX = unaff_DI;
    in_DX = extraout_DX_00;
    unaff_DI = (int *)CONCAT11(*(undefined1 *)(unaff_SI + 10),uVar9);
  }
  uVar7 = (uint)(byte)((byte)(iVar6 + 0x44c6) | in_BX[unaff_SI]);
  *(undefined2 *)(unaff_SI + 2) = in_BX;
  if ((*(byte *)(unaff_SI + 0x1f) & 1) == 0) {
    *(byte *)(unaff_SI + 1) = *(byte *)(unaff_SI + 1) | (byte)((uint)in_DX >> 8);
  }
  else {
    puVar11 = (undefined1 *)(iVar10 + -1);
    *(undefined2 *)(iVar10 + -1) = 0xd70;
    uVar8 = FUN_1000_13a2();
    *(undefined2 *)(unaff_SI + 0x1a) = uVar8;
    puVar12 = puVar11 + -2;
    *(undefined2 *)(puVar11 + -2) = 0xd7d;
    FUN_1000_7297();
    puVar13 = puVar12 + -2;
    *(undefined2 *)(puVar12 + -2) = 0xd89;
    uVar7 = FUN_1000_0f08();
    bVar15 = 0;
    if ((*(byte *)(unaff_SI + 0x1f) & 8) == 0) {
      pcVar2 = (char *)(unaff_SI + 0x16);
      *pcVar2 = *pcVar2 + -1;
      if (*pcVar2 != '\0') {
        return uVar7;
      }
      puVar14 = puVar13 + -2;
      *(undefined2 *)(puVar13 + -2) = 0xd99;
      uVar16 = thunk_FUN_0000_70d2();
      bVar5 = (byte)uVar16;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      uVar9 = (undefined1)((ulong)uVar16 >> 8);
      bVar15 = bVar5 + in_AF * '\x06' + (0x99 < bVar5 | bVar15) * '`';
      *(uint *)(puVar14 + -2) = CONCAT11(uVar9,bVar15);
      bVar5 = bVar15 - 0xd;
      bVar15 = bVar5 + (9 < (bVar5 & 0xf) | in_AF) * '\x06' + (0x99 < bVar5 || 0xc < bVar15) * '`';
      uVar7 = CONCAT11(uVar9,bVar15);
      *(uint *)(puVar14 + -4) = uVar7;
      pcVar2 = (char *)(unaff_SI + 0x19);
      *pcVar2 = *pcVar2 + -1;
      if (*pcVar2 == '\0') {
        out((int)((ulong)uVar16 >> 0x10),CONCAT11(bVar15 / 10,bVar15 % 10));
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      return uVar7;
    }
  }
  return uVar7;
}


