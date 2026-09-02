/* 1000:53d6 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_53d6(void)

{
  undefined2 in_DX;
  int unaff_BP;
  undefined1 *unaff_SI;
  undefined2 unaff_DS;
  bool in_ZF;
  undefined2 in_stack_00000000;
  undefined2 in_stack_0000000c;
  undefined2 in_stack_00000010;
  
  if (!in_ZF) {
    out(*unaff_SI,CONCAT11((char)((uint)in_DX >> 8),(char)in_DX + unaff_SI[unaff_BP]));
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined1 *)0x107d = 0x34;
  *(undefined1 *)0x107b = 0x8d;
  *(undefined1 *)(unaff_BP + 10) = 0;
  return CONCAT22(in_stack_0000000c,in_stack_00000010);
}


