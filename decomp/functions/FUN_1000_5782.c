/* 1000:5782 */

int FUN_1000_5782(void)

{
  undefined1 *puVar1;
  int in_AX;
  int in_CX;
  int in_BX;
  undefined1 *unaff_SI;
  undefined2 unaff_DS;
  
  while( true ) {
    in_BX = in_BX + in_AX;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    puVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    in_AX = CONCAT11((char)((uint)in_AX >> 8),*puVar1);
  }
  return in_BX;
}


