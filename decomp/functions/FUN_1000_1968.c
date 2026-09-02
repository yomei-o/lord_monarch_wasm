/* 1000:1968 */

void FUN_1000_1968(void)

{
  char in_AL;
  char in_AH;
  char in_CL;
  char in_DH;
  undefined1 in_ZF;
  
  while ((bool)in_ZF) {
    do {
      do {
        in_CL = in_CL + '\x01';
      } while (in_AL == in_CL);
    } while (in_AH == in_CL);
    in_ZF = in_DH == in_CL;
  }
  return;
}


