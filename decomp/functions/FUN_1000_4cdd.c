/* 1000:4cdd */

undefined4 __cdecl16near FUN_1000_4cdd(void)

{
  char cVar1;
  undefined2 in_AX;
  int iVar2;
  char cVar3;
  undefined2 in_DX;
  int iVar4;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 unaff_DS;
  
  cVar3 = 'v';
  if (((*(int *)0x3bc2 != -1) && (cVar3 = '\0', *(int *)0x3bd4 != 0)) &&
     (cVar3 = '\x03', *(int *)0x3bd6 != 0)) {
    cVar3 = -10;
  }
  LOCK();
  cVar1 = *(char *)0x32c1;
  *(char *)0x32c1 = cVar3;
  iVar4 = CONCAT11(cVar1,cVar3);
  UNLOCK();
  if (cVar3 != cVar1) {
    cVar3 = *(char *)0x328a;
    if (cVar3 != -1) {
      FUN_1000_4d86();
      iVar4 = extraout_DX;
    }
    iVar2 = 8;
    do {
      if ((char)((byte)((uint)iVar4 >> 8) ^ (byte)iVar4) < '\0') {
        FUN_1000_8738();
        FUN_1000_727a();
        FUN_1000_8738();
        FUN_1000_727a();
        iVar4 = extraout_DX_00;
      }
      iVar4 = iVar4 * 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (cVar3 != -1) {
      FUN_1000_4d4a();
    }
  }
  return CONCAT22(in_DX,in_AX);
}


