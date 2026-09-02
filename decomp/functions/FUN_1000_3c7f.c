/* 1000:3c7f */

void __cdecl16near FUN_1000_3c7f(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  
  *unaff_SI = *unaff_SI & 0xfb;
  uVar4 = *(uint *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 8);
  iVar5 = *(int *)(*(int *)((undefined *)&DAT_0000_12ef + (uint)unaff_SI[0xc] * 2) + 10);
  uVar1 = (uint)(*(uint *)(unaff_SI + 6) >> 1 < uVar4);
  uVar2 = -iVar5;
  if (((iVar5 == 0 && uVar1 <= uVar2) && uVar2 != uVar1) ||
     ((uVar2 == uVar1 && (*(uint *)(unaff_SI + 6) >> 1 != uVar4)))) {
    if ((byte)(unaff_SI[0xc] + 0x14) == ((undefined *)&DAT_0000_d27e)[unaff_DI]) {
      bVar7 = false;
      if (*(int *)((undefined *)&DAT_0000_e480 + unaff_DI) == 0) {
        pbVar6 = unaff_SI;
        FUN_1000_add0();
        if ((!bVar7) && (uVar4 = *(uint *)(pbVar6 + 6) >> 2, uVar4 != 0)) {
          *(uint *)(unaff_SI + 6) = uVar4;
          *(uint *)(pbVar6 + 6) = *(int *)(pbVar6 + 6) - uVar4;
          uVar4 = unaff_DI + 2U >> 1;
          uVar3 = CONCAT11((char)(uVar4 / 0x30),(char)(uVar4 % 0x30));
          *(undefined2 *)(unaff_SI + 2) = uVar3;
          *(undefined2 *)(unaff_SI + 8) = uVar3;
          *(uint *)(unaff_SI + 4) = unaff_DI + 2U;
          *unaff_SI = 0;
          unaff_SI[1] = 6;
          *(byte **)((undefined *)&DAT_0000_e480 + unaff_DI) = unaff_SI;
          unaff_SI[10] = 1;
          unaff_SI[0xc] = pbVar6[0xc];
        }
      }
    }
  }
  else if ((byte)(unaff_SI[0xc] + 0x14) == ((undefined *)&DAT_0000_d27e)[unaff_DI]) {
    if (iVar5 != 0) {
      uVar4 = 0xffff;
    }
    uVar1 = *(uint *)(unaff_SI + 6);
    if (uVar1 <= uVar4 && uVar4 - uVar1 != 0) {
      uVar4 = (uVar4 - uVar1 >> 2) + 1;
      iVar5 = uVar4 + uVar1;
      if (CARRY2(uVar4,uVar1)) {
        iVar5 = -1;
      }
      *(int *)(unaff_SI + 6) = iVar5;
    }
  }
  return;
}


