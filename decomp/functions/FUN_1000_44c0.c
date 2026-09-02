/* 1000:44c0 */

/* WARNING: Instruction at (ram,0x0001454e) overlaps instruction at (ram,0x0001454a)
    */

undefined4
FUN_1000_44c0(undefined2 param_1,undefined2 param_2,uint *param_3,uint param_4,undefined2 param_5,
             uint param_6,undefined2 param_7,int param_8,undefined2 param_9,undefined2 param_10,
             undefined2 param_11)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  uint *puVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int in_CX;
  int iVar9;
  char extraout_DL;
  byte bVar10;
  char extraout_DH;
  uint in_BX;
  uint unaff_BP;
  int unaff_SI;
  uint *unaff_DI;
  byte *pbVar11;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  uint unaff_DS;
  uint uVar12;
  bool bVar13;
  undefined4 uVar14;
  
  *unaff_DI = *unaff_DI | in_BX;
  FUN_1000_7689();
  FUN_1000_61cb();
  puVar4 = (uint *)FUN_1000_7689();
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ (byte)puVar4;
  *(byte *)(unaff_BP + (int)puVar4) = *(byte *)(unaff_BP + (int)puVar4) & (byte)unaff_SI;
  *(uint *)(in_BX + (int)puVar4) = *(uint *)(in_BX + (int)puVar4) & unaff_BP;
  iVar9 = in_CX + -1;
  if (iVar9 != 0 && (*(char *)0x4026 == '\0' && (char)((uint)in_CX >> 8) == '\0')) {
    bVar10 = extraout_DH + *(char *)((int)unaff_DI + unaff_BP + 8);
    param_2 = puVar4;
    goto code_r0x000144fa;
  }
  FUN_1000_7676();
  func_0x000161bc();
  param_2 = (uint *)0x44e4;
  func_0x0001767a();
  *(undefined2 *)0x3296 = 63999;
  unaff_SS = 0x44e1;
  uVar5 = 0;
  do {
    bVar10 = (byte)((uint)*(undefined2 *)0x3be6 >> 8);
    if (bVar10 < 2) {
code_r0x000144fa:
      iVar8 = (uint)(bVar10 ^ *(byte *)((int)puVar4 + 0x25)) << 8;
FUN_1000_4516:
      uVar12 = unaff_DS;
      bVar13 = iVar8 < 0;
      uVar7 = FUN_1000_453f();
      *(uint *)0x7898 = uVar7;
      if (bVar13) {
        pbVar11 = (byte *)((uint)unaff_DI ^ uVar7);
        unaff_DI = (uint *)(pbVar11 + 1);
        *pbVar11 = (byte)uVar7;
        goto LAB_1000_454a_4;
      }
      bVar13 = 8 < (byte)uVar7;
      iVar9 = iVar9 + 1;
      if (-1 < iVar9) goto code_r0x00014526;
    }
    else {
      uVar6 = CONCAT11((char)((uint)uVar5 >> 8),(char)uVar5 * '\x02' + '\x12');
      uVar7 = *(uint *)0x3298;
      bVar13 = uVar6 < uVar7;
      iVar8 = uVar6 - uVar7;
      uVar12 = unaff_BP;
      if (uVar6 != uVar7) goto FUN_1000_4516;
code_r0x00014526:
      cVar3 = *(char *)((int)puVar4 + in_BX + 0xe81c);
      *(char *)puVar4 = (char)*puVar4 + '\x18';
      pcVar1 = (char *)(in_BX + 1 + (int)puVar4);
      *pcVar1 = *pcVar1 << (((char)iVar9 - cVar3) - bVar13 & 0x1fU);
      iVar9 = param_8;
      in_BX = param_6;
      unaff_BP = param_4;
      puVar4 = param_3;
      unaff_DI = param_2;
    }
    while( true ) {
      func_0x000161a2();
      uVar5 = FUN_1000_7660();
      *(undefined2 *)0xaa98 = 0x80b5;
      pbVar2 = (byte *)((int)unaff_DI + in_BX + 0x58);
      *pbVar2 = *pbVar2 ^ (byte)(in_BX >> 8);
      bVar10 = extraout_DL + *(char *)((int)puVar4 + unaff_BP + 0x79);
      unaff_DS = uVar12;
      if (-1 < (char)bVar10) break;
      bVar13 = (char)(bVar10 | *(byte *)(in_BX - 1)) < '\0';
      uVar14 = func_0x0001b7b8();
      iVar8 = (int)uVar14;
      if (bVar13) {
        if (iVar8 + 1 != 0) {
          out(0x32,(char)(iVar8 + 1));
          *(undefined2 *)0x32e8 =
               CONCAT11((char)((ulong)uVar14 >> 0x18),
                        (byte)((ulong)uVar14 >> 0x10) | *(byte *)((int)puVar4 + (unaff_BP - 0x58)));
          func_0x0001fc0d();
          return CONCAT22(param_11,(uint)*(byte *)0x3298);
        }
        in_BX = CONCAT11((char)(in_BX >> 8),0x20);
        unaff_DI = (uint *)((int)unaff_DI + 1);
                    /* WARNING: Call to offcut address within same function */
        iVar8 = func_0x000145e5();
      }
      out(0x3b,(char)iVar8);
LAB_1000_454a_4:
      iVar9 = CONCAT11(0x80,(char)iVar9);
    }
  } while( true );
}


