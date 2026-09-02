/* 1000:5685 */

void FUN_1000_5685(void)

{
  undefined2 uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined4 uVar6;
  undefined2 in_stack_00000000;
  
  pcVar5 = (char *)0xb98e;
  for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar3 = unaff_DI;
    unaff_DI = unaff_DI + 2;
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 2;
    *(undefined2 *)pcVar3 = *(undefined2 *)pcVar2;
  }
  func_0x00015c5b();
  uVar1 = *(undefined2 *)0xaa40;
  *unaff_DI = (char)uVar1;
  *pcVar5 = *pcVar5 + (char)uVar1 + -0x45;
  uVar6 = FUN_1000_5782();
  if ((int)uVar6 == *(int *)0x3e98) {
    out(*(undefined2 *)pcVar5,(int)((ulong)uVar6 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_DI + 1))();
  return;
}


