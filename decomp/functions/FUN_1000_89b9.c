/* 1000:89b9 */

void FUN_1000_89b9(void)

{
  byte *pbVar1;
  byte bVar2;
  int in_AX;
  int iVar3;
  char extraout_AH;
  uint uVar4;
  byte bVar5;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  char cVar6;
  char cVar7;
  byte in_AF;
  byte bVar8;
  undefined4 uVar9;
  
  *(int *)(unaff_BP + unaff_SI) = *(int *)(unaff_BP + unaff_SI) + in_AX + (uint)in_CF;
  bVar5 = 9 < ((byte)in_AX & 0xf) | in_AF;
  pbVar1 = (byte *)(unaff_BP + 0x2f35);
  bVar2 = *pbVar1 + (byte)in_BX;
  cVar6 = CARRY1(*pbVar1,(byte)in_BX) || CARRY1(bVar2,bVar5);
  *pbVar1 = bVar2 + bVar5;
  FUN_1000_5bbb();
  uVar9 = FUN_1000_a3c1();
  cVar6 = (char)uVar9 + *(char *)0x2f35 + cVar6;
  out((int)((ulong)uVar9 >> 0x10),cVar6);
  iVar3 = CONCAT11((char)((ulong)uVar9 >> 8),cVar6) + -1;
  bVar2 = (byte)iVar3;
  bVar5 = 9 < (bVar2 & 0xf) | bVar5;
  *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)in_BX + bVar5;
  bVar8 = ((CONCAT11((char)((uint)iVar3 >> 8) - bVar5,bVar2 + bVar5 * -6) & 0xff0f) + 0xbf2f &
          0x1000) != 0;
  cVar6 = -0x41;
  func_0x0001f1ba();
  bVar5 = cVar6 + (char)extraout_DX;
  *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)((uint)extraout_DX >> 8);
  uVar4 = CONCAT11(extraout_AH - bVar8,bVar8 * -6) & 0xff0f;
  pbVar1 = (byte *)(unaff_BP + 0x2f45);
  bVar2 = *pbVar1 + (byte)in_BX;
  cVar7 = CARRY1(*pbVar1,(byte)in_BX) || CARRY1(bVar2,bVar8);
  *pbVar1 = bVar2 + bVar8;
  func_0x00015bb1();
  cVar6 = func_0x0001ebb7();
  iVar3 = uVar4 + 1;
  pbVar1 = (byte *)(unaff_BP + iVar3 + -0x4167);
  *pbVar1 = *pbVar1 | (cVar6 + *(char *)(unaff_BP + uVar4) + cVar7) - 1U;
  pbVar1 = (byte *)(unaff_BP + -1 + iVar3);
  *pbVar1 = *pbVar1 & (byte)in_BX;
  iVar3 = in_BX;
  func_0x00015ba8();
  FUN_1000_20ae();
  *(byte *)(iVar3 + 0x2f75) = *(byte *)(iVar3 + 0x2f75) | 8;
  *(byte *)(unaff_BP + 0x5554) = *(byte *)(unaff_BP + 0x5554) & (byte)iVar3;
  FUN_1000_5ba1();
  FUN_1000_33a7();
  pbVar1 = (byte *)(unaff_BP + -1 + in_BX);
  *pbVar1 = *pbVar1 | (byte)((uint)iVar3 >> 8);
  *(byte *)(iVar3 + 0x3f5d) = *(byte *)(iVar3 + 0x3f5d) & bVar5;
  return;
}


