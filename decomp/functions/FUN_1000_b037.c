/* 1000:b037 */

undefined4 __cdecl16near FUN_1000_b037(void)

{
  byte bVar1;
  undefined2 in_AX;
  byte bVar4;
  int iVar2;
  undefined2 uVar3;
  undefined1 uVar5;
  byte bVar6;
  undefined2 in_DX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar1 = ((undefined *)&DAT_0000_d21e)[unaff_DI];
  bVar4 = (byte)((uint)in_AX >> 8);
  bVar6 = (byte)in_AX;
  if (bVar1 < 0x30) {
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = (uint)bVar4 << 8;
      goto LAB_1000_b0ff;
    }
    bVar1 = ((undefined *)&DAT_0000_d1be)[unaff_DI];
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,0x80);
      goto LAB_1000_b0ff;
    }
  }
  bVar1 = ((undefined *)&DAT_0000_d2de)[unaff_DI];
  if (bVar1 < 0x30) {
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,2);
      goto LAB_1000_b0ff;
    }
    bVar1 = ((undefined *)&DAT_0000_d33e)[unaff_DI];
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,0x82);
      goto LAB_1000_b0ff;
    }
  }
  bVar1 = ((undefined *)&DAT_0000_d27c)[unaff_DI];
  if (bVar1 < 0x30) {
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,1);
      goto LAB_1000_b0ff;
    }
    bVar1 = ((undefined *)&DAT_0000_d27a)[unaff_DI];
    if (((bVar1 != bVar4) && (bVar1 != bVar6)) && ((byte)(bVar1 - 8) < 4)) {
      iVar2 = CONCAT11(bVar4,0x81);
      goto LAB_1000_b0ff;
    }
  }
  bVar1 = ((undefined *)&DAT_0000_d280)[unaff_DI];
  uVar3 = CONCAT11(bVar4,bVar1);
  if (bVar1 < 0x30) {
    if (((bVar1 == bVar4) || (bVar1 == bVar6)) ||
       (uVar3 = CONCAT11(bVar4,bVar1 - 8), 3 < (byte)(bVar1 - 8))) {
      bVar1 = ((undefined *)&DAT_0000_d282)[unaff_DI];
      uVar5 = (undefined1)((uint)uVar3 >> 8);
      uVar3 = CONCAT11(uVar5,bVar1);
      if (((bVar1 == bVar4) || (bVar1 == bVar6)) ||
         (uVar3 = CONCAT11(uVar5,bVar1 - 8), 3 < (byte)(bVar1 - 8))) goto LAB_1000_b0fc;
      iVar2 = CONCAT11(uVar5,0x83);
    }
    else {
      iVar2 = CONCAT11(bVar4,3);
    }
LAB_1000_b0ff:
    return CONCAT22(in_DX,iVar2);
  }
LAB_1000_b0fc:
  return CONCAT22(in_DX,uVar3);
}


