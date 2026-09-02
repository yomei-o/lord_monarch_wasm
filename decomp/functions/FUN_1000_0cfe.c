/* 1000:0cfe */

/* WARNING: Instruction at (ram,0x00010d21) overlaps instruction at (ram,0x00010d20)
    */
/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_0cfe(undefined4 param_1)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 uVar5;
  code *pcVar6;
  byte bVar7;
  uint in_AX;
  undefined1 extraout_AH;
  undefined2 uVar8;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  undefined1 *in_BX;
  int unaff_BP;
  byte *unaff_SI;
  int *unaff_DI;
  undefined2 unaff_SS;
  undefined2 in_FS;
  char cVar9;
  byte bVar10;
  byte in_AF;
  bool bVar11;
  undefined4 uVar12;
  undefined2 in_stack_00000000;
  undefined2 uStack0002;
  undefined2 uStack0004;
  uint uVar4;
  
  unaff_SI[1] = unaff_SI[1] ^ 0xc3;
  cVar9 = '\0';
  if ((unaff_SI[10] & 1) == 0) {
    bVar10 = *unaff_SI;
    in_AX = CONCAT11((char)(in_AX >> 8),bVar10);
    cVar9 = bVar10 < unaff_SI[9];
    if (bVar10 == unaff_SI[9]) {
      uVar12 = FUN_1000_12a3();
      in_DX = (undefined2)((ulong)uVar12 >> 0x10);
      in_AX = (uint)uVar12;
    }
  }
  bVar10 = (byte)((uint)in_DX >> 8);
  pbVar1 = unaff_SI;
  *pbVar1 = *pbVar1 - 1;
  bVar11 = false;
  if (*pbVar1 == 0) {
    while( true ) {
      while( true ) {
        bVar10 = (byte)((uint)in_DX >> 8);
        bVar7 = (char)in_AX + ' ' + cVar9;
        unaff_BP = unaff_BP + CONCAT11((char)(in_AX >> 8),bVar7);
        *unaff_DI = *unaff_DI + -0x75;
        in_CX = CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + unaff_SI[unaff_BP + 0x4307]);
        cVar9 = bVar7 < 0xf0;
        if ((bool)cVar9) break;
        FUN_1000_0ffc();
        in_AX = CONCAT11(extraout_AH,*in_BX);
        in_DX = extraout_DX;
        in_BX = in_BX + 1;
      }
      puVar2 = (uint *)0x8820;
      uVar3 = *puVar2;
      uVar4 = *puVar2;
      *puVar2 = uVar4 + 5;
      if (0xfffb < uVar3 || 0xfffe < uVar4 + 4) break;
      _uStack0002 = CONCAT22(uStack0004,0xd37);
      func_0x000112b0();
      uVar5 = *in_BX;
      *(undefined1 **)(unaff_SI + 2) = in_BX + 1;
      if (-2 < (int)in_BX) {
        _uStack0002 = CONCAT22(unaff_SS,(int)&stack0x0002 + 2);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      cVar9 = '\0';
      in_AX = (uint)unaff_DI | 0x75;
      _uStack0002 = CONCAT22(unaff_SS,in_CX);
      in_DX = extraout_DX_00;
      in_BX = in_BX + 1;
      unaff_DI = (int *)CONCAT11(unaff_SI[10],uVar5);
    }
    *(undefined1 **)(unaff_SI + 2) = in_BX;
    bVar11 = (unaff_SI[0x1f] & 1) == 0;
  }
  if (bVar11) {
    unaff_SI[1] = unaff_SI[1] | bVar10;
  }
  else {
    uVar8 = FUN_1000_13a2();
    *(undefined2 *)(unaff_SI + 0x1a) = uVar8;
    _uStack0002 = CONCAT22(uStack0004,0xd7d);
    FUN_1000_7297();
    _uStack0002 = CONCAT22(0xd89,uStack0002);
    FUN_1000_0f08();
    bVar10 = 0;
    if ((unaff_SI[0x1f] & 8) == 0) {
      pbVar1 = unaff_SI + 0x16;
      *pbVar1 = *pbVar1 - 1;
      if (*pbVar1 != 0) {
        return;
      }
      bVar7 = thunk_FUN_0000_70d2();
      in_AF = 9 < (bVar7 & 0xf) | in_AF;
      bVar10 = bVar7 + in_AF * '\x06' + (0x99 < bVar7 | bVar10) * '`';
      bVar7 = bVar10 - 0xd;
      bVar10 = bVar7 + (9 < (bVar7 & 0xf) | in_AF) * '\x06' + (0x99 < bVar7 || 0xc < bVar10) * '`';
      pbVar1 = unaff_SI + 0x19;
      *pbVar1 = *pbVar1 - 1;
      if (*pbVar1 == 0) {
        out(extraout_DX_01,CONCAT11(bVar10 / 10,bVar10 % 10));
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      return;
    }
  }
  return;
}


