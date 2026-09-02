/* 1000:079b */

undefined4 FUN_1000_079b(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte in_AL;
  byte bVar4;
  uint in_CX;
  int iVar5;
  byte bVar6;
  undefined2 in_DX;
  byte *in_BX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  byte *pbVar7;
  byte *pbVar8;
  uint unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  bool bVar10;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  bVar4 = in_AL & 0x7f;
  bVar6 = (byte)in_DX;
  if ((char)in_AL < '\0') {
    in_BX[unaff_DI] = in_BX[unaff_DI] & (byte)((in_CX & 0xff07) >> 8);
    *(int *)(in_BX + (int)unaff_SI) = *(int *)(in_BX + (int)unaff_SI) - (int)&stack0x0000;
    bVar9 = (unaff_ES & 1) != 0;
    pbVar1 = in_BX;
    bVar3 = *pbVar1;
    bVar2 = *pbVar1 + (byte)in_BX;
    *pbVar1 = bVar2 + bVar9;
    unaff_SI[unaff_BP] =
         unaff_SI[unaff_BP] + bVar4 + (CARRY1(bVar3,(byte)in_BX) || CARRY1(bVar2,bVar9));
    return CONCAT22(CONCAT11((char)((uint)in_DX >> 8),bVar6 + unaff_SI[0x1210]),unaff_CS);
  }
  pbVar1 = in_BX + 0x52a;
  bVar9 = false;
  *pbVar1 = *pbVar1 | '\x01' << (sbyte)(in_CX & 0xff07);
  bVar10 = *pbVar1 == 0;
  pbVar7 = (byte *)0x1000;
  iVar5 = 0xe;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pbVar1 = pbVar7;
    pbVar7 = pbVar7 + 1;
    bVar9 = bVar4 < *pbVar1;
    bVar10 = bVar4 == *pbVar1;
  } while (!bVar10);
  pbVar8 = pbVar7;
  if (bVar10) {
    pbVar8 = pbVar7 + -0x1001;
    bVar4 = pbVar7[0xd];
    bVar3 = bVar4 & 7;
    bVar9 = false;
    *(byte *)0x32cc = *(byte *)0x32cc | '\x01' << bVar3 | 1U >> 8 - bVar3;
    in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),bVar4);
    in_BX[0x32c3] = 0;
  }
  unaff_SI[0x1eff] =
       (unaff_SI[0x1eff] - 0x1a) -
       (bVar6 < in_BX[(int)pbVar8] || (byte)(bVar6 - in_BX[(int)pbVar8]) < bVar9);
  iVar5 = 2;
  bVar4 = 0;
  do {
    bVar3 = *unaff_SI;
    in_BX[0x32f2] = in_BX[0x32f2] | bVar3;
    LOCK();
    bVar6 = in_BX[0x32f3];
    in_BX[0x32f3] = bVar3;
    UNLOCK();
    bVar4 = bVar4 | bVar6 ^ bVar3;
    unaff_SI = unaff_SI + 8;
    in_BX = in_BX + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((bVar4 & 8) != 0) {
    out(0x37,6);
    iVar5 = 0x1000;
    do {
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    out(0x37,7);
  }
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


