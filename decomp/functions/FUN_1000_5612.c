/* 1000:5612 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

undefined2 FUN_1000_5612(void)

{
  uint *puVar1;
  byte *pbVar2;
  uint *puVar3;
  byte bVar4;
  char cVar5;
  byte bVar8;
  undefined2 uVar7;
  undefined2 in_AX;
  int in_CX;
  int iVar9;
  int in_BX;
  uint uVar10;
  int unaff_BP;
  uint *puVar11;
  uint *unaff_SI;
  uint *puVar12;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined4 uVar15;
  int iStack_4;
  undefined2 uVar16;
  uint uVar6;
  
  uVar14 = (undefined1)((uint)in_AX >> 8);
  *(undefined1 *)0x3e92 = uVar14;
  bVar4 = (byte)in_AX;
  if (in_CF) {
    uVar10 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)(in_BX + (int)unaff_SI));
    bVar8 = *(byte *)((int)unaff_SI + uVar10 + 100);
    if (in_CX == 1 || bVar8 == bVar4) {
      puVar1 = unaff_SI;
      uVar6 = (uint)(bVar8 < bVar4);
      uVar14 = CARRY2(*puVar1,uVar10) || CARRY2(*puVar1 + uVar10,uVar6);
      *puVar1 = *puVar1 + uVar10 + uVar6;
      FUN_1000_5820();
      FUN_1000_56a1();
      if (!(bool)uVar14) {
        uVar7 = FUN_1000_5c30();
        unaff_SI = (uint *)0xb98e;
        for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
          puVar3 = unaff_DI;
          unaff_DI = unaff_DI + 1;
          puVar1 = unaff_SI;
          unaff_SI = unaff_SI + 1;
          *puVar3 = *puVar1;
        }
        func_0x00015c5b();
      }
    }
    uVar7 = *(undefined2 *)0xaa40;
    *(char *)unaff_DI = (char)uVar7;
    *(char *)unaff_SI = (char)*unaff_SI + (char)uVar7 + -0x45;
    uVar15 = FUN_1000_5782(0x5060);
    if ((int)uVar15 == *(int *)0x3e98) {
      out(*unaff_SI,(int)((ulong)uVar15 >> 0x10));
    }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar7 = (*(code *)((int)unaff_DI + 1))();
    return uVar7;
  }
  uVar13 = false;
  uVar7 = CONCAT11(uVar14,bVar4 - 0x40 | *(byte *)(unaff_BP + (int)unaff_DI));
  while (iVar9 = iStack_4, !(bool)uVar13) {
                    /* WARNING: Call to offcut address within same function */
    uVar16 = 0x55e0;
    uVar15 = func_0x0001565f();
    uVar7 = (undefined2)uVar15;
    if ((bool)uVar13) break;
    pbVar2 = (byte *)((int)unaff_DI + in_BX + 22000);
    bVar4 = *pbVar2;
    bVar8 = (byte)((ulong)uVar15 >> 8);
    *pbVar2 = *pbVar2 + bVar8;
    do {
      puVar12 = unaff_DI;
      puVar11 = unaff_SI;
      *(char *)puVar11 = (char)*puVar12;
      unaff_SI = (uint *)((int)puVar11 + 1);
      in_CX = in_CX + -1;
      unaff_DI = (uint *)((int)puVar12 + 1);
    } while (in_CX != 0);
    bVar4 = *(char *)(unaff_BP + 0xc) + -0x5f + CARRY1(bVar4,bVar8);
    uVar6 = CONCAT11(0x50,bVar4);
    puVar1 = (uint *)((int)puVar12 + 0x1d);
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + uVar6;
    *(int *)((int)puVar12 + 0x1f) = *(int *)((int)puVar12 + 0x1f) + (uint)CARRY2(uVar10,uVar6);
    unaff_DI = (uint *)((int)puVar12 + 3);
    *(byte *)(puVar11 + 9) = (char)puVar11[9] + bVar4 + (uVar6 < *(uint *)((int)puVar12 + 1));
    cVar5 = in((int)((ulong)uVar15 >> 0x10));
    uVar13 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < bVar4);
                    /* WARNING: Call to offcut address within same function */
    iStack_4 = 0x55db;
    uVar7 = func_0x000156b4(uVar16);
    in_BX = iVar9;
  }
  pbVar2 = (byte *)((int)unaff_SI + in_BX + 7);
  *pbVar2 = *pbVar2 ^ (byte)((uint)in_CX >> 8);
  return uVar7;
}


