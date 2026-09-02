/* 1000:727a */

undefined2 __cdecl16near FUN_1000_727a(void)

{
  undefined2 uVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 in_AX;
  int iVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar2 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar2 ^ 1;
  out(0xa6,bVar2 ^ 1);
  puVar5 = (undefined2 *)&DAT_0000_648c;
  iVar4 = 0x480;
  do {
    LOCK();
    uVar1 = puVar5[0x480];
    puVar5[0x480] = *puVar5;
    UNLOCK();
    puVar3 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return in_AX;
}


