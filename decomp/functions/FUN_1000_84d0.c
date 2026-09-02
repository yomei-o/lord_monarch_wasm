/* 1000:84d0 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */

void FUN_1000_84d0(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined2 in_AX;
  int iVar8;
  int in_CX;
  byte bVar9;
  undefined2 uVar10;
  undefined2 in_DX;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint unaff_BP;
  uint *unaff_DI;
  uint *puVar15;
  uint *puVar16;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar17;
  undefined4 uVar18;
  byte bVar11;
  
  uVar18 = CONCAT22(in_DX,in_AX);
  do {
    puVar15 = unaff_DI;
    uVar12 = unaff_BP;
    uVar14 = uVar12;
    unaff_DI = puVar15;
    uVar6 = uVar18;
LAB_1000_84d4:
    do {
      uVar5 = uVar6;
      puVar16 = unaff_DI;
      iVar8 = in_CX;
      uVar13 = (uint)uVar5;
      unaff_DI = puVar16 + 1;
      in_CX = iVar8 + -1;
      if (in_CX == 0) {
code_r0x000184d9:
        uVar13 = uVar12 - 8;
        if (uVar12 < 8) {
          uVar13 = 0;
        }
        else if (0x1ef < uVar13) {
          *(byte *)(uVar14 + 0x5d) = *(byte *)(uVar14 + 0x5d) | (byte)uVar13;
          return;
        }
        pcVar2 = (char *)(uVar13 + ((uint)puVar15 >> 1));
        *pcVar2 = (*pcVar2 - (char)in_CX) - (((uint)puVar15 & 1) != 0);
        return;
      }
      unaff_BP = *unaff_DI;
      bVar7 = (byte)puVar16[-0x16c0];
      bVar11 = (byte)((ulong)uVar5 >> 0x18);
      uVar10 = CONCAT11(bVar11,bVar7);
      uVar18 = CONCAT22(uVar10,uVar13);
      if (bVar7 != 5) {
        uVar14 = unaff_BP + 8;
        uVar6 = CONCAT22(uVar10,uVar13);
        if ((unaff_BP < 0xfff8) && (uVar6 = CONCAT22(uVar10,uVar13), uVar14 < uVar12)) {
          bVar3 = *(byte *)(uVar12 + (int)puVar15);
          bVar4 = bVar7 + *(byte *)(uVar12 + (int)puVar15);
          bVar9 = bVar4 + (uVar12 < uVar14);
          *unaff_DI = uVar13;
          unaff_DI = (uint *)((int)puVar16 + 5);
          *(char *)(puVar16 + 2) = (char)uVar5;
          *(char *)(uVar14 + (int)puVar15) =
               *(char *)(uVar14 + (int)puVar15) + (char)(uVar12 >> 8) +
               (CARRY1(bVar7,bVar3) || CARRY1(bVar4,uVar12 < uVar14));
          *(char *)(puVar15 + 0x1b) = (char)puVar15[0x1b] << 1;
          bVar7 = (byte)((ulong)uVar5 >> 8);
          if (bVar9 == bVar7) {
            *(undefined2 *)(uVar14 + (int)puVar15) = 0xa6e2;
            goto code_r0x000184d9;
          }
          puVar15[-0x3ffb] = (puVar15[-0x3ffb] - (int)&stack0x0000) - (uint)(bVar9 < bVar7);
          pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0xf);
          bVar17 = CARRY1(*pbVar1,bVar11);
          *pbVar1 = *pbVar1 + bVar11;
          uVar18 = FUN_1000_7a7c();
          in_CX = iVar8;
          unaff_BP = uVar14;
          uVar6 = uVar18;
          if (!bVar17) break;
        }
        goto LAB_1000_84d4;
      }
      uVar14 = unaff_BP;
      uVar6 = CONCAT22(uVar10,uVar13);
    } while (uVar12 <= unaff_BP);
  } while( true );
}


