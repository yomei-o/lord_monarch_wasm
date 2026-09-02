/* 1000:49a2 */

void FUN_1000_49a2(void)

{
  int in_AX;
  undefined2 *unaff_BP;
  int *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  *unaff_SI = *unaff_SI + in_AX + (uint)in_CF;
  out(0xee,(char)in_AX);
  *unaff_BP = 0x49af;
  FUN_1000_60e9();
  return;
}


