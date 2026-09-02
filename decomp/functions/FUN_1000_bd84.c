/* 1000:bd84 */

undefined4 __cdecl16near FUN_1000_bd84(void)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  byte *unaff_SI;
  byte *pbVar4;
  undefined2 unaff_DS;
  undefined4 uVar5;
  
  pbVar4 = (byte *)&DAT_0000_c800;
  iVar3 = 0x40;
  uVar5 = FUN_1000_a61d();
  uVar1 = *(uint *)(unaff_SI + 6);
  do {
    if ((((*pbVar4 & (byte)((ulong)uVar5 >> 0x18)) == 0) && (unaff_SI != pbVar4)) &&
       ((byte)((ulong)uVar5 >> 0x10) == pbVar4[0xb])) {
      if ((byte)((ulong)uVar5 >> 8) == pbVar4[0xc]) {
LAB_1000_bdbb:
        **(undefined2 **)(pbVar4 + 4) = 0xffff;
      }
      else if ((byte)uVar5 == pbVar4[0xc]) {
        if (CARRY2(*(uint *)(pbVar4 + 6),uVar1)) goto LAB_1000_bdbb;
      }
      else if ((CARRY2(*(uint *)(pbVar4 + 6) >> 1,*(uint *)(pbVar4 + 6))) ||
              (uVar1 <= (*(uint *)(pbVar4 + 6) >> 1) + *(uint *)(pbVar4 + 6))) {
        puVar2 = *(undefined2 **)(pbVar4 + 4);
        *puVar2 = 0xffff;
        puVar2[-0x30] = 0xffff;
        puVar2[0x30] = 0xffff;
        puVar2[-1] = 0xffff;
        puVar2[1] = 0xffff;
      }
    }
    pbVar4 = pbVar4 + 0x10;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return CONCAT22(in_DX,in_AX);
    }
  } while( true );
}


