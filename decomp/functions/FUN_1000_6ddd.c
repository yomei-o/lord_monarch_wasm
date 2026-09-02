/* 1000:6ddd */

void FUN_1000_6ddd(void)

{
  int iVar1;
  undefined1 extraout_AH;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  *unaff_DI = in_DX;
  func_0x0001f552();
  LOCK();
  iVar1 = *(int *)(in_stack_00000000 + unaff_SI);
  *(int *)(in_stack_00000000 + unaff_SI) = unaff_SI;
  UNLOCK();
  LOCK();
  *(undefined2 *)(in_stack_00000000 + iVar1 + 0x14) = extraout_DX;
  UNLOCK();
  *(undefined1 *)((int)unaff_DI + in_stack_00000000 + 9) = extraout_AH;
  return;
}


