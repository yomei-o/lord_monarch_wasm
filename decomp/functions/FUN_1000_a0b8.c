/* 1000:a0b8 */

/* WARNING: Instruction at (ram,0x0001a05e) overlaps instruction at (ram,0x0001a05d)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void FUN_1000_a0b8(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint *puVar3;
  undefined2 uVar4;
  int in_AX;
  uint uVar5;
  byte bVar6;
  byte extraout_DL;
  int extraout_DX;
  undefined2 extraout_DX_00;
  byte extraout_DH;
  undefined1 uVar7;
  int iVar8;
  byte bVar10;
  int iVar9;
  undefined1 *puVar11;
  undefined2 *puVar12;
  byte *pbVar13;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar14;
  byte bVar15;
  byte in_TF;
  byte in_IF;
  bool bVar16;
  byte in_NT;
  uint uVar17;
  
  do {
    bVar15 = 1;
    FUN_1000_5cac();
    FUN_1000_899f();
    bVar10 = (byte)(in_AX + 1);
    uVar5 = CONCAT11((char)((uint)(in_AX + 1) >> 8),bVar10 + 0xb5);
    bVar6 = 0xda;
    *(char *)0xc372 = *(char *)0xc372 + '@' + (0x4a < bVar10);
    puVar3 = unaff_DI;
    uVar17 = uVar5 - *puVar3;
    uVar17 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar5,*puVar3) * 0x800 |
             (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)uVar17 < 0) * 0x80
             | (uint)(uVar17 == 0) * 0x40 | (uint)(bVar15 & 1) * 0x10 |
             (uint)((POPCOUNT(uVar17 & 0xff) & 1U) == 0) * 4 | (uint)(uVar5 < *puVar3);
    unaff_DI[1] = CONCAT11(*(char *)((int)(unaff_DI + 1) + uVar17 + 0x502b) + -0x4d,0xe8);
    pbVar13 = (byte *)((int)unaff_DI + 5);
    *(undefined1 *)(unaff_DI + 2) = 0xe8;
    iVar9 = -0x6e18;
    *(byte *)(uVar17 + 0xdabc) = *(byte *)(uVar17 + 0xdabc) & extraout_DH;
    unaff_DI[-0x3704] = unaff_DI[-0x3704] ^ (uint)pbVar13;
    func_0x00015aa0();
    *(int *)0xdab9 = *(int *)0xdab9 - extraout_DX;
    iVar8 = CONCAT11((byte)((uint)iVar9 >> 8) ^ pbVar13[iVar9 + 2],(char)iVar9);
    func_0x0001b79b(0xdab9,extraout_DX);
    pbVar1 = (byte *)(uVar17 + 0xdab9);
    bVar16 = false;
    *pbVar1 = *pbVar1 ^ extraout_DL;
    bVar14 = (POPCOUNT(*pbVar1) & 1U) == 0;
    iVar9 = func_0x0001377a();
    puVar12 = (undefined2 *)0x31fd;
    if (bVar16) {
      if (!bVar14) goto code_r0x0001a060;
    }
    else {
      uVar7 = (undefined1)iVar8;
      bVar10 = (byte)((uint)iVar8 >> 8) ^ *(byte *)(iVar8 + 0x57a0);
      func_0x00015ade();
      puVar12 = (undefined2 *)0x3205;
      pbVar13 = (byte *)0x16a6;
      func_0x00015ade();
      iVar9 = FUN_1000_34d8();
      iVar9 = iVar9 + 1;
      iVar8 = CONCAT11(bVar10 + *(char *)(uVar17 + 0x321a),uVar7);
code_r0x0001a060:
      *pbVar13 = (byte)iVar9;
      pbVar13[-1] = (byte)iVar9;
      thunk_FUN_1000_3656(iVar9);
      pbVar13 = *(byte **)(pbVar13 + -1 + uVar17 + 0x25);
      puVar2 = puVar12;
      puVar12 = puVar12 + -1;
      out(*puVar2,extraout_DX_00);
      uVar4 = FUN_1000_7258();
      out(0xb8,uVar4);
      *(char *)(iVar8 + (int)puVar12) = *(char *)(iVar8 + (int)puVar12) + -0x18;
    }
    *(char *)(iVar8 + (int)puVar12) = *(char *)(iVar8 + (int)puVar12) + '\x01';
    puVar11 = (undefined1 *)0x46c5;
    *(undefined2 *)0x46c5 = 0xa07f;
    uVar4 = FUN_1000_89cd();
    bVar10 = *(byte *)(uVar17 + 0x4802);
    *(undefined2 *)(puVar11 + -2) = uVar4;
    bVar10 = ((char)((uint)iVar8 >> 8) - *(char *)(iVar8 + (int)puVar12)) - (bVar10 < 0x42);
    uVar17 = CONCAT11(bVar10 ^ *(byte *)(CONCAT11(bVar10,(char)iVar8) + 0x3f2e),(char)iVar8);
    *(undefined2 *)(puVar11 + -4) = 0xa091;
    FUN_1000_5abc();
    *(byte *)(uVar17 + 0x6935) = *(byte *)(uVar17 + 0x6935) & bVar6;
    bVar10 = (uVar17 < *(uint *)(pbVar13 + 2)) + '^' + *(char *)0x6935 ^ 0x50;
    *pbVar13 = bVar10;
    unaff_DI = (uint *)(pbVar13 + -2);
    pbVar13[-1] = bVar10;
    in_AX = CONCAT11(0x24,bVar10 - 5);
  } while( true );
}


