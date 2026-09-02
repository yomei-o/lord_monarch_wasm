/* 1000:493a */

void __cdecl16near FUN_1000_493a(void)

{
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(char *)(unaff_SI + 0xe) = *(char *)(unaff_SI + 0xe) + '\x01';
  if (*(byte *)(unaff_SI + 0xe) < 4) {
    return;
  }
  FUN_1000_a9ca();
  return;
}


