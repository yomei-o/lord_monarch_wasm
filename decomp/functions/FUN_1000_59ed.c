/* 1000:59ed */

undefined4 FUN_1000_59ed(void)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  uint in_AX;
  undefined2 uVar4;
  uint uVar5;
  int in_CX;
  uint uVar6;
  undefined2 in_DX;
  char cVar7;
  undefined1 uVar8;
  int in_BX;
  int *piVar9;
  uint uVar10;
  int unaff_BP;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  while (!(bool)in_ZF) {
    piVar9 = (int *)(in_BX + 1);
    unaff_SI = unaff_SI + 1;
    in_CX = in_CX + -1;
    if (in_CX == 0) {
      *(undefined2 *)(char *)((int)piVar9 + (int)unaff_DI) = in_DX;
      *(byte *)((int)piVar9 + unaff_SI) = *(byte *)((int)piVar9 + unaff_SI) ^ (byte)in_DX;
      uVar4 = CONCAT11((char)(in_AX >> 8),(char)in_AX + 'Q');
      uVar5 = 0xe500;
      if ((*unaff_DI != '\0') && (*unaff_DI != -0x1b)) {
        cVar7 = (char)((uint)in_DX >> 8) + (char)piVar9;
        in_DX = CONCAT11(cVar7,(byte)in_DX);
        *(char *)((int)piVar9 + unaff_SI) = *(char *)((int)piVar9 + unaff_SI) - cVar7;
        uVar5 = 0x6a;
      }
      LOCK();
      cVar7 = *(char *)((int)piVar9 + unaff_SI);
      *(char *)((int)piVar9 + unaff_SI) = (char)in_DX;
      uVar8 = (undefined1)((uint)in_DX >> 8);
      UNLOCK();
      *piVar9 = *piVar9 + -1;
      uVar10 = (uint)((int)piVar9 * 3) >> 1;
      uVar6 = 0xf000;
      if (((int)piVar9 * 3 & 1U) != 0) {
        uVar5 = uVar5 << 4;
        uVar6 = 0xf;
      }
      *(char *)(unaff_BP + (int)piVar9) = *(char *)(unaff_BP + (int)piVar9) + (char)uVar6;
      *(uint *)(uVar10 + (int)piVar9) = *(uint *)(uVar10 + (int)piVar9) & uVar6;
      puVar1 = (uint *)(uVar10 + (int)piVar9);
      *puVar1 = *puVar1 | uVar5;
      if (0 < (int)*puVar1) {
        cVar3 = *(char *)(uVar10 + 0x77);
        piVar2 = (int *)((int)piVar9 + uVar10 + 0x1c4d);
        *piVar2 = *piVar2 - (int)piVar9;
        return CONCAT22(CONCAT11(uVar8,cVar7 + cVar3),uVar4);
      }
      return CONCAT22(CONCAT11(uVar8,cVar7),uVar4);
    }
    in_AX = *(uint *)((int)piVar9 + unaff_SI);
    if ((in_AX & 0xfff) == 0) break;
    in_BX = in_BX + 2;
    in_AX = *(uint *)(in_BX + unaff_SI);
    in_ZF = (in_AX & 0xfff0) == 0;
  }
  return CONCAT22(in_DX,in_AX);
}


