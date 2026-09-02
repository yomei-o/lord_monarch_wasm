/* 1000:a08e */

/* WARNING: Instruction at (ram,0x0001a05e) overlaps instruction at (ram,0x0001a05d)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void FUN_1000_a08e(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint *puVar3;
  uint uVar4;
  char cVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 in_CX;
  byte extraout_DL;
  int extraout_DX;
  undefined2 extraout_DX_00;
  byte extraout_DH;
  undefined1 uVar9;
  int iVar10;
  uint in_BX;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined2 *puVar21;
  byte *unaff_DI;
  uint *puVar22;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar23;
  byte bVar24;
  byte in_TF;
  byte in_IF;
  byte bVar25;
  bool bVar26;
  byte in_NT;
  
  bVar25 = 0;
  do {
    bVar24 = (byte)in_CX;
    iVar7 = FUN_1000_5abc();
    *(byte *)(in_BX + 0x6935) = *(byte *)(in_BX + 0x6935) & bVar24;
    cVar5 = (in_BX < *(uint *)(unaff_DI + 2)) + '^';
    *(undefined2 *)(iVar7 + -2) = CONCAT11(0x24,cVar5);
    bVar24 = cVar5 + *(char *)0x6935 ^ 0x50;
    *unaff_DI = bVar24;
    puVar22 = (uint *)(unaff_DI + (uint)bVar25 * -2 + 1 + (uint)bVar25 * -2 + 1);
    unaff_DI[(uint)bVar25 * -2 + 1] = bVar24;
    iVar11 = CONCAT11(0x24,bVar24 - 5);
    bVar24 = 1;
    puVar19 = (undefined1 *)(iVar7 + -4);
    *(undefined2 *)(iVar7 + -4) = 0xa0c8;
    FUN_1000_5cac();
    puVar20 = puVar19 + -2;
    *(undefined2 *)(puVar19 + -2) = 0xa0cb;
    FUN_1000_899f();
    bVar25 = (byte)(iVar11 + 1);
    uVar8 = CONCAT11((char)((uint)(iVar11 + 1) >> 8),bVar25 + 0xb5);
    in_CX = 0x40da;
    *(char *)0xc372 = *(char *)0xc372 + '@' + (0x4a < bVar25);
    puVar3 = puVar22;
    uVar4 = uVar8 - *puVar3;
    *(uint *)(puVar20 + -2) =
         (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar8,*puVar3) * 0x800 |
         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)uVar4 < 0) * 0x80 |
         (uint)(uVar4 == 0) * 0x40 | (uint)(bVar24 & 1) * 0x10 |
         (uint)((POPCOUNT(uVar4 & 0xff) & 1U) == 0) * 4 | (uint)(uVar8 < *puVar3);
    iVar7 = *(int *)(puVar20 + -2);
    puVar22[1] = CONCAT11(*(char *)((int)(puVar22 + 1) + iVar7 + 0x502b) + -0x4d,0xe8);
    unaff_DI = (byte *)((int)puVar22 + 5);
    *(undefined1 *)(puVar22 + 2) = 0xe8;
    *(undefined2 *)(puVar20 + -2) = unaff_CS;
    iVar11 = -0x6e18;
    *(undefined2 *)(puVar20 + -4) = 0x1ae0;
    *(byte *)(iVar7 + -0x2544) = *(byte *)(iVar7 + -0x2544) & extraout_DH;
    bVar25 = 1;
    puVar22[-0x3704] = puVar22[-0x3704] ^ (uint)unaff_DI;
    puVar12 = puVar20 + -6;
    *(undefined2 *)(puVar20 + -6) = 0xa024;
    func_0x00015aa0();
    *(undefined2 *)(puVar12 + -2) = 0xdab9;
    *(int *)(puVar12 + -4) = extraout_DX;
    *(undefined2 *)(puVar12 + -6) = 0xdab9;
    *(int *)0xdab9 = *(int *)0xdab9 - extraout_DX;
    iVar10 = CONCAT11((byte)((uint)iVar11 >> 8) ^ unaff_DI[iVar11 + 2],(char)iVar11);
    puVar13 = puVar12 + -8;
    *(undefined2 *)(puVar12 + -8) = 0xa036;
    func_0x0001b79b();
    pbVar1 = (byte *)(iVar7 + -0x2547);
    bVar26 = false;
    *pbVar1 = *pbVar1 ^ extraout_DL;
    bVar23 = (POPCOUNT(*pbVar1) & 1U) == 0;
    puVar14 = puVar13 + -2;
    *(undefined2 *)(puVar13 + -2) = 0xa03e;
    iVar11 = func_0x0001377a();
    puVar21 = (undefined2 *)0x31fd;
    if (bVar26) {
      if (!bVar23) goto code_r0x0001a060;
    }
    else {
      uVar9 = (undefined1)iVar10;
      bVar24 = (byte)((uint)iVar10 >> 8) ^ *(byte *)(iVar10 + 0x57a0);
      puVar15 = puVar14 + -2;
      *(undefined2 *)(puVar14 + -2) = 0xa04f;
      func_0x00015ade();
      puVar21 = (undefined2 *)0x3205;
      unaff_DI = (byte *)0x16a6;
      puVar16 = puVar15 + -2;
      *(undefined2 *)(puVar15 + -2) = 0xa058;
      func_0x00015ade();
      puVar17 = puVar16 + -2;
      *(undefined2 *)(puVar16 + -2) = 0xa05b;
      iVar11 = FUN_1000_34d8();
      puVar14 = puVar17 + -2;
      *(undefined2 *)(puVar17 + -2) = unaff_DS;
      iVar11 = iVar11 + 1;
      iVar10 = CONCAT11(bVar24 + *(char *)(iVar7 + 0x321a),uVar9);
code_r0x0001a060:
      *(int *)(puVar14 + -2) = iVar11;
      *unaff_DI = (byte)iVar11;
      unaff_DI[-1] = (byte)iVar11;
      puVar18 = puVar14 + -4;
      *(undefined2 *)(puVar14 + -4) = 0xa069;
      thunk_FUN_1000_3656();
      unaff_DI = *(byte **)(unaff_DI + -1 + iVar7 + 0x25);
      puVar2 = puVar21;
      puVar21 = puVar21 + -1;
      out(*puVar2,extraout_DX_00);
      *(undefined2 *)(puVar18 + -2) = 0xa070;
      uVar6 = FUN_1000_7258();
      out(0xb8,uVar6);
      *(char *)(iVar10 + (int)puVar21) = *(char *)(iVar10 + (int)puVar21) + -0x18;
    }
    *(char *)(iVar10 + (int)puVar21) = *(char *)(iVar10 + (int)puVar21) + '\x01';
    *(undefined2 *)0x46c5 = 0xa07f;
    FUN_1000_89cd();
    bVar24 = ((char)((uint)iVar10 >> 8) - *(char *)(iVar10 + (int)puVar21)) -
             (*(byte *)(iVar7 + 0x4802) < 0x42);
    in_BX = CONCAT11(bVar24 ^ *(byte *)(CONCAT11(bVar24,(char)iVar10) + 0x3f2e),(char)iVar10);
  } while( true );
}


