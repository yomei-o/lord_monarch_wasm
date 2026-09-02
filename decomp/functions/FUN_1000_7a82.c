/* 1000:7a82 */

void FUN_1000_7a82(void)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int in_BX;
  byte *unaff_SI;
  int *piVar8;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  iVar4 = in_BX * 2;
  piVar8 = (int *)0xc4f8;
  uVar7 = *(uint *)(iVar4 + 0x22f5);
  iVar6 = 0xc;
  do {
    iVar5 = iVar6;
    uVar3 = uVar7 & 1;
    uVar7 = uVar7 >> 1;
    uVar3 = (uint)(uVar3 != 0);
    piVar1 = piVar8;
    piVar8 = piVar8 + 1;
    *piVar1 = -uVar3;
    iVar6 = iVar5 + -1;
  } while (iVar6 != 0);
  *piVar8 = -1;
  if (uVar3 != 0) {
    iVar6 = *(uint *)(iVar4 + 0x10) - *(uint *)(iVar4 + -0x5409);
    if (*(uint *)(iVar4 + 0x10) < *(uint *)(iVar4 + -0x5409) || iVar6 == 0) {
      if (*(byte *)0x3c00 == unaff_SI[0xc]) {
        *(undefined2 *)0xc52c = 0xffff;
        *unaff_SI = *unaff_SI | 1;
      }
    }
    else {
      *(int *)(iVar4 + 0xe) = iVar5;
      *(int *)(iVar4 + 0x10) = iVar6 + -1;
    }
    return;
  }
  bVar2 = unaff_SI[iVar4];
  unaff_SI[iVar4] = bVar2 << 6 | bVar2 >> 3;
  return;
}


