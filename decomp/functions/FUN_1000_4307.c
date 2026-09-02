/* 1000:4307 */

/* WARNING: Instruction at (ram,0x00014308) overlaps instruction at (ram,0x00014307)
    */

void FUN_1000_4307(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 extraout_AH;
  int in_CX;
  uint in_DX;
  undefined2 extraout_DX;
  undefined2 *unaff_SI;
  undefined2 unaff_DS;
  undefined2 uStack_10;
  
  if (in_CX != 1) {
    uStack_10 = 0x3c11;
    *unaff_SI = 0x203a;
    in(in_DX | (uint)&uStack_10);
  }
  FUN_1000_77f2();
  func_0x000177f4();
  *(undefined2 *)0xc890 = 0x2c53;
  cVar2 = *(char *)0x5a19;
  if (cVar2 != '\0') {
    cVar2 = cVar2 + -1;
  }
  out(*unaff_SI,extraout_DX);
  unaff_SI[1] = unaff_SI[1] ^ CONCAT11(extraout_AH,cVar2 + -7) ^ 0x6f;
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}


