/* 1000:bd3b */

undefined4 __cdecl16near FUN_1000_bd3b(void)

{
  uint uVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  byte *unaff_SI;
  byte *pbVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  pbVar3 = (byte *)&DAT_0000_c800;
  iVar2 = 0x40;
  uVar4 = FUN_1000_a61d();
  uVar1 = *(uint *)(unaff_SI + 6);
  do {
    if (((((*pbVar3 & (byte)((ulong)uVar4 >> 0x18)) == 0) && (unaff_SI != pbVar3)) &&
        ((byte)((ulong)uVar4 >> 0x10) == pbVar3[0xb])) &&
       (((byte)((ulong)uVar4 >> 8) == pbVar3[0xc] ||
        (((byte)uVar4 == pbVar3[0xc] && (CARRY2(*(uint *)(pbVar3 + 6),uVar1))))))) {
      **(undefined2 **)(pbVar3 + 4) = 0xffff;
    }
    pbVar3 = pbVar3 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}


