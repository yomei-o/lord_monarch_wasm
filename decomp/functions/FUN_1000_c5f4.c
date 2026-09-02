/* 1000:c5f4 */

undefined2 __cdecl16near FUN_1000_c5f4(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d6 < *(byte *)0x34d7) break;
    *(char *)0x34d6 = *(byte *)0x34d6 - *(byte *)0x34d7;
    FUN_1000_9aa6();
  }
  *(undefined1 *)0x34d6 = 0;
  return in_AX;
}


