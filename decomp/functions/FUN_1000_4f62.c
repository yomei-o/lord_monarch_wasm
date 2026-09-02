/* 1000:4f62 */

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

uint FUN_1000_4f62(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  code *pcVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint in_AX;
  uint uVar9;
  uint uVar10;
  byte *in_CX;
  int iVar11;
  char cVar13;
  byte *pbVar12;
  byte extraout_DL;
  undefined2 in_DX;
  byte extraout_DH;
  byte bVar14;
  byte *in_BX;
  byte *pbVar15;
  byte *unaff_BP;
  byte *pbVar16;
  int *unaff_SI;
  int *piVar17;
  undefined2 *puVar18;
  byte *unaff_DI;
  byte *pbVar19;
  undefined1 *puVar20;
  byte *unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte bVar21;
  bool bVar22;
  char cVar23;
  byte in_AF;
  bool bVar24;
  bool bVar25;
  longdouble in_ST0;
  byte *pbVar26;
  uint uStack_2;
  
  bVar25 = false;
  *unaff_SI = (int)ROUND(in_ST0);
  uVar9 = CONCAT11((char)(in_AX >> 8),((char)in_AX + -0x41) - in_CF) | 0x93e8;
  puVar18 = (undefined2 *)&stack0xfffc;
  bVar8 = (byte)uVar9;
  bVar4 = 9 < (bVar8 & 0xf) | in_AF;
  bVar6 = bVar8 + bVar4 * '\x06' + (0x99 < bVar8) * '`';
  *unaff_DI = bVar6;
  unaff_DI[1] = bVar6;
  bVar22 = CARRY1((byte)((uint)in_DX >> 8),unaff_BP[(int)unaff_SI]);
  pbVar19 = unaff_DI + 1;
  pbVar1 = unaff_BP + (int)unaff_SI;
  bVar8 = *pbVar1;
  bVar14 = *pbVar1;
  *pbVar1 = bVar14 + bVar6 + bVar22;
  bVar7 = (byte)unaff_DI;
  bVar21 = 0;
  pbVar12 = in_CX;
  pbVar15 = in_BX;
  FUN_1000_5c9f(bVar7 + (9 < (bVar7 & 0xf) | bVar4) * '\x06' +
                (0x99 < bVar7 || (CARRY1(bVar8,bVar6) || CARRY1(bVar14 + bVar6,bVar22))) * '`');
  uVar10 = FUN_1000_76f4();
  pbVar1 = unaff_BP + (int)unaff_SI;
  bVar8 = *pbVar1;
  bVar7 = (byte)uVar10;
  bVar14 = *pbVar1;
  bVar4 = *pbVar1 + bVar7;
  *pbVar1 = bVar4 + bVar21;
  pbVar16 = unaff_BP;
  pbVar26 = unaff_ES;
  uStack_2 = in_AX;
  if ((SCARRY1(bVar14,bVar7) != SCARRY1(bVar4,bVar21)) != (char)*pbVar1 < '\0') goto LAB_1000_4fb3;
  unaff_BP[(int)unaff_SI] =
       unaff_BP[(int)unaff_SI] + bVar7 + (CARRY1(bVar8,bVar7) || CARRY1(bVar4,bVar21));
  piVar17 = (int *)((int)unaff_SI + -1);
  bVar22 = CARRY1(extraout_DH,unaff_BP[(int)pbVar19]);
  bVar8 = extraout_DH + unaff_BP[(int)pbVar19];
  uStack_2 = in_AX;
  if (!bVar22 && bVar8 != 0) {
    bVar14 = bVar8 + pbVar15[(int)pbVar19];
    if (CARRY1(bVar8,pbVar15[(int)pbVar19]) || bVar14 == 0) {
      pcVar5 = (code *)swi(3);
      uVar10 = (*pcVar5)(piVar17);
      return uVar10;
    }
    bVar22 = false;
    uVar10 = (uVar10 & 0xff) + 0xaaaa +
             (uint)CARRY1((byte)(uVar10 >> 8),(pbVar15 + (int)piVar17)[0x2d]) | 0xe8;
    pbVar15 = (byte *)CONCAT11((char)((uint)pbVar15 >> 8),(byte)pbVar15 | bVar14);
    pbVar16 = unaff_BP + 1;
    piVar17 = unaff_SI + -1;
    uStack_2 = in_AX;
    bVar8 = bVar14;
  }
  while( true ) {
    pbVar1 = pbVar16 + (int)piVar17;
    bVar14 = *pbVar1;
    bVar7 = (byte)uVar10;
    bVar4 = *pbVar1;
    *pbVar1 = bVar4 + bVar7 + bVar22;
    unaff_SI = (int *)((int)piVar17 + -1);
    pbVar16[(int)unaff_SI] =
         pbVar16[(int)unaff_SI] + bVar7 + (CARRY1(bVar14,bVar7) || CARRY1(bVar4 + bVar7,bVar22));
    pbVar19[0x60] = pbVar19[0x60] ^ bVar8;
    bVar25 = ((uint)pbVar16 & 0x400) != 0;
    pbVar16[(int)unaff_SI] = pbVar16[(int)unaff_SI] + bVar7 + (((uint)pbVar16 & 1) != 0);
LAB_1000_4fb3:
    bVar14 = 0;
    FUN_1000_5c87();
    uVar10 = func_0x0001c4dc();
    pbVar1 = pbVar16 + (int)unaff_SI;
    bVar8 = *pbVar1 + (byte)uVar10;
    bVar22 = CARRY1(*pbVar1,(byte)uVar10) || CARRY1(bVar8,bVar14);
    *pbVar1 = bVar8 + bVar14;
    bVar24 = *pbVar1 == 0;
    if (!bVar24) break;
    *(undefined2 *)0xb56a = *(undefined2 *)0x3bc4;
    *(byte **)(pbVar16 + (int)unaff_SI + 0x2aa) =
         pbVar16 + *(int *)(pbVar16 + (int)unaff_SI + 0x2aa);
    pbVar12 = (byte *)CONCAT11(0x12,(char)pbVar26);
    bVar14 = (byte)uStack_2;
    bVar22 = false;
    uVar10 = *(uint *)0xbe09;
    pbVar15 = in_CX;
    pbVar16 = in_BX;
    piVar17 = (int *)&stack0xfffc;
    pbVar19 = unaff_BP;
    pbVar26 = pbVar12;
    uStack_2 = uVar10;
    bVar8 = (byte)(uVar9 >> 8);
    if ('\0' < (char)(bVar14 & 0x7a ^ 0xe8)) {
code_r0x00014fdb:
      puVar20 = (undefined1 *)0xd27e;
      iVar11 = 0x900;
      do {
        puVar2 = puVar18;
        puVar18 = puVar18 + (uint)bVar25 * -2 + 1;
        puVar3 = puVar20;
        puVar20 = puVar20 + (uint)bVar25 * -2 + 1;
        *puVar3 = (char)*puVar2;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      pbVar15[(int)puVar18] = pbVar15[(int)puVar18] & bVar6;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if ((POPCOUNT(*pbVar1) & 1U) == 0) {
    do {
      if (!bVar22) {
        if (!bVar24) {
          return uVar10;
        }
        cVar23 = CARRY1((byte)pbVar12,pbVar15[(int)pbVar19]);
        cVar13 = (char)((uint)pbVar12 >> 8);
        bVar8 = FUN_1000_567c();
        if ((bool)cVar23) {
          *pbVar19 = bVar8;
          *(uint *)((int)unaff_SI + -0x1f) = *(uint *)((int)unaff_SI + -0x1f) | (uint)unaff_SI;
          return uStack_2;
        }
        uVar10 = FUN_1000_2fef();
        pbVar1 = pbVar16 + (int)unaff_SI + 0x12aa;
        *pbVar1 = *pbVar1 + cVar13 + cVar23;
        bVar24 = *pbVar1 == 0;
      }
      pbVar1 = *(byte **)(pbVar15 + (int)pbVar19);
      unaff_ES = (byte *)((ulong)pbVar1 >> 0x10);
      pbVar12 = (byte *)pbVar1;
      if (!bVar24) {
        return uStack_2;
      }
      *(uint *)(pbVar19 + 0xd) = *(uint *)(pbVar19 + 0xd) | (uint)unaff_SI;
      pbVar15[(int)unaff_SI] = pbVar15[(int)unaff_SI] & (byte)pbVar1;
      bVar22 = (byte)uVar10 < 6;
      bVar24 = (byte)uVar10 == 6;
    } while( true );
  }
  FUN_1000_5978();
  puVar18 = (undefined2 *)0xd27e;
  bVar6 = extraout_DL;
  goto code_r0x00014fdb;
}


