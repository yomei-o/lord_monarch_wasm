/* 1000:6dce */

void FUN_1000_6dce(void)

{
  byte *pbVar1;
  int iVar2;
  undefined1 extraout_AH;
  byte in_CL;
  undefined2 in_DX;
  undefined2 uVar3;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  uVar3 = CONCAT11((char)((uint)in_DX >> 8) - *(char *)(unaff_BP + (int)unaff_DI),(char)in_DX);
  pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x65f);
  *pbVar1 = *pbVar1 >> (in_CL & 7) | *pbVar1 << 8 - (in_CL & 7);
  if (in_BX != 0) {
    uVar3 = *(undefined2 *)(in_BX + 6);
  }
  *unaff_DI = uVar3;
  func_0x0001f552();
  LOCK();
  iVar2 = *(int *)(in_stack_00000000 + unaff_SI);
  *(int *)(in_stack_00000000 + unaff_SI) = unaff_SI;
  UNLOCK();
  LOCK();
  *(undefined2 *)(in_stack_00000000 + iVar2 + 0x14) = extraout_DX;
  UNLOCK();
  *(undefined1 *)((int)unaff_DI + in_stack_00000000 + 9) = extraout_AH;
  return;
}


