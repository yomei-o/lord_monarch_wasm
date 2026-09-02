/* 1000:77b5 */

undefined4 FUN_1000_77b5(void)

{
  byte bVar1;
  int in_CX;
  int in_BX;
  undefined2 unaff_DS;
  int in_stack_00000000;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  
  do {
    in_CX = in_CX + -1;
    if (in_CX == 0) {
      in_stack_00000000 = in_stack_00000000 + -1;
      if (in_stack_00000000 == 0) {
        return CONCAT22(in_stack_0000000e,in_stack_00000012);
      }
      in_CX = 3;
    }
    FUN_1000_6ab8();
    bVar1 = *(byte *)(in_BX + -0x2d82);
    if ((bVar1 < 0x30) || (0x5f < bVar1)) {
      if ((bVar1 < 0x20) || (0x2f < bVar1)) {
        if ((bVar1 == 0) || (4 < bVar1)) {
          if ((0x5f < bVar1) && (bVar1 < 0x70)) {
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
    }
    else {
      FUN_1000_77c1();
    }
  } while( true );
}


