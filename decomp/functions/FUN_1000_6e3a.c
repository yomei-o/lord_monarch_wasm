/* 1000:6e3a */

uint __cdecl16near FUN_1000_6e3a(void)

{
  int in_AX;
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(((uint)(in_AX * 3) >> 1) + *(int *)0x3e86);
  if ((in_AX * 3 & 1U) == 0) {
    uVar1 = uVar1 & 0xfff;
  }
  else {
    uVar1 = uVar1 >> 4;
  }
  if ((1 < uVar1) && (0xff6 < uVar1)) {
    uVar1 = 0xffff;
  }
  return uVar1;
}


