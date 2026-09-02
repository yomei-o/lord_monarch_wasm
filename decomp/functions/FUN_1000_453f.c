/* 1000:453f */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4
FUN_1000_453f(char *param_1,int param_2,undefined2 param_3,int param_4,undefined2 param_5,
             int param_6,undefined2 param_7,undefined2 param_8,undefined2 param_9)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  char extraout_DL;
  byte bVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int iVar11;
  int unaff_DS;
  bool bVar12;
  undefined4 uVar13;
  byte *in_stack_00000000;
  
  iVar6 = param_6;
  iVar8 = param_4;
  pbVar10 = in_stack_00000000;
  do {
    while( true ) {
      FUN_1000_61a2();
      uVar4 = FUN_1000_7660();
      *(undefined2 *)0xaa98 = 0x80b5;
      pbVar10[iVar8 + 0x58] = pbVar10[iVar8 + 0x58] ^ (byte)((uint)iVar8 >> 8);
      if (-1 < (char)(extraout_DL + param_1[param_2 + 0x79])) break;
      bVar12 = (char)(extraout_DL + param_1[param_2 + 0x79] | *(byte *)(iVar8 + -1)) < '\0';
      uVar13 = func_0x0001b7b8();
      iVar5 = (int)uVar13;
      if (bVar12) {
        if (iVar5 + 1 != 0) {
          out(0x32,(char)(iVar5 + 1));
          *(undefined2 *)0x32e8 =
               CONCAT11((char)((ulong)uVar13 >> 0x18),
                        (byte)((ulong)uVar13 >> 0x10) | param_1[param_2 + -0x58]);
          func_0x0001fc0d();
          return CONCAT22(param_9,(uint)*(byte *)0x3298);
        }
        iVar8 = CONCAT11((char)((uint)iVar8 >> 8),0x20);
        pbVar10 = pbVar10 + 1;
                    /* WARNING: Call to offcut address within same function */
        iVar5 = func_0x000145e5();
      }
      out(0x3b,(char)iVar5);
LAB_1000_454a_4:
      iVar6 = CONCAT11(0x80,(char)iVar6);
    }
    bVar7 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
    if (1 < bVar7) {
      param_6 = param_2;
      uVar2 = CONCAT11((char)((uint)uVar4 >> 8),(char)uVar4 * '\x02' + '\x12');
      uVar3 = *(uint *)0x3298;
      bVar12 = uVar2 < uVar3;
      iVar5 = uVar2 - uVar3;
      iVar11 = param_2;
      if (uVar2 != uVar3) goto FUN_1000_4516;
      goto code_r0x00014526;
    }
    iVar5 = (uint)(byte)(bVar7 ^ param_1[0x25]) << 8;
FUN_1000_4516:
    bVar12 = iVar5 < 0;
    param_6 = 0x4519;
    uVar3 = FUN_1000_453f();
    *(uint *)0x7898 = uVar3;
    if (bVar12) {
      pbVar9 = (byte *)((uint)pbVar10 ^ uVar3);
      pbVar10 = pbVar9 + 1;
      *pbVar9 = (byte)uVar3;
      goto LAB_1000_454a_4;
    }
    bVar12 = 8 < (byte)uVar3;
    iVar6 = iVar6 + 1;
    iVar11 = unaff_DS;
    if (-1 < iVar6) {
code_r0x00014526:
      cVar1 = param_1[iVar8 + -0x17e4];
      *param_1 = *param_1 + '\x18';
      param_1[iVar8 + 1] = param_1[iVar8 + 1] << (((char)iVar6 - cVar1) - bVar12 & 0x1fU);
      iVar6 = param_6;
      iVar8 = param_4;
      pbVar10 = in_stack_00000000;
      unaff_DS = iVar11;
    }
  } while( true );
}


