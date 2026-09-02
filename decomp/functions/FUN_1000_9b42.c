/* 1000:9b42 */

undefined4 __cdecl16near FUN_1000_9b42(void)

{
  uint uVar1;
  byte bVar2;
  undefined2 in_AX;
  byte bVar3;
  undefined1 uVar5;
  undefined2 in_DX;
  uint uVar6;
  undefined2 unaff_DS;
  byte bVar4;
  
  if (*(int *)0x3288 == 0) {
    *(undefined2 *)&DAT_0000_3be2 = 0;
    return CONCAT22(in_DX,in_AX);
  }
  if (*(int *)0x3288 != 1) {
    uVar1 = *(uint *)&DAT_0000_3be2;
    bVar4 = (byte)((uint)*(undefined2 *)&DAT_0000_3be4 >> 8);
    bVar2 = (byte)*(undefined2 *)&DAT_0000_3be4;
    bVar3 = bVar4 - (char)(uVar1 >> 8);
    uVar5 = (undefined1)uVar1;
    if ((char)bVar3 < '\x03') {
      uVar6 = CONCAT11(bVar4 - 3,uVar5);
      if (bVar4 < 3) {
        uVar6 = uVar1 & 0xff;
      }
    }
    else {
      uVar6 = uVar1;
      if ((7 < bVar3) && (uVar6 = CONCAT11(bVar4 - 8,uVar5), 0x23 < (byte)(bVar4 - 8))) {
        uVar6 = CONCAT11(0x24,uVar5);
      }
    }
    bVar3 = bVar2 - (char)uVar6;
    bVar4 = (byte)(uVar6 >> 8);
    if ((char)bVar3 < '\x03') {
      uVar6 = CONCAT11(bVar4,bVar2 - 3);
      if (bVar2 < 3) {
        uVar6 = (uint)bVar4 << 8;
      }
    }
    else if ((7 < bVar3) && (uVar6 = CONCAT11(bVar4,bVar2 - 8), 0x23 < (byte)(bVar2 - 8))) {
      uVar6 = CONCAT11(bVar4,0x24);
    }
    *(uint *)&DAT_0000_3be2 = uVar6;
    return CONCAT22(in_DX,in_AX);
  }
  uVar1 = *(uint *)&DAT_0000_3be2;
  bVar4 = (byte)((uint)*(undefined2 *)&DAT_0000_3be4 >> 8);
  bVar2 = (byte)*(undefined2 *)&DAT_0000_3be4;
  bVar3 = bVar4 - (char)(uVar1 >> 8);
  uVar5 = (undefined1)uVar1;
  if ((char)bVar3 < '\x06') {
    uVar6 = CONCAT11(bVar4 - 6,uVar5);
    if (bVar4 < 6) {
      uVar6 = uVar1 & 0xff;
    }
  }
  else {
    uVar6 = uVar1;
    if ((0x10 < bVar3) && (uVar6 = CONCAT11(bVar4 - 0x11,uVar5), 0x17 < (byte)(bVar4 - 0x11))) {
      uVar6 = CONCAT11(0x18,uVar5);
    }
  }
  bVar3 = bVar2 - (char)uVar6;
  bVar4 = (byte)(uVar6 >> 8);
  if ((char)bVar3 < '\x06') {
    uVar6 = CONCAT11(bVar4,bVar2 - 6);
    if (bVar2 < 6) {
      uVar6 = (uint)bVar4 << 8;
    }
  }
  else if ((0x10 < bVar3) && (uVar6 = CONCAT11(bVar4,bVar2 - 0x11), 0x17 < (byte)(bVar2 - 0x11))) {
    uVar6 = CONCAT11(bVar4,0x18);
  }
  *(uint *)&DAT_0000_3be2 = uVar6;
  return CONCAT22(in_DX,in_AX);
}


