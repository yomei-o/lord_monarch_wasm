/* 1000:729a */

undefined2 __cdecl16near FUN_1000_729a(void)

{
  byte bVar1;
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
  return in_AX;
}


