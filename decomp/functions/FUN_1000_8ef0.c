/* 1000:8ef0 */

undefined3 FUN_1000_8ef0(void)

{
  char cVar1;
  char in_DL;
  byte in_DH;
  int in_BX;
  undefined2 unaff_BP;
  int unaff_SI;
  undefined2 unaff_DS;
  
  cVar1 = *(char *)(in_BX + unaff_SI + 0x55);
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) ^ in_DH;
  return CONCAT12(in_DL + cVar1,unaff_BP);
}


