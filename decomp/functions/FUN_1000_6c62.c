/* 1000:6c62 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_6c62(void)

{
  undefined1 uVar1;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int in_stack_00000000;
  
  *(undefined2 *)(in_stack_00000000 + -2) = 0x6c6a;
  uVar1 = func_0x000121da();
  *unaff_DI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


