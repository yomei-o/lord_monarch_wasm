/* 1000:55d3 */

void FUN_1000_55d3(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  byte extraout_AH;
  int in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_BP;
  undefined1 *puVar7;
  undefined1 *unaff_SI;
  uint *puVar8;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  bool bVar9;
  int iStack_2;
  uint uVar6;
  
  while( true ) {
    cVar5 = in(in_DX);
    bVar9 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,in_CF);
    iStack_2 = 0x55db;
    func_0x000156b4();
    if (bVar9) break;
    func_0x0001565f();
    if (bVar9) break;
    pbVar1 = (byte *)((int)unaff_DI + in_BX + 22000);
    bVar4 = *pbVar1;
    *pbVar1 = *pbVar1 + extraout_AH;
    do {
      puVar8 = unaff_DI;
      puVar7 = unaff_SI;
      *puVar7 = (char)*puVar8;
      unaff_SI = puVar7 + 1;
      in_CX = in_CX + -1;
      unaff_DI = (uint *)((int)puVar8 + 1);
    } while (in_CX != 0);
    bVar4 = *(char *)(unaff_BP + 0xc) + -0x5f + CARRY1(bVar4,extraout_AH);
    uVar6 = CONCAT11(0x50,bVar4);
    puVar2 = (uint *)((int)puVar8 + 0x1d);
    uVar3 = *puVar2;
    *puVar2 = *puVar2 + uVar6;
    *(int *)((int)puVar8 + 0x1f) = *(int *)((int)puVar8 + 0x1f) + (uint)CARRY2(uVar3,uVar6);
    unaff_DI = (uint *)((int)puVar8 + 3);
    puVar7[0x12] = puVar7[0x12] + bVar4 + (uVar6 < *(uint *)((int)puVar8 + 1));
    in_CF = 0x74 < bVar4;
    in_DX = extraout_DX;
    in_BX = iStack_2;
  }
  unaff_SI[in_BX + 7] = unaff_SI[in_BX + 7] ^ (byte)((uint)in_CX >> 8);
  return;
}


