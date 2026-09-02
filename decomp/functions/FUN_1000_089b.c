/* 1000:089b */

undefined1 FUN_1000_089b(void)

{
  char *pcVar1;
  undefined1 uVar2;
  undefined2 in_DX;
  char in_BH;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0x7fd9);
  *pcVar1 = *pcVar1 + in_BH;
  uVar2 = in(in_DX);
  return uVar2;
}


