/* 1000:452d */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4
FUN_1000_452d(byte *param_1,char *param_2,int param_3,undefined2 param_4,int param_5,
             undefined2 param_6,uint param_7,undefined2 param_8,undefined2 param_9,
             undefined2 param_10)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  uint in_CX;
  char extraout_DL;
  byte bVar5;
  int in_BX;
  char *unaff_SI;
  char *pcVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int unaff_DS;
  int iVar9;
  char in_CF;
  bool bVar10;
  undefined4 uVar11;
  
  pcVar6 = unaff_SI;
code_r0x0001452d:
  do {
    iVar9 = unaff_DS;
    *pcVar6 = (*pcVar6 + '\x18') - in_CF;
    pcVar6[in_BX] = pcVar6[in_BX] << ((byte)in_CX & 0x1f);
    in_CX = param_7;
    in_BX = param_5;
    pbVar8 = param_1;
    do {
      while( true ) {
        param_8 = 0x4547;
        FUN_1000_61a2();
        uVar3 = FUN_1000_7660();
        *(undefined2 *)0xaa98 = 0x80b5;
        pbVar8[in_BX + 0x58] = pbVar8[in_BX + 0x58] ^ (byte)((uint)in_BX >> 8);
        if (-1 < (char)(extraout_DL + param_2[param_3 + 0x79])) break;
        bVar10 = (char)(extraout_DL + param_2[param_3 + 0x79] | *(byte *)(in_BX + -1)) < '\0';
        uVar11 = func_0x0001b7b8();
        iVar4 = (int)uVar11;
        if (bVar10) {
          if (iVar4 + 1 != 0) {
            out(0x32,(char)(iVar4 + 1));
            *(undefined2 *)0x32e8 =
                 CONCAT11((char)((ulong)uVar11 >> 0x18),
                          (byte)((ulong)uVar11 >> 0x10) | param_2[param_3 + -0x58]);
            param_8 = 0x45cd;
            func_0x0001fc0d();
            return CONCAT22(param_10,(uint)*(byte *)0x3298);
          }
          in_BX = CONCAT11((char)((uint)in_BX >> 8),0x20);
          pbVar8 = pbVar8 + 1;
                    /* WARNING: Call to offcut address within same function */
          iVar4 = func_0x000145e5();
        }
        out(0x3b,(char)iVar4);
LAB_1000_454a_4:
        in_CX = CONCAT11(0x80,(char)in_CX);
      }
      bVar5 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
      pcVar6 = param_2;
      if (bVar5 < 2) {
        iVar4 = (uint)(byte)(bVar5 ^ param_2[0x25]) << 8;
      }
      else {
        uVar1 = CONCAT11((char)((uint)uVar3 >> 8),(char)uVar3 * '\x02' + '\x12');
        uVar2 = *(uint *)0x3298;
        in_CF = uVar1 < uVar2;
        iVar4 = uVar1 - uVar2;
        unaff_DS = param_3;
        if (uVar1 == uVar2) goto code_r0x0001452d;
      }
      bVar10 = iVar4 < 0;
      uVar2 = FUN_1000_453f();
      *(uint *)0x7898 = uVar2;
      if (bVar10) {
        pbVar7 = (byte *)((uint)pbVar8 ^ uVar2);
        pbVar8 = pbVar7 + 1;
        *pbVar7 = (byte)uVar2;
        goto LAB_1000_454a_4;
      }
      in_CX = in_CX + 1;
    } while ((int)in_CX < 0);
    in_CX = (uint)(byte)(((char)in_CX - param_2[in_BX + -0x17e4]) - (8 < (byte)uVar2));
    in_BX = in_BX + 1;
    in_CF = '\0';
    unaff_DS = iVar9;
  } while( true );
}


