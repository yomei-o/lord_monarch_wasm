/* 1000:9632 */

uint __cdecl16near FUN_1000_9632(void)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined2 unaff_ES;
  
  puVar4 = (uint *)0x500;
  iVar2 = 0x128;
  uVar1 = in_AX;
  do {
    iVar3 = 0x28;
    do {
      *puVar4 = *puVar4 & uVar1;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = (uVar1 >> 1 | (uint)((uVar1 & 1) != 0) << 0xf) >> 1 |
            (uint)((uVar1 >> 1 & 1) != 0) << 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}


