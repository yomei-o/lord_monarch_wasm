/* 1000:674a */

/* WARNING: Instruction at (ram,0x0001678f) overlaps instruction at (ram,0x0001678d)
    */
/* WARNING: Removing unreachable block (ram,0x00016781) */
/* WARNING: Removing unreachable block (ram,0x00016792) */
/* WARNING: Removing unreachable block (ram,0x00016796) */
/* WARNING: Removing unreachable block (ram,0x0001679f) */
/* WARNING: Removing unreachable block (ram,0x000167a2) */
/* WARNING: Removing unreachable block (ram,0x000167a6) */
/* WARNING: Removing unreachable block (ram,0x000167ad) */
/* WARNING: Removing unreachable block (ram,0x0001686f) */
/* WARNING: Removing unreachable block (ram,0x0001678f) */
/* WARNING: Removing unreachable block (ram,0x00016793) */

void FUN_1000_674a(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint in_AX;
  uint uVar3;
  byte in_CL;
  int iVar4;
  int in_BX;
  uint unaff_BP;
  byte *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xe216);
  *pbVar1 = *pbVar1 & in_CL;
  *(int *)(in_BX + 0x600c) = (*(int *)(in_BX + 0x600c) - (int)unaff_DI) - (uint)(unaff_BP < in_AX);
  do {
    iVar4 = 0x18;
    uVar3 = 0;
    while( true ) {
      pbVar1 = unaff_SI + in_BX;
      *pbVar1 = *pbVar1 & (byte)iVar4;
      uVar3 = CONCAT11((char)uVar3,*(undefined1 *)(in_BX + -0x2d82));
      uVar3 = CONCAT11((char)(uVar3 % (uint)*unaff_SI),(char)(uVar3 / *unaff_SI));
      if (*pbVar1 != 0) {
        FUN_1000_9163();
        uVar3 = FUN_1000_816c();
        unaff_DI[0x240] = 0xffff;
      }
      puVar2 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar2 = uVar3;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      uVar3 = uVar3 >> 8;
      in(0x51);
      in_BX = in_BX + 2;
    }
    in_BX = in_BX + 0x32;
  } while( true );
}


