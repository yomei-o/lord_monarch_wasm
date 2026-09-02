/* 1000:ac00 */

void __cdecl16near FUN_1000_ac00(void)

{
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  if (unaff_SI[0xc] == 4) {
    if ((*unaff_SI & 2) != 0) {
      return;
    }
    return;
  }
  if ((*unaff_SI & 2) == 0) {
    if ((*unaff_SI & 1) != 0) {
      return;
    }
    return;
  }
  return;
}


