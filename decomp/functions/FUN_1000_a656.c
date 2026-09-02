/* 1000:a656 */

undefined2 __cdecl16near FUN_1000_a656(void)

{
  uint uVar1;
  byte bVar2;
  undefined2 in_AX;
  uint uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined1 uVar5;
  
  if (*(int *)0x3c04 != 1) {
    uVar1 = *(uint *)&DAT_0000_3be4;
    bVar2 = (byte)(uVar1 >> 8);
    uVar3 = CONCAT11(bVar2 - 6,(char)uVar1);
    if (bVar2 < 6) {
      uVar3 = uVar1 & 0xff;
    }
    if (0x23 < (byte)(uVar3 >> 8)) {
      uVar3 = CONCAT11(0x24,(char)uVar3);
    }
    uVar5 = (undefined1)(uVar3 >> 8);
    bVar2 = (byte)uVar3 - 6;
    if ((byte)uVar3 < 6) {
      bVar2 = 0;
    }
    uVar4 = CONCAT11(uVar5,bVar2);
    if (0x23 < bVar2) {
      uVar4 = CONCAT11(uVar5,0x24);
    }
    *(undefined2 *)&DAT_0000_3be2 = uVar4;
    return in_AX;
  }
  uVar1 = *(uint *)&DAT_0000_3be4;
  bVar2 = (byte)(uVar1 >> 8);
  uVar3 = CONCAT11(bVar2 - 0xc,(char)uVar1);
  if (bVar2 < 0xc) {
    uVar3 = uVar1 & 0xff;
  }
  if (0x17 < (byte)(uVar3 >> 8)) {
    uVar3 = CONCAT11(0x18,(char)uVar3);
  }
  uVar5 = (undefined1)(uVar3 >> 8);
  bVar2 = (byte)uVar3 - 0xc;
  if ((byte)uVar3 < 0xc) {
    bVar2 = 0;
  }
  uVar4 = CONCAT11(uVar5,bVar2);
  if (0x17 < bVar2) {
    uVar4 = CONCAT11(uVar5,0x18);
  }
  *(undefined2 *)&DAT_0000_3be2 = uVar4;
  return in_AX;
}


