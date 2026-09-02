/* 1000:6aea */

undefined4 __cdecl16near FUN_1000_6aea(void)

{
  code *pcVar1;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  return CONCAT22(in_AX,in_stack_00000000);
}


