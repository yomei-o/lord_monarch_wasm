/* 1000:c6d1 */

undefined4 __cdecl16near FUN_1000_c6d1(void)

{
  uint uVar1;
  int in_AX;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)&DAT_0000_d274;
  *(uint *)0xd278 = in_AX * 0x10 | uVar1;
  *(uint *)&DAT_0000_d27c = in_AX * -0x10 + 0x1900U | uVar1;
  return CONCAT22(in_DX,in_AX);
}


