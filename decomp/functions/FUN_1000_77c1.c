/* 1000:77c1 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_77c1(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int in_CX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar3;
  undefined2 in_stack_00000010;
  undefined2 in_stack_00000014;
  
  FUN_1000_842c();
  bVar2 = FUN_1000_812c();
  pbVar1 = (byte *)(in_BX + unaff_SI);
  bVar3 = false;
  *pbVar1 = *pbVar1 & (byte)in_CX;
  if (-1 < (char)*pbVar1) {
    FUN_1000_8a2a();
    *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) & (byte)in_CX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  do {
    if ((!bVar3) && (bVar2 < 0x70)) {
      FUN_1000_78c3();
    }
    while( true ) {
      while( true ) {
        while( true ) {
          in_CX = in_CX + -1;
          if (in_CX == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) {
              return CONCAT22(in_stack_00000010,in_stack_00000014);
            }
            in_CX = 3;
          }
          FUN_1000_6ab8();
          bVar2 = *(byte *)(in_BX + -0x2d82);
          if ((bVar2 < 0x30) || (0x5f < bVar2)) break;
          FUN_1000_77c1();
        }
        if ((bVar2 < 0x20) || (0x2f < bVar2)) break;
        func_0x0001783a();
      }
      if ((bVar2 == 0) || (4 < bVar2)) break;
      FUN_1000_7885();
    }
    bVar3 = bVar2 < 0x60;
  } while( true );
}


