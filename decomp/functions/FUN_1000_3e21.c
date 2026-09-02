/* 1000:3e21 */

undefined4 __cdecl16near FUN_1000_3e21(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 in_AX;
  int iVar4;
  undefined2 in_DX;
  uint uVar5;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  pbVar3 = *(byte **)((undefined *)&DAT_0000_e47e + in_BX);
  if ((((pbVar3 == (byte *)0x0) || (*(byte *)(unaff_SI + 0xc) != pbVar3[0xc])) ||
      ((*pbVar3 & 2) != 0)) ||
     (iVar4 = *(uint *)(unaff_SI + 6) + *(uint *)(pbVar3 + 6),
     CARRY2(*(uint *)(unaff_SI + 6),*(uint *)(pbVar3 + 6)))) goto LAB_1000_3e94;
  bVar1 = *(byte *)(unaff_SI + 10);
  bVar2 = pbVar3[10];
  if ((bVar1 & 0x20) == 0) {
    if ((bVar2 & 0x20) == 0) {
      if ((CONCAT11(bVar1,bVar2) & 0x1010) != 0) {
        if ((bVar2 & 0x10) == 0) goto LAB_1000_3e86;
        if ((bVar1 & 0x10) == 0) goto LAB_1000_3e7d;
      }
      uVar5 = CONCAT11(bVar1,bVar2) & 0xf0f;
      if (uVar5 != 0x303) {
        if ((char)(uVar5 >> 8) == '\x03') goto LAB_1000_3e7d;
        if ((char)uVar5 == '\x03') goto LAB_1000_3e86;
      }
      if (*(uint *)(pbVar3 + 6) <= *(uint *)(unaff_SI + 6)) goto LAB_1000_3e86;
    }
LAB_1000_3e7d:
    *(int *)(pbVar3 + 6) = iVar4;
    FUN_1000_a9ca();
  }
  else {
LAB_1000_3e86:
    *(int *)(unaff_SI + 6) = iVar4;
    FUN_1000_a9ca();
  }
LAB_1000_3e94:
  return CONCAT22(in_DX,in_AX);
}


