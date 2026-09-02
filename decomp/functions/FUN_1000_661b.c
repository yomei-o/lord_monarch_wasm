/* 1000:661b */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016623) overlaps instruction at (ram,0x00016622)
    */

uint FUN_1000_661b(void)

{
  int *piVar1;
  byte *pbVar2;
  bool bVar3;
  uint uVar4;
  byte bVar5;
  byte extraout_AL;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar10;
  undefined2 in_AX;
  byte bVar11;
  int iVar9;
  undefined1 extraout_AH;
  int in_CX;
  int iVar12;
  int extraout_DX;
  byte *in_BX;
  int iVar13;
  int unaff_BP;
  byte *unaff_DI;
  byte *pbVar14;
  byte *unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  byte in_AF;
  int in_stack_00000000;
  
  do {
    bVar7 = *unaff_DI;
    bVar5 = (byte)in_AX;
    pbVar2 = in_BX;
    bVar8 = *pbVar2;
    bVar11 = (byte)((uint)in_AX >> 8);
    bVar6 = *pbVar2;
    *pbVar2 = bVar6 + bVar11 + (bVar5 < bVar7);
    iVar9 = unaff_BP;
    pbVar14 = unaff_DI + 1;
    if (!CARRY1(bVar8,bVar11) && !CARRY1(bVar6 + bVar11,bVar5 < bVar7)) {
      in_AX = CONCAT11(bVar11,bVar5 + 1);
    }
    do {
      while( true ) {
        do {
          if ((byte)in_AX != *in_BX) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          unaff_DI = pbVar14 + 0x280;
          in_BX = in_BX + 1;
          unaff_BP = iVar9 + 2;
          if ((in_CX == 1) && (unaff_DI = pbVar14 + -0x757f, in_stack_00000000 == 1)) {
            uVar4 = uRam00003be4 >> 8;
            iVar12 = (uRam00003be4 & 0xff) * 0x80;
            iVar9 = uRam00003be4 * 0x200 + iVar12;
            iVar13 = (uRam00003be4 & 0xff) + (uRam00003be4 >> 8) * 0x30;
            *(undefined1 *)(iVar13 + 0x648c) = 0xff;
            FUN_1000_59e0();
            bVar6 = extraout_AL | 0xa4;
            *(undefined1 *)(iVar9 + uVar4 + 0x28c + extraout_DX) = uRam000026bb;
            bRam000026bc = bRam000026bc ^ (byte)iVar12;
            in_AF = 9 < (bVar6 & 0xf) | in_AF;
            bVar7 = bVar6 + in_AF * -6 + (0x99 < bVar6) * -0x60;
            bVar8 = bVar7 - bRam000026bc;
            iVar9 = (CONCAT11(extraout_AH,bVar8 - (0x99 < bVar6)) + 0x2410) -
                    (uint)(bVar7 < bRam000026bc || bVar8 < (0x99 < bVar6));
            bVar8 = (byte)iVar9;
            bVar3 = 0x99 < bVar8 || bVar8 < *unaff_ES;
            unaff_ES[iVar13 + 0x24] = unaff_ES[iVar13 + 0x24] + (byte)iVar12 + bVar3;
            return CONCAT11((char)((uint)iVar9 >> 8),
                            bVar8 + (9 < (bVar8 & 0xf) | in_AF) * -6 + bVar3 * -0x60) | 0x1f;
          }
          in_CX = 0x30;
          piVar1 = (int *)(iVar9 + 0x1153);
          iVar9 = (CONCAT11((char)((uint)in_AX >> 8),*(undefined1 *)(iVar9 + -0x2d80)) | 0x74) +
                  0x75ca;
          bVar8 = (byte)iVar9 | 0xca;
          uVar10 = (undefined1)((uint)iVar9 >> 8);
          in_AX = CONCAT11(uVar10,bVar8 + 0x80);
          iVar9 = unaff_BP;
          pbVar14 = unaff_DI;
          in_stack_00000000 = unaff_DS;
        } while ((byte)(bVar8 + 0x80) == -0x70);
        if ((*(byte *)(*piVar1 + 10) & 0x20) == 0) break;
        in_AX = CONCAT11(uVar10,bVar8 + 0x83);
      }
    } while (*(uint *)(*piVar1 + 6) < 1000);
    in_AX = CONCAT11(uVar10,bVar8 + 0x81);
  } while( true );
}


