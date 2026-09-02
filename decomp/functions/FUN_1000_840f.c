/* 1000:840f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */
/* WARNING: Removing unreachable block (ram,0x00018424) */

uint FUN_1000_840f(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int in_AX;
  uint uVar6;
  byte bVar8;
  byte bVar9;
  undefined2 uVar7;
  undefined2 in_CX;
  byte bVar12;
  int iVar10;
  int iVar11;
  byte bVar13;
  undefined2 in_DX;
  char cVar15;
  byte bVar16;
  undefined2 uVar14;
  char cVar17;
  undefined2 in_BX;
  uint uVar19;
  uint unaff_BP;
  int unaff_SI;
  uint *puVar20;
  int unaff_DI;
  uint *puVar21;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar22;
  byte in_AF;
  bool bVar23;
  bool bVar24;
  byte in_TF;
  byte in_IF;
  bool bVar25;
  byte in_NT;
  undefined4 uVar26;
  uint *in_stack_00000000;
  uint uVar18;
  
  uVar6 = in_AX + 0x197e;
  bVar9 = (byte)in_DX;
  cVar15 = (char)((uint)in_DX >> 8) + *(char *)(unaff_DI + -0x5e);
  iVar10 = CONCAT11(cVar15,bVar9);
  piVar1 = (int *)(unaff_BP + unaff_DI);
  iVar11 = *piVar1;
  *piVar1 = *piVar1 - iVar10;
  if (!SBORROW2(iVar11,iVar10)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar8 = (byte)(uVar6 >> 8);
  bVar13 = (byte)in_BX;
  *(byte *)(unaff_BP + 0xebff) = *(byte *)(unaff_BP + 0xebff) | bVar13;
  bVar12 = (byte)((uint)in_CX >> 8);
  iVar11 = CONCAT11(bVar12,(char)in_CX - *(char *)(unaff_SI + 0x70));
  pbVar3 = (byte *)(unaff_BP + unaff_SI + -0x1401);
  *pbVar3 = *pbVar3 | bVar8;
  puVar2 = (uint *)(unaff_BP + unaff_SI + 0x2a);
  bVar22 = *puVar2 < uVar6;
  bVar25 = SBORROW2(*puVar2,uVar6);
  *puVar2 = *puVar2 - uVar6;
  bVar24 = (int)*puVar2 < 0;
  bVar23 = *puVar2 == 0;
  bVar16 = POPCOUNT(*puVar2 & 0xff);
  if (!bVar25) {
    bVar25 = SCARRY1(bVar13,bVar12);
    cVar17 = bVar13 + bVar12;
    uVar18 = CONCAT11((char)((uint)in_BX >> 8),cVar17);
    bVar24 = cVar17 < '\0';
    bVar23 = cVar17 == '\0';
    bVar16 = POPCOUNT(cVar17);
    bVar22 = false;
    if (CARRY1(bVar13,bVar12)) {
      uVar7 = CONCAT11(bVar8,(char)uVar6 + '\x7f');
      uVar26 = CONCAT22(iVar10,uVar7);
      piVar1 = (int *)((int)param_1 + unaff_BP + 5);
      *piVar1 = *piVar1 + (int)param_1;
      if (4 < bVar9) {
        uVar14 = CONCAT11(cVar15,bVar9 - 8);
        uVar26 = CONCAT22(uVar14,uVar7);
        puVar20 = param_1;
        uVar5 = CONCAT22(uVar14,uVar7);
        if (3 < (byte)(bVar9 - 8)) goto LAB_1000_84d4;
      }
      do {
        uVar18 = unaff_BP;
        unaff_BP = uVar18;
        puVar20 = in_stack_00000000;
        uVar5 = uVar26;
LAB_1000_84d4:
        do {
          uVar4 = uVar5;
          puVar21 = in_stack_00000000;
          iVar10 = iVar11;
          uVar6 = (uint)uVar4;
          in_stack_00000000 = puVar21 + 1;
          iVar11 = iVar10 + -1;
          if (iVar11 == 0) {
code_r0x000184d9:
            uVar19 = uVar18 - 8;
            if (uVar18 < 8) {
              uVar19 = 0;
            }
            else if (0x1ef < uVar19) {
              *(byte *)(unaff_BP + 0x5d) = *(byte *)(unaff_BP + 0x5d) | (byte)uVar19;
              return uVar6;
            }
            uVar6 = (uint)puVar20 >> 1;
            *(char *)(uVar19 + uVar6) =
                 (*(char *)(uVar19 + uVar6) - (char)iVar11) - (((uint)puVar20 & 1) != 0);
            return CONCAT11((char)(uVar6 / 0x30),(char)(uVar6 % 0x30));
          }
          uVar19 = *in_stack_00000000;
          bVar9 = (byte)puVar21[-0x16c0];
          bVar16 = (byte)((ulong)uVar4 >> 0x18);
          uVar7 = CONCAT11(bVar16,bVar9);
          uVar26 = CONCAT22(uVar7,uVar6);
          if (bVar9 != 5) {
            unaff_BP = uVar19 + 8;
            uVar5 = CONCAT22(uVar7,uVar6);
            if ((uVar19 < 0xfff8) && (uVar5 = CONCAT22(uVar7,uVar6), unaff_BP < uVar18)) {
              bVar8 = *(byte *)(uVar18 + (int)puVar20);
              bVar12 = bVar9 + *(byte *)(uVar18 + (int)puVar20);
              bVar13 = bVar12 + (uVar18 < unaff_BP);
              *in_stack_00000000 = uVar6;
              in_stack_00000000 = (uint *)((int)puVar21 + 5);
              *(char *)(puVar21 + 2) = (char)uVar4;
              *(char *)(unaff_BP + (int)puVar20) =
                   *(char *)(unaff_BP + (int)puVar20) + (char)(uVar18 >> 8) +
                   (CARRY1(bVar9,bVar8) || CARRY1(bVar12,uVar18 < unaff_BP));
              *(char *)(puVar20 + 0x1b) = (char)puVar20[0x1b] << 1;
              bVar9 = (byte)((ulong)uVar4 >> 8);
              if (bVar13 == bVar9) {
                *(undefined2 *)(unaff_BP + (int)puVar20) = 0xa6e2;
                goto code_r0x000184d9;
              }
              puVar20[-0x3ffb] = (puVar20[-0x3ffb] - (int)&stack0x0000) - (uint)(bVar13 < bVar9);
              pbVar3 = (byte *)((int)in_stack_00000000 + uVar19 + 0xf);
              bVar22 = CARRY1(*pbVar3,bVar16);
              *pbVar3 = *pbVar3 + bVar16;
              uVar26 = FUN_1000_7a7c();
              iVar11 = iVar10;
              uVar5 = uVar26;
              if (!bVar22) break;
            }
            goto LAB_1000_84d4;
          }
          unaff_BP = uVar19;
          uVar5 = CONCAT22(uVar7,uVar6);
        } while (uVar18 <= uVar19);
      } while( true );
    }
  }
  return (uint)(in_NT & 1) * 0x4000 | (uint)bVar25 * 0x800 | (uint)(in_IF & 1) * 0x200 |
         (uint)(in_TF & 1) * 0x100 | (uint)bVar24 * 0x80 | (uint)bVar23 * 0x40 |
         (uint)(in_AF & 1) * 0x10 | (uint)((bVar16 & 1) == 0) * 4 | (uint)bVar22;
}


