/* 1000:08f7 */

/* WARNING: Instruction at (ram,0x0001094c) overlaps instruction at (ram,0x0001094b)
    */

void FUN_1000_08f7(void)

{
  int *piVar1;
  int iVar2;
  undefined2 in_AX;
  uint uVar3;
  int in_CX;
  char in_DL;
  int in_BX;
  byte bVar4;
  byte *unaff_BP;
  uint uVar5;
  uint *unaff_SI;
  byte *unaff_DI;
  byte *pbVar6;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  
  do {
    if (unaff_BP <= unaff_DI) {
LAB_1000_0947:
      *(undefined2 *)(in_BX + 0x5410) = in_AX;
      uVar3 = FUN_1000_0984();
      uVar5 = 0x50;
      if (((uVar3 & 0x700) != 0) && (uVar5 = 0xa0, 1 < ((byte)(uVar3 >> 8) & 7))) {
        uVar5 = 0xf0;
      }
      unaff_SI[1] = uVar5;
      *unaff_SI = (uVar3 & 0xff) * 0xa0 >> 8;
      return;
    }
    bVar4 = (byte)((uint)in_AX >> 8);
    out(0xa6,0);
    *unaff_DI = *unaff_DI & bVar4;
    unaff_DI[0x50] = 0;
    unaff_DI[0xa0] = 0;
    unaff_DI[0xf0] = unaff_DI[0xf0] & bVar4;
    iVar2 = CONCAT11(bVar4,1) * 2;
    uVar3 = unaff_SI[1];
    pbVar6 = unaff_DI + unaff_SI[1];
    *(byte **)pbVar6 = unaff_BP;
    pbVar6[-0x4b] = pbVar6[-0x4b] + in_DL + CARRY2((uint)unaff_DI,uVar3);
    uVar3 = *unaff_SI;
    bVar4 = (byte)((uint)in_BX >> 8);
    *pbVar6 = *pbVar6 | bVar4;
    pbVar6[0x50] = pbVar6[0x50] | (byte)in_BX;
    pbVar6[0xa0] = pbVar6[0xa0] | (byte)in_BX;
    pbVar6[0x302d] = pbVar6[0x302d] | bVar4;
    piVar1 = (int *)((int)unaff_SI + in_BX + -0x14ea);
    *piVar1 = (int)(&stack0x0000 + *piVar1);
    in_CX = in_CX + -1;
    if (in_CX == 0) {
      in_AX = 0x33b;
      if ((uint *)*(undefined2 *)0x3bb6 <= unaff_SI) {
        unaff_SI = (uint *)0xce74;
      }
      goto LAB_1000_0947;
    }
    (unaff_BP + (int)pbVar6)[-0x4dca] = (unaff_BP + (int)pbVar6)[-0x4dca] + (char)in_CX;
    unaff_BP = (byte *)0x7d00;
    in_BX = 0x183c;
    in_AX = 0xe7c3;
    in_DL = '\x04';
    unaff_DI = (byte *)*unaff_SI;
    unaff_DS = (CONCAT11((char)((uint)iVar2 >> 8) + (char)uVar3,(char)iVar2) | 0x26) + 0x7316;
  } while( true );
}


