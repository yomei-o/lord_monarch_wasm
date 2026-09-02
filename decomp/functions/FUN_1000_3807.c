/* 1000:3807 */

void __cdecl16near FUN_1000_3807(void)

{
  int unaff_SI;
  undefined2 unaff_DS;
  
  if ((*(byte *)(unaff_SI + 10) & 0x80) != 0) {
    return;
  }
  if ((*(byte *)(unaff_SI + 10) & 0x40) == 0) {
    *(undefined1 *)(unaff_SI + 10) = 1;
    return;
  }
  *(undefined1 *)(unaff_SI + 10) = 0x10;
  return;
}


