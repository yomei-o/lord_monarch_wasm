/* 1000:5622 */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

void FUN_1000_5622(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte extraout_AH;
  int in_AX;
  int iVar9;
  undefined2 uVar10;
  int iVar11;
  undefined2 in_CX;
  undefined2 extraout_DX;
  undefined2 in_DX;
  byte bVar12;
  byte *pbVar13;
  byte *in_BX;
  byte *unaff_BP;
  uint *puVar14;
  int *unaff_SI;
  uint *puVar15;
  uint *puVar16;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar17;
  undefined1 uVar18;
  bool bVar19;
  undefined4 uVar20;
  byte *pbStack_a;
  
  *(char *)unaff_SI = (char)*unaff_SI + (char)in_AX + in_CF;
  unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + (char)in_BX;
  bVar7 = (byte)((uint)(in_AX + 1) >> 8);
  bVar6 = *in_BX;
  cVar5 = (char)(in_AX + 1);
  bVar12 = (byte)((uint)in_DX >> 8);
  puVar15 = (uint *)CONCAT11(bVar12,((char)in_DX - cVar5) - CARRY1(bVar7,*in_BX));
  *unaff_SI = (int)(*unaff_SI + (int)unaff_SI);
  iVar9 = CONCAT11(bVar7 + bVar6,cVar5 + '\x01') + 1;
  iVar11 = CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + (char)*unaff_DI);
  bVar17 = false;
  bVar6 = ((byte)iVar9 | bVar12) ^ in_BX[(int)puVar15];
  bVar19 = bVar6 == 0;
  if (!bVar19) {
    *(byte *)0xbb = *(byte *)0xbb ^ bVar6 + 0xb4;
    (unaff_BP + (int)puVar15)[-0x80] = (unaff_BP + (int)puVar15)[-0x80] | (byte)((uint)iVar9 >> 8);
    *unaff_BP = bVar6 + 0xb4;
    unaff_DI = (uint *)(unaff_BP + 2);
    bVar7 = (bVar6 + 0x34) - CARRY1((byte)((uint)unaff_SI >> 8),(byte)*puVar15) | (byte)*puVar15;
    pbVar1 = unaff_BP + (int)unaff_DI + 0x1400;
    bVar12 = (byte)((uint)in_BX >> 8);
    uVar18 = CARRY1(*pbVar1,bVar12);
    bVar6 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar12;
    if (*pbVar1 == 0 || SCARRY1(bVar6,bVar12) != (char)*pbVar1 < '\0') {
      while (pbVar13 = pbStack_a, !(bool)uVar18) {
                    /* WARNING: Call to offcut address within same function */
        uVar10 = 0x55e0;
        func_0x0001565f();
        if ((bool)uVar18) break;
        pbVar1 = in_BX + (int)unaff_DI + 22000;
        bVar6 = *pbVar1;
        *pbVar1 = *pbVar1 + extraout_AH;
        do {
          puVar16 = unaff_DI;
          puVar14 = puVar15;
          *(char *)puVar14 = (char)*puVar16;
          puVar15 = (uint *)((int)puVar14 + 1);
          iVar11 = iVar11 + -1;
          unaff_DI = (uint *)((int)puVar16 + 1);
        } while (iVar11 != 0);
        bVar6 = unaff_BP[0xc] + 0xa1 + CARRY1(bVar6,extraout_AH);
        uVar8 = CONCAT11(0x50,bVar6);
        puVar2 = (uint *)((int)puVar16 + 0x1d);
        uVar3 = *puVar2;
        *puVar2 = *puVar2 + uVar8;
        *(int *)((int)puVar16 + 0x1f) = *(int *)((int)puVar16 + 0x1f) + (uint)CARRY2(uVar3,uVar8);
        unaff_DI = (uint *)((int)puVar16 + 3);
        *(byte *)(puVar14 + 9) = (char)puVar14[9] + bVar6 + (uVar8 < *(uint *)((int)puVar16 + 1));
        cVar5 = in(extraout_DX);
        uVar18 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < bVar6);
                    /* WARNING: Call to offcut address within same function */
        pbStack_a = (byte *)0x55db;
        func_0x000156b4(uVar10);
        in_BX = pbVar13;
      }
      (in_BX + (int)puVar15)[7] = (in_BX + (int)puVar15)[7] ^ (byte)((uint)iVar11 >> 8);
      return;
    }
    in_BX = (byte *)CONCAT11(bVar12,(char)in_BX + in_BX[(int)puVar15]);
    bVar17 = (in_BX + (int)puVar15)[100] < bVar7;
    bVar19 = (in_BX + (int)puVar15)[100] == bVar7;
  }
  if (iVar11 == 1 || bVar19) {
    puVar2 = puVar15;
    uVar18 = CARRY2(*puVar2,(uint)in_BX) || CARRY2((uint)(in_BX + *puVar2),(uint)bVar17);
    *puVar2 = (uint)(in_BX + *puVar2 + bVar17);
    FUN_1000_5820();
    FUN_1000_56a1();
    if (!(bool)uVar18) {
      uVar10 = FUN_1000_5c30();
      puVar15 = (uint *)0xb98e;
      for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
        puVar4 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar2 = puVar15;
        puVar15 = puVar15 + 1;
        *puVar4 = *puVar2;
      }
      func_0x00015c5b();
    }
  }
  uVar10 = *(undefined2 *)0xaa40;
  *(char *)unaff_DI = (char)uVar10;
  *(char *)puVar15 = (char)*puVar15 + (char)uVar10 + -0x45;
  uVar20 = FUN_1000_5782(0x5060);
  if ((int)uVar20 == *(int *)0x3e98) {
    out(*puVar15,(int)((ulong)uVar20 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((int)unaff_DI + 1))();
  return;
}


