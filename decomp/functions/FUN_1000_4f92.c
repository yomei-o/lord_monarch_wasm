/* 1000:4f92 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014fad) overlaps instruction at (ram,0x00014fab)
    */

undefined4
FUN_1000_4f92(undefined2 *param_1,int param_2,undefined2 param_3,byte *param_4,int param_5,
             undefined2 param_6,undefined2 param_7)

{
  byte *pbVar1;
  int *piVar2;
  char *pcVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined2 in_AX;
  int iVar9;
  undefined2 in_CX;
  int iVar10;
  char cVar11;
  undefined2 in_DX;
  byte bVar12;
  byte bVar14;
  int extraout_DX;
  byte *in_BX;
  byte *pbVar15;
  int unaff_BP;
  uint uVar16;
  uint unaff_SI;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined1 *unaff_DI;
  undefined1 *puVar19;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar20;
  bool bVar21;
  char cVar22;
  bool bVar23;
  bool bVar24;
  undefined4 uVar25;
  undefined1 *in_stack_00000000;
  byte bVar13;
  
  bVar13 = (byte)((uint)in_DX >> 8);
  bVar12 = bVar13 + in_BX[(int)unaff_DI];
  iVar10 = (uint)bVar12 << 8;
  puVar17 = (undefined2 *)(unaff_SI ^ *(uint *)(unaff_BP + 0x10));
  if (CARRY1(bVar13,in_BX[(int)unaff_DI]) || bVar12 == 0) {
    pcVar6 = (code *)swi(3);
    uVar25 = (*pcVar6)();
    return uVar25;
  }
  do {
    bVar12 = (byte)((uint)in_AX >> 8);
    iVar9 = CONCAT11(bVar12 + (in_BX + (int)puVar17)[0x2d],(char)in_AX) + -0x5556 +
            (uint)CARRY1(bVar12,(in_BX + (int)puVar17)[0x2d]);
    bVar14 = (byte)((uint)iVar10 >> 8);
    pbVar15 = (byte *)CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX | bVar14);
    bVar13 = (byte)iVar9;
    bVar20 = bVar13 | 0xe8;
    uVar16 = unaff_BP + 1;
    pbVar1 = (byte *)((int)puVar17 + unaff_BP);
    bVar12 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar20;
    puVar18 = puVar17 + -1;
    *(char *)(uVar16 + (int)puVar18) =
         *(char *)(uVar16 + (int)puVar18) + bVar20 + CARRY1(bVar12,bVar20);
    unaff_DI[0x60] = unaff_DI[0x60] ^ bVar14;
    bVar24 = (uVar16 & 0x400) != 0;
    *(char *)(uVar16 + (int)puVar18) =
         *(char *)(uVar16 + (int)puVar18) + bVar20 + ((uVar16 & 1) != 0);
    bVar20 = 0;
    FUN_1000_5c87(CONCAT11((byte)((uint)iVar9 >> 8) | *pbVar15,bVar13) | 0xe8);
    uVar25 = func_0x0001c4dc();
    pbVar1 = (byte *)(uVar16 + (int)puVar18);
    bVar12 = *pbVar1 + (byte)uVar25;
    bVar21 = CARRY1(*pbVar1,(byte)uVar25) || CARRY1(bVar12,bVar20);
    *pbVar1 = bVar12 + bVar20;
    bVar23 = *pbVar1 == 0;
    if (!bVar23) {
      if ((POPCOUNT(*pbVar1) & 1U) == 0) goto code_r0x00015009;
      FUN_1000_5978();
      param_1 = (undefined2 *)0xd27e;
      param_5 = extraout_DX;
      break;
    }
    *(undefined2 *)0xb56a = *(undefined2 *)0x3bc4;
    piVar2 = (int *)((int)puVar18 + unaff_BP + 0x2ab);
    *piVar2 = *piVar2 + uVar16;
    in_CX = CONCAT11(0x12,(char)param_6);
    bVar12 = (byte)param_7;
    in_AX = *(undefined2 *)0xbe09;
    iVar10 = param_5;
    pbVar15 = param_4;
    in_BX = param_4;
    unaff_BP = param_2;
    puVar17 = param_1;
    unaff_DI = in_stack_00000000;
    param_6 = in_CX;
    param_7 = in_AX;
  } while ((char)(bVar12 & 0x7a ^ 0xe8) < '\x01');
  puVar19 = (undefined1 *)0xd27e;
  iVar10 = 0x900;
  do {
    puVar4 = param_1;
    param_1 = param_1 + (uint)bVar24 * -2 + 1;
    puVar5 = puVar19;
    puVar19 = puVar19 + (uint)bVar24 * -2 + 1;
    *puVar5 = (char)*puVar4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  pbVar15[(int)param_1] = pbVar15[(int)param_1] & (byte)param_5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
code_r0x00015009:
  if (!bVar21) {
    if (!bVar23) {
      return uVar25;
    }
    cVar22 = CARRY1((byte)in_CX,pbVar15[(int)unaff_DI]);
    cVar11 = (char)((uint)in_CX >> 8);
    uVar8 = FUN_1000_567c();
    if ((bool)cVar22) {
      *unaff_DI = uVar8;
      *(uint *)((int)puVar17 + -0x21) = *(uint *)((int)puVar17 + -0x21) | (uint)puVar18;
LAB_1000_5029:
      return CONCAT22(param_5,param_7);
    }
    uVar25 = FUN_1000_2fef();
    pcVar3 = (char *)((int)puVar18 + unaff_BP + 0x12ab);
    *pcVar3 = *pcVar3 + cVar11 + cVar22;
    bVar23 = *pcVar3 == '\0';
  }
  uVar7 = *(undefined4 *)(pbVar15 + (int)unaff_DI);
  unaff_ES = (undefined2)((ulong)uVar7 >> 0x10);
  in_CX = (undefined2)uVar7;
  if (!bVar23) goto LAB_1000_5029;
  *(uint *)(unaff_DI + 0xd) = *(uint *)(unaff_DI + 0xd) | (uint)puVar18;
  pbVar15[(int)puVar18] = pbVar15[(int)puVar18] & (byte)uVar7;
  bVar21 = (byte)uVar25 < 6;
  bVar23 = (byte)uVar25 == 6;
  goto code_r0x00015009;
}


