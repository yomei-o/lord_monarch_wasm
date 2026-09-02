/* 1000:5c94 */

/* WARNING: Instruction at (ram,0x00015cda) overlaps instruction at (ram,0x00015cd9)
    */

uint FUN_1000_5c94(void)

{
  int *piVar1;
  char in_AL;
  char cVar2;
  uint uVar3;
  int in_CX;
  int iVar4;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint in_stack_00000000;
  
  do {
    do {
      iVar5 = unaff_DI;
      cVar2 = in_AL;
      iVar4 = in_CX;
      FUN_1000_5cac();
      in_CX = iVar4 + -1;
      in_AL = cVar2 + '\x01';
      unaff_DI = iVar5;
    } while (in_CX != 0);
    if (SCARRY1(cVar2,'\x01')) {
      return CONCAT11(0xc0,cVar2 + '\x01') ^ 0xad;
    }
    in_CX = iVar4 + -2;
    if (in_CX == 0) {
      return in_stack_00000000;
    }
    piVar1 = (int *)(in_BX + iVar5 + 2 + -0x517b);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    in_AL = cVar2;
    unaff_DI = iVar5 + 2;
  } while (*piVar1 == 0 || SBORROW2(iVar4,1) != *piVar1 < 0);
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(undefined2 *)(iVar5 + 0x1214) = 0x8348;
  *(undefined2 *)(unaff_SI + -0x7a39) = 0xc480;
  uVar3 = func_0x0001b63b();
  return uVar3;
}


