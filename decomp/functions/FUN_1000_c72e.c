/* 1000:c72e */

undefined4 __cdecl16near FUN_1000_c72e(void)

{
  uint uVar1;
  int in_AX;
  uint uVar2;
  undefined2 in_DX;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)&DAT_0000_d274;
  *(int *)0xd276 = in_AX * 0x28;
  *(undefined2 *)&DAT_0000_d27a = 0;
  uVar2 = in_AX * -0x10 + 0x1920;
  if (0x1900 < uVar2) {
    uVar2 = 0x1900;
  }
  *(uint *)0xd278 = uVar2 | uVar1;
  *(uint *)&DAT_0000_d27c = in_AX * 0x10 | uVar1;
  return CONCAT22(in_DX,in_AX);
}


