/* 1000:5c87 */

/* WARNING: Instruction at (ram,0x00015cda) overlaps instruction at (ram,0x00015cd9)
    */

uint FUN_1000_5c87(void)

{
  int *piVar1;
  undefined2 uVar2;
  byte bVar3;
  undefined2 *puVar4;
  undefined2 in_AX;
  byte bVar6;
  uint uVar5;
  int iVar7;
  int iVar8;
  undefined2 in_DX;
  int in_BX;
  undefined1 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint in_stack_00000000;
  
  uVar2 = in(in_DX);
  *unaff_DI = uVar2;
  *unaff_SI = 0;
  bVar6 = (byte)((uint)in_AX >> 8);
  bVar3 = bVar6 >> 1;
  iVar8 = 0x40;
  bVar3 = (byte)(bVar3 | bVar6 << 7) >> 1 | bVar3 << 7;
  puVar4 = unaff_DI + 1;
  do {
    do {
      puVar9 = puVar4;
      bVar6 = bVar3;
      iVar7 = iVar8;
      FUN_1000_5cac();
      iVar8 = iVar7 + -1;
      bVar3 = bVar6 + 1;
      puVar4 = puVar9;
    } while (iVar8 != 0);
    if (SCARRY1(bVar6,'\x01')) {
      return CONCAT11(0xc0,bVar6 + 1) ^ 0xad;
    }
    iVar8 = iVar7 + -2;
    if (iVar8 == 0) {
      return in_stack_00000000;
    }
    piVar1 = (int *)((int)(puVar9 + 1) + in_BX + -0x517b);
    iVar7 = *piVar1;
    *piVar1 = *piVar1 + -1;
    bVar3 = bVar6;
    puVar4 = puVar9 + 1;
  } while (*piVar1 == 0 || SBORROW2(iVar7,1) != *piVar1 < 0);
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  puVar9[0x90a] = 0x8348;
  *(undefined2 *)(unaff_SI + -0x7a39) = 0xc480;
  uVar5 = func_0x0001b63b();
  return uVar5;
}


