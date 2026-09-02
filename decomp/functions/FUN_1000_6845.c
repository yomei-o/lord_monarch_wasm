/* 1000:6845 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_6845(void)

{
  code *pcVar1;
  byte in_CL;
  undefined2 in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_DS;
  int iStack_2;
  
  *(int *)((int)&iStack_2 + (-(uint)CARRY1(in_CL,*unaff_SI) - *(int *)(unaff_SI + unaff_BP))) =
       unaff_BP;
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


