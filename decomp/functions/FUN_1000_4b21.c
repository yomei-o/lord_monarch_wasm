/* 1000:4b21 */

/* WARNING: Instruction at (ram,0x00014b0f) overlaps instruction at (ram,0x00014b0e)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_4b21(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  undefined2 in_CX;
  char extraout_DL;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar8;
  undefined2 uVar9;
  undefined1 uStack_3;
  byte bVar4;
  
  do {
    FUN_1000_567c();
    if ((bool)in_CF) {
LAB_1000_4b12_1:
      in(0x1f);
      uVar9 = unaff_DS;
    }
    else {
      FUN_1000_5d4f();
      uVar9 = 0x4b32;
      FUN_1000_56a3();
      if ((bool)in_CF) goto LAB_1000_4b12_1;
      bVar8 = CARRY1(extraout_DL - (char)*(undefined2 *)(in_BX + unaff_SI),
                     *(byte *)(unaff_BP + unaff_SI + 0x1b));
      pbVar1 = (byte *)0xb43;
      bVar3 = *pbVar1;
      bVar7 = (byte)in_CX;
      bVar4 = *pbVar1;
      *pbVar1 = bVar4 + bVar7 + bVar8;
      uVar6 = unaff_SI;
      if (CARRY1(bVar3,bVar7) || CARRY1(bVar4 + bVar7,bVar8)) {
LAB_1000_4b0f_2:
        unaff_SI = uVar6 | *(uint *)(unaff_BP + uVar6 + -0x1c);
      }
      else {
        uVar6 = 0x9812;
        unaff_SI = unaff_SI | *(uint *)(unaff_BP + unaff_SI + -0x3c);
        pbVar1 = (byte *)(unaff_BP + unaff_SI);
        bVar3 = *pbVar1;
        *pbVar1 = *pbVar1 + 0x12;
        pcVar2 = (char *)(unaff_BP + unaff_SI + 0xeaa);
        *pcVar2 = *pcVar2 + (char)((uint)in_CX >> 8) + (0xed < bVar3);
        pbVar1 = (byte *)(unaff_BP + 1);
        bVar3 = *pbVar1;
        *pbVar1 = *pbVar1 - bVar7;
        if (bVar3 < bVar7) goto LAB_1000_4b0f_2;
        pbVar1 = (byte *)0x11ea;
        bVar8 = CARRY1(*pbVar1,bVar7);
        *pbVar1 = *pbVar1 + bVar7;
        uVar6 = func_0x000156a0(0);
        if (!bVar8) {
          uStack_3 = (byte)in_CX;
          pbVar1 = (byte *)(unaff_BP + unaff_SI);
          bVar3 = *pbVar1;
          bVar5 = (byte)uVar6;
          *pbVar1 = *pbVar1 + bVar5;
          unaff_BP = unaff_BP + 1;
          pbVar1 = (byte *)0xb0d;
          bVar4 = *pbVar1;
          bVar7 = *pbVar1;
          *pbVar1 = bVar7 + uStack_3 + CARRY1(bVar3,bVar5);
          if (!CARRY1(bVar4,uStack_3) && !CARRY1(bVar7 + uStack_3,CARRY1(bVar3,bVar5))) {
            *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)in_BX;
            return 0xe000;
          }
          in_CX = CONCAT11((char)((uint)in_CX >> 8) + bVar5 + '\x01',uStack_3);
          goto LAB_1000_4b0f_2;
        }
        FUN_1000_56a3();
        if (bVar8) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
    in_CF = (byte)((uint)in_CX >> 8) < *(byte *)(unaff_BP + unaff_SI);
    unaff_SI = 0x336e;
    unaff_DS = uVar9;
  } while( true );
}


