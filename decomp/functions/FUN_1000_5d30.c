/* 1000:5d30 */

undefined2 FUN_1000_5d30(void)

{
  undefined1 uVar1;
  undefined2 in_AX;
  char in_BL;
  uint *unaff_SI;
  undefined2 unaff_DS;
  char in_CF;
  undefined2 in_stack_00000000;
  
  uVar1 = *(undefined1 *)0x3183;
  *(char *)unaff_SI = (char)*unaff_SI + in_BL + in_CF;
  *unaff_SI = *unaff_SI ^ 0xffa1;
  do {
  } while (CONCAT11((char)((uint)in_AX >> 8),uVar1) == *(int *)0x32da);
  return in_stack_00000000;
}


