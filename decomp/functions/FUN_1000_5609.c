/* 1000:5609 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

undefined2 FUN_1000_5609(void)

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
  int in_CX;
  int in_BX;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *unaff_SI;
  uint *puVar14;
  uint *unaff_DI;
  undefined2 uVar15;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined4 uVar18;
  int in_stack_00000000;
  uint uVar8;
  
  uVar15 = (undefined2)((ulong)*(undefined4 *)0x3e86 >> 0x10);
  iVar12 = (int)*(undefined4 *)0x3e86;
  pcVar5 = (code *)swi(0x1b);
  uVar9 = (*pcVar5)();
  uVar17 = (undefined1)((uint)uVar9 >> 8);
  *(undefined1 *)0x3e92 = uVar17;
  bVar6 = (byte)uVar9;
  if ((bool)in_CF) {
    uVar11 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)(in_BX + (int)unaff_SI));
    bVar10 = *(byte *)((int)unaff_SI + uVar11 + 100);
    if (in_CX == 1 || bVar10 == bVar6) {
      puVar1 = unaff_SI;
      uVar8 = (uint)(bVar10 < bVar6);
      uVar17 = CARRY2(*puVar1,uVar11) || CARRY2(*puVar1 + uVar11,uVar8);
      *puVar1 = *puVar1 + uVar11 + uVar8;
      FUN_1000_5820();
      FUN_1000_56a1();
      uVar9 = uVar15;
      if (!(bool)uVar17) {
        uVar9 = FUN_1000_5c30();
        unaff_SI = (uint *)0xb98e;
        for (iVar12 = 0x200; iVar12 != 0; iVar12 = iVar12 + -1) {
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
    uVar18 = FUN_1000_5782(0x5060,uVar9);
    if ((int)uVar18 == *(int *)0x3e98) {
      out(*unaff_SI,(int)((ulong)uVar18 >> 0x10));
    }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar9 = (*(code *)((int)unaff_DI + 1))();
    return uVar9;
  }
  uVar16 = false;
  uVar9 = CONCAT11(uVar17,bVar6 - 0x40 | *(byte *)(iVar12 + (int)unaff_DI));
  while (!(bool)uVar16) {
                    /* WARNING: Call to offcut address within same function */
    uVar18 = func_0x0001565f();
    uVar9 = (undefined2)uVar18;
    if ((bool)uVar16) break;
    pbVar2 = (byte *)((int)unaff_DI + in_BX + 22000);
    bVar6 = *pbVar2;
    bVar10 = (byte)((ulong)uVar18 >> 8);
    *pbVar2 = *pbVar2 + bVar10;
    do {
      puVar14 = unaff_DI;
      puVar13 = unaff_SI;
      *(char *)puVar13 = (char)*puVar14;
      unaff_SI = (uint *)((int)puVar13 + 1);
      in_CX = in_CX + -1;
      unaff_DI = (uint *)((int)puVar14 + 1);
    } while (in_CX != 0);
    bVar6 = *(char *)(iVar12 + 0xc) + -0x5f + CARRY1(bVar6,bVar10);
    uVar8 = CONCAT11(0x50,bVar6);
    puVar1 = (uint *)((int)puVar14 + 0x1d);
    uVar11 = *puVar1;
    *puVar1 = *puVar1 + uVar8;
    *(int *)((int)puVar14 + 0x1f) = *(int *)((int)puVar14 + 0x1f) + (uint)CARRY2(uVar11,uVar8);
    unaff_DI = (uint *)((int)puVar14 + 3);
    *(byte *)(puVar13 + 9) = (char)puVar13[9] + bVar6 + (uVar8 < *(uint *)((int)puVar14 + 1));
    cVar7 = in((int)((ulong)uVar18 >> 0x10));
    uVar16 = 0xf4 < (byte)(cVar7 + 1U) || CARRY1(cVar7 + 0xc,0x74 < bVar6);
                    /* WARNING: Call to offcut address within same function */
    uVar9 = func_0x000156b4();
    in_BX = in_stack_00000000;
    in_stack_00000000 = 0x55db;
  }
  pbVar2 = (byte *)((int)unaff_SI + in_BX + 7);
  *pbVar2 = *pbVar2 ^ (byte)((uint)in_CX >> 8);
  return uVar9;
}


