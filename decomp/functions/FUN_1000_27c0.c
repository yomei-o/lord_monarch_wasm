/* 1000:27c0 */

void FUN_1000_27c0(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 in_AX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  
  bVar3 = (byte)in_AX;
  if ((bVar3 == 0) || (4 < bVar3)) {
    if ((bVar3 < 0x14) || (0x17 < bVar3)) {
      if ((7 < bVar3) && (bVar3 < 0xc)) {
        in_AX = FUN_1000_2983();
      }
    }
    else {
      in_AX = func_0x0001294d();
    }
  }
  else {
    in_AX = FUN_1000_2923();
  }
  bVar3 = 9 < ((byte)in_AX & 0xf) | in_AF;
  bVar4 = (byte)in_AX + bVar3 * -6 & 0xf;
  if (bVar4 < 0x60) {
    bVar4 = 0x30;
  }
  else {
    if ((bVar4 < 0x60) || (0x6f < bVar4)) goto LAB_1000_2810;
    bVar4 = 0x60;
  }
  *(byte *)(unaff_SI + 2) = bVar4;
LAB_1000_2810:
  bVar2 = 9 < (bVar4 & 0xf) | bVar3;
  pbVar1 = (byte *)(unaff_SI + 2) + unaff_BP;
  *pbVar1 = *pbVar1 ^ ((char)((uint)in_AX >> 8) - bVar3) + bVar2 +
                      (9 < (bVar4 + bVar2 * '\x06' & 0xf) | bVar2);
  return;
}


