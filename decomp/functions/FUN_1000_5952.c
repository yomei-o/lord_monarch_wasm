/* 1000:5952 */

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_1000_5952(undefined2 param_1,int param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  byte bVar7;
  int iVar8;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined2 in_stack_00000018;
  undefined2 in_stack_0000001c;
  
                    /* WARNING: Call to offcut address within same function */
  bVar7 = func_0x00015974();
  if ((bool)in_CF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_SI = *unaff_SI & bVar7;
  pbVar2 = unaff_DI + -0x10;
  bVar3 = *pbVar2;
  *pbVar2 = *pbVar2 + bVar7;
  *unaff_SI = *unaff_SI + bVar7 + CARRY1(bVar3,bVar7);
  uVar6 = FUN_1000_5ab6();
  *unaff_DI = uVar6;
  puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
  pcVar1 = puVar5 + param_2;
  *pcVar1 = *pcVar1 + (char)((uint)param_5 >> 8);
  puVar4 = (undefined1 *)(unaff_BP + 2);
  *(undefined1 *)(unaff_BP + 1) = *puVar5;
  *puVar4 = 0x20;
  for (iVar8 = 10; puVar4 = puVar4 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar4 = 0;
  }
  return CONCAT22(in_stack_00000018,in_stack_0000001c);
}


