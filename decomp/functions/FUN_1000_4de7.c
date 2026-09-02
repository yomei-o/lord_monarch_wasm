/* 1000:4de7 */

/* WARNING: Instruction at (ram,0x00014e2d) overlaps instruction at (ram,0x00014e2c)
    */

undefined4 FUN_1000_4de7(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  undefined2 in_CX;
  byte bVar6;
  int iVar5;
  byte extraout_DL;
  undefined2 extraout_DX;
  char cVar7;
  byte *in_BX;
  undefined2 unaff_BP;
  int unaff_SI;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar10;
  undefined1 in_ZF;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000c;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000010;
  
  do {
    FUN_1000_5cc6();
    func_0x0001561b();
    if (!(bool)in_CF) {
      *(undefined2 *)0x3bc4 = *(undefined2 *)0xdb7e;
      *(char *)(unaff_SI + 1) = *(char *)(unaff_SI + 1) + (byte)extraout_DX;
      *in_BX = *in_BX & (byte)extraout_DX;
      in(extraout_DX);
      bVar10 = false;
      *(undefined1 *)0x3c08 = 0;
      *(undefined2 *)0x3bce = 0;
      uVar4 = unaff_ES;
      FUN_1000_5ab2();
      if ((bVar10) || (*(int *)(*(int *)0x3e94 + 0xc) != 0)) {
        bVar10 = false;
SUB_1000_4e36:
        func_0x00014e5d();
        if (!bVar10) {
          puVar8 = (undefined1 *)0xdb7d;
          puVar9 = (undefined2 *)0xe47c;
          iVar5 = 0x900;
          uVar4 = 0x6400;
          do {
            puVar2 = puVar8;
            puVar8 = puVar8 + -1;
            uVar4 = CONCAT11((char)((uint)uVar4 >> 8),*puVar2);
            puVar3 = puVar9;
            puVar9 = puVar9 + -1;
            *puVar3 = uVar4;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          *(undefined2 *)0x346e = *(undefined2 *)0x3bc2;
          return CONCAT22(in_stack_0000000a,in_stack_0000000e);
        }
LAB_1000_4e57:
        func_0x0001f293();
        return CONCAT22(in_stack_0000000c,in_stack_00000010);
      }
      pbVar1 = in_BX + 0x3386;
      bVar10 = *pbVar1 < extraout_DL;
      *pbVar1 = *pbVar1 - extraout_DL;
      if (bVar10 || *pbVar1 == 0) goto SUB_1000_4e36;
      bVar6 = (byte)((uint)in_CX >> 8);
      in_CF = CARRY1((byte)in_BX,bVar6);
      cVar7 = (byte)in_BX + bVar6;
      in_BX = (byte *)CONCAT11((char)((uint)in_BX >> 8),cVar7);
      in_ZF = cVar7 == '\0';
      FUN_1000_5a2d(uVar4);
      unaff_ES = unaff_BP;
    }
    do {
      if (!(bool)in_ZF) goto LAB_1000_4e57;
      func_0x0001b1c4();
      unaff_SI = 0x3326;
      FUN_1000_55f9();
    } while ((bool)in_CF);
  } while( true );
}


