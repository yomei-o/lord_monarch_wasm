/* 1000:9b7a */

void FUN_1000_9b7a(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  uint uVar4;
  bool bVar5;
  long lVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  char extraout_AH;
  uint uVar11;
  byte in_CL;
  byte bVar12;
  undefined2 extraout_DX;
  byte bVar13;
  undefined2 extraout_DX_00;
  byte bVar14;
  int in_BX;
  int iVar15;
  int unaff_BP;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar16;
  char cVar17;
  byte bVar18;
  ulong uVar19;
  undefined4 uVar20;
  
  in(0x2e);
  func_0x00015bd6();
  uVar3 = in(extraout_DX);
  *(undefined1 *)0x2fa4 = uVar3;
  lVar6 = FUN_1000_8940();
  lVar6 = lVar6 / (long)*(int *)(in_BX + 0x2fa5);
  bVar8 = (byte)lVar6;
  uVar9 = CONCAT11((char)((ulong)lVar6 >> 8),bVar8 + *(byte *)0xa6cd);
  puVar1 = (uint *)0xa6eb;
  uVar11 = (uint)CARRY1(bVar8,*(byte *)0xa6cd);
  uVar4 = *puVar1 + uVar9;
  cVar16 = CARRY2(*puVar1,uVar9) || CARRY2(uVar4,uVar11);
  *puVar1 = uVar4 + uVar11;
  func_0x0003b312();
  uVar19 = func_0x0004a8ae();
  bVar14 = (byte)in_BX;
  *(char *)(unaff_BP + -0x5915) = *(char *)(unaff_BP + -0x5915) + bVar14 + cVar16;
  ((char *)s_0___sound_Driver_0000_2eec + 1)[unaff_BP] =
       ((char *)s_0___sound_Driver_0000_2eec + 1)[unaff_BP] >> 0x1f;
  bVar18 = (uVar19 & 0x1000) != 0;
  *(byte *)(in_BX + 0x31b5) = *(byte *)(in_BX + 0x31b5) & in_CL;
  bVar7 = ((byte)uVar19 ^ 0xe8) + 0x40 & 0x30;
  pbVar2 = (byte *)(in_BX + -0x7114);
  bVar8 = *pbVar2;
  bVar13 = (byte)(uVar19 >> 0x18);
  *pbVar2 = *pbVar2 + bVar13;
  bVar12 = bVar14 + *(byte *)(unaff_BP + -0x2b57);
  cVar16 = bVar12 + CARRY1(bVar8,bVar13);
  iVar15 = CONCAT11((char)((uint)in_BX >> 8),cVar16);
  bVar5 = 0x99 < bVar7 ||
          (CARRY1(bVar14,*(byte *)(unaff_BP + -0x2b57)) || CARRY1(bVar12,CARRY1(bVar8,bVar13)));
  bVar8 = bVar7 + bVar18 * -6 + bVar5 * -0x60;
  *(char *)(unaff_BP + -0x5915) = *(char *)(unaff_BP + -0x5915) + cVar16 + bVar5;
  bVar8 = CARRY1(bVar8,bVar8);
  func_0x00015bc3((int)(uVar19 >> 0x10));
  iVar10 = func_0x000190c9();
  *(uint *)((char *)s_0___sound_Driver_0000_2eec + 9 + unaff_BP) =
       *(int *)((char *)s_0___sound_Driver_0000_2eec + 9 + unaff_BP) + iVar10 + (uint)bVar8;
  bVar18 = 9 < ((byte)iVar10 & 0xf) | bVar18;
  pbVar2 = (byte *)(unaff_BP + 0x2f35);
  bVar8 = *pbVar2 + (byte)iVar15;
  cVar16 = CARRY1(*pbVar2,(byte)iVar15) || CARRY1(bVar8,bVar18);
  *pbVar2 = bVar8 + bVar18;
  func_0x00015bbb();
  uVar20 = FUN_1000_a3c1();
  cVar16 = (char)uVar20 + *(char *)0x2f35 + cVar16;
  out((int)((ulong)uVar20 >> 0x10),cVar16);
  iVar10 = CONCAT11((char)((ulong)uVar20 >> 8),cVar16) + -1;
  bVar8 = (byte)iVar10;
  bVar18 = 9 < (bVar8 & 0xf) | bVar18;
  *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)iVar15 + bVar18;
  bVar18 = ((CONCAT11((char)((uint)iVar10 >> 8) - bVar18,bVar8 + bVar18 * -6) & 0xff0f) + 0xbf2f &
           0x1000) != 0;
  cVar16 = -0x41;
  func_0x0001f1ba();
  bVar12 = cVar16 + (char)extraout_DX_00;
  *(char *)(unaff_BP + 0x2f3d) = *(char *)(unaff_BP + 0x2f3d) + (char)((uint)extraout_DX_00 >> 8);
  uVar11 = CONCAT11(extraout_AH - bVar18,bVar18 * -6) & 0xff0f;
  pbVar2 = (byte *)(unaff_BP + 0x2f45);
  bVar8 = *pbVar2 + (byte)iVar15;
  cVar17 = CARRY1(*pbVar2,(byte)iVar15) || CARRY1(bVar8,bVar18);
  *pbVar2 = bVar8 + bVar18;
  func_0x00015bb1();
  cVar16 = func_0x0001ebb7();
  iVar10 = uVar11 + 1;
  pbVar2 = (byte *)(unaff_BP + iVar10 + -0x4167);
  *pbVar2 = *pbVar2 | (cVar16 + *(char *)(unaff_BP + uVar11) + cVar17) - 1U;
  pbVar2 = (byte *)(unaff_BP + -1 + iVar10);
  *pbVar2 = *pbVar2 & (byte)iVar15;
  iVar10 = iVar15;
  func_0x00015ba8();
  FUN_1000_20ae();
  *(byte *)(iVar10 + 0x2f75) = *(byte *)(iVar10 + 0x2f75) | 8;
  *(byte *)(unaff_BP + 0x5554) = *(byte *)(unaff_BP + 0x5554) & (byte)iVar10;
  FUN_1000_5ba1();
  FUN_1000_33a7();
  pbVar2 = (byte *)(unaff_BP + -1 + iVar15);
  *pbVar2 = *pbVar2 | (byte)((uint)iVar10 >> 8);
  *(byte *)(iVar10 + 0x3f5d) = *(byte *)(iVar10 + 0x3f5d) & bVar12;
  return;
}


