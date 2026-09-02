/* 1000:1751 */

/* WARNING: Instruction at (ram,0x00014b0d) overlaps instruction at (ram,0x00014b0b)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_1000_1751(uint param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
             undefined2 param_6,undefined2 param_7)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar3;
  byte bVar4;
  undefined1 uVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  int in_CX;
  int iVar10;
  int iVar11;
  char extraout_DL;
  int extraout_DX;
  undefined2 *extraout_DX_00;
  uint in_BX;
  undefined2 **ppuVar12;
  undefined2 *puVar13;
  undefined2 **ppuVar14;
  undefined2 *unaff_BP;
  undefined2 *unaff_SI;
  undefined1 *puVar15;
  undefined2 *puVar16;
  undefined1 *unaff_DI;
  undefined1 *puVar17;
  undefined1 *puVar18;
  uint unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar19;
  undefined1 in_CF;
  undefined1 uVar20;
  bool bVar21;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  char cStack_b;
  byte bStack_a;
  char cStack_9;
  undefined2 *puStack_2;
  
  while( true ) {
    ppuVar12 = &puStack_2;
    ppuVar14 = &puStack_2;
    puStack_2 = unaff_BP;
    cVar6 = '\x1e';
    do {
      unaff_BP = unaff_BP + -1;
      ppuVar12 = ppuVar12 + -1;
      *ppuVar12 = (undefined2 *)*unaff_BP;
      cVar6 = cVar6 + -1;
    } while ('\0' < cVar6);
    iVar8 = FUN_1000_967a();
    bVar19 = in_CX != 0;
    in_CX = 0;
    if (bVar19) break;
LAB_1000_173f:
    FUN_1000_6e71();
    do {
      puStack_2 = (undefined2 *)0x1745;
      bVar4 = func_0x0001c49c();
    } while ((bVar4 & 0x6f) == 0);
    iVar8 = in_CX;
    if ((bVar4 & 0x20) != 0) goto LAB_1000_17ab;
    in_CF = 0;
    in_OF = '\0';
    in_SF = '\0';
    in_ZF = (bVar4 & 0x40) == 0;
    unaff_BP = ppuVar14;
    if (!(bool)in_ZF) {
      *unaff_DI = 0;
      return CONCAT22(param_5,param_7);
    }
  }
  puVar16 = (undefined2 *)&stack0x207a;
  ppuVar14 = (undefined2 **)&stack0x207a;
  if ((bool)in_CF) {
    in_BX = in_BX + 1;
    in_CX = iVar8;
    goto LAB_1000_173f;
  }
  puVar13 = (undefined2 *)&stack0x1853;
  ppuVar14 = (undefined2 **)&stack0x1853;
  cVar6 = '\x18';
  do {
    puVar16 = puVar16 + -1;
    puVar13 = puVar13 + -1;
    *puVar13 = *puVar16;
    cVar6 = cVar6 + -1;
  } while ('\0' < cVar6);
  if ((bool)in_ZF || in_OF != in_SF) {
    puStack_2 = (undefined2 *)0x176f;
    func_0x000108d1();
    bVar19 = CARRY2(in_BX,param_1);
    in_BX = in_BX + param_1;
    *(int *)(in_BX + (int)unaff_SI) = (*(int *)(in_BX + (int)unaff_SI) - extraout_DX) - (uint)bVar19
    ;
    FUN_1000_7860();
    unaff_SI = (undefined2 *)0x10f1;
    FUN_1000_5782();
    in_CX = iVar8;
    param_1 = unaff_ES;
    goto LAB_1000_173f;
  }
LAB_1000_17ab:
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 0x65);
  *pbVar1 = *pbVar1 & (byte)(in_BX >> 8);
  puStack_2 = unaff_SI;
  FUN_1000_49e9();
  puStack_2 = (undefined2 *)0x17bb;
  func_0x00014a3f();
  puVar16 = &param_2;
  uVar5 = FUN_1000_6e4c();
  uVar20 = (undefined2 *)*(uint *)(in_BX + (int)unaff_SI) < unaff_SI;
  *unaff_DI = uVar5;
  unaff_DI[1] = uVar5;
  puStack_2 = extraout_DX_00;
  FUN_1000_5a4b();
  FUN_1000_5685();
  if (!(bool)uVar20) {
    FUN_1000_5d53();
    func_0x000156ac();
    if (!(bool)uVar20) goto LAB_1000_4af9;
  }
  puVar17 = (undefined1 *)0x5200;
  iVar10 = 0xa0;
  do {
    cVar6 = FUN_1000_60d8();
    puVar15 = (undefined1 *)0x3e50;
    iVar11 = 0x10;
    do {
      puVar18 = puVar17;
      puVar17 = puVar18 + 1;
      *puVar18 = *puVar15;
      puVar15 = puVar15 + 2;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (0x7f < (byte)(cVar6 + 1U)) {
      puVar17 = puVar18 + 0x201;
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
LAB_1000_4af9:
  do {
    pbVar1 = (byte *)((int)&stack0x0002 + in_BX + 1);
    bVar19 = false;
    *pbVar1 = *pbVar1 ^ (byte)iVar8;
    iVar11 = param_2 + -1;
    cStack_b = 'K';
    iVar10 = iVar8;
    func_0x00015687();
  } while (bVar19);
  iVar8 = in_BX - 2;
  pbVar1 = (byte *)0x1244;
  bVar19 = CARRY1(*pbVar1,(byte)iVar11);
  *pbVar1 = *pbVar1 + (byte)iVar11;
LAB_1000_4b0f:
  bStack_a = 0x12;
  func_0x000156a8();
  if (bVar19) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
code_r0x00014b14:
  uVar3 = CONCAT11(bStack_a,cStack_b);
  puVar17 = (undefined1 *)puVar16;
  do {
    uVar5 = (byte)((uint)iVar11 >> 8) < (byte)puVar17[iVar8];
    puVar17 = (undefined1 *)0x336e;
    FUN_1000_567c();
    if (!(bool)uVar5) {
      cStack_b = '/';
      bStack_a = 0x4b;
      FUN_1000_5d4f();
      func_0x000156a4();
      if (!(bool)uVar5) break;
    }
    in(0x1f);
  } while( true );
  bVar19 = CARRY1(extraout_DL - (char)*(undefined2 *)(iVar10 + 0x336e),*(byte *)(iVar8 + 0x3389));
  pbVar1 = (byte *)0xb43;
  bVar4 = *pbVar1;
  bVar9 = (byte)iVar11;
  bVar2 = *pbVar1;
  *pbVar1 = bVar2 + bVar9 + bVar19;
  if (!CARRY1(bVar4,bVar9) && !CARRY1(bVar2 + bVar9,bVar19)) {
    puVar17 = (undefined1 *)0x9812;
    cStack_b = '\0';
    bStack_a = 0;
    puVar16 = (undefined2 *)(*(uint *)(iVar8 + 0x3332) | 0x336e);
    pbVar1 = (byte *)((int)puVar16 + iVar8);
    bVar4 = *pbVar1;
    *pbVar1 = *pbVar1 + 0x12;
    *(char *)((int)puVar16 + iVar8 + 0xeaa) =
         *(char *)((int)puVar16 + iVar8 + 0xeaa) + (char)((uint)iVar11 >> 8) + (0xed < bVar4);
    pbVar1 = (byte *)(iVar8 + 1);
    bVar4 = *pbVar1;
    *pbVar1 = *pbVar1 - bVar9;
    if (bVar9 <= bVar4) {
      pbVar1 = (byte *)0x11ea;
      bVar21 = CARRY1(*pbVar1,bVar9);
      *pbVar1 = *pbVar1 + bVar9;
      puVar17 = (undefined1 *)func_0x000156a0();
      bVar19 = true;
      if (bVar21) goto LAB_1000_4b0f;
      bStack_a = (byte)iVar11;
      cStack_9 = (char)((uint)iVar11 >> 8);
      pbVar1 = (byte *)((int)puVar16 + iVar8);
      bVar4 = *pbVar1;
      bVar7 = (byte)puVar17;
      *pbVar1 = *pbVar1 + bVar7;
      iVar8 = iVar8 + 1;
      pbVar1 = (byte *)0xb0d;
      bVar2 = *pbVar1;
      bVar9 = *pbVar1;
      *pbVar1 = bVar9 + bStack_a + CARRY1(bVar4,bVar7);
      if (!CARRY1(bVar2,bStack_a) && !CARRY1(bVar9 + bStack_a,CARRY1(bVar4,bVar7))) {
        *(char *)((int)puVar16 + iVar10) = *(char *)((int)puVar16 + iVar10) + (char)iVar10;
        return 0xe000;
      }
      iVar11 = CONCAT11(cStack_9 + bVar7 + '\x01',bStack_a);
      cStack_b = cStack_9;
    }
  }
  puVar16 = (undefined2 *)((uint)puVar17 | *(uint *)(puVar17 + iVar8 + -0x1c));
  goto code_r0x00014b14;
}


