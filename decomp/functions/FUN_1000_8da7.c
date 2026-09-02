/* 1000:8da7 */

/* WARNING: Instruction at (ram,0x00018dc5) overlaps instruction at (ram,0x00018dc3)
    */

undefined2 FUN_1000_8da7(void)

{
  undefined2 in_AX;
  int in_CX;
  undefined2 in_DX;
  byte bVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined2 uStack_6;
  
  bVar1 = *(byte *)(unaff_SI + 0xc) & 0xf;
  if (in_CX == 1 || (*(byte *)(unaff_SI + 0xc) & 0xf) == 0) {
    *(undefined2 *)0x34b8 = *(undefined2 *)(unaff_SI + 8);
    *(undefined2 *)0x34be = *(undefined2 *)(unaff_SI + 4);
    bVar1 = *(byte *)(unaff_SI + 0xc);
    in_AX = 0x1308;
    uStack_6 = in_DX;
  }
  if ((bVar1 & 0x10) != 0) {
    in_AX = 0x1306;
  }
  *(undefined2 *)0x34bc = in_AX;
  *(uint *)0x34ba = bVar1 & 0xf;
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d6 < *(byte *)0x34d7) break;
    *(char *)0x34d6 = *(byte *)0x34d6 - *(byte *)0x34d7;
    func_0x00016292();
  }
  *(undefined1 *)0x34d6 = 0;
  return uStack_6;
}


