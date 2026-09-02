/* 1000:a120 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_a120(void)

{
  byte bVar1;
  int in_AX;
  byte bVar2;
  uint in_CX;
  int extraout_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar3;
  
  *(undefined1 *)(unaff_SI + -0x70c3) = 0;
  *(byte *)(unaff_SI + 0x39e8) = *(byte *)(unaff_SI + 0x39e8) | (byte)(in_CX >> 8);
  *(uint *)0xb8fe = *(uint *)0xb8fe & in_CX;
  FUN_1000_5c43();
  bVar2 = (byte)in_CX;
  bVar1 = FUN_1000_4f4a();
  uVar3 = 0x880d;
  *(int *)(in_AX + -0x77d1) = (*(int *)(in_AX + -0x77d1) - extraout_DX) - (uint)(10 < bVar1);
  in(0xb8);
  FUN_1000_5a33();
  FUN_1000_5c39(uVar3);
  uVar3 = FUN_1000_343c();
  *(char *)(unaff_BP + -0xed3) = *(char *)(unaff_BP + -0xed3) >> (bVar2 & 0x1f);
  out(0xf,uVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


