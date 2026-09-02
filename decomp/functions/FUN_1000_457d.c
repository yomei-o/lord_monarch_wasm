/* 1000:457d */

/* WARNING: Instruction at (ram,0x0001453e) overlaps instruction at (ram,0x0001453c)
    */

undefined4
FUN_1000_457d(char *param_1,undefined2 *param_2,undefined2 param_3,int param_4,undefined2 param_5,
             int param_6)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint in_AX;
  uint uVar5;
  int in_CX;
  byte bVar6;
  undefined2 in_DX;
  int in_BX;
  undefined2 *unaff_BP;
  char *unaff_SI;
  byte *pbVar7;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 *puVar8;
  undefined2 *unaff_DS;
  bool in_ZF;
  bool bVar9;
  undefined4 uVar10;
  byte *in_stack_00000000;
  undefined2 uStack_1697;
  undefined2 uStack_1693;
  
  if ((in_ZF) || (in_AX = in_AX & 0xfff7, *(int *)0x32e6 < 0)) {
    if (((char)((uint)in_DX >> 8) != '\x02') || ((in_AX & 4) == 0)) {
      puVar8 = (undefined2 *)&stack0xfffe;
      cVar2 = '\x05';
      do {
        unaff_BP = unaff_BP + -1;
        puVar8 = puVar8 + -1;
        *puVar8 = *unaff_BP;
        cVar2 = cVar2 + -1;
      } while ('\0' < cVar2);
      uVar5 = CONCAT11((byte)((uint)uStack_1697 >> 8) | unaff_SI[in_BX + 0x3298],(char)uStack_1697);
      goto code_r0x000145d5;
    }
    pbVar1 = (byte *)(unaff_SI + in_BX);
    *pbVar1 = *pbVar1 & (byte)((uint)in_CX >> 8);
    if ('\0' < (char)*pbVar1) {
                    /* WARNING: Call to offcut address within same function */
      func_0x000145e3();
      uVar10 = func_0x0001b6cb();
LAB_1000_45aa:
      out(0x3b,(char)uVar10);
LAB_1000_454a_4:
      in_CX = CONCAT11(0x80,(char)in_CX);
      do {
        unaff_DI[in_BX + 0x58] = unaff_DI[in_BX + 0x58] ^ (byte)((uint)in_BX >> 8);
        bVar6 = (char)((ulong)uVar10 >> 0x10) + ((char *)((int)unaff_BP + (int)unaff_SI))[0x79];
        if ((char)bVar6 < '\0') {
          bVar9 = (char)(bVar6 | *(byte *)(in_BX + -1)) < '\0';
          uVar10 = func_0x0001b7b8();
          if (!bVar9) goto LAB_1000_45aa;
          in_DX = CONCAT11((char)((ulong)uVar10 >> 0x18),
                           (byte)((ulong)uVar10 >> 0x10) |
                           ((char *)((int)unaff_BP + (int)unaff_SI))[-0x58]);
          iVar4 = (int)uVar10 + 1;
          if (iVar4 != 0) goto LAB_1000_45c0;
          in_BX = CONCAT11((char)((uint)in_BX >> 8),0x20);
          unaff_DI = unaff_DI + 1;
                    /* WARNING: Call to offcut address within same function */
          uVar10 = func_0x000145e5();
          goto LAB_1000_45aa;
        }
        bVar6 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
        if (bVar6 < 2) {
          iVar4 = (uint)(byte)(bVar6 ^ unaff_SI[0x25]) << 8;
FUN_1000_4516:
          bVar9 = iVar4 < 0;
          uVar10 = FUN_1000_453f();
          *(uint *)0x7898 = (uint)uVar10;
          bVar6 = (byte)uVar10;
          if (bVar9) goto LAB_1000_4547_2;
          bVar9 = 8 < bVar6;
          in_CX = in_CX + 1;
          puVar8 = unaff_DS;
          if (-1 < in_CX) goto code_r0x00014526;
        }
        else {
          uVar3 = CONCAT11((char)((ulong)uVar10 >> 8),(char)uVar10 * '\x02' + '\x12');
          uVar5 = *(uint *)0x3298;
          bVar9 = uVar3 < uVar5;
          iVar4 = uVar3 - uVar5;
          puVar8 = unaff_BP;
          if (uVar3 != uVar5) goto FUN_1000_4516;
code_r0x00014526:
          cVar2 = unaff_SI[in_BX + -0x17e4];
          *unaff_SI = *unaff_SI + '\x18';
          unaff_SI[in_BX + 1] = unaff_SI[in_BX + 1] << (((char)in_CX - cVar2) - bVar9 & 0x1fU);
          in_CX = param_6;
          in_BX = param_4;
          unaff_BP = param_2;
          unaff_SI = param_1;
          unaff_DI = in_stack_00000000;
          unaff_DS = puVar8;
        }
        FUN_1000_61a2();
        uVar10 = FUN_1000_7660();
        *(undefined2 *)0xaa98 = 0x80b5;
      } while( true );
    }
    *(undefined2 *)0x32e6 = in_DX;
  }
  else {
    iVar4 = 1;
LAB_1000_45c0:
    out(0x32,(char)iVar4);
  }
  *(undefined2 *)0x32e8 = in_DX;
  func_0x0001fc0d();
  uVar5 = (uint)*(byte *)0x3298;
code_r0x000145d5:
  return CONCAT22(uStack_1693,uVar5);
LAB_1000_4547_2:
  pbVar7 = (byte *)((uint)unaff_DI ^ (uint)uVar10);
  uVar10 = CONCAT22((int)((ulong)uVar10 >> 0x10),(int)(char)bVar6);
  unaff_DI = pbVar7 + 1;
  *pbVar7 = bVar6;
  goto LAB_1000_454a_4;
}


