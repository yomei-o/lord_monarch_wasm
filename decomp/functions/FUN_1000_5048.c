/* 1000:5048 */

/* WARNING: Control flow encountered bad instruction data */

ulong FUN_1000_5048(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  uint in_CX;
  int iVar10;
  undefined2 in_DX;
  undefined2 extraout_DX;
  byte *in_BX;
  uint unaff_BP;
  int *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  uint unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  byte bVar11;
  byte in_AF;
  ulong in_stack_00000012;
  
  if ((bool)in_CF) {
    FUN_1000_69bc();
    FUN_1000_5fcb();
    FUN_1000_69bc();
    FUN_1000_5fcb();
    in_DX = extraout_DX;
  }
  if ((int)&stack0x0000 < 1) {
    *unaff_SI = *unaff_SI >> 1;
    pbVar4 = (byte *)((unaff_BP ^ unaff_SS) + (int)unaff_SI);
    *pbVar4 = *pbVar4 & (byte)unaff_SS;
    *unaff_SI = *unaff_SI;
    bVar6 = (byte)unaff_SS + 0x73;
    iVar10 = (unaff_BP ^ unaff_SS) + in_CX;
    bVar11 = 9 < (bVar6 & 0xf) | in_AF;
    uVar7 = CONCAT11((char)(unaff_SS >> 8) - bVar11 & *in_BX,bVar6 + bVar11 * -6) & 0xff0f;
    uVar8 = uVar7 + 0x373;
    puVar2 = (uint *)((int)unaff_SI + 1);
    uVar5 = (uint)(0xfc8c < uVar7);
    uVar7 = *puVar2;
    uVar3 = *puVar2;
    *puVar2 = uVar3 + uVar8 + uVar5;
    puVar2 = (uint *)((int)unaff_SI + iVar10 + 2);
    uVar5 = (uint)(CARRY2(uVar7,uVar8) || CARRY2(uVar3 + uVar8,uVar5));
    uVar7 = *puVar2;
    uVar3 = *puVar2;
    *puVar2 = uVar3 + uVar8 + uVar5;
    *(undefined1 *)((int)unaff_SI + iVar10 + 2) = (char)in_CX;
    piVar1 = (int *)((int)unaff_SI + iVar10 + 2);
    *piVar1 = *piVar1 + uVar8 + (uint)(CARRY2(uVar7,uVar8) || CARRY2(uVar3 + uVar8,uVar5));
    uVar9 = in(in_DX);
    bVar11 = (byte)uVar9;
    *unaff_DI = bVar11;
    puVar2 = (uint *)((int)unaff_SI + CONCAT11(7,(char)in_BX) + 2);
    uVar7 = (uint)((byte)(bVar11 - 0x18) < 0x12 || (byte)(bVar11 - 0x2a) < (0x17 < bVar11));
    bVar11 = CARRY2(*puVar2,in_CX) || CARRY2(*puVar2 + in_CX,uVar7);
    *puVar2 = *puVar2 + in_CX + uVar7;
    FUN_1000_6bca();
    *(uint *)0x87c = *(uint *)0x87c << 1 | (uint)bVar11;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x0001595c();
  FUN_1000_559b();
  if (!(bool)in_CF) {
    unaff_DI = (byte *)0xcc00;
    func_0x000155d8();
    if (!(bool)in_CF) goto LAB_1000_5080;
  }
  for (iVar10 = 0x13a; iVar10 != 0; iVar10 = iVar10 + -1) {
    pbVar4 = unaff_DI;
    unaff_DI = unaff_DI + -2;
    pbVar4[0] = 0;
    pbVar4[1] = 0;
  }
LAB_1000_5080:
  FUN_1000_99d8();
  return in_stack_00000012 >> 8 & 0xffff;
}


