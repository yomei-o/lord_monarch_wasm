/* 1000:59f3 */

undefined4 FUN_1000_59f3(void)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  undefined2 in_AX;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 in_DX;
  char cVar7;
  undefined1 uVar8;
  int *in_BX;
  uint uVar9;
  int unaff_BP;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined2 *)(char *)((int)in_BX + (int)unaff_DI) = in_DX;
  *(byte *)((int)in_BX + unaff_SI) = *(byte *)((int)in_BX + unaff_SI) ^ (byte)in_DX;
  uVar4 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + 'Q');
  uVar5 = 0xe500;
  if ((*unaff_DI != '\0') && (*unaff_DI != -0x1b)) {
    cVar7 = (char)((uint)in_DX >> 8) + (char)in_BX;
    in_DX = CONCAT11(cVar7,(byte)in_DX);
    *(char *)((int)in_BX + unaff_SI) = *(char *)((int)in_BX + unaff_SI) - cVar7;
    uVar5 = 0x6a;
  }
  LOCK();
  cVar7 = *(char *)((int)in_BX + unaff_SI);
  *(char *)((int)in_BX + unaff_SI) = (char)in_DX;
  uVar8 = (undefined1)((uint)in_DX >> 8);
  UNLOCK();
  *in_BX = *in_BX + -1;
  uVar9 = (uint)((int)in_BX * 3) >> 1;
  uVar6 = 0xf000;
  if (((int)in_BX * 3 & 1U) != 0) {
    uVar5 = uVar5 << 4;
    uVar6 = 0xf;
  }
  *(char *)(unaff_BP + (int)in_BX) = *(char *)(unaff_BP + (int)in_BX) + (char)uVar6;
  *(uint *)(uVar9 + (int)in_BX) = *(uint *)(uVar9 + (int)in_BX) & uVar6;
  puVar1 = (uint *)(uVar9 + (int)in_BX);
  *puVar1 = *puVar1 | uVar5;
  if (0 < (int)*puVar1) {
    cVar3 = *(char *)(uVar9 + 0x77);
    piVar2 = (int *)((int)in_BX + uVar9 + 0x1c4d);
    *piVar2 = *piVar2 - (int)in_BX;
    return CONCAT22(CONCAT11(uVar8,cVar7 + cVar3),uVar4);
  }
  return CONCAT22(CONCAT11(uVar8,cVar7),uVar4);
}


