/* 1000:174b */

/* WARNING: Instruction at (ram,0x00014b0d) overlaps instruction at (ram,0x00014b0b)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_174b(void)

{
  byte *pbVar1;
  byte bVar2;
  char cVar4;
  bool bVar5;
  undefined2 uVar6;
  byte bVar7;
  byte in_AL;
  byte bVar8;
  int iVar9;
  byte bVar10;
  int in_CX;
  int iVar11;
  char extraout_DL;
  int extraout_DX;
  undefined2 extraout_DX_00;
  uint in_BX;
  int iVar12;
  undefined2 **ppuVar13;
  undefined1 **ppuVar14;
  undefined1 **ppuVar15;
  undefined2 **ppuVar16;
  undefined1 **unaff_BP;
  undefined2 *unaff_SI;
  undefined1 *puVar17;
  undefined1 *puVar18;
  char *unaff_DI;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar21;
  undefined1 uVar22;
  undefined1 in_ZF;
  bool bVar23;
  char cVar24;
  char cVar25;
  undefined2 in_stack_0000000e;
  char cStack_208b;
  undefined1 uVar26;
  undefined1 uVar27;
  uint uVar28;
  uint in_stack_0000df84;
  undefined1 *puStack_82b;
  undefined1 *puStack_829;
  undefined1 *puStack_827;
  undefined1 *puStack_40;
  undefined1 *puStack_4;
  undefined2 *puStack_2;
  byte bVar3;
  
  while ((bool)in_ZF) {
    bVar21 = false;
    cVar25 = '\0';
    cVar24 = '\0';
    bVar23 = (in_AL & 0x40) == 0;
    if (!bVar23) {
      *unaff_DI = '\0';
      return in_stack_0000000e;
    }
    puStack_40 = (undefined1 *)&puStack_2;
    ppuVar13 = &puStack_2;
    ppuVar16 = &puStack_2;
    puStack_2 = unaff_BP;
    cVar4 = '\x1e';
    do {
      unaff_BP = unaff_BP + -1;
      ppuVar13 = ppuVar13 + -1;
      *ppuVar13 = (undefined2 *)*unaff_BP;
      cVar4 = cVar4 + -1;
    } while ('\0' < cVar4);
    iVar9 = FUN_1000_967a();
    bVar5 = in_CX != 0;
    in_CX = 0;
    if (bVar5) {
      ppuVar14 = &puStack_4;
      ppuVar16 = (undefined2 **)&puStack_4;
      puStack_4 = (undefined1 *)&puStack_2;
      if (bVar21) {
        in_BX = in_BX + 1;
        in_CX = iVar9;
      }
      else {
        ppuVar15 = &puStack_82b;
        unaff_BP = &puStack_82b;
        ppuVar16 = (undefined2 **)&puStack_82b;
        cVar4 = '\x18';
        puStack_82b = (undefined1 *)&puStack_4;
        puStack_829 = (undefined1 *)&puStack_4;
        puStack_827 = (undefined1 *)&puStack_4;
        do {
          ppuVar14 = ppuVar14 + -1;
          ppuVar15 = ppuVar15 + -1;
          *ppuVar15 = *ppuVar14;
          cVar4 = cVar4 + -1;
        } while ('\0' < cVar4);
        if (!bVar23 && cVar25 == cVar24) goto code_r0x000117bb;
        func_0x000108d1();
        bVar21 = CARRY2(in_BX,in_stack_0000df84);
        in_BX = in_BX + in_stack_0000df84;
        *(int *)(in_BX + (int)unaff_SI) =
             (*(int *)(in_BX + (int)unaff_SI) - extraout_DX) - (uint)bVar21;
        FUN_1000_7860();
        unaff_SI = (undefined2 *)0x10f1;
        in_stack_0000df84 = 0x173f;
        FUN_1000_5782();
        in_CX = iVar9;
      }
    }
    puStack_4 = (undefined1 *)0x1742;
    FUN_1000_6e71();
    do {
      puStack_2 = (undefined2 *)0x1745;
      bVar7 = func_0x0001c49c();
      in_AL = bVar7 & 0x6f;
    } while (in_AL == 0);
    in_ZF = (bVar7 & 0x20) == 0;
    unaff_BP = (undefined1 **)ppuVar16;
  }
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x65);
  *pbVar1 = *pbVar1 & (byte)(in_BX >> 8);
  puStack_4 = (undefined1 *)0x17b8;
  puStack_2 = unaff_SI;
  FUN_1000_49e9();
  puStack_2 = (undefined2 *)0x17bb;
  func_0x00014a3f();
  iVar9 = in_CX;
code_r0x000117bb:
  puVar18 = &stack0xdf84;
  cVar24 = FUN_1000_6e4c();
  uVar22 = (undefined2 *)*(uint *)(in_BX + (int)unaff_SI) < unaff_SI;
  *unaff_DI = cVar24;
  unaff_DI[1] = cVar24;
  uVar27 = SUB21(unaff_BP,0);
  FUN_1000_5a4b((char)(unaff_DI + 2),(char)unaff_SI,uVar27,&stack0xdf84,in_BX,extraout_DX_00,iVar9,
                (int)cVar24);
  FUN_1000_5685();
  if (!(bool)uVar22) {
    uVar26 = 0xc6;
    FUN_1000_5d53();
    uVar27 = 0xc9;
    func_0x000156ac();
    if (!(bool)uVar22) goto LAB_1000_4af9;
  }
  puVar19 = (undefined1 *)0x5200;
  iVar11 = 0xa0;
  do {
    uVar26 = (undefined1)iVar11;
    uVar22 = (undefined1)((uint)iVar11 >> 8);
    cVar24 = FUN_1000_60d8(uVar26,uVar27);
    puVar17 = (undefined1 *)0x3e50;
    iVar11 = 0x10;
    do {
      puVar20 = puVar19;
      puVar19 = puVar20 + 1;
      *puVar20 = *puVar17;
      puVar17 = puVar17 + 2;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (0x7f < (byte)(cVar24 + 1U)) {
      puVar19 = puVar20 + 0x201;
    }
    iVar11 = CONCAT11(uVar22,uVar26) + -1;
  } while (iVar11 != 0);
LAB_1000_4af9:
  do {
    iVar12 = iVar9;
    uVar28 = in_BX;
    puVar19 = puVar18;
    bVar21 = false;
    puVar19[uVar28 - 1] = puVar19[uVar28 - 1] ^ (byte)iVar12;
    iVar11 = in_stack_0000df84 - 1;
    cStack_208b = 'K';
    puVar18 = puVar19;
    in_BX = uVar28;
    iVar9 = iVar12;
    func_0x00015687(uVar26);
  } while (bVar21);
  iVar9 = uVar28 - 2;
  pbVar1 = (byte *)0x1244;
  bVar21 = CARRY1(*pbVar1,(byte)iVar11);
  *pbVar1 = *pbVar1 + (byte)iVar11;
LAB_1000_4b0f:
  bVar7 = 0x12;
  cVar24 = 'K';
  func_0x000156a8(uVar27);
  if (bVar21) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
code_r0x00014b14:
  uVar6 = CONCAT11(bVar7,cStack_208b);
  puVar18 = puVar19;
  do {
    uVar22 = (byte)((uint)iVar11 >> 8) < (byte)puVar18[iVar9];
    puVar18 = (undefined1 *)0x336e;
    FUN_1000_567c(cVar24);
    if (!(bool)uVar22) {
      cStack_208b = '/';
      bVar7 = 0x4b;
      FUN_1000_5d4f();
      cVar24 = '2';
      uVar27 = 0x4b;
      func_0x000156a4();
      if (!(bool)uVar22) break;
    }
    in(0x1f);
  } while( true );
  bVar21 = CARRY1(extraout_DL - (char)*(undefined2 *)(iVar12 + 0x336e),*(byte *)(iVar9 + 0x3389));
  pbVar1 = (byte *)0xb43;
  bVar2 = *pbVar1;
  bVar10 = (byte)iVar11;
  bVar3 = *pbVar1;
  *pbVar1 = bVar3 + bVar10 + bVar21;
  if (!CARRY1(bVar2,bVar10) && !CARRY1(bVar3 + bVar10,bVar21)) {
    puVar18 = (undefined1 *)0x9812;
    cStack_208b = '\0';
    bVar7 = 0;
    puVar19 = (undefined1 *)(*(uint *)(iVar9 + 0x3332) | 0x336e);
    pbVar1 = puVar19 + iVar9;
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 + 0x12;
    puVar19[iVar9 + 0xeaa] = puVar19[iVar9 + 0xeaa] + (char)((uint)iVar11 >> 8) + (0xed < bVar2);
    pbVar1 = (byte *)(iVar9 + 1);
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 - bVar10;
    if (bVar10 <= bVar2) {
      pbVar1 = (byte *)0x11ea;
      bVar23 = CARRY1(*pbVar1,bVar10);
      *pbVar1 = *pbVar1 + bVar10;
      puVar18 = (undefined1 *)func_0x000156a0();
      bVar21 = true;
      if (bVar23) goto LAB_1000_4b0f;
      bVar7 = (byte)iVar11;
      cStack_208b = (char)((uint)iVar11 >> 8);
      pbVar1 = puVar19 + iVar9;
      bVar2 = *pbVar1;
      bVar8 = (byte)puVar18;
      *pbVar1 = *pbVar1 + bVar8;
      iVar9 = iVar9 + 1;
      pbVar1 = (byte *)0xb0d;
      bVar3 = *pbVar1;
      bVar10 = *pbVar1;
      *pbVar1 = bVar10 + bVar7 + CARRY1(bVar2,bVar8);
      if (!CARRY1(bVar3,bVar7) && !CARRY1(bVar10 + bVar7,CARRY1(bVar2,bVar8))) {
        puVar19[iVar12] = puVar19[iVar12] + (char)iVar12;
        return 0xe000;
      }
      iVar11 = CONCAT11(cStack_208b + bVar8 + '\x01',bVar7);
      cVar24 = cStack_208b;
    }
  }
  puVar19 = (undefined1 *)((uint)puVar18 | *(uint *)(puVar18 + iVar9 + -0x1c));
  goto code_r0x00014b14;
}


