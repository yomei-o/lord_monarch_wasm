/* 1000:5b82 */

undefined4 FUN_1000_5b82(undefined2 param_1,undefined2 param_2)

{
  undefined2 in_AX;
  byte *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  *unaff_DI = in_AX;
  *unaff_SI = *unaff_SI & (byte)in_AX;
  out(0xec,0);
  return CONCAT22(in_stack_00000000,param_2);
}


