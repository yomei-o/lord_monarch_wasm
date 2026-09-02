/* 1000:4490 */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4 FUN_1000_4490(void)

{
  int in_AX;
  byte *pbVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int in_CX;
  int iVar6;
  byte extraout_DL;
  char extraout_DL_00;
  char extraout_DH;
  byte bVar7;
  int in_BX;
  uint unaff_BP;
  int unaff_SI;
  byte *unaff_DI;
  byte *pbVar8;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  uint unaff_DS;
  uint uVar9;
  bool bVar10;
  undefined4 uVar11;
  byte *pbStack000a;
  byte *in_stack_0000000c;
  uint in_stack_0000000e;
  int in_stack_00000012;
  int in_stack_00000016;
  undefined2 in_stack_0000001c;
  
  if (in_AX == -1) {
    unaff_SI = -0xa4;
  }
  bVar7 = ((byte)in_CX & 0x1f) % 0x11;
  uVar4 = *(uint *)(in_BX + 0x55);
  *(uint *)(in_BX + 0x55) = uVar4 << bVar7 | (uint)(CONCAT12(in_AX != -1,uVar4) >> 0x11 - bVar7);
  func_0x000176e0();
  FUN_1000_61cb();
  func_0x000176e0();
  FUN_1000_6bca();
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) ^ extraout_DL;
                    /* WARNING: Call to offcut address within same function */
  func_0x000144d1();
  *(undefined2 *)0xfb96 = *(undefined2 *)0x34ca;
  unaff_DI[unaff_BP + 0xd5bd] = unaff_DI[unaff_BP + 0xd5bd] | (byte)in_CX;
  FUN_1000_61cb();
  FUN_1000_7689();
  FUN_1000_61cb();
  pbVar1 = (byte *)FUN_1000_7689();
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ (byte)pbVar1;
  pbVar1[unaff_BP] = pbVar1[unaff_BP] & (byte)unaff_SI;
  *(uint *)(pbVar1 + in_BX) = *(uint *)(pbVar1 + in_BX) & unaff_BP;
  iVar6 = in_CX + -1;
  if (iVar6 != 0 && (*(char *)0x4026 == '\0' && (char)((uint)in_CX >> 8) == '\0')) {
    bVar7 = extraout_DH + unaff_DI[unaff_BP + 8];
    pbStack000a = pbVar1;
    goto code_r0x000144fa;
  }
  FUN_1000_7676();
  func_0x000161bc();
  pbStack000a = (byte *)0x44e4;
  func_0x0001767a();
  *(undefined2 *)0x3296 = 63999;
  unaff_SS = 0x44e1;
  uVar2 = 0;
  do {
    bVar7 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
    if (bVar7 < 2) {
code_r0x000144fa:
      iVar5 = (uint)(bVar7 ^ pbVar1[0x25]) << 8;
FUN_1000_4516:
      uVar9 = unaff_DS;
      bVar10 = iVar5 < 0;
      uVar4 = FUN_1000_453f();
      *(uint *)0x7898 = uVar4;
      if (bVar10) {
        pbVar8 = (byte *)((uint)unaff_DI ^ uVar4);
        unaff_DI = pbVar8 + 1;
        *pbVar8 = (byte)uVar4;
        goto LAB_1000_454a_4;
      }
      bVar10 = 8 < (byte)uVar4;
      iVar6 = iVar6 + 1;
      if (-1 < iVar6) goto code_r0x00014526;
    }
    else {
      uVar3 = CONCAT11((char)((uint)uVar2 >> 8),(char)uVar2 * '\x02' + '\x12');
      uVar4 = *(uint *)0x3298;
      bVar10 = uVar3 < uVar4;
      iVar5 = uVar3 - uVar4;
      uVar9 = unaff_BP;
      if (uVar3 != uVar4) goto FUN_1000_4516;
code_r0x00014526:
      bVar7 = pbVar1[in_BX + -0x17e4];
      *pbVar1 = *pbVar1 + 0x18;
      pbVar1[in_BX + 1] = pbVar1[in_BX + 1] << (((char)iVar6 - bVar7) - bVar10 & 0x1f);
      iVar6 = in_stack_00000016;
      in_BX = in_stack_00000012;
      unaff_BP = in_stack_0000000e;
      pbVar1 = in_stack_0000000c;
      unaff_DI = pbStack000a;
    }
    while( true ) {
      func_0x000161a2();
      uVar2 = FUN_1000_7660();
      *(undefined2 *)0xaa98 = 0x80b5;
      unaff_DI[in_BX + 0x58] = unaff_DI[in_BX + 0x58] ^ (byte)((uint)in_BX >> 8);
      unaff_DS = uVar9;
      if (-1 < (char)(extraout_DL_00 + pbVar1[unaff_BP + 0x79])) break;
      bVar10 = (char)(extraout_DL_00 + pbVar1[unaff_BP + 0x79] | *(byte *)(in_BX + -1)) < '\0';
      uVar11 = func_0x0001b7b8();
      iVar5 = (int)uVar11;
      if (bVar10) {
        if (iVar5 + 1 != 0) {
          out(0x32,(char)(iVar5 + 1));
          *(undefined2 *)0x32e8 =
               CONCAT11((char)((ulong)uVar11 >> 0x18),
                        (byte)((ulong)uVar11 >> 0x10) | pbVar1[unaff_BP - 0x58]);
          func_0x0001fc0d();
          return CONCAT22(in_stack_0000001c,(uint)*(byte *)0x3298);
        }
        in_BX = CONCAT11((char)((uint)in_BX >> 8),0x20);
        unaff_DI = unaff_DI + 1;
                    /* WARNING: Call to offcut address within same function */
        iVar5 = func_0x000145e5();
      }
      out(0x3b,(char)iVar5);
LAB_1000_454a_4:
      iVar6 = CONCAT11(0x80,(char)iVar6);
    }
  } while( true );
}


