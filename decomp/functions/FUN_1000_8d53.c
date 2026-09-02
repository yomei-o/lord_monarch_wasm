/* 1000:8d53 */

undefined2 FUN_1000_8d53(void)

{
  byte bVar1;
  char in_CH;
  undefined2 in_DX;
  int in_BX;
  undefined1 *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  uint in_stack_00000008;
  
  unaff_SI[-0x75c2] = unaff_SI[-0x75c2] ^ (byte)in_BX;
  out(*unaff_SI,in_DX);
                    /* WARNING: Call to offcut address within same function */
  func_0x00018d7d();
                    /* WARNING: Call to offcut address within same function */
  func_0x00018d7d();
                    /* WARNING: Call to offcut address within same function */
  func_0x00018d7d();
  bVar1 = FUN_1000_807d();
  *(byte *)0xd050 = *(byte *)0xd050 & 0xe8;
  if (bVar1 >> 3 != 0) {
    in_CH = '0';
  }
  *unaff_DI = (bVar1 >> 3) + in_CH;
  return CONCAT11((char)((in_stack_00000008 & 0xff0f) >> 8),
                  (byte)(in_stack_00000008 & 0xff0f) | unaff_SI[in_BX + 0x4d]);
}


