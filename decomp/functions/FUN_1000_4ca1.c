/* 1000:4ca1 */

void __cdecl16near FUN_1000_4ca1(void)

{
  byte in_AL;
  byte in_CH;
  char *unaff_DI;
  undefined2 unaff_DS;
  
  if ((in_AL & 2) == 0) {
    if ((char)(*unaff_DI + -1) < '\0') {
      return;
    }
  }
  else if (in_CH < (byte)(*unaff_DI + 1U)) {
    return;
  }
  return;
}


