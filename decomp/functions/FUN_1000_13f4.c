/* 1000:13f4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011539) overlaps instruction at (ram,0x00011538)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x000115ef) */
/* WARNING: Removing unreachable block (ram,0x00011641) */
/* WARNING: Removing unreachable block (ram,0x000115f1) */

void FUN_1000_13f4(undefined2 param_1)

{
  byte *pbVar1;
  uint *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  long lVar5;
  byte *pbVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  undefined2 uVar10;
  uint uVar11;
  int in_CX;
  int iVar12;
  char extraout_DL;
  char cVar13;
  char extraout_DH;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  char extraout_DH_00;
  char extraout_DH_01;
  undefined2 *in_BX;
  int iVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  undefined2 *puVar17;
  int unaff_BP;
  undefined2 *puVar18;
  int iVar19;
  undefined1 *puVar20;
  byte *unaff_SI;
  byte *pbVar21;
  undefined2 *unaff_DI;
  byte *pbVar22;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  undefined1 uVar23;
  byte in_AF;
  undefined1 in_ZF;
  bool bVar24;
  longdouble in_ST0;
  undefined4 uVar25;
  undefined2 in_stack_00002776;
  int in_stack_0000277e;
  byte *in_stack_00002780;
  undefined1 *in_stack_00002782;
  undefined2 *in_stack_00002786;
  int in_stack_0000278a;
  undefined2 in_stack_0000278c;
  
  FUN_1000_7157();
  bVar7 = FUN_1000_0dff();
  if (!(bool)in_ZF) {
    uVar10 = *in_BX;
    *in_BX = 0x1452;
    cVar8 = FUN_1000_712e();
    in_BX[-1] = unaff_BP;
    in_BX[-2] = unaff_BP;
    pbVar22 = (byte *)in_BX[-1];
    pbVar21 = (byte *)*in_BX;
    iVar19 = in_BX[1];
    iVar14 = in_BX[3];
    cVar13 = (char)((uint)in_BX[4] >> 8);
    bVar7 = (byte)in_BX[6];
    puVar16 = in_BX + 7;
    lVar5 = (long)*(int *)(pbVar21 + iVar14) * 0x11f;
    iVar12 = (int)lVar5;
    if (cVar8 != '\x15') {
      *pbVar21 = (*pbVar21 - bVar7) - (iVar12 != lVar5);
      pbVar6 = (byte *)in_BX[7];
      *(char *)(iVar19 + -3) = *(char *)(iVar19 + -3) + (char)lVar5 + (bVar7 < *pbVar6);
      puVar15 = in_BX + 7;
                    /* WARNING: Call to offcut address within same function */
      in_BX[7] = 0x146d;
      func_0x000170e1();
      puVar16 = (undefined2 *)((int)puVar15 + -2);
      *(undefined2 *)((int)puVar15 + -2) = 0x1470;
      bVar7 = FUN_1000_0cfe();
      pbVar22 = pbVar6 + -1;
      pbVar1 = pbVar21;
      pbVar21 = pbVar21 + -1;
      *pbVar6 = *pbVar1;
      pbVar21[iVar14] = pbVar21[iVar14] & (byte)iVar12;
      iVar19 = iVar19 + iVar12;
      cVar13 = extraout_DH;
    }
    bVar9 = bVar7 + (9 < (bVar7 & 0xf) | in_AF) * '\x06' + (0x99 < bVar7) * '`';
    iVar12 = CONCAT11(((char)((uint)iVar14 >> 8) - cVar13) -
                      (0x8a < bVar9 || CARRY1(bVar9 + 0x75,0x99 < bVar7)),(char)iVar14);
    *(undefined2 *)((int)puVar16 + -3) = uVar10;
    if (puVar16 == (undefined2 *)0x1) {
      puVar17 = (undefined2 *)0xfffc;
      *(undefined2 *)0xfffc = 0x1484;
      func_0x00010d23();
                    /* WARNING: Call to offcut address within same function */
      *puVar17 = 0x148c;
      uVar23 = func_0x000170dc();
      out(extraout_DX,uVar23);
      return;
    }
    *(long *)(iVar12 + -0x75) = (long)ROUND(in_ST0);
    pbVar21[-0x2777] = pbVar21[-0x2777] + 1;
    bVar7 = *(byte *)(iVar12 + -0x318c);
    out(0x7e,bVar7);
    pshufw(SUB108(in_ST0,0),*(undefined8 *)(pbVar21 + iVar19 + -1),0x97);
    if (bVar7 == pbVar21[iVar19 + -1]) {
      pbVar21[iVar19 + -1] = bVar7;
    }
    *(int *)((int)puVar16 + -5) = iVar19;
    uVar11 = *(uint *)((int)puVar16 + -5);
    *(undefined2 *)((int)puVar16 + -5) = unaff_DS;
    pbVar22[0x4c] = 0x72;
    pbVar22[-4] = 0x72;
    puVar2 = (uint *)(pbVar22 + -5);
    iVar12 = (uVar11 & 3) - (*puVar2 & 3);
    *puVar2 = *puVar2 + (uint)(0 < iVar12) * iVar12;
    *(undefined2 *)((int)puVar16 + -5) = unaff_ES;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar18 = (undefined2 *)(unaff_BP + -1);
  *unaff_SI = *unaff_SI - (char)in_BX;
  if ((bVar7 | 0x74) != 0) {
    *(byte *)((int)in_BX + (int)unaff_SI) = *(byte *)((int)in_BX + (int)unaff_SI) ^ 0x42;
    pbVar1 = (byte *)((int)in_BX + (int)unaff_DI + 0x41f5);
    *pbVar1 = ~*pbVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar13 = '\x02';
  puVar4 = (undefined2 *)register0x00000010;
  do {
    puVar18 = puVar18 + -1;
    puVar4 = puVar4 + -1;
    *puVar4 = *puVar18;
    cVar13 = cVar13 + -1;
  } while ('\0' < cVar13);
code_r0x00011538:
  if ((undefined2 *)(*(uint *)0x3bc6 & 0xfffe) != in_BX) {
    func_0x000108b9();
    *(undefined2 *)0x3bc6 = in_BX;
    FUN_1000_5b6a();
    func_0x000108d8();
  }
  FUN_1000_7885();
  FUN_1000_6e9a();
  FUN_1000_08f7();
  *(uint *)0x3bc6 = *(uint *)0x3bc6 | 1;
  func_0x00015b6b();
  puVar20 = (undefined1 *)register0x00000010;
LAB_1000_156e:
  *(undefined2 *)0x3bc6 = in_stack_00002776;
  *(undefined1 *)0x32d4 = 0x1e;
  uVar10 = 0;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  do {
    *(undefined2 *)0x32ea = uVar10;
    *(undefined2 *)0x32ec = uVar10;
    in_stack_00002776 = 0x1588;
    bVar7 = FUN_1000_27c5();
    puVar18 = unaff_DI + 1;
    cVar13 = (char)((uint)in_BX >> 8);
    if ((bVar7 & 0x6f) != 0) {
      *unaff_SI = *unaff_SI + cVar13;
      ((byte *)((int)in_BX + (int)unaff_SI))[-0x58] =
           ((byte *)((int)in_BX + (int)unaff_SI))[-0x58] & (byte)in_CX;
      unaff_SI[3] = unaff_SI[3] & (byte)((uint)extraout_DX_00 >> 8);
code_r0x000115a6:
      uVar11 = FUN_1000_6e80();
      cVar13 = extraout_DH_01;
      goto code_r0x00011666;
    }
    in_BX = (undefined2 *)CONCAT11(cVar13,(char)in_BX + (char)((uint)in_CX >> 8));
    uVar11 = in(extraout_DX_00);
    bVar24 = *(byte *)0x3c00 == 4;
    if (*(byte *)0x3c00 < 4) {
      uVar11 = uVar11 + 0xb7e0;
      if ((uVar11 & 0x20) != 0) goto code_r0x000115a6;
      bVar24 = (uVar11 & 0x40) == 0;
    }
    uVar25 = CONCAT22(extraout_DX_00,uVar11);
    bVar7 = 0;
    if (!bVar24) {
      do {
        LOCK();
        *(undefined1 *)((int)in_BX + (int)puVar18) = (char)((ulong)uVar25 >> 0x10);
        UNLOCK();
        bVar9 = (byte)uVar25 + 0x30;
        uVar23 = 0xcf < (byte)uVar25 || CARRY1(bVar9,bVar7);
        puVar3 = puVar18;
        puVar18 = puVar18 + 1;
        *puVar3 = CONCAT11((char)((ulong)uVar25 >> 8),bVar9 + bVar7);
        func_0x0001c4cb();
        while (FUN_1000_4980(), (bool)uVar23) {
          while ((uVar23 = *(int *)0x3bc2 != -1, *(int *)0x3bc2 != -1 &&
                 (uVar23 = 0, *(int *)0x3bd4 != 0))) {
            unaff_SI[0x34] = unaff_SI[0x34] & (byte)in_CX;
            FUN_1000_16c6();
          }
        }
        FUN_1000_6e79();
        uVar11 = (uint)puVar20 & 0xff;
        bVar7 = CARRY2(uVar11,uVar11);
        in_BX = (undefined2 *)(uVar11 * 2);
        (*(code *)*(undefined2 *)((int)in_BX + 0x202d))();
        FUN_1000_48ac();
        FUN_1000_786d();
        FUN_1000_6e7c();
        uVar25 = FUN_1000_4919();
      } while( true );
    }
    uVar23 = 0;
    bVar24 = false;
    if (*(char *)0x32e5 != '\0') break;
    FUN_1000_96a4();
    if ((in_CX == 0) || (func_0x0001a96b(), (bool)uVar23)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(int *)((int)in_BX + (int)puVar18) = in_CX;
    *(byte *)((int)in_BX + (int)unaff_SI) = *(byte *)((int)in_BX + (int)unaff_SI) + extraout_DL;
    unaff_DI = (undefined2 *)(in_stack_0000277e + -0x40fa);
    *in_stack_00002780 = *in_stack_00002780 + (char)((uint)in_stack_00002786 >> 8);
    *in_stack_00002780 = *in_stack_00002780 ^ (byte)((uint)in_stack_0000278c >> 8);
    unaff_SI = in_stack_00002780 + 1;
    in_stack_0000278c = 0x15d8;
    in_CX = in_stack_0000278a;
    in_BX = in_stack_00002786;
    FUN_1000_7885();
    uVar10 = FUN_1000_6e8e();
    puVar20 = in_stack_00002782;
  } while( true );
  uVar11 = FUN_1000_96a0();
  if (in_CX != 0) {
    pbVar1 = puVar20 + (int)puVar18 + 0x8aa;
    *pbVar1 = *pbVar1 & (byte)((uint)in_CX >> 8);
    if ((POPCOUNT(*pbVar1) & 1U) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar13 = extraout_DH_00;
  if (bVar24) goto code_r0x00011666;
  FUN_1000_6e83();
  unaff_DI = puVar18;
  goto LAB_1000_156e;
code_r0x00011666:
  *(uint *)0xfde9 = *(uint *)0xfde9 & uVar11;
  *(char *)((int)in_BX + (int)puVar18) = *(char *)((int)in_BX + (int)puVar18) + '\x01';
  *(byte *)0xf270 = *(byte *)0xf270 & (byte)((uint)in_CX >> 8);
  ((byte *)((int)in_BX + (int)unaff_SI))[-0x17fe] =
       ((byte *)((int)in_BX + (int)unaff_SI))[-0x17fe] + cVar13;
  unaff_DI = unaff_DI + 2;
  pbVar1 = unaff_SI;
  unaff_SI = unaff_SI + 2;
  *puVar18 = *(undefined2 *)pbVar1;
  XRELEASE();
  *(undefined2 *)0x3bc6 = 5;
  func_0x00015b6b();
  if (*(char *)0x34d6 != '\0') {
    func_0x0001c1e1();
  }
  func_0x000108d8();
                    /* WARNING: Call to offcut address within same function */
  func_0x00011693();
  in_BX = (undefined2 *)((uint)(byte)((char)(*(uint *)0x3bc4 / 10) - 1) * 2 + 0x10);
  goto code_r0x00011538;
}


