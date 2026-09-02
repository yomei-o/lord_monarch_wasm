/* 1000:5cdf */

/* WARNING: Instruction at (ram,0x00015ce0) overlaps instruction at (ram,0x00015cdf)
    */

uint FUN_1000_5cdf(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  char in_AL;
  uint uVar4;
  int in_CX;
  int iVar5;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint in_stack_00000000;
  
  while( true ) {
    iVar5 = in_CX + -1;
    if (iVar5 == 0) {
      return in_stack_00000000;
    }
    piVar1 = (int *)(in_BX + unaff_DI + -0x517b);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    cVar3 = in_AL;
    if (*piVar1 != 0 && SBORROW2(iVar2,1) == *piVar1 < 0) break;
    do {
      in_AL = cVar3;
      FUN_1000_5cac();
      iVar5 = iVar5 + -1;
      cVar3 = in_AL + '\x01';
    } while (iVar5 != 0);
    if (SCARRY1(in_AL,'\x01')) {
      return CONCAT11(0xc0,in_AL + '\x01') ^ 0xad;
    }
    unaff_DI = unaff_DI + 2;
    in_CX = 0;
  }
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_AL;
  *(undefined2 *)(unaff_DI + 0x1212) = 0x8348;
  *(undefined2 *)(unaff_SI + -0x7a39) = 0xc480;
  uVar4 = func_0x0001b63b();
  return uVar4;
}


