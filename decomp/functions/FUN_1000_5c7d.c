/* 1000:5c7d */

/* WARNING: Instruction at (ram,0x00015cda) overlaps instruction at (ram,0x00015cd9)
    */

uint FUN_1000_5c7d(void)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  uint in_AX;
  byte bVar8;
  undefined1 uVar9;
  uint uVar7;
  int in_CX;
  int iVar10;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint in_stack_00000000;
  
  unaff_SI[unaff_BP + 0x1e6a] = unaff_SI[unaff_BP + 0x1e6a] | (byte)((uint)in_CX >> 8);
  bVar5 = (byte)in_AX;
  *unaff_SI = *unaff_SI + bVar5;
  bVar8 = (byte)(in_AX >> 8);
  if (!CARRY1(bVar5,bVar5) && (in_AX & 0x7f) != 0) {
    uVar7 = (uint)*(undefined4 *)(unaff_BP + (int)unaff_DI);
    goto LAB_1000_5cc9;
  }
  puVar2 = unaff_DI;
  unaff_DI = unaff_DI + 1;
  uVar3 = in(in_DX);
  *puVar2 = uVar3;
  *unaff_SI = '\0';
  in_CX = 0x40;
  bVar5 = bVar8 >> 1;
  uVar7 = (uint)(byte)((byte)(bVar5 | bVar8 << 7) >> 1 | bVar5 << 7);
  do {
    uVar4 = CONCAT11(0xc0,(char)uVar7);
    do {
      iVar10 = in_CX;
      uVar7 = uVar4;
      FUN_1000_5cac();
      uVar9 = (undefined1)(uVar7 >> 8);
      cVar6 = (char)uVar7 + '\x01';
      in_CX = iVar10 + -1;
      uVar4 = CONCAT11(uVar9,cVar6);
    } while (in_CX != 0);
    if (SCARRY1((char)uVar7,'\x01')) {
      return CONCAT11(uVar9,cVar6) ^ 0xad;
    }
    unaff_DI = unaff_DI + 1;
    uVar7 = uVar7 & 0xff;
    in_CX = iVar10 + -2;
    if (in_CX == 0) {
      return in_stack_00000000;
    }
LAB_1000_5cc9:
    piVar1 = (int *)((int)unaff_DI + in_BX + -0x517b);
    iVar10 = *piVar1;
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 == 0 || SBORROW2(iVar10,1) != *piVar1 < 0);
  unaff_SI[in_BX] = unaff_SI[in_BX] + (char)uVar7;
  unaff_DI[0x909] = 0x8348;
  (unaff_SI + -0x7a39)[0] = -0x80;
  (unaff_SI + -0x7a39)[1] = -0x3c;
  uVar7 = func_0x0001b63b();
  return uVar7;
}


