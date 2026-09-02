/* 1000:8940 */

void FUN_1000_8940(void)

{
  byte *pbVar1;
  byte bVar2;
  byte in_CL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  byte bVar3;
  
  pbVar1 = (byte *)0xcceb;
  bVar2 = *pbVar1;
  bVar3 = *pbVar1;
  *pbVar1 = bVar3 + in_CL + in_CF;
  *(int *)0x4402 = in_BX;
  *(char *)(in_BX + unaff_SI) =
       *(char *)(in_BX + unaff_SI) + '\x1e' + (CARRY1(bVar2,in_CL) || CARRY1(bVar3 + in_CL,in_CF));
  return;
}


