/* 1000:ab3e */

undefined4 __cdecl16near FUN_1000_ab3e(void)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  undefined2 in_AX;
  int iVar4;
  undefined2 in_DX;
  uint uVar5;
  int in_BX;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  FUN_1000_9b34();
  bVar2 = ((undefined *)&DAT_0000_d27e)[in_BX];
  iVar6 = 0;
  if (((((bVar2 != 0) && ((iVar6 = 1, bVar2 < 8 || (0xb < bVar2)))) &&
       ((iVar6 = 2, bVar2 < 0xc || (0xf < bVar2)))) &&
      ((((((iVar6 = 3, bVar2 == 0 || (4 < bVar2)) && (iVar6 = 4, bVar2 != 0x7b)) &&
         ((iVar6 = 5, bVar2 < 0x20 || (0x2f < bVar2)))) &&
        ((iVar6 = 6, bVar2 != 5 && (iVar6 = 7, bVar2 != 0x7a)))) &&
       ((iVar6 = 8, bVar2 < 0x30 || (0x5f < bVar2)))))) &&
     ((iVar6 = 9, bVar2 < 0x14 || (0x17 < bVar2)))) {
    iVar6 = 10;
  }
  uVar5 = *(uint *)(iVar6 * 4 + 0x22f5);
  iVar4 = 0xc;
  piVar8 = (int *)0xc4f8;
  do {
    piVar7 = piVar8;
    uVar3 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    *piVar7 = -(uint)(uVar3 != 0);
    iVar4 = iVar4 + -1;
    piVar8 = piVar7 + 1;
  } while (iVar4 != 0);
  piVar8 = piVar7 + 2;
  piVar7[1] = -1;
  uVar5 = *(uint *)(iVar6 * 4 + 0x22f7);
  iVar6 = 0xc;
  do {
    uVar3 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    piVar1 = piVar8;
    piVar8 = piVar8 + 1;
    *piVar1 = -(uint)(uVar3 != 0);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *piVar8 = -1;
  return CONCAT22(in_DX,in_AX);
}


