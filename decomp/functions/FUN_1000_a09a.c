/* 1000:a09a */

/* WARNING: Instruction at (ram,0x0001a05e) overlaps instruction at (ram,0x0001a05d)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

void FUN_1000_a09a(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint *puVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  undefined2 uVar7;
  int in_AX;
  int iVar8;
  uint uVar9;
  byte extraout_DL;
  int extraout_DX;
  undefined2 extraout_DX_00;
  byte extraout_DH;
  undefined1 uVar10;
  int iVar11;
  uint in_BX;
  int iVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined2 *puVar23;
  char *unaff_SI;
  byte *unaff_DI;
  uint *puVar24;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar25;
  byte bVar26;
  byte in_TF;
  byte in_IF;
  byte bVar27;
  bool bVar28;
  byte in_NT;
  
  bVar27 = 0;
  do {
    cVar5 = (in_BX < *(uint *)(unaff_DI + 2)) + '^';
    *(undefined2 *)(in_AX + -2) = CONCAT11(0x24,cVar5);
    bVar6 = cVar5 + *unaff_SI ^ 0x50;
    *unaff_DI = bVar6;
    puVar24 = (uint *)(unaff_DI + (uint)bVar27 * -2 + 1 + (uint)bVar27 * -2 + 1);
    unaff_DI[(uint)bVar27 * -2 + 1] = bVar6;
    iVar8 = CONCAT11(0x24,bVar6 - 5);
    bVar26 = 1;
    puVar21 = (undefined1 *)(in_AX + -4);
    *(undefined2 *)(in_AX + -4) = 0xa0c8;
    FUN_1000_5cac();
    puVar22 = puVar21 + -2;
    *(undefined2 *)(puVar21 + -2) = 0xa0cb;
    FUN_1000_899f();
    bVar27 = (byte)(iVar8 + 1);
    uVar9 = CONCAT11((char)((uint)(iVar8 + 1) >> 8),bVar27 + 0xb5);
    bVar6 = 0xda;
    *(char *)0xc372 = *(char *)0xc372 + '@' + (0x4a < bVar27);
    puVar3 = puVar24;
    uVar4 = uVar9 - *puVar3;
    *(uint *)(puVar22 + -2) =
         (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar9,*puVar3) * 0x800 |
         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)uVar4 < 0) * 0x80 |
         (uint)(uVar4 == 0) * 0x40 | (uint)(bVar26 & 1) * 0x10 |
         (uint)((POPCOUNT(uVar4 & 0xff) & 1U) == 0) * 4 | (uint)(uVar9 < *puVar3);
    iVar8 = *(int *)(puVar22 + -2);
    puVar24[1] = CONCAT11(*(char *)((int)(puVar24 + 1) + iVar8 + 0x502b) + -0x4d,0xe8);
    unaff_DI = (byte *)((int)puVar24 + 5);
    *(undefined1 *)(puVar24 + 2) = 0xe8;
    *(undefined2 *)(puVar22 + -2) = unaff_CS;
    iVar12 = -0x6e18;
    *(undefined2 *)(puVar22 + -4) = 0x1ae0;
    *(byte *)(iVar8 + -0x2544) = *(byte *)(iVar8 + -0x2544) & extraout_DH;
    bVar27 = 1;
    puVar24[-0x3704] = puVar24[-0x3704] ^ (uint)unaff_DI;
    puVar13 = puVar22 + -6;
    *(undefined2 *)(puVar22 + -6) = 0xa024;
    func_0x00015aa0();
    *(undefined2 *)(puVar13 + -2) = 0xdab9;
    *(int *)(puVar13 + -4) = extraout_DX;
    *(undefined2 *)(puVar13 + -6) = 0xdab9;
    *(int *)0xdab9 = *(int *)0xdab9 - extraout_DX;
    iVar11 = CONCAT11((byte)((uint)iVar12 >> 8) ^ unaff_DI[iVar12 + 2],(char)iVar12);
    puVar14 = puVar13 + -8;
    *(undefined2 *)(puVar13 + -8) = 0xa036;
    func_0x0001b79b();
    pbVar1 = (byte *)(iVar8 + -0x2547);
    bVar28 = false;
    *pbVar1 = *pbVar1 ^ extraout_DL;
    bVar25 = (POPCOUNT(*pbVar1) & 1U) == 0;
    puVar15 = puVar14 + -2;
    *(undefined2 *)(puVar14 + -2) = 0xa03e;
    iVar12 = func_0x0001377a();
    puVar23 = (undefined2 *)0x31fd;
    if (bVar28) {
      if (!bVar25) goto code_r0x0001a060;
    }
    else {
      uVar10 = (undefined1)iVar11;
      bVar26 = (byte)((uint)iVar11 >> 8) ^ *(byte *)(iVar11 + 0x57a0);
      puVar16 = puVar15 + -2;
      *(undefined2 *)(puVar15 + -2) = 0xa04f;
      func_0x00015ade();
      puVar23 = (undefined2 *)0x3205;
      unaff_DI = (byte *)0x16a6;
      puVar17 = puVar16 + -2;
      *(undefined2 *)(puVar16 + -2) = 0xa058;
      func_0x00015ade();
      puVar18 = puVar17 + -2;
      *(undefined2 *)(puVar17 + -2) = 0xa05b;
      iVar12 = FUN_1000_34d8();
      puVar15 = puVar18 + -2;
      *(undefined2 *)(puVar18 + -2) = unaff_DS;
      iVar12 = iVar12 + 1;
      iVar11 = CONCAT11(bVar26 + *(char *)(iVar8 + 0x321a),uVar10);
code_r0x0001a060:
      *(int *)(puVar15 + -2) = iVar12;
      *unaff_DI = (byte)iVar12;
      unaff_DI[-1] = (byte)iVar12;
      puVar19 = puVar15 + -4;
      *(undefined2 *)(puVar15 + -4) = 0xa069;
      thunk_FUN_1000_3656();
      unaff_DI = *(byte **)(unaff_DI + -1 + iVar8 + 0x25);
      puVar2 = puVar23;
      puVar23 = puVar23 + -1;
      out(*puVar2,extraout_DX_00);
      *(undefined2 *)(puVar19 + -2) = 0xa070;
      uVar7 = FUN_1000_7258();
      out(0xb8,uVar7);
      *(char *)(iVar11 + (int)puVar23) = *(char *)(iVar11 + (int)puVar23) + -0x18;
    }
    *(char *)(iVar11 + (int)puVar23) = *(char *)(iVar11 + (int)puVar23) + '\x01';
    puVar20 = (undefined1 *)0x46c5;
    *(undefined2 *)0x46c5 = 0xa07f;
    uVar7 = FUN_1000_89cd();
    bVar26 = *(byte *)(iVar8 + 0x4802);
    *(undefined2 *)(puVar20 + -2) = uVar7;
    bVar26 = ((char)((uint)iVar11 >> 8) - *(char *)(iVar11 + (int)puVar23)) - (bVar26 < 0x42);
    in_BX = CONCAT11(bVar26 ^ *(byte *)(CONCAT11(bVar26,(char)iVar11) + 0x3f2e),(char)iVar11);
    *(undefined2 *)(puVar20 + -4) = 0xa091;
    in_AX = FUN_1000_5abc();
    unaff_SI = (char *)0x6935;
    *(byte *)(in_BX + 0x6935) = *(byte *)(in_BX + 0x6935) & bVar6;
  } while( true );
}


