/* 1000:4e06 */

/* WARNING: Instruction at (ram,0x00014e2d) overlaps instruction at (ram,0x00014e2c)
    */

undefined4 FUN_1000_4e06(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  undefined2 in_CX;
  byte bVar6;
  int iVar5;
  byte extraout_DL;
  undefined2 extraout_DX;
  undefined2 in_DX;
  char cVar7;
  byte *in_BX;
  undefined2 unaff_BP;
  byte *unaff_SI;
  undefined1 *puVar8;
  undefined1 *unaff_DI;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 uVar10;
  bool bVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined2 in_stack_0000000c;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000010;
  undefined2 in_stack_00000012;
  
  *unaff_SI = *unaff_SI | (byte)((uint)in_BX >> 8);
  while( true ) {
    in(in_DX);
    bVar11 = false;
    *unaff_DI = 0;
    *(undefined2 *)0x3bce = 0;
    FUN_1000_5ab2();
    if ((bVar11) || (*(int *)(*(int *)0x3e94 + 0xc) != 0)) break;
    pbVar1 = in_BX + 0x3386;
    bVar11 = *pbVar1 < extraout_DL;
    *pbVar1 = *pbVar1 - extraout_DL;
    if (bVar11 || *pbVar1 == 0) goto SUB_1000_4e36;
    bVar6 = (byte)((uint)in_CX >> 8);
    uVar12 = CARRY1((byte)in_BX,bVar6);
    cVar7 = (byte)in_BX + bVar6;
    in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),cVar7);
    uVar13 = cVar7 == '\0';
    FUN_1000_5a2d();
    do {
      do {
        uVar10 = uVar12;
        if (!(bool)uVar13) goto LAB_1000_4e57;
        func_0x0001b1c4();
        FUN_1000_55f9();
        uVar12 = 1;
      } while ((bool)uVar10);
      FUN_1000_5cc6();
      func_0x0001561b();
      uVar12 = 1;
    } while ((bool)uVar10);
    *(undefined2 *)0x3bc4 = *(undefined2 *)0xdb7e;
    *(char *)0x3327 = *(char *)0x3327 + (byte)extraout_DX;
    *in_BX = *in_BX & (byte)extraout_DX;
    unaff_DI = (undefined1 *)0x3c08;
    in_DX = extraout_DX;
    unaff_ES = unaff_BP;
  }
  bVar11 = false;
SUB_1000_4e36:
  func_0x00014e5d();
  if (!bVar11) {
    puVar8 = (undefined1 *)0xdb7d;
    puVar9 = (undefined2 *)0xe47c;
    iVar5 = 0x900;
    uVar4 = 0x6400;
    do {
      puVar2 = puVar8;
      puVar8 = puVar8 + -1;
      uVar4 = CONCAT11((char)((uint)uVar4 >> 8),*puVar2);
      puVar3 = puVar9;
      puVar9 = puVar9 + -1;
      *puVar3 = uVar4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined2 *)0x346e = *(undefined2 *)0x3bc2;
    return CONCAT22(in_stack_0000000c,in_stack_00000010);
  }
LAB_1000_4e57:
  func_0x0001f293();
  return CONCAT22(in_stack_0000000e,in_stack_00000012);
}


