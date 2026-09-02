/* 1000:359d */

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_1000_359d(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  byte *pbVar1;
  code *pcVar2;
  int in_CX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI + -0x752c);
  *pbVar1 = *pbVar1 | (byte)in_CX;
  if (in_CX == 1 || *pbVar1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar2 = (code *)swi(0x5a);
  (*pcVar2)();
  return CONCAT22(param_4,param_2);
}


