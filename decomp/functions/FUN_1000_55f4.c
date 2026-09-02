/* 1000:55f4 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

undefined2 FUN_1000_55f4(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint *puVar3;
  code *pcVar4;
  char cVar5;
  byte bVar8;
  uint uVar6;
  undefined2 uVar7;
  undefined2 in_AX;
  byte bVar9;
  undefined2 in_CX;
  int iVar10;
  int iVar11;
  int in_BX;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint *unaff_SI;
  uint *puVar15;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined4 uVar19;
  int iStack_4;
  undefined2 uVar20;
  
  bVar9 = (byte)in_CX ^ *(byte *)(in_BX + (int)unaff_SI);
  iVar10 = CONCAT11((char)((uint)in_CX >> 8),bVar9);
  if (bVar9 != 0) {
    func_0x00015c62();
    bVar16 = false;
    in_BX = 0x800;
    iVar10 = 0x300;
    unaff_ES = (undefined2)((ulong)*(undefined4 *)0x3e86 >> 0x10);
    iVar13 = (int)*(undefined4 *)0x3e86;
    pcVar4 = (code *)swi(0x1b);
    in_AX = (*pcVar4)();
    uVar18 = (undefined1)((uint)in_AX >> 8);
    *(undefined1 *)0x3e92 = uVar18;
    if (!bVar16) {
      uVar17 = false;
      uVar7 = CONCAT11(uVar18,(char)in_AX - 0x40U | *(byte *)(iVar13 + (int)unaff_DI));
      while (iVar11 = iStack_4, !(bool)uVar17) {
                    /* WARNING: Call to offcut address within same function */
        uVar20 = 0x55e0;
        uVar19 = func_0x0001565f();
        uVar7 = (undefined2)uVar19;
        if ((bool)uVar17) break;
        pbVar2 = (byte *)((int)unaff_DI + in_BX + 22000);
        bVar9 = *pbVar2;
        bVar8 = (byte)((ulong)uVar19 >> 8);
        *pbVar2 = *pbVar2 + bVar8;
        do {
          puVar15 = unaff_DI;
          puVar14 = unaff_SI;
          *(char *)puVar14 = (char)*puVar15;
          unaff_SI = (uint *)((int)puVar14 + 1);
          iVar10 = iVar10 + -1;
          unaff_DI = (uint *)((int)puVar15 + 1);
        } while (iVar10 != 0);
        bVar9 = *(char *)(iVar13 + 0xc) + -0x5f + CARRY1(bVar9,bVar8);
        uVar6 = CONCAT11(0x50,bVar9);
        puVar1 = (uint *)((int)puVar15 + 0x1d);
        uVar12 = *puVar1;
        *puVar1 = *puVar1 + uVar6;
        *(int *)((int)puVar15 + 0x1f) = *(int *)((int)puVar15 + 0x1f) + (uint)CARRY2(uVar12,uVar6);
        unaff_DI = (uint *)((int)puVar15 + 3);
        *(byte *)(puVar14 + 9) = (char)puVar14[9] + bVar9 + (uVar6 < *(uint *)((int)puVar15 + 1));
        cVar5 = in((int)((ulong)uVar19 >> 0x10));
        uVar17 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < bVar9);
                    /* WARNING: Call to offcut address within same function */
        iStack_4 = 0x55db;
        uVar7 = func_0x000156b4(uVar20);
        in_BX = iVar11;
      }
      pbVar2 = (byte *)((int)unaff_SI + in_BX + 7);
      *pbVar2 = *pbVar2 ^ (byte)((uint)iVar10 >> 8);
      return uVar7;
    }
  }
  uVar12 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)(in_BX + (int)unaff_SI));
  bVar9 = *(byte *)((int)unaff_SI + uVar12 + 100);
  if (iVar10 == 1 || bVar9 == (byte)in_AX) {
    puVar1 = unaff_SI;
    uVar6 = (uint)(bVar9 < (byte)in_AX);
    uVar18 = CARRY2(*puVar1,uVar12) || CARRY2(*puVar1 + uVar12,uVar6);
    *puVar1 = *puVar1 + uVar12 + uVar6;
    FUN_1000_5820();
    FUN_1000_56a1();
    in_AX = unaff_ES;
    if (!(bool)uVar18) {
      uVar7 = FUN_1000_5c30();
      unaff_SI = (uint *)0xb98e;
      for (iVar10 = 0x200; iVar10 != 0; iVar10 = iVar10 + -1) {
        puVar3 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        *puVar3 = *puVar1;
      }
      in_AX = 0x5691;
      func_0x00015c5b();
    }
  }
  uVar7 = *(undefined2 *)0xaa40;
  *(char *)unaff_DI = (char)uVar7;
  *(char *)unaff_SI = (char)*unaff_SI + (char)uVar7 + -0x45;
  uVar19 = FUN_1000_5782(0x5060,in_AX);
  if ((int)uVar19 == *(int *)0x3e98) {
    out(*unaff_SI,(int)((ulong)uVar19 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*(code *)((int)unaff_DI + 1))();
  return uVar7;
}


