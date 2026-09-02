/* 1000:801d */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001801e) overlaps instruction at (ram,0x0001801d)
    */

void FUN_1000_801d(void)

{
  byte *pbVar1;
  undefined2 in_AX;
  uint uVar2;
  int in_CX;
  byte in_DL;
  byte bVar4;
  int iVar3;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  byte *pbVar5;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  
  pbVar5 = (byte *)(unaff_SI + 1);
  pbVar5[in_BX] = pbVar5[in_BX] + 1;
  pbVar5[in_BX] = pbVar5[in_BX] + (char)in_CX + CARRY1(in_DL,(byte)((uint)in_AX >> 8));
  bVar6 = false;
  iVar3 = 0;
  uVar2 = in(0);
  while( true ) {
    iVar3 = (iVar3 - *(int *)(pbVar5 + in_BX)) - (uint)bVar6;
    uVar2 = uVar2 & 0xc;
    if (uVar2 == 0xc) {
      *pbVar5 = *pbVar5 ^ (byte)in_BX;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(undefined2 *)(unaff_BP + -2) = 0;
    if (in_CX != 1) break;
    *pbVar5 = *pbVar5;
    pbVar1 = (byte *)(unaff_BP + unaff_DI);
    bVar4 = (byte)((uint)iVar3 >> 8);
    bVar6 = CARRY1(*pbVar1,bVar4);
    *pbVar1 = *pbVar1 + bVar4;
    in_CX = 0;
  }
  func_0x00019c68();
  halt_baddata();
}


