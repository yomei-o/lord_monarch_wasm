/* 1000:8d15 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018d17) overlaps instruction at (ram,0x00018d16)
    */

void FUN_1000_8d15(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint in_DX;
  uint in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  byte in_CF;
  char in_PF;
  byte in_AF;
  char in_ZF;
  char in_SF;
  int in_stack_00000000;
  
  bVar3 = in_SF << 7 | in_ZF << 6 | in_AF << 4 | in_PF << 2 | 2 | in_CF;
  iVar4 = 4;
  while( true ) {
    do {
      bVar2 = *unaff_SI;
      bVar1 = bVar2 * '\x02' + in_CF;
      in_AF = 9 < (bVar1 & 0xf) | in_AF;
      in_CF = 0x99 < bVar1 || (CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',in_CF));
      bVar2 = bVar1 + in_AF * '\x06' + in_CF * '`';
      *unaff_SI = bVar2;
      unaff_SI = unaff_SI + -1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    in_stack_00000000 = in_stack_00000000 + -1;
    if (in_stack_00000000 == 0) break;
    bVar5 = CARRY2(in_BX,in_BX);
    in_BX = in_BX * 2;
    in_CF = CARRY2(in_DX,in_DX) || CARRY2(in_DX * 2,(uint)bVar5);
    in_DX = in_DX * 2 + (uint)bVar5;
    unaff_SI = (byte *)0x3e9f;
    iVar4 = 4;
  }
  *(byte *)0x32b0 = bVar2;
  *(byte *)(unaff_BP + 0x3e9c) = *(byte *)(unaff_BP + 0x3e9c) ^ bVar3;
  FUN_1000_8da3();
  FUN_1000_8da3();
  FUN_1000_8da3();
  func_0x0001e1a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


