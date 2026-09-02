/* 1000:4b3d */

/* WARNING: Instruction at (ram,0x00014b13) overlaps instruction at (ram,0x00014b11)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_4b3d(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  undefined2 in_CX;
  char extraout_DL;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar8;
  undefined1 in_CF;
  bool bVar9;
  undefined2 in_stack_00000000;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
code_r0x00014b3d:
  uVar6 = unaff_SI;
  if (!(bool)in_CF) {
    uVar6 = 0x9812;
    unaff_SI = unaff_SI | *(uint *)(unaff_BP + unaff_SI + -0x3c);
    pbVar1 = (byte *)(unaff_BP + unaff_SI);
    bVar3 = *pbVar1;
    *pbVar1 = *pbVar1 + 0x12;
    pcVar2 = (char *)(unaff_BP + unaff_SI + 0xeaa);
    *pcVar2 = *pcVar2 + (char)((uint)in_CX >> 8) + (0xed < bVar3);
    pbVar1 = (byte *)(unaff_BP + unaff_DI + 1);
    bVar3 = *pbVar1;
    bVar7 = (byte)in_CX;
    *pbVar1 = *pbVar1 - bVar7;
    if (bVar7 <= bVar3) {
      pbVar1 = (byte *)0x11ea;
      bVar9 = CARRY1(*pbVar1,bVar7);
      *pbVar1 = *pbVar1 + bVar7;
      uVar6 = func_0x000156a0((char)unaff_DI);
      if (bVar9) {
        FUN_1000_56a3();
        if (bVar9) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        goto code_r0x00014b15;
      }
      uStack_3 = (byte)in_CX;
      uStack_2 = (char)((uint)in_CX >> 8);
      pbVar1 = (byte *)(unaff_BP + unaff_SI);
      bVar3 = *pbVar1;
      bVar5 = (byte)uVar6;
      *pbVar1 = *pbVar1 + bVar5;
      unaff_BP = unaff_BP + 1;
      pbVar1 = (byte *)0xb0d;
      bVar7 = *pbVar1;
      bVar4 = *pbVar1;
      *pbVar1 = bVar4 + uStack_3 + CARRY1(bVar3,bVar5);
      if (!CARRY1(bVar7,uStack_3) && !CARRY1(bVar4 + uStack_3,CARRY1(bVar3,bVar5))) {
        *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)in_BX;
        return 0xe000;
      }
      in_CX = CONCAT11(uStack_2 + bVar5 + '\x01',uStack_3);
    }
  }
  unaff_SI = uVar6 | *(uint *)(unaff_BP + uVar6 + -0x1c);
code_r0x00014b15:
  do {
    uVar8 = (byte)((uint)in_CX >> 8) < *(byte *)(unaff_BP + unaff_SI);
    unaff_SI = 0x336e;
    FUN_1000_567c();
    if (!(bool)uVar8) {
      unaff_DI = 0;
      FUN_1000_5d4f();
      FUN_1000_56a3();
      if (!(bool)uVar8) break;
    }
    in(0x1f);
  } while( true );
  bVar9 = CARRY1(extraout_DL - (char)*(undefined2 *)(in_BX + 0x336e),*(byte *)(unaff_BP + 0x3389));
  pbVar1 = (byte *)0xb43;
  bVar3 = *pbVar1 + (byte)in_CX;
  in_CF = CARRY1(*pbVar1,(byte)in_CX) || CARRY1(bVar3,bVar9);
  *pbVar1 = bVar3 + bVar9;
  unaff_DS = in_stack_00000000;
  in_stack_00000000 = 0x4b2f;
  goto code_r0x00014b3d;
}


