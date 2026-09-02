/* 1000:2d39 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_2d39(void)

{
  byte in_AL;
  undefined1 uVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar2;
  
  bVar2 = 0xf7 < in_AL;
  uVar1 = func_0x0001a63f();
  if (!bVar2) {
    *(undefined1 *)(unaff_SI + 1) = uVar1;
    uVar1 = func_0x0001ae89();
    *(undefined1 *)(unaff_SI + 0xb) = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


