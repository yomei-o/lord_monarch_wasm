/* 1000:2425 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012673) overlaps instruction at (ram,0x00012671)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_2425(void)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  byte bVar4;
  uint in_AX;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint in_CX;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined2 in_DX;
  uint uVar11;
  byte bVar12;
  undefined2 in_BX;
  undefined1 uVar13;
  int *piVar14;
  undefined1 *puVar15;
  int *piVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  int *unaff_BP;
  int iVar20;
  byte *unaff_SI;
  uint uVar21;
  int unaff_DI;
  uint *puVar22;
  uint *puVar23;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar24;
  bool bVar25;
  char cVar26;
  
  bVar12 = *unaff_SI;
  uVar13 = (undefined1)((uint)in_BX >> 8);
  bVar24 = *(byte *)(CONCAT11(uVar13,bVar12) + 0x2200);
  pbVar1 = unaff_SI + 3;
  bVar4 = (byte)in_CX & 0x1f;
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 << bVar4;
  bVar25 = (in_CX & 0x1f) == 0;
  bVar24 = bVar25 * ((byte)((uint)in_DX >> 8) < bVar24) |
           !bVar25 * ((char)(bVar3 << bVar4 - 1) < '\0');
  cVar26 = *(char *)0x9e8;
  iVar20 = *unaff_BP;
  *unaff_SI = *unaff_SI ^ (char)(in_AX + 0x850) + bVar24;
  pbVar1 = (byte *)(iVar20 + unaff_DI + 0x4d);
  *pbVar1 = *pbVar1 & (byte)in_DX;
  bVar12 = (bVar12 - cVar26) - (0xf7af < in_AX || CARRY2(in_AX + 0x850,(uint)bVar24)) |
           *(byte *)(iVar20 + -0x1f);
  iVar9 = CONCAT11(uVar13,bVar12);
  cVar26 = bVar12 == 0;
  piVar14 = unaff_BP + 1;
  unaff_BP[1] = 0x255a;
  FUN_1000_5f51();
  puVar15 = (undefined1 *)((int)piVar14 + -2);
  *(undefined2 *)((int)piVar14 + -2) = 0x255d;
  FUN_1000_75c3();
  uVar21 = 0x1203;
  piVar16 = (int *)(puVar15 + -2);
  *(undefined2 *)(puVar15 + -2) = 0x2563;
  uVar5 = FUN_1000_5c72();
  *(undefined2 *)((int)piVar16 + -2) = uVar5;
  *(undefined2 *)((int)piVar16 + -4) = unaff_CS;
  if (!(bool)cVar26) {
    puVar17 = (undefined1 *)((int)piVar16 + -6);
    *(undefined2 *)((int)piVar16 + -6) = 0x256a;
    FUN_1000_6bca();
    puVar18 = puVar17 + -2;
    *(undefined2 *)(puVar17 + -2) = 0x256d;
    bVar12 = func_0x00013abe();
    *(byte *)0x1203 = *(byte *)0x1203 & bVar12;
    iVar9 = CONCAT11((char)((uint)iVar9 >> 8),(byte)iVar9 | *(byte *)(iVar9 + 0x1d));
    piVar16 = (int *)(puVar18 + -2);
    *(undefined2 *)(puVar18 + -2) = 0x2579;
    uVar6 = func_0x00016bc7();
    unaff_DS = *piVar16;
    *piVar16 = iVar20;
    piVar16[-1] = iVar20;
    piVar16[-2] = unaff_CS;
    uVar21 = 0x1202;
    cVar26 = (char)((char)uVar6 + -0x61 + (uVar6 < 0x8304)) == '\0';
  }
  iVar8 = in_CX - 1;
  if (iVar8 == 0 || cVar26 != '\0') {
    puVar19 = (undefined1 *)((int)piVar16 + -6);
    *(undefined2 *)((int)piVar16 + -6) = 0x25bc;
    FUN_1000_435f();
    *(undefined2 *)(puVar19 + -2) = 0x25bf;
    func_0x00016bbf();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  XRELEASE();
  *(uint *)(iVar20 + -2) = uVar21;
  *(int *)(iVar20 + -4) = unaff_DI - iVar8;
  iVar9 = (iVar9 * 0x30 + iVar8) * 2;
  puVar22 = (uint *)(iVar9 + -0x2d82);
  uVar7 = CONCAT11(100,(char)*(undefined2 *)0x34ce);
  iVar8 = 0x60;
  uVar6 = *(uint *)(iVar20 + -2);
  uVar11 = *(uint *)(iVar20 + -4);
  if (-1 < (int)uVar11) {
    bVar25 = true;
    if (uVar6 < uVar11) {
      while( true ) {
        uVar10 = uVar6;
        *(int *)(uVar21 + 0x60) =
             (*(int *)(uVar21 + 0x60) - (int)((int)piVar16 + -4)) - (uint)bVar25;
        *puVar22 = uVar7;
        bVar25 = uVar21 < uVar10;
        uVar21 = uVar21 - uVar10;
        puVar23 = puVar22 + 1;
        if (bVar25) {
          uVar21 = uVar21 + *(int *)(iVar20 + -4);
          puVar23 = puVar22 + 0x31;
        }
        bVar25 = bVar25 && (uint *)0xff9f < puVar22 + 1;
        if (uVar11 - 1 == 0) break;
        puVar22 = puVar23 + 1;
        *puVar23 = uVar7;
        uVar6 = uVar11 - 1;
        uVar11 = uVar10;
      }
      iVar8 = *(int *)(iVar20 + -2) * 0x60;
      iVar9 = *(int *)(iVar20 + -4);
    }
    else {
      uVar21 = uVar6 >> 1;
      iVar9 = uVar6 + 1;
      do {
        *puVar22 = uVar7;
        puVar23 = puVar22 + 0x30;
        bVar25 = uVar21 < uVar11;
        uVar21 = uVar21 - uVar11;
        if (bVar25) {
          uVar21 = uVar21 + *(int *)(iVar20 + -2);
          puVar23 = puVar22 + 0x31;
        }
        iVar9 = iVar9 + -1;
        puVar22 = puVar23;
      } while (iVar9 != 0);
      *(char *)(uVar21 - 0x15) = *(char *)(uVar21 - 0x15) + '\x01';
      iVar9 = 0;
    }
    iVar9 = iVar9 + 1;
    do {
      *(uint *)(iVar8 + (int)puVar23) = uVar7;
      puVar2 = puVar23;
      puVar23 = puVar23 + 1;
      *puVar2 = uVar7;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    puVar22 = (uint *)*(undefined2 *)((int)piVar16 + -4);
    iVar9 = *(int *)(iVar20 + -4);
    iVar20 = *(int *)(iVar20 + -2) + 1;
    do {
      *puVar22 = uVar7;
      puVar22[iVar9] = uVar7;
      puVar22 = puVar22 + 0x30;
      iVar20 = iVar20 + -1;
    } while (iVar20 != 0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(uint *)(iVar20 + -4) = uVar11;
  do {
  } while ((uVar7 ^ 0x8f0) == 0);
  *(char *)(iVar20 + uVar21) =
       *(char *)(iVar20 + uVar21) + (char)(uVar7 ^ 0x8f0) + (puVar22 < (uint *)0x35);
  *(uint *)(iVar9 + -0x2db7) = uVar7 ^ 0x2b0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


