/* 1000:1c91 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011d9f) overlaps instruction at (ram,0x00011d9e)
    */

void FUN_1000_1c91(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                  int param_5,int param_6,int param_7,undefined2 param_8,int param_9,
                  undefined2 param_10,uint param_11)

{
  int *piVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  byte extraout_AL;
  char cVar5;
  byte bVar6;
  byte bVar7;
  byte extraout_AL_00;
  byte extraout_AH;
  uint in_AX;
  byte extraout_AH_00;
  int iVar8;
  uint in_CX;
  char extraout_DH;
  byte bVar9;
  int in_BX;
  byte *pbVar10;
  int unaff_BP;
  uint *unaff_SI;
  byte *pbVar11;
  byte *unaff_DI;
  byte *pbVar12;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  byte bVar13;
  char cVar14;
  byte bVar15;
  bool bVar16;
  undefined1 uVar17;
  undefined4 uVar18;
  
  bVar7 = (byte)in_AX;
  *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ bVar7;
  bVar15 = (in_AX & 0x1000) != 0;
  *unaff_DI = bVar7;
  pbVar12 = unaff_DI + 2;
  unaff_DI[1] = bVar7;
  pbVar10 = (byte *)CONCAT11((char)((uint)in_BX >> 8) + *(byte *)((int)unaff_SI + in_BX + 0x3045),
                             (char)in_BX);
  pbVar2 = pbVar10 + (int)pbVar12 + 0x3c73;
  *(uint *)pbVar2 = *(int *)pbVar2 - in_CX;
  bVar16 = *(int *)pbVar2 == 0;
  FUN_1000_082c();
  if ((bVar16) && (cVar14 = 0, (*unaff_SI & 2) == 0)) {
    *(undefined2 *)0x3ea6 = unaff_SI;
    func_0x0001b849();
    func_0x0001b961();
                    /* WARNING: Call to offcut address within same function */
    func_0x00011e09();
    uVar4 = in_CX;
    bVar6 = extraout_AL;
    bVar7 = extraout_AH;
    if ((bool)cVar14) goto LAB_1000_1df9;
    *pbVar12 = extraout_AL;
    unaff_DI[3] = extraout_AL;
    *(undefined2 *)0x3ea4 = param_2;
    func_0x0001b84a();
    cVar5 = func_0x0001b8b0();
    *(byte *)unaff_SI = (byte)*unaff_SI + cVar5 + cVar14;
    *(int *)(param_7 + param_6 + 3) = param_6;
    piVar1 = (int *)(param_7 + param_6 + -0x18);
    *piVar1 = *piVar1 + -0x4b;
    bVar13 = (byte)((uint)param_9 >> 8) < *(byte *)(param_7 + param_5 + 0x1093);
    FUN_1000_56d9();
    FUN_1000_44c0();
    bVar6 = FUN_1000_9eb2();
    pbVar2 = (byte *)0x1093;
    bVar7 = *pbVar2;
    bVar15 = *pbVar2;
    *pbVar2 = bVar15 + bVar6 + bVar13;
    *(int *)(param_9 + 0x1093) =
         *(int *)(param_9 + 0x1093) + -0x6c96 +
         (uint)(CARRY1(bVar7,bVar6) || CARRY1(bVar15 + bVar6,bVar13));
    *(char *)(param_7 + 0x1093) = *(char *)(param_7 + 0x1093) + extraout_DH;
    in(0x3c);
    FUN_1000_779e();
    FUN_1000_576c();
    FUN_1000_56d7();
    bVar7 = FUN_1000_4550();
    pbVar11 = (byte *)0x10a7;
    pbVar12 = (byte *)0x3bd2;
    bVar15 = bVar7 < 7;
    if (bVar7 != 7) {
      pbVar11 = (byte *)0x109b;
      pbVar12 = (byte *)0x3bd0;
    }
    pbVar10 = pbVar11;
    FUN_1000_56d7();
    FUN_1000_44be();
    uVar18 = func_0x0001ddb0();
    pbVar2 = pbVar11;
    bVar6 = *pbVar2;
    bVar9 = (byte)((ulong)uVar18 >> 0x18);
    bVar13 = *pbVar2 + bVar9;
    *pbVar2 = bVar13 + bVar15;
    if (*pbVar2 != 0) goto code_r0x00011da0;
    unaff_SI = (uint *)0x1c51;
    bVar7 = (byte)uVar18;
    if (CARRY1(bVar6,bVar9) || CARRY1(bVar13,bVar15)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar6 = 1;
    if (*(byte *)0x3bf4 != 1) {
      bVar6 = *(byte *)0x3bf4 | 0x10;
    }
LAB_1000_1d86:
    *(byte *)(unaff_SI + 5) = bVar6 | bVar7 >> 2 | bVar7 << 6;
    *(int *)0x5489 = (int)(pbVar10 + *(int *)0x5489);
  }
  else {
    func_0x00016d9e();
    func_0x0001c3c9();
    *(int *)(pbVar10 + 10) = *(int *)(pbVar10 + 10) + 0x55;
    uVar4 = in_CX;
    bVar6 = extraout_AL_00;
    bVar7 = extraout_AH_00;
LAB_1000_1df9:
    param_11 = uVar4;
    if ((bVar6 & 0x40) != 0) {
      *pbVar12 = bVar6;
      pbVar12 = unaff_DI + 4;
      unaff_DI[3] = bVar6;
      iVar8 = func_0x000146ae();
      if ((char)iVar8 == '\0') {
        *(int *)0xc55e = iVar8;
        *(int *)0x3bce = iVar8;
        iVar8 = iVar8 + -1;
        *(int *)0x34c8 = iVar8;
        *(undefined1 *)0x328a = (char)iVar8;
        *(int *)0x3296 = iVar8;
        *(int *)0x3298 = iVar8;
        *(int *)0x329a = iVar8;
        *(undefined2 *)0x3bc2 = 0x95;
        cVar5 = '8';
        func_0x0001fd7c(*(undefined2 *)(unaff_DI + 0x1b),0x34);
        *(undefined2 *)0x3bc4 = 10;
        FUN_1000_5b9e();
        cVar14 = FUN_1000_077d(pbVar12);
        if ((char)(cVar14 + cVar5) != '\0') {
          func_0x0001c0a4();
          FUN_1000_079b();
          FUN_1000_5838();
          FUN_1000_91d1();
          FUN_1000_4f92();
          FUN_1000_6d2a();
          FUN_1000_5838();
          FUN_1000_4f92();
          FUN_1000_6d2a();
          func_0x0001fd2c();
          func_0x0001fd1a();
          func_0x0001fd46();
          puVar3 = unaff_SI;
          *puVar3 = *puVar3 - (int)unaff_SI;
          if (*puVar3 == 0) {
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
      func_0x000107d7();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar3 = (uint *)(pbVar10 + 4);
    uVar4 = *puVar3;
    *puVar3 = *puVar3 - 0x61;
    if (uVar4 < 0x61 && *puVar3 != 0) goto LAB_1000_1d86;
    unaff_DI[3] = bVar6;
    pbVar12 = unaff_DI + 5;
    unaff_DI[4] = bVar6;
    bVar13 = pbVar12[unaff_BP + 0x447];
    if (-1 < (char)(bVar6 + 0x5d)) {
      *unaff_SI = (uint)(byte)(bVar13 + (9 < (bVar13 & 0xf) | bVar15) * '\x06' +
                              (0x99 < bVar13 || 0xa2 < bVar6) * '`') * (uint)bVar7 >> 8;
      return;
    }
  }
  cVar14 = '\0';
  uVar17 = pbVar12 == (byte *)0x0;
  func_0x0001b28d();
  uVar18 = func_0x0001bbbe();
  if ((bool)uVar17) {
    pbVar10[(int)unaff_SI] = (pbVar10[(int)unaff_SI] - *(char *)0x3689) - cVar14;
    *(uint *)(pbVar10 + (int)unaff_SI) = *(uint *)(pbVar10 + (int)unaff_SI) ^ param_11;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
code_r0x00011da0:
  out((int)((ulong)uVar18 >> 0x10),(int)uVar18);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


