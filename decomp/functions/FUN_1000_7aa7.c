/* 1000:7aa7 */

void FUN_1000_7aa7(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  uint in_CX;
  uint in_DX;
  int in_BX;
  undefined1 *unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  
  uVar3 = CONCAT11((char)((uint)in_AX >> 8),*unaff_SI);
  uVar2 = uVar3 + 0x21e8;
  uVar4 = uVar2 + in_CF;
  pbVar1 = unaff_SI + 1;
  *pbVar1 = *pbVar1 << 1 | (0xde17 < uVar3 || CARRY2(uVar2,(uint)in_CF));
  *(char *)(in_BX + 0xe) = *(char *)(in_BX + 0xe) + -1;
  uVar2 = (uint)(in_CX < uVar4);
  uVar3 = *(uint *)(in_BX + 0x10) - in_DX;
  if (*(uint *)(in_BX + 0x10) < in_DX || uVar3 < uVar2) {
    if (*(char *)0x3c00 == unaff_SI[0xd]) {
      *(undefined2 *)0xc52c = 0xffff;
      pbVar1 = unaff_SI + 1;
      *pbVar1 = *pbVar1 | 1;
    }
  }
  else {
    *(int *)(in_BX + 0xe) = in_CX - uVar4;
    *(int *)(in_BX + 0x10) = uVar3 - uVar2;
  }
  return;
}


