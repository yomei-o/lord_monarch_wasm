/* 1000:5c9f */

/* WARNING: Instruction at (ram,0x00015cda) overlaps instruction at (ram,0x00015cd9)
    */

uint FUN_1000_5c9f(uint param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined2 in_AX;
  undefined1 uVar5;
  uint uVar4;
  int iVar6;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  int iVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  do {
    cVar3 = (char)in_AX;
    uVar5 = (undefined1)((uint)in_AX >> 8);
    in_AX = CONCAT11(uVar5,cVar3 + '\x01');
    iVar6 = in_stack_00000000 + -1;
    iVar7 = unaff_DI;
    if (iVar6 == 0) {
      if (SCARRY1(cVar3,'\x01')) {
        return CONCAT11(uVar5,cVar3 + '\x01') ^ 0xad;
      }
      iVar7 = unaff_DI + 2;
      iVar6 = in_stack_00000000 + -2;
      if (iVar6 == 0) {
        return param_1;
      }
      piVar1 = (int *)(in_BX + iVar7 + -0x517b);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0 && SBORROW2(iVar2,1) == *piVar1 < 0) {
        *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
        *(undefined2 *)(unaff_DI + 0x1214) = 0x8348;
        *(undefined2 *)(unaff_SI + -0x7a39) = 0xc480;
        uVar4 = func_0x0001b63b();
        return uVar4;
      }
      in_AX = CONCAT11(0xc0,cVar3);
    }
    FUN_1000_5cac();
    unaff_DI = iVar7;
    in_stack_00000000 = iVar6;
  } while( true );
}


