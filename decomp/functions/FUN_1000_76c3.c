/* 1000:76c3 */

undefined2 FUN_1000_76c3(void)

{
  int *piVar1;
  char in_AL;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  if ((*(byte *)0x3be8 & ~(in_AL << (*(byte *)0x3c02 & 0x1f))) == 0) {
    piVar1 = (int *)0x3bcc;
    *piVar1 = *piVar1 + 1;
    if (*piVar1 == 0) {
      *(undefined2 *)0x3bcc = 0xffff;
    }
    if (*(int *)0x3bca != 0) {
      *(int *)0x3bca = *(int *)0x3bca + -1;
    }
  }
  return in_stack_00000000;
}


