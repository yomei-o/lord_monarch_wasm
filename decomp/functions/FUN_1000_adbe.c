/* 1000:adbe */

void __cdecl16near FUN_1000_adbe(void)

{
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  if (*(int *)0xc4f2 != 0) {
    *(int *)0xc4f2 = *(int *)0xc4f2 + -1;
    return;
  }
  *unaff_SI = *unaff_SI | 1;
  return;
}


