/* 1000:65fc */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_1000_65fc(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  byte bVar6;
  byte extraout_AL;
  byte bVar7;
  uint in_AX;
  byte bVar9;
  int iVar8;
  undefined1 extraout_AH;
  int in_CX;
  int iVar10;
  int extraout_DX;
  byte *in_BX;
  int iVar11;
  int unaff_BP;
  int unaff_SI;
  byte *unaff_DI;
  byte *pbVar12;
  byte *unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  byte in_AF;
  bool bVar13;
  char cVar5;
  
  do {
    cVar5 = (char)in_AX;
    bVar9 = (byte)(in_AX >> 8);
    bVar4 = cVar5 + 0x80;
    if (bVar4 == 0x90) {
LAB_1000_6622_1:
      bVar13 = bVar4 == *in_BX;
      pbVar12 = unaff_DI;
    }
    else {
      if ((*(byte *)(unaff_SI + 10) & 0x20) != 0) {
        bVar4 = cVar5 + 0x83;
        goto LAB_1000_6622_1;
      }
      if (*(uint *)(unaff_SI + 6) < 1000) goto LAB_1000_6622_1;
      bVar6 = cVar5 + 0x81;
      pbVar12 = unaff_DI + 1;
      bVar2 = *unaff_DI;
      pbVar1 = in_BX;
      bVar4 = *pbVar1;
      bVar7 = *pbVar1;
      *pbVar1 = bVar7 + bVar9 + (bVar6 < bVar2);
      if (!CARRY1(bVar4,bVar9) && !CARRY1(bVar7 + bVar9,bVar6 < bVar2)) {
        bVar6 = cVar5 + 0x82;
      }
      bVar13 = bVar6 == *in_BX;
    }
    if (!bVar13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_DI = pbVar12 + 0x280;
    in_BX = in_BX + 1;
    if ((in_CX == 1) && (unaff_DI = pbVar12 + -0x757f, unaff_DS == 1)) {
      uVar3 = uRam00003be4 >> 8;
      iVar10 = (uRam00003be4 & 0xff) * 0x80;
      iVar8 = uRam00003be4 * 0x200 + iVar10;
      iVar11 = (uRam00003be4 & 0xff) + (uRam00003be4 >> 8) * 0x30;
      *(undefined1 *)(iVar11 + 0x648c) = 0xff;
      FUN_1000_59e0();
      bVar9 = extraout_AL | 0xa4;
      *(undefined1 *)(iVar8 + uVar3 + 0x28c + extraout_DX) = uRam000026bb;
      bRam000026bc = bRam000026bc ^ (byte)iVar10;
      in_AF = 9 < (bVar9 & 0xf) | in_AF;
      bVar7 = bVar9 + in_AF * -6 + (0x99 < bVar9) * -0x60;
      bVar4 = bVar7 - bRam000026bc;
      iVar8 = (CONCAT11(extraout_AH,bVar4 - (0x99 < bVar9)) + 0x2410) -
              (uint)(bVar7 < bRam000026bc || bVar4 < (0x99 < bVar9));
      bVar4 = (byte)iVar8;
      bVar13 = 0x99 < bVar4 || bVar4 < *unaff_ES;
      unaff_ES[iVar11 + 0x24] = unaff_ES[iVar11 + 0x24] + (byte)iVar10 + bVar13;
      return CONCAT11((char)((uint)iVar8 >> 8),
                      bVar4 + (9 < (bVar4 & 0xf) | in_AF) * -6 + bVar13 * -0x60) | 0x1f;
    }
    in_CX = 0x30;
    unaff_SI = *(int *)(unaff_BP + 0x1153);
    in_AX = (CONCAT11(bVar9,*(undefined1 *)(unaff_BP + -0x2d80)) | 0x74) + 0x75ca | 0xca;
    unaff_BP = unaff_BP + 2;
  } while( true );
}


