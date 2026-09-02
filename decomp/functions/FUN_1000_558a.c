/* 1000:558a */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

undefined2 FUN_1000_558a(void)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  uint *puVar4;
  code *pcVar5;
  byte bVar6;
  char cVar7;
  undefined2 in_AX;
  uint uVar8;
  int iVar9;
  byte bVar12;
  undefined2 uVar11;
  int in_CX;
  int iVar13;
  int unaff_BP;
  int iVar14;
  uint *unaff_SI;
  uint *puVar15;
  uint *unaff_DI;
  uint *puVar16;
  int unaff_ES;
  undefined2 uVar17;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte bVar18;
  bool bVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined4 uVar22;
  int iVar23;
  undefined2 uVar24;
  uint uVar10;
  
  if (in_CX != 0) {
    bVar3 = *(byte *)0x2602;
    uVar8 = CONCAT11((char)((uint)in_AX >> 8),((char)in_AX - (char)*unaff_SI) - in_CF) + 1;
    bVar18 = uVar8 < 0x7201;
    iVar9 = FUN_1000_5a67(uVar8);
    pbVar1 = (byte *)(unaff_BP + iVar9);
    bVar6 = *pbVar1;
    bVar12 = *pbVar1;
    *pbVar1 = bVar12 + bVar3 + bVar18;
    *(int *)0xe806 =
         (*(int *)0xe806 - CONCAT11((char)((uint)unaff_SI >> 8),bVar3)) -
         (uint)(CARRY1(bVar6,bVar3) || CARRY1(bVar12 + bVar3,bVar18));
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar19 = false;
  iVar9 = 0x800;
  iVar13 = 0x300;
  uVar17 = (undefined2)((ulong)*(undefined4 *)0x3e86 >> 0x10);
  iVar14 = (int)*(undefined4 *)0x3e86;
  pcVar5 = (code *)swi(0x1b);
  uVar11 = (*pcVar5)();
  uVar21 = (undefined1)((uint)uVar11 >> 8);
  *(undefined1 *)0x3e92 = uVar21;
  bVar6 = (byte)uVar11;
  if (bVar19) {
    uVar8 = CONCAT11((char)((uint)iVar9 >> 8),(char)iVar9 + *(char *)(iVar9 + (int)unaff_SI));
    bVar12 = *(byte *)((int)unaff_SI + uVar8 + 100);
    if (iVar13 == 1 || bVar12 == bVar6) {
      puVar2 = unaff_SI;
      uVar10 = (uint)(bVar12 < bVar6);
      uVar21 = CARRY2(*puVar2,uVar8) || CARRY2(*puVar2 + uVar8,uVar10);
      *puVar2 = *puVar2 + uVar8 + uVar10;
      FUN_1000_5820();
      FUN_1000_56a1();
      uVar11 = uVar17;
      if (!(bool)uVar21) {
        uVar11 = FUN_1000_5c30();
        unaff_SI = (uint *)0xb98e;
        for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
          puVar4 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          puVar2 = unaff_SI;
          unaff_SI = unaff_SI + 1;
          *puVar4 = *puVar2;
        }
        uVar11 = 0x5691;
        func_0x00015c5b();
      }
    }
    uVar24 = *(undefined2 *)0xaa40;
    *(char *)unaff_DI = (char)uVar24;
    *(char *)unaff_SI = (char)*unaff_SI + (char)uVar24 + -0x45;
    uVar22 = FUN_1000_5782(0x5060,uVar11);
    if ((int)uVar22 == *(int *)0x3e98) {
      out(*unaff_SI,(int)((ulong)uVar22 >> 0x10));
    }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar11 = (*(code *)((int)unaff_DI + 1))();
    return uVar11;
  }
  uVar20 = false;
  uVar11 = CONCAT11(uVar21,bVar6 - 0x40 | *(byte *)(iVar14 + (int)unaff_DI));
  while (!(bool)uVar20) {
                    /* WARNING: Call to offcut address within same function */
    uVar24 = 0x55e0;
    uVar22 = func_0x0001565f();
    uVar11 = (undefined2)uVar22;
    if ((bool)uVar20) break;
    pbVar1 = (byte *)((int)unaff_DI + iVar9 + 22000);
    bVar6 = *pbVar1;
    bVar12 = (byte)((ulong)uVar22 >> 8);
    *pbVar1 = *pbVar1 + bVar12;
    do {
      puVar16 = unaff_DI;
      puVar15 = unaff_SI;
      *(char *)puVar15 = (char)*puVar16;
      unaff_SI = (uint *)((int)puVar15 + 1);
      iVar13 = iVar13 + -1;
      unaff_DI = (uint *)((int)puVar16 + 1);
    } while (iVar13 != 0);
    bVar6 = *(char *)(iVar14 + 0xc) + -0x5f + CARRY1(bVar6,bVar12);
    uVar10 = CONCAT11(0x50,bVar6);
    puVar2 = (uint *)((int)puVar16 + 0x1d);
    uVar8 = *puVar2;
    *puVar2 = *puVar2 + uVar10;
    *(int *)((int)puVar16 + 0x1f) = *(int *)((int)puVar16 + 0x1f) + (uint)CARRY2(uVar8,uVar10);
    unaff_DI = (uint *)((int)puVar16 + 3);
    *(byte *)(puVar15 + 9) = (char)puVar15[9] + bVar6 + (uVar10 < *(uint *)((int)puVar16 + 1));
    cVar7 = in((int)((ulong)uVar22 >> 0x10));
    uVar20 = 0xf4 < (byte)(cVar7 + 1U) || CARRY1(cVar7 + 0xc,0x74 < bVar6);
                    /* WARNING: Call to offcut address within same function */
    iVar23 = 0x55db;
    uVar11 = func_0x000156b4(uVar24);
    iVar9 = unaff_ES;
    unaff_ES = iVar23;
  }
  pbVar1 = (byte *)((int)unaff_SI + iVar9 + 7);
  *pbVar1 = *pbVar1 ^ (byte)((uint)iVar13 >> 8);
  return uVar11;
}


