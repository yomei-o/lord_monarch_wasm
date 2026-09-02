/* 1000:5c96 */

/* WARNING: Instruction at (ram,0x00015cda) overlaps instruction at (ram,0x00015cd9)
    */

uint FUN_1000_5c96(void)

{
  int *piVar1;
  char cVar2;
  undefined2 in_AX;
  undefined1 uVar4;
  uint uVar3;
  int in_CX;
  int iVar5;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint in_stack_00000000;
  
  while( true ) {
    do {
      iVar5 = in_CX;
      FUN_1000_5cac();
      cVar2 = (char)in_AX;
      uVar4 = (undefined1)((uint)in_AX >> 8);
      in_AX = CONCAT11(uVar4,cVar2 + '\x01');
      in_CX = iVar5 + -1;
    } while (in_CX != 0);
    if (SCARRY1(cVar2,'\x01')) {
      return CONCAT11(uVar4,cVar2 + '\x01') ^ 0xad;
    }
    in_CX = iVar5 + -2;
    if (in_CX == 0) {
      return in_stack_00000000;
    }
    piVar1 = (int *)(in_BX + unaff_DI + 2 + -0x517b);
    iVar5 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0 && SBORROW2(iVar5,1) == *piVar1 < 0) break;
    in_AX = CONCAT11(0xc0,cVar2);
    unaff_DI = unaff_DI + 2;
  }
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(undefined2 *)(unaff_DI + 0x1214) = 0x8348;
  *(undefined2 *)(unaff_SI + -0x7a39) = 0xc480;
  uVar3 = func_0x0001b63b();
  return uVar3;
}


