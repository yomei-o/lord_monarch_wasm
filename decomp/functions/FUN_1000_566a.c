/* 1000:566a */

void FUN_1000_566a(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined4 uVar6;
  
  uVar3 = FUN_1000_5c30();
  pcVar5 = (char *)0xb98e;
  for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar2 = unaff_DI;
    unaff_DI = unaff_DI + 2;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + 2;
    *(undefined2 *)pcVar2 = *(undefined2 *)pcVar1;
  }
  func_0x00015c5b();
  uVar3 = *(undefined2 *)0xaa40;
  *unaff_DI = (char)uVar3;
  *pcVar5 = *pcVar5 + (char)uVar3 + -0x45;
  uVar6 = FUN_1000_5782();
  if ((int)uVar6 == *(int *)0x3e98) {
    out(*(undefined2 *)pcVar5,(int)((ulong)uVar6 >> 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x0001571b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_DI + 1))();
  return;
}


