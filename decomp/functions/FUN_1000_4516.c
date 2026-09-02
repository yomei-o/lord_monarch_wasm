/* 1000:4516 */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4
FUN_1000_4516(undefined2 param_1,byte *param_2,char *param_3,int param_4,undefined2 param_5,
             int param_6,undefined2 param_7,int param_8,undefined2 param_9,undefined2 param_10,
             undefined2 param_11)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
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
  bool bVar8;
  undefined1 in_SF;
  undefined4 uVar9;
  
  do {
    uVar3 = FUN_1000_453f();
    *(uint *)0x7898 = uVar3;
    if ((bool)in_SF) {
      pbVar7 = (byte *)((uint)unaff_DI ^ uVar3);
      unaff_DI = pbVar7 + 1;
      *pbVar7 = (byte)uVar3;
      goto LAB_1000_454a_4;
    }
    bVar8 = 8 < (byte)uVar3;
    in_CX = in_CX + 1;
    iVar5 = unaff_DS;
    if (in_CX < 0) goto code_r0x00014540;
    do {
      cVar1 = unaff_SI[in_BX + -0x17e4];
      *unaff_SI = *unaff_SI + '\x18';
      unaff_SI[in_BX + 1] = unaff_SI[in_BX + 1] << (((char)in_CX - cVar1) - bVar8 & 0x1fU);
      in_CX = param_8;
      in_BX = param_6;
      unaff_BP = param_4;
      unaff_SI = param_3;
      unaff_DI = param_2;
      unaff_DS = iVar5;
code_r0x00014540:
      while( true ) {
        FUN_1000_61a2();
        uVar4 = FUN_1000_7660();
        *(undefined2 *)0xaa98 = 0x80b5;
        unaff_DI[in_BX + 0x58] = unaff_DI[in_BX + 0x58] ^ (byte)((uint)in_BX >> 8);
        if (-1 < (char)(extraout_DL + unaff_SI[unaff_BP + 0x79])) break;
        bVar8 = (char)(extraout_DL + unaff_SI[unaff_BP + 0x79] | *(byte *)(in_BX + -1)) < '\0';
        uVar9 = func_0x0001b7b8();
        iVar5 = (int)uVar9;
        if (bVar8) {
          if (iVar5 + 1 != 0) {
            out(0x32,(char)(iVar5 + 1));
            *(undefined2 *)0x32e8 =
                 CONCAT11((char)((ulong)uVar9 >> 0x18),
                          (byte)((ulong)uVar9 >> 0x10) | unaff_SI[unaff_BP + -0x58]);
            func_0x0001fc0d();
            return CONCAT22(param_11,(uint)*(byte *)0x3298);
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
      bVar6 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
      if (bVar6 < 2) {
        in_SF = (int)((uint)(byte)(bVar6 ^ unaff_SI[0x25]) << 8) < 0;
        break;
      }
      uVar2 = CONCAT11((char)((uint)uVar4 >> 8),(char)uVar4 * '\x02' + '\x12');
      uVar3 = *(uint *)0x3298;
      bVar8 = uVar2 < uVar3;
      in_SF = (int)(uVar2 - uVar3) < 0;
      iVar5 = unaff_BP;
    } while (uVar2 == uVar3);
  } while( true );
}


