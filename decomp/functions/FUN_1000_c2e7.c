/* 1000:c2e7 */

undefined2 __cdecl16near FUN_1000_c2e7(void)

{
  undefined2 in_AX;
  int iVar1;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(byte *)(unaff_SI + 0xb) != 0xff) {
    iVar1 = (uint)*(byte *)(unaff_SI + 0xb) * 0x80;
    *(int *)((undefined *)&DAT_0000_247c + iVar1) =
         *(int *)((undefined *)&DAT_0000_247c + iVar1) + -1;
    if (*(uint *)((undefined *)&DAT_0000_247c + iVar1) <=
        *(uint *)((undefined *)&DAT_0000_247e + iVar1)) {
      *(undefined1 *)(unaff_SI + 0xb) = 0xff;
    }
  }
  return in_AX;
}


