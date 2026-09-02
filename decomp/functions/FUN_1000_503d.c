/* 1000:503d */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_503d(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined2 in_AX;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  uint in_CX;
  int iVar9;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  byte *in_BX;
  uint unaff_BP;
  int *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  uint unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  undefined1 uVar10;
  byte bVar11;
  byte in_AF;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  byte bStack_1;
  
  uVar10 = &stack0x0000 < *(undefined1 **)(unaff_DI + unaff_BP + 0xc52c);
  *(int *)0x346e = CONCAT11((char)((uint)in_AX >> 8),-in_CF) + -1;
  func_0x00014d51();
  uVar8 = extraout_DX;
  if ((bool)uVar10) {
    FUN_1000_69bc();
    param_1._0_1_ = 0x51;
    param_1._1_1_ = 0x50;
    FUN_1000_5fcb();
    param_2._0_1_ = 0x54;
    param_2._1_1_ = 0x50;
    FUN_1000_69bc();
    param_3 = 0x5057;
    FUN_1000_5fcb();
    uVar8 = extraout_DX_00;
  }
  bStack_1 = (byte)unaff_SS;
  if ((int)&param_1 < 1) {
    *unaff_SI = *unaff_SI >> 1;
    pbVar4 = (byte *)((unaff_BP ^ unaff_SS) + (int)unaff_SI);
    *pbVar4 = *pbVar4 & bStack_1;
    *unaff_SI = *unaff_SI;
    iVar9 = (unaff_BP ^ unaff_SS) + in_CX;
    in_AF = 9 < (bStack_1 + 0x73 & 0xf) | in_AF;
    uVar6 = CONCAT11((char)(unaff_SS >> 8) - in_AF & *in_BX,bStack_1 + 0x73 + in_AF * -6) & 0xff0f;
    uVar7 = uVar6 + 0x373;
    puVar2 = (uint *)((int)unaff_SI + 1);
    uVar5 = (uint)(0xfc8c < uVar6);
    uVar6 = *puVar2;
    uVar3 = *puVar2;
    *puVar2 = uVar3 + uVar7 + uVar5;
    puVar2 = (uint *)((int)unaff_SI + iVar9 + 2);
    uVar5 = (uint)(CARRY2(uVar6,uVar7) || CARRY2(uVar3 + uVar7,uVar5));
    uVar6 = *puVar2;
    uVar3 = *puVar2;
    *puVar2 = uVar3 + uVar7 + uVar5;
    *(undefined1 *)((int)unaff_SI + iVar9 + 2) = (char)in_CX;
    piVar1 = (int *)((int)unaff_SI + iVar9 + 2);
    *piVar1 = *piVar1 + uVar7 + (uint)(CARRY2(uVar6,uVar7) || CARRY2(uVar3 + uVar7,uVar5));
    uVar8 = in(uVar8);
    bVar11 = (byte)uVar8;
    *unaff_DI = bVar11;
    puVar2 = (uint *)((int)unaff_SI + CONCAT11(7,(char)in_BX) + 2);
    uVar6 = (uint)((byte)(bVar11 - 0x18) < 0x12 || (byte)(bVar11 - 0x2a) < (0x17 < bVar11));
    bVar11 = CARRY2(*puVar2,in_CX) || CARRY2(*puVar2 + in_CX,uVar6);
    *puVar2 = *puVar2 + in_CX + uVar6;
    FUN_1000_6bca();
    *(uint *)0x87c = *(uint *)0x87c << 1 | (uint)bVar11;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x0001595c();
  param_1._0_1_ = 0x50;
  FUN_1000_559b();
  if (!(bool)uVar10) {
    unaff_DI = (byte *)0xcc00;
    param_1._1_1_ = 0x72;
    param_2._0_1_ = 0x50;
    func_0x000155d8();
    if (!(bool)uVar10) goto LAB_1000_5080;
  }
  for (iVar9 = 0x13a; iVar9 != 0; iVar9 = iVar9 + -1) {
    pbVar4 = unaff_DI;
    unaff_DI = unaff_DI + 2;
    pbVar4[0] = 0;
    pbVar4[1] = 0;
  }
LAB_1000_5080:
  param_1._1_1_ = 0x83;
  param_2._0_1_ = 0x50;
  FUN_1000_99d8();
  return CONCAT22(in_stack_00000010._1_2_,in_stack_00000014._1_2_);
}


