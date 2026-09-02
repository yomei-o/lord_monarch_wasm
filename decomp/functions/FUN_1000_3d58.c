/* 1000:3d58 */

uint FUN_1000_3d58(void)

{
  byte *pbVar1;
  int in_AX;
  byte in_CL;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  pbVar1 = (byte *)(unaff_BP + unaff_DI + 0xc4e);
  *pbVar1 = *pbVar1 | in_CL;
  return in_AX + 1U | 0x8b;
}


