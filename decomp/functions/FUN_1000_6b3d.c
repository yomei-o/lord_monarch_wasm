/* 1000:6b3d */

/* WARNING: Instruction at (ram,0x00016bc4) overlaps instruction at (ram,0x00016bc3)
    */
/* WARNING: Removing unreachable block (ram,0x00016b15) */
/* WARNING: Removing unreachable block (ram,0x00016b25) */

ulong FUN_1000_6b3d(char *param_1,byte *param_2,int param_3,undefined2 param_4,int param_5,
                   undefined2 param_6,byte *param_7,uint param_8,undefined1 *param_9)

{
  uint *puVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  code *pcVar5;
  byte bVar6;
  undefined2 in_CX;
  uint uVar7;
  int iVar8;
  int iVar9;
  char extraout_DL;
  undefined2 in_DX;
  byte bVar10;
  int extraout_DX;
  undefined2 in_BX;
  byte *pbVar11;
  int iVar12;
  int unaff_BP;
  int iVar13;
  undefined1 *unaff_SI;
  uint uVar14;
  int unaff_DI;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar17;
  char cVar18;
  byte in_AF;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar19;
  ulong uVar20;
  undefined2 in_stack_00000000;
  undefined1 *puVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  
  bVar10 = (byte)((uint)in_DX >> 8);
  iVar12 = CONCAT11(bVar10,0xf2);
  puVar1 = (uint *)(unaff_DI + -0x35);
  iVar13 = ((uint)unaff_SI & 3) - (*puVar1 & 3);
  *puVar1 = *puVar1 + (uint)(0 < iVar13) * iVar13;
  unaff_SI[unaff_BP + 0x4f] = unaff_SI[unaff_BP + 0x4f] | (byte)((uint)in_BX >> 8);
  pbVar11 = (byte *)0x1fc7;
  cVar18 = unaff_SI[-0x1fab];
  *(undefined1 *)(unaff_DI + -1) = *unaff_SI;
  *(undefined1 *)(unaff_DI + iVar12) = unaff_SI[1];
  puVar15 = (undefined1 *)(unaff_DI + iVar12) + iVar12 + 1;
  puVar21 = &stack0xfffe;
  pbVar2 = unaff_SI + 2;
  *pbVar2 = *pbVar2 ^ (byte)in_CX;
  iVar13 = unaff_BP + -1;
  puVar16 = unaff_SI + 3;
  out(unaff_SI[2],iVar12);
  bVar17 = bVar10 < (byte)unaff_SI[0x1fcc];
  uVar7 = CONCAT11((char)((uint)in_CX >> 8) + cVar18,(byte)in_CX) - 1;
  if (uVar7 == 0 || bVar10 == unaff_SI[0x1fcc]) {
    LOCK();
    puVar16[unaff_BP + 0x1d] = puVar16[unaff_BP + 0x1d] ^ 199;
    UNLOCK();
    uVar23 = 0xf03a;
    uVar22 = 0x1fc7;
    iVar8 = (uVar7 & 0xff) << 3;
    uVar14 = 0x5f1c;
    iVar9 = 8;
    do {
      FUN_1000_6baa(iVar8,puVar15,puVar16,iVar13,puVar21,uVar22,iVar12,uVar7,uVar23);
      cVar18 = 0xfffc < uVar14;
      uVar14 = uVar14 + 3;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    do {
      iVar13 = 0x6b92;
      FUN_1000_74aa(puVar15);
      pbVar11[uVar14] = pbVar11[uVar14] + extraout_DL + cVar18;
      puVar15 = (undefined1 *)0x6b97;
      uVar19 = FUN_1000_6ba9();
      cVar18 = uVar14 < 3;
      uVar14 = uVar14 - 3;
      bVar17 = iVar8 != 1;
      iVar8 = iVar13;
    } while (bVar17);
    return CONCAT22(CONCAT11(((char)((ulong)uVar19 >> 0x18) - pbVar11[uVar14]) -
                             CARRY1((byte)uVar19,*pbVar11),
                             ((char)((ulong)uVar19 >> 0x10) - pbVar11[uVar14]) - cVar18),
                    CONCAT11((char)((ulong)uVar19 >> 8),(byte)uVar19 + *pbVar11)) | 0x61;
  }
  while( true ) {
    puVar16[iVar13] = puVar16[iVar13] + (char)((uint)iVar12 >> 8) + bVar17;
    *(byte *)0x5e59 = *(byte *)0x5e59 ^ (byte)uVar7;
    iVar12 = CONCAT11(((char)((uint)param_7 >> 8) - param_1[param_3 + 0x1f]) - (0xffaf < unaff_ES),
                      (byte)param_7);
    bVar10 = (byte)((uint)param_6 >> 8);
    iVar13 = CONCAT11(bVar10,(byte)param_6 & (byte)param_7);
    if ((iVar12 != 0) && (iVar12 != 0)) break;
    bVar6 = (byte)param_8;
    in_AF = 9 < (bVar6 & 0xf) | in_AF;
    param_7 = (byte *)(param_1 + 1);
    *param_1 = bVar6 + in_AF * -6 + (0x99 < bVar6) * -0x60;
    *(double *)(param_2 + param_5) = (double)in_ST0;
    *param_7 = *param_2;
    bVar6 = param_2[1];
    pbVar11 = param_7;
    for (; pbVar11 = pbVar11 + 1, iVar13 != 0; iVar13 = iVar13 + -1) {
      *pbVar11 = bVar6;
    }
    *pbVar11 = param_2[2];
    *(byte **)(param_2 + param_5 + -0x47ce) =
         param_2 + (uint)((byte *)0xffd2 < param_2 + 3) +
                   *(int *)(param_2 + param_5 + -0x47ce) + 0x30;
    unaff_SS = *(undefined2 *)(param_2 + param_5 + 0x30);
    bVar17 = false;
    iVar12 = (uint)(bVar10 ^ param_2[param_5 + 0x30]) << 8;
    param_8 = 0x1000;
    uVar7 = param_8;
    iVar13 = param_3;
    puVar16 = param_9;
    in_ST0 = in_ST1;
    in_ST1 = in_ST2;
    in_ST2 = in_ST3;
    in_ST3 = in_ST4;
    in_ST4 = in_ST5;
    in_ST5 = in_ST6;
    in_ST6 = in_ST7;
  }
  if (iVar12 != 0) {
    puVar16 = (undefined1 *)((int)(param_1 + param_8) * 2 + 0x50d);
    uVar19 = func_0x000e3580();
    uVar7 = (0x27 - ((int)((ulong)uVar19 >> 0x10) + -1)) * 2;
    cVar18 = (char)((uint)iVar12 >> 8);
    if ((POPCOUNT(uVar7 & 0xff) & 1U) == 0) {
      param_2[iVar12 + 0x10f] = param_2[iVar12 + 0x10f] - cVar18;
      func_0x00014c23();
      do {
        puVar3 = (undefined2 *)(puVar16 + 1);
        *puVar16 = 0xff;
        for (iVar13 = extraout_DX; iVar13 != 0; iVar13 = iVar13 + -1) {
          puVar4 = puVar3;
          puVar3 = puVar3 + 1;
          *puVar4 = 0xffff;
        }
        *(undefined1 *)puVar3 = 0xff;
        puVar16 = (undefined1 *)((int)puVar3 + uVar7 + 1);
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      *(undefined1 *)0xf566 = 0xff;
      pbVar2 = param_2;
      bVar10 = *pbVar2;
      *pbVar2 = *pbVar2 - 0x25;
      return CONCAT22(extraout_DX,CONCAT11(0xf5,(0x24 < bVar10) + -0x18));
    }
    return (ulong)CONCAT12(cVar18,(int)uVar19) | 0x8b05;
  }
  pcVar5 = (code *)swi(3);
  uVar20 = (*pcVar5)();
  return uVar20;
}


