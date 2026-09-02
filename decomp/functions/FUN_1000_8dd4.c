/* 1000:8dd4 */

undefined2 FUN_1000_8dd4(void)

{
  uint in_BX;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  *(uint *)0x34ba = in_BX & 0xf;
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d6 < *(byte *)0x34d7) break;
    *(char *)0x34d6 = *(byte *)0x34d6 - *(byte *)0x34d7;
    func_0x00016292();
  }
  *(undefined1 *)0x34d6 = 0;
  return in_stack_00000000;
}


