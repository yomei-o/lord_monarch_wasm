/* 1000:27c5 */

void FUN_1000_27c5(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  
  uVar4 = FUN_1000_2923();
  in_AF = 9 < ((byte)uVar4 & 0xf) | in_AF;
  bVar3 = (byte)uVar4 + in_AF * -6 & 0xf;
  if (bVar3 < 0x60) {
    bVar3 = 0x30;
  }
  else {
    if ((bVar3 < 0x60) || (0x6f < bVar3)) goto LAB_1000_2810;
    bVar3 = 0x60;
  }
  *(byte *)(unaff_SI + 2) = bVar3;
LAB_1000_2810:
  bVar2 = 9 < (bVar3 & 0xf) | in_AF;
  pbVar1 = (byte *)(unaff_SI + 2) + unaff_BP;
  *pbVar1 = *pbVar1 ^ ((char)((uint)uVar4 >> 8) - in_AF) + bVar2 +
                      (9 < (bVar3 + bVar2 * '\x06' & 0xf) | bVar2);
  return;
}


