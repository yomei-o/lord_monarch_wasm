/* 1000:3892 */

undefined4 FUN_1000_3892(undefined2 param_1)

{
  byte *pbVar1;
  int in_AX;
  undefined2 in_DX;
  char cVar2;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  undefined2 in_stack_00000000;
  
  cVar2 = (char)((uint)in_DX >> 8) + *(char *)(in_BX + unaff_SI);
  *(char *)(unaff_DI + 0x72) = *(char *)(unaff_DI + 0x72) - cVar2;
  pbVar1 = (byte *)(unaff_BP + unaff_DI + -0x178e);
  *pbVar1 = *pbVar1 | (byte)(CONCAT22(CONCAT11(cVar2,(char)in_DX),(in_AX + 0x5556) - (uint)in_CF) %
                            (ulong)*(uint *)(unaff_SI + 0x820));
  *(int *)(unaff_BP + unaff_DI) = *(int *)(unaff_BP + unaff_DI) >> 0x10;
  return CONCAT22(param_1,in_stack_00000000);
}


