/* 1000:96ed */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000196f9) overlaps instruction at (ram,0x000196f7)
    */

void FUN_1000_96ed(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 in_AX;
  uint uVar3;
  undefined2 uVar4;
  char extraout_DL;
  byte in_BL;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  char cVar5;
  bool in_ZF;
  
  uVar1 = (undefined1)((uint)in_AX >> 8);
  uVar3 = CONCAT11(uVar1,*(undefined1 *)0xbec3);
  if (in_ZF) {
    in_CF = 0;
    uVar3 = CONCAT11(uVar1,*(undefined1 *)0xbec3) & 0xff16;
  }
  cVar5 = 0xe9db < uVar3 || CARRY2(uVar3 + 0x1624,(uint)in_CF);
  in(0x8c);
  cVar2 = func_0x00015d3d();
  *(char *)0x2c01 = cVar2 + '4' + cVar5;
  *(char *)(unaff_BP + 0x2e0d) = *(char *)(unaff_BP + 0x2e0d) - extraout_DL;
  uVar4 = func_0x00015ecd();
  *(undefined2 *)0xb8c7 = uVar4;
  FUN_1000_8bd4();
  FUN_1000_5d7a();
  func_0x00014b80();
  *(byte *)0x2e55 = *(byte *)0x2e55 & in_BL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


