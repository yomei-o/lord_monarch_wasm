/* 1000:444b */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4 FUN_1000_444b(void)

{
  char cVar1;
  undefined2 uVar2;
  char cVar7;
  uint *puVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar8;
  int iVar9;
  byte extraout_DL;
  char extraout_DL_00;
  undefined2 extraout_DX;
  char extraout_DH;
  byte bVar10;
  int in_BX;
  int iVar11;
  uint unaff_BP;
  uint *unaff_SI;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  uint unaff_DS;
  uint uVar14;
  byte in_AF;
  bool bVar15;
  undefined4 uVar16;
  byte *pbStack0012;
  byte *in_stack_00000014;
  uint in_stack_00000016;
  int in_stack_0000001a;
  int in_stack_0000001e;
  undefined2 in_stack_00000024;
  
  iVar11 = CONCAT11((byte)((uint)in_BX >> 8) & *(byte *)(in_BX + 0x1e3e),(char)in_BX);
  iVar8 = 8;
  FUN_1000_76f2(0x10);
  in(extraout_DX);
  in(extraout_DX);
  FUN_1000_4490(extraout_DX);
  iVar9 = *(int *)0x34ce;
  *(int *)0x329a = iVar9;
  FUN_1000_76e9();
  FUN_1000_61da();
  FUN_1000_76e9();
  uVar2 = FUN_1000_61da();
  pbVar13 = (byte *)(iVar9 + -0x27c);
  puVar3 = unaff_SI + 1;
  bVar10 = (byte)uVar2;
  cVar7 = (char)((uint)uVar2 >> 8);
  bVar15 = 0x99 < bVar10 || *unaff_SI < *(uint *)(iVar9 + -0x27e);
  cVar1 = bVar10 + (9 < (bVar10 & 0xf) | in_AF) * '\x06' + bVar15 * '`';
  iVar9 = CONCAT11(cVar7,cVar1);
  pbVar13[iVar11 + 0x329a] = pbVar13[iVar11 + 0x329a] + cVar7 + bVar15;
  if (iVar9 == -1) {
    puVar3 = (uint *)(CONCAT11(cVar7,cVar1) ^ 0xa3);
  }
  bVar10 = ((byte)iVar8 & 0x1f) % 0x11;
  uVar6 = *(uint *)(iVar11 + 0x55);
  *(uint *)(iVar11 + 0x55) = uVar6 << bVar10 | (uint)(CONCAT12(iVar9 != -1,uVar6) >> 0x11 - bVar10);
  func_0x000176e0();
  FUN_1000_61cb();
  func_0x000176e0();
  FUN_1000_6bca();
  *(byte *)(iVar11 + (int)puVar3) = *(byte *)(iVar11 + (int)puVar3) ^ extraout_DL;
                    /* WARNING: Call to offcut address within same function */
  func_0x000144d1();
  *(undefined2 *)0xfb96 = *(undefined2 *)0x34ca;
  pbVar13[unaff_BP + 0xd5bd] = pbVar13[unaff_BP + 0xd5bd] | (byte)iVar8;
  FUN_1000_61cb();
  FUN_1000_7689();
  FUN_1000_61cb();
  pbVar4 = (byte *)FUN_1000_7689();
  *(byte *)(unaff_BP + (int)puVar3) = *(byte *)(unaff_BP + (int)puVar3) ^ (byte)pbVar4;
  pbVar4[unaff_BP] = pbVar4[unaff_BP] & (byte)puVar3;
  *(uint *)(pbVar4 + iVar11) = *(uint *)(pbVar4 + iVar11) & unaff_BP;
  iVar9 = iVar8 + -1;
  if (iVar9 != 0 && (*(char *)0x4026 == '\0' && (char)((uint)iVar8 >> 8) == '\0')) {
    bVar10 = extraout_DH + pbVar13[unaff_BP + 8];
    pbStack0012 = pbVar4;
    goto code_r0x000144fa;
  }
  FUN_1000_7676();
  func_0x000161bc();
  pbStack0012 = (byte *)0x44e4;
  func_0x0001767a();
  *(undefined2 *)0x3296 = 63999;
  unaff_SS = 0x44e1;
  uVar2 = 0;
  do {
    bVar10 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
    if (bVar10 < 2) {
code_r0x000144fa:
      iVar8 = (uint)(bVar10 ^ pbVar4[0x25]) << 8;
FUN_1000_4516:
      uVar14 = unaff_DS;
      bVar15 = iVar8 < 0;
      uVar6 = FUN_1000_453f();
      *(uint *)0x7898 = uVar6;
      if (bVar15) {
        pbVar12 = (byte *)((uint)pbVar13 ^ uVar6);
        pbVar13 = pbVar12 + 1;
        *pbVar12 = (byte)uVar6;
        goto LAB_1000_454a_4;
      }
      bVar15 = 8 < (byte)uVar6;
      iVar9 = iVar9 + 1;
      if (-1 < iVar9) goto code_r0x00014526;
    }
    else {
      uVar5 = CONCAT11((char)((uint)uVar2 >> 8),(char)uVar2 * '\x02' + '\x12');
      uVar6 = *(uint *)0x3298;
      bVar15 = uVar5 < uVar6;
      iVar8 = uVar5 - uVar6;
      uVar14 = unaff_BP;
      if (uVar5 != uVar6) goto FUN_1000_4516;
code_r0x00014526:
      bVar10 = pbVar4[iVar11 + -0x17e4];
      *pbVar4 = *pbVar4 + 0x18;
      pbVar4[iVar11 + 1] = pbVar4[iVar11 + 1] << (((char)iVar9 - bVar10) - bVar15 & 0x1f);
      iVar9 = in_stack_0000001e;
      iVar11 = in_stack_0000001a;
      unaff_BP = in_stack_00000016;
      pbVar4 = in_stack_00000014;
      pbVar13 = pbStack0012;
    }
    while( true ) {
      func_0x000161a2();
      uVar2 = FUN_1000_7660();
      *(undefined2 *)0xaa98 = 0x80b5;
      pbVar13[iVar11 + 0x58] = pbVar13[iVar11 + 0x58] ^ (byte)((uint)iVar11 >> 8);
      unaff_DS = uVar14;
      if (-1 < (char)(extraout_DL_00 + pbVar4[unaff_BP + 0x79])) break;
      bVar15 = (char)(extraout_DL_00 + pbVar4[unaff_BP + 0x79] | *(byte *)(iVar11 + -1)) < '\0';
      uVar16 = func_0x0001b7b8();
      iVar8 = (int)uVar16;
      if (bVar15) {
        if (iVar8 + 1 != 0) {
          out(0x32,(char)(iVar8 + 1));
          *(undefined2 *)0x32e8 =
               CONCAT11((char)((ulong)uVar16 >> 0x18),
                        (byte)((ulong)uVar16 >> 0x10) | pbVar4[unaff_BP - 0x58]);
          func_0x0001fc0d();
          return CONCAT22(in_stack_00000024,(uint)*(byte *)0x3298);
        }
        iVar11 = CONCAT11((char)((uint)iVar11 >> 8),0x20);
        pbVar13 = pbVar13 + 1;
                    /* WARNING: Call to offcut address within same function */
        iVar8 = func_0x000145e5();
      }
      out(0x3b,(char)iVar8);
LAB_1000_454a_4:
      iVar9 = CONCAT11(0x80,(char)iVar9);
    }
  } while( true );
}


