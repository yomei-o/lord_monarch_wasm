/* 1000:3578 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012673) overlaps instruction at (ram,0x00012671)
    */

void FUN_1000_3578(undefined2 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  uint in_CX;
  byte bVar10;
  byte in_DL;
  uint uVar11;
  int iVar12;
  int in_BX;
  int unaff_BP;
  uint uVar13;
  int unaff_SI;
  uint *puVar14;
  uint *puVar15;
  int unaff_DI;
  undefined2 unaff_ES;
  uint *unaff_CS;
  undefined2 unaff_SS;
  int unaff_DS;
  undefined1 uVar16;
  bool bVar17;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI);
  bVar4 = *pbVar1;
  bVar7 = (byte)in_CX;
  bVar10 = *pbVar1;
  *pbVar1 = bVar10 + bVar7 + (in_DL < 0xf);
  bVar4 = -(CARRY1(bVar4,bVar7) || CARRY1(bVar10 + bVar7,in_DL < 0xf));
  bVar10 = (byte)(in_CX >> 8);
  bVar4 = bVar4 + bVar10 + CARRY1(bVar4,bVar10) + 0x44;
  if (bVar4 < 0x30) {
    in(0x575a);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar2 = (char *)(unaff_DI + 0x6f);
  *pcVar2 = *pcVar2 << (bVar7 & 0x1f);
  bVar17 = (in_CX & 0x1f) != 0;
  uVar16 = !bVar17 && bVar4 == 0x30 || bVar17 && *pcVar2 == '\0';
  FUN_1000_5f51();
  FUN_1000_75c3();
  uVar13 = 0x1203;
  param_1 = 0x2563;
  param_2 = FUN_1000_5c72();
  bVar17 = true;
  if (!(bool)uVar16) {
    FUN_1000_6bca();
    param_1 = 0x256d;
    bVar4 = func_0x00013abe();
    *(byte *)0x1203 = *(byte *)0x1203 & bVar4;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX | *(byte *)(in_BX + 0x1d));
    uVar5 = func_0x00016bc7();
    uVar13 = 0x1202;
    bVar17 = (char)((char)uVar5 + -0x61 + (uVar5 < 0x8304)) == '\0';
    unaff_DS = param_3;
    param_2 = unaff_BP;
    param_3 = unaff_BP;
  }
  iVar8 = in_CX - 1;
  if (iVar8 != 0 && !bVar17) {
    XRELEASE();
    *(uint *)(unaff_BP + -2) = uVar13;
    *(int *)(unaff_BP + -4) = unaff_DI - iVar8;
    iVar8 = (in_BX * 0x30 + iVar8) * 2;
    puVar14 = (uint *)(iVar8 + -0x2d82);
    uVar6 = CONCAT11(100,(char)*(undefined2 *)0x34ce);
    iVar12 = 0x60;
    uVar5 = *(uint *)(unaff_BP + -2);
    uVar11 = *(uint *)(unaff_BP + -4);
    if ((int)uVar11 < 0) {
      *(uint *)(unaff_BP + -4) = uVar11;
      do {
      } while ((uVar6 ^ 0x8f0) == 0);
      *(char *)(unaff_BP + uVar13) =
           *(char *)(unaff_BP + uVar13) + (char)(uVar6 ^ 0x8f0) + (puVar14 < (uint *)0x35);
      *(uint *)(iVar8 + -0x2db7) = uVar6 ^ 0x2b0;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar17 = true;
    if (uVar5 < uVar11) {
      while( true ) {
        uVar9 = uVar5;
        *(int *)(uVar13 + 0x60) = (*(int *)(uVar13 + 0x60) - (int)&stack0x0002) - (uint)bVar17;
        *puVar14 = uVar6;
        bVar17 = uVar13 < uVar9;
        uVar13 = uVar13 - uVar9;
        puVar15 = puVar14 + 1;
        if (bVar17) {
          uVar13 = uVar13 + *(int *)(unaff_BP + -4);
          puVar15 = puVar14 + 0x31;
        }
        bVar17 = bVar17 && (uint *)0xff9f < puVar14 + 1;
        if (uVar11 - 1 == 0) break;
        puVar14 = puVar15 + 1;
        *puVar15 = uVar6;
        uVar5 = uVar11 - 1;
        uVar11 = uVar9;
      }
      iVar12 = *(int *)(unaff_BP + -2) * 0x60;
      iVar8 = *(int *)(unaff_BP + -4);
    }
    else {
      uVar13 = uVar5 >> 1;
      iVar8 = uVar5 + 1;
      do {
        *puVar14 = uVar6;
        puVar15 = puVar14 + 0x30;
        bVar17 = uVar13 < uVar11;
        uVar13 = uVar13 - uVar11;
        if (bVar17) {
          uVar13 = uVar13 + *(int *)(unaff_BP + -2);
          puVar15 = puVar14 + 0x31;
        }
        iVar8 = iVar8 + -1;
        puVar14 = puVar15;
      } while (iVar8 != 0);
      *(char *)(uVar13 - 0x15) = *(char *)(uVar13 - 0x15) + '\x01';
      iVar8 = 0;
    }
    iVar8 = iVar8 + 1;
    do {
      *(uint *)(iVar12 + (int)puVar15) = uVar6;
      puVar3 = puVar15;
      puVar15 = puVar15 + 1;
      *puVar3 = uVar6;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar8 = *(int *)(unaff_BP + -4);
    iVar12 = *(int *)(unaff_BP + -2) + 1;
    do {
      *unaff_CS = uVar6;
      unaff_CS[iVar8] = uVar6;
      unaff_CS = unaff_CS + 0x30;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_1000_435f();
  param_1 = 0x25bf;
  func_0x00016bbf();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


