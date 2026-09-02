/* 1000:aad5 */

uint __cdecl16near FUN_1000_aad5(void)

{
  byte bVar1;
  uint uVar2;
  uint *in_BX;
  undefined2 unaff_DS;
  
  uVar2 = *in_BX;
  if (0x1ef < uVar2) {
    bVar1 = (byte)in_BX[-0x16c1];
    uVar2 = CONCAT11((char)(uVar2 >> 8),bVar1);
    if (((bVar1 == 0x7a) || (bVar1 == 0x7b)) || ((0x2f < bVar1 && (bVar1 < 0x60)))) {
      uVar2 = in_BX[-0x30];
      if (in_BX[0x30] < in_BX[-0x30]) {
        uVar2 = in_BX[0x30];
      }
      if (in_BX[-1] < uVar2) {
        uVar2 = in_BX[-1];
      }
      if (in_BX[1] < uVar2) {
        uVar2 = in_BX[1];
      }
      uVar2 = uVar2 + 1;
    }
  }
  return uVar2;
}


