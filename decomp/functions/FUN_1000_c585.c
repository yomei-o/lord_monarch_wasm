/* 1000:c585 */

void __cdecl16near FUN_1000_c585(void)

{
  byte bVar1;
  uint in_AX;
  char in_CH;
  char *unaff_DI;
  undefined2 unaff_ES;
  
  bVar1 = ((byte)(in_AX >> 1) & 0x7f) >> 3;
  if (bVar1 != 0) {
    in_CH = '0';
  }
  *unaff_DI = bVar1 + in_CH;
  if ((in_AX & 0xf) != 0) {
    in_CH = '0';
  }
  unaff_DI[1] = ((byte)in_AX & 0xf) + in_CH;
  return;
}


