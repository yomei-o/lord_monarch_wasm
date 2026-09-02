/* 1000:1346 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_1346(int param_1,undefined2 param_2,undefined2 param_3,int param_4)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_AX;
  uint uVar5;
  byte in_CL;
  int in_BX;
  uint unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  longdouble in_ST0;
  
  uVar5 = CONCAT11((char)((uint)in_AX >> 8),0x76);
  out(0x3fdf,0x76);
  if ((POPCOUNT(unaff_BP - *(int *)(in_BX + unaff_SI) & 0xff) & 1U) == 0) {
    iVar4 = *(int *)0x654d;
    puVar2 = (uint *)(in_BX + 0x39);
    uVar3 = *puVar2;
    *puVar2 = *puVar2 - uVar5;
    pcVar1 = (char *)(uVar5 + iVar4 + 0x3b40);
    *pcVar1 = *pcVar1 + (char)(unaff_BP >> 8) + (uVar3 < uVar5);
    FUN_1000_71d9();
    *(float *)(param_4 + param_1 + -0x2a93) = (float)in_ST0;
    out(0x71,(char)*(undefined2 *)0x3b4a);
    out(0x71,(char)((uint)*(undefined2 *)0x3b4a >> 8));
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return CONCAT22((int)unaff_BP >> 0xf,unaff_BP >> (in_CL & 0x1f));
}


