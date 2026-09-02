/* 1000:55c6 */

void FUN_1000_55c6(void)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  char cVar5;
  uint in_AX;
  byte extraout_AH;
  int in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_BP;
  undefined1 *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  int iStack_2;
  
  while( true ) {
    puVar2 = unaff_DI + 0xe;
    uVar4 = *puVar2;
    *puVar2 = *puVar2 + in_AX;
    unaff_DI[0xf] = unaff_DI[0xf] + (uint)CARRY2(uVar4,in_AX);
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    unaff_SI[0x11] = unaff_SI[0x11] + (byte)in_AX + (in_AX < *puVar2);
    cVar5 = in(in_DX);
    bVar6 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < (byte)in_AX);
    iStack_2 = 0x55db;
    func_0x000156b4();
    if (bVar6) break;
    func_0x0001565f();
    if (bVar6) break;
    pbVar1 = (byte *)((int)unaff_DI + in_BX + 22000);
    bVar3 = *pbVar1;
    *pbVar1 = *pbVar1 + extraout_AH;
    do {
      *unaff_SI = (char)*unaff_DI;
      unaff_SI = unaff_SI + 1;
      unaff_DI = (uint *)((int)unaff_DI + 1);
      in_CX = in_CX + -1;
    } while (in_CX != 0);
    in_AX = CONCAT11(0x50,*(char *)(unaff_BP + 0xc) + -0x5f + CARRY1(bVar3,extraout_AH));
    in_DX = extraout_DX;
    in_BX = iStack_2;
  }
  unaff_SI[in_BX + 7] = unaff_SI[in_BX + 7] ^ (byte)((uint)in_CX >> 8);
  return;
}


