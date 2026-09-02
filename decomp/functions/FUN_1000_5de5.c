/* 1000:5de5 */

undefined4 FUN_1000_5de5(void)

{
  char in_AL;
  byte bVar1;
  int in_CX;
  int in_BX;
  uint unaff_BP;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  char *unaff_DS;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  do {
    *(byte *)(in_BX + 0x2e10) = *(byte *)(in_BX + 0x2e10) & (byte)in_CX;
    *(uint *)(unaff_DS + unaff_BP + 0x8aa) = *(uint *)(unaff_DS + unaff_BP + 0x8aa) & unaff_BP;
    bVar1 = in_AL - 0x18U & 0xf;
    out(0xae,bVar1);
    *(byte *)(in_BX + 0x2e12) = *(byte *)(in_BX + 0x2e12) | bVar1;
    in_AL = *(char *)0x2e10;
    *(char *)(in_BX + 0x2e2f) = *(char *)(in_BX + 0x2e2f) + in_AL;
    *unaff_DS = in_AL;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + '\x01');
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


