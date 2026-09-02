/* 1000:8435 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

uint FUN_1000_8435(uint *param_1)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  char *pcVar4;
  byte bVar5;
  undefined4 uVar6;
  uint in_AX;
  byte bVar8;
  uint uVar7;
  int in_CX;
  byte bVar10;
  int iVar9;
  byte bVar11;
  byte bVar12;
  undefined2 in_DX;
  char cVar13;
  undefined2 in_BX;
  uint uVar15;
  uint unaff_BP;
  int unaff_SI;
  uint *puVar16;
  uint *puVar17;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar18;
  byte in_AF;
  bool bVar19;
  bool bVar20;
  undefined4 uVar21;
  uint *in_stack_00000000;
  uint uVar14;
  
  pbVar3 = (byte *)(unaff_BP + unaff_SI + -0x1401);
  bVar8 = (byte)(in_AX >> 8);
  *pbVar3 = *pbVar3 | bVar8;
  puVar1 = (uint *)(unaff_BP + unaff_SI + 0x2a);
  bVar18 = *puVar1 < in_AX;
  uVar14 = *puVar1;
  *puVar1 = *puVar1 - in_AX;
  bVar20 = (int)*puVar1 < 0;
  bVar19 = *puVar1 == 0;
  bVar12 = POPCOUNT(*puVar1 & 0xff);
  if (!SBORROW2(uVar14,in_AX)) {
    bVar10 = (byte)((uint)in_CX >> 8);
    cVar13 = (byte)in_BX + bVar10;
    uVar14 = CONCAT11((char)((uint)in_BX >> 8),cVar13);
    bVar20 = cVar13 < '\0';
    bVar19 = cVar13 == '\0';
    bVar12 = POPCOUNT(cVar13);
    bVar18 = false;
    if (CARRY1((byte)in_BX,bVar10)) {
      uVar7 = CONCAT11(bVar8,(char)in_AX + '\x7f');
      piVar2 = (int *)((int)param_1 + unaff_BP + 5);
      *piVar2 = *piVar2 + (int)param_1;
      if (4 < (byte)in_DX) {
        bVar12 = (byte)in_DX - 8;
        in_DX = CONCAT11((char)((uint)in_DX >> 8),bVar12);
        puVar16 = param_1;
        uVar21 = CONCAT22(in_DX,uVar7);
        if (3 < bVar12) goto LAB_1000_84d4;
      }
      do {
        puVar16 = in_stack_00000000;
        uVar14 = unaff_BP;
        unaff_BP = uVar14;
        in_stack_00000000 = puVar16;
        uVar21 = CONCAT22(in_DX,uVar7);
LAB_1000_84d4:
        do {
          uVar6 = uVar21;
          puVar17 = in_stack_00000000;
          iVar9 = in_CX;
          uVar7 = (uint)uVar6;
          in_stack_00000000 = puVar17 + 1;
          in_CX = iVar9 + -1;
          if (in_CX == 0) {
code_r0x000184d9:
            uVar15 = uVar14 - 8;
            if (uVar14 < 8) {
              uVar15 = 0;
            }
            else if (0x1ef < uVar15) {
              *(byte *)(unaff_BP + 0x5d) = *(byte *)(unaff_BP + 0x5d) | (byte)uVar15;
              return uVar7;
            }
            pcVar4 = (char *)(uVar15 + ((uint)puVar16 >> 1));
            *pcVar4 = (*pcVar4 - (char)in_CX) - (((uint)puVar16 & 1) != 0);
            return ((uint)puVar16 >> 1) % 0x30;
          }
          uVar15 = *in_stack_00000000;
          bVar12 = (byte)puVar17[-0x16c0];
          bVar8 = (byte)((ulong)uVar6 >> 0x18);
          in_DX = CONCAT11(bVar8,bVar12);
          if (bVar12 != 5) {
            unaff_BP = uVar15 + 8;
            uVar21 = CONCAT22(in_DX,uVar7);
            if ((uVar15 < 0xfff8) && (uVar21 = CONCAT22(in_DX,uVar7), unaff_BP < uVar14)) {
              bVar10 = *(byte *)(uVar14 + (int)puVar16);
              bVar5 = bVar12 + *(byte *)(uVar14 + (int)puVar16);
              bVar11 = bVar5 + (uVar14 < unaff_BP);
              *in_stack_00000000 = uVar7;
              in_stack_00000000 = (uint *)((int)puVar17 + 5);
              *(char *)(puVar17 + 2) = (char)uVar6;
              *(char *)(unaff_BP + (int)puVar16) =
                   *(char *)(unaff_BP + (int)puVar16) + (char)(uVar14 >> 8) +
                   (CARRY1(bVar12,bVar10) || CARRY1(bVar5,uVar14 < unaff_BP));
              *(char *)(puVar16 + 0x1b) = (char)puVar16[0x1b] << 1;
              bVar12 = (byte)((ulong)uVar6 >> 8);
              if (bVar11 == bVar12) {
                *(undefined2 *)(unaff_BP + (int)puVar16) = 0xa6e2;
                goto code_r0x000184d9;
              }
              puVar16[-0x3ffb] = (puVar16[-0x3ffb] - (int)&stack0x0000) - (uint)(bVar11 < bVar12);
              pbVar3 = (byte *)((int)in_stack_00000000 + uVar15 + 0xf);
              bVar18 = CARRY1(*pbVar3,bVar8);
              *pbVar3 = *pbVar3 + bVar8;
              uVar21 = FUN_1000_7a7c();
              in_DX = (undefined2)((ulong)uVar21 >> 0x10);
              uVar7 = (uint)uVar21;
              in_CX = iVar9;
              if (!bVar18) break;
            }
            goto LAB_1000_84d4;
          }
          unaff_BP = uVar15;
          uVar21 = CONCAT22(in_DX,uVar7);
        } while (uVar14 <= uVar15);
      } while( true );
    }
  }
  return (uint)bVar20 * 0x80 | (uint)bVar19 * 0x40 | (uint)(in_AF & 1) * 0x10 |
         (uint)((bVar12 & 1) == 0) * 4 | (uint)bVar18;
}


