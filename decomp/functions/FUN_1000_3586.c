/* 1000:3586 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012673) overlaps instruction at (ram,0x00012671)
    */

void FUN_1000_3586(undefined2 param_1,int param_2,int param_3)

{
  char *pcVar1;
  uint *puVar2;
  byte bVar3;
  char in_AL;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint in_CX;
  uint uVar8;
  undefined2 in_DX;
  int iVar9;
  int in_BX;
  int unaff_BP;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  int unaff_DI;
  undefined2 unaff_ES;
  uint *unaff_CS;
  undefined2 unaff_SS;
  int unaff_DS;
  undefined1 uVar13;
  bool bVar14;
  
  if ((byte)(in_AL - 0x30U) < 0x30) {
    in(in_DX);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar1 = (char *)(unaff_DI + 0x6f);
  *pcVar1 = *pcVar1 << ((byte)in_CX & 0x1f);
  bVar14 = (in_CX & 0x1f) != 0;
  uVar13 = !bVar14 && (byte)(in_AL - 0x30U) == 0x30 || bVar14 && *pcVar1 == '\0';
  FUN_1000_5f51();
  FUN_1000_75c3();
  uVar10 = 0x1203;
  param_1 = 0x2563;
  param_2 = FUN_1000_5c72();
  bVar14 = true;
  if (!(bool)uVar13) {
    FUN_1000_6bca();
    param_1 = 0x256d;
    bVar3 = func_0x00013abe();
    *(byte *)0x1203 = *(byte *)0x1203 & bVar3;
    in_BX = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX | *(byte *)(in_BX + 0x1d));
    uVar4 = func_0x00016bc7();
    uVar10 = 0x1202;
    bVar14 = (char)((char)uVar4 + -0x61 + (uVar4 < 0x8304)) == '\0';
    unaff_DS = param_3;
    param_2 = unaff_BP;
    param_3 = unaff_BP;
  }
  iVar6 = in_CX - 1;
  if (iVar6 != 0 && !bVar14) {
    XRELEASE();
    *(uint *)(unaff_BP + -2) = uVar10;
    *(int *)(unaff_BP + -4) = unaff_DI - iVar6;
    iVar6 = (in_BX * 0x30 + iVar6) * 2;
    puVar11 = (uint *)(iVar6 + -0x2d82);
    uVar5 = CONCAT11(100,(char)*(undefined2 *)0x34ce);
    iVar9 = 0x60;
    uVar4 = *(uint *)(unaff_BP + -2);
    uVar8 = *(uint *)(unaff_BP + -4);
    if ((int)uVar8 < 0) {
      *(uint *)(unaff_BP + -4) = uVar8;
      do {
      } while ((uVar5 ^ 0x8f0) == 0);
      *(char *)(unaff_BP + uVar10) =
           *(char *)(unaff_BP + uVar10) + (char)(uVar5 ^ 0x8f0) + (puVar11 < (uint *)0x35);
      *(uint *)(iVar6 + -0x2db7) = uVar5 ^ 0x2b0;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar14 = true;
    if (uVar4 < uVar8) {
      while( true ) {
        uVar7 = uVar4;
        *(int *)(uVar10 + 0x60) = (*(int *)(uVar10 + 0x60) - (int)&stack0x0002) - (uint)bVar14;
        *puVar11 = uVar5;
        bVar14 = uVar10 < uVar7;
        uVar10 = uVar10 - uVar7;
        puVar12 = puVar11 + 1;
        if (bVar14) {
          uVar10 = uVar10 + *(int *)(unaff_BP + -4);
          puVar12 = puVar11 + 0x31;
        }
        bVar14 = bVar14 && (uint *)0xff9f < puVar11 + 1;
        if (uVar8 - 1 == 0) break;
        puVar11 = puVar12 + 1;
        *puVar12 = uVar5;
        uVar4 = uVar8 - 1;
        uVar8 = uVar7;
      }
      iVar9 = *(int *)(unaff_BP + -2) * 0x60;
      iVar6 = *(int *)(unaff_BP + -4);
    }
    else {
      uVar10 = uVar4 >> 1;
      iVar6 = uVar4 + 1;
      do {
        *puVar11 = uVar5;
        puVar12 = puVar11 + 0x30;
        bVar14 = uVar10 < uVar8;
        uVar10 = uVar10 - uVar8;
        if (bVar14) {
          uVar10 = uVar10 + *(int *)(unaff_BP + -2);
          puVar12 = puVar11 + 0x31;
        }
        iVar6 = iVar6 + -1;
        puVar11 = puVar12;
      } while (iVar6 != 0);
      *(char *)(uVar10 - 0x15) = *(char *)(uVar10 - 0x15) + '\x01';
      iVar6 = 0;
    }
    iVar6 = iVar6 + 1;
    do {
      *(uint *)(iVar9 + (int)puVar12) = uVar5;
      puVar2 = puVar12;
      puVar12 = puVar12 + 1;
      *puVar2 = uVar5;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = *(int *)(unaff_BP + -4);
    iVar9 = *(int *)(unaff_BP + -2) + 1;
    do {
      *unaff_CS = uVar5;
      unaff_CS[iVar6] = uVar5;
      unaff_CS = unaff_CS + 0x30;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_1000_435f();
  param_1 = 0x25bf;
  func_0x00016bbf();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


