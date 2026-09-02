/* 1000:2703 */

void FUN_1000_2703(void)

{
  code *pcVar1;
  char in_AL;
  int iVar2;
  byte in_CL;
  undefined2 in_DX;
  byte in_BH;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  *(char *)0x230 = in_AL + -0x5b;
  iVar2 = in(in_DX);
  *(int *)(unaff_BP + in_stack_00000000) =
       *(int *)(unaff_BP + in_stack_00000000) + iVar2 + (uint)CARRY1(in_BH,in_CL);
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}


