/* 1000:6e99 */

uint __cdecl16near FUN_1000_6e99(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  uVar3 = *(uint *)(*(int *)0x3e94 + 0x1a);
  do {
    uVar2 = uVar3;
    uVar1 = uVar2 * 3;
    uVar3 = *(uint *)((uVar1 >> 1) + *(int *)0x3e86);
    if ((uVar1 & 1) == 0) {
      uVar3 = uVar3 & 0xfff;
    }
    else {
      uVar3 = uVar3 >> 4;
    }
  } while (uVar3 < 0xff7);
  return uVar2;
}


