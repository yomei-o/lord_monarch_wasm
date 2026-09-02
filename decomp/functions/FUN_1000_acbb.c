/* 1000:acbb */

undefined4 __cdecl16near FUN_1000_acbb(void)

{
  int iVar1;
  undefined2 in_AX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_DX;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined2 unaff_DS;
  
  iVar4 = *(int *)0xce70;
  if (iVar4 != 0) {
    uVar3 = 0;
    piVar7 = (int *)&DAT_0000_cc00;
    do {
      piVar6 = piVar7;
      iVar5 = uVar3 + 0xc80;
      if (0xf37f < uVar3) {
        iVar5 = -1;
      }
      iVar1 = *piVar6;
      piVar6[2] = iVar5 - iVar1;
      uVar2 = (uint)(((ulong)((piVar6[1] & 0xffU) * 10 + ((uint)piVar6[1] >> 8)) *
                     (ulong)(uint)(iVar5 - iVar1)) / 1000);
      piVar6[3] = uVar2;
      piVar6[4] = 0;
      iVar5 = uVar2 - uVar3;
      if (uVar2 < uVar3) {
        piVar6[4] = -1;
        iVar5 = -iVar5;
      }
      piVar6[5] = iVar5;
      piVar7 = piVar6 + 6;
      iVar4 = iVar4 + -1;
      uVar3 = uVar2;
    } while (iVar4 != 0);
    if ((*(int *)0xce70 == 0x33) && (*piVar7 != 0)) {
      iVar4 = uVar2 + 0xc80;
      if (0xf37f < uVar2) {
        iVar4 = -1;
      }
      iVar5 = *piVar7;
      piVar6[8] = iVar4 - iVar5;
      uVar3 = (uint)(((ulong)((piVar6[7] & 0xffU) * 10 + ((uint)piVar6[7] >> 8)) *
                     (ulong)(uint)(iVar4 - iVar5)) / 1000);
      piVar6[9] = uVar3;
      piVar6[10] = 0;
      iVar4 = uVar3 - uVar2;
      if (uVar3 < uVar2) {
        piVar6[10] = -1;
        iVar4 = -iVar4;
      }
      piVar6[0xb] = iVar4;
    }
  }
  return CONCAT22(in_DX,in_AX);
}


