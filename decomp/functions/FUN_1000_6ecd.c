/* 1000:6ecd */

uint __cdecl16near FUN_1000_6ecd(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  iVar4 = *(int *)0x3e86;
  uVar3 = 2;
  iVar2 = 0x262;
  while( true ) {
    iVar4 = iVar4 + 1;
    if ((*(uint *)(uVar3 + iVar4) & 0xfff) == 0) {
      return uVar3;
    }
    uVar1 = *(uint *)(uVar3 + 1 + iVar4);
    if ((uVar1 & 0xfff0) == 0) break;
    uVar3 = uVar3 + 2;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      *(undefined1 *)0x3e92 = 0xd0;
      return uVar1;
    }
  }
  return uVar3 + 1;
}


