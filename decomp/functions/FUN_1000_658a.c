/* 1000:658a */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00016634) */
/* WARNING: Removing unreachable block (ram,0x0001663b) */
/* WARNING: Removing unreachable block (ram,0x00016681) */
/* WARNING: Removing unreachable block (ram,0x00016683) */
/* WARNING: Removing unreachable block (ram,0x0001659d) */

void FUN_1000_658a(void)

{
  char *pcVar1;
  byte bVar2;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined2 in_AX;
  int iVar8;
  byte bVar9;
  undefined2 in_DX;
  uint uVar10;
  uint uVar11;
  int in_BX;
  byte *pbVar12;
  int unaff_BP;
  int iVar13;
  undefined2 *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar14;
  byte bVar3;
  
  out(*unaff_SI,in_DX);
  *(undefined2 *)((int)unaff_SI + unaff_BP + 2) = unaff_ES;
  bVar6 = 0;
  uVar10 = 0x4444 - unaff_SI[0x61];
  while( true ) {
    *(byte *)((int)unaff_SI + -0x463d) = *(byte *)((int)unaff_SI + -0x463d) | bVar6;
    pcVar1 = (char *)((int)unaff_SI + unaff_BP + 0x2a2a);
    *pcVar1 = *pcVar1 + '@';
    unaff_DI[unaff_BP + 0x75] = unaff_DI[unaff_BP + 0x75] & 0x18;
    uVar11 = uVar10 + 0x800;
    if ((0xb800 < uVar11) && (bVar14 = 0xdfff < uVar11, uVar11 = uVar10 + 0x2800, bVar14)) break;
    bVar6 = 0x33;
    *(undefined1 *)(unaff_BP + 0x2bc2) = *(undefined1 *)(unaff_BP + 0x2bc2);
    uVar10 = uVar11;
  }
  iVar8 = (uint)(byte)((byte)((uint)in_AX >> 8) ^ *(byte *)((int)unaff_SI + in_BX + -0x41)) << 8;
  *(undefined2 *)(unaff_BP + (int)unaff_SI) = unaff_ES;
  iVar13 = 0;
  pbVar12 = (byte *)0x648c;
  do {
    iVar8 = (CONCAT11((char)((uint)iVar8 >> 8),*(undefined1 *)(iVar13 + -0x2d82)) | 0x74) + 0x75ca;
    bVar6 = (byte)iVar8 | 0xca;
    bVar9 = (byte)((uint)iVar8 >> 8);
    iVar8 = CONCAT11(bVar9,bVar6 + 0x80);
    if ((byte)(bVar6 + 0x80) == -0x70) {
LAB_1000_6622_1:
      bVar14 = (byte)iVar8 == *pbVar12;
    }
    else {
      if ((*(byte *)(*(int *)(iVar13 + 0x1151) + 10) & 0x20) != 0) {
        iVar8 = CONCAT11(bVar9,bVar6 + 0x83);
        goto LAB_1000_6622_1;
      }
      if (*(uint *)(*(int *)(iVar13 + 0x1151) + 6) < 1000) goto LAB_1000_6622_1;
      bVar7 = bVar6 + 0x81;
      pbVar4 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      bVar5 = *pbVar4;
      pbVar4 = pbVar12;
      bVar2 = *pbVar4;
      bVar3 = *pbVar4;
      *pbVar4 = bVar3 + bVar9 + (bVar7 < bVar5);
      if (!CARRY1(bVar2,bVar9) && !CARRY1(bVar3 + bVar9,bVar7 < bVar5)) {
        bVar7 = bVar6 + 0x82;
      }
      iVar8 = CONCAT11(bVar9,bVar7);
      bVar14 = bVar7 == *pbVar12;
    }
    if (!bVar14) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_DI = unaff_DI + 0x280;
    pbVar12 = pbVar12 + 1;
    iVar13 = iVar13 + 2;
  } while( true );
}


