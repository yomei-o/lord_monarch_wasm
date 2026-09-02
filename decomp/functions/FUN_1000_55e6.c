/* 1000:55e6 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

undefined2 FUN_1000_55e6(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint *puVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  byte bVar10;
  undefined2 uVar8;
  uint in_AX;
  uint uVar9;
  int in_CX;
  int iVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  uint *unaff_SI;
  uint *puVar15;
  uint *unaff_DI;
  uint unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined4 uVar19;
  int iStack_16;
  undefined2 uVar20;
  uint uVar7;
  
  iVar12 = (uint)*(byte *)&DAT_0000_3e80 * 2;
  uVar9 = in_AX & 0xff00;
  if ((*(byte *)(iVar12 + 0x32f2) & 8) != 0) {
    func_0x00015c62();
    bVar16 = false;
    iVar12 = 0x800;
    in_CX = 0x300;
    unaff_ES = (uint)((ulong)*(undefined4 *)0x3e86 >> 0x10);
    iVar13 = (int)*(undefined4 *)0x3e86;
    pcVar4 = (code *)swi(0x1b);
    uVar9 = (*pcVar4)();
    uVar18 = (undefined1)(uVar9 >> 8);
    *(undefined1 *)0x3e92 = uVar18;
    if (!bVar16) {
      uVar17 = false;
      uVar8 = CONCAT11(uVar18,(char)uVar9 - 0x40U | *(byte *)(iVar13 + (int)unaff_DI));
      while (iVar11 = iStack_16, !(bool)uVar17) {
                    /* WARNING: Call to offcut address within same function */
        uVar20 = 0x55e0;
        uVar19 = func_0x0001565f();
        uVar8 = (undefined2)uVar19;
        if ((bool)uVar17) break;
        pbVar2 = (byte *)((int)unaff_DI + iVar12 + 22000);
        bVar5 = *pbVar2;
        bVar10 = (byte)((ulong)uVar19 >> 8);
        *pbVar2 = *pbVar2 + bVar10;
        do {
          puVar15 = unaff_DI;
          puVar14 = unaff_SI;
          *(char *)puVar14 = (char)*puVar15;
          unaff_SI = (uint *)((int)puVar14 + 1);
          in_CX = in_CX + -1;
          unaff_DI = (uint *)((int)puVar15 + 1);
        } while (in_CX != 0);
        bVar5 = *(char *)(iVar13 + 0xc) + -0x5f + CARRY1(bVar5,bVar10);
        uVar7 = CONCAT11(0x50,bVar5);
        puVar1 = (uint *)((int)puVar15 + 0x1d);
        uVar9 = *puVar1;
        *puVar1 = *puVar1 + uVar7;
        *(int *)((int)puVar15 + 0x1f) = *(int *)((int)puVar15 + 0x1f) + (uint)CARRY2(uVar9,uVar7);
        unaff_DI = (uint *)((int)puVar15 + 3);
        *(byte *)(puVar14 + 9) = (char)puVar14[9] + bVar5 + (uVar7 < *(uint *)((int)puVar15 + 1));
        cVar6 = in((int)((ulong)uVar19 >> 0x10));
        uVar17 = 0xf4 < (byte)(cVar6 + 1U) || CARRY1(cVar6 + 0xc,0x74 < bVar5);
                    /* WARNING: Call to offcut address within same function */
        iStack_16 = 0x55db;
        uVar8 = func_0x000156b4(uVar20);
        iVar12 = iVar11;
      }
      pbVar2 = (byte *)((int)unaff_SI + iVar12 + 7);
      *pbVar2 = *pbVar2 ^ (byte)((uint)in_CX >> 8);
      return uVar8;
    }
  }
  uVar7 = CONCAT11((char)((uint)iVar12 >> 8),(char)iVar12 + *(char *)(iVar12 + (int)unaff_SI));
  bVar5 = *(byte *)((int)unaff_SI + uVar7 + 100);
  if (in_CX == 1 || bVar5 == (byte)uVar9) {
    puVar1 = unaff_SI;
    uVar9 = (uint)(bVar5 < (byte)uVar9);
    uVar18 = CARRY2(*puVar1,uVar7) || CARRY2(*puVar1 + uVar7,uVar9);
    *puVar1 = *puVar1 + uVar7 + uVar9;
    FUN_1000_5820();
    FUN_1000_56a1();
    uVar9 = unaff_ES;
    if (!(bool)uVar18) {
      uVar8 = FUN_1000_5c30();
      unaff_SI = (uint *)0xb98e;
      for (iVar12 = 0x200; iVar12 != 0; iVar12 = iVar12 + -1) {
        puVar3 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        *puVar3 = *puVar1;
      }
      uVar9 = 0x5691;
      func_0x00015c5b();
    }
  }
  uVar8 = *(undefined2 *)0xaa40;
  *(char *)unaff_DI = (char)uVar8;
  *(char *)unaff_SI = (char)*unaff_SI + (char)uVar8 + -0x45;
  uVar19 = FUN_1000_5782(0x5060,uVar9);
  if ((int)uVar19 == *(int *)0x3e98) {
    out(*unaff_SI,(int)((ulong)uVar19 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar8 = (*(code *)((int)unaff_DI + 1))();
  return uVar8;
}


