/* 1000:86c1 */

/* WARNING: Instruction at (ram,0x000186e5) overlaps instruction at (ram,0x000186e4)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_86c1(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  undefined2 *puVar4;
  byte bVar5;
  undefined2 *puVar6;
  char cVar7;
  code *pcVar8;
  byte bVar9;
  uint uVar10;
  undefined2 uVar11;
  int iVar12;
  int iVar13;
  int in_DX;
  int in_BX;
  undefined2 *unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *puVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  byte *unaff_DI;
  undefined2 *puVar17;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar18;
  undefined4 in_stack_00000000;
  byte *pbVar19;
  undefined2 in_stack_0000cba3;
  
  iVar12 = 0x900;
  while( true ) {
    puVar4 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    bVar9 = (byte)*puVar4;
    if ((bVar9 != 0) && (bVar9 != 0x7b)) break;
    in_BX = in_BX + 1;
    iVar12 = iVar12 + -1;
    if (iVar12 == 0) {
LAB_1000_86e4:
      *(int *)((byte *)((int)unaff_BP + (int)unaff_DI) + -0x1e) =
           *(int *)((byte *)((int)unaff_BP + (int)unaff_DI) + -0x1e) + in_BX;
      pbVar19 = (byte *)((ulong)in_stack_00000000 >> 0x10);
      uVar10 = (CONCAT11((byte)in_BX,(((byte)in_BX ^ 0x90) + 0x14 | 0x3a) + 0xae) ^ 0x9000) & 0xff75
      ;
      puVar2 = (uint *)((byte *)((int)unaff_BP + (int)unaff_DI) + -0x20);
      uVar3 = *puVar2;
      *puVar2 = *puVar2 + uVar10;
      pbVar1 = (byte *)((int)unaff_BP + (int)pbVar19);
      *(uint *)pbVar1 = *(int *)pbVar1 + uVar10 + (uint)CARRY2(uVar3,uVar10);
      pbVar1 = pbVar19;
      *pbVar1 = *pbVar1 ^ (byte)uVar10;
      unaff_DI[0x3c] = 0x12;
      puVar14 = (undefined2 *)0xd27e;
      iVar12 = 0x30;
      do {
        iVar13 = 0x30;
        do {
          puVar15 = puVar14;
          puVar14 = puVar15 + 1;
          bVar18 = (byte)*puVar15 < 0x30;
          uVar11 = 0x4000;
          if (!bVar18) {
            uVar11 = 0xffff;
          }
          pbVar1 = unaff_DI;
          unaff_DI = unaff_DI + 2;
          *(undefined2 *)pbVar1 = uVar11;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      puVar16 = (undefined2 *)&stack0xffef;
      cVar7 = '\x1d';
      do {
        unaff_BP = unaff_BP + -1;
        puVar16 = puVar16 + -1;
        *puVar16 = *unaff_BP;
        cVar7 = cVar7 + -1;
      } while ('\0' < cVar7);
      puVar17 = (undefined2 *)0x0;
      puVar16 = (undefined2 *)0x1200;
      for (iVar12 = 0x900; iVar12 != 0; iVar12 = iVar12 + -1) {
        puVar6 = puVar17;
        puVar17 = puVar17 + 1;
        puVar4 = puVar16;
        puVar16 = puVar16 + 1;
        *puVar6 = *puVar4;
      }
      *(int *)((int)puVar15 + (int)&stack0xfff0) =
           *(int *)((int)puVar15 + (int)&stack0xfff0) + in_DX + (uint)bVar18;
      out(*puVar14,in_DX);
      *(byte *)((int)puVar15 + (int)&stack0x0c39) =
           *(byte *)((int)puVar15 + (int)&stack0x0c39) | 0xe8;
      pcVar8 = (code *)swi(3);
      (*pcVar8)();
      return;
    }
  }
  in_BX = CONCAT11(bVar9,(bVar9 - 0x18) - (bVar9 < 0x7b));
  if ((0x17 < bVar9 && (bVar9 < 0x7b) <= (byte)(bVar9 - 0x18)) &&
     (in_BX = CONCAT11(bVar9,bVar9 - 0xc), 3 < (byte)(bVar9 - 0xc))) {
    pbVar19 = unaff_DI + 1;
    bVar5 = *unaff_DI;
    unaff_DI = unaff_DI + 2;
    *pbVar19 = bVar9;
    in_BX = CONCAT11(0x1d,bVar9 + 0x73 + (bVar9 < bVar5));
  }
  goto LAB_1000_86e4;
}


