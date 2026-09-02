/* 1000:02ca */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000103a0) overlaps instruction at (ram,0x0001039f)
    */

ulong FUN_1000_02ca(void)

{
  byte *pbVar1;
  uint *puVar2;
  int *piVar3;
  byte in_AL;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  byte bVar9;
  int iVar7;
  uint uVar8;
  undefined2 in_CX;
  uint uVar10;
  byte extraout_DL;
  undefined2 uVar11;
  char cVar12;
  int in_BX;
  byte *pbVar13;
  undefined2 *puVar14;
  undefined2 *unaff_BP;
  undefined2 *puVar15;
  byte *unaff_SI;
  int *unaff_DI;
  int *piVar16;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar17;
  bool bVar18;
  ulong uVar19;
  undefined4 uVar20;
  char in_stack_00000000;
  int in_stack_000017b9;
  int in_stack_000017bb;
  undefined2 in_stack_000017bd;
  
  uVar10 = CONCAT11((char)((uint)in_CX >> 8),(byte)in_CX | *(byte *)(unaff_BP + -0x2345));
  pbVar1 = (byte *)(in_BX + (int)unaff_DI);
  bVar4 = *pbVar1;
  *pbVar1 = *pbVar1 + in_AL;
  if (CARRY1(bVar4,in_AL) || *pbVar1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pbVar13 = (byte *)0xc792;
  *(undefined2 *)0xc792 = 1;
  bVar17 = (char)(in_stack_00000000 + '\x14') == '\0';
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    piVar3 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    bVar17 = CONCAT11(100,in_stack_00000000 + '\x14') == *piVar3;
  } while (!bVar17);
  piVar16 = unaff_DI;
  if (bVar17) {
    piVar16 = unaff_DI + 0x16c0;
    *(undefined2 *)0xc794 =
         CONCAT11((char)(((uint)piVar16 >> 1) / 0x30),(char)(((uint)piVar16 >> 1) % 0x30));
    *(undefined2 *)0xc796 = piVar16;
    bVar17 = false;
    uVar10 = 0;
    *(undefined2 *)0xc792 = 0;
    *(undefined2 *)0xc7a0 = 5000;
    *(undefined2 *)0xc7a2 = 0;
    *(undefined2 *)0xc79e = 200;
    *(undefined1 *)0xc7a4 = 10;
    *(undefined1 *)0xc7a5 = 0;
    *(undefined1 *)0xc7a6 = 0x80;
    uVar5 = func_0x0001adac();
    if (!bVar17) {
      *(byte **)(pbVar13 + 6) = unaff_SI;
      *(undefined2 *)(unaff_SI + 2) = uVar5;
      *(int **)(unaff_SI + 4) = piVar16;
      *(undefined2 *)(unaff_SI + 8) = uVar5;
      *unaff_SI = 0;
      unaff_SI[1] = 6;
      unaff_DI[0x8ff] = (int)unaff_SI;
      unaff_SI[10] = 0x2d;
      unaff_SI[0xc] = extraout_DL;
      (unaff_SI + 6)[0] = 0xe8;
      (unaff_SI + 6)[1] = 3;
      uVar5 = func_0x0001adac();
      if (!bVar17) {
        uVar5 = CONCAT11((char)((uint)uVar5 >> 8) - pbVar13[(int)unaff_SI],
                         (char)uVar5 + '\x01' + pbVar13[(int)(unaff_DI + 0x16c1)]);
        puVar14 = (undefined2 *)&stack0xfff4;
        puVar15 = (undefined2 *)&stack0xfff4;
        cVar12 = '\x1d';
        do {
          unaff_BP = unaff_BP + -1;
          puVar14 = puVar14 + -1;
          *puVar14 = *unaff_BP;
          cVar12 = cVar12 + -1;
        } while ('\0' < cVar12);
        pbVar13 = (byte *)(in_stack_000017b9 + 0x16);
        uVar11 = CONCAT11((char)((uint)in_stack_000017bd >> 8),(char)in_stack_000017bd + '\x01');
        goto LAB_1000_0394;
      }
    }
  }
  *(uint *)(pbVar13 + (int)unaff_SI + 0x3a06) =
       *(uint *)(pbVar13 + (int)unaff_SI + 0x3a06) | (uint)unaff_SI;
  bVar17 = false;
  bVar18 = (unaff_BP[-0x17] & (uint)piVar16) == 0;
  puVar15 = unaff_BP;
  do {
    bVar4 = (byte)((uint)pbVar13 >> 8);
    if (!bVar18) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    piVar16[-0x16c1] = 0x6400;
    uVar19 = func_0x0001ad99();
    uVar11 = (undefined2)(uVar19 >> 0x10);
    uVar6 = (uint)uVar19;
    if (bVar17) {
      halt_baddata();
    }
    pbVar13 = (byte *)CONCAT11(bVar4,0x30);
    cVar12 = (char)(uVar6 / 0x30);
    bVar9 = (byte)(uVar6 % 0x30);
    iVar7 = CONCAT11(cVar12,bVar9);
    if ((uVar19 & 0xc10) == 0) {
LAB_1000_03ee:
      bVar4 = (char)piVar16[-0x16c1] - 8;
      uVar10 = CONCAT11((char)((uint)iVar7 >> 8),bVar4);
      if (3 < bVar4) goto LAB_1000_040a_1;
      uVar20 = func_0x0001ada4();
      uVar10 = (uint)uVar20;
      uVar11 = CONCAT11((char)((ulong)uVar20 >> 0x18) + '\x01',(char)((ulong)uVar20 >> 0x10));
code_r0x000103ff:
      cVar12 = (char)((uint)uVar11 >> 8) << 4;
      uVar11 = CONCAT11(cVar12,(char)uVar11);
      *(char *)((int)piVar16 + -0x2d81) = cVar12;
LAB_1000_040a_1:
      uVar6 = *(uint *)0x3bc2;
      uVar8 = uVar10;
      if (((uVar6 <= *(uint *)0xce70) && (uVar6 != 0)) &&
         (puVar2 = (uint *)((uVar6 - 1) * 0xc + -0x33fa), uVar8 = uVar10 + *puVar2,
         CARRY2(uVar10,*puVar2))) {
        uVar8 = 0xffff;
      }
      *(uint *)0x3bca = uVar8;
      *(undefined2 *)0x3bcc = 0;
      *(undefined2 *)0x3bec = 0;
      return CONCAT22(uVar11,uVar10);
    }
    if (POPCOUNT(uVar6 & 0x10) != '\0') {
      out(0xd0,bVar9);
      out(0xd0,bVar9);
      out(0xd0,bVar9);
      out(0x88,bVar9);
      pbVar1 = (byte *)((int)puVar15 + (int)unaff_SI);
      bVar9 = (byte)uVar10 & 0x1f;
      bVar4 = *pbVar1;
      *pbVar1 = (char)*pbVar1 >> bVar9;
      (pbVar13 + (int)unaff_SI)[-0x22] =
           (pbVar13 + (int)unaff_SI)[-0x22] + cVar12 +
           ((uVar10 & 0x1f) != 0) * (((char)bVar4 >> bVar9 - 1 & 1U) != 0);
      uVar10 = 0xc80;
      goto LAB_1000_040a_1;
    }
    uVar11 = CONCAT11((byte)(uVar19 >> 0x18) | bVar9,(char)(uVar19 >> 0x10));
    bVar9 = (byte)uVar10 | *pbVar13;
    if ('\0' < (char)bVar9) {
      uVar10 = iVar7 + *(int *)unaff_SI | 0xe8;
      piVar16 = piVar16 + 1;
      goto code_r0x000103ff;
    }
    *unaff_SI = *unaff_SI & bVar4;
    unaff_SI[0xb] = 0xff;
    uVar5 = CONCAT11(cVar12,6);
    piVar16 = piVar16 + 1;
    in_stack_000017bb = CONCAT11((char)(uVar10 >> 8),bVar9) + -1;
    if (in_stack_000017bb == 0) {
      iVar7 = 0;
      *(undefined1 *)0xc7fc = 0;
      *(undefined1 *)0xc7fd = 0;
      *(undefined2 *)0xc7f8 = 0;
      *(undefined2 *)0xc7fa = 0;
      *(undefined1 *)0xc7fe = 0x80;
      *(byte *)(puVar15 + -0x1c37) = *(byte *)(puVar15 + -0x1c37) & bVar4;
      goto LAB_1000_03ee;
    }
LAB_1000_0394:
    if (in_stack_000017bb != 1) {
      return CONCAT22(uVar11,uVar5) | 0x58;
    }
    piVar16 = (int *)0x0;
    uVar10 = 0x900;
    bVar17 = 6 < *(byte *)0xd27e;
    bVar18 = *(byte *)0xd27e == 6;
  } while( true );
}


