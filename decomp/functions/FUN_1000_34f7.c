/* 1000:34f7 */

void FUN_1000_34f7(void)

{
  byte *pbVar1;
  byte bVar2;
  unkbyte10 Var4;
  undefined1 uVar5;
  byte bVar6;
  code *pcVar7;
  byte bVar8;
  uint uVar9;
  byte in_CL;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  uint unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  unkbyte10 in_ST0;
  byte bVar3;
  
  uVar5 = in(in_DX);
  *unaff_DI = uVar5;
  if (!in_CF) {
    unaff_SI[in_BX] = unaff_SI[in_BX] - (char)((uint)in_DX >> 8);
    *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) << 1;
    *(byte *)(in_BX + -0x2d81) = (byte)in_DX;
    *unaff_SI = *unaff_SI + (byte)unaff_ES + CARRY1((byte)in_DX,*(byte *)(in_BX + -0x21));
    *unaff_SI = *unaff_SI & (byte)unaff_ES;
    *(uint *)(unaff_DI + in_BX + 1) = *(uint *)(unaff_DI + in_BX + 1) | unaff_ES;
    Var4 = to_bcd(in_ST0);
    *(unkbyte10 *)(unaff_SI + in_BX) = Var4;
  }
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ (byte)(unaff_ES >> 8);
  bVar8 = (byte)(unaff_ES / (byte)unaff_DI[4]);
  uVar9 = CONCAT11((char)(unaff_ES % (uint)(byte)unaff_DI[4]),bVar8);
  bVar6 = *unaff_SI;
  pbVar1 = unaff_SI + unaff_BP;
  bVar2 = *pbVar1;
  bVar3 = *pbVar1;
  *pbVar1 = bVar3 + bVar8 + CARRY1(in_CL,bVar6);
  unaff_SI[unaff_BP] =
       unaff_SI[unaff_BP] + (char)unaff_SS +
       (uVar9 < *(uint *)(unaff_SI + unaff_BP) ||
       uVar9 - *(uint *)(unaff_SI + unaff_BP) <
       (uint)(CARRY1(bVar2,bVar8) || CARRY1(bVar3 + bVar8,CARRY1(in_CL,bVar6))));
  pcVar7 = (code *)swi(3);
  (*pcVar7)(&stack0xfffe);
  return;
}


