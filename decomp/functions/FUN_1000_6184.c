/* 1000:6184 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016240) overlaps instruction at (ram,0x0001623f)
    */

int FUN_1000_6184(undefined2 param_1)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  byte bVar7;
  char cVar8;
  undefined1 uVar9;
  undefined1 extraout_AL;
  int iVar10;
  char cVar14;
  uint uVar11;
  int iVar12;
  uint uVar13;
  char extraout_AH;
  char cVar15;
  byte in_CL;
  byte bVar16;
  uint extraout_DX;
  int in_BX;
  int iVar17;
  undefined2 *unaff_BP;
  uint uVar18;
  int unaff_SI;
  undefined1 *puVar19;
  undefined2 *puVar20;
  uint *puVar21;
  undefined2 *unaff_DI;
  int *piVar22;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar23;
  bool bVar24;
  undefined4 uVar25;
  int in_stack_0000b8bf;
  undefined2 *in_stack_0000b8c1;
  
  puVar19 = (undefined1 *)(unaff_SI + 1);
  FUN_1000_1a90();
  bVar7 = FUN_1000_a120();
  *(byte *)0xe83a = *(byte *)0xe83a & in_CL;
  puVar20 = (undefined2 *)&stack0x0002;
  cVar15 = '\x14';
  do {
    unaff_BP = unaff_BP + -1;
    puVar20 = puVar20 + -1;
    *puVar20 = *unaff_BP;
    cVar15 = cVar15 + -1;
  } while ('\0' < cVar15);
  pbVar1 = (byte *)((int)unaff_DI + in_BX + 0x30);
  *pbVar1 = *pbVar1 ^ bVar7;
  uVar25 = FUN_1000_771b();
  iVar10 = (int)uVar25 + 1;
  cVar15 = (&stack0x3043)[(int)unaff_DI];
  bVar16 = (byte)((ulong)uVar25 >> 0x10);
  bVar7 = (byte)iVar10;
  *(byte *)((int)&stack0x0002 + (int)puVar19) = *(byte *)((int)&stack0x0002 + (int)puVar19) | bVar7;
  cVar14 = (char)((uint)iVar10 >> 8);
  cVar8 = -((char)bVar7 >> 7);
  in_BX = in_BX + 1;
  *(byte *)((int)&stack0x0002 + (int)puVar19) = *(byte *)((int)&stack0x0002 + (int)puVar19) ^ bVar16
  ;
  uVar18 = (uint)&stack0x0002 & (uint)unaff_DI;
  *(undefined2 *)0x3e76 = unaff_DI;
  *(int *)(uVar18 + 2) = in_BX;
  bVar7 = (byte)in_BX & puVar19[uVar18];
  iVar10 = CONCAT11((char)((uint)in_BX >> 8),bVar7);
  out(*puVar19,CONCAT11((char)((ulong)uVar25 >> 0x18) + cVar15,bVar16));
  if (bVar7 == 0) {
    cVar15 = *(char *)(uVar18 + 0x30);
    puVar20 = (undefined2 *)0x612;
    *(byte *)(iVar10 + 0x612) = *(byte *)(iVar10 + 0x612) ^ bVar16;
    cVar15 = CARRY1(cVar8 + cVar15 + cVar14 * -0x42,*(byte *)0x5056);
    uVar9 = FUN_1000_5b27();
    out(0x23,uVar9);
    *(char *)(uVar18 + 0x3e50) = (*(char *)(uVar18 + 0x3e50) - (char)((uint)iVar10 >> 8)) - cVar15;
  }
  else {
    pbVar1 = (byte *)(unaff_SI + 2);
    *pbVar1 = *pbVar1 ^ in_CL;
    if ((POPCOUNT(*pbVar1) & 1U) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar20 = (undefined2 *)0x3e50;
    in_stack_0000b8bf = CONCAT11(cVar14,cVar8);
    in_stack_0000b8c1 = unaff_DI;
  }
  *unaff_DI = *puVar20;
  unaff_DI[0x28] = puVar20[1];
  pbVar1 = (byte *)(puVar20 + 2);
  *pbVar1 = *pbVar1 ^ in_CL;
  *(byte *)(unaff_DI + 0x50) = *(byte *)(puVar20 + 2);
  iVar10 = 0x10;
  puVar5 = (uint *)(in_stack_0000b8bf + -2);
  piVar6 = (int *)((int)unaff_DI + -0x411);
  do {
    piVar22 = piVar6;
    puVar21 = puVar5;
    puVar5 = puVar21 + 1;
    uVar18 = *puVar21;
    piVar22[-0x28] = uVar18;
    piVar22[0x28] = uVar18;
    uVar11 = CONCAT11((char)uVar18,(char)(uVar18 >> 8));
    uVar4 = uVar11 * 2;
    cVar15 = ((uVar18 & 0x100) != 0) << 7;
    iVar17 = CONCAT11(cVar15,CARRY2(uVar11,uVar11));
    uVar18 = uVar11 | uVar4 | uVar11 >> 1;
    bVar7 = (byte)(uVar18 >> 8);
    iVar12 = CONCAT11((char)uVar18,bVar7);
    *(bool *)((int)piVar22 + -1) = CARRY2(uVar11,uVar11);
    *piVar22 = iVar12;
    *(char *)((int)piVar22 + 1) = cVar15;
    iVar10 = iVar10 + -1;
    piVar6 = piVar22 + 0x28;
  } while (iVar10 != 0);
  *(byte *)puVar5 = (byte)*puVar5 ^ bVar7;
  pbVar1 = (byte *)((int)piVar22 + 0x4f);
  *pbVar1 = *pbVar1 + bVar7;
  *(byte *)((int)piVar22 + 0x4f) = bVar7;
  puVar19 = (undefined1 *)((int)piVar22 + 0x51);
  uVar13 = iVar12 + 1;
  *(byte *)(puVar5 + uVar11) =
       (byte)puVar5[uVar11] + (byte)uVar13 + (((uint)((int)unaff_DI + -0x411) & 1) != 0);
  uVar18 = (in_stack_0000b8bf + -2) * 0x100;
  bVar24 = (uVar18 & 0x400) != 0;
  if ((uVar18 & 0x800) == 0) {
    *(byte *)(puVar21 + 0x1a4) = (byte)puVar21[0x1a4] + (char)(uVar13 >> 8);
    *(byte *)(piVar22 + 0x28) = (byte)*puVar5;
    iVar12 = (uint)bVar24 * -2 + 2;
    puVar19 = puVar19 + uVar13 + (uint)bVar24 * -2;
    pbVar1 = (byte *)((int)puVar5 + iVar17 + iVar12 + 0x10);
    *pbVar1 = *pbVar1 | (byte)(uVar11 >> 1);
    pbVar1 = (byte *)((int)puVar5 + iVar17 + iVar12);
    *pbVar1 = *pbVar1 << 1;
    LOCK();
    pbVar1 = (byte *)((int)puVar5 + iVar17 + iVar12 + 0x30ac);
    *pbVar1 = *pbVar1 ^ (byte)uVar13;
    UNLOCK();
  }
  iVar12 = *(int *)0x32a8;
  FUN_1000_5aba();
  puVar19[uVar4 + 0xbad9] = puVar19[uVar4 + 0xbad9] - (byte)iVar10;
  puVar19[uVar4] = puVar19[uVar4] + (char)((uint)iVar10 >> 8);
  piVar2 = (int *)(iVar17 + iVar12 + 0x10ff);
  *piVar2 = *piVar2 >> ((byte)iVar10 & 0x1f);
  iVar10 = iVar17;
  cVar15 = extraout_AH;
  do {
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      puVar3 = puVar19;
      puVar19 = puVar19 + (uint)bVar24 * -2 + 1;
      *puVar3 = extraout_AL;
    }
    bVar23 = CARRY2((uint)puVar19,extraout_DX);
    puVar19 = puVar19 + extraout_DX;
    cVar15 = cVar15 + -1;
    iVar10 = iVar17;
  } while (cVar15 != '\0');
  return (byte)-bVar23 + 0x6108 + (uint)bVar23;
}


