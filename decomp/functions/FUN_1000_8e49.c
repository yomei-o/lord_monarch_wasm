/* 1000:8e49 */

undefined1 FUN_1000_8e49(void)

{
  char *pcVar1;
  undefined1 uVar2;
  char in_AL;
  char in_AH;
  int in_CX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0x30);
  *pcVar1 = *pcVar1 + in_AL + in_CF;
  do {
    uVar2 = *(undefined1 *)(in_BX + -0x5946);
    in_AH = -in_AH;
    *(char *)(in_BX + 0x3e20) = in_AH;
    in_BX = in_BX + 1;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return uVar2;
}


