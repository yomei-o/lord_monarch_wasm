/* 1000:6e4c */

void FUN_1000_6e4c(void)

{
  byte *pbVar1;
  int in_CX;
  undefined1 *unaff_SI;
  undefined1 *puVar2;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  char in_CF;
  
  while( true ) {
    unaff_SI[0x2488] = unaff_SI[0x2488] + (char)in_CX + in_CF;
    puVar2 = unaff_SI + 0xb;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    pbVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    unaff_SI = &stack0x0001 + (int)puVar2;
    in_CF = (byte)puVar2[(int)register0x00000010] < *pbVar1;
  }
  return;
}


