/* 1000:44eb */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4
FUN_1000_44eb(char *param_1,int param_2,undefined2 param_3,int param_4,undefined2 param_5,
             int param_6,undefined2 param_7,undefined2 param_8,undefined2 param_9)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int in_CX;
  char extraout_DL;
  byte bVar6;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  byte *unaff_DI;
  byte *pbVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  int iVar8;
  bool bVar9;
  undefined4 uVar10;
  byte *in_stack_00000000;
  
  uVar2 = 0;
  do {
    bVar6 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
    if (bVar6 < 2) {
      iVar5 = (uint)(byte)(bVar6 ^ unaff_SI[0x25]) << 8;
FUN_1000_4516:
      bVar9 = iVar5 < 0;
      uVar4 = FUN_1000_453f();
      *(uint *)0x7898 = uVar4;
      if (bVar9) {
        pbVar7 = (byte *)((uint)unaff_DI ^ uVar4);
        unaff_DI = pbVar7 + 1;
        *pbVar7 = (byte)uVar4;
        goto LAB_1000_454a_4;
      }
      bVar9 = 8 < (byte)uVar4;
      in_CX = in_CX + 1;
      iVar8 = unaff_DS;
      if (-1 < in_CX) goto code_r0x00014526;
    }
    else {
      uVar3 = CONCAT11((char)((uint)uVar2 >> 8),(char)uVar2 * '\x02' + '\x12');
      uVar4 = *(uint *)0x3298;
      bVar9 = uVar3 < uVar4;
      iVar5 = uVar3 - uVar4;
      iVar8 = unaff_BP;
      if (uVar3 != uVar4) goto FUN_1000_4516;
code_r0x00014526:
      cVar1 = unaff_SI[in_BX + -0x17e4];
      *unaff_SI = *unaff_SI + '\x18';
      unaff_SI[in_BX + 1] = unaff_SI[in_BX + 1] << (((char)in_CX - cVar1) - bVar9 & 0x1fU);
      in_CX = param_6;
      in_BX = param_4;
      unaff_BP = param_2;
      unaff_SI = param_1;
      unaff_DI = in_stack_00000000;
      unaff_DS = iVar8;
    }
    while( true ) {
      FUN_1000_61a2();
      uVar2 = FUN_1000_7660();
      *(undefined2 *)0xaa98 = 0x80b5;
      unaff_DI[in_BX + 0x58] = unaff_DI[in_BX + 0x58] ^ (byte)((uint)in_BX >> 8);
      if (-1 < (char)(extraout_DL + unaff_SI[unaff_BP + 0x79])) break;
      bVar9 = (char)(extraout_DL + unaff_SI[unaff_BP + 0x79] | *(byte *)(in_BX + -1)) < '\0';
      uVar10 = func_0x0001b7b8();
      iVar5 = (int)uVar10;
      if (bVar9) {
        if (iVar5 + 1 != 0) {
          out(0x32,(char)(iVar5 + 1));
          *(undefined2 *)0x32e8 =
               CONCAT11((char)((ulong)uVar10 >> 0x18),
                        (byte)((ulong)uVar10 >> 0x10) | unaff_SI[unaff_BP + -0x58]);
          func_0x0001fc0d();
          return CONCAT22(param_9,(uint)*(byte *)0x3298);
        }
        in_BX = CONCAT11((char)((uint)in_BX >> 8),0x20);
        unaff_DI = unaff_DI + 1;
                    /* WARNING: Call to offcut address within same function */
        iVar5 = func_0x000145e5();
      }
      out(0x3b,(char)iVar5);
LAB_1000_454a_4:
      in_CX = CONCAT11(0x80,(char)in_CX);
    }
  } while( true );
}


