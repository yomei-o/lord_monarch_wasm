/* 1000:12c2 */

undefined4 FUN_1000_12c2(undefined2 param_1)

{
  int iVar1;
  undefined2 in_CX;
  int in_BX;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_DS;
  char in_CF;
  
  *unaff_DI = (*unaff_DI - (char)in_BX) - in_CF;
  iVar1 = (int)*(char *)(unaff_SI + 8) + *(int *)(in_BX + 0x244d);
  return CONCAT22(param_1,CONCAT11((byte)((uint)iVar1 >> 8) | (byte)((uint)in_CX >> 8),(char)iVar1))
  ;
}


