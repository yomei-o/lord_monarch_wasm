/* 1000:5641 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

void FUN_1000_5641(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte extraout_AH;
  undefined2 in_AX;
  undefined2 uVar8;
  int in_CX;
  int iVar9;
  undefined2 extraout_DX;
  undefined2 in_DX;
  int in_BX;
  byte bVar11;
  uint uVar10;
  int unaff_BP;
  uint *puVar12;
  uint *unaff_SI;
  uint *puVar13;
  uint *puVar14;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar15;
  undefined4 uVar16;
  byte *in_stack_00000000;
  int iStack_2;
  uint uVar7;
  
  bVar4 = (byte)in_AX;
  *(byte *)0xbb = *(byte *)0xbb ^ bVar4;
  pbVar1 = (byte *)((int)unaff_SI + unaff_BP + -0x80);
  *pbVar1 = *pbVar1 | (byte)((uint)in_AX >> 8);
  *in_stack_00000000 = bVar4;
  puVar14 = (uint *)(in_stack_00000000 + 2);
  bVar6 = (bVar4 + 0x80) - CARRY1((byte)((uint)in_DX >> 8),(byte)*unaff_SI) | (byte)*unaff_SI;
  pbVar1 = (byte *)((int)puVar14 + unaff_BP + 0x1400);
  bVar11 = (byte)((uint)in_BX >> 8);
  uVar15 = CARRY1(*pbVar1,bVar11);
  bVar4 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar11;
  if (*pbVar1 != 0 && SCARRY1(bVar4,bVar11) == (char)*pbVar1 < '\0') {
    uVar10 = CONCAT11(bVar11,(char)in_BX + *(char *)(in_BX + (int)unaff_SI));
    bVar4 = *(byte *)((int)unaff_SI + uVar10 + 100);
    if (in_CX == 1 || bVar4 == bVar6) {
      puVar2 = unaff_SI;
      uVar7 = (uint)(bVar4 < bVar6);
      uVar15 = CARRY2(*puVar2,uVar10) || CARRY2(*puVar2 + uVar10,uVar7);
      *puVar2 = *puVar2 + uVar10 + uVar7;
      FUN_1000_5820();
      FUN_1000_56a1();
      if (!(bool)uVar15) {
        uVar8 = FUN_1000_5c30();
        unaff_SI = (uint *)0xb98e;
        for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
          puVar3 = puVar14;
          puVar14 = puVar14 + 1;
          puVar2 = unaff_SI;
          unaff_SI = unaff_SI + 1;
          *puVar3 = *puVar2;
        }
        func_0x00015c5b();
      }
    }
    uVar8 = *(undefined2 *)0xaa40;
    *(char *)puVar14 = (char)uVar8;
    *(char *)unaff_SI = (char)*unaff_SI + (char)uVar8 + -0x45;
    uVar16 = FUN_1000_5782(0x5060);
    if ((int)uVar16 == *(int *)0x3e98) {
      out(*unaff_SI,(int)((ulong)uVar16 >> 0x10));
    }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((int)puVar14 + 1))();
    return;
  }
                    /* WARNING: Call to offcut address within same function */
  while ((iVar9 = iStack_2, !(bool)uVar15 && (func_0x0001565f(), !(bool)uVar15))) {
    pbVar1 = (byte *)((int)puVar14 + in_BX + 22000);
    bVar4 = *pbVar1;
    *pbVar1 = *pbVar1 + extraout_AH;
    do {
      puVar13 = puVar14;
      puVar12 = unaff_SI;
      *(char *)puVar12 = (char)*puVar13;
      unaff_SI = (uint *)((int)puVar12 + 1);
      in_CX = in_CX + -1;
      puVar14 = (uint *)((int)puVar13 + 1);
    } while (in_CX != 0);
    bVar4 = *(char *)(unaff_BP + 0xc) + -0x5f + CARRY1(bVar4,extraout_AH);
    uVar7 = CONCAT11(0x50,bVar4);
    puVar2 = (uint *)((int)puVar13 + 0x1d);
    uVar10 = *puVar2;
    *puVar2 = *puVar2 + uVar7;
    *(int *)((int)puVar13 + 0x1f) = *(int *)((int)puVar13 + 0x1f) + (uint)CARRY2(uVar10,uVar7);
    puVar14 = (uint *)((int)puVar13 + 3);
    *(byte *)(puVar12 + 9) = (char)puVar12[9] + bVar4 + (uVar7 < *(uint *)((int)puVar13 + 1));
    cVar5 = in(extraout_DX);
    uVar15 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < bVar4);
                    /* WARNING: Call to offcut address within same function */
    iStack_2 = 0x55db;
    func_0x000156b4();
    in_BX = iVar9;
  }
  pbVar1 = (byte *)((int)unaff_SI + in_BX + 7);
  *pbVar1 = *pbVar1 ^ (byte)((uint)in_CX >> 8);
  return;
}


