/* 1000:0dff */

/* WARNING: Instruction at (ram,0x00010e9f) overlaps instruction at (ram,0x00010e9c)
    */

undefined1 * FUN_1000_0dff(void)

{
  uint *puVar1;
  char *pcVar2;
  int *piVar3;
  uint uVar4;
  undefined1 *puVar5;
  byte bVar6;
  byte bVar7;
  undefined1 uVar8;
  undefined2 in_AX;
  int iVar9;
  undefined1 *puVar10;
  undefined1 extraout_AH;
  uint in_CX;
  byte *in_BX;
  undefined1 uVar11;
  uint unaff_BP;
  int *unaff_SI;
  int *piVar12;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar13;
  bool bVar14;
  undefined1 auStack_e [4];
  
  uVar11 = (undefined1)((uint)in_BX >> 8);
  puVar1 = (uint *)((int)unaff_SI + unaff_BP + 0x6eaa);
  *puVar1 = *puVar1 & unaff_BP;
  bVar13 = (byte)in_AX | 0x8a;
  uVar8 = (undefined1)((uint)in_AX >> 8);
  bVar6 = bVar13 + *(byte *)((int)unaff_SI + 0xb);
  iVar9 = CONCAT11(uVar8,bVar6);
  if (CARRY1(bVar13,*(byte *)((int)unaff_SI + 0xb))) {
LAB_1000_0e1f:
    iVar9 = FUN_1000_0f02();
    if ((char)unaff_SI[7] != '\0') {
      bVar13 = *(byte *)((int)unaff_SI + 5);
      in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),bVar13);
      if ((bVar13 & 8) == 0) {
        bVar13 = bVar13 + 4;
        *(byte *)((int)unaff_SI + 5) = bVar13;
        pcVar2 = (char *)((uint)bVar13 + (int)unaff_SI);
        *pcVar2 = *pcVar2 + (char)in_CX;
        in_BX = (byte *)(bVar13 + 1);
        bVar13 = (byte)(iVar9 + 1);
        *(byte *)((int)unaff_SI + 0xb) = bVar13;
        bVar6 = (byte)((uint)(iVar9 + 1) >> 8);
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] | bVar6;
        bVar14 = SCARRY1(bVar13,'$');
        puVar10 = (undefined1 *)CONCAT11(bVar6,bVar13 + 0x24);
        piVar12 = unaff_SI;
        if ((byte)(bVar13 + 0x24) != '\0' && -0x25 < (char)bVar13) goto LAB_1000_0e8f;
        *(char *)(unaff_BP + (int)unaff_SI) =
             *(char *)(unaff_BP + (int)unaff_SI) + bVar6 + (0xdb < bVar13);
        *(byte *)((int)unaff_SI + 0x1f) = *(byte *)((int)unaff_SI + 0x1f) | 4;
      }
    }
    uVar11 = (undefined1)((uint)in_BX >> 8);
    bVar13 = 0;
    iVar9 = FUN_1000_0efe();
    unaff_DI = unaff_DI + 1;
  }
  else {
    bVar13 = bVar6 < *(byte *)((int)unaff_SI + 0xd);
    if (!(bool)bVar13) {
      bVar7 = bVar6 - *(byte *)((int)unaff_SI + 0xb);
      iVar9 = CONCAT11(uVar8,bVar7);
      if ((bVar6 < *(byte *)((int)unaff_SI + 0xb)) ||
         (bVar13 = bVar7 < *(byte *)((int)unaff_SI + 0xd), bVar7 <= *(byte *)((int)unaff_SI + 0xd)))
      goto LAB_1000_0e1f;
    }
  }
  *unaff_SI = *unaff_SI + iVar9 + (uint)bVar13;
  in_BX = (byte *)CONCAT11(uVar11,0x21);
  *in_BX = *in_BX | 0x21;
  puVar1 = (uint *)((int)unaff_SI + 0x23);
  uVar4 = *puVar1;
  *puVar1 = *puVar1 + (int)unaff_SI;
  piVar12 = (int *)((int)unaff_SI + -1);
  *(uint *)(in_BX + (int)piVar12 + 0xd) =
       *(int *)(in_BX + (int)piVar12 + 0xd) + in_CX + (uint)CARRY2(uVar4,(uint)unaff_SI);
  in_CX = (uint)(byte)(((char)in_CX - (in_BX + (int)piVar12)[0x1c4c]) -
                      (0xbb76 < CONCAT11((char)((uint)iVar9 >> 8),(char)iVar9 + '@')));
  FUN_1000_1371();
  FUN_1000_7245();
  FUN_1000_7245();
  FUN_1000_0eb7();
  bVar14 = false;
  puVar10 = (undefined1 *)(CONCAT11(extraout_AH,(char)unaff_SI[0xf]) & 0xff8c);
LAB_1000_0e8f:
  bVar13 = (byte)in_BX;
  if (bVar14) {
    pcVar2 = (char *)((int)piVar12 + unaff_BP + 0x1c4d);
    *pcVar2 = *pcVar2 + (char)in_CX;
    uVar8 = func_0x00013a6a();
    puVar10 = auStack_e;
    puVar5 = unaff_DI + 1;
    *unaff_DI = uVar8;
    unaff_DI = unaff_DI + 2;
    *puVar5 = uVar8;
    bVar14 = CARRY1(bVar13,unaff_DI[unaff_BP + 0x302b]);
    piVar12 = piVar12 + 1;
  }
  else {
    bVar14 = false;
    *(byte *)(unaff_BP - 0x6c) = *(byte *)(unaff_BP - 0x6c) ^ (byte)puVar10;
  }
  iVar9 = ((uint)unaff_DI & 3) - ((uint)piVar12 & 3);
  piVar12 = (int *)((int)piVar12 + (uint)(0 < iVar9) * iVar9);
  piVar3 = piVar12 + 0x1d;
  *piVar3 = (*piVar3 - (int)piVar12) - (uint)bVar14;
  return puVar10;
}


