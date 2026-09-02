/* 1000:462f */

/* WARNING: Instruction at (ram,0x00014727) overlaps instruction at (ram,0x00014726)
    */

void FUN_1000_462f(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  char cVar9;
  uint uVar8;
  byte bVar10;
  uint uVar11;
  byte bVar12;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  undefined1 uVar14;
  int *piVar13;
  int unaff_BP;
  byte *unaff_SI;
  int iVar15;
  int iVar16;
  undefined1 *puVar17;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar18;
  undefined4 uVar19;
  int in_stack_0000000a;
  int in_stack_0000000c;
  byte in_stack_00000012;
  byte *pbStack_c;
  int iStack_a;
  undefined2 uStack_6;
  uint uVar7;
  
  cVar9 = '\0';
  FUN_1000_7676();
  unaff_SI[unaff_BP + -0x81e] = (unaff_SI[unaff_BP + -0x81e] - cVar9) - in_CF;
  if (*(int *)0x32a6 != 0) {
    *(uint *)(in_BX + 0x2cdb) = *(uint *)(in_BX + 0x2cdb) ^ 0x14;
    FUN_1000_8940();
    func_0x000161bc();
    FUN_1000_6844();
    *(byte *)(in_stack_0000000c + in_stack_0000000a) =
         *(byte *)(in_stack_0000000c + in_stack_0000000a) & in_stack_00000012;
    thunk_FUN_1000_7b7d();
    return;
  }
  piVar13 = (int *)(*(int *)0x3bda * 8);
  uVar11 = (uint)*(byte *)((int)piVar13 + 0x2b55);
  iVar15 = 0x3490;
  do {
    FUN_1000_7676();
    FUN_1000_61bd();
    uVar19 = FUN_1000_6845();
    cVar9 = (char)((ulong)uVar19 >> 8);
    bVar3 = (char)uVar19 + 1;
    uVar7 = CONCAT11(cVar9,bVar3);
    if (0x7e < bVar3) {
      uVar7 = CONCAT11(cVar9 + '\x01',0x21);
    }
    iVar16 = iVar15 + 2;
    if ((int)((ulong)uVar19 >> 0x10) == 1) {
      iVar16 = iVar15 + 0x4da;
    }
    uVar11 = uVar11 - 1;
    iVar15 = iVar16;
  } while (uVar11 != 0);
  out(0xff,uVar7);
  *(char *)(unaff_BP + iVar16) = *(char *)(unaff_BP + iVar16) + (char)uVar7;
  pbVar2 = (byte *)(unaff_BP + iVar16 + -0x1730);
  *pbVar2 = *pbVar2 >> 6 | *pbVar2 << 2;
  puVar17 = (undefined1 *)(iVar16 + (uVar7 ^ 0xc2) + 0x2d0e);
  if (puVar17 != (undefined1 *)*(int *)0x32a2) {
    FUN_1000_46ef();
    uVar14 = (undefined1)((uint)piVar13 >> 8);
    *(undefined2 *)0x32a2 = puVar17;
    uVar4 = FUN_1000_86c1();
    *puVar17 = uVar4;
    piVar13 = (int *)CONCAT11(uVar14,unaff_SI[unaff_BP]);
  }
  do {
    func_0x00017617();
    FUN_1000_6159();
    uVar8 = func_0x00017617();
    puVar17 = (undefined1 *)*(undefined2 *)0x36a2;
    puVar1 = (uint *)(unaff_SI + unaff_BP);
    uVar7 = *puVar1;
    *puVar1 = *puVar1 - uVar8;
    bVar18 = 0xefdb < uVar8 || CARRY2(uVar8 + 0x1024,(uint)(uVar7 < uVar8));
    bVar5 = (char)(uVar8 + 0x1024) + (uVar7 < uVar8);
    bVar3 = bVar5 + 0xa8;
    bVar6 = bVar3 - bVar18;
    bVar12 = (byte)(uVar11 >> 8);
    bVar10 = (byte)uVar11;
    iVar15 = *piVar13;
    FUN_1000_6153();
    func_0x00017611();
    *(undefined2 *)0x89a2 = 0x132;
    pbVar2 = unaff_SI;
    *pbVar2 = *pbVar2 >> (bVar10 & 7) | *pbVar2 << 8 - (bVar10 & 7);
    FUN_1000_4693();
    func_0x0001b778();
    uVar4 = in(extraout_DX);
    *puVar17 = uVar4;
    *(uint *)((byte *)((int)piVar13 + (int)unaff_SI) + 0x7440) =
         *(int *)((byte *)((int)piVar13 + (int)unaff_SI) + 0x7440) -
         (unaff_BP + iVar15 +
         (uint)(bVar12 < bVar6 || (byte)(bVar12 - bVar6) < (bVar5 < 0x58 || bVar3 < bVar18)));
    unaff_ES = *(undefined2 *)(byte *)((int)piVar13 + (int)unaff_SI);
    uVar11 = 0x46e6;
    piVar13 = (int *)CONCAT11((char)((uint)uStack_6 >> 8),(char)uStack_6 + 'F');
    do {
      thunk_FUN_1000_47c8();
      bVar3 = func_0x0001b68c();
    } while ((bVar3 & 0xf) != 0);
    *(undefined2 *)0x3bdc = extraout_DX_00;
    *(undefined1 *)0x3289 = 0x2f;
    unaff_BP = iStack_a;
    unaff_SI = pbStack_c;
  } while( true );
}


