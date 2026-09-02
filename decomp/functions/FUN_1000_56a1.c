/* 1000:56a1 */

void FUN_1000_56a1(void)

{
  undefined2 uVar1;
  char *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined4 uVar2;
  
  uVar1 = *(undefined2 *)0xaa40;
  *unaff_DI = (char)uVar1;
  *unaff_SI = *unaff_SI + (char)uVar1 + -0x45;
  uVar2 = FUN_1000_5782(0x5060);
  if ((int)uVar2 == *(int *)0x3e98) {
    out(*(undefined2 *)unaff_SI,(int)((ulong)uVar2 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_DI + 1))();
  return;
}


