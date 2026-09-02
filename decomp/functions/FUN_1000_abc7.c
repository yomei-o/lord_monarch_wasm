/* 1000:abc7 */

void __cdecl16near FUN_1000_abc7(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_AX;
  uint in_DX;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2);
  uVar2 = (uint)(*(uint *)(iVar1 + 0xe) < in_AX);
  uVar3 = *(uint *)(iVar1 + 0x10) - in_DX;
  if (*(uint *)(iVar1 + 0x10) < in_DX || uVar3 < uVar2) {
    if (*(byte *)0x3c00 == unaff_SI[0xc]) {
      *(undefined2 *)0xc52c = 0xffff;
      *unaff_SI = *unaff_SI | 1;
    }
  }
  else {
    *(int *)(iVar1 + 0xe) = *(uint *)(iVar1 + 0xe) - in_AX;
    *(int *)(iVar1 + 0x10) = uVar3 - uVar2;
  }
  return;
}


