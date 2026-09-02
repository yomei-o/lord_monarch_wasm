/* 1000:1a90 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011b04) overlaps instruction at (ram,0x00011b03)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00011b01) */
/* WARNING: Removing unreachable block (ram,0x00011b1c) */
/* WARNING: Removing unreachable block (ram,0x00011b27) */

void FUN_1000_1a90(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  char cVar7;
  uint uVar8;
  uint in_AX;
  int in_CX;
  int iVar9;
  undefined2 in_DX;
  byte bVar10;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  uint in_BX;
  uint unaff_BP;
  undefined4 *unaff_SI;
  undefined1 *puVar11;
  undefined2 *unaff_DI;
  undefined1 *puVar12;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar13;
  bool in_ZF;
  bool bVar14;
  char in_SF;
  bool bVar15;
  char in_OF;
  bool bVar16;
  undefined4 uVar17;
  undefined2 in_stack_00000000;
  undefined2 uStack_6;
  undefined4 *puVar18;
  undefined2 *puVar19;
  
  if (in_ZF || in_OF != in_SF) {
    while( true ) {
      uVar8 = in_AX + 1;
      unaff_SI = (undefined4 *)(in_AX * 0xc);
      uVar13 = false;
      bVar16 = false;
      bVar15 = *(int *)((int)unaff_SI + -0x982) < 0;
      bVar14 = *(int *)((int)unaff_SI + -0x982) == 0;
      if (!bVar14) break;
      uVar17 = func_0x00016e05();
      *(uint *)(in_BX + (int)unaff_SI) = *(uint *)(in_BX + (int)unaff_SI) & (uint)unaff_SI;
      in_DX = CONCAT11((char)((ulong)uVar17 >> 0x18) + *(char *)((int)unaff_SI + -0x4f9d),
                       (char)((ulong)uVar17 >> 0x10));
      bVar14 = CARRY2((uint)uVar17,unaff_BP);
      cVar7 = (char)unaff_BP;
      puVar2 = unaff_SI;
      unaff_DS = (undefined2)((ulong)*puVar2 >> 0x10);
      unaff_BP = (uint)*puVar2;
      if (bVar14) {
        puVar5 = unaff_DI;
        unaff_DI = (undefined2 *)((int)unaff_DI + 1);
        puVar2 = unaff_SI;
        unaff_SI = (undefined4 *)((int)unaff_SI + 1);
        *(undefined1 *)puVar5 = *(undefined1 *)puVar2;
        in(0xed);
        if (in_CX != 0) goto LAB_1000_1b10;
        bVar10 = 0;
        goto code_r0x00011afa;
      }
      in_AX = (uint)(byte)((char)uVar17 + cVar7);
    }
  }
  else {
    pbVar3 = (byte *)((int)unaff_SI + -0x29);
    bVar10 = (byte)((uint)in_DX >> 8);
    uVar13 = CARRY1(*pbVar3,bVar10);
    bVar16 = SCARRY1(*pbVar3,bVar10);
    *pbVar3 = *pbVar3 + bVar10;
    bVar15 = (char)*pbVar3 < '\0';
    bVar14 = *pbVar3 == 0;
    uVar8 = in_AX;
  }
  *(undefined2 *)0x3bd6 = 0;
  puVar12 = (undefined1 *)0x3eea;
  puVar11 = (undefined1 *)0x3e20;
  for (iVar9 = 0x2d; iVar9 != 0; iVar9 = iVar9 + -1) {
    puVar6 = puVar12;
    puVar12 = puVar12 + 1;
    puVar4 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar6 = *puVar4;
  }
  in_CX = in_CX + -1;
  if (in_CX == 0) {
    if (bVar14 || bVar16 != bVar15) {
      puVar19 = (undefined2 *)*(undefined2 *)0x3bee;
      puVar18 = (undefined4 *)0x1ab6;
      FUN_1000_5ebc();
      in_DX = extraout_DX;
    }
    else {
      out(in_DX,(char)uVar8);
      uVar13 = unaff_BP < uVar8;
      unaff_ES = in_stack_00000000;
      puVar18 = unaff_SI;
      puVar19 = unaff_DI;
    }
    *(int *)0x3bee = (int)puVar18;
    if ((bool)uVar13) {
LAB_1000_1b10:
      in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX ^ *(byte *)(unaff_DI + -0x2d0c));
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        func_0x00010363();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      *unaff_DI = *(undefined2 *)unaff_SI;
      goto LAB_1000_1ae9;
    }
    if (puVar19 != (undefined2 *)*(undefined2 *)0x3bc6) goto LAB_1000_1ac3;
  }
  else {
LAB_1000_1ac3:
    FUN_1000_0820();
    FUN_1000_5acf();
    func_0x0001083f();
  }
  func_0x0001b848();
  func_0x0001fdbe();
  func_0x0001fe35();
  func_0x0001fdea();
  func_0x0001a1f9();
  FUN_1000_6dce();
  FUN_1000_8ea9();
  FUN_1000_6dce();
  FUN_1000_77f2();
  in_DX = extraout_DX_00;
LAB_1000_1ae9:
  bVar10 = (byte)in_CX;
  unaff_SI = (undefined4 *)0x3eea;
  unaff_DI = (undefined2 *)0x404d;
  *(byte *)0x3483 = *(byte *)0x3483 ^ 1;
  uStack_6 = in_DX;
code_r0x00011afa:
  FUN_1000_6dca();
  func_0x00018ea5();
  FUN_1000_6dca();
                    /* WARNING: Bad instruction - Truncating control flow here */
  func_0x000177ee();
  uVar13 = func_0x00016dfd();
  *(undefined1 *)0xa332 = uVar13;
  *(undefined1 *)unaff_DI = *(undefined1 *)unaff_SI;
  puVar1 = (uint *)((int)unaff_DI + unaff_BP + 1);
  *puVar1 = *puVar1 | (uint)&uStack_6;
  FUN_1000_45d0();
  uStack_6 = 0x483e;
  FUN_1000_38ed();
  puVar1 = (uint *)((int)unaff_DI + in_BX + 1);
  *puVar1 = *puVar1 | in_BX;
  uStack_6 = 0x4846;
  FUN_1000_6b3d();
  FUN_1000_5acf();
  *(byte *)(unaff_BP + 0x123f) = *(byte *)(unaff_BP + 0x123f) & bVar10;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


