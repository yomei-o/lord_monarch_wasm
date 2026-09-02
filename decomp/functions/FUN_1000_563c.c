/* 1000:563c */

/* WARNING: Instruction at (ram,0x000156bb) overlaps instruction at (ram,0x000156ba)
    */
/* WARNING: Removing unreachable block (ram,0x00015699) */

void FUN_1000_563c(void)

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
  undefined2 uVar9;
  int in_CX;
  int iVar10;
  undefined2 extraout_DX;
  undefined2 in_DX;
  uint uVar11;
  uint in_BX;
  byte bVar12;
  byte *unaff_BP;
  uint *puVar13;
  uint *unaff_SI;
  uint *puVar14;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  undefined1 uVar15;
  char in_ZF;
  undefined4 uVar16;
  uint uStack_4;
  
  if (!(bool)in_CF && !(bool)in_ZF) {
    bVar6 = (char)in_AX + 0xb4;
    *(byte *)0xbb = *(byte *)0xbb ^ bVar6;
    (unaff_BP + (int)unaff_SI)[-0x80] = (unaff_BP + (int)unaff_SI)[-0x80] | (byte)((uint)in_AX >> 8)
    ;
    *unaff_BP = bVar6;
    unaff_DI = (uint *)(unaff_BP + 2);
    bVar7 = ((char)in_AX + '4') - CARRY1((byte)((uint)in_DX >> 8),(byte)*unaff_SI) | (byte)*unaff_SI
    ;
    pbVar1 = unaff_BP + (int)unaff_DI + 0x1400;
    bVar12 = (byte)(in_BX >> 8);
    uVar15 = CARRY1(*pbVar1,bVar12);
    bVar6 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar12;
    if (*pbVar1 == 0 || SCARRY1(bVar6,bVar12) != (char)*pbVar1 < '\0') {
      while (uVar11 = uStack_4, !(bool)uVar15) {
                    /* WARNING: Call to offcut address within same function */
        uVar9 = 0x55e0;
        func_0x0001565f();
        if ((bool)uVar15) break;
        pbVar1 = (byte *)((int)unaff_DI + in_BX + 22000);
        bVar6 = *pbVar1;
        *pbVar1 = *pbVar1 + extraout_AH;
        do {
          puVar14 = unaff_DI;
          puVar13 = unaff_SI;
          *(char *)puVar13 = (char)*puVar14;
          unaff_SI = (uint *)((int)puVar13 + 1);
          in_CX = in_CX + -1;
          unaff_DI = (uint *)((int)puVar14 + 1);
        } while (in_CX != 0);
        bVar6 = unaff_BP[0xc] + 0xa1 + CARRY1(bVar6,extraout_AH);
        uVar8 = CONCAT11(0x50,bVar6);
        puVar2 = (uint *)((int)puVar14 + 0x1d);
        uVar3 = *puVar2;
        *puVar2 = *puVar2 + uVar8;
        *(int *)((int)puVar14 + 0x1f) = *(int *)((int)puVar14 + 0x1f) + (uint)CARRY2(uVar3,uVar8);
        unaff_DI = (uint *)((int)puVar14 + 3);
        *(byte *)(puVar13 + 9) = (char)puVar13[9] + bVar6 + (uVar8 < *(uint *)((int)puVar14 + 1));
        cVar5 = in(extraout_DX);
        uVar15 = 0xf4 < (byte)(cVar5 + 1U) || CARRY1(cVar5 + 0xc,0x74 < bVar6);
                    /* WARNING: Call to offcut address within same function */
        uStack_4 = 0x55db;
        func_0x000156b4(uVar9);
        in_BX = uVar11;
      }
      pbVar1 = (byte *)((int)unaff_SI + in_BX + 7);
      *pbVar1 = *pbVar1 ^ (byte)((uint)in_CX >> 8);
      return;
    }
    in_BX = CONCAT11(bVar12,(char)in_BX + *(char *)(in_BX + (int)unaff_SI));
    bVar6 = *(byte *)((int)unaff_SI + in_BX + 100);
    in_CF = bVar6 < bVar7;
    in_ZF = bVar6 == bVar7;
  }
  if (in_CX == 1 || in_ZF != '\0') {
    puVar2 = unaff_SI;
    uVar15 = CARRY2(*puVar2,in_BX) || CARRY2(*puVar2 + in_BX,(uint)in_CF);
    *puVar2 = *puVar2 + in_BX + (uint)in_CF;
    FUN_1000_5820();
    FUN_1000_56a1();
    if (!(bool)uVar15) {
      uVar9 = FUN_1000_5c30();
      unaff_SI = (uint *)0xb98e;
      for (iVar10 = 0x200; iVar10 != 0; iVar10 = iVar10 + -1) {
        puVar4 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar2 = unaff_SI;
        unaff_SI = unaff_SI + 1;
        *puVar4 = *puVar2;
      }
      func_0x00015c5b();
    }
  }
  uVar9 = *(undefined2 *)0xaa40;
  *(char *)unaff_DI = (char)uVar9;
  *(char *)unaff_SI = (char)*unaff_SI + (char)uVar9 + -0x45;
  uVar16 = FUN_1000_5782(0x5060);
  if ((int)uVar16 == *(int *)0x3e98) {
    out(*unaff_SI,(int)((ulong)uVar16 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((int)unaff_DI + 1))();
  return;
}


