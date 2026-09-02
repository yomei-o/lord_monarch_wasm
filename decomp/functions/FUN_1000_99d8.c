/* 1000:99d8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00019a41) overlaps instruction at (ram,0x00019a40)
    */
/* WARNING: Removing unreachable block (ram,0x00019a64) */

void FUN_1000_99d8(void)

{
  char *pcVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined2 uVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  char cVar9;
  undefined1 *puVar10;
  undefined2 in_CX;
  undefined1 uVar11;
  byte extraout_DL;
  byte bVar12;
  byte extraout_DL_00;
  byte extraout_DH;
  int in_BX;
  int iVar13;
  int unaff_BP;
  undefined2 *unaff_SI;
  int unaff_DI;
  undefined2 uVar14;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  char cVar15;
  longdouble in_ST0;
  undefined1 *puVar16;
  char *pcVar17;
  undefined4 uStack_2c;
  undefined1 *puStack_2a;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  byte bStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 *puStack_1a;
  int iStack_18;
  undefined2 uStack_16;
  undefined1 uVar18;
  
  func_0x0001c8a4();
  pcVar1 = (char *)((int)unaff_SI + unaff_BP + 0x4aa);
  *pcVar1 = *pcVar1 + (char)((uint)in_CX >> 8) + in_CF;
  unaff_SI[0xb0f] = (int)ROUND(in_ST0);
  uVar6 = *(undefined4 *)(in_BX + (int)unaff_SI);
  uVar14 = (undefined2)((ulong)uVar6 >> 0x10);
  iVar13 = CONCAT11((byte)((ulong)uVar6 >> 8) | (byte)in_CX,(char)uVar6);
  func_0x0001a79f();
  uVar11 = (undefined1)((uint)in_CX >> 8);
  *(byte *)(iVar13 + (int)unaff_SI) = *(byte *)(iVar13 + (int)unaff_SI) & extraout_DL;
  puVar16 = (undefined1 *)func_0x0001b49d();
  uStack_16 = (undefined2)((ulong)puVar16 >> 0x10);
  puVar10 = (undefined1 *)puVar16;
  puStack_1a = &stack0xfff0;
  *(byte *)(unaff_DI + -0x1764) = *(byte *)(unaff_DI + -0x1764) | (byte)((ulong)puVar16 >> 0x18);
  uStack_1c = (undefined1)unaff_BP;
  uStack_1b = (undefined1)((uint)unaff_BP >> 8);
  bStack_1e = (byte)unaff_SI;
  uStack_1d = (undefined1)((uint)unaff_SI >> 8);
  uStack_20 = SUB41(puVar16,0);
  uStack_1f = (undefined1)((ulong)puVar16 >> 8);
  *(char *)(unaff_BP + (int)unaff_SI) = *(char *)(unaff_BP + (int)unaff_SI) + (char)unaff_DI;
  pcVar3 = (char *)(unaff_SI + 1);
  uVar4 = *unaff_SI;
  bVar5 = pcVar3[iVar13];
  uVar7 = (undefined1)uVar4;
  bVar12 = (char)((ulong)puVar16 >> 0x10) + *(char *)(unaff_SI + 0x301a);
  pbVar2 = puVar10 + -0x1764;
  *pbVar2 = *pbVar2 | (byte)iVar13;
  if ((char)*pbVar2 < '\x01') {
    uStack_2c = CONCAT22(&uStack_20,unaff_BP);
    *puVar10 = uVar7;
    puVar10[1] = uVar7;
    pcVar3[iVar13 + -0x1764] = pcVar3[iVar13 + -0x1764] | bVar12;
    pcVar3[iVar13] = pcVar3[iVar13] ^ bVar12;
    iStack_18 = iVar13;
    pcVar17 = pcVar3;
    FUN_1000_5e86(uStack_20,(char)pcVar3);
    uVar18 = (undefined1)((uint)pcVar17 >> 8);
    uVar8 = FUN_1000_369b();
    *(byte *)(unaff_BP + -100) = *(byte *)(unaff_BP + -100) | extraout_DH;
    FUN_1000_0082(uVar8,uVar18);
    cVar15 = '\0';
    pcVar3[iVar13] = pcVar3[iVar13] & extraout_DL_00;
    FUN_1000_369b();
    cVar9 = FUN_1000_4679();
    *pcVar3 = *pcVar3 + cVar9 + cVar15;
    pcVar1 = (char *)(CONCAT11(uVar7,uVar11) + (int)uStack_2c._1_2_);
    *pcVar1 = *pcVar1 + ((byte)((uint)uVar4 >> 8) ^ bVar5);
    pbVar2 = (byte *)(CONCAT11(uVar7,uVar11) + (int)uStack_2c._1_2_);
    *pbVar2 = *pbVar2 & bStack_1e;
    return;
  }
  return;
}


