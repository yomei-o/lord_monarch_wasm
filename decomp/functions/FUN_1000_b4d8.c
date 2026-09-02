/* 1000:b4d8 */

void __cdecl16near FUN_1000_b4d8(void)

{
  uint uVar1;
  uint in_AX;
  uint in_DX;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 0x10);
  if ((uVar1 < in_DX ||
       uVar1 - in_DX <
       (uint)(*(uint *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 0xe) <
             in_AX)) && (*(byte *)0x3c00 == unaff_SI[0xc])) {
    *(undefined2 *)0xc52c = 0xffff;
    *unaff_SI = *unaff_SI | 1;
  }
  return;
}


