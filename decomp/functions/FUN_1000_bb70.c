/* 1000:bb70 */

undefined4 __cdecl16near FUN_1000_bb70(void)

{
  int iVar1;
  uint uVar2;
  undefined2 in_BX;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  
  uVar2 = 0x2000;
  uVar3 = 0;
  uVar4 = 0x1f1;
  iVar1 = 0x900;
  do {
    if (((undefined *)&DAT_0000_d27e)[uVar3] == 'z') {
      if (*(uint *)((undefined *)&DAT_0000_ffa0 + uVar3) < uVar4) {
        in_BX = 0xff00;
        uVar2 = uVar3;
        uVar4 = *(uint *)((undefined *)&DAT_0000_ffa0 + uVar3);
      }
      if (*(uint *)(uVar3 - 2) < uVar4) {
        in_BX = 0xff;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 - 2);
      }
      if (*(uint *)(uVar3 + 2) < uVar4) {
        in_BX = 1;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 + 2);
      }
      if (*(uint *)(uVar3 + 0x60) < uVar4) {
        in_BX = 0x100;
        uVar2 = uVar3;
        uVar4 = *(uint *)(uVar3 + 0x60);
      }
    }
    uVar3 = uVar3 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(CONCAT11((char)((uVar2 >> 1) / 0x30) + (char)((uint)in_BX >> 8),
                           (char)((uVar2 >> 1) % 0x30) + (char)in_BX),uVar4);
}


