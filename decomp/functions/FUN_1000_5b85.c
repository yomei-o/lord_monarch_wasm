/* 1000:5b85 */

undefined2 FUN_1000_5b85(undefined2 param_1)

{
  byte in_AL;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  *unaff_SI = *unaff_SI & in_AL;
  out(0xec,0);
  return param_1;
}


