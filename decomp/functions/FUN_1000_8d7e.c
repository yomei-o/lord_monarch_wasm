/* 1000:8d7e */

undefined2 FUN_1000_8d7e(void)

{
  char in_AL;
  char in_CH;
  int in_BX;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  bool in_ZF;
  uint in_stack_00000000;
  
  if (!in_ZF) {
    in_CH = '0';
  }
  *unaff_DI = in_AL + in_CH;
  return CONCAT11((char)((in_stack_00000000 & 0xff0f) >> 8),
                  (byte)(in_stack_00000000 & 0xff0f) | *(byte *)(in_BX + unaff_SI + 0x48));
}


