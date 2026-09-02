/* 1000:475c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014727) overlaps instruction at (ram,0x00014726)
    */
/* WARNING: Removing unreachable block (ram,0x000147af) */
/* WARNING: Removing unreachable block (ram,0x000147b3) */
/* WARNING: Removing unreachable block (ram,0x000147c8) */
/* WARNING: Removing unreachable block (ram,0x000147d7) */
/* WARNING: Removing unreachable block (ram,0x000147e1) */
/* WARNING: Removing unreachable block (ram,0x0001481b) */
/* WARNING: Removing unreachable block (ram,0x00014814) */
/* WARNING: Removing unreachable block (ram,0x00014817) */
/* WARNING: Removing unreachable block (ram,0x00014819) */
/* WARNING: Removing unreachable block (ram,0x0001481d) */

void FUN_1000_475c(void)

{
  byte *pbVar1;
  undefined1 uVar2;
  byte bVar3;
  byte in_AL;
  undefined2 in_CX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined1 *unaff_SS;
  undefined2 unaff_DS;
  byte *pbStack_c;
  int iStack_a;
  undefined2 uStack_6;
  
  if (in_AL < 8) {
    return;
  }
  do {
    *(undefined2 *)0x89a2 = 0x132;
    pbVar1 = unaff_SI;
    bVar3 = (byte)in_CX & 7;
    *pbVar1 = *pbVar1 >> bVar3 | *pbVar1 << 8 - bVar3;
    FUN_1000_4693();
    func_0x0001b778();
    uVar2 = in(extraout_DX);
    *unaff_DI = uVar2;
    *(int *)(unaff_SI + in_BX + 0x7440) = *(int *)(unaff_SI + in_BX + 0x7440) - unaff_BP;
    unaff_ES = *(undefined2 *)(unaff_SI + in_BX);
    in_CX = 0x470f;
    in_BX = CONCAT11((char)((uint)uStack_6 >> 8),(char)uStack_6 + 'G');
    do {
      thunk_FUN_1000_47c8();
      bVar3 = func_0x0001b68c();
    } while ((bVar3 & 0xf) != 0);
    *(undefined2 *)0x3bdc = extraout_DX_00;
    *(undefined1 *)0x3289 = 0x2f;
    unaff_BP = iStack_a;
    unaff_SI = pbStack_c;
    unaff_DI = unaff_SS;
  } while( true );
}


