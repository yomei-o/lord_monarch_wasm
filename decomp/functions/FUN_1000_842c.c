/* 1000:842c */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

uint FUN_1000_842c(uint *param_1)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint in_AX;
  byte bVar7;
  uint uVar6;
  undefined2 in_CX;
  byte bVar10;
  int iVar8;
  int iVar9;
  byte bVar11;
  byte bVar12;
  undefined2 in_DX;
  byte bVar13;
  char cVar14;
  undefined2 in_BX;
  uint uVar16;
  uint unaff_BP;
  int unaff_SI;
  uint *puVar17;
  uint *puVar18;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar19;
  byte in_AF;
  bool bVar20;
  bool bVar21;
  undefined4 uVar22;
  uint *in_stack_00000000;
  uint uVar15;
  
  bVar13 = (byte)in_BX;
  *(byte *)(unaff_BP + 0xebff) = *(byte *)(unaff_BP + 0xebff) | bVar13;
  bVar10 = (byte)((uint)in_CX >> 8);
  iVar9 = CONCAT11(bVar10,(char)in_CX - *(char *)(unaff_SI + 0x70));
  pbVar3 = (byte *)(unaff_BP + unaff_SI + -0x1401);
  bVar7 = (byte)(in_AX >> 8);
  *pbVar3 = *pbVar3 | bVar7;
  puVar1 = (uint *)(unaff_BP + unaff_SI + 0x2a);
  bVar19 = *puVar1 < in_AX;
  uVar15 = *puVar1;
  *puVar1 = *puVar1 - in_AX;
  bVar21 = (int)*puVar1 < 0;
  bVar20 = *puVar1 == 0;
  bVar12 = POPCOUNT(*puVar1 & 0xff);
  if (!SBORROW2(uVar15,in_AX)) {
    cVar14 = bVar13 + bVar10;
    uVar15 = CONCAT11((char)((uint)in_BX >> 8),cVar14);
    bVar21 = cVar14 < '\0';
    bVar20 = cVar14 == '\0';
    bVar12 = POPCOUNT(cVar14);
    bVar19 = false;
    if (CARRY1(bVar13,bVar10)) {
      uVar6 = CONCAT11(bVar7,(char)in_AX + '\x7f');
      piVar2 = (int *)((int)param_1 + unaff_BP + 5);
      *piVar2 = *piVar2 + (int)param_1;
      if (4 < (byte)in_DX) {
        bVar12 = (byte)in_DX - 8;
        in_DX = CONCAT11((char)((uint)in_DX >> 8),bVar12);
        puVar17 = param_1;
        uVar22 = CONCAT22(in_DX,uVar6);
        if (3 < bVar12) goto LAB_1000_84d4;
      }
      do {
        puVar17 = in_stack_00000000;
        uVar15 = unaff_BP;
        unaff_BP = uVar15;
        in_stack_00000000 = puVar17;
        uVar22 = CONCAT22(in_DX,uVar6);
LAB_1000_84d4:
        do {
          uVar5 = uVar22;
          puVar18 = in_stack_00000000;
          iVar8 = iVar9;
          uVar6 = (uint)uVar5;
          in_stack_00000000 = puVar18 + 1;
          iVar9 = iVar8 + -1;
          if (iVar9 == 0) {
code_r0x000184d9:
            uVar16 = uVar15 - 8;
            if (uVar15 < 8) {
              uVar16 = 0;
            }
            else if (0x1ef < uVar16) {
              *(byte *)(unaff_BP + 0x5d) = *(byte *)(unaff_BP + 0x5d) | (byte)uVar16;
              return uVar6;
            }
            pcVar4 = (char *)(uVar16 + ((uint)puVar17 >> 1));
            *pcVar4 = (*pcVar4 - (char)iVar9) - (((uint)puVar17 & 1) != 0);
            return ((uint)puVar17 >> 1) % 0x30;
          }
          uVar16 = *in_stack_00000000;
          bVar12 = (byte)puVar18[-0x16c0];
          bVar7 = (byte)((ulong)uVar5 >> 0x18);
          in_DX = CONCAT11(bVar7,bVar12);
          if (bVar12 != 5) {
            unaff_BP = uVar16 + 8;
            uVar22 = CONCAT22(in_DX,uVar6);
            if ((uVar16 < 0xfff8) && (uVar22 = CONCAT22(in_DX,uVar6), unaff_BP < uVar15)) {
              bVar10 = *(byte *)(uVar15 + (int)puVar17);
              bVar13 = bVar12 + *(byte *)(uVar15 + (int)puVar17);
              bVar11 = bVar13 + (uVar15 < unaff_BP);
              *in_stack_00000000 = uVar6;
              in_stack_00000000 = (uint *)((int)puVar18 + 5);
              *(char *)(puVar18 + 2) = (char)uVar5;
              *(char *)(unaff_BP + (int)puVar17) =
                   *(char *)(unaff_BP + (int)puVar17) + (char)(uVar15 >> 8) +
                   (CARRY1(bVar12,bVar10) || CARRY1(bVar13,uVar15 < unaff_BP));
              *(char *)(puVar17 + 0x1b) = (char)puVar17[0x1b] << 1;
              bVar12 = (byte)((ulong)uVar5 >> 8);
              if (bVar11 == bVar12) {
                *(undefined2 *)(unaff_BP + (int)puVar17) = 0xa6e2;
                goto code_r0x000184d9;
              }
              puVar17[-0x3ffb] = (puVar17[-0x3ffb] - (int)&stack0x0000) - (uint)(bVar11 < bVar12);
              pbVar3 = (byte *)((int)in_stack_00000000 + uVar16 + 0xf);
              bVar19 = CARRY1(*pbVar3,bVar7);
              *pbVar3 = *pbVar3 + bVar7;
              uVar22 = FUN_1000_7a7c();
              in_DX = (undefined2)((ulong)uVar22 >> 0x10);
              uVar6 = (uint)uVar22;
              iVar9 = iVar8;
              if (!bVar19) break;
            }
            goto LAB_1000_84d4;
          }
          unaff_BP = uVar16;
          uVar22 = CONCAT22(in_DX,uVar6);
        } while (uVar15 <= uVar16);
      } while( true );
    }
  }
  return (uint)bVar21 * 0x80 | (uint)bVar20 * 0x40 | (uint)(in_AF & 1) * 0x10 |
         (uint)((bVar12 & 1) == 0) * 4 | (uint)bVar19;
}


