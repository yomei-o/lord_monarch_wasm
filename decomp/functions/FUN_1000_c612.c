/* 1000:c612 */

undefined2 __cdecl16near FUN_1000_c612(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (CARRY1(*(byte *)0x34d6,*(byte *)0x34d7)) break;
    *(char *)0x34d6 = *(byte *)0x34d6 + *(byte *)0x34d7;
    FUN_1000_9aa6();
  }
  *(undefined1 *)0x34d6 = 0xff;
  return in_AX;
}


