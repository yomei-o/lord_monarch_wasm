/* 1000:6de4 */

void FUN_1000_6de4(void)

{
  int iVar1;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  *unaff_DI = in_AX;
  func_0x0001f552();
  LOCK();
  iVar1 = *(int *)(in_BX + unaff_SI);
  *(int *)(in_BX + unaff_SI) = unaff_SI;
  UNLOCK();
  LOCK();
  *(undefined2 *)(in_BX + iVar1 + 0x14) = extraout_DX;
  UNLOCK();
  *(undefined1 *)((int)unaff_DI + in_BX + 9) = extraout_AH;
  return;
}


