/* 1000:8dc3 */

undefined2 FUN_1000_8dc3(void)

{
  byte bVar1;
  undefined2 uVar2;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  bVar1 = *(byte *)(unaff_SI + 10);
  uVar2 = 0x1308;
  if ((bVar1 & 0x10) != 0) {
    uVar2 = 0x1306;
  }
  *(undefined2 *)0x34bc = uVar2;
  *(uint *)0x34ba = bVar1 & 0xf;
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d6 < *(byte *)0x34d7) break;
    *(char *)0x34d6 = *(byte *)0x34d6 - *(byte *)0x34d7;
    func_0x00016292();
  }
  *(undefined1 *)0x34d6 = 0;
  return in_stack_00000000;
}


