/* 1000:4924 */

void __cdecl16near FUN_1000_4924(void)

{
  byte in_AL;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  if ((*unaff_SI & 2) == 0) {
    *unaff_SI = *unaff_SI | 2;
    unaff_SI[0xf] = in_AL;
    unaff_SI[0xe] = 0;
  }
  (unaff_SI + 6)[0] = 0;
  (unaff_SI + 6)[1] = 0;
  return;
}


