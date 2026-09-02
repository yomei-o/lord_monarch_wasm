/* 1000:562d */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

void FUN_1000_562d(void)

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
  undefined2 in_AX;
  int iVar9;
  undefined2 uVar10;
  int iVar11;
  undefined2 in_CX;
  undefined2 extraout_DX;
  uint *in_DX;
  uint uVar12;
  uint in_BX;
  byte bVar13;
  byte *unaff_BP;
  uint *puVar14;
  int *unaff_SI;
  uint *puVar15;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar16;
  undefined1 uVar17;
  bool bVar18;
  undefined4 uVar19;
  uint uStack_6;
  
  *unaff_SI = *unaff_SI + (int)unaff_SI;
  iVar9 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + '\x01') + 1;
  iVar11 = CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + (char)*unaff_DI);
  bVar16 = false;
  bVar6 = ((byte)iVar9 | (byte)((uint)in_DX >> 8)) ^ *(byte *)(in_BX + (int)in_DX);
  bVar18 = bVar6 == 0;
  if (!bVar18) {
    *(byte *)0xbb = *(byte *)0xbb ^ bVar6 + 0xb4;
    (unaff_BP + (int)in_DX)[-0x80] = (unaff_BP + (int)in_DX)[-0x80] | (byte)((uint)iVar9 >> 8);
    *unaff_BP = bVar6 + 0xb4;
    unaff_DI = (uint *)(unaff_BP + 2);
    bVar7 = (bVar6 + 0x34) - CARRY1((byte)((uint)unaff_SI >> 8),(byte)*in_DX) | (byte)*in_DX;
    pbVar1 = unaff_BP + (int)unaff_DI + 0x1400;
    bVar13 = (byte)(in_BX >> 8);
    uVar17 = CARRY1(*pbVar1,bVar13);
    bVar6 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar13;
    if (*pbVar1 == 0 || SCARRY1(bVar6,bVar13) != (char)*pbVar1 < '\0') {
      while (uVar12 = uStack_6, !(bool)uVar17) {
                    /* WARNING: Call to offcut address within same function */
        uVar10 = 0x55e0;
        func_0x0001565f();
        if ((bool)uVar17) break;
        pbVar1 = (byte *)((int)unaff_DI + in_BX + 22000);
        bVar6 = *pbVar1;
        *pbVar1 = *pbVar1 + extraout_AH;
        do {
          puVar15 = unaff_DI;
          puVar14 = in_DX;
          *(char *)puVar14 = (char)*puVar15;
          in_DX = (uint *)((int)puVar14 + 1);
          iVar11 = iVar11 + -1;
          unaff_DI = (uint *)((int)puVar15 + 1);
        } while (iVar11 != 0);
        bVar6 = unaff_BP[0xc] + 0xa1 + CARRY1(bVar6,extraout_AH);
        uVar8 = CONCAT11(0x50,bVar6);
        puVar2 = (uint *)((int)puVar15 + 0x1d);
        uVar3 = *puVar2;
        *puVar2 = *puVar2 + uVar8;
        *(int *)((int)puVar15 + 0x1f) = *(int *)((int)puVar15 + 0x1f) + (uint)CARRY2(uVar3,uVar8);
        unaff_DI = (uint *)((int)puVar15 + 3);
        *(byte *)(puVar14 + 9) = (char)puVar14[9] + bVar6 + (uVar8 < *(uint *)((int)puVar15 + 1));
        cVar5 = in(extraout_DX);
        uVar17 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < bVar6);
                    /* WARNING: Call to offcut address within same function */
        uStack_6 = 0x55db;
        func_0x000156b4(uVar10);
        in_BX = uVar12;
      }
      pbVar1 = (byte *)((int)in_DX + in_BX + 7);
      *pbVar1 = *pbVar1 ^ (byte)((uint)iVar11 >> 8);
      return;
    }
    in_BX = CONCAT11(bVar13,(char)in_BX + *(char *)(in_BX + (int)in_DX));
    bVar6 = *(byte *)((int)in_DX + in_BX + 100);
    bVar16 = bVar6 < bVar7;
    bVar18 = bVar6 == bVar7;
  }
  if (iVar11 == 1 || bVar18) {
    puVar2 = in_DX;
    uVar17 = CARRY2(*puVar2,in_BX) || CARRY2(*puVar2 + in_BX,(uint)bVar16);
    *puVar2 = *puVar2 + in_BX + (uint)bVar16;
    FUN_1000_5820();
    FUN_1000_56a1();
    if (!(bool)uVar17) {
      uVar10 = FUN_1000_5c30();
      in_DX = (uint *)0xb98e;
      for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
        puVar4 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar2 = in_DX;
        in_DX = in_DX + 1;
        *puVar4 = *puVar2;
      }
      func_0x00015c5b();
    }
  }
  uVar10 = *(undefined2 *)0xaa40;
  *(char *)unaff_DI = (char)uVar10;
  *(char *)in_DX = (char)*in_DX + (char)uVar10 + -0x45;
  uVar19 = FUN_1000_5782(0x5060);
  if ((int)uVar19 == *(int *)0x3e98) {
    out(*in_DX,(int)((ulong)uVar19 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((int)unaff_DI + 1))();
  return;
}


