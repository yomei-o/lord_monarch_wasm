/* 1000:9650 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_9650(void)

{
  undefined2 in_CX;
  byte bVar1;
  byte extraout_DH;
  char *in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 in_stack_00000000;
  
  *(undefined1 *)(unaff_BP + unaff_SI + 0x8aa) = 0;
  bVar1 = (byte)((uint)in_CX >> 8) & (byte)((uint)*(undefined2 *)0xc763 >> 8);
  func_0x00015fc6();
  func_0x00011ecd();
  func_0x00015fc3();
  func_0x00011eca();
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) | extraout_DH;
  *in_BX = *in_BX + bVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


