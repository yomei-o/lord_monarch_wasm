/* 1000:4550 */

/* WARNING: Instruction at (ram,0x0001453e) overlaps instruction at (ram,0x0001453c)
    */

undefined4
FUN_1000_4550(byte *param_1,char *param_2,int param_3,undefined2 param_4,int param_5,
             undefined2 param_6,int param_7)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined2 in_AX;
  int iVar4;
  int in_CX;
  byte bVar5;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  byte *pbVar6;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int iVar7;
  int unaff_DS;
  bool bVar8;
  undefined4 uVar9;
  
  uVar9 = CONCAT22(in_DX,in_AX);
  do {
    while( true ) {
      unaff_DI[in_BX + 0x58] = unaff_DI[in_BX + 0x58] ^ (byte)((uint)in_BX >> 8);
      bVar5 = (char)((ulong)uVar9 >> 0x10) + unaff_SI[unaff_BP + 0x79];
      if (-1 < (char)bVar5) break;
      bVar8 = (char)(bVar5 | *(byte *)(in_BX + -1)) < '\0';
      uVar9 = func_0x0001b7b8();
      if (bVar8) {
        iVar4 = (int)uVar9 + 1;
        if (iVar4 != 0) {
          out(0x32,(char)iVar4);
          *(undefined2 *)0x32e8 =
               CONCAT11((char)((ulong)uVar9 >> 0x18),
                        (byte)((ulong)uVar9 >> 0x10) | unaff_SI[unaff_BP + -0x58]);
          func_0x0001fc0d();
          return CONCAT22(param_1,(uint)*(byte *)0x3298);
        }
        in_BX = CONCAT11((char)((uint)in_BX >> 8),0x20);
        unaff_DI = unaff_DI + 1;
                    /* WARNING: Call to offcut address within same function */
        uVar9 = func_0x000145e5();
      }
      out(0x3b,(char)uVar9);
LAB_1000_454a_4:
      in_CX = CONCAT11(0x80,(char)in_CX);
    }
    bVar5 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
    if (bVar5 < 2) {
      iVar4 = (uint)(byte)(bVar5 ^ unaff_SI[0x25]) << 8;
FUN_1000_4516:
      bVar8 = iVar4 < 0;
      uVar9 = FUN_1000_453f();
      *(uint *)0x7898 = (uint)uVar9;
      bVar5 = (byte)uVar9;
      if (bVar8) {
        pbVar6 = (byte *)((uint)unaff_DI ^ (uint)uVar9);
        uVar9 = CONCAT22((int)((ulong)uVar9 >> 0x10),(int)(char)bVar5);
        unaff_DI = pbVar6 + 1;
        *pbVar6 = bVar5;
        goto LAB_1000_454a_4;
      }
      bVar8 = 8 < bVar5;
      in_CX = in_CX + 1;
      iVar7 = unaff_DS;
      if (-1 < in_CX) goto code_r0x00014526;
    }
    else {
      uVar3 = CONCAT11((char)((ulong)uVar9 >> 8),(char)uVar9 * '\x02' + '\x12');
      uVar2 = *(uint *)0x3298;
      bVar8 = uVar3 < uVar2;
      iVar4 = uVar3 - uVar2;
      iVar7 = unaff_BP;
      if (uVar3 != uVar2) goto FUN_1000_4516;
code_r0x00014526:
      cVar1 = unaff_SI[in_BX + -0x17e4];
      *unaff_SI = *unaff_SI + '\x18';
      unaff_SI[in_BX + 1] = unaff_SI[in_BX + 1] << (((char)in_CX - cVar1) - bVar8 & 0x1fU);
      in_CX = param_7;
      in_BX = param_5;
      unaff_BP = param_3;
      unaff_SI = param_2;
      unaff_DI = param_1;
      unaff_DS = iVar7;
    }
    FUN_1000_61a2();
    uVar9 = FUN_1000_7660();
    *(undefined2 *)0xaa98 = 0x80b5;
  } while( true );
}


