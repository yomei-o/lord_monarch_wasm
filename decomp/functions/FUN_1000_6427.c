/* 1000:6427 */

void FUN_1000_6427(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  byte bVar3;
  int in_AX;
  byte bVar4;
  uint in_CX;
  uint uVar5;
  int in_BX;
  int unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar2 = *(undefined2 *)(in_BX + unaff_SI);
  do {
    bVar4 = (byte)((uint)in_AX >> 8);
    *unaff_DI = bVar4;
    in_CX = in_CX - 1;
    if (in_CX == 0) goto LAB_1000_6450;
    bVar3 = (byte)in_AX;
    in_AX = CONCAT11(bVar4 >> 1 | bVar4 << 7,bVar3);
  } while (!(bool)(bVar4 & 1));
  unaff_DI = unaff_DI + 1;
  uVar5 = in_CX >> 3;
  if (uVar5 != 0) {
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      pbVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *pbVar1 = bVar3;
    }
  }
  for (uVar5 = in_CX & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    bVar4 = (byte)((uint)in_AX >> 8);
    *unaff_DI = bVar4;
    in_AX = (uint)(byte)(bVar4 >> 1 | bVar4 << 7) << 8;
  }
LAB_1000_6450:
  if (unaff_SI + in_BX == 0) {
    unaff_DI[in_BX + 0x6e] = unaff_DI[in_BX + 0x6e] | (byte)uVar2;
    return;
  }
  return;
}


