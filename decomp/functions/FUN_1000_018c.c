/* 1000:018c */

void __cdecl16near FUN_1000_018c(void)

{
  uint *puVar1;
  byte in_AH;
  int in_CX;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  do {
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  puVar1 = (uint *)(in_BX + unaff_SI + 2);
  *puVar1 = *puVar1 | in_DX;
  *(char *)(unaff_BP + in_stack_00000000) =
       *(char *)(unaff_BP + in_stack_00000000) + '`' + (in_AH < (byte)(in_DX >> 8));
  out(0x43,0x40);
  return;
}


