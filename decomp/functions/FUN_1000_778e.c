/* 1000:778e */

undefined4 FUN_1000_778e(void)

{
  byte in_AL;
  int in_CX;
  int in_BX;
  undefined2 unaff_DS;
  int in_stack_00000000;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  
  do {
    if ((in_AL < 0x20) || (0x2f < in_AL)) {
      if ((in_AL == 0) || (4 < in_AL)) {
        if ((0x5f < in_AL) && (in_AL < 0x70)) {
          FUN_1000_78c3();
        }
      }
      else {
        FUN_1000_7885();
      }
    }
    else {
      func_0x0001783a();
    }
    while( true ) {
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        in_stack_00000000 = in_stack_00000000 + -1;
        if (in_stack_00000000 == 0) {
          return CONCAT22(in_stack_0000000e,in_stack_00000012);
        }
        in_CX = 3;
      }
      FUN_1000_6ab8();
      in_AL = *(byte *)(in_BX + -0x2d82);
      if ((in_AL < 0x30) || (0x5f < in_AL)) break;
      FUN_1000_77c1();
    }
  } while( true );
}


