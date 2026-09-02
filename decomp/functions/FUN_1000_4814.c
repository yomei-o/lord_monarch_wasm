/* 1000:4814 */

void __cdecl16near FUN_1000_4814(void)

{
  int in_DX;
  undefined2 extraout_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(undefined1 *)(unaff_SI + 0xb) = 0xff;
  if (in_DX != *(int *)0x32bb) {
    FUN_1000_bd1e();
    if (((*(int *)0x3bce == 0) || (9 < *(uint *)0x3bc2)) ||
       (*(char *)(unaff_SI + 0xc) == *(char *)0x3c00)) {
      FUN_1000_bd84();
    }
    else {
      FUN_1000_bd3b();
    }
    FUN_1000_be36();
    *(undefined2 *)0x32bb = extraout_DX;
  }
  return;
}


