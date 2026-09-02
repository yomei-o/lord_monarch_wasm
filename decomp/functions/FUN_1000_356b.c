/* 1000:356b */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012673) overlaps instruction at (ram,0x00012671)
    */

void FUN_1000_356b(undefined2 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  uint *puVar4;
  byte bVar5;
  code *pcVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  undefined2 in_AX;
  byte bVar10;
  int iVar11;
  uint uVar12;
  uint in_CX;
  byte bVar13;
  byte in_DL;
  uint uVar14;
  int iVar15;
  int in_BX;
  int unaff_BP;
  uint uVar16;
  byte *unaff_SI;
  uint *puVar17;
  uint *puVar18;
  int unaff_DI;
  undefined2 unaff_ES;
  uint *unaff_CS;
  undefined2 unaff_SS;
  int unaff_DS;
  byte in_CF;
  byte in_AF;
  undefined1 uVar19;
  bool bVar20;
  
  bVar7 = (byte)in_AX;
  bVar7 = bVar7 + (9 < (bVar7 & 0xf) | in_AF) * -6 + (0x99 < bVar7 | in_CF) * -0x60;
  uVar16 = CONCAT11((char)((uint)in_AX >> 8),bVar7);
  bVar10 = (byte)in_CX;
  bVar13 = (byte)(in_CX >> 8);
  if ((bVar7 == 0) || (in_DL == 0)) {
    bVar5 = *unaff_SI;
    pbVar1 = unaff_SI + unaff_BP;
    bVar13 = *pbVar1;
    bVar3 = *pbVar1;
    *pbVar1 = bVar3 + bVar7 + CARRY1(bVar10,bVar5);
    unaff_SI[unaff_BP] =
         unaff_SI[unaff_BP] + (char)unaff_SS +
         (uVar16 < *(uint *)(unaff_SI + unaff_BP) ||
         uVar16 - *(uint *)(unaff_SI + unaff_BP) <
         (uint)(CARRY1(bVar13,bVar7) || CARRY1(bVar3 + bVar7,CARRY1(bVar10,bVar5))));
    pcVar6 = (code *)swi(3);
    (*pcVar6)(&stack0xfffe);
    return;
  }
  pbVar1 = unaff_SI + unaff_BP;
  bVar7 = *pbVar1;
  bVar3 = *pbVar1;
  *pbVar1 = bVar3 + bVar10 + (in_DL < 0xf);
  bVar7 = -(CARRY1(bVar7,bVar10) || CARRY1(bVar3 + bVar10,in_DL < 0xf));
  bVar7 = bVar7 + bVar13 + CARRY1(bVar7,bVar13) + 0x44;
  if (bVar7 < 0x30) {
    in(0x575a);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar2 = (char *)(unaff_DI + 0x6f);
  *pcVar2 = *pcVar2 << (bVar10 & 0x1f);
  bVar20 = (in_CX & 0x1f) != 0;
  uVar19 = !bVar20 && bVar7 == 0x30 || bVar20 && *pcVar2 == '\0';
  FUN_1000_5f51();
  FUN_1000_75c3();
  uVar16 = 0x1203;
  param_1 = 0x2563;
  param_2 = FUN_1000_5c72();
  bVar20 = true;
  if (!(bool)uVar19) {
    FUN_1000_6bca();
    param_1 = 0x256d;
    bVar7 = func_0x00013abe();
    *(byte *)0x1203 = *(byte *)0x1203 & bVar7;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX | *(byte *)(in_BX + 0x1d));
    uVar8 = func_0x00016bc7();
    uVar16 = 0x1202;
    bVar20 = (char)((char)uVar8 + -0x61 + (uVar8 < 0x8304)) == '\0';
    unaff_DS = param_3;
    param_2 = unaff_BP;
    param_3 = unaff_BP;
  }
  iVar11 = in_CX - 1;
  if (iVar11 == 0 || bVar20) {
    FUN_1000_435f();
    param_1 = 0x25bf;
    func_0x00016bbf();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  XRELEASE();
  *(uint *)(unaff_BP + -2) = uVar16;
  *(int *)(unaff_BP + -4) = unaff_DI - iVar11;
  iVar11 = (in_BX * 0x30 + iVar11) * 2;
  puVar17 = (uint *)(iVar11 + -0x2d82);
  uVar9 = CONCAT11(100,(char)*(undefined2 *)0x34ce);
  iVar15 = 0x60;
  uVar8 = *(uint *)(unaff_BP + -2);
  uVar14 = *(uint *)(unaff_BP + -4);
  if (-1 < (int)uVar14) {
    bVar20 = true;
    if (uVar8 < uVar14) {
      while( true ) {
        uVar12 = uVar8;
        *(int *)(uVar16 + 0x60) = (*(int *)(uVar16 + 0x60) - (int)&stack0x0002) - (uint)bVar20;
        *puVar17 = uVar9;
        bVar20 = uVar16 < uVar12;
        uVar16 = uVar16 - uVar12;
        puVar18 = puVar17 + 1;
        if (bVar20) {
          uVar16 = uVar16 + *(int *)(unaff_BP + -4);
          puVar18 = puVar17 + 0x31;
        }
        bVar20 = bVar20 && (uint *)0xff9f < puVar17 + 1;
        if (uVar14 - 1 == 0) break;
        puVar17 = puVar18 + 1;
        *puVar18 = uVar9;
        uVar8 = uVar14 - 1;
        uVar14 = uVar12;
      }
      iVar15 = *(int *)(unaff_BP + -2) * 0x60;
      iVar11 = *(int *)(unaff_BP + -4);
    }
    else {
      uVar16 = uVar8 >> 1;
      iVar11 = uVar8 + 1;
      do {
        *puVar17 = uVar9;
        puVar18 = puVar17 + 0x30;
        bVar20 = uVar16 < uVar14;
        uVar16 = uVar16 - uVar14;
        if (bVar20) {
          uVar16 = uVar16 + *(int *)(unaff_BP + -2);
          puVar18 = puVar17 + 0x31;
        }
        iVar11 = iVar11 + -1;
        puVar17 = puVar18;
      } while (iVar11 != 0);
      *(char *)(uVar16 - 0x15) = *(char *)(uVar16 - 0x15) + '\x01';
      iVar11 = 0;
    }
    iVar11 = iVar11 + 1;
    do {
      *(uint *)(iVar15 + (int)puVar18) = uVar9;
      puVar4 = puVar18;
      puVar18 = puVar18 + 1;
      *puVar4 = uVar9;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = *(int *)(unaff_BP + -4);
    iVar15 = *(int *)(unaff_BP + -2) + 1;
    do {
      *unaff_CS = uVar9;
      unaff_CS[iVar11] = uVar9;
      unaff_CS = unaff_CS + 0x30;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(uint *)(unaff_BP + -4) = uVar14;
  do {
  } while ((uVar9 ^ 0x8f0) == 0);
  *(char *)(unaff_BP + uVar16) =
       *(char *)(unaff_BP + uVar16) + (char)(uVar9 ^ 0x8f0) + (puVar17 < (uint *)0x35);
  *(uint *)(iVar11 + -0x2db7) = uVar9 ^ 0x2b0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


