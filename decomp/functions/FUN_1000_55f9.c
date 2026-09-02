/* 1000:55f9 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

undefined2 FUN_1000_55f9(int param_1)

{
  uint *puVar1;
  byte *pbVar2;
  undefined2 uVar3;
  uint *puVar4;
  code *pcVar5;
  byte bVar6;
  char cVar7;
  byte bVar10;
  undefined2 uVar9;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *unaff_SI;
  uint *puVar17;
  uint *unaff_DI;
  undefined2 uVar18;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined4 uVar22;
  uint uVar8;
  
  func_0x00015c62();
  bVar19 = false;
  iVar13 = 0x800;
  iVar11 = 0x300;
  uVar18 = (undefined2)((ulong)*(undefined4 *)0x3e86 >> 0x10);
  iVar15 = (int)*(undefined4 *)0x3e86;
  pcVar5 = (code *)swi(0x1b);
  uVar9 = (*pcVar5)();
  uVar21 = (undefined1)((uint)uVar9 >> 8);
  *(undefined1 *)0x3e92 = uVar21;
  bVar6 = (byte)uVar9;
  if (bVar19) {
    uVar14 = CONCAT11((char)((uint)iVar13 >> 8),(char)iVar13 + *(char *)(iVar13 + (int)unaff_SI));
    bVar10 = *(byte *)((int)unaff_SI + uVar14 + 100);
    if (iVar11 == 1 || bVar10 == bVar6) {
      puVar1 = unaff_SI;
      uVar8 = (uint)(bVar10 < bVar6);
      uVar21 = CARRY2(*puVar1,uVar14) || CARRY2(*puVar1 + uVar14,uVar8);
      *puVar1 = *puVar1 + uVar14 + uVar8;
      FUN_1000_5820();
      FUN_1000_56a1();
      uVar9 = uVar18;
      if (!(bool)uVar21) {
        uVar9 = FUN_1000_5c30();
        unaff_SI = (uint *)0xb98e;
        for (iVar13 = 0x200; iVar13 != 0; iVar13 = iVar13 + -1) {
          puVar4 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          puVar1 = unaff_SI;
          unaff_SI = unaff_SI + 1;
          *puVar4 = *puVar1;
        }
        uVar9 = 0x5691;
        func_0x00015c5b();
      }
    }
    uVar3 = *(undefined2 *)0xaa40;
    *(char *)unaff_DI = (char)uVar3;
    *(char *)unaff_SI = (char)*unaff_SI + (char)uVar3 + -0x45;
    uVar22 = FUN_1000_5782(0x5060,uVar9);
    if ((int)uVar22 == *(int *)0x3e98) {
      out(*unaff_SI,(int)((ulong)uVar22 >> 0x10));
    }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar9 = (*(code *)((int)unaff_DI + 1))();
    return uVar9;
  }
  uVar20 = false;
  uVar9 = CONCAT11(uVar21,bVar6 - 0x40 | *(byte *)(iVar15 + (int)unaff_DI));
  while (iVar12 = param_1, !(bool)uVar20) {
                    /* WARNING: Call to offcut address within same function */
    uVar22 = func_0x0001565f();
    uVar9 = (undefined2)uVar22;
    if ((bool)uVar20) break;
    pbVar2 = (byte *)((int)unaff_DI + iVar13 + 22000);
    bVar6 = *pbVar2;
    bVar10 = (byte)((ulong)uVar22 >> 8);
    *pbVar2 = *pbVar2 + bVar10;
    do {
      puVar17 = unaff_DI;
      puVar16 = unaff_SI;
      *(char *)puVar16 = (char)*puVar17;
      unaff_SI = (uint *)((int)puVar16 + 1);
      iVar11 = iVar11 + -1;
      unaff_DI = (uint *)((int)puVar17 + 1);
    } while (iVar11 != 0);
    bVar6 = *(char *)(iVar15 + 0xc) + -0x5f + CARRY1(bVar6,bVar10);
    uVar8 = CONCAT11(0x50,bVar6);
    puVar1 = (uint *)((int)puVar17 + 0x1d);
    uVar14 = *puVar1;
    *puVar1 = *puVar1 + uVar8;
    *(int *)((int)puVar17 + 0x1f) = *(int *)((int)puVar17 + 0x1f) + (uint)CARRY2(uVar14,uVar8);
    unaff_DI = (uint *)((int)puVar17 + 3);
    *(byte *)(puVar16 + 9) = (char)puVar16[9] + bVar6 + (uVar8 < *(uint *)((int)puVar17 + 1));
    cVar7 = in((int)((ulong)uVar22 >> 0x10));
    uVar20 = 0xf4 < (byte)(cVar7 + 1U) || CARRY1(cVar7 + 0xc,0x74 < bVar6);
                    /* WARNING: Call to offcut address within same function */
    param_1 = 0x55db;
    uVar9 = func_0x000156b4();
    iVar13 = iVar12;
  }
  pbVar2 = (byte *)((int)unaff_SI + iVar13 + 7);
  *pbVar2 = *pbVar2 ^ (byte)((uint)iVar11 >> 8);
  return uVar9;
}


