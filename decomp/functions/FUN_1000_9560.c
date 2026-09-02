/* 1000:9560 */

byte __cdecl16near FUN_1000_9560(void)

{
  byte bVar1;
  int iVar2;
  undefined1 *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar2 = 0xb5e;
  bVar1 = *(byte *)0x3482;
  do {
    out(0xa6,bVar1 ^ 1);
    out(0xa6,bVar1);
    *unaff_SI = *unaff_SI;
    unaff_SI = unaff_SI + 0xb;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}


