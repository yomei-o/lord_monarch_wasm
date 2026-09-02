/* 1000:46d3 */

undefined4 __cdecl16near FUN_1000_46d3(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  byte bVar3;
  uint uVar2;
  int iVar4;
  char cVar5;
  undefined2 in_DX;
  uint uVar6;
  int unaff_SI;
  byte *pbVar7;
  byte *unaff_DI;
  undefined2 unaff_DS;
  bool bVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  FUN_1000_4814();
  uVar1 = FUN_1000_a61d();
  pbVar7 = (byte *)&DAT_0000_c800;
  iVar4 = 0x40;
  uVar6 = 0xffff;
  do {
    if ((((((*pbVar7 & 0x80) == 0) && ((pbVar7[10] & 0x20) != 0)) && ((byte)uVar1 != pbVar7[0xc]))
        && ((bVar3 = (byte)((uint)uVar1 >> 8), bVar8 = bVar3 < pbVar7[0xc], bVar3 != pbVar7[0xc] &&
            (uVar2 = FUN_1000_aaae(), !bVar8)))) && (uVar2 < uVar6)) {
      uVar6 = uVar2;
      unaff_DI = pbVar7;
    }
    pbVar7 = pbVar7 + 0x10;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((uVar6 < 0x1f0) && (uVar6 * 2 <= *(uint *)(unaff_SI + 6))) {
    if ((byte)(unaff_DI[0xc] + 0x14) == ((undefined *)&DAT_0000_d27e)[*(int *)(unaff_DI + 4)]) {
      uVar6 = *(uint *)(unaff_DI + 6);
      if (((char)(((int)uVar6 < 0) + CARRY2(uVar6 * 2,uVar6)) != '\0') ||
         (uVar9 = uVar6 * 3 == *(uint *)(unaff_SI + 6), *(uint *)(unaff_SI + 6) <= uVar6 * 3)) {
        if ((uVar6 >> 1) + (uVar6 >> 2) < *(uint *)(unaff_SI + 6)) {
          uVar1 = *(undefined2 *)
                   (*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_DI[0xc] * 2) + 2);
          cVar5 = (char)uVar1 + '\x02';
          uVar10 = cVar5 == '\0';
          *(undefined2 *)(unaff_SI + 8) = CONCAT11((char)((uint)uVar1 >> 8),cVar5);
          FUN_1000_b78c();
          uVar9 = FUN_1000_c0bd();
          if (!(bool)uVar10) {
            *(undefined1 *)(unaff_SI + 0xb) = uVar9;
            *(undefined1 *)(unaff_SI + 10) = 2;
            *(undefined1 *)(unaff_SI + 0xf) = 4;
            return CONCAT22(in_DX,in_AX);
          }
        }
        goto LAB_1000_47e6;
      }
    }
    else {
      uVar9 = *(uint *)(unaff_DI + 6) == *(uint *)(unaff_SI + 6);
      if (*(uint *)(unaff_SI + 6) <= *(uint *)(unaff_DI + 6)) {
        uVar10 = unaff_DI[0xc] == 0;
        *(undefined2 *)(unaff_SI + 8) =
             *(undefined2 *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_DI[0xc] * 2) + 2);
        FUN_1000_b78c();
        uVar9 = FUN_1000_c0bd();
        if (!(bool)uVar10) {
          *(undefined1 *)(unaff_SI + 0xb) = uVar9;
          *(undefined1 *)(unaff_SI + 10) = 2;
          *(undefined1 *)(unaff_SI + 0xf) = 4;
          return CONCAT22(in_DX,in_AX);
        }
        goto LAB_1000_47e6;
      }
    }
    *(undefined2 *)(unaff_SI + 8) = *(undefined2 *)(unaff_DI + 8);
    FUN_1000_b78c();
    uVar10 = FUN_1000_c0bd();
    if (!(bool)uVar9) {
      *(undefined1 *)(unaff_SI + 0xb) = uVar10;
      *(undefined1 *)(unaff_SI + 10) = 1;
      *(undefined1 *)(unaff_SI + 0xf) = 4;
      return CONCAT22(in_DX,in_AX);
    }
  }
LAB_1000_47e6:
  return CONCAT22(in_DX,in_AX);
}


