/* 1000:6f1f */

uint __cdecl16near FUN_1000_6f1f(void)

{
  uint *puVar1;
  int iVar2;
  uint in_AX;
  uint uVar3;
  uint uVar4;
  int in_BX;
  uint uVar5;
  undefined2 unaff_DS;
  
  uVar3 = in_AX & 0xfff;
  uVar5 = (uint)(in_BX * 3) >> 1;
  uVar4 = 0xf000;
  if ((in_BX * 3 & 1U) != 0) {
    uVar3 = in_AX << 4;
    uVar4 = 0xf;
  }
  iVar2 = *(int *)0x3e86;
  puVar1 = (uint *)(uVar5 + iVar2);
  *puVar1 = *puVar1 & uVar4;
  puVar1 = (uint *)(uVar5 + iVar2);
  *puVar1 = *puVar1 | uVar3;
  return in_AX;
}


