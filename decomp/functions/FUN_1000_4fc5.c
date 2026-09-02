/* 1000:4fc5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014fd3) overlaps instruction at (ram,0x00014fd2)
    */

undefined4
FUN_1000_4fc5(undefined2 *param_1,int param_2,undefined2 param_3,int param_4,undefined2 param_5,
             undefined2 param_6,undefined2 param_7)

{
  byte *pbVar1;
  int *piVar2;
  char *pcVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined1 uVar8;
  int iVar9;
  char cVar11;
  undefined2 uVar10;
  undefined2 extraout_DX;
  int iVar12;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined1 *puVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar14;
  bool bVar15;
  byte in_CF;
  char cVar16;
  bool bVar17;
  bool bVar18;
  undefined4 uVar19;
  undefined1 *in_stack_00000000;
  
  bVar18 = false;
  do {
    *(undefined2 *)0xb56a = *(undefined2 *)0x3bc4;
    piVar2 = (int *)((int)unaff_SI + unaff_BP + 0x2aa);
    *piVar2 = *piVar2 + unaff_BP + (uint)in_CF;
    param_3 = &stack0x0010;
    param_6 = CONCAT11(0x12,(char)param_6);
    bVar7 = (byte)param_7;
    param_7 = *(undefined2 *)0xbe09;
    iVar12 = param_4;
    if ('\0' < (char)(bVar7 & 0x7a ^ 0xe8)) {
code_r0x00014fdb:
      puVar13 = (undefined1 *)0xd27e;
      iVar9 = 0x900;
      do {
        puVar4 = param_1;
        param_1 = param_1 + (uint)bVar18 * -2 + 1;
        puVar5 = puVar13;
        puVar13 = puVar13 + (uint)bVar18 * -2 + 1;
        *puVar5 = (char)*puVar4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      *(byte *)(iVar12 + (int)param_1) = *(byte *)(iVar12 + (int)param_1) & (byte)param_5;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar18 = ((uint)in_stack_00000000 & 0x400) != 0;
    *(char *)(param_2 + (int)param_1) =
         *(char *)(param_2 + (int)param_1) + (char)param_7 + (((uint)in_stack_00000000 & 1) != 0);
    bVar14 = 0;
    uVar10 = param_6;
    FUN_1000_5c87();
    uVar19 = func_0x0001c4dc();
    pbVar1 = (byte *)(param_2 + (int)param_1);
    bVar7 = *pbVar1 + (byte)uVar19;
    bVar15 = CARRY1(*pbVar1,(byte)uVar19) || CARRY1(bVar7,bVar14);
    *pbVar1 = bVar7 + bVar14;
    bVar17 = *pbVar1 == 0;
    if (!bVar17) {
      if ((POPCOUNT(*pbVar1) & 1U) == 0) break;
      FUN_1000_5978();
      param_1 = (undefined2 *)0xd27e;
      param_5 = extraout_DX;
      goto code_r0x00014fdb;
    }
    in_CF = 0;
    unaff_BP = param_2;
    unaff_SI = param_1;
    in_stack_00000000 = (undefined1 *)0x4fbe;
  } while( true );
code_r0x00015009:
  if (!bVar15) {
    if (!bVar17) {
      return uVar19;
    }
    cVar16 = CARRY1((byte)uVar10,in_stack_00000000[iVar12]);
    cVar11 = (char)((uint)uVar10 >> 8);
    uVar8 = FUN_1000_567c();
    if ((bool)cVar16) {
      *in_stack_00000000 = uVar8;
      *(uint *)((int)param_1 + -0x1f) = *(uint *)((int)param_1 + -0x1f) | (uint)param_1;
LAB_1000_5029:
      return CONCAT22(param_5,param_7);
    }
    uVar19 = FUN_1000_2fef();
    pcVar3 = (char *)((int)param_1 + param_2 + 0x12aa);
    *pcVar3 = *pcVar3 + cVar11 + cVar16;
    bVar17 = *pcVar3 == '\0';
  }
  uVar6 = *(undefined4 *)(in_stack_00000000 + iVar12);
  unaff_ES = (undefined2)((ulong)uVar6 >> 0x10);
  uVar10 = (undefined2)uVar6;
  if (!bVar17) goto LAB_1000_5029;
  *(uint *)(in_stack_00000000 + 0xd) = *(uint *)(in_stack_00000000 + 0xd) | (uint)param_1;
  *(byte *)(iVar12 + (int)param_1) = *(byte *)(iVar12 + (int)param_1) & (byte)uVar6;
  bVar15 = (byte)uVar19 < 6;
  bVar17 = (byte)uVar19 == 6;
  goto code_r0x00015009;
}


