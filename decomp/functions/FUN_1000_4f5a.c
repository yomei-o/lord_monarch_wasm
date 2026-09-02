/* 1000:4f5a */

/* WARNING: Instruction at (ram,0x00015002) overlaps instruction at (ram,0x00015000)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00014f6d) */
/* WARNING: Removing unreachable block (ram,0x00014f4d) */
/* WARNING: Removing unreachable block (ram,0x00014f72) */
/* WARNING: Removing unreachable block (ram,0x00015020) */
/* WARNING: Removing unreachable block (ram,0x00015022) */
/* WARNING: Removing unreachable block (ram,0x00014ff9) */
/* WARNING: Removing unreachable block (ram,0x00015012) */

uint FUN_1000_4f5a(int *param_1,uint param_2,undefined2 param_3,int param_4,int param_5,
                  undefined2 param_6,uint param_7)

{
  byte *pbVar1;
  int *piVar2;
  char *pcVar3;
  undefined1 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  uint in_AX;
  uint uVar11;
  undefined2 in_CX;
  int iVar12;
  char cVar13;
  undefined2 in_DX;
  byte extraout_DH;
  byte bVar14;
  int extraout_DX;
  int in_BX;
  uint unaff_BP;
  int *unaff_SI;
  int *piVar15;
  byte *unaff_DI;
  byte *pbVar16;
  undefined1 *puVar17;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar18;
  bool bVar19;
  char cVar20;
  byte in_AF;
  bool bVar21;
  bool bVar22;
  longdouble in_ST0;
  byte *in_stack_00000000;
  
  bVar14 = (byte)((uint)in_DX >> 8);
  bVar22 = false;
  *(uint *)(in_BX + (int)unaff_SI) = *(uint *)(in_BX + (int)unaff_SI) ^ unaff_BP;
  pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
  bVar7 = (byte)in_AX;
  bVar18 = CARRY1(*pbVar1,bVar7);
  bVar10 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar7;
  pbVar16 = unaff_DI;
  if (*pbVar1 == 0 || SCARRY1(bVar10,bVar7) != (char)*pbVar1 < '\0') {
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) & bVar7;
    *unaff_SI = (int)ROUND(in_ST0);
    bVar10 = bVar7 + 0xbf | 0xe8;
    bVar7 = 9 < (bVar10 & 0xf) | in_AF;
    bVar8 = bVar10 + bVar7 * '\x06' + (0x99 < bVar10) * '`';
    *unaff_DI = bVar8;
    unaff_DI[1] = bVar8;
    bVar19 = CARRY1(bVar14,*(byte *)(unaff_BP + (int)unaff_SI));
    pbVar16 = unaff_DI + 1;
    pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
    bVar10 = *pbVar1;
    bVar14 = *pbVar1;
    *pbVar1 = bVar14 + bVar8 + bVar19;
    bVar9 = (byte)unaff_DI;
    bVar18 = 0;
    FUN_1000_5c9f(bVar9 + (9 < (bVar9 & 0xf) | bVar7) * '\x06' +
                  (0x99 < bVar9 || (CARRY1(bVar10,bVar8) || CARRY1(bVar14 + bVar8,bVar19))) * '`');
    in_AX = FUN_1000_76f4();
    bVar14 = extraout_DH;
  }
  pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
  bVar10 = *pbVar1;
  bVar9 = (byte)in_AX;
  bVar7 = *pbVar1;
  bVar8 = *pbVar1 + bVar9;
  *pbVar1 = bVar8 + bVar18;
  if ((SCARRY1(bVar7,bVar9) != SCARRY1(bVar8,bVar18)) != (char)*pbVar1 < '\0') goto LAB_1000_4fb3;
  *(char *)(unaff_BP + (int)unaff_SI) =
       *(char *)(unaff_BP + (int)unaff_SI) + bVar9 + (CARRY1(bVar10,bVar9) || CARRY1(bVar8,bVar18));
  piVar15 = (int *)((int)unaff_SI + -1);
  bVar19 = CARRY1(bVar14,pbVar16[unaff_BP]);
  bVar14 = bVar14 + pbVar16[unaff_BP];
  iVar12 = (uint)bVar14 << 8;
  if (!bVar19 && bVar14 != 0) {
    bVar10 = bVar14 + pbVar16[in_BX];
    if (CARRY1(bVar14,pbVar16[in_BX]) || bVar10 == 0) {
      pcVar5 = (code *)swi(3);
      uVar11 = (*pcVar5)(piVar15);
      return uVar11;
    }
    bVar19 = false;
    in_AX = (in_AX & 0xff) + 0xaaaa +
            (uint)CARRY1((byte)(in_AX >> 8),*(byte *)((int)piVar15 + in_BX + 0x2d)) | 0xe8;
    unaff_BP = unaff_BP + 1;
    iVar12 = (uint)bVar10 << 8;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX | bVar10);
    piVar15 = unaff_SI + -1;
  }
  while( true ) {
    pbVar1 = (byte *)(unaff_BP + (int)piVar15);
    bVar10 = *pbVar1;
    bVar7 = (byte)in_AX;
    bVar14 = *pbVar1;
    *pbVar1 = bVar14 + bVar7 + bVar19;
    unaff_SI = (int *)((int)piVar15 + -1);
    *(char *)(unaff_BP + (int)unaff_SI) =
         *(char *)(unaff_BP + (int)unaff_SI) + bVar7 +
         (CARRY1(bVar10,bVar7) || CARRY1(bVar14 + bVar7,bVar19));
    pbVar16[0x60] = pbVar16[0x60] ^ (byte)((uint)iVar12 >> 8);
    bVar22 = (unaff_BP & 0x400) != 0;
    *(char *)(unaff_BP + (int)unaff_SI) =
         *(char *)(unaff_BP + (int)unaff_SI) + bVar7 + ((unaff_BP & 1) != 0);
LAB_1000_4fb3:
    bVar14 = 0;
    FUN_1000_5c87();
    uVar11 = func_0x0001c4dc();
    pbVar1 = (byte *)(unaff_BP + (int)unaff_SI);
    bVar10 = *pbVar1 + (byte)uVar11;
    bVar19 = CARRY1(*pbVar1,(byte)uVar11) || CARRY1(bVar10,bVar14);
    *pbVar1 = bVar10 + bVar14;
    bVar21 = *pbVar1 == 0;
    if (!bVar21) break;
    *(undefined2 *)0xb56a = *(undefined2 *)0x3bc4;
    piVar2 = (int *)((int)unaff_SI + unaff_BP + 0x2aa);
    *piVar2 = *piVar2 + unaff_BP;
    in_CX = CONCAT11(0x12,(undefined1)param_6);
    bVar10 = (byte)param_7;
    bVar19 = false;
    in_AX = *(uint *)0xbe09;
    iVar12 = param_5;
    in_BX = param_4;
    unaff_BP = param_2;
    piVar15 = param_1;
    pbVar16 = in_stack_00000000;
    param_6 = in_CX;
    param_7 = in_AX;
    if ('\0' < (char)(bVar10 & 0x7a ^ 0xe8)) {
code_r0x00014fdb:
      puVar17 = (undefined1 *)0xd27e;
      iVar12 = 0x900;
      do {
        piVar2 = param_1;
        param_1 = param_1 + (uint)bVar22 * -2 + 1;
        puVar4 = puVar17;
        puVar17 = puVar17 + (uint)bVar22 * -2 + 1;
        *puVar4 = (char)*piVar2;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      *(byte *)(in_BX + (int)param_1) = *(byte *)(in_BX + (int)param_1) & (byte)param_5;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if ((POPCOUNT(*pbVar1) & 1U) == 0) {
    do {
      if (!bVar19) {
        if (!bVar21) {
          return uVar11;
        }
        cVar20 = CARRY1((byte)in_CX,pbVar16[in_BX]);
        cVar13 = (char)((uint)in_CX >> 8);
        bVar10 = FUN_1000_567c();
        if ((bool)cVar20) {
          *pbVar16 = bVar10;
          *(uint *)((int)unaff_SI + -0x1f) = *(uint *)((int)unaff_SI + -0x1f) | (uint)unaff_SI;
          return param_7;
        }
        uVar11 = FUN_1000_2fef();
        pcVar3 = (char *)((int)unaff_SI + unaff_BP + 0x12aa);
        *pcVar3 = *pcVar3 + cVar13 + cVar20;
        bVar21 = *pcVar3 == '\0';
      }
      uVar6 = *(undefined4 *)(pbVar16 + in_BX);
      unaff_ES = (undefined2)((ulong)uVar6 >> 0x10);
      in_CX = (undefined2)uVar6;
      if (!bVar21) {
        return param_7;
      }
      *(uint *)(pbVar16 + 0xd) = *(uint *)(pbVar16 + 0xd) | (uint)unaff_SI;
      *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) & (byte)uVar6;
      bVar19 = (byte)uVar11 < 6;
      bVar21 = (byte)uVar11 == 6;
    } while( true );
  }
  FUN_1000_5978();
  param_1 = (int *)0xd27e;
  param_5 = extraout_DX;
  goto code_r0x00014fdb;
}


