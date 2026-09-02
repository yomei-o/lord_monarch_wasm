/* 1000:5d19 */

undefined2 FUN_1000_5d19(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int in_CX;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  while( true ) {
    LOCK();
    uVar1 = unaff_DI[0x480];
    unaff_DI[0x480] = in_AX;
    UNLOCK();
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar2 = uVar1;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    in_AX = *unaff_DI;
  }
  return in_stack_00000000;
}


