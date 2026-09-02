/* 1000:6def */

char FUN_1000_6def(void)

{
  int iVar1;
  char cVar2;
  char cVar3;
  undefined1 extraout_AH;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  cVar3 = func_0x0001f552();
  LOCK();
  iVar1 = *(int *)(in_BX + unaff_SI);
  *(int *)(in_BX + unaff_SI) = unaff_SI;
  UNLOCK();
  cVar2 = *(char *)(in_BX + -0x79);
  LOCK();
  *(undefined2 *)(in_BX + iVar1 + 0x14) = extraout_DX;
  UNLOCK();
  *(undefined1 *)(in_BX + unaff_DI + 7) = extraout_AH;
  return cVar3 + cVar2;
}


