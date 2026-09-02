/* 1000:1cc3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011d9f) overlaps instruction at (ram,0x00011d9e)
    */
/* WARNING: Removing unreachable block (ram,0x00011ccf) */

void FUN_1000_1cc3(undefined1 param_1)

{
  byte *pbVar1;
  uint *puVar2;
  byte extraout_AL;
  char in_AL;
  byte bVar3;
  byte bVar4;
  byte extraout_AL_00;
  char cVar5;
  byte extraout_AH;
  byte extraout_AH_00;
  int iVar6;
  uint in_CX;
  undefined1 extraout_DL;
  uint in_DX;
  char extraout_DH;
  byte bVar7;
  byte *in_BX;
  int iVar8;
  uint unaff_BP;
  uint *unaff_SI;
  byte *pbVar9;
  byte *unaff_DI;
  uint uVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  char cVar11;
  byte bVar12;
  byte bVar13;
  char cVar14;
  byte in_AF;
  undefined1 uVar15;
  undefined4 uVar16;
  undefined1 in_stack_00000000;
  undefined1 in_stack_00000001;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 in_stack_0000fff1;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined2 in_stack_0000fff5;
  undefined1 uStack_3;
  undefined1 uStack_2;
  char cStack_1;
  
  cVar5 = cStack_1;
  uVar15 = uStack_2;
  cVar11 = (char)(in_CX >> 8);
  bVar3 = in_AL - cVar11;
  (in_BX + (int)unaff_SI)[-0x4c] = (in_BX + (int)unaff_SI)[-0x4c] + 1;
  iVar8 = (unaff_BP & 3) - (bVar3 & 3);
  uStack_2 = SUB21(unaff_SI,0);
  cStack_1 = (char)((uint)unaff_SI >> 8);
  if ((byte)(bVar3 + (0 < iVar8) * (char)iVar8) == '*') {
    uVar10 = (uint)unaff_DI | *(uint *)(in_BX + (int)unaff_DI);
    cVar14 = (byte)in_CX < *(byte *)0x200a;
    cVar5 = (byte)in_CX - *(byte *)0x200a;
    in_CX = CONCAT11(cVar11,cVar5);
    if (cVar5 == '\0') {
code_r0x00011d1e:
      pbVar1 = (byte *)((int)unaff_SI + (unaff_BP - 0x18));
      *(int *)pbVar1 = *(int *)pbVar1 + -0x4b;
      bVar12 = (byte)((uint)in_BX >> 8) < *(byte *)(unaff_BP + uVar10 + 0x1093);
      uStack_3 = 0x1d;
      FUN_1000_56d9();
      uStack_2 = 0x32;
      cStack_1 = 0x1d;
      FUN_1000_44c0();
      bVar4 = FUN_1000_9eb2();
      pbVar1 = (byte *)0x1093;
      bVar3 = *pbVar1;
      bVar13 = *pbVar1;
      *pbVar1 = bVar13 + bVar4 + bVar12;
      *(uint *)(in_BX + 0x1093) =
           *(int *)(in_BX + 0x1093) + -0x6c96 +
           (uint)(CARRY1(bVar3,bVar4) || CARRY1(bVar13 + bVar4,bVar12));
      *(char *)(unaff_BP + 0x1093) = *(char *)(unaff_BP + 0x1093) + extraout_DH;
      in(0x3c);
      FUN_1000_779e();
      FUN_1000_576c();
      FUN_1000_56d7();
      bVar3 = FUN_1000_4550();
      pbVar9 = (byte *)0x10a7;
      unaff_DI = (byte *)0x3bd2;
      bVar13 = bVar3 < 7;
      if (bVar3 != 7) {
        pbVar9 = (byte *)0x109b;
        unaff_DI = (byte *)0x3bd0;
      }
      in_BX = pbVar9;
      FUN_1000_56d7();
      FUN_1000_44be();
      uVar16 = func_0x0001ddb0();
      pbVar1 = pbVar9;
      bVar4 = *pbVar1;
      bVar7 = (byte)((ulong)uVar16 >> 0x18);
      bVar12 = *pbVar1 + bVar7;
      *pbVar1 = bVar12 + bVar13;
      if (*pbVar1 != 0) goto code_r0x00011da0;
      unaff_SI = (uint *)CONCAT11(uStack_2,uStack_3);
      bVar3 = (byte)uVar16;
      if (CARRY1(bVar4,bVar7) || CARRY1(bVar12,bVar13)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      bVar13 = 1;
      if (*(byte *)0x3bf4 != 1) {
        bVar13 = *(byte *)0x3bf4 | 0x10;
      }
LAB_1000_1d86:
      *(byte *)(unaff_SI + 5) = bVar13 | bVar3 >> 2 | bVar3 << 6;
      uStack_2 = (undefined1)((uint)in_BX >> 8);
      *(int *)0x5489 = (int)(in_BX + *(int *)0x5489);
      goto code_r0x00011d93;
    }
    uStack_2 = (undefined1)unaff_DS;
    cStack_1 = (char)((uint)unaff_DS >> 8);
    unaff_SI[4] = in_DX;
    *(byte *)((int)unaff_SI + 0xb) = 0xff;
    uVar15 = false;
  }
  else {
    iVar8 = unaff_BP + in_CX;
    cVar11 = 0;
    cStack_1 = cVar5;
    if ((*unaff_SI & 2) == 0) {
      *(undefined2 *)0x3ea6 = unaff_SI;
      pbVar9 = (byte *)(CONCAT22(0x1c48,in_stack_0000fff5) >> 8);
      uStack_2 = uVar15;
      func_0x0001b849();
      func_0x0001b961();
      uVar15 = 0x51;
                    /* WARNING: Call to offcut address within same function */
      func_0x00011e09();
      bVar13 = extraout_AL;
      bVar3 = extraout_AH;
      if (!(bool)cVar11) {
        unaff_SS = CONCAT11(param_1,in_stack_00000001);
        *unaff_DI = extraout_AL;
        unaff_DI[1] = extraout_AL;
        *(undefined2 *)0x3ea4 = CONCAT11(in_stack_00000000,cStack_1);
        cStack_1 = 0x62;
        in_BX = pbVar9;
        func_0x0001b84a();
        cVar5 = func_0x0001b8b0();
        *(byte *)unaff_SI = (byte)*unaff_SI + cVar5 + cVar11;
        uVar10 = CONCAT11(uStack_11,uStack_12);
        unaff_SI = (uint *)CONCAT11(in_stack_0000fff1,uStack_10);
        unaff_BP = CONCAT11(uStack_d,uStack_e);
        in_CX = CONCAT11(uVar15,0x1c);
        *(uint **)(byte *)((int)unaff_SI + unaff_BP + 3) = unaff_SI;
        goto code_r0x00011d1e;
      }
    }
    else {
      func_0x00016d9e();
      func_0x0001c3c9();
      *(int *)(in_BX + 10) = *(int *)(in_BX + 10) + 0x55;
      bVar13 = extraout_AL_00;
      bVar3 = extraout_AH_00;
    }
    if ((bVar13 & 0x40) != 0) {
      *unaff_DI = bVar13;
      cVar5 = (char)unaff_DI + '\x02';
      unaff_DI[1] = bVar13;
      cVar11 = (char)in_BX + cVar5;
      uStack_3 = 99;
      uStack_2 = 0x1e;
      iVar6 = func_0x000146ae();
      cStack_1 = (char)iVar6;
      if (cStack_1 != '\0') {
        uStack_3 = 0x6e;
        uStack_2 = 0x1e;
        func_0x000107d7();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      uStack_3 = (undefined1)in_CX;
      uStack_2 = (undefined1)(in_CX >> 8);
      uVar16 = CONCAT22(&stack0x0001,iVar8);
      *(int *)0xc55e = iVar6;
      *(int *)0x3bce = iVar6;
      iVar6 = iVar6 + -1;
      *(int *)0x34c8 = iVar6;
      *(undefined1 *)0x328a = (char)iVar6;
      *(int *)0x3296 = iVar6;
      *(int *)0x3298 = iVar6;
      *(int *)0x329a = iVar6;
      *(undefined2 *)0x3bc2 = 0x95;
      cVar14 = '8';
      uVar15 = extraout_DL;
      func_0x0001fd7c(*(undefined2 *)(unaff_DI + 0x19),0x34);
      *(undefined2 *)0x3bc4 = 10;
      FUN_1000_5b9e();
      cVar5 = FUN_1000_077d(cVar5);
      if ((char)(cVar5 + cVar14) != '\0') {
        func_0x0001c0a4();
        FUN_1000_079b(uVar16,cVar11,uVar15);
        FUN_1000_5838();
        FUN_1000_91d1();
        FUN_1000_4f92();
        FUN_1000_6d2a();
        uStack_3 = 0xcf;
        uStack_2 = 0x1e;
        FUN_1000_5838();
        cStack_1 = -0x2e;
        FUN_1000_4f92();
        FUN_1000_6d2a();
        func_0x0001fd2c();
        func_0x0001fd1a();
        func_0x0001fd46();
        puVar2 = unaff_SI;
        *puVar2 = *puVar2 - (int)unaff_SI;
        if (*puVar2 == 0) {
          func_0x0001fd71();
        }
        func_0x00015002();
        func_0x00015059();
        func_0x00014fb0();
        FUN_1000_774c();
        FUN_1000_774c();
      }
      func_0x0001c0c0();
      func_0x00012d1d();
      return;
    }
    puVar2 = (uint *)(in_BX + 4);
    uVar10 = *puVar2;
    *puVar2 = *puVar2 - 0x61;
    if (uVar10 < 0x61 && *puVar2 != 0) goto LAB_1000_1d86;
    pbVar9 = unaff_DI + 2;
    unaff_DI[1] = bVar13;
    unaff_DI = unaff_DI + 3;
    *pbVar9 = bVar13;
    bVar4 = unaff_DI[iVar8 + 0x447];
    if (-1 < (char)(bVar13 + 0x5d)) {
      *unaff_SI = (uint)(byte)(bVar4 + (9 < (bVar4 & 0xf) | in_AF) * '\x06' +
                              (0x99 < bVar4 || 0xa2 < bVar13) * '`') * (uint)bVar3 >> 8;
      return;
    }
    uStack_2 = (undefined1)((uint)&uStack_3 >> 8);
code_r0x00011d93:
    cVar14 = false;
    uVar15 = unaff_DI == (byte *)0x0;
  }
  uStack_3 = 0x1d;
  func_0x0001b28d();
  uStack_2 = 0x9e;
  cStack_1 = 0x1d;
  uVar16 = func_0x0001bbbe();
  if ((bool)uVar15) {
    in_BX[(int)unaff_SI] = (in_BX[(int)unaff_SI] - *(char *)0x3689) - cVar14;
    *(uint *)(in_BX + (int)unaff_SI) = *(uint *)(in_BX + (int)unaff_SI) ^ in_CX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
code_r0x00011da0:
  out((int)((ulong)uVar16 >> 0x10),(int)uVar16);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


