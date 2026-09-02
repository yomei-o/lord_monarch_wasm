/* 1000:4946 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_4946(void)

{
  uint *puVar1;
  byte in_CL;
  uint in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)0xb223 = *(byte *)0xb223 ^ in_CL;
  *unaff_DI = *unaff_SI;
  *(undefined2 *)0x3bde = 0;
  *(undefined2 *)0x32a6 = 1;
  *(undefined2 *)0x32a2 = 0xffff;
  *(undefined2 *)0x32a4 = 0xffff;
  FUN_1000_6b3e();
  FUN_1000_45d0();
  FUN_1000_38ed();
  puVar1 = (uint *)((int)unaff_DI + in_BX + 2);
  *puVar1 = *puVar1 | in_BX;
  FUN_1000_6b3d();
  FUN_1000_5acf();
  *(byte *)(unaff_BP + 0x123f) = *(byte *)(unaff_BP + 0x123f) & in_CL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


