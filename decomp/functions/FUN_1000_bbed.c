/* 1000:bbed */

undefined4 __cdecl16near FUN_1000_bbed(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte extraout_AL;
  uint in_AX;
  byte bVar4;
  byte extraout_AH;
  int iVar5;
  undefined2 in_DX;
  uint *in_BX;
  uint uVar6;
  byte *unaff_SI;
  byte *pbVar7;
  undefined2 unaff_DS;
  undefined2 local_8;
  uint local_4;
  
  pbVar7 = (byte *)&DAT_0000_c800;
  bVar3 = (byte)in_AX;
  bVar4 = 0x80;
  iVar5 = 0x40;
  uVar6 = 0x1f1;
  uVar1 = *(uint *)(unaff_SI + 6);
  do {
    if (((((*pbVar7 & bVar4) == 0) && (bVar3 == pbVar7[0xc])) &&
        (in_BX = (uint *)(CONCAT11((char)((uint)in_BX >> 8),pbVar7[10]) & 0xff0f),
        (char)in_BX == '\x02')) &&
       ((uVar1 <= *(uint *)(pbVar7 + 6) && (!CARRY2(uVar1,*(uint *)(pbVar7 + 6)))))) {
      FUN_1000_9b34();
      uVar2 = *in_BX;
      bVar3 = extraout_AL;
      bVar4 = extraout_AH;
      if ((uVar2 != 1) && (uVar2 <= uVar6)) {
        uVar6 = uVar2;
        unaff_SI = pbVar7;
      }
    }
    pbVar7 = pbVar7 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_8 = in_DX;
  local_4 = in_AX;
  if (uVar6 < 0x1f0) {
    local_8 = *(undefined2 *)(unaff_SI + 8);
    local_4 = uVar6;
  }
  return CONCAT22(local_8,local_4);
}


