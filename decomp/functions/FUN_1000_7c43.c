/* 1000:7c43 */

undefined4 FUN_1000_7c43(undefined2 param_1)

{
  undefined2 in_AX;
  int iVar1;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = 0x6033;
  do {
    if ((*unaff_SI & 0x80) != 0) break;
    unaff_SI = unaff_SI + 0x10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(param_1,in_AX);
}


