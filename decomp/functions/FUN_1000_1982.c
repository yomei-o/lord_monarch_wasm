/* 1000:1982 */

/* WARNING: Instruction at (ram,0x00018e55) overlaps instruction at (ram,0x00018e53)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00011b01) */
/* WARNING: Removing unreachable block (ram,0x00011b1c) */

long FUN_1000_1982(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  int *piVar1;
  char *pcVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 extraout_AL;
  byte bVar10;
  byte bVar11;
  char cVar12;
  uint uVar13;
  undefined2 in_AX;
  char extraout_AH;
  int iVar14;
  undefined2 uVar15;
  int iVar16;
  undefined1 uVar17;
  char cVar18;
  undefined1 uVar19;
  int in_CX;
  byte bVar20;
  uint in_DX;
  byte extraout_DH;
  undefined2 extraout_DX;
  uint in_BX;
  undefined2 *puVar21;
  undefined2 *unaff_BP;
  undefined2 *unaff_SI;
  undefined1 *puVar22;
  undefined2 *unaff_DI;
  undefined1 *puVar23;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  byte bVar24;
  undefined1 uVar25;
  bool bVar26;
  bool bVar27;
  long lVar28;
  undefined4 uVar29;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  byte bStack_4;
  undefined1 uStack_3;
  undefined2 uStack_2;
  
  while( true ) {
    uStack_2._0_1_ = (undefined1)in_AX;
    uStack_2._1_1_ = (undefined1)((uint)in_AX >> 8);
    bStack_4 = (byte)in_CX;
    uStack_3 = (undefined1)((uint)in_CX >> 8);
    uStack_6 = (undefined1)in_DX;
    uStack_5 = (undefined1)(in_DX >> 8);
    uStack_8 = (undefined1)in_BX;
    uStack_7 = (undefined1)(in_BX >> 8);
    uStack_c = SUB21(unaff_BP,0);
    uStack_b = (undefined1)((uint)unaff_BP >> 8);
    uStack_e = SUB21(unaff_SI,0);
    uStack_d = (undefined1)((uint)unaff_SI >> 8);
    uStack_10 = SUB21(unaff_DI,0);
    uStack_f = (undefined1)((uint)unaff_DI >> 8);
    uStack_11 = 0x19;
    uStack_a = (undefined1 *)register0x00000010;
    FUN_1000_6217();
    uVar9 = extraout_AL;
    cVar18 = extraout_AH;
    if ((bool)in_CF) {
      while( true ) {
        cVar18 = -cVar18;
        *(char *)(in_BX + 0x3e20) = cVar18;
        in_CX = in_CX + -1;
        if (in_CX == 0) break;
        uVar9 = *(undefined1 *)(in_BX + 0xa6bb);
        in_BX = in_BX + 1;
      }
      return CONCAT22(0x5ca6,CONCAT11(cVar18,uVar9));
    }
    lVar28 = (ulong)CONCAT21((uint)extraout_DH << 8,extraout_AH) << 8;
    cVar18 = *(char *)0x107d;
    bVar27 = SBORROW1(cVar18,'\x01');
    bVar26 = (char)(cVar18 + -1) < '\0';
    uVar13 = in_BX;
    if (cVar18 != '\x01') {
      uStack_2._0_1_ = 0x9b;
      uStack_2._1_1_ = 0x19;
      FUN_1000_619e();
      FUN_1000_7810();
      FUN_1000_45bf();
      unaff_SI = (undefined2 *)0x1079;
      unaff_DI = (undefined2 *)0x3bf0;
      FUN_1000_452d();
      param_3 = CONCAT22(param_3._2_2_,0x19b0);
      FUN_1000_6e1f();
      param_3 = CONCAT22(0x19b3,(undefined2)param_3);
      bVar10 = FUN_1000_2f10();
      *(byte *)((int)unaff_BP + 0x1079) = *(byte *)((int)unaff_BP + 0x1079) & bVar10;
      piVar1 = unaff_BP + 0x1df8;
      unaff_BP = (undefined2 *)(undefined2 *)((long)*piVar1 * -0x18);
      bVar26 = (undefined2 *)(long)(int)unaff_BP != (undefined2 *)((long)*piVar1 * -0x18);
      param_3 = CONCAT22(0x19c3,(undefined2)param_3);
      lVar28 = FUN_1000_4754();
      if (bVar26) {
        bVar24 = (byte)lVar28 < 0xb2;
        out((int)((ulong)lVar28 >> 0x10),(byte)lVar28 + 0x4e);
        bVar20 = (byte)(in_BX >> 8);
        func_0x0001fe31();
        func_0x0001fe49();
        cVar12 = func_0x0001fdcc();
        pbVar3 = (byte *)0xf95b;
        bVar10 = *pbVar3;
        bVar11 = *pbVar3;
        *pbVar3 = bVar11 + bVar20 + bVar24;
        puVar21 = (undefined2 *)((int)&param_3 + 1);
        param_3._0_3_ = CONCAT21(unaff_BP,(undefined1)param_3);
        cVar18 = '\x1d';
        do {
          unaff_BP = unaff_BP + -1;
          puVar21 = puVar21 + -1;
          *puVar21 = *unaff_BP;
          cVar18 = cVar18 + -1;
        } while ('\0' < cVar18);
        LOCK();
        *(char *)0x1079 =
             *(char *)0x1079 + cVar12 + (CARRY1(bVar10,bVar20) || CARRY1(bVar11 + bVar20,bVar24));
        UNLOCK();
        pcVar7 = (code *)swi(3);
        lVar28 = (*pcVar7)();
        return lVar28;
      }
      bVar27 = false;
      bVar26 = *(int *)0x3e96 < 0;
      uVar13 = in_BX;
      if (*(int *)0x3e96 != 0) {
        return lVar28;
      }
    }
    in_DX = (uint)((ulong)lVar28 >> 0x10);
    bVar10 = (byte)in_CX;
    uVar9 = (undefined1)((uint)in_CX >> 8);
    in_BX = uVar13;
    if ((bVar27 == bVar26) || (in_BX = uVar13 * 2, *(int *)(in_BX + 0xc562) != 0)) break;
    bVar11 = (byte)lVar28;
    bVar26 = (byte)(bVar11 + 0xe) < 0x8f || (byte)(bVar11 + 0x7f) < (0xf2 < bVar11);
    puVar5 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    in_AX = *puVar5;
    bVar11 = bVar10 + *(byte *)(unaff_DI + uVar13 + 0xe186);
    in_CF = CARRY1(bVar10,*(byte *)(unaff_DI + uVar13 + 0xe186)) || CARRY1(bVar11,bVar26);
    in_CX = CONCAT11(uVar9,bVar11 + bVar26);
  }
  iVar14 = (int)lVar28 + 100;
  *(int *)0x3bc2 = iVar14;
  if (*(int *)0x3bc6 != 5) {
    uStack_2._0_1_ = 0xf4;
    uStack_2._1_1_ = 0x19;
    uVar15 = FUN_1000_0834();
    out(0x7fdf,0x93);
    pcVar2 = (char *)((int)unaff_SI + in_BX + 0xee92);
    *pcVar2 = *pcVar2 + (byte)in_BX + CARRY1((byte)uVar15,(byte)in_BX);
    out(0x7fdd,0);
    out(0xbfdb,1);
    uVar9 = in(10);
    uVar13 = CONCAT11((char)((uint)uVar15 >> 8),uVar9) & 0xffdf;
    out(10,(char)uVar13);
    return CONCAT22(0xbfdb,uVar13);
  }
  uStack_2._1_1_ = (undefined1)((uint)iVar14 >> 8);
  uStack_6 = (undefined1)((ulong)lVar28 >> 0x10);
  uStack_5 = (undefined1)((ulong)lVar28 >> 0x18);
  uStack_8 = (undefined1)in_BX;
  uStack_7 = (undefined1)(in_BX >> 8);
  uStack_c = SUB21(unaff_BP,0);
  uVar8 = uStack_c;
  uStack_b = (undefined1)((uint)unaff_BP >> 8);
  uStack_e = SUB21(unaff_SI,0);
  uStack_d = (undefined1)((uint)unaff_SI >> 8);
  uStack_10 = SUB21(unaff_DI,0);
  uStack_f = (undefined1)((uint)unaff_DI >> 8);
  cVar18 = -CARRY2(in_DX,*(uint *)((int)unaff_BP + (int)unaff_SI));
  iVar16 = CONCAT11(uStack_2._1_1_,cVar18);
  puVar22 = (undefined1 *)*(uint *)((int)unaff_BP + (int)unaff_DI + -0x3ad4);
  *(int *)0x32bf = iVar16;
  uStack_11 = 0;
  *(char *)((int)unaff_BP + 0x7241) =
       (*(char *)((int)unaff_BP + 0x7241) - (cVar18 + -1)) - (&uStack_10 < puVar22);
  iVar16 = iVar16 + 0x6e7;
  cVar18 = (char)iVar16;
  out(0xeb,cVar18);
  uVar17 = (undefined1)((uint)iVar16 >> 8);
  out(0x5d,CONCAT11(uVar17,cVar18 + '\x18'));
  uVar15 = *(undefined2 *)(in_BX + (int)unaff_SI);
  bVar11 = cVar18 + 0xa8;
  iVar16 = in_CX - *(int *)((int)unaff_BP + (int)unaff_DI + -0x7fc0);
  bVar20 = (byte)((uint)iVar16 >> 8);
  uVar25 = bVar20 < bVar11;
  uVar19 = (undefined1)iVar16;
  cVar18 = bVar20 - bVar11;
  uVar13 = CONCAT11(cVar18,uVar19);
  bStack_4 = bVar10;
  uStack_3 = uVar9;
  uStack_2 = iVar14;
  if (!SBORROW1(bVar20,bVar11)) {
    uStack_a = (undefined1 *)register0x00000010;
    uVar15 = FUN_1000_6e0c();
    out(0x30,uVar15);
    *(undefined1 *)((uVar13 & 0xff) + 0x14) = (char)(uVar13 >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar23 = (undefined1 *)0x3eea;
  puVar22 = (undefined1 *)0x3e20;
  for (iVar16 = 0x2d; iVar16 != 0; iVar16 = iVar16 + -1) {
    puVar6 = puVar23;
    puVar23 = puVar23 + 1;
    puVar4 = puVar22;
    puVar22 = puVar22 + 1;
    *puVar6 = *puVar4;
  }
  iVar16 = CONCAT11(cVar18,uVar19) + -1;
  uStack_a = (undefined1 *)register0x00000010;
  if (iVar16 == 0) {
    if (cVar18 == '\0' || (char)bVar20 < (char)bVar11) {
      FUN_1000_5ebc((char)*(undefined2 *)0x3bee);
      uVar15 = extraout_DX;
      iVar14 = uStack_2;
    }
    else {
      out(uVar15,bVar11);
      uVar25 = unaff_BP < (undefined2 *)CONCAT11(uVar17,bVar11);
      unaff_ES = 0x13;
    }
    *(undefined2 *)0x3bee = CONCAT11(uStack_e,uStack_f);
    uVar29 = CONCAT22(uVar15,CONCAT11(uStack_c,uStack_d));
    uStack_2 = iVar14;
    if ((bool)uVar25) {
      in_BX = CONCAT11((char)(in_BX >> 8),(byte)in_BX ^ *(byte *)(unaff_DI + -0x2d0c));
      iVar16 = iVar16 + -1;
      if (iVar16 == 0) {
        uStack_d = (undefined1)unaff_SS;
        uStack_c = (undefined1)((uint)unaff_SS >> 8);
        uStack_f = 7;
        uStack_e = 0x1b;
        func_0x00010363();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      *unaff_DI = *unaff_SI;
      goto LAB_1000_1ae9;
    }
    if (CONCAT11(uStack_c,uStack_d) != *(int *)0x3bc6) goto LAB_1000_1ac3;
  }
  else {
LAB_1000_1ac3:
    uStack_d = 200;
    uStack_c = 0x1a;
    uStack_2 = iVar14;
    FUN_1000_0820();
    uStack_b = 0xcb;
    uStack_a._0_1_ = 0x1a;
    FUN_1000_5acf();
    uStack_a._1_1_ = 0xce;
    uStack_8 = 0x1a;
    func_0x0001083f();
  }
  uStack_d = 0xd1;
  uStack_c = 0x1a;
  func_0x0001b848();
  uStack_b = 0xd4;
  uStack_a._0_1_ = 0x1a;
  func_0x0001fdbe();
  uStack_a._1_1_ = 0xd7;
  uStack_8 = 0x1a;
  func_0x0001fe35();
  uStack_7 = 0xda;
  uStack_6 = 0x1a;
  func_0x0001fdea();
  uStack_5 = 0xdd;
  bStack_4 = 0x1a;
  func_0x0001a1f9();
  uStack_3 = 0xe0;
  uStack_2._0_1_ = 0x1a;
  FUN_1000_6dce();
  uStack_2._1_1_ = 0xe3;
  FUN_1000_8ea9();
  FUN_1000_6dce();
  uVar29 = FUN_1000_77f2();
  iVar14 = CONCAT11(uStack_2._1_1_,(undefined1)uStack_2);
LAB_1000_1ae9:
  uStack_d = (undefined1)uVar29;
  uStack_c = (undefined1)((ulong)uVar29 >> 8);
  uStack_f = (undefined1)iVar16;
  uStack_e = (undefined1)((uint)iVar16 >> 8);
  uStack_11 = (undefined1)((ulong)uVar29 >> 0x10);
  uStack_10 = (undefined1)((ulong)uVar29 >> 0x18);
  *(byte *)0x3483 = *(byte *)0x3483 ^ 1;
  uStack_2 = iVar14;
  FUN_1000_6dca(0x404d,0xea,uVar8,(char)&uStack_b,(char)in_BX);
  bVar10 = (byte)iVar16;
  func_0x00018ea5();
  FUN_1000_6dca();
                    /* WARNING: Bad instruction - Truncating control flow here */
  func_0x000177ee();
  uVar9 = func_0x00016dfd();
  *(undefined1 *)0xa332 = uVar9;
  *(undefined1 *)0x404d = *(undefined1 *)0x3eea;
  unaff_BP[0x2027] = unaff_BP[0x2027] | (uint)&uStack_11;
  FUN_1000_45d0();
  uStack_11 = 0x3e;
  uStack_10 = 0x48;
  FUN_1000_38ed();
  uStack_f = (undefined1)unaff_CS;
  uStack_e = (undefined1)((uint)unaff_CS >> 8);
  *(uint *)(in_BX + 0x404e) = *(uint *)(in_BX + 0x404e) | in_BX;
  uStack_11 = 0x46;
  uStack_10 = 0x48;
  FUN_1000_6b3d();
  uStack_f = 0x49;
  uStack_e = 0x48;
  FUN_1000_5acf();
  *(byte *)((int)unaff_BP + 0x123f) = *(byte *)((int)unaff_BP + 0x123f) & bVar10;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


