/* 1000:5712 */

void FUN_1000_5712(void)

{
  int in_AX;
  undefined2 in_DX;
  undefined2 *unaff_SI;
  code *unaff_DI;
  undefined2 unaff_DS;
  
  if (in_AX == *(int *)0x3e98) {
    out(*unaff_SI,in_DX);
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*unaff_DI)();
  return;
}


