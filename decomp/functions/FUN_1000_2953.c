/* 1000:2953 */

void FUN_1000_2953(void)

{
  char *pcVar1;
  byte *pbVar2;
  undefined1 in_AL;
  byte in_AH;
  byte in_DL;
  char in_DH;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) ^ in_DL;
  *unaff_DI = in_AL;
  unaff_DI[1] = in_AL;
  pbVar2 = (byte *)(in_BX + unaff_SI + 0x3a);
  *pbVar2 = *pbVar2 | in_AH;
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0x62);
  *pcVar1 = *pcVar1 + in_DH;
  return;
}


