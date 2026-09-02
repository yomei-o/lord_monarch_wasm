/* 1000:4b16 */

/* WARNING: Instruction at (ram,0x00014b0f) overlaps instruction at (ram,0x00014b0e)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_4b16(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar5;
  byte bVar6;
  undefined2 in_CX;
  char extraout_DL;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  uint uVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar8;
  bool bVar9;
  byte bStack_3;
  byte bVar4;
  
  do {
    while( true ) {
      uVar8 = (byte)((uint)in_CX >> 8) < *(byte *)(unaff_BP + unaff_SI);
      uVar7 = 0x336e;
      FUN_1000_567c();
      if (!(bool)uVar8) break;
LAB_1000_4b12_1:
      in(0x1f);
      unaff_SI = uVar7;
    }
    FUN_1000_5d4f();
    FUN_1000_56a3();
    if ((bool)uVar8) goto LAB_1000_4b12_1;
    bVar9 = CARRY1(extraout_DL - (char)*(undefined2 *)(in_BX + 0x336e),*(byte *)(unaff_BP + 0x3389))
    ;
    pbVar1 = (byte *)0xb43;
    bVar3 = *pbVar1;
    bVar6 = (byte)in_CX;
    bVar4 = *pbVar1;
    *pbVar1 = bVar4 + bVar6 + bVar9;
    if (CARRY1(bVar3,bVar6) || CARRY1(bVar4 + bVar6,bVar9)) {
LAB_1000_4b0f_2:
      unaff_SI = uVar7 | *(uint *)(unaff_BP + uVar7 + -0x1c);
      unaff_DS = 0x4b32;
    }
    else {
      uVar7 = 0x9812;
      unaff_SI = *(uint *)(unaff_BP + 0x3332) | 0x336e;
      pbVar1 = (byte *)(unaff_BP + unaff_SI);
      bVar3 = *pbVar1;
      *pbVar1 = *pbVar1 + 0x12;
      pcVar2 = (char *)(unaff_BP + unaff_SI + 0xeaa);
      *pcVar2 = *pcVar2 + (char)((uint)in_CX >> 8) + (0xed < bVar3);
      pbVar1 = (byte *)(unaff_BP + 1);
      bVar3 = *pbVar1;
      *pbVar1 = *pbVar1 - bVar6;
      if (bVar3 < bVar6) goto LAB_1000_4b0f_2;
      pbVar1 = (byte *)0x11ea;
      bVar9 = CARRY1(*pbVar1,bVar6);
      *pbVar1 = *pbVar1 + bVar6;
      uVar7 = func_0x000156a0(0);
      if (!bVar9) {
        bStack_3 = (byte)in_CX;
        pbVar1 = (byte *)(unaff_BP + unaff_SI);
        bVar3 = *pbVar1;
        bVar5 = (byte)uVar7;
        *pbVar1 = *pbVar1 + bVar5;
        unaff_BP = unaff_BP + 1;
        pbVar1 = (byte *)0xb0d;
        bVar4 = *pbVar1;
        bVar6 = *pbVar1;
        *pbVar1 = bVar6 + bStack_3 + CARRY1(bVar3,bVar5);
        if (!CARRY1(bVar4,bStack_3) && !CARRY1(bVar6 + bStack_3,CARRY1(bVar3,bVar5))) {
          *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)in_BX;
          return 0xe000;
        }
        in_CX = CONCAT11((char)((uint)in_CX >> 8) + bVar5 + '\x01',bStack_3);
        goto LAB_1000_4b0f_2;
      }
      FUN_1000_56a3();
      unaff_DS = 0x4b32;
      if (bVar9) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  } while( true );
}


