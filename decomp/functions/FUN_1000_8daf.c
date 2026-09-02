/* 1000:8daf */

/* WARNING: Instruction at (ram,0x00018dc5) overlaps instruction at (ram,0x00018dc3)
    */

undefined2 FUN_1000_8daf(void)

{
  undefined2 in_AX;
  int in_CX;
  byte in_BL;
  int unaff_SI;
  undefined2 unaff_DS;
  char in_ZF;
  undefined2 in_stack_00000000;
  
  if (in_CX == 1 || in_ZF != '\0') {
    *(undefined2 *)0x34b8 = *(undefined2 *)(unaff_SI + 8);
    *(undefined2 *)0x34be = *(undefined2 *)(unaff_SI + 4);
    in_BL = *(byte *)(unaff_SI + 0xc);
    in_AX = 0x1308;
  }
  if ((in_BL & 0x10) != 0) {
    in_AX = 0x1306;
  }
  *(undefined2 *)0x34bc = in_AX;
  *(uint *)0x34ba = in_BL & 0xf;
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d6 < *(byte *)0x34d7) break;
    *(char *)0x34d6 = *(byte *)0x34d6 - *(byte *)0x34d7;
    func_0x00016292();
  }
  *(undefined1 *)0x34d6 = 0;
  return in_stack_00000000;
}


